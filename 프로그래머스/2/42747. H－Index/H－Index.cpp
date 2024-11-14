#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 내림차순 정렬
    sort(citations.begin(), citations.end(), greater<>());

    // 6 5 5 1 1 0 -> h-index는 3
    // 1<= h <= n
    for(int i=0; i<citations.size(); i++)
    {
        if(citations[i] >= i+1)
        {
            answer = i+1;
        }
        else
            break;
    }
    
    return answer;
}