#include <iostream>
#include <vector>

using namespace std;

int N; // N개의 사람, 일
vector<vector<int>> D; // D[i][j]: 사람i가 일j를 하는 비용
vector<bool> HasWorked; // 사람 i가 일했는지 여부

// 백트래킹 문제
//
// 0~N-1번의 일을 하는 것을 완전탐색 돌리는데, 이전에 확인한 것보다 커지면


// DP[일 조합]: 일 조합에 해당하는 일들을 했을 때 비용 최소합
// DP의 요소 개수는 2^N개!!
// 2^20 * 4Byte -> 4MB (4*1024*1024)

vector<int> DP;

int Count1(int mask)
{
    int res = 0;
    while (mask > 0)
    {
        res += (mask & 1);
        mask >>= 1;
    }
    return res;
}

int main()
{
    cin >> N;
    
    DP.assign(1<<N, 1e9); // 0 ~ (2^N-1)
    DP[0] = 0;
    
    D.assign(N, vector<int>(N, 0));
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            cin >> D[i][j];
        }
    }
    
    
    for (int mask = 0; mask < (1<<N); ++mask) // 모든 조합에 대해,
    {
        int i = Count1(mask); // mask에서 1의 개수를 세면 -> 일한 사람 수 == 다음 일할 사람 번호
        
        for (int j=0; j<N; ++j) // 모든 일에 대해,
        {
            if (mask & (1 << j)) continue; // 이미 한 일이면 continue;
            
            
             // j번째 일을 i가 하면 -> mask | (1<<j) 의 일 조합이 됨.
             // 이 일 조합에 대해 이전에 확인했던 것과 비교하여 갱신 결정
            int nextMask = mask | (1<<j);
            DP[nextMask] = min(DP[nextMask], DP[mask] + D[i][j]);
            
        }
    }
    
    cout << DP[(1<<N)-1];
    
    return 0;
}
