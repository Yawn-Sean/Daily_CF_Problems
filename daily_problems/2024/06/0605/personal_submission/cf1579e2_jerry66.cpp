#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200100;

int t, n;
int a[N];

int tr[N];

vector<int> ls;

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int d)
{
	for (int i = x; i <= ls.size(); i += lowbit(i))
		tr[i] += d;
}

int query(int x)
{
	int sum = 0;
	for (int i = x; i; i -= lowbit(i)) sum += tr[i];
	return sum;
}


int get(int x)
{
	int p = lower_bound(ls.begin(), ls.end(), x) - ls.begin();
	return p + 1;
}

void solve()
{
	ls.clear();

	cin >> n;
	for (int i = 0; i < n; i ++ ) cin >> a[i], ls.push_back(a[i]);

	sort(ls.begin(), ls.end());
	ls.erase(unique(ls.begin(), ls.end()), ls.end());
	

	int sz = ls.size();
	for (int i = 0; i <= sz; i ++ ) tr[i] = 0;

	LL cnt = 0;
	for (int i = 0; i < n; i ++ ) 
	{
		int v = get(a[i]);
		int big = query(sz) - query(v);
		int small = query(v - 1);
		cnt = cnt + (LL)min(big, small);
		add(v, 1);
	}

	cout << cnt << '\n';
}

signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> t;
	while (t -- ) solve();
}
