T=int(input()) #데스트데이터 수
roomNumber=[]
while T > 0:
    T-=1
    H,W,N = map(int, input().split())
    
    floor = N%H
    room = N//H+1
    if(floor==0):
        floor=H
        room=N//H
    
    roomNumber.append(floor*100+room)

for rN in roomNumber:
    print(rN)
