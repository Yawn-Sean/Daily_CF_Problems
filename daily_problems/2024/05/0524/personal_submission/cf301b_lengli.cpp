// Problem: B. Yaroslav and Time
// Contest: Codeforces - Codeforces Round 182 (Div. 1)
// URL: https://codeforces.com/problemset/problem/301/b
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=110;

int n,d;
int a[N];
array<int,2> pt[N];
int dist[N][N];

void solve(){
	cin>>n>>d;
	for(int i=2;i<n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++) cin>>pt[i][0]>>pt[i][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			int len=abs(pt[i][0]-pt[j][0])+abs(pt[i][1]-pt[j][1]);
			len=d*len-a[j];
			if(i!=j) dist[i][j]=len;
			else dist[i][j]=0;
		}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	cout<<dist[1][n];
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
