// Problem: C. Travelling Salesman and Special Numbers
// Contest: Codeforces - Codecraft-18 and Codeforces Round 458 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/914/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

const int N=1010;

string s;
int k;
Mint f[N][N][2];
bool st[N][N][2];
int g[N];
int a[N],pos;

Mint dfs(int pos,int cnt,bool limit,bool zero){
	if(!pos) return !zero and g[cnt]+1==k;
	auto &res=f[pos][cnt][zero];
	if(!limit and st[pos][cnt][zero]) return res;
	Mint ans=0;
	int ma=(limit ? a[pos] : 1);
	for(int i=0;i<=ma;i++){
		ans+=dfs(pos-1,cnt+(i==1),limit and i==ma,zero and i==0);
	}
	if(!limit) res=ans,st[pos][cnt][zero]=1;
	return ans; 
}

Mint cal(){
	pos=0;
	reverse(all(s));
	for(int i=0;i<s.size();i++) a[++pos]=s[i]-'0';
	return dfs(pos,0,1,1);
}

void solve(){
	cin>>s;
	cin>>k;
	if(k==0){
		cout<<1<<endl;
		return;
	}
	g[1]=0;
	for(int i=2;i<N;i++){
		int cnt=0;
		for(int j=0;j<11;j++){
			if(i>>j&1) cnt++;
		}
		g[i]=g[cnt]+1;
	}
	auto res=cal();
	if(k==1) res-=1;
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
