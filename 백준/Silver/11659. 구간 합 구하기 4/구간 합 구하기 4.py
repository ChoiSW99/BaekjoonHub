import sys
input=sys.stdin.readline

N, M = map(int,input().split())
sums = [0] * (N+1) # N+1개의 부분합 0 0~1 0~2 0~3 0~4 0~5


nums = list(map(int, input().split()))
for i in range(1, N+1):
    sums[i] = sums[i-1] + nums[i-1]

for _ in range(M):
    i, j = map(int, input().split()) # i~j번 구간합
    print(sums[j]-sums[i-1])
    