#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> m;
    m["0001101"] = 0;
    m["0011001"] = 1;
    m["0010011"] = 2;
    m["0111101"] = 3;
    m["0100011"] = 4;
    m["0110001"] = 5;
    m["0101111"] = 6;
    m["0111011"] = 7;
    m["0110111"] = 8;
    m["0001011"] = 9;

    int T; cin >> T;
    int N, M;

    int ignore=0;
    string ignoreStr;

    for (int t = 1; t <= T; t++)
    {
        while (ignore-- > 0)
            cin >> ignoreStr;
        
        cin >> N >> M;
        int num = 0;
        bool stop = false;

        for (int i = 0; i < N; i++)
        {
            if (stop) 
                break;
            string s;
            cin >> s;

            for (int j = M - 1; j >= 55; j--)
            {
                if (s[j] == '1')
                {
                    string sub = s.substr(j - 55, 56);
                    int sum = 0;
                    // 7비트씩 8개
                    for (int k = 0; k < 8; k++)
                    {
                        if (k % 2 == 1)
                        {
                            num += m[sub.substr(7 * k, 7)];
                            sum += m[sub.substr(7 * k, 7)];
                        }
                        else
                        {
                            num += 3*m[sub.substr(7 * k, 7)];
                            sum += m[sub.substr(7 * k, 7)];
                        }
                    }
                    int result = (num % 10 == 0) ? sum : 0;
                    cout << "#" << t << " " << result << '\n';
                    stop = true;
                    ignore = N - i - 1;
                    break;
                }
            }
        }
    }
}
