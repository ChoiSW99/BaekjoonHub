#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

// {작업번호, 요청시각, 소요시간}
struct Task {
    int Number;
    int ReqTime;
    int Duration;

    Task(int n, int r, int d) : Number(n), ReqTime(r), Duration(d) { }
};

// jobs는 최대 500
// 요청시각 최대 1000 ms
// 소요시간 최대 1000 ms
// {reqTime, duration}
int solution(vector<vector<int>> jobs) {
    int answer = 0; // 모든 요청 작업의 반환 시간의 평균 
    // 반환 시간 = 종료시간 - 요청시간

    sort(jobs.begin(), jobs.end(), less<>()); // 오름차순

    //  작업의 소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것 순으로 우선순위가 높습니다.
    auto CC = [](const Task& t1, const Task& t2) {
        if (t1.Duration == t2.Duration)
        {
            if (t1.ReqTime == t2.ReqTime)
            {
                return t1.Number > t2.Number;
            }
            return t1.ReqTime > t2.ReqTime; // 요청시각 빠른것 우선
        }
        return t1.Duration > t2.Duration; // 소요시간 짧은것 우선
        };
    priority_queue<Task, vector<Task>, decltype(CC)> pq(CC);

    int idx = 0;
    int curTime = jobs[0][0]; // {요청시각, 소요시간}
    int jobCount = jobs.size();

    while (true)
    {
        if (pq.empty())
        {
            if (idx >= jobCount)
            {
                break;
            }

            while (idx < jobCount && jobs[idx][0] <= curTime)
            {
                // {작업번호, 요청시각, 소요시간}
                pq.push(Task(idx, jobs[idx][0], jobs[idx][1]));
                idx++;
            }
            if(pq.empty())
                curTime = jobs[idx][0];
        }
        else
        {
            Task t = pq.top(); pq.pop(); // {작업번호, 요청시각, 소요시간}
            // 반환 시간 = 종료시간 - 요청시간
            answer += (curTime + t.Duration) - t.ReqTime;
            // cout << t.Number << "=" << (curTime + t.Duration) - t.ReqTime << " ";
            curTime += t.Duration;

            while (idx < jobCount && jobs[idx][0] <= curTime)
            {
                // {작업번호, 요청시각, 소요시간}
                pq.push(Task(idx, jobs[idx][0], jobs[idx][1]));
                idx++;
            }
        }
    }
// [[1, 4], [7, 9], [1000, 3]]
    return (answer / jobCount);
}