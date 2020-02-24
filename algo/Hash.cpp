#include "algo/Hash.h"

RobinHoodHash::RobinHoodHash(){
	Bucket* buckets = NULL;
	uint64_t n_buckets = 1000;
	uint64_t n_buckets_used = 0;
	uint64_t probing_max = 1000; 
}

RobinHoodHash::RobinHoodHash(uint64_t size){
	Bucket* buckets = NULL;
	uint64_t n_buckets = size;
	uint64_t n_buckets_used = 0;
	uint64_t probing_max = size; 
}

uint64_t RobinHoodHash::GetHashValue(const char* data){
	return HashFunction()
}

uint64_t RobinHoodHash::HashFunction(const char* data){
	//hash function associated -> you can use anything you like. I will use one from CLRS ie OG division method. 
	//Choosing my primes to be 337. Might not be the most uniformly distributed set of keys, but it gets the job done for now.
	//Assuming the chars are utf16 there are approx 2^16 possible chars
	uint64_t hash_value= 0;
	for(uint64_t i = 0; data[i] != '/0'; ++i){
		hash_value += data[i];
		hash_value %= 337;
	}
	return hash_value;
}

uint64_t RobinHoodHash::MaxInputSize(){
	return n_buckets;
}

int RobinHoodHash::Open(){
	buckets = new Bucket[n_buckets];
	//bucket elements are all set to point NULL
	memset(buckets, 0, n_buckets* sizeof(Bucket));
	return 0;   
}

int RobinHoodHash::Close(){
	if(buckets != 0){
		for(uint64_t i = 0; i < n_buckets; ++i){
			delete buckets[i]->entry;   //does this cause error if entry is NULL. We shall see
			delete buckets[i]->hash_val;
		}
		delete[] buckets;
	}
	return 0;
}

int RobinHoodHash::GetDistanceToInitIndex(uint64_t idx, uint64_t &distance){
	if(buckets[idx].entry == 0 ) return -1;
	uint64_t init_index = buckets[idx].hash_val % n_buckets;
	if(init_index <= idx){
		distance = idx - init_index;
	}
	else
		distance = (n_buckets - init_index) + idx;
	return 0;
}

int RobinHoodHash::Get(const std::string& key, std::string& value){
	uint64_t hash_value = GetHashValue(key);
	uint64_t start_bucket_idx = hash_value % n_buckets;
	uint64_t probe_distance = 0;
	bool found = false;

    for(uint64_t i = 0; i < probing_max; ++i){
    	uint64_t curr_index = (start_bucket_idx + i) % n_buckets;
    	GetDistanceToInitIndex(curr_index, probe_distance);
    	if(buckets[curr_index].entry  == 0 || i > probe_distance)
    		break;
    	if( (buckets[curr_index].entry->key_size == key.size()) &&
    	    (memcmp(buckets[curr_index].entry->data, key.c_str(), key.size()) == 0) )
    		value = std::string(buckets[curr_index].entry->data + key.size(), buckets[curr_index].entry->value_size; //string(start_pos, size)

    }
    if(found) return 0;
    return 1;
}

int RobinHoodHash::Put(const std::string& key, const std::string& value){
	if(n_buckets == n_buckets_used)
		return 1;

	++n_buckets_used;

	uint64_t hash_value = GetHashValue(key);
	uint64_t start_bucket_idx = hash_value % n_buckets;
	uint64_t probe_distance = 0;
	uint64_t probe_current = 0;

    std::string data_part = key + value;
    Entry data_entry = new Entry();
    data_entry->key_size = key.size();
    data_entry->val_size = value.size();
    data_entry->data = data_part.c_str();

	for(uint64_t i = 0; i < probing_max; ++i){
		int curr_index = (start_bucket_idx + i) % n_buckets;
		GetDistanceToInitIndex(curr_index, probe_distance);
		if(buckets[curr_index] != 0 ){
			if(probe_current > probe_distance){
				uint64_t temp_hash_value = buckets[curr_index].hash_val;
				Entry* temp_entry = buckets[curr_index].entry;
				buckets[curr_index].hash_val = hash_val;
				buckets[curr_index].entry = data_entry;
				hash_val = temp_hash_value;
				data_entry = temp_entry;
				probe_current = probe_distance;
			}
		}
		if(buckets[curr_index] == 0){
			buckets[curr_index].hash_val = hash_value;
			buckets[curr_index].entry = data_entry;
			break;
		}
		++probe_current;	

	}
	return 0;
}

int RobinHoodHash::Delete(const std::string& key);