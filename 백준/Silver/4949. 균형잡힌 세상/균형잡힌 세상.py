import sys
from collections import deque
input=sys.stdin.readline


while(True):
    stack = []
    str = input().rstrip()
    if str == '.':
        break
    
    for x in str:
           
        if x == '(' or x == '[':
            stack.append(x)
            
        elif x == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(')')
                break
            
        elif x == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                stack.append(']')
                break
            
    if(len(stack) == 0):
        print('yes')
    else:
        print('no')


    
