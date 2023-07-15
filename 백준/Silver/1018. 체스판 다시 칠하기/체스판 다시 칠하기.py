import sys
input = sys.stdin.readline

N, M = map(int, input().split()) # n x m 행렬

chessBoard = [[0]*M for _ in range(N)]
cntBoard = [[0]*(M-7) for _ in range(N-7)]


for i in range(N):
    chessBoard[i] = list(input().rstrip())

# for i in range(N):
#     print(chessBoard[i])
    
    
def Count(i, j):
    a = 0
    b = 0
    for x in range(i, i+8):
        for y in range(j, j+8):
            if((x+y) % 2 == 0):
                if(chessBoard[x][y] != 'W'):
                    a+=1
            else:
                if(chessBoard[x][y] != 'B'):
                    a+=1
                    
    for x in range(i, i+8):
        for y in range(j, j+8):
            if((x+y) % 2 == 1):
                if(chessBoard[x][y] != 'W'):
                    b+=1
            else:
                if(chessBoard[x][y] != 'B'):
                    b+=1
    return min(a,b)

minCnt = 64
for i in range(N-7):
    for j in range(M-7):
        minCnt = min(minCnt, Count(i, j))

print(minCnt)
