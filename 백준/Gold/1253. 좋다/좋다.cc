// #define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// freopen("input.txt", "r", stdin);

	int N;
	vector<int> nums;
	int result = 0;

	cin >> N;

	if (N <= 2)
	{
		cout << 0;
		return 0;
	}

	while (N-- > 0)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}

	sort(nums.begin(), nums.end(), less<>());
	for (int i = 0; i < nums.size(); i++)
	{
		int n1 = 0;
		int n2 = nums.size() -1;

		while (n1 < n2)
		{
			if (n1 == i )
			{
				n1++;
				continue;
			}
			else if (n2 == i)
			{
				n2--;
				continue;
			}

			if (nums[n1] + nums[n2] == nums[i])
			{
				result++;
				break;
			}
			else if (nums[n1] + nums[n2] < nums[i])
				n1++;
			else if (nums[n1] + nums[n2] > nums[i])
				n2--;
		}
	}

	cout << result;
	
	return 0;
}