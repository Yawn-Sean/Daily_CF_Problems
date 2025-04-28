#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

#include <iostream>
#include <map>
#include <string>


int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (auto& s : v)
	{
		cin >> s;
	}
	int sx, sy, fx, fy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 'S')
			{
				sx = i, sy = j;
			}
			if (v[i][j] == 'T')
			{
				fx = i, fy = j;
			}
		}
	}
	auto check = [&](int x1, int y1, int x2, int y2)->bool
	{
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);

		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				if (v[i][j] == '*')
				{
					return false;
				}
			}
		}
		return true;
	};

	for (int i = 0; i < n; i++)

	{
		if (check(sx, sy, i, sy) && check(i, sy, i, fy) && check(i, fy, fx, fy))
		{
			cout << "YES";
			return 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (check(sx, sy, sx, i) && check(sx, i, fx, i) && check(fx, i, fx, fy))
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}
