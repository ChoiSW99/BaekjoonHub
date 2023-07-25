import sys
sys.setrecursionlimit(10**6)

def append_star(LEN):
    if LEN == 1:
        return ['*']

    Stars = append_star(LEN//3) 
    L = []  
    #print('STARS', Stars)
    for S in Stars:
        L.append(S + S + S)
    for S in Stars:
        L.append(S + ' '*(LEN//3) + S)
    for S in Stars:
        L.append(S + S + S)
    #print(L)
    return L

n = int(sys.stdin.readline().strip())
print('\n'.join(append_star(n)))

'''
Stars=ap_star(27)
        Stars=ap_star(9)
        ('***', '* *', '***')
                Stars=ap_star(3)
                        [*]=Stars=ap_star(1)
                L.append(***)
                L.append(* *)
                L.append(***)    


'''