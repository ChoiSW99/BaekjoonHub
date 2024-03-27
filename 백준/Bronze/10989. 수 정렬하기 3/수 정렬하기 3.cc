// https://www.acmicpc.net/problem/10989 수 정렬하기

#include <iostream>
	
using namespace std;

// 계수정렬 ( counting sort )
// 1. 데이터가 양수
// 2. 데이터 크기가 매우 작음 ( 자릿수!  개수가 아니라.) 
//    이유? 숫자의 크기가 10000이하일 때, 10001 배열을 만들어 사용하기 때문!

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int N;
	cin >> N;
	int count[10001] = { 0, };
	int number = 0;
	
	for (int i = 1; i <= N; i++)
	{
		cin >> number;
		count[number]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (count[i] != 0)
		{
			for (int j = 0; j < count[i]; j++)
				cout << i << '\n';
		}
	}


}