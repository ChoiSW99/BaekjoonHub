import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

import heapq


def dijkstra(start):
    q = []

    # 최단 거리 테이블을 모두 무한으로 초기화
    distance = [INF] * (n + 1)

    # 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        # 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        dist, now = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if distance[now] < dist:
            continue
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[now]:
            cost = dist + i[1]
            # 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

    return distance

# 테스트 케이스의 개수
t = int(input())

for _ in range(t):
    # 정점의 개수 n, 간선의 개수 m, 목적지 후보 개수
    n, m, k = map(int, input().split())

    # 출발지, 지나간 도로
    s, g, h = map(int, input().split())

    # 무한을 의미하는 INF
    INF = int(1e9)

    # 그래프 초기화
    graph = [[] for _ in range(n+1)]

    # 간선 정보 입력
    for _ in range(m):
        a, b, c = map(int, input().split())
        # a->b가 c비용
        graph[a].append((b, c))
        graph[b].append((a, c))

    # 목적지 후보
    array = []
    for _ in range(k):
        array.append(int(input()))

    # 다익스트라 알고리즘을 수행
    first = dijkstra(s)

    g_dijk = dijkstra(g)
    h_dijk = dijkstra(h)

    arr = []

    for b in array:
        if first[g] + g_dijk[h] + h_dijk[b] == first[b] or first[h] + h_dijk[g] + g_dijk[b] == first[b]:
            arr.append(b)

    arr.sort()

    for w in arr:
        print(w, end=' ')
    print()