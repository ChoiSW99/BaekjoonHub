#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

struct MapBlock{
    int number; // 섬 번호 -1, -2, ...
    int dist;
};

MapBlock Map[101][101];

// 섬 번호 매기기 (-1, -2 ...)
void SetIslandMapBFS()
{
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    int islandNumber = 0;
    for (int r=0; r<N; ++r)
    {
        for (int c=0; c<N; ++c)
        {
            if (Map[r][c].number == 1 && !visited[r][c])
            {
                --islandNumber;
                
                // BFS
                queue<pair<int ,int>> que;
                
                que.push({r, c});
                visited[r][c] = true;
                Map[r][c].number = islandNumber;
                
                while(!que.empty())
                {
                    int row = que.front().first;
                    int col = que.front().second;
                    que.pop();
                    
                    for(int i=0; i<4; ++i)
                    {
                        int nRow = row + dr[i];
                        int nCol = col + dc[i];
                        
                        if(nRow < 0 || nRow >= N || nCol < 0 || nCol >= N)
                            continue;
                            
                        if (visited[nRow][nCol])
                            continue;
                        
                        if (Map[nRow][nCol].number != 1)
                            continue; // 섬이 아님
                        
                        que.push({nRow, nCol});
                        visited[nRow][nCol] = true;
                        Map[nRow][nCol].number = islandNumber;
                    }
                }
            }
        }
    }
}

// 특정 섬 기준으로 최단거리 반환하기
int BFS(int startNumber, vector<vector<bool>>& checked)
{
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int, int>> que;
    for (int r=0; r<N; ++r)
    {
        for (int c=0; c<N; ++c)
        {
            if (Map[r][c].number == startNumber)
            {
                que.push({r, c});
                checked[r][c] = true;
                dist[r][c] = 0;
            }
        }
    }
    
    
    while(!que.empty()){
        int r = que.front().first;
        int c = que.front().second;
        que.pop();
        
        for (int i=0; i<4; ++i)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            
            int& nDist = dist[nr][nc];
            if (nDist != -1) continue;
            
             // 다른 섬 만남
            if (Map[nr][nc].number < 0)
                return dist[r][c];
            
            que.push({nr, nc});
            nDist = dist[r][c] + 1;
        }
    }
    return 1e9;
}

// 최단 다리 길이 구하기
int Solv()
{
    int ret = 1e9;
    
    vector<vector<bool>> checked(N, vector<bool>(N, false));
    
    for (int r=0; r<N; ++r)
    {
        for (int c=0; c<N; ++c)
        {
            int number = Map[r][c].number;
            if (checked[r][c] == false && number < 0)
            {
                ret = min(ret, BFS(number, checked));
            }
        }
    }
    
    return ret;
}

int main()
{
    cin >> N; // 지도의 크기N
    for (int r=0; r<N; ++r)
    {
        for(int c=0; c<N; ++c)
        {
            cin >> Map[r][c].number;
        }
    }
    
    SetIslandMapBFS();
    
    cout << Solv();
}

