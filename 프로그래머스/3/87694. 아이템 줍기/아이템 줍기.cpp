#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>>& board, int startC, int startR, int endC, int endR);

using pii = pair<int, int>;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

/*
51 x 51 보드

    상하좌우로 이동
    다각형의 테두리를 따라 이동
    
    디폴트 0
    테두리 2
    내부 1
    
*/

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    // board를 2배 사이즈로 만들어줌으로써, 
    // ㄷ 자 모양의 길에서 바로 위로 가지 않고 ㄷ자를 따라서 휘어가도록 할 수 있다.

    vector<vector<int>> board(102, vector<int>(102, 0));
    for(vector<int>& rect : rectangle)
    {
        // 좌측하단(rect[0], rect[1]), 우측상단(rect[2], rect[3])
        //
        // 테두리는 2로, 내부는 1로 채우기
        // 테두리 처리) 
        //      1이면 채워진 부분이므로, pass !!
        //      2이면, 테두리 부분이므로, pass
        //      0이면, 2로 바꾼다.
        
        // 내부 처리)
        //      1이면 pass
        //      2이면 1로
        //      0이면 1로
        
        int lowC = rect[0] * 2;
        int lowR = rect[1] * 2;
        int highC = rect[2] * 2;
        int highR = rect[3] * 2;
        

        for(int r=highR; r>=lowR; --r)
        {
            for(int c=highC; c>=lowC; --c)
            {
                if(r < highR && r > lowR && c < highC && c > lowC)
                {
                    // 내부 처리
                    board[r][c] = 1;
                }
                else
                {
                    // 테두리 처리
                    if(board[r][c] != 1)
                        board[r][c] = 2;
                }
            }
        }
    }
    
   /*for(int r=100; r>=0; --r)
    {
        for(int c=0; c<30; ++c)
        {
            cout << board[r][c] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "\n";*/
    
    // BFS
    answer = BFS(board, characterX*2, characterY*2, itemX*2, itemY*2) / 2;
    
    return answer;
}

int BFS(vector<vector<int>>& board, int startC, int startR, int endC, int endR)
{
    int ret = 0;
    
    int boardR = board.size();
    int boardC = board[0].size();
    
    queue<pii> que;
    vector<vector<int>> visited(boardR, vector<int>(boardC, -1));
    // row col로 넣기
    visited[startR][startC] = 0;
    
    que.push({startR, startC});
    
    while(!que.empty())
    {
        pii now = que.front();
        que.pop();
        for(int i=0; i<4; i++)
        {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            
             // 유효 범위
            if(nr < 0 || nr >= boardR || nc < 0 || nc >= boardC)
                continue;
            
             // 테두리인지 확인
            if(board[nr][nc] != 2)
                continue;
            
             // 이미 방문한 지점인지 확인
            if(visited[nr][nc] != -1)
                continue;
            
            visited[nr][nc] = visited[now.first][now.second]+1;
            que.push({nr, nc});
            
            if(nr == endR && nc == endC)
            {
                return ret = visited[nr][nc];
            }
            
        }
    }
    return ret = -1;
}

