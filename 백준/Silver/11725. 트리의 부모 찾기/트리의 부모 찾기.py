import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N=int(input())
Node=[[] for _ in range(N+1)]
ParentNode=[-1,-1]+[0 for _ in range(N-1)]



for _ in range(N-1):
    n1, n2 = map(int, input().split())
    Node[n1].append(n2)
    Node[n2].append(n1)
#print(Node)
#print(ParentNode)

def DFS(n):
    for k in Node[n]:
        if ParentNode[k] == 0:
            ParentNode[k]=n
            DFS(k)
DFS(1)

for i in range(2,N+1):
    print(ParentNode[i])