#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<local/dbg.h>
#else
#define dbg(...) 42
#endif

using LL=long long;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);ai(26);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

#define OMDA {cout<<"Omda\n";return;}
#define TEEMO {cout<<"Teemo\n";return;}
void solve(){
	int n,k;
	cin>>n>>k;
	if(k&1){
		if(n&1) OMDA;  // all odd, first win
		TEEMO;
	}
	else{
		const int r=1ll*n*k%(k+1);
		if(r&1 || r==k) OMDA;
		TEEMO;
	}
}
int main(){
#ifdef ONLINE_JUDGE
	freopen("dotak.in","r",stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
