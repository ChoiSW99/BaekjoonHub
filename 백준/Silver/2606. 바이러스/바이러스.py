import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(10e6))

n=int(input())
graph = [[] for _ in range(n+1)]
check = [0 for _ in range(n+1)]

for _ in range(int(input())):
    a, b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

def Sol(start):
    st = [start]
    cnt=0

    while st:
        s = st.pop()
        if check[s] == 0:
            check[s] = 1
            cnt+=1
        
            for x in graph[s]:
                st.append(x)

    return cnt-1

print(Sol(1))