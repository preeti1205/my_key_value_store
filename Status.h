#ifndef STATUS_H
#define STATUS_H

#include <iostream>
#include <string>

class Status{
	Status();
	Status(int);
	Status(int, std::string);
	bool IsOK();
private:
	int code_;
	std::string message_;

	enum Code{
		kOK = 0;
		kNotFound = 1;
		kDeleteOrder = 2;
		kInvalidArgument = 3;
		kIOError= 4;
		kDone = 5;
	};

	int code() const { return code_ ; };

};