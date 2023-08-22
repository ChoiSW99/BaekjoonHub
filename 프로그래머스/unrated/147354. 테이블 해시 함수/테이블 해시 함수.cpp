#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int COL;
bool compare(vector<int>& a, vector<int>&b)
{
    if(a[COL-1] < b[COL-1])
        return true;
    else if(a[COL-1] == b[COL-1])
        return a[0] > b[0];
    else
        return false;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int Si = 0;
    int answer = 0;
    COL = col;
    sort(data.begin(), data.end(), compare);
    
    for(int i = row_begin; i < row_end+1; i++)
    {
        Si = 0;
        for(int j=0; j<data[i-1].size(); j++)
            Si += data[i-1][j]%i;
        
        if(i == row_begin)
            answer = Si;
        else
            answer ^= Si;
    }
    
    return answer;
}

