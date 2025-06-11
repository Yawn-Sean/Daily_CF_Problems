#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 1e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void print(vector <int> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
}

void solve(){
    const int mod = 1e6+3;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector <int> vis0(n, -1), vis1(m, -1);

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            char ch;
            cin >> ch;
            if (isdigit(ch)) g[i][j] = ch - '0';
            else g[i][j] = -1;
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (g[i][j] > 0){
				int v0 = (j & 1) ^ (g[i][j] == 1 || g[i][j] == 2);
				int v1 = (i & 1) ^ (g[i][j] == 1 || g[i][j] == 4);

				if (vis0[i] == -1) vis0[i] = v0;
				else if (vis0[i] != v0) return cout << 0 << "\n", void();

				if (vis1[j] == -1) vis1[j] = v1;
				else if (vis1[j] != v1) return cout << 0 << "\n", void();
            }
        }
    }
    int ans = 1;
	for (auto &v: vis0)
		if (v == -1) ans = ans * 2 % mod;
	
	for (auto &v: vis1)
		if (v == -1) ans = ans * 2 % mod;
	
	cout << ans << "\n";
}
