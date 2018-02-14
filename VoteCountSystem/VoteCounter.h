#include "stdafx.h"
#pragma once
#include "Candidate.h"
#include "BallotPaper.h"
#include <vector>
#include <fstream>
#include <iostream>

class VoteCounter
{
public:
	VoteCounter();
	~VoteCounter();

	void extract();
	void ComputerElection();

private:
	vector<Candidate*> candidates;
	vector<BallotPaper*> ballots;
};

