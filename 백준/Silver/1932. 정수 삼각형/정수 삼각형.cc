#include <iostream>
#include <cstring>

using namespace std;

int Nums[501][501];
// Nums의 0,0부터 0,n까지는 0으로 한칸씩 다 채워버리기

int DP_Sum[501][501];
// DP_Sum[a][b] = max(DP_Sum[a-1][b-1], DP_Sum[a-1][b])+Nums[a][b]

// 100,000Byte(25,000*4) -> 100KB -> 0.1MB

int main()
{
    int n; cin >> n;
    memset(Nums, 0, sizeof(Nums));
    memset(DP_Sum, 0, sizeof(Nums)); // -1은 아직 계산 안 됨을 뜻함
    int result = -1;
    
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=i; ++j)
        {
            cin >> Nums[i][j];
        }
    }
    
    for (int a=1; a<=n; ++a)
    {
        for (int b=1; b<=a; ++b)
        {
            DP_Sum[a][b] = max(DP_Sum[a-1][b-1], DP_Sum[a-1][b])+Nums[a][b];
            
            if (a == n)
            {
                result = max(result, DP_Sum[a][b]);
            }
        }
    }
    
    cout << result;
    return 0;
}