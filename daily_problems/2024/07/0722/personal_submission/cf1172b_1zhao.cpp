#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

vector<long long> fa;

void dfs(int cur, int pa, vector<vector<int>> &tr, vector<long long> &f) {
	f[cur] = 1;
	int cnt_son = 0;
	for(int son: tr[cur]) {
		if(son != pa) {
			dfs(son, cur, tr, f);
			f[cur] *= f[son];
			f[cur] %= mod;
			cnt_son ++;
		}
	}
	if(pa != -1) cnt_son ++;
	
	f[cur] *= fa[cnt_son];
	f[cur] %= mod;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> tree(n);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		tree[a-1].push_back(b-1);
		tree[b-1].push_back(a-1);
	}
	
	fa.resize(n+1);
	fa[0] = 1;
	for(int i=1; i<=n; i++) {
		fa[i] = fa[i-1] * i;
		fa[i] %= mod;
	}
	
	vector<long long> f(n);
	
	dfs(0, -1, tree, f);
	
	//for(int i:f) cout << i << ' ' << endl;
	
	long long res = f[0] * n;
	res %= mod;
	
	cout << res << endl;
	
	return 0;
}
