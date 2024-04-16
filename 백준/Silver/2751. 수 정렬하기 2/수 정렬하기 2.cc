// https://www.acmicpc.net/problem/2751
// stable sort : 앞의 배열과 뒤의 배열에서 현재 가리키는 값이 같을 때, 앞의 원소를 먼저 넣어주는 것
// merge sort는 stable sort임. 
#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int temp[1000001];

void Merge(int st, int mid, int end)
{
	int l_idx = st;		// [st, mid) 
	int r_idx = mid;	//			[mid, end)
	for (int i = st; i < end; i++)
	{
		if (r_idx == end) // 오른쪽 배열을 다 넣음
			temp[i] = arr[l_idx++];
		else if (l_idx == mid) // 왼쪽 배열을 다 넣음
			temp[i] = arr[r_idx++];
		else if (arr[l_idx] <= arr[r_idx])
			temp[i] = arr[l_idx++];
		else
			temp[i] = arr[r_idx++];
	}

	for (int i = st; i < end; i++)
		arr[i] = temp[i];
}

void MergeSort(int st, int end) // [st, end) 배열
{
	if (st == end - 1) return; // 1칸짜리
	int mid = (st + end) / 2;
	MergeSort(st, mid);
	MergeSort(mid, end);

	Merge(st, mid, end);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	MergeSort(0, N);
	for (int i = 0; i < N; i++)
		cout <<  arr[i] << '\n';
}
