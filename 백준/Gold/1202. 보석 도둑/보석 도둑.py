import sys, heapq
input = sys.stdin.readline
'''
가방용량을 오름차순으로 정렬해주고 // 작은 가방에 들어가는건 큰 가방에 들어갈 수 있음. 하지만 큰 가방에 들어가는건 작은 가방에 못 들어갈 수도 있음

보석도 무게 오름차순으로 정렬해준 후,

용량이 작은 가방부터 확인해줘야함.
'''

# 보석개수N, 가방개수K
N, K = map(int, input().split())

# 보석정보 무게w, 가격v
jew = []
for _ in range(N):
    M, V = map(int, input().split())
    jew.append((M, V))
    
jew.sort()

bagW = []
# 가방에 담을 수 있는 최대 무게 
for _ in range(K):
    C = int(input())
    bagW.append(C)
    
bagW.sort()

# maxHeap
maxHeap = []
sum = 0

i=0
for w in bagW:    
    
    while i < N and jew[i][0] <= w: 
        heapq.heappush(maxHeap, -jew[i][1]) #보석의 value, idx
        i += 1
            
    if maxHeap:
        sum -= heapq.heappop(maxHeap)           

print(sum)