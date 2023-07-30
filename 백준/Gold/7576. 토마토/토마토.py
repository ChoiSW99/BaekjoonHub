import sys
from collections import deque
input = sys.stdin.readline

# Col, Row
C, R = map(int, input().split()) 

# -1없음, 0익지않음, 1익음
Box = [list(map(int, input().split())) for _ in range(R)]
#print(Box)

cntZero = 0

que = deque()
for r in range(R):
    for c in range(C):
        if Box[r][c] == 1:
            que.append((r,c))
        if Box[r][c] == 0:
            cntZero+=1

def BFS():
    days = 0
    global cntZero
    d = [-1, +1]
    
    while que:
        r, c = que.popleft()
        
        for i in range(2):
            if 0 <= r+d[i] and r+d[i] <= R-1:
                if Box[r+d[i]][c] == 0:
                    Box[r+d[i]][c] = Box[r][c] + 1
                    days = Box[r+d[i]][c]-1
                    cntZero-=1
                    que.append((r+d[i], c))

        for i in range(2):
            if 0 <= c+d[i] and c+d[i] <= C-1:
                if Box[r][c+d[i]] == 0:
                    Box[r][c+d[i]] = Box[r][c] + 1
                    days = Box[r][c+d[i]]-1
                    cntZero-=1
                    que.append((r, c+d[i]))
                    
    if cntZero == 0:
        print(days)     
    else:
        print(-1)
                    
BFS()        
        
        