#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> DP(money.size(), 0);
    
    // DP[i] = i번 집까지 털기 고려했을 때의 최댓값
    // DP[n] = max( DP[n-1], DP[n-2] + money[n] )
    
    // 0번 집 털었을 때
    fill(DP.begin(),  DP.end(), 0);
    DP[0] = money[0];
    DP[1] = money[0];
    DP[2] = max(DP[1], DP[0] + money[2]);
    
    for(int i=3; i<money.size()-1; ++i)
    {
        DP[i] = max(DP[i-1], DP[i-2] + money[i]);
    }
    int answer1 = DP[money.size()-2];
    
    // 0번 집 안털었을 때
    fill(DP.begin(),  DP.end(), 0);
    DP[0] = 0;
    DP[1] = money[1];
    DP[2] = max(DP[1], DP[0] + money[2]);
    
    for(int i=3; i<money.size(); ++i)
    {
        DP[i] = max(DP[i-1], DP[i-2] + money[i]);
    }
    int answer2 = DP[money.size()-1];
    
    answer = max(answer1, answer2);
    
    return answer;
}

/*
n-1번째 털기 기준!!

DP[n]
      = DP[n-3] + money[n-1]
          vs 
        DP[n-2] + money[n]
        
DP[0] = 1
DP[1] = 2
DP[2] = money[1] vs DP[0] + money[2]
DP[3] = DP[2] vs DP[1] + money[3]


*/