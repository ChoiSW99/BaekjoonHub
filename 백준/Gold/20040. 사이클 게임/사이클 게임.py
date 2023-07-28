import sys
input = sys.stdin.readline

# 점개수, 차례수
n, m = map(int, input().split())

parentNode = [i for i in range(n)]

def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parentNode[a] = b
    else:
        parentNode[b] = a



        
def find(x):
    if parentNode[x] != x:
        parentNode[x] = find(parentNode[x])
    return parentNode[x]
    
isCycle = False               
for i in range(m):
    a, b = map(int, input().split())
    
    if find(a) == find(b) and isCycle == False:
        print(i+1)
        isCycle = True

    union(a,b)


if isCycle == False:
    print(0)
