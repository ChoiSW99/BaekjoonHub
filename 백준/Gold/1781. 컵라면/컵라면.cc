#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*

데드라인 역순으로 뽑아주기
x일에 뽑을 수 있는 것은 데드라인이 x 이상인 문제들

1    2    3    6
7 6  5 4  2 1  1
*/


int main()
{
    long long answer = 0;
    int N; cin >> N; // 문제 개수
    
    vector<vector<int>> problems(N+1);
    
    for(int n=0; n<N; ++n)
    {
        int deadline, cups; cin >> deadline >> cups;
        problems[deadline].push_back(cups);
    }
    
    // 컵라면 후보들
    priority_queue<int, vector<int>, less<>> pq;
    
    for(int time = N; time > 0; --time)
    {
        for(int t : problems[time])
            pq.push(t);
        
        if(!pq.empty())
        {
            // 후보중에 가장 많은 것 택하기
            answer += pq.top();
            pq.pop();
        }
    }
    
    cout << answer;
    
    return 0;
}