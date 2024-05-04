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
        int P, Q, R, S, W;
        cin >> P >> Q >> R >> S >> W;

        int A = 0;
        int B = 0;

        A = W * P;
        B = W <= R ? Q : Q + S * (W - R);
        cout << "#" << t << " " << min(A, B) << '\n';
    }
}
