import sys, math
input = sys.stdin.readline

dist = []
for _ in range(int(input())):
    d1, d2 = map(int,input().split())
    dist.append(d2-d1)

sum = [0]
for i in range(1, int(math.sqrt(max(dist)))+2):
    sum.append(sum[i-1]+i)
#print(sum)
for d in dist:
    cnt = 0
    i = 1
    while True:
        if d > sum[i]:
            cnt += 1
            d -= i
            i+=1
        elif d == sum[i]:
            cnt += 1
            d -= i
        elif d < sum[i]:
            i -= 1
        #print('!', d)
        if d == 0:
            print(cnt)
            break
        
