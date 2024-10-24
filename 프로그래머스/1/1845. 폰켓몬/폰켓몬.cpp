#include <vector>
#include <unordered_map>
using namespace std;


/*
N/2마리 가져가기
같은 종류면, 같은 번호
최대한 많은 종류 갖기

1. 4마리 1종류 -> 결과:1
2. 4마리 3종류 -> 결과:2
3. 4마리 2종류 -> 결과:3

*/
int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int, int> m;
    int keyCount = 0;
    
    for(int num : nums){
        if(m[num]==0)
            keyCount++;
        
        m[num]++;
    }
    answer = min((int)nums.size()/2, keyCount);
    
    return answer;
}