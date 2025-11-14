#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
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
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

int dx[]={0,2,4},dy[]={0,1,3,4};
void solve(){
	int n; cin>>n;
	++n;
	int m=n%6;
	if(m==1) m=7;
	const int b=(n-m)/6;
	const int nn=b*6;
	--n;
	vector s(n,string(n,'.'));
	for(int i=0;i<b;++i){
		const int x=i*6;
		for(int j=0;j<b;++j){
			const int y=j*6;
			for(auto& xx:dx) for(auto& yy:dy){
				s[x+xx][y+yy]='#';
			}
		}
	}
	if(m==2){
		for(int i=0;i<b;++i){
			const int j=i*6;
			for(auto& yy:dy){
				s[nn][j+yy]=s[j+yy][nn]='#';
			}
		}
	}
	else if(m==3){
		for(int i=0;i<b;++i){
			const int j=i*6;
			for(auto& xx:dx){
				s[nn][j+xx]=s[nn+1][j+xx]='#';
				s[j+xx][nn]=s[j+xx][nn+1]='#';
			}
		}
		s[nn][nn]=s[nn][nn+1]='#';
	}
	else if(m==4){
		for(int i=0;i<b;++i){
			const int j=i*6;
			for(auto& yy:dy){
				s[nn][j+yy]=s[j+yy][nn]='#';
				s[nn+2][j+yy]=s[j+yy][nn+2]='#';
			}
		}
		s[nn][nn]=s[nn][nn+1]='#';
		s[nn+2][nn]=s[nn+2][nn+1]='#';
	}
	else if(m==5){
		for(int i=0;i<b;++i){
			const int j=i*6;
			for(auto& xx:dx){
				s[nn][j+xx]=s[nn+1][j+xx]='#';
				s[j+xx][nn]=s[j+xx][nn+1]='#';
			}
			for(auto& yy:dy){
				s[nn+3][j+yy]=s[j+yy][nn+3]='#';
			}
		}
		s[nn][nn]=s[nn][nn+1]='#';
		s[nn+2][nn]=s[nn+3][nn]='#';
		s[nn][nn+3]=s[nn+1][nn+3]='#';
		s[nn+3][nn+2]=s[nn+3][nn+3]='#';
	}
	else if(m==7){
		for(int i=0;i<b;++i){
			const int j=i*6;
			for(auto& xx:dx){
				s[nn][j+xx]=s[nn+1][j+xx]='#';
				s[j+xx][nn]=s[j+xx][nn+1]='#';
			}
			for(auto& yy:dy){
				s[nn+3][j+yy]=s[j+yy][nn+3]='#';
				s[nn+5][j+yy]=s[j+yy][nn+5]='#';
			}
		}
		s[nn][nn]=s[nn][nn+1]=s[nn+2][nn]=s[nn+2][nn+1]='#';
		s[nn][nn+3]=s[nn+1][nn+3]=s[nn][nn+5]=s[nn+1][nn+5]='#';
		s[nn+4][nn]=s[nn+5][nn]=s[nn+4][nn+2]=s[nn+5][nn+2]='#';
		s[n-1][n-1]=s[n-1][n-2]=s[n-3][n-1]=s[n-3][n-2]='#';
	}
	for(auto& t:s) cout<<t<<'\n';
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
