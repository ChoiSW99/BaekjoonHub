#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 한 번에 최대 2명 탄다
// 무게제한 limit
//  50,000명
//  40 ~ 240 kg

// 20 50 50 80 -> limit = 100 -> 2번

// vector<int> p(241); // 각 무게 당 사람 수
// 가장 작은 사람 찾고, limit - min 이하 중 가장 큰 사람 찾으면 베스트
// 종료조건( )
int solution(vector<int> people, int limit) {
    int answer = 0;

    int leftCnt = people.size(); // 구출대상 수
    vector<int> weight(241);
    for(int w : people)
        weight[w]++;
    
    int mini = 1;
    while(leftCnt > 0)
    {
        for(int i = mini; i <= 240; i++)
        {
            if(weight[i] > 0)
            {
                mini = i;
                weight[mini]--;
                leftCnt--;
                //cout << i << " ";
                break;
            }
        }
        
        for(int i= limit-mini; i >= mini; i--)
        {
            if(weight[i] > 0)
            {
                weight[i]--;
                leftCnt--;
                //cout << i << "\n";
                break;
            }
        }
        
        answer++;
    }
    
    
    return answer;
}