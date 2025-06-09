#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

#include <iostream>
#include <map>
#include <string>


int main()
{
	int t;
	int n, m, a, b;
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n >> m >> a >> b;
		vector<int> s(m);
		for (auto& x : s)
		{
			cin >> x;
		}
		sort(s.begin(), s.end());
		if (b < a)
		{
			a = n - a + 1;
			b = n - b + 1;
		}
		int ke = b - a - 1;
		int index = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] <= a - 1 + ke)
			{
				index = i;
			}
		}
		while (ke)
		{
			if (index < 0)
			{
				break;
			}
			if (s[index] <= a - 1 + ke)
			{
				index--;
				ans++;
			}
			else
			{
				index--;
				continue;
			}
			ke--;
		}

		cout << ans << endl;
	}
	return 0;
}
