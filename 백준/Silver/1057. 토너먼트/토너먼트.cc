#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, a, b;
    cin >> N >> a >> b;

    int round = 0;
    while (a != b) {
        
        // a가 홀수면 a/2+1, 짝수면 a/2
        // 이 때,  (a+1)/2로 위의 2가지 경우를 함께 고려해줄 수 있다.
        a = (a + 1) / 2; 
        
        b = (b + 1) / 2;
        round++;
    }

    cout << round;
    return 0;
}
