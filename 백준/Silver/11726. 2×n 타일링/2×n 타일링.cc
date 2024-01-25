#include <iostream>

using namespace std;

int DP[1001];
int n; // 2 x n 직사각형

void Sol()
{
    for(int col = 3; col <= n; col++)
        DP[col] = (DP[col - 1] + DP[col - 2])%10007;
}
                                                                                                                          
int main()
{
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;

    cin >> n;
    Sol();
    cout << DP[n];
}