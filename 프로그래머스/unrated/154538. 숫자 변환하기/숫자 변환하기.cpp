#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int nums[1000001];

int solution(int x, int y, int n) {
    if(x==y)
        return 0;
    queue<pair<int, int>> que;
    que.push({x, 0});
    
    pair<int, int> now;
    while(!que.empty())
    {
        now = que.front();
        que.pop();
        if(nums[now.first] != 0 || now.first > y)
            continue;
        
        nums[now.first] = now.second;
        
        que.push({now.first+n, now.second+1});
        que.push({now.first*2, now.second+1});
        que.push({now.first*3, now.second+1});
        
    }
    
    if(nums[y] == 0)
        return -1;
    else
        return nums[y];
}