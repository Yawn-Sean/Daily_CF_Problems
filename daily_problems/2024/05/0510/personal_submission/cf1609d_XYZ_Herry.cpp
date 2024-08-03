#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int p[N], cnt[N];
int n, m;

int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;
    int t = 0, res = 0;
    for (int i = 1; i <= n; i ++ ) cnt[i] = 1, p[i] = i;
    for (int i = 0; i < m; i ++ )
    {
    	int a, b;
    	cin >> a >> b;
    	a = find(a), b = find(b);
    	if (a != b)
    	{
    		p[a] = b;
    		cnt[b] += cnt[a];
    		res = max(res, cnt[b]);
    	}
    	else t ++ ;
    	int ans = res;
    	if (t > 0)
    	{
    		set<int> se;
	    	vector<int> v;
	    	for (int j = 1; j <= n; j ++ )
	    	{
	    		int f = find(j);
	    		if (!se.count(f)) v.push_back(cnt[f]);
	    		se.insert(f);
	    	}
	    	sort(v.begin(), v.end());
	    	int len = v.size();
	    	for (int j = 0; j < t; j ++ ) ans += v[len - j - 2];
    	}
    	cout << ans - 1 << endl;
    }
	return 0;
}
