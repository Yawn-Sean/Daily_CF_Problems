// Problem: C. Rectangles
// Contest: Codeforces - AIM Tech Round 5 (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1028/C
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
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010,inf=1e18;

void solve(){
	int n;
	cin>>n;
	vector<array<int,4>> a(n);
	for(auto &[x_1,y_1,x_2,y_2]:a) cin>>x_1>>y_1>>x_2>>y_2;
	int id=-1,cnt=0;
	
	auto check=[&](array<int,4> l,array<int,4> r){
		array<int,4> res={inf,inf,inf,inf};
		if(l[2]<r[0] or l[0]>r[2]) return res;
		if(l[3]<r[1] or l[1]>r[3]) return res;
		res={max(l[0],r[0]),max(l[1],r[1]),min(l[2],r[2]),min(l[3],r[3])};
		return res;
	};
	
	srand(time(0));
	while(1){
		random_shuffle(all(a));
		array<int,4> tt={-inf,-inf,inf,inf};
		int cnt=0;
		for(int i=0;i<n;i++){
			auto nt=check(tt,a[i]);
			if(nt[0]==inf){
				cnt++;
				continue;
			}
			tt=nt;
		}
		if(cnt<=1){
			cout<<tt[0]<<" "<<tt[1]<<endl;
			return;
		}
	}
	
	
	
	
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
