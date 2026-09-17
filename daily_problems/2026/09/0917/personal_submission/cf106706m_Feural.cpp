#include<bits/stdc++.h>
#define endl '\n'
#define rep(a,b,c) for(int a=b;a<c;a++)
#define per(a,b,c) for(int a=b;a>c;a--)
#define pb push_back
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef int i32;
typedef unsigned int u32;
typedef long long i64;
typedef unsigned long long u64;
typedef __int128 i128;
typedef unsigned __int128 u128;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef queue<int> qi;
typedef unordered_map<int,int> umapii;

int T=1,n,m,q,M,N;

void solve(){
    // cout<<endl;debug(T);
	cin>>n;
	vll a(n),pre(n+1,0ll);
	rep(i,0,n)cin>>a[i];

	rep(i,1,n+1)pre[i]=pre[i-1]+a[i-1];
	// vdebug(pre);

	ll mx=pre[n]-(n+1);
	rep(i,0,n){
		mx=max(mx,pre[i]-a[i]);
		mx=max(mx,pre[n]-pre[i+1]-a[i]);
	}
	cout<<mx<<endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T;
    // cin.ignore();
    while(T--){
        solve();
    }
    // solve();
}
