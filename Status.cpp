#include "Status.h"

Status::Status(){
	code_ = kOK;
	message_ = "";
}

Status::Status(int stat_code){
	code_ = stat_code;
}

Status::Status(int stat_code, std::string error_message){
	code_ = stat_code;
	message_ = error_message;
}

bool Status::IsOK(){
	return code_ == kOK;
}