#include <iostream>

using namespace std;

// (x, y)에 주사위 놓여져 있음
// 초기 주사위는 모든 면이 0

// 바닥이 0이면,        주사위->바닥으로 복사
// 바닥이 0이 아니면,   바닥->주사위로 복사 & 바닥은 0으로 됨

// 지도에 쓰여 있는 수는 0~9

int N, M; // 가로 세로 크기
int X, Y; // 주사위 좌표
int K;    // 명령 개수
// 명령) 1동 2서 3북 4남

struct Dice
{
    // 상 하 좌 우 위 아래(바닥면)
    int row, col;
    int up, down, left, right, top, bottom;
    
    Dice(){
        row = col = -1;
        up = down = left = right = top = bottom = 0;
    }
};

int Map[21][21];

// 동서북남 순서.
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

int main()
{
    cin >> N >> M;
    cin >> X >> Y;
    cin >> K;
    
    for (int n=0; n<N; ++n)
        for (int m=0; m<M; ++m)
            cin >> Map[n][m];
            
    Dice dice;
    dice.row = X; dice.col = Y;
            
    for (int k=0; k<K; ++k)
    {
        int dir; cin >> dir; // 1동 2서 3북 4남
        
        // 1동 -> left=bottom top=left right=top bottom=right?
        // 2서 -> left=top top=right right=bottom bottom=left?
        // 3북 -> up=top top=down down=up bottom=up? 
        // 4남 -> up=bottom top=up down=top bottom=down?
        
        int nextR = dice.row + dr[dir-1];
        int nextC = dice.col + dc[dir-1];
        
            // 유효 범위
        if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) continue;
        
        dice.row = nextR;
        dice.col = nextC;
        
        if(dir == 1) // 동
        {
            int prevRight = dice.right;
            dice.right = dice.top;
            dice.top = dice.left;
            dice.left = dice.bottom;
            dice.bottom = prevRight;
        }
        else if(dir == 2) // 서
        {
            int prevLeft = dice.left;
            
            dice.left = dice.top;
            dice.top = dice.right;
            dice.right = dice.bottom;
            dice.bottom = prevLeft;
        }
        else if(dir == 3) // 북
        {
            int prevUp = dice.up;
            
            dice.up = dice.top;
            dice.top = dice.down;
            dice.down = dice.bottom;
            dice.bottom = prevUp;
        }
        else if(dir == 4) // 남
        {
            int prevDown = dice.down;
            
            dice.down = dice.top;
            dice.top = dice.up;
            dice.up = dice.bottom;
            dice.bottom = prevDown;
        }
        
        if(Map[nextR][nextC] == 0) // 0이면 주사위->바닥 복사
        {
            Map[nextR][nextC] = dice.bottom;
        }
        else // 0이 아니면, 바닥->주사위 바닥면 복사
        {
            dice.bottom = Map[nextR][nextC];
            Map[nextR][nextC] = 0;
        }
        
        cout << dice.top << "\n";
    }
}

