// Problem: C. Remove Extra One
// Contest: Codeforces - Codeforces Round 450 (Div. 2)
// URL: https://codeforces.com/problemset/problem/900/C
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

const int N=100010;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	vector<int> cnt(n);
	
	int ma0=-1,ma1=-1;
	int res=0;
	for(int i=0;i<n;i++){
		if(ma0==-1 or a[i]>a[ma0]) res++,cnt[i]--;
		
		if(ma0!=-1){
			if(ma1==-1){
				if(a[i]<a[ma0]) cnt[ma0]++;
			}else if(a[i]<a[ma0] and a[i]>a[ma1]) cnt[ma0]++;
		}
		
		
		if(ma0==-1) ma0=i;
		else if(a[i]>a[ma0]) ma1=ma0,ma0=i;
		else if(ma1==-1) ma1=i;
		else if(a[i]>a[ma1]) ma1=i;
	}
	int ma=-1,v=1e9;
	for(int i=0;i<n;i++){
		int ans=res+cnt[i];
		if(ans>ma) ma=ans,v=a[i];
		else if(ans==ma and v>a[i]) v=a[i];
	}
	cout<<v<<endl;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
