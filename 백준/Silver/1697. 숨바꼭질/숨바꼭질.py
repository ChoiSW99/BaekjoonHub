import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
visited = [False] * (100001)
visited[N] = True

que = deque()
que.append((N, 0))
time = 0
while que:
    #print(que)
    x, t = que.popleft()
    #print(x, t)
    if x == K:
        print(t)
        break
    
    if x-1 >= 0 and visited[x-1] == False:
        visited[x-1] = True
        que.append((x-1, t+1))
        
    if x+1 <= 100000 and visited[x+1] == False:
        visited[x+1] = True
        que.append((x+1, t+1))
        
    if x*2 <= 100000 and visited[x*2] == False:
        visited[x*2] = True
        que.append((x*2, t+1))
