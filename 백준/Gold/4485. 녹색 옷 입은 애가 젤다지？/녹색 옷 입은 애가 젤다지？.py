import sys, heapq
input = sys.stdin.readline

Tc = 1
dx = [-1, 1,  0, 0]
dy = [ 0, 0, -1, 1]

def Dijkstra():
    lose = [list(map(int, input().split())) for _ in range(N)]
    loseSum = [[float('inf') for _ in range(N)] for _ in range(N)]
    loseSum[0][0] = lose[0][0]
    
    que = [(lose[0][0], 0, 0)] # lose, i, j
    while que:
        lsum, i, j = heapq.heappop(que)
        
        if lsum > loseSum[i][j]:
            continue
        
        if i == j == N-1:
            return loseSum[N-1][N-1]
        
        for idx in range(4):
            if 0 <= i+dx[idx] <= N-1 and 0<= j+dy[idx] <= N-1:
                newLose = lsum + lose[i+dx[idx]][j+dy[idx]] 
                if newLose < loseSum[i+dx[idx]][j+dy[idx]]:
                    loseSum[i+dx[idx]][j+dy[idx]] = newLose
                    heapq.heappush(que, (newLose, i+dx[idx], j+dy[idx]))
                    
    

while True:
    N = int(input())
    if N == 0:
        break
    
    result = Dijkstra()
    
    print(f'Problem {Tc}: {result}')
    Tc += 1