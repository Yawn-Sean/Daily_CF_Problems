// Problem: D. Something with XOR Queries
// Contest: Codeforces - Technocup 2018 - Elimination Round 2
// URL: https://codeforces.com/problemset/problem/870/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
	
	vector<int> pb(n,0),bp(n,0);
	
	auto query=[&](int i,int j){
		cout<<"? "<<i<<" "<<j<<endl;
		int x;
		cin>>x;
		return x;
	};
	
	for(int i=0;i<n;i++){
		pb[i]=query(0,i);
		if(i) bp[i]=query(i,0);
	}
	int cnt=0;
	vector<int> res(n);
	vector<int> ans;
	vector<int> b(n);
	for(int i=0;i<n;i++){
		for(int i=0;i<n;i++) res[i]=0;
		res[0]=i;
		bool flag=1;
		for(int i=0;i<n;i++) {
			b[i]=res[0]^pb[i];
			if(b[i]<0 or b[i]>=n) flag=0;
		}
		if(!flag) continue;
		for(int i=0;i<n;i++){
			res[b[i]]=i;
			if(!b[i] and res[0]!=i) flag=0; 
		}
		if(!flag) continue;
		for(int i=1;i<n;i++){
			if(res[i]<0 or res[i]>=n) flag=0;
			if((res[i]^b[0])!=bp[i]) flag=0;
		}
		if(flag){
			cnt++;
			ans=res;
		}
	}
	cout<<"!"<<endl;
	cout<<cnt<<endl;
	for(int i=0;i<n;i++) cout<<ans[i]<<" ";cout<<endl;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
