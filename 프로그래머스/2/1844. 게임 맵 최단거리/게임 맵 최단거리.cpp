#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Robot {
public:
    int row;
    int col;
    int move;
    Robot(int r, int c, int m) : row(r), col(c), move(m) { }
};

int solution(vector<vector<int> > maps)
{
    int answer = -1;

    int n = maps.size(); 
    int m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    queue<Robot*> que;
    que.push(new Robot(0, 0, 1));
    visited[0][0] = 1;

    bool found = false;

    while (!que.empty()) {
        auto robot = que.front();
        que.pop();
        int curRow = robot->row;
        int curCol = robot->col;
        int curMove = robot->move;

        for (int i = 0; i < 4; i++) {
            int nextRow = curRow + dr[i];
            int nextCol = curCol + dc[i];
            int nextMove = curMove + 1;

            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m)
                continue;
            if (maps[nextRow][nextCol] == 0)
                continue;
            if (visited[nextRow][nextCol] == 1)
                continue;

            // 상대방 진영
            if (nextRow == n-1 && nextCol == m-1) {
                answer = nextMove;
                found = true;
                break;
            }

            que.push(new Robot(nextRow, nextCol, nextMove));
            visited[nextRow][nextCol] = 1;
        }

        if (found)
            break;
    }
    return answer;
}