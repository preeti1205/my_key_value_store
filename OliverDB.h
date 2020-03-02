#ifndef OLIVERDB_H
#define OLIVERDB_H

#include <iostream>
#include <stdio.h>

#include "algo/Hash.h"
#include "Options.h"
#include "DBIterator.h"
#include "Status.h"

class OliverDB{
	Status open(string name);
	Status close();
	Status get(std::string key_name);
	Status put(std::string key_name, std::string val_name);
	Iterator* NewIterator();

private:
	RobinHoodHash HashMap_;

};