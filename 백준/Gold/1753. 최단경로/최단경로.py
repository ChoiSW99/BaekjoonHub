import sys
input=sys.stdin.readline
import heapq

V,E=map(int,input().split()) #정점개수, 간선개수
K=int(input()) #시작정점

graph=[[] for _ in range(V+1)]
distance=[float('inf')]*(V+1)
visited=[False]*(V+1)

for _ in range(E):
    u,v,w= map(int, input().split())
    graph[u].append((v,w)) # u -> v , 가중치w

#print(graph)

que=[]
heapq.heappush(que, (0, K))
distance[K]=0

while que:
    weight, now = heapq.heappop(que)
    if visited[now]:
        continue
    else:
        visited[now] = True

    for next, value in graph[now]:
        if distance[next] > distance[now]+value:
            distance[next] = distance[now]+value
            heapq.heappush(que, (distance[next], next))
    
for i in range(1, V+1):
    if visited[i]:
        print(distance[i])
    else:
        print('INF')