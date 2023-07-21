import sys
sys.setrecursionlimit(100000)

n = int(input())
Edge = [[] for _ in range(n+1)]
Visited = [False] * (n+1)

for _ in range(n-1):
    a, b, w = map(int, input().split())
    
    Edge[a].append((b,w))
    Edge[b].append((a,w))
    
#print(Edge)


farNode = 0
diameter = 0



def DFS(node, weight):
    global diameter
    Visited[node] = True
    
    for e in Edge[node]:
        if(Visited[e[0]] == False):        
            if weight + e[1] > diameter:
                global farNode
                farNode = e[0]
                diameter = weight + e[1]
                
            DFS(e[0], weight + e[1])


Visited = [False] * (n+1)
DFS(1, 0)
# print(farNode)
# print(diameter)

Visited = [False] * (n+1)
DFS(farNode, 0)
# print(farNode)
print(diameter)
