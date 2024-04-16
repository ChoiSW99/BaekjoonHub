/*
https://www.acmicpc.net/problem/15688
counting sort
*/

#include <bits/stdc++.h>

using namespace std;

int digitsSum(const string& s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
			sum += s[i]-'0';
	}
	return sum;
}

bool compare(const string& s1, const string& s2)
{
	if (s1.length() < s2.length()) return true;
	else if (s1.length() > s2.length()) return false;
	else
	{
		int s1Sum = digitsSum(s1);
		int s2Sum = digitsSum(s2);
		if (s1Sum < s2Sum)	return true;
		else if (s1Sum > s2Sum)	return false;
		else 
		{
			for (int j = 0; j < s1.length(); j++)
			{
				if (s1[j] != s2[j]) return s1[j] < s2[j];
			}
		}
	}
}

string serial[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> serial[i];
	}

	sort(serial, serial + N, compare);

	for (int i = 0; i < N; i++)
		cout << serial[i] << '\n';
}
