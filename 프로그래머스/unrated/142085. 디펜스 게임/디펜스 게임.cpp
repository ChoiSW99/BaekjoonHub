#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    if (k >= enemy.size())
        return enemy.size();
    int sum = 0;
    int cnt = k;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int idx = 0; idx < k; idx++)
        minHeap.push(enemy[idx]);
    
    for (int idx = k; idx < enemy.size(); idx++)
    {
        minHeap.push(enemy[idx]);
        if (sum + minHeap.top() > n)
            break;
        
        sum += minHeap.top(); minHeap.pop();
        
        
        cnt++;
    }

    return cnt;
}