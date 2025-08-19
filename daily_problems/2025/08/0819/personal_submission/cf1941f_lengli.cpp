// Problem: F. Rudolf and Imbalance
// Contest: Codeforces - Codeforces Round 933 (Div. 3)
// URL: https://codeforces.com/contest/1941/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	int mx=-1,smx=-1,cnt=0,idx=0;
	for(int i=1;i<n;i++){
		int d=a[i]-a[i-1];
		if(d>mx) smx=mx,mx=d,cnt=1,idx=i-1;
		else if(d==mx) cnt++;
		else if(d>smx) smx=d;
	}
	vector<int> b(m);
	vector<int> f(k);
	for(auto &x:b) cin>>x;
	for(auto &x:f) cin>>x;
	sort(all(b));
	sort(all(f));
	f.push_back(2e9);
	b.erase(unique(all(b)),b.end());
	f.erase(unique(all(f)),f.end());
	
	if(cnt>=2) cout<<mx<<endl;
	else{
		int ll=a[idx],rr=a[idx+1];
		auto res=mx;
		for(auto x:b){
			if(x>rr) break;
			
			auto check=[&](int t)->int{
				int nd=t-x;
				int it1=upper_bound(f.begin(),f.end(),nd)-f.begin()-1;
				// int ct=2e9;
				// if(f[it]>nd) return ct;
				// if(f[it]+x>=ll and f[it]+x<=rr){
					// int p=f[it]+x;
					// ct=max(p-ll,rr-p);
				// }
				// it++;
				// if(f[it]+x>=ll and f[it]+x<=rr){
					// int p=f[it]+x;
					// ct=min(ct,max(p-ll,rr-p));
				// }
				int ct=2e9;
				for(int it=max(0ll,it1-5ll);it<=min((int)f.size()-1,it1+5);it++){
					if(f[it]+x>=ll and f[it]+x<=rr){
						int p=f[it]+x;
						ct=min(ct,max(p-ll,rr-p));
					}
				}
				return ct;
			};

			int mid=(ll+rr)/2;
			int ans=2e9;
			for(int jj=max(ll,mid-5);jj<=min(rr,mid+5);jj++){
				ans=min(ans,check(jj));
			}
			res=min(res,ans);
			
		}
		res=max(res,smx);
		cout<<res<<endl;
	}
	
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
