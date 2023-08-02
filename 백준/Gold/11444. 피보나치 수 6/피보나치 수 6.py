import sys, copy
input = sys.stdin.readline
sys.setrecursionlimit(100000)

# F0 = 0, F1 = 1

n = int(input())
f = [[0,1], [1, 1]]

def Fib(num):
    if num == 1:
        return f
    tmp = Fib(num//2)
    
    if num % 2 == 0:
        return Mult(tmp, tmp)
    else:
        return Mult(Mult(tmp, tmp), f)
    
    
def Mult(a, b):
    result = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            r = 0
            for k in range(2):
                r += a[i][k] * b[k][j]
                
            result[i][j] = r % 1000000007
    return result


print(Fib(n)[0][1] % 1000000007)
