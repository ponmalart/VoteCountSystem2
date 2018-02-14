#include "stdafx.h"
#include "VoteCounter.h"
using namespace std;

VoteCounter::VoteCounter()
{
}

VoteCounter::~VoteCounter()
{
}

void VoteCounter::extract()
{
	string line;
	ifstream myfile("votes2.txt");
	if (myfile.is_open())
	{
		// get the 1st line
		getline(myfile, line);
		int i;
		int num = 0;
		string names;
		// this line contains the candidates and their party
		while (line.find(";") != -1)
		{
			i = line.find(";");
			names = line.substr(0, i);
			line = line.substr(i + 1);

			int Cnames = names.find(",");
			string name = names.substr(0, Cnames);
			string party = names.substr(Cnames);
			Candidate* c = new Candidate(name, party);
			candidates.push_back(c);
			num++;
		}
		// last candidate
		names = line;
		int Cnames = names.find(",");
		string name = names.substr(0, Cnames);
		string party = names.substr(Cnames);
		Candidate* c = new Candidate(name, party);
		candidates.push_back(c);

		// get ballots
		while (getline(myfile, line))
		{
			BallotPaper* ballot = new BallotPaper();
			int cdt = 0;
			int choice;
			while (line.find(",") != -1)
			{
				i = line.find(",");
				choice = stoi(line.substr(0, i));
				ballot->setPreference(choice, candidates[cdt]);

				line = line.substr(i + 1);
				cdt++;
			}
			ballot->setPreference(stoi(line), candidates[cdt]);
			ballots.push_back(ballot);
		}
		myfile.close();
	}

	else cout << "Unable to open file";

}

void VoteCounter::ComputerElection()
{
	int NoOfCdt = candidates.size();
	while (NoOfCdt > 1)
	{
		vector<vector<int>> count(NoOfCdt);

		//initialization of count
		for (int i = 0; i < NoOfCdt; i++)
		{
			count[i] = vector<int>(NoOfCdt);
			for (int j = 0; j < NoOfCdt; j++)
			{
				count[i][j] = 0;
			}
		}

		for (int b = 0; b < ballots.size(); b++)
		{
			for (int pref = 0; pref < NoOfCdt; pref++)
			{
				int index = 0;
				while ( index < candidates.size()-1 && candidates[index] != ballots[b]->getPreference(pref + 1))
				{
					index++;
				}
				count[index][pref]++;
			}
		}

		int indexOfLoser = 0;
		int NoOfVoteForLoser = count[0][0];
		for (int indexOfCdt = 0; indexOfCdt < NoOfCdt; indexOfCdt++)
		{
			if (NoOfVoteForLoser > count[indexOfCdt][0])
			{
				NoOfVoteForLoser = count[indexOfCdt][0];
				indexOfLoser = indexOfCdt;
			}
		}
		Candidate * Loser = candidates[indexOfLoser];
		cout << Loser->getName() << " is eliminated with " << to_string(NoOfVoteForLoser) << " votes.\n";
		//delete loser from candidates
		candidates.erase(candidates.begin() + indexOfLoser) ;

		//delete loser from all ballots in ballots
		for (int b = 0; b < ballots.size(); b++)
		{
			ballots[b]->remove(Loser);
		}
		NoOfCdt = candidates.size();
	}
	cout << candidates[0]->getName() << " is the winner";
	cout << candidates[0]->getParty() << " is the winner party.";
}