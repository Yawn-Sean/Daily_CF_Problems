// Problem: G. Harvester
// Contest: Codeforces - Bubble Cup 12 - Finals [Online Mirror, unrated, Div. 2]
// URL: https://codeforces.com/problemset/problem/1219/G
// Memory Limit: 256 MB
// Time Limit: 500 ms

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
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m,0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) cin>>a[i][j];
	vector<int> h(n,0),l(m,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			h[i]+=a[i][j];
			l[j]+=a[i][j];
		}
	}
	
	if(n+m<=4){
		int res=0;
		for(auto x:a) for(auto y:x) res+=y;
		cout<<res<<endl;
		return;
	}
	
	auto cal4=[&](vector<int> q){
		if(q.size()<4) return 0ll;
		sort(all(q),greater<>());
		return q[0]+q[1]+q[2]+q[3];
	};
	
	auto res=max(cal4(h),cal4(l));
	
	auto cal_1_3=[&](vector<int> &ll,vector<int> &rr){
		if(rr.size()<3) return 0ll;
		int res=0;
		for(int i=0;i<n;i++){
			priority_queue<int> q;
			for(int j=0;j<m;j++) q.push(rr[j]-a[i][j]);
			int ans=ll[i];
			for(int j=0;j<3;j++){
				ans+=q.top();
				q.pop();
			}
			res=max(res,ans);
		}
		return res;
	};
	auto cal_3_1=[&](vector<int> &ll,vector<int> &rr){
		if(ll.size()<3) return 0ll;
		int res=0;
		for(int i=0;i<m;i++){
			priority_queue<int> q;
			for(int j=0;j<n;j++) q.push(ll[j]-a[j][i]);
			int ans=rr[i];
			for(int j=0;j<3;j++){
				ans+=q.top();
				q.pop();
			}
			res=max(res,ans);
		}
		return res;
	};
	
	res=max(res,cal_1_3(h,l));
	res=max(res,cal_3_1(h,l));
	
	auto cal2=[&](vector<int> ll,vector<int> rr){
		int res=0;
		if(n<m){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i==j) continue;
					int ans=ll[i]+ll[j];
					int fm=0,sm=0;
					for(int k=0;k<m;k++) {
						int v=rr[k]-a[i][k]-a[j][k];
						if(v>fm) sm=fm,fm=v;
						else if(v>sm) sm=v;
					}
					ans+=fm+sm;
					res=max(res,ans);
				}
			}
		}else{
			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					if(i==j) continue;
					int ans=rr[i]+rr[j];
					int fm=0,sm=0;
					for(int k=0;k<n;k++) {
						int v=ll[k]-a[k][i]-a[k][j];
						if(v>fm) sm=fm,fm=v;
						else if(v>sm) sm=v;
					}
					ans+=fm+sm;
					res=max(res,ans);
				}
			}
		}
		return res;
	};
	
	res=max(res,cal2(h,l));
	
	cout<<res<<endl;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
