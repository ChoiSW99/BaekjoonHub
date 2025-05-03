#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

// DP[a][b] = DP[a-1][b] + DP[a][b-1]

int Board[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(auto p : puddles)
        Board[p[1]][p[0]] = -1;
    
    Board[1][1] = 1;
    
    for(int r=1; r<= n; r++)
    {
        for(int c=1; c<=m; c++)
        {
            if(r==1 && c==1) continue;
            if(Board[r][c] == -1) continue;
            
            int up = 0;
            int left = 0;
            if(Board[r-1][c] != -1)
                up = Board[r-1][c];
            
            if(Board[r][c-1] != -1)
                left = Board[r][c-1];
            
            Board[r][c] = (up + left) % 1000000007;
        }
    }
    
    return Board[n][m];
}
