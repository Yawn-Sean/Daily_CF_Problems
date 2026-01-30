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

bool cmp(const string_view& s,const string_view& t){
	char from='A',to='B',mid='C';
	for(int i=int(s.size())-1;~i;--i){
		const char c=s[i],d=t[i];
		if(c!=d){
			return c==to?1:0;
		}
		else{
			if(c==from){
				swap(to,mid);
			}
			else{
				swap(from,mid);
			}
		}
	}
	return 0;
}

void solve(){
	int n,m;
	cin>>n>>m;
	string ans(n,'A'); int i=1;
	for(int j=1;j<=m;++j){
		string s;
		cin>>s;
		if(cmp(s,ans)){
			swap(ans,s);
			i=j;
		}
	}
	cout<<i<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	solve();
	return 0;
}
