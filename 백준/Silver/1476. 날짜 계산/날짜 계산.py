import sys
input = sys.stdin.readline

# earth, sun, moon
E, S, M = map(int, input().split())

e,s,m = 1,1,1
cnt = 1
while True:
    if e == E and s == S and m == M:
        print(cnt)
        break
    else:
        e = max(1, (e+1)%16)
        s = max(1, (s+1)%29)
        m = max(1, (m+1)%20)
        cnt += 1
        




'''
x년일 때 
E == x%16
S == x%29
M == x%20
'''
 