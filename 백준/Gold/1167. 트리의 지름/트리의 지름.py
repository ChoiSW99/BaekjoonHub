import sys
from collections import deque
sys.setrecursionlimit(100000)

V = int(input())
Edge = [[] for _ in range(V+1)]
for _ in range(V):
    x = list(map(int, input().split()))
    a = x[0]
    b=0
    w=0
    for i in range(1, len(x)-1):
        if i%2 == 1:
            b = x[i]
        else:
            w = x[i]
            Edge[a].append((b,w))

#print(Edge)
    
visited = [False] * (V+1)
W = [0] * (V+1) #가중치

farNode = 0
farDist = 0

def DFS(start, W):
    global farNode
    global farDist
    stack = [(start,0)]
    
    while stack:
        e, w = stack.pop()
        visited[e] = True
        W[e] += w
        
        if W[e] > farDist:
            farNode = e
            farDist = W[e]
        
        for next in Edge[e]:
            if visited[next[0]] == False:
                W[next[0]] += W[e]
                stack.append(next)
                

DFS(1, W)   
visited = [False] * (V+1)
W = [0] * (V+1) #가중치           
DFS(farNode, W)

print(farDist)    
         