#ifndef HSTABLE_MANAGER_H
#define HSTABLE_MANAGER_H

#include <thread>
#include <mutex>
#include <chrono>
#include <string>

class HSTableManager{
public:
	HSTableManager() {
	    is_closed_ = true;
	    is_read_only_ = true;
	    has_file_ = false;
	    buffer_has_items_ = false;
	    has_sync_option_ = false;
	}

	HSTableManager(std::string db_name,
		           std::string prefix,
		           std::string prefix_compaction,
		           std::string dirpath_locks,
		           //Filetype filetype_default,
		           bool read_only = false
		           ): prefix_(prefix_), 
	                  prefix_compaction_(prefix_compaction), 
	                  dirpath_locks_(dirpath_locks), 
	                  is_read_only_(read_only),
	                  file_id_(0),
	                  sequencefile_id_(0),
	                  sequence_timestamp_(0),
	                  wait_until_can_open_new_files_(false),
	                  dbname_(db_name) {

	    //hash_ = MakeHash();
        Reset();
	    if (!is_read_only_) {
	      buffer_raw_ = new char[size_block_*2];
	      buffer_index_ = new char[size_block_*2];
	    }

	}

	
private:
	Hash* hash_;
	std::string dbname_;
	char *buffer_raw_;
    char *buffer_index_;

	bool is_closed_;
	bool is_read_only_;
	bool has_file_;
	bool buffer_has_items_;
	bool has_sync_option_;
	bool wait_until_can_open_new_files_;

	uint32_t file_id_;
	uint32_t sequencefile_id_;
	uint32_t sequence_timestamp_;
	uint64_t size_block_;
	uint64_t offset_start_;
    uint64_t offset_end_;
	std::string prefix_;
	std::string prefix_compaction_;
	std::string dirpath_locks_;

}