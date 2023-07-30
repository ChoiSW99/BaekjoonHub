import sys
input = sys.stdin.readline

# 행렬
M, N = map(int, input().split())
aMat = []
for _ in range(M):
    aMat.append(list(map(int, input().split())))

K, M = map(int, input().split())
bMat = []
for _ in range(K):
    bMat.append(list(map(int, input().split())))



#print(aMat)
#print(bMat)

result = []

for a in aMat:
    for m in range(M):
        r = 0
        for aa in range(len(a)):
            r += a[aa] * bMat[aa][m]
        print(r, end = ' ')
    print()
    
        

'''
1 2     
3 4     -1 -2 0
5 6      0  0 3

'''