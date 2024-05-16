#include <bits/stdc++.h>

using namespace std;

char Map[21][21];
int H, W;
int curRow, curCol;

void Move(char dir)
{
	int nextCol, nextRow;
	switch (dir)
	{
	case '<':
		nextCol = curCol - 1;
		if (nextCol >= 0)
			if (Map[curRow][nextCol] == '.')
			{
				Map[curRow][curCol] = '.';
				Map[curRow][nextCol] = '<';
				curCol = nextCol;
			}
		break;
	case '>':
		nextCol = curCol + 1;
		if (nextCol < W)
			if (Map[curRow][nextCol] == '.')
			{
				Map[curRow][curCol] = '.';
				Map[curRow][nextCol] = '>';
				curCol = nextCol;
			}
		break;
	case '^':
		nextRow = curRow - 1;
		if (nextRow >= 0)
			if (Map[nextRow][curCol] == '.')
			{
				Map[curRow][curCol] = '.';
				Map[nextRow][curCol] = '^';
				curRow = nextRow;
			}
		break;
	case 'v':
		nextRow = curRow + 1;
		if (nextRow < H)
			if (Map[nextRow][curCol] == '.')
			{
				Map[curRow][curCol] = '.';
				Map[nextRow][curCol] = 'v';
				curRow = nextRow;
			}
		break;
	}
}

void Shoot()
{
	char curDir = Map[curRow][curCol];
	int dst = 1;
	switch (curDir)
	{
	case '<':
		while (true)
		{
			int nextCol = curCol - dst;
			if (nextCol >= 0)
			{
				char next = Map[curRow][nextCol];
				if (next == '#')
					break;
				else if (next == '*') // 벽돌
				{
					Map[curRow][nextCol] = '.';
					break;
				}

				dst++;
			}
			else
				break;
		}
		break;
	case '>':
		while (true)
		{
			int nextCol = curCol + dst;
			if (nextCol < W)
			{
				char next = Map[curRow][nextCol];
				if (next == '#')
					break;
				else if (next == '*') // 벽돌
				{
					Map[curRow][nextCol] = '.';
					break;
				}

				dst++;
			}
			else
				break;
		}
		break;
	case '^':
		while (true)
		{
			int nextRow = curRow - dst;
			if (nextRow >= 0)
			{
				char next = Map[nextRow][curCol];
				if (next == '#')
					break;
				else if (next == '*') // 벽돌
				{
					Map[nextRow][curCol] = '.';
					break;
				}
				dst++;
			}
			else
				break;
		}
		break;
	case 'v':
		while (true)
		{
			int nextRow = curRow + dst;
			if (nextRow < H)
			{
				char next = Map[nextRow][curCol];
				if (next == '#')
					break;
				else if (next == '*') // 벽돌
				{
					Map[nextRow][curCol] = '.';
					break;
				}

				dst++;
			}
			else
				break;
		}
		break;
	}
}
void Operate(char op)
{
	switch (op)
	{
	case 'U':
		Map[curRow][curCol] = '^';
		Move('^');
		break;
	case 'D':
		Map[curRow][curCol] = 'v';
		Move('v');
		break;
	case 'L':
		Map[curRow][curCol] = '<';
		Move('<');
		break;
	case 'R':
		Map[curRow][curCol] = '>';
		Move('>');
		break;
	case 'S':
		Shoot();
		break;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> H >> W; // row, col
		
		for (int r = 0; r < H; r++)
			for (int c = 0; c < W; c++)
			{
				char x; cin >> x;
				Map[r][c] = x;
				if (x == '<' || x == 'v' || x == '>' || x == '^')
				{
					curRow = r; curCol = c;
				}
			}
		
		int N; cin >> N;
		string command; cin >> command;
		for (int i = 0; i < N; i++)
			Operate(command[i]);
		
		cout << "#" << tc << " ";
		for (int r = 0; r < H; r++)
		{
			for (int c = 0; c < W; c++)
			{
				cout << Map[r][c];
			}
			cout << '\n';
		}
	}
}

