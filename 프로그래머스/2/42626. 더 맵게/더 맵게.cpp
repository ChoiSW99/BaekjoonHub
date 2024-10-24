#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
우선순위 큐

모든 음식의 스코빌 지수 >= K 될때까지
    가장 낮은게 K보다 작은지 확인
    
    두번쨰로 낮은게 있는지 확인
    가장 낮은 + 2*두번째로 낮은 -> 섞기
    섞었는데 K보다 작으면 -> 또 더해줘야함
    
    섞은거 다시 넣기
    섞는 횟수++;

0 <= K <= 10억(1e9)
K = 1e9일 때
    (1e9-2) + 2*(1e9-1) 가능. 이는 int 범위 초과 -> long long 사용

2 <= 음식개수(scoville.size()) <= 1백만
0 <= scoville[i] <= 1백만

*/

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<long long, vector<long long>, greater<>> foods; // 오름차순
    for(int scov : scoville)
        foods.push(scov);
    
    // priority_queue 순회 못하나..?
    //for(long long s : foods)
    //    cout << s << " ";
    
    while(!foods.empty())
    {
        long long top = foods.top();
        foods.pop();
        // 가장 낮은 스코빌 지수 >= K
        // 모든 스코빌이 >= K
        if(top >= K)
            break;
        
        // 2번째로 작은게 없으면..(가장 낮은애 조건 만족시키도록 섞기 불가능) -1 return
        if(foods.size() == 0)
        {
            answer = -1;
            break;
        }
        long long secondTop = foods.top();
        foods.pop();
        
        long long mixed = top + secondTop * 2;

        answer++;
        foods.push(mixed);
    }
    return answer;
}