#include <bits/stdc++.h>

using namespace std;

int Farm[49][49];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 10;
    vector<int> v(8);

    for (int t = 1; t <= T; t++)
    {
        cin >> t;
        for (int i = 0; i < 8; i++)
            cin >> v[i];

        int minNum = *min_element(v.begin(), v.end());
        int minMulti = minNum / 15;
        if (minNum % 15 == 0)
            minMulti--;
        for (int i = 0; i < 8; i++)
            v[i] = v[i] - 15 * minMulti;

        int firstIdx = 0;
        int sub = 0; // 뺄 값
        bool find = false;
        while (true)
        {
            v[firstIdx] -= (sub + 1);
            if (v[firstIdx] <= 0)
            {
                v[firstIdx] = 0;
                find = true;
            }

            sub = (sub + 1) % 5; // 0~4
            firstIdx = (firstIdx + 1) % 8; // 0~7

            if (find)
            {
                cout << "#" << t << " ";
                for (int i = firstIdx; i < firstIdx+8; i++)
                    cout << v[i%8] << " ";
                break;
            }
        }
        cout << '\n';
    }
}
