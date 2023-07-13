# C * k  > A + B * k
A,B,C=input().split()
A=int(A)
B=int(B)
C=int(C)

if(B>=C):
    print(-1)
else:
    k=int(A/(C-B))
    while(True):
        if(C*k > A+B*k):
            print(k)
            break
        else:
            k+=1
