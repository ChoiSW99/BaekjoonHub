#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 치킨 거리 = 집과 가장 가까운 치킨집 사이 거리
// 도시 치킨 거리 = 모든 집의 치킨 거리 합

int N; // N×N 도시
int M; // 치킨집 최대 M개

// int cityMap[51][51]; // 1부터 시작
vector<pair<int, int>> homes;
vector<pair<int, int>> chickenStores;

vector<int> results;

vector<int> picked;

int getCityChickenDist() {
	int cityChickenDist = 0;

	for (pair<int, int> home : homes) {
		int minDist = 1e9;
		for (int p : picked) {
			int dist = abs(home.first - chickenStores[p].first) + abs(home.second - chickenStores[p].second);
			minDist = min(minDist, dist);
		}

		cityChickenDist += minDist;
	}
	return cityChickenDist;
}

void pick(int prev, int cnt) {

	if (cnt == M) {
		// 다 고름!
		results.push_back(getCityChickenDist());
	}

	for (int i = prev + 1; i < chickenStores.size(); i++) {
		picked.push_back(i);

		pick(i, cnt + 1);

		picked.pop_back();
	}
}

int main() {

	// memset(cityMap, 0, sizeof(cityMap));

	cin >> N >> M;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			int i;
			cin >> i;
			// 0빈 칸, 1집, 2치킨집
			if (i == 1) {
				homes.push_back(make_pair(r, c));
			}
			else if (i == 2) {
				chickenStores.push_back(make_pair(r, c));
			}
		}
	}

	pick(-1, 0);
	
	cout << *min_element(results.begin(), results.end());

}