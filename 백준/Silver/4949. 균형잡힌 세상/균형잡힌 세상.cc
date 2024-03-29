#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	while (true)
	{
		getline(cin, input);
		if (input[0] == '.')
			return 0;

		stack<char> st;
		for (char c : input)
		{
			if (c == '(' || c=='[')
				st.push(c);
			else if (c == ')')
			{
				if (st.empty())
				{
					cout << "no" << '\n';
					break;
				}
				else
				{
					char cc = st.top();
					if (cc == '(')
						st.pop();
					else
					{
						cout << "no" << '\n';
						break;
					}
				}
			}
			else if (c == ']')
			{
				if (st.empty())
				{
					cout << "no" << '\n';
					break;
				}
				else
				{
					char cc = st.top();
					if (cc == '[')
						st.pop();
					else
					{
						cout << "no" << '\n';
						break;
					}
				}
			}
			else if (c == '.')
			{
				if (st.empty())
					cout << "yes" << '\n';
				else
					cout << "no" << '\n';
			}
		}
	}

	return 0;
}