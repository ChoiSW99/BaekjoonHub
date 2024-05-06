#include <bits/stdc++.h>

using namespace std;

// 1은 N극 성질 (아래로)
// 2는 S극 성질 (위로)
int MAP[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 10;

    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        int cnt = 0;
        
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                cin >> MAP[i][j];

        // 각 col별로 위에서 아래로 탐색.
        // 1을 찾은 상태(hasOne==true)에서 탐색하다가 2를 찾으면 cnt++, hasOne=false
        for (int j = 0; j < 100; j++)
        {
            bool hasOne = false;
            for (int i = 0; i < 100; i++)
            {
                if (MAP[i][j] == 1)
                    hasOne = true;
                else if (MAP[i][j] == 2)
                {
                    if (hasOne)
                    {
                        cnt++;
                        hasOne = false;
                    }
                }
            }
        }
        cout << "#" << t << " " << cnt << '\n';
    }
}