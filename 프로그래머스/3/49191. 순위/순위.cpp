#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<bool>> Connected(n+1, vector<bool>(n+1, false));
    
    for(auto r : results)
        Connected[r[0]][r[1]] = true; // r[0]은 r[1]을 이긴다.
    
    for(int k=1; k<=n; ++k)
    {
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                if(Connected[i][k] && Connected[k][j])
                    Connected[i][j] = true;
            }
        }
    }
    
    for(int i=1; i<=n; ++i)
    {
        int cnt = 0; // 지거나 이긴 횟수
        for(int j=1; j<=n; ++j)
        {
            if(Connected[i][j] || Connected[j][i])
                ++cnt;
        }
        
        if(cnt == n-1) // 지거나 이긴 횟수 == n-1
            ++answer;
    }
    
    /*for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            cout << Connected[i][j] << " ";
        }
        cout << "\n";
    }cout << "\n";*/
    
    return answer;
}

/*

Dist[n][n] 의 배열
a가 c를 몇번을 거쳐 이겼는지 알기 위해서, 플로이드 워샬 알고리즘을 사용한다.

이 알고리즘은 O(V^3) 의 시간복잡도를 갖는다.

ex) (a->c 거리) = (a->b 거리) + (b->c 거리) 로 갱신해줄 수 있다.

우선, results에 대해 Dist[n][n] 배열에서 이겼으면 1로 설정해준다.

그 다음, 플로이드 워샬을 적용함으로써, x가 y를 몇 단계를 거쳐 이긴건지 표시해준다. 
// (즉, 사이에 몇 명 있는지)



*/