#include <iostream>
#include <queue>

// sort함수는 > 면 내림차순 & sort에 less 넣으면 오름차순
// pq는       > 면 오름차순 & less 넣으면 내림차순

using namespace std;

int N; // 행성 개수
vector<vector<int>> Cost;
vector<bool> Visited;

using pii = pair<int, int>;

struct Comp{
    bool operator()(const pii p1, const pii p2)
    {
        return p1.first > p2.first; // 오름차순
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    Cost.assign(N, vector<int>(N, 0));
    Visited.assign(N, false);
    
    for (int r=0; r<N; ++r)
        for (int c=0; c<N; ++c)
            cin >> Cost[r][c];
    
    long long res = 0;
    
    // 0번 행성에서 시작해서, 모든 행성을 최소 신장 트리로 잇는다.
    // {비용합, 행성번호}
    priority_queue<pii, vector<pii>, Comp> pq;
    pq.push({0, 0});
    int pickCnt = 0;
    //Visited[0] = true;
    
    while(!pq.empty()) // 갈 수 있는 경로 중, 비용이 제일 낮은 길을 택하기를 반복한다!
    {
        int curCostSum = pq.top().first;
        int curPlanet = pq.top().second;
        pq.pop();
        
        // 동일 행성으로 향하는 경로가 여러개일 수 있는데, 
        // 그 중 가장 비용이 낮은 것을 택해야하므로
        // pq에 push할 때 Visited = true 처리하지 않고
        // pop했을 때 Visited = true 처리를 해준다!!
        if (Visited[curPlanet]) continue;
        
        Visited[curPlanet] = true;
        res += curCostSum;
        ++pickCnt;
        if(pickCnt == N) break; // N개만큼 다 뽑음!
        
        //cout << curPlanet << "\n";
        
        for (int adj = 0; adj<N; ++adj)
        {
            if(adj == curPlanet) continue;
            
            if (Visited[adj]) continue;
            
            //cout << "> " << curPlanet << "->" << adj << "\n";
            
            pq.push({Cost[curPlanet][adj], adj});
        }
    }
    
    cout << res;
    return 0;
}

