#include <iostream>
#include <vector>

using namespace std;

int Stat[21][21];

bool isStartTeam[21];

int n; // 총원
int minDiff = 1e9;

void ChooseTeam(int memberCnt, int x)
{
	if (memberCnt == n / 2)
	{
		vector<int> startTeam;
		vector<int> linkTeam;
		int sumStart = 0;
		int sumLink = 0;

		for (int i = 1; i <= n; i++)
		{
			if (isStartTeam[i])
				startTeam.push_back(i);
			else
				linkTeam.push_back(i);
		}

		for (int s1 : startTeam)
		{
			for (int s2 : startTeam)
			{
				sumStart += Stat[s1][s2];
			}
		}

		for (int l1 : linkTeam)
		{
			for (int l2 : linkTeam)
			{
				sumLink += Stat[l1][l2];
			}
		}
		minDiff = min(minDiff, abs(sumStart - sumLink));
	}
	else
	{
		for (int i = x+1; i <= n; i++)
		{
			if (!isStartTeam[i])
			{
				isStartTeam[i] = true;
				ChooseTeam(memberCnt + 1, i);
				isStartTeam[i] = false;
			}
		}
	}
}

int main()
{
	 cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> Stat[i][j];
		}
	}

	ChooseTeam(0, 0);

	cout << minDiff;
	return 0;
}