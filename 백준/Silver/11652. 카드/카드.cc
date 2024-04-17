/*
https://www.acmicpc.net/problem/11652
sort
사용자 정의 compare

string의 size() 와 length()는 모두 O(1)의 시간복잡도
*/

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

bool Comp(const pair<long, int>& p1, const pair<long, int>& p2)
{
	if(p1.second != p2.second ) return p1.second > p2.second;
	else
	{
		return p1.first < p2.first;
	}
}

unordered_map<long, int> cardSumMap; // 해쉬 테이블

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long card;
		cin >> card;
		cardSumMap[card]++;
	}

	vector<pair<long, int>> CardSumVec(cardSumMap.begin(), cardSumMap.end());

	sort(CardSumVec.begin(), CardSumVec.end(), Comp);
	cout << CardSumVec.front().first;
}
