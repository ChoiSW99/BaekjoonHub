import sys, heapq
input = sys.stdin.readline

# 테스트케이스
Tc = int(input())
INF = int(1e9)

def dijkstra(start, graph, distTo):
    que = [(0, start)]
    distTo[start] = 0
    
    while que:
        nowDist, nowNode = heapq.heappop(que)
        
        if nowDist > distTo[nowNode]:
            continue

        for nextNode, nextDist in graph[nowNode]:
            dst = nowDist + nextDist
            if dst < distTo[nextNode]:
                distTo[nextNode] = dst
                heapq.heappush(que, (dst, nextNode))
    
    #return distTo[end]
    
result = []

while Tc > 0:
    Tc -= 1
    
    # 노드 개수, 엣지 개수, 목적지 후보 개수
    n, m, t = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    
    # s는 예술가의 출발지, 경유 g-h
    start, g, h = map(int, input().split())
    
    for _ in range(m):
        # a와 b 사이에 길이 d, 양방향
        a, b, d = map(int, input().split())
        graph[a].append([b, d])
        graph[b].append([a, d])
    #print(graph)
    for _ in range(t):
        expectDest = int(input())
        
        startTo = [INF for _ in range(n+1)]
        #gTo = [float('inf') for _ in range(n+1)]
        expectDestTo = [INF for _ in range(n+1)]
            
        #dijkstra(start, graph, distTo)
        
        dijkstra(start, graph, startTo)
        #dijkstra(g, graph, gTo)
        dijkstra(expectDest, graph, expectDestTo)
        
        ghDist = INF
        for x in graph[g]:
            if x[0] == h:
                ghDist = x[1]
                
        mini = min(startTo[g] + ghDist + expectDestTo[h], 
                   startTo[h] + ghDist + expectDestTo[g])

        if startTo[expectDest] == mini:
            result.append(expectDest)
    
            
    result.sort()
    for x in result:
        print(x, end = ' ')
    #print()
    result.clear()
    
            