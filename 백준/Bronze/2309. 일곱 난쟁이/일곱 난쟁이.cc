#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Pick(vector<int>& heights, vector<int>& picked, int sum, int toPick)
{
    if(toPick == 0)
    {
        if(sum == 100)
        {
            sort(picked.begin(), picked.end());
            for(int p : picked)
                cout << p << " ";
            exit(0); // 종료
        }
    }
    else{
        int smallest = picked.empty() ? 0 : picked.size();
        for(int next = smallest; next < heights.size(); next++)
        {
            picked.push_back(heights[next]);
            Pick(heights, picked, sum + heights[next], toPick-1);
            picked.pop_back();
        }    
    }
    
}


int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(NULL);
    
    vector<int> heights(9,-1);
    vector<int> picked;
    int sum = 0;
    
    for(int i=0; i<9; i++)
        cin >> heights[i];
    Pick(heights, picked, sum, 7);
}