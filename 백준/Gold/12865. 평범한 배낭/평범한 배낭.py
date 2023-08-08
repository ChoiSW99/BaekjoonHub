import sys
input = sys.stdin.readline

# 보석개수, 가방용량
N, K = map(int, input().split())

w = [0]
v = [0]
for _ in range(N):
    # 무게, 가격
    W, V = map(int,input().split())
    w.append(W)
    v.append(V)

# dp[i][j] : 1~i번 보석을 고려하고 가방 용량이 j일 때, 가치합의 최대값
# dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])
dp = [[0] * (K+1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, K+1):
        if j-w[i] >= 0: # i번째 보석을 넣을 수 있는 경우
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]) # 넣기, 안넣기 비교
        else: # i번째 보석을 넣을 수 없는 경우
            dp[i][j] = dp[i-1][j] # 가방용량은 유지한채 i-1번째 보석까지 고려한 것과 같음

print(dp[N][K])
