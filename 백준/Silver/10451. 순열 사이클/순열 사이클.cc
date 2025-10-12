#include <iostream>
#include <vector>

using namespace std;

int N; 
vector<int> Path; // 0 -> Path[0] //1->Path[1] ...
vector<bool> IsInCycle;
vector<bool> HasPassed;

// start에서 시작해 -> start에 도착했을때만
// 지나온 점들을 IsInCycle = true 처리
// & 순열 사이클 개수+1을 해준다.

int result = 0;

void Check(int start)
{
    HasPassed.assign(N+1, false);
    
    vector<int> pathes; // 경로 저장
    
    // 최대 n번 확인
    int n = HasPassed.size()-1;
    int cur = start;
    int next = Path[cur];
    
    pathes.push_back(cur);
    HasPassed[cur] = true;

    for (int i=0; i<n+1; ++i) // 최대 n+1의 사이클을 고려
    {
        if (HasPassed[next])
        {
            if (start == next) // 시작점으로 옴 (순열 사이클) -> return
            {
                for (int p : pathes)
                    IsInCycle[p] = true;

                ++result;
                
                return;
            }
            return;
        }
        // 다음 노드 확인
        pathes.push_back(next);
        HasPassed[next] = true;
        
        cur = next;
        next = Path[next];
    }
}

int main()
{
    int T; cin >> T;
    for (int tc=0; tc<T; ++tc)
    {
        result = 0;
        
        cin >> N; // 순열의 크기N
        
        // 1번부터 N번 노드
        Path.assign(N+1, 0);
        IsInCycle.assign(N+1, false);
        
        for (int n=1; n<=N; ++n)
        {
            cin >> Path[n];
        }
        
        // 순열 사이클 체크
        for (int n=1; n<=N; ++n)
        {
            if(IsInCycle[n] == false)
            {
                Check(n);
            }
        }
        cout << result << "\n";
        
    }
    
    
    
}