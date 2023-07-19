import sys
input=sys.stdin.readline
sys.setrecursionlimit(10000)

K = int(input())
nums = []
for _ in range(K):
    x = int(input())
    
    if x == 0 and nums:
        nums.pop()
    else:
        nums.append(x)
print(sum(nums))