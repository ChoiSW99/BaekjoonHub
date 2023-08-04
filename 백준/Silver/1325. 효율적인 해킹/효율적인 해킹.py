import sys
from collections import deque 

input = sys.stdin.readline

N, M = map(int, input().split())

graph = [[] for _ in range(N+1)]

for _ in range(M):
    # A가 B를 신뢰한다, B를 해킹하면 A도 해킹 가능. 즉 b -> a 
    a, b = map(int, input().split())
    graph[b].append(a)


result = [0] * (N+1)

def Traverse(start):
    cnt = 1
    visited = [False] * (N+1)
    que = deque([start])
    visited[start] = True
    
    while que:
        now = que.popleft()
        
        for x in graph[now]:
            if visited[x] == False:
                que.append(x)
                visited[x] = True
                cnt += 1
    return cnt


maxResult = 0
for i in range(1, N+1):
    result[i] = Traverse(i)
    maxResult = max(maxResult, result[i])
    
for i in range(1, N+1):
    if result[i] == maxResult:
        print(i, end = ' ')