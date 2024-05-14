// Problem: D. Concatenated Multiples
// Contest: Codeforces - Codeforces Round 506 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1029/D
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

const int N=100010;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res*=a;
		a*=a;
		b/=2;
	}
	return res;
}

void solve(){
	int n,k;
	cin>>n>>k;
	unordered_map<int,int,custom_hash> q[11];
	
	auto get=[&](int x){
		int res=1,cnt=10;
		while(cnt<=x) cnt*=10,res++;
		return res;
	};
	int res=0;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int i=1,j=x;i<=10;i++){
			j*=10;j%=k;
			q[i][j]++;
		}
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		int t=get(x);
		int m=(k-x%k+k)%k;
		res+=q[t][m];
		if((x%k*qmi(10,t)%k+x%k)%k==0) res--;
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
