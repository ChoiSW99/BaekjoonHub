#include <bits/stdc++.h>

using namespace std;

int Farm[49][49];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    string input;

    for (int t = 1; t <= T; t++)
    {
        int N; cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> input;
            for (int j = 0; j < N; j++)
            {
                Farm[i][j] = input[j] - '0';
            }
        }

        int value = 0;
        int mid = N / 2;
        int range = 0;

        for (int i = 0; i <= mid; i++)
        {
            for(int j = mid- range; j <= mid+ range; j++)
                value += Farm[i][j];
            range++;
        }

        range--;
        range--;

        for(int i = mid+1; i < N; i++)
        {
            for (int j = mid - range; j <= mid + range; j++)
                value += Farm[i][j];
            range--;
        }

        cout << "#" << t << " " << value << '\n';
    }
}
