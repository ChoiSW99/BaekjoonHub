import sys
input = sys.stdin.readline

T = int(input()) # 테스트케이스
rootFriend = {} # 친구관계
numFriend = {} # 친구 수

def find(x):
    if rootFriend[x] != x:
        rootFriend[x] = find(rootFriend[x])
    return rootFriend[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a > b:
        rootFriend[a] = b
        numFriend[b] += numFriend[a]
        print(numFriend[b])
    elif a < b:
        rootFriend[b] = a
        numFriend[a] += numFriend[b]
        print(numFriend[a])
    else:
        print(numFriend[b])
    
    

for _ in range(T):
    F = int(input()) # 친구 관계의 수

    for _ in range(F):
        a, b = input().split()
        
        if a not in rootFriend:
            rootFriend[a] = a
            numFriend[a] = 1
        if b not in rootFriend:
            rootFriend[b] = b
            numFriend[b] = 1

        union(a, b)
        
        
    #print(rootFriend)
    rootFriend.clear()
    numFriend.clear()
        
    
    
#    print(rootFriend)
            
        
    