// Problem: D. Colorful Points
// Contest: Codeforces - Codeforces Round 455 (Div. 2)
// URL: https://codeforces.com/problemset/problem/909/D
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

const int N=1000010;

array<int,2> a[N];
int idx;

void solve(){
	string s;
	cin>>s;
	int la=-1,cnt=0;
	for(auto x:s){
		int c=x-'a'+1;
		if(la==-1) la=c,cnt=1;
		else if(la==c) cnt++;
		else{
			a[++idx]={la,cnt};
			la=c,cnt=1;
		}
	}
	if(cnt) a[++idx]={la,cnt};
	
	
	
	int res=0;
	
	while(idx>1){
		int j=0;
		for(int i=1;i<=idx;i++){
			if(i==1 or i==idx){
				if(a[i][1]==1) continue;
				a[i][1]--;
				if(j>0 and a[j][0]==a[i][0]) a[j][1]+=a[i][1];
				else a[++j]=a[i];
			}else{
				a[i][1]-=2;
				if(a[i][1]<=0) continue;
				if(j>0 and a[j][0]==a[i][0]) a[j][1]+=a[i][1];
				else a[++j]=a[i];
			}
		}
		idx=j;
		res++;
	}
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
