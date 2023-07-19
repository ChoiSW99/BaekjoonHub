import sys
from collections import deque
input=sys.stdin.readline



while(True):
    str = input().rstrip()
    stack = []
    small = 0
    big = 0
    
    # 종료 조건
    if(str == '.'):
        break

    for c in str:
        if(c == '(' or c == ')' or c == '[' or c == ']'):
            stack.append(c)
    
    
    isDeleted = True
    while(isDeleted):
        isDeleted = False

        for i in range(len(stack)-1):
            if stack[i] =='(' and stack[i+1] == ')':
                stack.pop(i+1)
                stack.pop(i)
                isDeleted = True
                break
            elif stack[i] =='[' and stack[i+1] == ']':
                stack.pop(i+1)
                stack.pop(i)
                isDeleted = True
                break

    if stack:
        print("no")
    else:
        print("yes")   
        
#([(([([])()(())]))])