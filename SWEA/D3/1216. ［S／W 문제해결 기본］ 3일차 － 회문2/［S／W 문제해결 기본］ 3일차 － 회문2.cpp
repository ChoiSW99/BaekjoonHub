#include <bits/stdc++.h>

using namespace std;

char Map[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 10;

    for (int t = 1; t <= 10; t++)
    {
        cin >> t;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                cin >> Map[i][j];
        
        int longest = 0;

        // 가로
        for (int r = 0; r < 100; r++)
        {
            for (int length = 100; length >= 1; length--) // 각 행에서 가장 긴 문자열부터 확인
            {
                bool found = false;

                for (int stIdx = 0; stIdx <= 100 - length; stIdx++)
                {
                    // Map[r][st]부터 Map[r][st+length-1]까지
                    int endIdx = stIdx + length - 1;
                    bool isPalindrom = true;
                    for (int i = 0; i < length / 2; i++)
                    {
                        if (Map[r][stIdx+i] != Map[r][endIdx - i])
                        {
                            isPalindrom = false;
                            break;
                        }
                    }
                    if (isPalindrom) {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    longest = max(length, longest);
                    break;
                }
            }
        }

        // 세로
        for (int c = 0; c < 100; c++)
        {
            for (int length = 100; length >= 1; length--)
            {
                bool found = false;

                for (int stIdx = 0; stIdx <= 100 - length; stIdx++)
                {
                    int endIdx = stIdx + length - 1;
                    bool isPalindrom = true;
                    for (int i = 0; i < length / 2; i++)
                    {
                        if (Map[stIdx+i][c] != Map[endIdx - i][c])
                        {
                            isPalindrom = false;
                            break;
                        }
                    }
                    if (isPalindrom) {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    longest = max(length, longest);
                    break;
                }
            }
        }

        cout << "#" << t << " " << longest << '\n';
    }
}

