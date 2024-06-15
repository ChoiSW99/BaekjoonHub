#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool Visited[11][11][11][11]; 

int N, M; // N세로 M가로 --> N x M 배열

char Board[11][11];

// 상화좌우 순서
int dr[4] = { -1,+1, 0,0 };
int dc[4] = { 0,0,-1,1 };

// 정답 찾음
bool found = false;

struct StepInfo
{
	int rr=0; // red row
	int rc=0; // red col
	int br=0; // blue row
	int bc=0; // blue col
	int step = 0;

	StepInfo(int rr, int rc, int br, int bc, int st)
	{
		this->rr = rr; 
		this->rc = rc; 
		this->br = br; 
		this->bc = bc; 
		this->step = st;
	}
	StepInfo() {};
};

StepInfo Move(int i, StepInfo now, bool& isRedGoalIn, bool& isBlueGoalIn)
{
	int nrr = now.rr;
	int nrc = now.rc;
	int nbr = now.br;
	int nbc = now.bc;

	while (true)
	{
		nrr += dr[i];
		nrc += dc[i];
		if (Board[nrr][nrc] == '#') // 벽이면 뒤로 한칸
		{
			nrr -= dr[i];
			nrc -= dc[i];
			break;
		}
		if (Board[nrr][nrc] == 'O') // 빨간공 골인
		{
			isRedGoalIn = true;
			break;
		}
	}

	while (true)
	{
		nbr += dr[i];
		nbc += dc[i];
		if (Board[nbr][nbc] == '#')
		{
			nbr -= dr[i];
			nbc -= dc[i];
			break;
		}
		if (Board[nbr][nbc] == 'O')
		{
			isBlueGoalIn = true;
			break;
		}
	}

	// 공들이 겹칠 때.
	if (nrr == nbr && nrc == nbc)
	{
		if (i == 0) //상
		{
			if (now.rr < now.br) // 빨간공이 위에 있었으면
			{
				// 파란공을 한칸 물림
				nbr -= dr[i];
				nbc -= dc[i];
			}
			else if (now.rr > now.br)
			{
				nrr -= dr[i];
				nrc -= dc[i];
			}
		}
		else if (i == 1) // 하
		{
			if (now.rr > now.br) // 빨간공이 아래에 있었으면
			{
				// 파란공을 한칸 물림
				nbr -= dr[i];
				nbc -= dc[i];
			}
			else if (now.rr < now.br) // 빨간공이 위에 있었으면
			{
				nrr -= dr[i];
				nrc -= dc[i];
			}
		}
		else if (i == 2) // 좌
		{
			if (now.rc < now.bc) // 빨간공이 왼쪽에 있었으면
			{
				// 파란공을 한칸 물림
				nbr -= dr[i];
				nbc -= dc[i];
			}
			else if (now.rc > now.bc)
			{
				nrr -= dr[i];
				nrc -= dc[i];
			}
		}
		else if (i == 3) // 우
		{
			if (now.rc > now.bc) // 빨간공이 오른쪽에 있었으면
			{
				// 파란공을 한칸 물림
				nbr -= dr[i];
				nbc -= dc[i];
			}
			else if (now.rc < now.bc)
			{
				nrr -= dr[i];
				nrc -= dc[i];
			}
		}
	}
	return StepInfo(nrr, nrc, nbr, nbc, now.step + 1);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	memset(Visited, false, sizeof(Visited));

	StepInfo initStep = StepInfo();

	for (int r = 1; r <= N; r++)
	{
		string input; cin >> input;
		for (int c = 1; c <= M; c++)
		{
			Board[r][c] = input[c-1];
			if (Board[r][c] == 'R')
			{
				initStep.rr = r; initStep.rc = c;
			}
			else if (Board[r][c] == 'B')
			{
				initStep.br = r; initStep.bc = c;
			}
		}
	}
	initStep.step = 0;

	queue<StepInfo> que;
	que.push(initStep);
	Visited[initStep.rr][initStep.rc][initStep.br][initStep.bc] = true;

	while (!que.empty())
	{
		StepInfo now = que.front();
		que.pop();

		// 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1
		if (now.step >= 10)
			break;

		// 상하좌우 순으로 기울여보기
		for (int i = 0; i < 4; i++)
		{
			bool isRedGoalIn = false;
			bool isBlueGoalIn = false;

			StepInfo next = Move(i, now, isRedGoalIn, isBlueGoalIn);

			// 이미 방문
			if (Visited[next.rr][next.rc][next.br][next.bc])
				continue;

			// 골인여부 확인
			if (isBlueGoalIn)
				continue;
			else
			{
				if (isRedGoalIn)
				{
					cout << next.step;
					found = true;
					break;
				}
				else
				{
					
					//cout << next.rr << ", " << next.rc << ", " << next.br << ", " << next.bc << "\n";
					que.push(next);
					Visited[next.rr][next.rc][next.br][next.bc] = true;
				}
			}
		}

		if (found)
			break;
	}
	if (!found)
		cout << -1;

	return 0;
}