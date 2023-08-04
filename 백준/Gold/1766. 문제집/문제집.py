import sys, heapq
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
indegree = [0 for i in range(N+1)]
graph = [[] for _ in range(N+1)]

for _ in range(M):
    A, B = map(int, input().split())
    graph[A].append(B) # A번 문제는 B번 문제보다 먼저 푸는 것이 좋다
    indegree[B] += 1

#print(indegree)

que = []

for i in range(1, N+1):
    if indegree[i] == 0:
        que.append(i)
        
while que:
    now = heapq.heappop(que)
    print(now, end = ' ')
    
    for x in graph[now]:
        indegree[x] -= 1
        if indegree[x] == 0:
            heapq.heappush(que, x)
