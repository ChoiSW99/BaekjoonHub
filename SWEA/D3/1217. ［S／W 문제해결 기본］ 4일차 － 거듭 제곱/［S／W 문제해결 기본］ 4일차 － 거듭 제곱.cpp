#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 10;

    for (int t = 1; t <= T; t++)
    {
        cin >> t;
        int result = 1;
        int n; cin >> n;
        int m; cin >> m;
        for (int i = 0; i < m; i++)
        {
            result *= n;
        }
       cout << "#" << t << " " << result << '\n';
    }
}

