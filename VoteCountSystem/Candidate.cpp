#include "stdafx.h"
#include "Candidate.h"

Candidate::Candidate()
{

}

Candidate::Candidate(string theName, string theParty)
{
	name = theName;
	party = theParty;
}

void Candidate::setName(string newName)
{
	name = newName;
}

void Candidate::setParty(string newParty)
{
	party = newParty;
}

string Candidate::getName()
{
	return name;
}

string Candidate::getParty()
{
	return party;
}

Candidate::~Candidate()
{
}
