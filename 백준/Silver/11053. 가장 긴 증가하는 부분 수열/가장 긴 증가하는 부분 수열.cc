#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> Nums;
vector<int> Cached;

int LIS(int start)
{
    int& ret = Cached[start];
    
     // 이미 계산됐으면 return
    if(ret != -1) return ret;
    
    ret = 1;
    for(int next = start+1; next < N; next++)
    {
        if(Nums[start] < Nums[next])
            ret = max(ret, 1 + LIS(next));
    }
    return ret;
}

int main()
{
    Nums.assign(1001, -1);
    Cached.assign(1001, -1);
    
    cin >> N;
    for(int i =0; i<N; i++)
    {
        cin >> Nums[i];
    }
    
    
    int res = 0;
    for(int i=0; i<N; i++)
    {
        res = max(res, LIS(i));
    }
    cout << res;
}