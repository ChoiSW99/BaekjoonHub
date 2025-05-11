#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void BFS(vector<vector<int>>& Ground, int i, int j)
{
    int maxRow = Ground.size();
    int maxCol = Ground[0].size();
    
    // Ground[i][j]부터 BFS 탐색하여 1 -> 0으로 바꿔준다.
    
    queue<pair<int, int>> que;
    que.push({i, j});
    Ground[i][j] = 0;
    
    while(!que.empty())
    {
        auto [row, col] = que.front();
        que.pop();
        
        for(int i=0; i<4; ++i)
        {
            int nxtRow = row + dr[i];
            int nxtCol = col + dc[i];
            
            if(nxtRow < 0 || nxtRow >= maxRow || nxtCol < 0 || nxtCol >= maxCol)
                continue;
            
            if (Ground[nxtRow][nxtCol] == 0)
                continue;
            
            Ground[nxtRow][nxtCol] = 0;
            que.push({nxtRow, nxtCol});
        }
    }
}

int main()
{
    int T; cin >> T; // 테케T
    for(int t=0; t<T; ++t)
    {
        // 가로M, 세로N [N][M]
        int M, N; cin >> M >> N;
        vector<vector<int>> Ground(N, vector<int>(M, 0));
        
        // 배추개수K
        int K; cin >> K;
        
        for(int k=0; k < K; ++k)
        {
            // 배추위치 [Y][X]
            int X, Y; cin >>X >> Y;
            Ground[Y][X] = 1;
        }
        
        int result = 0;
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j)
            {
                if(Ground[i][j] == 1)
                {
                    BFS(Ground, i, j);
                    ++result;
                }
            }
        }
        
        cout << result << "\n";
    }
}