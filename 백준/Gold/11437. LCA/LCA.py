import sys
input = sys.stdin.readline # 시간 초과를 피하기 위한 빠른 입력 함수
sys.setrecursionlimit(int(1e5)) # 런타임 오류를 피하기 위한 재귀 깊이 제한 설정
LOG = 21 # 2^20 = 1,000,000

n = int(input())
parent = [[0] * LOG for _ in range(n+1)] # 부모 노드 정보
d = [0] * (n+1) # 각 노드까지의 깊이
c = [0] * (n+1) # 각 노드의 깊이가 계산되었는지 여부
graph = [[] for _ in range(n+1)] # 그래프(graph) 정보

for _ in range(n-1):    
	a,b = map(int,input().split())
	graph[a].append(b)
	graph[b].append(a)

# 루트 노드부터 시작하여 깊이(depth)를 구하는 함수
def dfs(x,depth):
    d[x] = depth
    c[x] = 1
    
    for n in graph[x]: 
        if c[n] == 0:
            parent[n][0] = x
            dfs(n, depth+1)

        
# 전체 부모 관계를 설정하는 함수
def set_parent():
    dfs(1, 0) # depth 설정
    
    for j in range(1, LOG):
        for i in range(1, n+1):
            # node[i]의 2^(j) 위 == 'node[i]의 2^(j-1) 위'의 2^(j-1) 위
            parent[i][j] = parent[parent[i][j-1]][j-1]
            


# A와 B의 최소 공통 조상을 찾는 함수
def lca(a,b):
    # 더 depth가 깊은 노드를 b로 설정
    if d[a] > d[b]:
        a,b = b,a
    
    # depth 맞춰주기
    for i in range(LOG-1, -1, -1):
        if d[b]-d[a] >= (1 << i): # 1*(2^i)
            b = parent[b][i]
                        
    if a == b:
        return a
    
    for i in range(LOG-1, -1, -1):
        # 2^i 번째 부모노드가 다르면
        if parent[a][i] != parent[b][i]:
            a = parent[a][i]
            b = parent[b][i]
        '''
        만약 6번째부터 부모가 같으면 
        i가 LOG ~ 3일 때는 parent[a][i] == parent[b][i] 상태이고
        i가 2일 때(2^2 위) != 이기에 a와 b의 4번째 부모로 각각 a와 b를 올린 후
        i가 1일 때(2^1 위)를 확인하는데 == 이므로 다음 반복으로 넘어가고
        i가 0일 때(2^0 위)를 확인하고  != 이므로 1번째 부모로 각각 a와 b를 올린 후,
        반복문은 끝남.
        '''
    return parent[a][0]

            
set_parent()

# for i in range(0, n+1):
#     for j in range(0, LOG):
#         print(parent[i][j], end = ' ')
#     print()

m = int(input())

for i in range(m):
    a,b = map(int,input().split())
    print(lca(a,b))


