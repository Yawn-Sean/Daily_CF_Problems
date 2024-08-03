#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 3010;

vector<int> v[N];
vector<int> pos[N];
vector<LL> a[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++ )
	{
		int idx, t;
		cin >> idx >> t;
		if (idx != 0) v[idx].push_back(t);
	}	
	LL ans = 2e18;
	int cnt1 = v[1].size();
	for (int i = 2; i <= m; i ++ )
	{
		if (v[i].empty()) continue;
		int len = v[i].size();
		sort(v[i].begin(), v[i].end());
		a[i].resize(len);
		a[i][0] = v[i][0];
		for (int j = 1; j < len; j ++ ) a[i][j] = a[i][j - 1] + v[i][j];
	} 
	for (int i = cnt1; i <= n; i ++ )
	{
		int t = 0;
		LL res = 0;
		vector<int> p;
		for (int j = 2; j <= m; j ++ )
		{
			if (v[j].empty()) continue;
			int len = v[j].size();
			if (len >= i)
			{
				for (int k = len - i + 1; k < len; k ++ ) p.push_back(v[j][k]);
				t += len - i + 1;
				//for (int k = 0; k <= len - i; k ++ ) res += v[j][k];
				res += a[j][len - i];
			} 
			else
			{
				for (int k = 0; k < len; k ++ ) p.push_back(v[j][k]);
			} 
		}
		//cout << cnt1 << ' ' << t << ' ' << i << endl;
		if (cnt1 + t > i) continue;
		t = i - cnt1 - t;
		sort(p.begin(), p.end());
		for (auto x : p)
		{
			if (t == 0) break;
			res += x;
			t -- ;
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}
