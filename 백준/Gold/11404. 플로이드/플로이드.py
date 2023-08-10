import sys
import math
input = sys.stdin.readline

n=int(input()) #도시개수
m=int(input()) #버스개수



cost = [[math.inf for _ in range(n+1)] for _ in range(n+1)]
for i in range(1, n+1):
    cost[i][i] = 0
    
for _ in range(m):
    s, e, wt = map(int, input().split()) #시작, 도착, 비용
    if cost[s][e] > wt:
        cost[s][e] = wt
    
# for i in range(1, n+1):
#     for j in range(1, n+1):
#         print(cost[i][j], end = ' ')
#     print()

#플로이드
for k in range(1, n+1):
    for start in range(1, n+1):
        for end in range(1, n+1):
            # if start != end:
            if cost[start][end] > cost[start][k]+cost[k][end]:
                cost[start][end] = cost[start][k]+cost[k][end]

for i in range(1, n+1):
    for j in range(1, n+1):
        if cost[i][j] != math.inf:
            print(cost[i][j], end = ' ')
        else:
            print(0, end = ' ')
    print()
