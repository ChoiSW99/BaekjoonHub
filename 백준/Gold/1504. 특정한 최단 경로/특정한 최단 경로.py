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
distTo1 = [float('inf') for _ in range(N+1)]
distTo2 = [float('inf') for _ in range(N+1)]
distTo3 = [float('inf') for _ in range(N+1)]

def Dijkstra(start, distTo):
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


Dijkstra(1, distTo1)
Dijkstra(v1, distTo2)
Dijkstra(N, distTo3)

mini = min(distTo1[v1] + distTo2[v2] + distTo3[v2], distTo1[v2] + distTo2[v2] + distTo3[v1])
if mini == float('inf'):
    print(-1)
else:
    print(mini)
