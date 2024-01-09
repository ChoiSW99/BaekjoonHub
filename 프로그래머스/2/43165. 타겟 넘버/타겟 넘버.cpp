#include <iostream>
#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int target, int current, int depth, int& answer)
{
    if (depth == numbers.size())
    {
        if (current == target)
            answer++;
        return;
    }
    
    DFS(numbers, target, current + numbers[depth], depth + 1, answer);
    DFS(numbers, target, current - numbers[depth], depth + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, target, 0, 0, answer);
    return answer;
}