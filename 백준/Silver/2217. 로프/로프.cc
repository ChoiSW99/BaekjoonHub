#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N; // 로프 개수
vector<int> maxWeights;

// 들 수 있는 최대 중량을 반환해야한다.

// 들 수 있는 최대 중량
//  = 가장 적게 들 수 있는 로프 * 현재 택한 로프들 개수

int main()
{
    cin >> N; 
    maxWeights.assign(N, 0);
    for (int n=0; n<N; ++n)
    {
        // 각 로프 최대 중량
        cin >> maxWeights[n];
    }
    
    // 내림차순 정렬
    sort(maxWeights.begin(), maxWeights.end(), greater<int>());
    
    int res = 0; // 들어올릴 수 있는 최대 중량 (반환)
    
    int pickCnt = 1;
    for (int n=0; n<N; ++n, ++pickCnt)
    {
        res = max(res, pickCnt * maxWeights[n]);
    }
    cout << res;
    return 0;
    
}

// 5 3 2 2 1

// 5
// 6
// 6
// 8
// 5

// 2개의 로프를 사용할 때,
// 5와 2가 아닌,
// 제일 많이 들 수 있는 로프 2개를 선택해야한다. -> 그리디!!

// 로프를 하나씩 더 사용할 때마다, 최대한 많이 들 수 있는 로프를 선택하면서 진행한다.