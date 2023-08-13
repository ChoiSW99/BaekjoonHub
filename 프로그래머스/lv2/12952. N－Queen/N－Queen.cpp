#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> &row, int level)
{
    for (int i = 0; i < level; i++)
    { // level행 전까지와 비교
        if (row[i] == row[level] || abs(row[i] - row[level]) == level - i)
        {
            return false;
        }
    }
    return true;
}

void nQueens(vector<int>& row, int level, int n, int &answer)
{
    if(level == n)
        answer++;
    else{
        for(int i=0; i<n; i++){
            row[level] = i;
            
            if(check(row, level))
                nQueens(row, level+1, n, answer);
        }
    }
}

int solution(int n)
{
    vector<int> row(n, -1);
    int answer = 0;

    nQueens(row, 0, n, answer);

    return answer;
}