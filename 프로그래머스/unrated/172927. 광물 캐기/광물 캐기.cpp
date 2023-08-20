#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 0;
    priority_queue<tuple<int, int, int>> pq;

    int picksSum = picks[0] + picks[1] + picks[2];
    bool stop = false;

    int dia, iro, sto;
    dia = 0, iro = 0, sto = 0;

    int i;
    for (i = 1; i < minerals.size() + 1; i++)
    {
        if (picksSum * 5 < i) {
            stop = true;
            break;
        }
            

        if (minerals[i - 1] == "diamond")
            dia += 1;
        else if (minerals[i - 1] == "iron")
            iro += 1;
        else if (minerals[i - 1] == "stone")
            sto += 1;

        if (i % 5 == 0)
        {
            pq.push(make_tuple(dia, iro, sto));
            dia = 0, iro = 0, sto = 0;
        }
    }

    if (!stop && (dia > 0 || iro > 0 || sto > 0)) {
        pq.push(make_tuple(dia, iro, sto));
        dia = 0, iro = 0, sto = 0;
    }

    while (!pq.empty() && (picks[0] > 0 || picks[1] > 0 || picks[2] > 0))
    {
        tuple<int, int, int> t = pq.top();
        pq.pop();

        if (picks[0] > 0) // 다이아 곡갱이
        {
            answer += (get<0>(t) + get<1>(t) + get<2>(t));
            picks[0] -= 1;
        }
        else if (picks[1] > 0) // 철 곡갱이
        {
            answer += (get<0>(t) * 5 + get<1>(t) + get<2>(t));
            picks[1] -= 1;
        }
        else if (picks[2] > 0) // 돌 곡갱이
        {
            answer += (get<0>(t) * 25 + get<1>(t) * 5 + get<2>(t));
            picks[2] -= 1;
        }
    }

    return answer;
}
