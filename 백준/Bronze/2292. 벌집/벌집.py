# 1 2~7 8~19 20~37 38~61 ,,,,
# 1, 6, 12, 18, 24 ,,,  

room = int(input())

if(room==1):
    print(1)
else:
    i=1
    room-=1
    while(True):
        if room <= (6*i):
            print(i+1)
            break
        
        room-=6*i
        i+=1
