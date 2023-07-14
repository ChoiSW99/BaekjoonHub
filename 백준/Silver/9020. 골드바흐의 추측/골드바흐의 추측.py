import sys
input = sys.stdin.readline

primeIdx = [0]*2 + [1]*9999

for i in range(2, int(10001**(1/2))+1):
    if(primeIdx[i] == 1):
        for j in range(i+i, 10001, i):
            primeIdx[j] = 0


T = int(input())
while(T>0):
    T-=1
    n = int(input())

    closestToHalf = n//2
    
    for j in range(closestToHalf, 0, -1):
        if(primeIdx[j] and primeIdx[n-j]):
            print(j, n-j)
            break