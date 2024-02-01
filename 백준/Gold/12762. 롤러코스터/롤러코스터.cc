//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

// https://www.acmicpc.net/problem/12762

int LeftUp[1001];
int RightUp[1001];

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, h;
	vector<int> pillar; // 기둥 높이
	pillar.push_back(0);

	cin >> n;

	for(int i=0; i<n; i++)
	{
		cin >> h;
		pillar.push_back(h);
	}

	LeftUp[1] = 1;
	RightUp[n] = 1;

	for (int now = 2; now <= n; now++)
	{
		int longest = 0;
		for (int idx = now-1; idx >= 1; idx--)
		{
			if (pillar[idx] > pillar[now]) // 기둥높이가 더 높으면
			{
				if (LeftUp[idx] > longest) // 최대 하이라이트 구하기
					longest = LeftUp[idx];
			}
		}
		LeftUp[now] = 1+longest;
	}

	for (int now = n-1; now >= 1; now--)
	{
		int longest = 0;
		for (int idx = now+1; idx <= n; idx++)
		{
			if (pillar[idx] > pillar[now])
			{
				if (RightUp[idx] > longest)
					longest = RightUp[idx];
			}
		}
		RightUp[now] = 1 + longest;
	}

	int result = -1;
	for (int idx = 1; idx <= n; idx++)
	{
		// 하이라이트 구간 나올 수 없는지 확인
		// 내려가는 구간 없으면 
		if (LeftUp[idx] == 1)
			continue;

		int l = LeftUp[idx] + RightUp[idx];
		if (result < l)
			result = l;
	}

	if (result == -1) // 하이라이트 구간이 하나도 나올 수 없는 경우
		cout << 1;
	else
		cout << result - 1;
	return 0;
}