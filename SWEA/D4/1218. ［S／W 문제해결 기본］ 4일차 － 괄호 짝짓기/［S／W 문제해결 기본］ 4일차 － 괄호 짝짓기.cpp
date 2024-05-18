#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 10;
	for (int tc = 1; tc <= T; tc++)
	{
		stack<char> st;
		int l; cin >> l;
		string input; cin >> input;
		bool isValid = true;
		for (int i = 0; i < l; i++)
		{
			if (!isValid)
				break;
			switch (input[i])
			{
			case '(':
			case '{':
			case '[':
			case '<':
				st.push(input[i]);
				break;

			case ')': {
				if (st.empty())
				{
					isValid = false;
					break;
				}
				char t = st.top();
				if (t != '(')
				{
					isValid = false;
					break;
				}
				st.pop();
				break;
			}
			case '}': {
				if (st.empty())
				{
					isValid = false;
					break;
				}
				char t = st.top();
				if (t != '{')
				{
					isValid = false;
					break;
				}
				st.pop();
				break;
			}
			case ']': {
				if (st.empty())
				{
					isValid = false;
					break;
				}
				char t = st.top();
				if (t != '[')
				{
					isValid = false;
					break;
				}
				st.pop();
				break;
			}
			case '>': {
				if (st.empty())
				{
					isValid = false;
					break;
				}
				char t = st.top();
				if (t != '<')
				{
					isValid = false;
					break;
				}
				st.pop();
				break;
			}
			}
		}
		cout << "#" << tc << " ";
		if (isValid)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}

