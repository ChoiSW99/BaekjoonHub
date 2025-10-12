#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> nums;
vector<int> subSum;

void MakeSubSums()
{
    subSum.assign(N+1, 0);
    
    // subSum[0] : 아무것도 X
    // subSum[3] : nums1,2,3 합
    // subSum[a] = nums[1]부터 nums[a]까지의 합
    for (int i=1; i<=N; ++i)
    {
        subSum[i] = subSum[i-1] + nums[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    nums.assign(N+1, 0);
    for (int n=1; n<=N; ++n)
    {
        cin >> nums[n];
    }
    
    MakeSubSums();
    
    for (int m=0; m<M; ++m)
    {
        int i, j;
        cin >> i >> j;
        // nums[i] ~ nums[j]까지의 합
        cout << subSum[j] - subSum[i-1] << "\n";
    }
}