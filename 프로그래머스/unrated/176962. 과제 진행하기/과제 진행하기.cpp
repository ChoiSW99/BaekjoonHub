#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct Task {
    string taskname;
    int start; //minute
    int take;
}task;

bool compare(task a, task b) {
    return a.start < b.start;
}

vector<string> solution(vector<vector<string>> plans)
{
    vector<string> answer;

    vector<task> plan;
    
    stack<pair<string, int>> st; // taskName, takeTime

    task t;
    for (int i = 0; i < plans.size(); i++) {
        t.taskname = plans[i][0];
        t.start = stoi(plans[i][1].substr(0, 2))*60 + stoi(plans[i][1].substr(3));
        t.take = stoi(plans[i][2]);
        plan.push_back(t);
    }
    sort(plan.begin(), plan.end(), compare);

    task now, next;
    int nowIdx = 0;

    next = plan[nowIdx++];


    while (nowIdx < plan.size()) {
        now = next;
        next = plan[nowIdx++];
        cout << "NOW = " << now.taskname << endl;
        cout << "next = " << next.taskname << endl;

        if (now.start + now.take > next.start)
        {
            st.push({now.taskname, now.start + now.take - next.start });
        }
        else if (now.start + now.take == next.start)
        {
            answer.push_back(now.taskname);
        }
        else { // 끝내고 시간 남음
            answer.push_back(now.taskname);
            int leftTime = next.start - (now.start + now.take);

            while (!st.empty() && leftTime > 0) {
                pair<string, int> TOP = st.top();

                if (TOP.second > leftTime) { // 다 못 끝냄, 다시 스택에 넣어주기
                    st.pop();
                    st.push({ TOP.first, TOP.second - leftTime });
                    leftTime = 0;
                }
                else if (TOP.second == leftTime) // 딱 맞게 끝냄
                {
                    answer.push_back(TOP.first);
                    st.pop();
                    leftTime = 0;
                }
                else { // (TOP.second < leftTime) // 끝내고 시간 남음
                    answer.push_back(TOP.first);
                    st.pop();
                    leftTime -= TOP.second;
                }
            }
        }
    }
    

    answer.push_back(next.taskname);

    while (!st.empty())
    {
        answer.push_back(st.top().first);
        st.pop();
    }

    return answer;
}

/*
시작 순서대로 정렬
현재 task의 종료시간(시작+소요)이 다음보다 
크면 stack에 push {"과제명", "소요시간"} 후, 다음 plan task
같으면 answer.push, 다음 plan task
작으면 answer.push, !stack.empty 면 st.top/pop , pop한 것의 종료시간 확인
*/

