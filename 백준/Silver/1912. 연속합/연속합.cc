#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
    Divide & Conqure 분할정복 문제
    a b c d e ... 있을 때, a~e범위 최대 = 
*/

// mid-1과 mid를 포함하는 최대 합 구하기
int FindOverlap(vector<int>& nums, int begin, int end)
{
    int mid = (begin+end)/2;
    
    // 우측으로 연속해서 모두 더해보며 최대합 찾기
    int curSum = nums[mid-1] + nums[mid];
    int maxSum = curSum;
    int rightEnd = mid+1;
    while(rightEnd < end)
    {
        curSum += nums[rightEnd];
        maxSum = max(maxSum, curSum);
        
        ++rightEnd;
    }
        
    
    // 좌측으로 연속해서 모두 더해보며 최대합 찾기
    curSum = maxSum;
    int leftStart = mid-2;
    while(leftStart >= begin)
    {
        curSum += nums[leftStart];
        maxSum = max(maxSum, curSum);
        --leftStart;
    }
    
    return maxSum;
}

int Calc(vector<int>& nums, int begin, int end)
{
    if (end-begin <= 1)
        return nums[begin];
    else
    {
        int mid = (begin+end)/2;
        
        //" [begin, mid) vs [mid, end) vs mid-1과 mid포함 최대합 "
        // 셋 중 최대값 반환해주기
        int left = Calc(nums, begin, mid); 
        int right = Calc(nums, mid, end);
        int overlap = FindOverlap(nums, begin, end);
        
        return max({left, right, overlap});
    }
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; ++i)
    {
        cin >> nums[i];
    }
    
    cout << Calc(nums, 0, nums.size());
    
    return 0;
}
/*
    10 -4 3 1 5 6 -35 12 21 -1
    10 -4 3 1 5 / 6 -35 12 21 -1
    10 -4 3 1 5 / 6 -35 12 21 -1
    10 -4 / 3 / 1 5 / 6 -35 / 12 / 21 -1
    10 / -4 / 3 / 1 / 5 / 6 / -35 / 12 / 21 / -1
*/

/*          
    2 1 -4 [3 4 -4 6 5] -5 1

    2 1 -4 3 4 -4 6 5 -5 1
    2 1 -4 3 4#-4 6 5 -5 1
    2 1#-4 3 4#-4 6 5#-5 1
    2 1#-4#3 4#-4 6#5#-5 1
    2#1#-4#3#4#-4#6#5#-5#1
*/