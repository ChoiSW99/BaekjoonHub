import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())

card = sorted(list(map(int, input().split())))

i1, i2, i3 = 0, 1, 2

sum = 0
closest = card[0] + card[1] + card[2]

for i1 in range(0, N-2):
    for i2 in range(i1+1, N-1):
        for i3 in range(i2+1, N):
            sum = card[i1]+card[i2]+card[i3]
            if(M-sum >= 0):
                if(M-closest > M-sum):
                    closest = sum

print(closest)

