#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 1; t <= T; t++)
    {
        string bits; cin >> bits;
        int cnt = 0;
        char cur = '0';
        for (int i = 0; i < bits.length(); i++)
        {
            if (bits[i] != cur)
            {
                cnt++;
                cur = bits[i];
            }
        }
        cout << "#" << t << " " << cnt << '\n';
    }
}
// 맨 앞에서부터 0 or 1로 바뀔 때마다 cnt++
