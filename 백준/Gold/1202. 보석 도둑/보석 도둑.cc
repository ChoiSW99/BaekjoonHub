#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

using pii = pair<int, int>;


    // 적게 담을 수 있는 가방부터 최대한 비싼거 담기
    // 가방에 담는 무게 오름차순 정렬
    // 보석) 무게로 오름차순 

int main()
{
    long long answer = 0;
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // 보석개수N  가방개수K
    int N, K; cin >> N >> K;
    
    vector<pii> jewels;
    
    vector<int> bags;
    
    for(int n=0; n<N; n++)
    {
        // 무게, 가격
        int wgt, price; cin >> wgt >> price;
        jewels.push_back({wgt, price});
    }
    sort(begin(jewels), end(jewels), less<>()); // 오름차순 정렬
    
    for(int k=0; k<K; k++)
    {
        int x; cin >> x;
        bags.push_back(x);
    }
    sort(begin(bags), end(bags), less<>()); // 오름차순 정렬
    
    
    int jewelIdx=0;
    priority_queue<int, vector<int>, less<int>> pq; // 내림차순 PQ

    for(int b : bags)
    {
        // 모든 보석에 대해 && 현재 가방의 적재 무게 이하면
        while(jewelIdx < N && jewels[jewelIdx].first <= b)
        {
            pq.push(jewels[jewelIdx].second);
            ++jewelIdx;
        }
        
        if(!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
            
    }
    
    

    cout << answer;
    
    return 0;
}