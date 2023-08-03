import sys
import heapq

input = sys.stdin.readline

N, E = map(int, input().split()) #정점개수, 간선개수

Graph = [[] for _ in range(N+1)]
Dist = [float('inf') for _ in range(N+1)]

for _ in range(E):
    a, b, c = map(int, input().split())
    
    Graph[a].append((b, c))
    Graph[b].append((a, c))

v1, v2 = map(int, input().split())

def Dijkstra(start, desti):
    distTo = [float('inf') for _ in range(N+1)]
    distTo[start] = 0
    que = []
    heapq.heappush(que, (0, start))
    
    while que:
        nowWeight, nowNode = heapq.heappop(que)
        
        for nextNode, nextWeight in Graph[nowNode]:
            d = nowWeight + nextWeight
            if d < distTo[nextNode]:
                distTo[nextNode] = d
                heapq.heappush(que, (d, nextNode))
    
    return distTo[desti]

d1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N)
d2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N)
mini = min(d1, d2)
if mini == float('inf'):
    print(-1)
else:
    print(mini)
