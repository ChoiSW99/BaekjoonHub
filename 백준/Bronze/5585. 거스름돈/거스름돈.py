import sys
input = sys.stdin.readline # 시간 초과를 피하기 위한 빠른 입력 함수

x = 1000 - int(input())
cnt = 0
coins = [500, 100, 50, 10, 5, 1]

for c in coins:
    k = x // c
    cnt += k
    x -= k*c




print(cnt)