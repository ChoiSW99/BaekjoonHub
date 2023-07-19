import sys
input=sys.stdin.readline

T = int(input())

def Count(str):
    cnt = 0
    for i in range(len(str)):
        if str[i] == ')':
           cnt -= 1
        elif str[i] == '(':
            cnt += 1
        
        if(cnt < 0):
            return 'NO'    
    
    if(cnt == 0):
        return 'YES'  
    else:
        return 'NO'  
    
for _ in range(T):
    str = input().rstrip()
    
    print(Count(str))
