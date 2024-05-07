// Problem: C. A Mist of Florescence
// Contest: Codeforces - Codeforces Round 487 (Div. 2)
// URL: https://codeforces.com/problemset/problem/989/C
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

const int N=100010;

void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	vector<vector<char>> A(25,vector<char>(25,'A'));
	vector<vector<char>> B(25,vector<char>(25,'B'));
	vector<vector<char>> C(25,vector<char>(25,'C'));
	vector<vector<char>> D(25,vector<char>(25,'D'));
	
	auto insert=[&](vector<vector<char>> &g,char c,int x){
		for(int i=0;i<25 and x;i+=2){
			for(int j=1;j<25 and x;j+=2){
				if(x){
					g[i][j]=c;
					x--;
				}
			}
		}
	};
	
	insert(A,'D',d-1);
	insert(D,'A',a-1);
	insert(B,'C',c-1);
	insert(C,'B',b-1);
	
	cout<<50<<" "<<50<<endl;
	for(int i=0;i<25;i++){
		for(auto j=0;j<25;j++){
			A[i].pb(B[i][j]);
		}
		for(auto x:A[i]) cout<<x;
		cout<<endl;
	}
	for(int i=0;i<25;i++){
		for(auto j=0;j<25;j++){
			C[i].pb(D[i][j]);
		}
		for(auto x:C[i]) cout<<x;
		cout<<endl;
	}
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
