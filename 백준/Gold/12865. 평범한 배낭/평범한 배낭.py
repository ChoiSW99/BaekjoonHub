import sys
input = sys.stdin.readline

# 보석개수, 가방용량
N, K = map(int, input().split())

w = [0]
v = [0]
dp = [0] * (K+1) # dp[i] : 가방용량이 i일 때의 최대가치합
for _ in range(N):
    # 무게, 가격
    W, V = map(int,input().split())
    w.append(W)
    v.append(V)

# dp[i][j] : 1~i번 보석을 고려하고 가방 용량이 j일 때, 최대가치합
# dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])

for i in range(1, N+1):
    for j in range(K, 0, -1): # 가방용량 j
        if j-w[i] >= 0: # i번째 보석을 넣을 수 있는 경우
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]) # 안넣을때 vs 넣을때 
        #else: # i번째 보석을 넣을 수 있는 경우
            # 그대로 유지


print(dp[K])
