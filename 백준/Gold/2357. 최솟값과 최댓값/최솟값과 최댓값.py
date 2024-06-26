import sys
input=sys.stdin.readline
sys.setrecursionlimit(10000)

N, M = map(int, input().split())

arr = []
segTree = [[0,0] for _ in range(N*4)] #[min, max] * ([)N*4)
#print(segTree)

for _ in range(N):
    arr.append(int(input()))
#print(arr)

def Build(node, start, end):
    # leaf node
    
    if(start == end):
        segTree[node] = [arr[start], arr[start]]
        #print(segTree)
        return segTree[node]
    else:
        
        mid = (start + end)//2
        left = Build(node*2, start, mid)
        right = Build(node*2+1, mid+1, end)
        segTree[node][0] = min(left[0],right[0])
        segTree[node][1] = max(left[1],right[1])
        #print(segTree)
        return segTree[node]
    
#print(segTree)
Build(1, 0, N-1)

#print(segTree)

minList = []
maxList = []

def Find(node, subStart, subEnd, start , end):
    if(subStart <= start and end <= subEnd):
        minList.append(segTree[node][0])
        maxList.append(segTree[node][1])
        return
    if(subStart > end or subEnd < start):
        return
    mid = (start + end)//2
    Find(node*2, subStart, subEnd, start, mid)
    Find(node*2+1, subStart, subEnd, mid+1, end)

for _ in range(M):
    a, b = map(int, input().split())
    Find(1, a-1, b-1, 0, N-1)
    #print("minList ", minList)
    #print("maxList ", maxList)
    print(min(minList), max(maxList))
    minList = []
    maxList = []
