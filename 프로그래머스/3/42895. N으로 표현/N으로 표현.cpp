#include <string>
#include <vector>

using namespace std;


int solution(int N, int number) {
    int answer = 0;
    
    vector<vector<int>> DP(9);
    
    if(N==number)
        return 1;
    DP[1].push_back(N);
    
    for(int i=2; i < 9; i++)
    {
        int nxt = DP[i-1][0]*10+N;
        DP[i].push_back(nxt); // 5 55 555 ...
        if(nxt == number)
            return i;
        
        for(int a=1; a<i; a++)
        {
            for (int n1 : DP[a])
            {
                for (int n2 : DP[i-a])
                {
                    nxt = n1+n2;
                    if(nxt == number)
                        return i;
                    DP[i].push_back(nxt);
                    
                    nxt = n1-n2;
                    if(nxt == number)
                        return i;
                    DP[i].push_back(nxt);
                    
                    nxt = n2-n1;
                    if(nxt == number)
                        return i;
                    DP[i].push_back(nxt);
                    
                    nxt = n1*n2;
                    if(nxt == number)
                        return i;
                    DP[i].push_back(nxt);
                    
                    if(n2!=0)
                    {
                        nxt = n1/n2;
                        if(nxt == number)
                            return i;
                        DP[i].push_back(nxt);
                    }
                   
                    if(n1!=0)
                    {
                        nxt = n2/n1;
                        if(nxt == number)
                            return i;
                        DP[i].push_back(nxt);
                    }
                }
            }
        }
    }
    
    return -1;
}

// 1개를 사용 -> n개까지 숫자  1개씩 추가해보며+사칙연산 계산

/* 개수가 7배씩 증가

DP[사용한N의 개수][b번째]

DP[1] -> 5

DP[2] -> 55  
            5+5  5-5  5-5  5/5  5/5  5*5 

DP[3] -> 555 
            (5+5)+5  (5+5)-5 5-(5+5) 5/(5+5) (5+5)/5 (5+5)*5
            (5-5)+5  (5-5)-5 5-(5-5) 5/(5-5) (5-5)/5 (5-5)*5

K번째 = K-i와 i의 사칙연산 (i=1,2,3,4) 7가지 => x*10+x x+y x-y y-x x*y x/y y/x 

*/