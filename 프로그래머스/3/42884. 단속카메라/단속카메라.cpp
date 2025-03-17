#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    // 오름차순 정렬
    sort(routes.begin(), routes.end(), less<>());
    
    for (int i = 0; i < routes.size(); i++)
    {
        int start = routes[i][0];
        int end = routes[i][1];
        
        // 다음 경로들 확인
        for (int j = i+1; j < routes.size(); j++)
        {
            int jStart = routes[j][0];
            int jEnd = routes[j][1];
            
            if (jEnd <= end) // a. 포함된다
            {
                // end를 앞당긴다
                end = jEnd;
            }
            else // end < jEnd
            {
                if (jStart <= end) // b. 겹친다
                {
                    // end 그대로
                    
                }
                else  // c. 아예 겹치지 않는다
                {
                    // 카메라 배치하기 !!
                    break;
                }               
            }
            
            i = j;
        }
        answer++;
    }
    
    return answer;
}