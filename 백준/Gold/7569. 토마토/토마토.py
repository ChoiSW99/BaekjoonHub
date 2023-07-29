import sys 
from collections import deque

input = sys.stdin.readline

# 열, 행, 높이
C, R, H = map(int, input().split())

Box = [[] for _ in range(H)]
Checked = [[[False for _ in range(C)] for _ in range(R) ] for _ in range(H)]

for h in range(H):
    for r in range(R):
        Box[h].append(list(input().rstrip().split()))
        
#print(Box)
#print(Checked)

cntZero = 0 #앞으로 익어야할 토마토수
days = 0 # 걸리는 날


def Sol():
    global cntZero
    global days
    que = deque()
    
    #초기화
    for h in range(H):
        for r in range(R):
            for c in range(C):
                if Box[h][r][c] == '1':
                    que.append((h,r,c))
                    Checked[h][r][c] = True
                elif Box[h][r][c] == '0':
                    cntZero+=1

    tempQue = que.copy()
    que.clear()
    #print('tempQue', tempQue)
    # BFS
        # 0익지않음 1익음 -1없음
    while tempQue:
        nowH, nowR, nowC = tempQue.popleft()        
        #print('tempQue', tempQue)
        if nowH+1 <= H-1:
            if Checked[nowH+1][nowR][nowC] == False: # 확인 X
                if Box[nowH+1][nowR][nowC] == '0': # 안익었으면
                    que.append((nowH+1, nowR, nowC))
                    Checked[nowH+1][nowR][nowC] = True
                    cntZero -= 1
                
        if nowH-1 >= 0:
            if Checked[nowH-1][nowR][nowC] == False: # 확인 X
                if Box[nowH-1][nowR][nowC] == '0': # 안익었으면
                    que.append((nowH-1, nowR, nowC))
                    Checked[nowH-1][nowR][nowC] = True
                    cntZero -= 1
                
        if nowR+1 <= R-1:
            if Checked[nowH][nowR+1][nowC] == False: # 확인 X
                if Box[nowH][nowR+1][nowC] == '0': # 안익었으면
                    que.append((nowH, nowR+1, nowC))
                    Checked[nowH][nowR+1][nowC] = True
                    cntZero -= 1
                
        if nowR-1 >=0:
            if Checked[nowH][nowR-1][nowC] == False: # 확인 X
                if Box[nowH][nowR-1][nowC] == '0': # 안익었으면
                    que.append((nowH, nowR-1, nowC))
                    Checked[nowH][nowR-1][nowC] = True
                    cntZero -= 1
                
        if nowC+1 <= C-1:
            if Checked[nowH][nowR][nowC+1] == False: # 확인 X
                if Box[nowH][nowR][nowC+1] == '0': # 안익었으면
                    que.append((nowH, nowR, nowC+1))
                    Checked[nowH][nowR][nowC+1] = True
                    cntZero -= 1
                
        if nowC-1 >= 0:
            if Checked[nowH][nowR][nowC-1] == False: # 확인 X
                if Box[nowH][nowR][nowC-1] == '0': # 안익었으면
                    que.append((nowH, nowR, nowC-1))
                    Checked[nowH][nowR][nowC-1] = True
                    cntZero -= 1
        
        if len(tempQue) == 0:
            #print('X')
            if len(que) == 0:
                break
            else:
                days += 1
                tempQue = que.copy()
                #print('tempQue', tempQue)
                que.clear()
                
Sol()
#print("cntZero", cntZero)
if cntZero == 0:
    print(days)
else:
    print(-1)
        


# Box[H][R][C] 층, 행, 열