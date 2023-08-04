import sys
input = sys.stdin.readline

N, M = map(int, input().split())
Graph = [[] for _ in range(N+1)]
leftEdge = [0] * (N+1)

que = []

for _ in range(M):
    A, B = map(int,input().split())
    Graph[A].append(B)
    leftEdge[B]+=1

for i in range(1, N+1):
    if leftEdge[i] == 0:
        que.append(i)

#print(leftEdge)



def Topology():
    while que:
        now = que.pop()
        print(now, end= ' ')
        
        for x in Graph[now]:
            leftEdge[x] -= 1
            if leftEdge[x] == 0:
                que.append(x)

Topology()