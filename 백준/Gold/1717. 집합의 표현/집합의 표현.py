import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000) # 재귀 깊이 제한 늘리기

n, m = map(int, input().split())

s = [0] * (n+1)
for i in range(1, n+1):
    s[i] = i # 집합i 의 대표는 i

# x가 포함된 집합의 대표노드 찾기
def find(x):
    if s[x] != x:
        s[x] = find(s[x])
    return s[x]

        
def union(a,b):
    aa = find(a)
    bb = find(b)
    
    if aa > bb:
        s[aa] = bb
    elif aa < bb:
        s[bb] = aa
    
    
for _ in range(m):
    q, a, b = map(int, input().split())

    if q == 0:
        union(a,b)
    elif q == 1:
        if find(a) == find(b):
            print('yes')
        else:
            print('no')
    #print(s)
            
  