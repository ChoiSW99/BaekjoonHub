#include <string>
#include <vector>

using namespace std;

// 탐색 범위
// 1 ~ 10억*10억분
// 양끝을 left와 right로 잡고 이분탐색
// x분일 때, 각 심사대마다 x/time만큼 사람처리

// log_2(10^18)는 2^10 => 10^3이라고 잡으면, 6번이므로 약 60
// 즉 대략 60회만에 정답을 찾게된다.

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 1;
    long long right = 1e18;
    
    // 이분탐색
    while(left < right) // 60회
    {
        long long mid = (left + right) / 2;
        
        long long cnt = 0; // 처리가능
        for(int t : times) // 10만회
            cnt += (mid / t);
        
        if (cnt < n)
        {
            left = mid+1;
        }
        else
        {
            right = mid;
            answer = mid;
        }
            // cnt == n인데, 더 적게 걸리는 시간이 있을 수 있음
    }
    
    return answer;
}