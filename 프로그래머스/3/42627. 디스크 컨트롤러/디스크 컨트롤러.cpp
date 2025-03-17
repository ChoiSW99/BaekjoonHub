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
        if (t1.Duration == t2.Duration) {
            if (t1.ReqTime == t2.ReqTime) {
                return t1.Number > t2.Number;
            }
            return t1.ReqTime > t2.ReqTime; // 요청시각 빠른것 우선
        }
        return t1.Duration > t2.Duration; // 소요시간 짧은것 우선
    };

    priority_queue<Task, vector<Task>, decltype(CC)> pq(CC);

    int idx = 0;
    int curTime = 0; // 요청시각
    int jobCount = jobs.size();

    while (idx < jobCount || !pq.empty()) {
        // 1. 현재 시각까지 도달한 모든 작업을 큐에 추가
        while (idx < jobCount && jobs[idx][0] <= curTime) {
            pq.push(Task(idx, jobs[idx][0], jobs[idx][1]));
            idx++;
        }

        // 2. 큐에 작업이 있으면 처리
        if (!pq.empty()) {
            Task t = pq.top(); pq.pop(); // {작업번호, 요청시각, 소요시간}
            answer += (curTime + t.Duration) - t.ReqTime;
            curTime += t.Duration;
        } else {
            // 큐가 비어있다면, 다음 작업 요청 시각으로 curTime을 갱신
            curTime = jobs[idx][0];
        }
    }

    return (answer / jobCount);
}
