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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,T;
	cin>>n>>T;
	string s,t;
	cin>>s;
	char last=s[0]; int cc=0;
	for(int i=0;i<n;){
		const char& c=s[i];
		if(c==last){
			++cc,++i;
			continue;
		}
		else{
			bool ok=0;
			if(last=='R' && c=='S') ok=1;
			else if(last=='S' && c=='P') ok=1;
			else if(last=='P' && c=='R') ok=1;
			dbg(i,last,c,ok);
			if(ok){
				pair<char,int>pre={last,cc},nw={c,0};
				int j=i;
				for(;j<n && s[i]==s[j];++j);
				nw.second=j-i;
				int sub=min(pre.second,T);
				if(pre.second!=sub) t.append(pre.second-sub,pre.first);
				t.append(nw.second,nw.first);
				i=j,last=pre.first,cc=sub;
			}
			else{
				t.append(cc,last);
				last=s[i++];
				cc=1;
			}
		}
	}
	if(cc) t.append(cc,last);
	cout<<t;
	return 0;
}
