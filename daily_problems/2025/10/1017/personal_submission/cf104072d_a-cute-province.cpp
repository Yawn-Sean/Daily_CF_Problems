#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 3010;
/*
	二维数点，nlogn
*/
int fenwick[N]; 
void add(int x){//单点修改
    for(; x < N; x += x&-x){
        fenwick[x]++;
    }
}
void del(int x){
    for(; x < N; x += x&-x){
        fenwick[x]--;
    }
}
int query(int l, int r){//区间查询
    if(r < l)return 0;
    int suml = 0, sumr = 0;
    for(; r!=0; r -= r&-r){
        sumr += fenwick[r];
    }
    l--;
     for(; l!=0; l -= l&-l){
        suml += fenwick[l];
    }
    return sumr - suml;
}
void solve()
{   
    int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	vector<vector<int>> u = grid, d = grid, l = grid, r = grid;

	for (int i = 1; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (u[i][j]) u[i][j] = u[i - 1][j] + 1;
		}
	}

	for (int i = n - 2; i >= 0; i --) {
		for (int j = 0; j < n; j ++) {
			if (d[i][j]) d[i][j] = d[i + 1][j] + 1;
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 1; j < n; j ++) {
			if (l[i][j]) l[i][j] = l[i][j - 1] + 1;
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = n - 2; j >= 0; j --) {
			if (r[i][j]) r[i][j] = r[i][j + 1] + 1;
		}
	}
  
    auto solve = [&] (int x, int y) -> int {
        memset(fenwick, 0, sizeof fenwick);
		vector<int> v1, v2;
		while (x < n & y < n) {
			v1.emplace_back(min(d[x][y], r[x][y]) - 1);
			v2.emplace_back(min(u[x][y], l[x][y]) - 1);
			x ++, y ++;
		}
		
		int k = v1.size(), ans = 0;

		vector<vector<int>> tmp(k + 5);

		for (int i = 1; i <= k; i ++)
			tmp[i - v2[i-1]].emplace_back(i);
		
		for (int i = 1; i <= k; i ++) {
			for (auto &j: tmp[i]) add(j);
			ans += query(1, min(i + v1[i-1], k));   
		}

		return ans - k * (k - 1) / 2;
	};
    int res = solve(0, 0);
    for (int i = 1; i < n; i ++)
		res += solve(0, i) + solve(i, 0);
    cout << res << '\n';
}

signed cute_prov0nce()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
