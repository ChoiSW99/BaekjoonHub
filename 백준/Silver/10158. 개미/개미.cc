#include <iostream>

using namespace std;

int w, h; // 격자 w, h
int p, q; // 초기위치 (p, q)
int t;    // 시간t


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> w >> h >> p >> q >> t;
    
    // 처음에는 오른대각으로 움직인다.
    
    // x좌표(좌우) y좌표(상하) 따로 계산하기
    
    int newX = (p+t) % (2*w);
    if (newX > w) // 꺾임 (w를 넘어간 부분을 w 아래로 접어줌)  
        newX = (2*w) - newX;
        
    int newY = (q+t) % (2*h);
    if (newY > h)
        newY = (2*h) - newY;
    
    cout << newX << " " << newY;
    
    return 0;
}