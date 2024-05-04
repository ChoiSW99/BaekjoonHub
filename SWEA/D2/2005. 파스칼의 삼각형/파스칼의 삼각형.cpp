//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int Num[10][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "#" << t << '\n';

        int N;
        cin >> N;

        // (0, 0)
        // (1, 0) (1,1)
        // (2,0) (2,1) (2,2)

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    Num[i][j] = 1;
                    cout << Num[i][j] << " ";
                }
                else
                {
                    Num[i][j] = Num[i - 1][j - 1] + Num[i - 1][j];
                    cout << Num[i][j] << " ";
                }
            }
            cout << '\n';
        }
    }
}
