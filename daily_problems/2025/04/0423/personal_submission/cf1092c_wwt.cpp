#include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;

#include <iostream>
#include <map>
#include <string>


int main()
{
	int n;
	cin >> n;
	vector<string> strs(2 * n - 2);
	for (string& s : strs)
	{
		cin >> s;
	}
	map<string, vector<int>> mp;
	for (int i = 0; i < 2 * n - 2; i++)
	{
		mp[strs[i]].push_back(i);
	}
	vector<int> tmp;
	for (int i = 0; i < 2 * n - 2; i++)
	{
		if (strs[i].size() == n - 1)
		{
			tmp.push_back(i);
		}
	}
	string s1 = strs[tmp[0]], s2 = strs[tmp[1]];//要么前缀要么后缀
	string ans(2 * n - 2,' ');
	auto check = [&](string s)->void {
		map<string, vector<bool>> cnt;
		for (int i = 1; i < n; i++)
		{
			cnt[s.substr(0, i)].push_back(1);
			cnt[s.substr(n - i, i)].push_back(0);
		}
		for (auto& [k, v] : mp)
		{
			if (cnt[k].size() != v.size())
			{
				return ;
			}
		}
		for (auto& [k, v] : mp)
		{
			for (int i = 0; i < v.size(); i++)
			{
				ans[v[i]] = (cnt[k][i] ? 'P' : 'S');
			}
		}
		cout << ans;
		exit(0);

	};

	check(s1 + s2. back());
	check(s2 + s1. back());


	return 0;
}
