import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000) # 재귀 깊이 제한 늘리기

N = int(input()) # 3의 거듭제곱
arr = [['*']*N for _ in range(N)]

def Print():
    for i in range(N):
        for j in range(N):
            print(arr[i][j], end = '')
        print()
    
def Pattern(N, xx, yy):
    for i in range((N//3), (N//3)*2):
        for j in range((N//3), (N//3)*2):
            arr[xx+i][yy+j] = ' '

    if N != 3:                
        for x in range(3):
            for y in range(3):
                Pattern(N//3, xx+(N//3)*x, yy+(N//3)*y)
                
                


Pattern(N, 0, 0)
Print()
'''
27 0 0
    9 0 0
        (n=3)
        3 0 0
        3 0 3
        3 0 6
        3 3 0
        3 3 3 X
        3 3 6
        3 6 0
        3 6 3
        3 6 6
    
    9 0 9
        3 0 9
        3 0 12
        3 0 15
    
    9 0 18
    9 9 0
    9 9 18
    9 2 0
    9 2 1
    9 2 2 
'''
