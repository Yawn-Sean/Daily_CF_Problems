/*
    Bonelight * v * 
    20240924 I'm Happy, solved 2013 / F2
    Not Coding, No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define ll long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
	const int N = 2e5 + 50;
	int n; cin >> n;
	vector<int> a(n + 1);
	vector<int> pre(N + 1), cnt(N + 1);
	for(int i = 1; i <= n; i ++) cin >> a[i], cnt[a[i] + 1] ++;
	for(int i = 1; i <= N; i ++) pre[i] = pre[i - 1] + cnt[i];	
	
	vector<int> ans(N + 1);
	for(int i = 1; i <= N; i ++){
		for(int j = i; j <= N; j += i){
			ans[i] += j * (pre[min(N,j + i)] - pre[j]);
		}
	}
	int mx = -INF;
	for(int i = 1; i <= n; i ++) mx = max(mx, ans[a[i]]);
	cout << mx << endl; 
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
