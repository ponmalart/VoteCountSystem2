#include "stdafx.h"
#pragma once
#include <map>
#include "Candidate.h"
using namespace std;

class BallotPaper
{
public:
	BallotPaper();
	~BallotPaper();

	void setPreference(int n, Candidate * c);
	Candidate * getPreference(int n);
	void remove(Candidate* c);

private:
	map<int, Candidate*> preference;
};

