import sys
input = sys.stdin.readline



''''
(a * b) mod c == ( a mod c * b mod c ) mod c

5 10 8
5 1 5 1 5 1

0 4 4 4 4 4

7 10 4
3 1 3 1 3

10 4 4 4
'''
#
# 2^9 == (Calc(2,4))^2 * 2
#     == (Calc(2,2)^2)^2 * 2
#     == ((Calc(2,1)^2)^2)^2 * 2

# 2^9 mod 5 == ( (Calc(2,4) * Calc(2,4)) * 2 ) mod 5 ==  ( (Calc(2,4) mod 5 * Calc(2,4)) mod 5 * 2 mod 5) mod 5
#
#
#


A, B, C = map(int, input().split())


def Calc(A,B,C):
    global res
    if B == 1:
        return A % C
    
    if B % 2 == 0:
        return ( ( Calc(A, B//2, C) % C ) ** 2 ) % C
    else:
        return ( ( Calc(A, B//2, C) % C ) ** 2 * ( A % C ) ) % C

print(Calc(A,B,C))