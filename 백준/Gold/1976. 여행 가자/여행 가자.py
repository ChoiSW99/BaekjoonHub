import sys
input = sys.stdin.readline

N = int(input()) # 도시의 수
M = int(input()) # 여행계획에 속한 도시들의 수
parentNode = [i for i in range(N+1)]

def find(x):
    if parentNode[x] != x:
        parentNode[x] = find(parentNode[x])
    return parentNode[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        parentNode[a] = b
    elif a < b:
        parentNode[b] = a
    

for i in range(1, N+1):
    e = list(map(int, input().split()))
    for j in range(0, len(e)):
        if e[j] == 1:
            union(i, j+1)
    #print(parentNode)

k = list(map(int, input().split()))

s = set()
for kk in k:
    s.add(find(kk))
if len(s) >= 2:
    print("NO")
else:
    print("YES")