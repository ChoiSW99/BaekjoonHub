#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int, int>> que;
    
    que.push({numbers[0], 0});
    que.push({(-1) * numbers[0], 0});
    
    while(!que.empty())
    {
        auto now = que.front();
        que.pop();
        int curSum = now.first;
        int curIdx = now.second;
        
        // 확인하기
        if(curIdx == numbers.size()-1)
        {
            if(curSum == target)
                answer++;
            continue;
        }
        
        que.push({curSum+numbers[curIdx+1], curIdx+1});
        que.push({curSum-numbers[curIdx+1], curIdx+1});
    }
    
    return answer;
}