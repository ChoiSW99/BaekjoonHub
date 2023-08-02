import sys, copy
input = sys.stdin.readline
sys.setrecursionlimit(100000)

N, B = map(int, input().split())
mat = []

for _ in range(N):
    lst = list(map(int, input().split()))
    mat.append(lst)
    

def Mult(aM, bM):
    cM = [[ 0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            x = 0
            for k in range(N):
                x += aM[i][k] * bM[k][j]

            cM[i][j] = x%1000
            
    return cM

def Calc(A, B):
    if B == 1:
        for i in range(N):
            for j in range(N):
                A[i][j] %= 1000
        return A
    
    tmp = Calc(A, B//2)
    
    if B % 2 == 0:
        return Mult(tmp, tmp)
    else:
        return Mult(Mult(tmp, tmp), A)
    

result = Calc(mat, B)

for i in range(N):
    for j in range(N):
        print(result[i][j], end = ' ')
    print()