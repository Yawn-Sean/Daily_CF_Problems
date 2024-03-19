// Problem: F. Vasilije Loves Number Theory
// Contest: Codeforces - Codeforces Round 900 (Div. 3)
// URL: https://codeforces.com/contest/1878/problem/F
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

//--------------------------------
template<typename T> void printvt(vector<T> &a){
	for(auto x:a) cout<<x<<" ";cout<<endl;
};
template<typename T> void printay(T a[],int l,int r){
	for(int i=l;i<=r;i++) cout<<a[i]<<" ";cout<<endl;
};
//--------------------------------

typedef pair<int,int> PII;
typedef long long LL;
const int N=100010;

int n,q;

map<int,int> get(int x){
	map<int,int> res;
	for(int i=2;i<=x/i;i++){
		if(x%i==0){
			int cnt=0;
			while(x%i==0) cnt++,x/=i;
			res[i]=cnt;
		}
	}
	if(x>1) res[x]=1;
	return res;
}

void solve(){
	cin>>n>>q;
	
	map<int,int> a=get(n);
	map<int,int> b=a;
	
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int x;
			cin>>x;
			map<int,int> c=get(x);
			for(auto [l,r]:c) b[l]+=r;
			
			LL k=1;
			for(auto [l,r]:b){
				k*=r+1;
			}
			c=get(k);
			bool flag=1;
			for(auto [l,r]:c){
				if(!b.count(l) or b[l]<r) flag=0;
			}
			cout<<(flag ? "YES" : "NO")<<endl;
			
		}else b=a;
	}
	cout<<endl;
}

signed main(){
    fastio;
    
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
