#include <iostream>
#include <set>

using namespace std;

int TC;
int K; // 연산 개수


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin >> TC;
    while (TC-- > 0)
    {
        multiset<int> ms;

        cin >> K; // 연산 개수
        while(K-- > 0)
        {
            char op; cin >> op; //연산 D 또는 I
            int n; cin >> n; // 정수n
            
            // D 1  -> 최댓값 삭제
            // D -1 -> 최솟값 삭제
            // I a -> 정수a를 Q에 삽입
            // 동일한 정수가 삽입될 수 있음
            
            switch(op)
            {
            case 'I':
                {
                    ms.insert(n);
                }
                break;
            case 'D':
                {
                    if(ms.empty()) continue;
                        
                    if(n == 1)
                    {
                        // 최댓값 삭제
                        ms.erase(prev(ms.end()));
                    }
                    else if(n == -1)
                    {
                        // 최솟값 삭제   
                        ms.erase(ms.begin());
                    }
                }
                break;
            }
            
        }
        if(ms.empty()) 
            cout << "EMPTY" << "\n";
        else
            cout << *(prev(ms.end())) << " " << *(ms.begin()) << "\n";
    }
}