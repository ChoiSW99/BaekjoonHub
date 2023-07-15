import sys
input = sys.stdin.readline

N = int(input())
Number = N
cnt=0
while(Number > 0):
    Number //= 10
    cnt+=1

constructor = []

if(cnt == 1): #한자리수
    if(N%2 == 0):
        constructor.append(N//2)
    
elif(cnt == 2): # 두자리수
    for i in range(N-9*cnt, N-1):
        x = i
        sum = i
        while(x>0):
            sum += x%10
            x//=10
            
        if(N == sum):
            constructor.append(i)
else:
    for i in range(N-9*cnt, N-2):
        x = i
        sum = i
        while(x>0):
            sum += x%10
            x//=10
            
        if(N == sum):
            constructor.append(i)

if(constructor):
    print(min(constructor))
else:
    print(0)

