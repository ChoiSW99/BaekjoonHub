import sys
import heapq
input=sys.stdin.readline

Left_maxHeap = []
Right_minHeap = []

N = int(input())
for i in range(1, N+1): # 1~N
    k = int(input())
    
    if(i%2 != 0):
        heapq.heappush(Left_maxHeap, -k)
    else:
        heapq.heappush(Right_minHeap, k)
        
    if(i>=2):
        if(len(Left_maxHeap) >= 1 and len(Right_minHeap) >= 1 and Left_maxHeap[0]*(-1) > Right_minHeap[0]):
            left_maxValue = heapq.heappop(Left_maxHeap)
            right_minValue = heapq.heappop(Right_minHeap)
            
            heapq.heappush(Left_maxHeap, -1 * right_minValue)
            heapq.heappush(Right_minHeap, -1 * left_maxValue)
            
    print( -1 * Left_maxHeap[0])

