/*
	터지는 경우 : 상하좌우로 같은색 4개이상 붙어있을 때
	여러곳에서 터질 수 있으면, 한번에 터진다. 연쇄 또한 +1만 된다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char field[12][6];
bool visited[12][6];

int dr[4] = { -1, +1, 0, 0 };
int dc[4] = { 0, 0, -1, +1 };


vector<pair<int, int>> findAdjacency(int row, int col) {

	char current = field[row][col];

	vector<pair<int, int>> adjacency; // 인접한 뿌요들(터뜨리기 위해 좌표 저장)
	adjacency.push_back({ row,col });
	
	queue<pair<int, int>> que;
	que.push({ row,col });
	visited[row][col] = true;


	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr > 11 || nc < 0 || nc > 5) continue;
			if (visited[nr][nc]) continue;

			if (field[nr][nc] == current) {
				que.push({ nr,nc });
				adjacency.push_back({ nr, nc });
				visited[nr][nc] = true;
			}
		}
	}
	return adjacency;
}

void clearBbuyo(vector<pair<int, int>> adjacency) {
	for (pair<int, int> bbuyo : adjacency) {
		field[bbuyo.first][bbuyo.second] = '.';
	}
}

void moveBbuyo() {
	 // column별로 내려주기
	for (int c = 0; c < 6; c++) {
		for (int r = 11; r >= 1; r--) {

			if (field[r][c] != '.') 
				continue;

			// 위쪽 확인하기
			for (int upRow = r-1; upRow >= 0; upRow--) {

				if (field[upRow][c] == '.')
					continue; 

				field[r][c] = field[upRow][c];
				field[upRow][c] = '.';
				break;
			}
		}
	}
}

/* 뿌요가 터지는지 */
bool hasExploded() {

	bool result = false;

	memset(visited, false, sizeof(visited)); // memset은 -1, 0, 0x3f, 0x7f 만 쓰기!

	for (int r = 0; r < 12; r++) {
		for (int c = 0; c < 6; c++) {

			if (visited[r][c]) {
				continue;
			}

			if (field[r][c] == '.') {
				visited[r][c] = true;
				continue;
			}

			vector<pair<int, int>> adjacency = findAdjacency(r, c);
			//cout << "size = " << adjacency.size() << "\n";
			// 4개이상 붙어있을 때, 터진다.
			if (adjacency.size() >=  4) {
				clearBbuyo(adjacency); // 뿌요 터뜨리기
				moveBbuyo(); // 뿌요 내려오기

				result = true;
				
			}
		}
	}

	return result;
}

int main() {

	for (int r = 0; r < 12; r++) {
		for (int c = 0; c < 6; c++) {
			cin >> field[r][c];
		}
	}

	//for (int r = 0; r < 12; r++) {
	//	for (int c = 0; c < 6; c++) {
	//		cout << field[r][c];
	//	}
	//	cout << "\n";
	//}

	int chainCnt = 0; // 연쇄횟수

	while (true) {
		if (hasExploded()) {
			chainCnt++;
		}
		else {
			break;
		}
	}

	cout << chainCnt;

	return 0;
}