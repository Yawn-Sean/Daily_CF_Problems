#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
char DEBUG_BUFFER[1000];
#define debug(...) {sprintf(DEBUG_BUFFER,##__VA_ARGS__);\
cerr<<"\033[1;36m"<<DEBUG_BUFFER<<"\033[0;2m"<<"\033[0m";\
fflush(stderr);}
#define s S.c_str()
char TEST_GEN[1000],TEST_ANS[1000],TEST_OUT[1000],TEST_FC[1000];
void TEST(string S){
	sprintf(TEST_GEN,"%s_gen.exe > %s_input.txt",s,s);
	sprintf(TEST_ANS,"%s_sol.exe < %s_input.txt > %s_ans.txt",s,s,s);
	sprintf(TEST_OUT,"%s.exe < %s_input.txt > %s_out.txt",s,s,s);
	sprintf(TEST_FC,"fc %s_ans.txt %s_out.txt /n",s,s);
	while(1){
		debug("gen\n"); system(TEST_GEN);
		debug("ans\n"); system(TEST_ANS);
		debug("out\n"); system(TEST_OUT);
		if(system(TEST_FC)) break;
	}
}
#undef s
#else
#define debug(...) ;
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
int rand(int l,int r){return rng()%(r-l+1)+l;}

#define FAIL {cout<<"NO\n";return;}
void solve(){
	int n; string s;
	cin>>n>>s;
	vector<int>odd(n),even(n);
	for(int i=0;i<n;++i){
		odd[i]=i*2+1;
		even[i]=(i+1)*2;
	}
	vector<ai2>a(n+1);
	for(int i=n;i>0;--i){
		if(s[i-1]=='O'){ // odd
			if(odd.empty() || even.empty()) FAIL;
			a[i]={odd.back(),even.back()};
			odd.pop_back();
			even.pop_back();
		}
		else{
			if(even.empty() || odd.back()>even.back()){
				if(odd.size()<2) FAIL;
				a[i][0]=odd.back();
				odd.pop_back();
				a[i][1]=odd.back();
				odd.pop_back();
			}
			else{
				if(even.size()<2) FAIL;
				a[i][0]=even.back();
				even.pop_back();
				a[i][1]=even.back();
				even.pop_back();
			}
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;++i){
		cout<<a[i][0]<<' '<<a[i][1]<<'\n';
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
