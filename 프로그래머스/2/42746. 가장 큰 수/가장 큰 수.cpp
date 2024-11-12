#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 우선, 모두 문자열로 바꾼다.
// a+b > b+a로 어떻게 조합했을 때 더 큰지에 대해 비교함수를 작성한다.

bool comp(string a, string b)
{
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> nums;
    for(int n : numbers)
        nums.push_back(to_string(n));
    
    sort(nums.begin(), nums.end(), [](string a, string b) -> bool { return (a+b > b+a); } );
    if(nums[0] == "0")
        return "0";
    
    for(string n : nums)
        answer += n;
    return answer;
}
