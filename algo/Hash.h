#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

struct Entry{
	uint64_t size_key;
	uint64_t size_value;
	char* data;
};

struct Bucket{
	Entry* entry;
};

class Hash{
	Hash();
	virtual ~Hash();
    virtual uint64_t GetHashValue(const char* data);
private:
	virtual uint64_t HashFunction(const char* data);
    virtual uint64_t MaxInputSize(); 
};

class RobinHoodHash: public Hash{
	RobinHoodHash();
	RobinHoodHash(uint64_t size);
	~RobinHoodHash();      
	uint64_t GetHashValue(const char* data);
private:
	uint64_t HashFunction(const char* data);
	uint64_t MaxInputSize();
	Bucket* buckets;
	uint64_t n_buckets;
	uint64_t n_buckets_used;
	uint64_t probing_max; 

	int Open();
	int Close();
	int Get(const std::string& key, std::string& value);
	int Put(const std::string& key, const std::string& value);
	int Exists(const std::string& key);
	int Delete(const std::string& key);

}