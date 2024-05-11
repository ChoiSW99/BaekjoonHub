#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 10;
    for (int t = 1; t <= T; t++)
    {
        cin >> t;
        int result = 0;
        string find; cin >> find;
        string input; cin >> input;
        for (int i = 0; i < input.size()-find.size()+1; i++)
        {
            if (input[i] == find[0])
            {
                bool same = true;
                for (int j = 1; j < find.size(); j++)
                {
                    if (input[i + j] != find[j])
                    {
                        same = false; 
                        break;
                    }
                }
                if (same)
                    result++;
            }
        }
       cout << "#" << t << " " << result << '\n';
    }
}

