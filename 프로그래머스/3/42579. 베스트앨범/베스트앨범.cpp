#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;
// 장르별 가장많이재생 2개씩 고르기
// 가장 많이재생된 장르 고르고 -> 그 장르에서 가장많이재생된 2개 고르기
// 만약 횟수가 같으면, 고유번호 낮은 것을 수록하기

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if(p1.second != p2.second)
        return p1.second > p2.second;
    else
    {
        return p1.first < p2.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> m1;
    map<string, vector<pair<int, int>>> m2;
    // map2개 (하나는 장르별 총 재생수)
    //        (다른하나는 장르별 [고유번호, 노래재생수])
    
    for(int i=0; i<genres.size(); i++)
    {
        m1[genres[i]] += plays[i];
        m2[genres[i]].push_back({i,plays[i]});
    }
    vector<pair<string, int>> v;
    for(pair<string, int> p : m1)
        v.push_back(p);
    sort(v.begin(), v.end(), [](pair<string, int>& p1, pair<string, int>& p2) {
        return p1.second > p2.second;
    });
        
    // 1번맵으로 가장 큰 순서부터 확인할 수 있다. -> for(auto ~~)
    // for문 내에서, 정렬후, 2개씩 뽑는다.
    for (pair<string, int> p : v)
    {
        //cout << p.first << "->" << p.second << endl;
        sort(m2[p.first].begin(), m2[p.first].end(), comp);
        
        int j = std::min(2, (int)m2[p.first].size());
        for(int i=0; i<j; i++)
        {
            answer.push_back(m2[p.first][i].first);
        }
    }
    // "classic" : n    
    // "classic" : [[,], [,]]
    return answer;
}