#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef pair<int, int> pt;

#define x first
#define y second


int m, n, k, t;
vector<int> l, r, d, a;

bool can(int x)
{
	int mn = int(1e9);
	for (int i = 0; i < x; i++)
		mn = min(mn, a[i]);
	vector<pt> segm;
	for (int i = 0; i < k; i++)
		if (d[i] > mn)
			segm.push_back(make_pair(l[i], r[i]));
	int req_time = 0;
	sort(segm.begin(), segm.end());
	int lastr = 0;
	for (auto s : segm)
	{
		if (s.x <= lastr)
		{
			req_time += max(0, s.y - lastr);
			lastr = max(s.y, lastr);
		}
		else
		{
			req_time += s.y - s.x + 1;
			lastr = s.y;
		}
	}
	req_time = 2 * req_time + n + 1;
	return req_time <= t;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d %d %d", &m, &n, &k, &t);
	a.resize(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	l.resize(k);
	r.resize(k);
	d.resize(k);
	for (int i = 0; i < k; i++)
		scanf("%d %d %d", &l[i], &r[i], &d[i]);

	int lf = 0;
	int rg = m + 1;
	while (rg - lf > 1)
	{
		int mid = (lf + rg) / 2;
		if (can(mid))
			lf = mid;
		else
			rg = mid;
	}
	printf("%d\n", lf);
	return 0;
}
