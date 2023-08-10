import sys, heapq
input = sys.stdin.readline

INF = float('inf')

def BellmanFord(start):
    d = [10001] * (N+1)
    d[start] = 0
    for _ in range(N-1):
        for i in range(1, N+1):
            for x in graph[i]:
                dst = d[i]+x[1]
                if dst < d[x[0]]:
                    d[x[0]] = dst
       
    for i in range(1, N+1):
        for x in graph[i]:
            dst = d[i]+x[1]
            if dst < d[x[0]]:
                # 사이클 발생
                return False
    return True

TC = int(input())

for _ in range(TC):
    # 지점N, 도로M, 웜홀W
    N, M, W = map(int, input().split())
    
    graph = [[] for _ in range(N+1)]
    
    #도로정보
    for _ in range(M):
        # 지점1, 지점2, time
        S, E, T = map(int, input().split())
        graph[S].append((E,T))
        graph[E].append((S,T))
    
    # 웜홀정보
    for _ in range(W):
        # start, end, time
        S, E, T = map(int, input().split())
        graph[S].append((E,-T))

    if BellmanFord(1):
        print("NO")
    else:
        print("YES")
        

        
        
'''
1 ==[-3]==> 4 ==[+2]==> 3 ==[+1]==> 2
일 때, v-1번(3번) 반복해줘야 1에서 2까지의 최단 경로를 구할 수 있음.

'''