#include <string>
#include <vector>

using namespace std;

int DP[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size(); // 5
    
    DP[0][0] = triangle[0][0];
    
    for(int i=1; i<triangle.size(); ++i)
    {
        for (int j=0; j<triangle[i].size(); ++j)
        {
            if(j == 0)
            {
                DP[i][j] = triangle[i][j] + DP[i-1][j];
            }
            else if(j == triangle[i].size()-1)
            {
                DP[i][j] = triangle[i][j] + DP[i-1][j-1];
            }
            else
            {
                DP[i][j] = triangle[i][j] + max(DP[i-1][j-1], DP[i-1][j]);
            }
            
            if(DP[i][j] > answer)
                answer = DP[i][j];
        }
    }
    
    return answer;
}
