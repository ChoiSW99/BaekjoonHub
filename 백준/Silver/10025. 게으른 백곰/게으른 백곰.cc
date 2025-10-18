    #include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N; // N개의 얼음양동이
int K; // 좌우로 K만큼 닿을 수 있음
// vector<int> Buckets; // 양동이 좌표
//vector<int> Ices; // 얼음의 양
//vector<long long> Sums; // Sums[i] == i좌표에서의 얼음들의 합

using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    
    // 범위: 2K+1
    // priority_queue에는 전체를 다 넣어놓는다.
    
    // queue에 현재 좌표에서 백곰이 닿는 얼음들의 좌표를 넣어놓는다.
    // .front() .back() .push(e) .pop()
    
    // <다음 확인할 좌표 찾는 방법>
    // 갱신하는 경우 -> 
    // 현재 포함된 것이 빠져나가거나 다음 pop한 것이 포함되어야하는 경우
    // -> nextLoc = .back()+2K vs pq.pop() 중 더 작은 경우
    
    // 현재 확인중인 좌표 p일 때, 
    // 다음 pop한 것의 좌표가 j이면
    
    // 오름차순 pq
    priority_queue<pii,  vector<pii>, greater<pii>> pq; 
    queue<pii> nowQue; // 닿는 양동이들 {좌표, 얼음 수}
    
    long long result = -1; // 얼음 최대합
    for (int n=0; n<N; ++n)
    {
        int g, c; cin >> g >> c; // 얼음의양, 양동이좌표
        pq.push({c, g}); // 양동이 좌표로 오름차순
    }
    
    // 초기 세팅
    pii firstBucket = pq.top();
    //int nowPos = firstBucket.first - K; // 초기 좌표
    long long nowSum = firstBucket.second;
    nowQue.push(firstBucket);
    pq.pop();
    
    while (!pq.empty())
    {
        pii nextBucket = pq.top();
        pq.pop();
        
        int nextBucketPos = nextBucket.first;
        int nextMinPos = nextBucketPos - (2*K);
        
        // 현재 큐에서 빼주기
        while (!nowQue.empty())
        {
            pii nowQueMin = nowQue.front();
            int nowQueMinPos = nowQueMin.first;
            if (nowQueMinPos < nextMinPos)
            {
                nowSum -= nowQueMin.second;
                nowQue.pop();
            }                
            else
                break;
        }
        
        nowQue.push(nextBucket);
        nowSum += nextBucket.second;
        result = max(result, nowSum);
    }
    
    cout << result << "\n";
    return 0;
}
