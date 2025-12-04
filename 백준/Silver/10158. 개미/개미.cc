#include <iostream>

using namespace std;

int w, h; // 격자 w, h
int p, q; // 초기위치 (p, q)
int t;    // 시간t

int Calc(int nowPos, int leftMove, int maxPos)
{
    int newPos = nowPos;
    
    int distToMax = maxPos-newPos;
    if (leftMove > distToMax)
    {
        // max까지 증가
        leftMove -= distToMax;
        newPos = maxPos;
        
        if (leftMove > newPos)
        {
            // 0까지 이동
            leftMove -= newPos;
            newPos = 0;
            
            
            // max쪽으로 이동
            newPos += leftMove;
            leftMove = 0;
        }
        else
        {
            newPos -= leftMove;
        }
    }
    else
    {
        newPos += leftMove;
    }
    
    return newPos;
}
// 방향전환 없이 쭉 간다고 치면 p+t에 위치. 이 때 2*w로 나눈 나머지만큼 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> w >> h >> p >> q >> t;
    
    // 처음에는 오른대각으로 움직인다.
    
    // x좌표(좌우) y좌표(상하) 따로 계산하기
    
    int moveX = t % (2 * w);    // 2*w만큼 이동하면 제자리임
    int newX = Calc(p, moveX, w);
    
    int moveY = t % (2 * h);
    int newY = Calc(q, moveY, h);
    
    cout << newX << " " << newY;
    
    return 0;
}