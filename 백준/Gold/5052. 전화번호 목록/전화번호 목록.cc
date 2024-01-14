#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// https://www.acmicpc.net/problem/5052 전화번호 목록

struct Trie
{
	bool isEnd;
	unordered_map<char, Trie*> child;

	Trie() { isEnd = false; }

	void Insert(string &str)
	{
		Trie* tr = this;
		for (int idx = 0; idx < str.size(); idx++)
		{
			if (tr->child[str[idx]] == nullptr)
				tr->child[str[idx]] = new Trie();

			if(idx == str.size()-1)
				tr->child[str[idx]]->isEnd = true;

			tr = tr->child[str[idx]];
		}
	}

	bool CheckConsistency(string& str)
	{
		Trie* tr = this;
		for (int idx = 0; idx < str.size()-1; idx++)
		{
			if (tr->child[str[idx]]->isEnd)
				return false;
			tr = tr->child[str[idx]];
		}
		return true;
	}
};

int main()
{
	//freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t-- > 0) 
	{
		vector<string> v;
		Trie trie;
		int n;
		string number;
		cin >> n;
		while (n-- > 0)
		{
			cin >> number;
			trie.Insert(number);
			v.push_back(number);
		}

		string answer = "YES";
		for (string& number : v)
		{
			bool isConsistent = trie.CheckConsistency(number);
			if (!isConsistent)
			{
				answer = "NO";
				break;
			}
		}
		cout << answer << '\n';

	}
}