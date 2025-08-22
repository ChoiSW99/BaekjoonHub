#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

// 중심 행성 T
// N개의 행성 간에 플로우 설치
// 플로우 내에는 제국군을 주둔시키기
// 목표) 모든 행성을 연결하면서, 플로우 유지비용 최소화 -> MST
// 크루스칼(Union Find) 알고리즘

using namespace std;

// {cost, v1, v2}

vector<int> Parent(1001, -1);

int Find(int v)
{
    if (Parent[v] < 0)
        return v;
    return Parent[v] = Find(Parent[v]);
}

bool Union(int u, int v)
{
    int uRoot = Find(u);
    int vRoot = Find(v);

    if (uRoot == vRoot)
        return false;

    if (Parent[uRoot] == Parent[vRoot])
        Parent[uRoot]--;

    if (Parent[uRoot] < Parent[vRoot])
        Parent[vRoot] = uRoot;
    else
        Parent[uRoot] = vRoot;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long totalCost = 0;
    int N; cin >> N;
    vector<tuple<int, int, int>> edges;


    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            int cost;
            cin >> cost;
            if (r < c)
                edges.push_back({ cost, r, c });
        }
    }

    // 1) 간선비용 오름차순 정렬
    sort(edges.begin(), edges.end());

    // 2) V-1개의 간선을 뽑을 때까지 반복
    //    Union-Find로 같은 그룹인지 확인
    int picked = 0;
    for (int e = 0; e < edges.size(); e++)
    {
        int cost, u, v;
        tie(cost, u, v) = edges[e];

        if (Union(u, v))
        {
            totalCost += cost;
            picked++;
            if (picked == N - 1)
                break;
        }
    }
    cout << totalCost;
    return 0;
}