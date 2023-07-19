import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
seq=[] #수열

s=1
stack=deque()
pm=[]

for _ in range(n):
    seq.append(int(input()))

for x in seq:
    while s <= x:  
        stack.append(s)
        pm.append('+')
        s+=1
        
    if stack[-1] == x:
        stack.pop()
        pm.append('-')
    else:
        pm=['NO']
        break
        
for x in pm:
    print(x)
    