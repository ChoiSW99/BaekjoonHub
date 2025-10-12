#include <iostream>
#include <vector>

using namespace std;

int N; 
vector<int> Path; // 0 -> Path[0] //1->Path[1] ...
vector<bool> Visited;

// 순열이므로, out/indegree가 무조건 1이다. 
// 즉, 모든 정점은 어떤 사이클에 포함된다.

void Check(int start)
{
    Visited[start] = true;
    
    int now = start;
    int next = Path[now];
    
    while(Visited[next] == false)
    {
        Visited[next] = true;
        next = Path[next];
    }
}

int main()
{
    int T; cin >> T;
    for (int tc=0; tc<T; ++tc)
    {
        int result = 0;
        
        cin >> N; // 순열의 크기N
        
        // 1번부터 N번 노드
        Path.assign(N+1, 0);
        Visited.assign(N+1, false);
        
        for (int n=1; n<=N; ++n)
        {
            cin >> Path[n];
        }
        
        // 순열 사이클 체크
        for (int n=1; n<=N; ++n)
        {
            if(Visited[n] == false)
            {
                Check(n);
                ++result;
            }
        }
        cout << result << "\n";
    }
    
}