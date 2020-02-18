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
	//Choosing my prime to be 337 
	uint64_t hash_value= 0;
	for(uint64_t i = 0; data[i] != '/0'; ++i){

	}
	return hash_value;

}

uint64_t RobinHoodHash::MaxInputSize(){

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
		}
		delete[] buckets;
	}
	return 0;
}

int RobinHoodHash::Get(const std::string& key, std::string& value){


}

int RobinHoodHash::Put(const std::string& key, const std::string& value);
int RobinHoodHash::Exists(const std::string& key);
int RobinHoodHash::Delete(const std::string& key);