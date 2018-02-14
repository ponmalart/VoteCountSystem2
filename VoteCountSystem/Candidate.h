#include "stdafx.h"
#pragma once
#include <string>
using std::string;

class Candidate
{
public:
	string name;
	string party;

	Candidate();
	Candidate(string theName, string theParty);
	void setName(string newName);
	void setParty(string newParty);
	string getName();
	string getParty();


	~Candidate();
};