import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())

maze = []

for _ in range(N):
  maze.append(list(map(int, input().rstrip())))
        

#print(maze)

def BFS(start_i, start_j):
    # 상, 하, 좌, 우
    di = [1, -1, 0, 0]
    dj = [0, 0, -1, 1]

    que = deque([(start_i-1, start_j-1)])
    
    while que:
        i,j = que.popleft()
        
        for n in range(4):
            if 0 <= i+di[n] and i+di[n] <= N-1 and 0 <= j+dj[n] and j+dj[n] <= M-1:
                if maze[i+di[n]][j+dj[n]] == 1:
                     maze[i+di[n]][j+dj[n]] = maze[i][j]+1
                     
                     que.append((i+di[n], j+dj[n]))
                     

            


BFS(1,1)
print(maze[N-1][M-1])
