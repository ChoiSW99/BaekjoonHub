#include <bits/stdc++.h>

using namespace std;

void Command(char op, list<char>& editor, list<char>::iterator& cursor)
{
	switch (op)
	{
	case 'L':
		if (cursor != editor.begin())
			cursor--;
		break;
	case 'D':
		if (cursor != editor.end())
			cursor++;
		break;
	case 'B':
		if (cursor != editor.begin())
			cursor = editor.erase(--cursor);
		break;
	case 'P':
		char num;
		cin >> num;
		editor.insert(cursor, num);
		break;
	}
}

// abcd-
// abc-

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string input;
	getline(cin, input);
	list<char> editor;

	for(int i=0; i<input.size(); i++)
		editor.push_back(input[i]);

	list<char>::iterator cursor = editor.end(); // 문장의 맨 뒤

	int M;
	cin >> M;

	while (M--)
	{
		char op;
		cin >> op;
		Command(op, editor, cursor);
	}
	for (char c : editor)
		cout << c;
}