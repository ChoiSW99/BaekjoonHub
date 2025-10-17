#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

long long  Count[65][100];
// Count[i][j] == i자리 수일 때, i번째자리가 j일 때의 개수
// Count[i][j] = Count[i-1][0]부터 Count[i-1][j]까지의 합


// 줄어들지 않음) 완 <= 오
int main()
{
    int T; cin >>T;
    
    memset(Count, 0, sizeof(Count));
    for (int i=1; i<=64; ++i)
    {
        for (int j=0; j<=9; ++j)
        {
            if (i==1)
                Count[1][j] = 1;
            else
            {
                long long sum = 0;
                for (int k=0; k<=j; ++k)
                    sum += Count[i-1][k];
                
                Count[i][j] = sum;
            }
        }
    }
    
    
    for (int tc=0; tc<T; ++tc)
    {
        int n; cin >> n;
        cout << std::accumulate(begin(Count[n]), begin(Count[n])+10, (long long)0) << "\n";
    }
    
    return 0;
}
