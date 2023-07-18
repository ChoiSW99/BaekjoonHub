import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
N, M, K = map(int,input().split()) #수의 개수 / 수의 변경횟수 / 구간의 합 구하는 횟수

Array = [0]+[ int(input()) for _ in range(N) ]
#print(nums)
Tree = [0]* (N*4)
    
def initSegTree(start, end, idx):
    if start == end:
        Tree[idx] = Array[start]
        return 
    mid= (start+end)//2
    initSegTree(start, mid, idx*2)
    initSegTree(mid+1, end, idx*2+1)
    Tree[idx] = Tree[idx*2]+Tree[idx*2+1]

    
initSegTree(1,N,1)
#print(Tree)

def query(start, end, idx, qLeft, qRight):
    if qRight < start or end < qLeft: # 범위 밖
        return 0
    if qLeft <= start and end <= qRight: # 범위에 포함됨
        return Tree[idx]
    #걸침
    mid = (start+end)//2
    return query(start, mid, idx*2, qLeft, qRight) + query(mid+1, end, idx*2+1, qLeft, qRight) 

def update(start, end, idx, k, X):
    global diff
    diff = 0
    if start == end and start== k:
        diff = X-Tree[idx]
        Tree[idx] = X
        return
    mid = (start+end)//2
    if k <= mid:
        update(start, mid, idx*2, k, X)
    else:
        update(mid+1, end, idx*2+1, k, X)
    Tree[idx] += diff
    
    

for _ in range(M+K):
    a,b,c = map(int,input().split())
    if a == 1: #b번째 수를 c로 변경
        update(1,N,1, b,c)
        #print("Tree",Tree)
    elif a == 2: # b~c번째 수들의 합(구간합)
        print(query(1,N,1,b,c))
