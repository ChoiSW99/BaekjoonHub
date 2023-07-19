import sys, math
from collections import deque
from bisect import bisect_left, bisect_right

input=sys.stdin.readline

size = 2*123456
sieve = [False]*2 + [True]*(size-1)
primes=[]
for i in range(2, int((size)**(0.5))+1):
    if sieve[i]:
        for j in range(i+i, size+1, i):
            sieve[j] = False
            
for i in range(2, size+1):
    if sieve[i]:
        primes.append(i)

while True:
    x = int(input())
    if x == 0:
        break
    else:
        print(bisect_right(primes, 2*x) - bisect_left(primes, x+1))

    