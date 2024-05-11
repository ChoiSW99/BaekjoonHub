#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 10;

    for (int t = 1; t <= T; t++)
    {
        list<int> lst;
        int N; cin >> N;
        for (int i = 0; i < N; i++)
        {
            int x; cin >> x;
            lst.push_back(x);
        }
        int cmdCnt; cin >> cmdCnt;
        for(int i=0; i<cmdCnt; i++)
        {
            char l;
            int x, y, s;
            cin >> l >> x >> y;

            auto iter = lst.begin();
            advance(iter, x);

            for (int c = 0; c < y; c++) 
            {
                int s; cin >> s;
                lst.insert(iter, s);
            }
        }
        cout << "#" << t << " ";
        auto iter = lst.begin();
        for (int i=0; i < 10 && iter!=lst.end(); i++, iter++)
            cout << *iter << " ";
        cout << '\n';
    }
}

