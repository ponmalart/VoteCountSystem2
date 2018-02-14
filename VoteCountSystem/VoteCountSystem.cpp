// VoteCountSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include "VoteCounter.h"

using namespace std;

int main()
{
	VoteCounter vote_counter;
	vote_counter.extract();
	vote_counter.ComputerElection();
	cin.ignore();
	system("pause");
}

