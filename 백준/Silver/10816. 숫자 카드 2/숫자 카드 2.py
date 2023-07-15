import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

N = int(input())
Ncards = sorted(list(map(int, input().split())))

M = int(input())
Mcards = list(map(int, input().split()))

# print(Ncards)
# print(Mcards)


for i in range(M):
    cnt = 0
    index1 = bisect_left(Ncards, Mcards[i])
    index2 = bisect_right(Ncards, Mcards[i])
    # while(index < N and Ncards[index] == Mcards[i] ):
    #     index += 1
    #     cnt += 1
    print(index2 - index1, end = ' ')


    