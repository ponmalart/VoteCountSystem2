#include "stdafx.h"
#include "BallotPaper.h"


BallotPaper::BallotPaper()
{
}

BallotPaper::~BallotPaper()
{
}

void BallotPaper::setPreference(int n, Candidate * c)
{
	this->preference[n] = c;
}

Candidate * BallotPaper::getPreference(int n)
{
	return this->preference[n];
}

void BallotPaper::remove(Candidate* c)
{
	int pref = 1;
	while (preference[pref] != c)
	{
		pref++;
	}
	//to get indexOfCdt in preference
	int size = preference.size();
	for (int i = pref; i < size; i++)
	{
		preference[i] = preference[i + 1];
	}
	preference.erase(preference.size() + 1);
}