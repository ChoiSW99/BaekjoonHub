#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
vector<bool> visited;

// 길이가 M인 수열을 모두 구하기!
// N개의 자연수 중 M개를 고른 수열

// 중복X, 오름차순으로 출력

void Solv(vector<int>& nums, vector<int>& picked, set<vector<int>>& s, int lastIdx)
{
    // base case) M개 뽑음
    if (picked.size() == M)
    {
        if (s.find(picked) == s.end()) // 중복 방지
        {
            for (int p : picked)
                cout << p << " ";
            cout << "\n";
            s.insert(picked);
        }
        return;
    }
    
    
    // 맨 마지막에 뽑은 다음부터 수열에 추가하기
    for (int i=0; i < N; ++i)
    {
        if(visited[i]) continue;
         
        picked.push_back(nums[i]);
        visited[i] = true;
        Solv(nums, picked, s, i);
        
        picked.pop_back();
        visited[i] = false;
    }
}

// 1 7 9 9

int main()
{
    cin >> N >> M;
    vector<int> nums(N);
    set<vector<int>> s;
    vector<int> picked;
    visited.assign(N, false);
    
    for (int n=0; n<N; ++n)
    {
        cin >> nums[n];
    }
    
    // 오름차순 정렬
    sort(nums.begin(), nums.end(), less<int>());

    Solv(nums, picked, s, -1);
    
    return 0;
}
