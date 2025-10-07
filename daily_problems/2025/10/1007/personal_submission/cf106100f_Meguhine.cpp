#include<bits/stdc++.h>
using namespace std;

#define isd(c) ((c)>='0' && (c)<='9')
#define iss(c) std::isspace(c)
struct IO{
	static constexpr int sz=1<<17;
	char buf[sz],*p1,*p2,pbuf[sz],*pp;
	FILE *in,*out;
	int prec; std::chars_format fmt;
	IO(FILE *i=stdin,FILE *o=stdout):
	p1(buf),p2(buf),pp(pbuf),
	in(i),out(o),prec(6),fmt(std::chars_format::fixed){}
	~IO(){fwrite(pbuf,1,pp-pbuf,out);}
	char gc(){
#ifdef LOCAL
		return getchar();
#else
		if(p1==p2) p2=(p1=buf)+fread(buf,1,sz,in);
		return p1==p2?' ':*p1++;
#endif
	}
	// Char/String Input
	IO& operator >>(char& c){
		for(c=gc();iss(c);c=gc());
		return *this;
	}
	IO& operator >>(char* s){
		char c=gc(); for(;iss(c);c=gc());
		for(;!iss(c);c=gc()) *s++=c; *s=0;
		return *this;
	}
	IO& operator >>(string& s){
		s.clear();
		char c=gc(); for(;iss(c);c=gc());
		for(;!iss(c);c=gc()) s.push_back(c);
		return *this;
	}
	// Signed Integer Input
#define SGNI {bool neg=0;x=0;char c=gc();\
	for(;!isd(c);c=gc()){if(c=='-') neg=1;}\
	if(neg){for(;isd(c);c=gc()) x=x*10+('0'-c);}\
	else{for(;isd(c);c=gc()) x=x*10+(c-'0');}\
	return *this;}
	IO& operator >>(short& x) SGNI
	IO& operator >>(int& x) SGNI
	IO& operator >>(long long& x) SGNI
	// Unsigned Integer input
#define USGNI {x=0;char c=gc();\
	for(;!isd(c);c=gc());\
	for(;isd(c);c=gc()) x=x*10+(c-'0');\
	return *this;}
	IO& operator >>(unsigned short& x) USGNI
	IO& operator >>(unsigned int& x) USGNI
	IO& operator >>(unsigned long long& x) USGNI
	// Float Input
#define FLTI(FUNC) {static char sta[64];\
	char* t=sta; char c=gc(); for(;iss(c);c=gc());\
	if(c=='+' || c=='-'){*t++=c;c=gc();}\
	for(;isd(c);c=gc()) *t++=c;\
	if(c=='.'){*t++=c; c=gc();\
	for(;isd(c);c=gc()) *t++=c;}\
	if(c=='e' || c=='E'){*t++=c; c=gc();\
	if(c=='+' || c=='-'){*t++=c;c=gc();}\
	for(;isd(c);c=gc()) *t++=c;}\
	*t=0; x=std::FUNC(sta,nullptr);\
	return *this;}
	IO& operator >>(float& x) FLTI(strtof);
	IO& operator >>(double& x) FLTI(strtod);
	IO& operator >>(long double& x) FLTI(strtold);
	void flush(){
#ifndef LOCAL
		fwrite(pbuf,1,pp-pbuf,out); pp=pbuf;
#endif
		fflush(out);
	}
	void pc(const char &c){
#ifdef LOCAL
		putchar(c);
#else
		if(pp-pbuf==sz) fwrite(pbuf,1,sz,out),pp=pbuf;
		*pp++=c;
#endif
	}
	// Char/String Output
	IO& operator <<(const char& c){
		pc(c);
		return *this;
	}
	IO& operator <<(const char* s){
		while(*s) pc(*s++);
		return *this;
	}
	IO& operator <<(const string& s){
		for(const auto& c:s) pc(c);
		return *this;
	}
	// Signed Integer Output
#define SGNO {bool neg=0;\
	if(x<0){neg=1;pc('-');}\
	static int sta[64]; int top=0;\
	do{sta[top++]=x%10;x/=10;}while(x);\
	if(neg){while(top)pc('0'-sta[--top]);}\
	else{while(top)pc('0'+sta[--top]);}\
	return *this;}
	IO& operator <<(short x) SGNO
	IO& operator <<(int x) SGNO
	IO& operator <<(long long x) SGNO
	// Unsigned Integer Output
#define USGNO {static int sta[64];int top=0;\
	do{sta[top++]=x%10;x/=10;}while(x);\
	while(top)pc('0'+sta[--top]);\
	return *this;}
	IO& operator <<(unsigned short x) USGNO
	IO& operator <<(unsigned int x) USGNO
	IO& operator <<(unsigned long long x) USGNO
	// Float Output
	void setp(int p){prec=p;}
	void setf(std::chars_format f){fmt=f;}
#define FLTO {static char sta[64];\
	auto [ed,_]=std::to_chars(sta,sta+64,x,fmt,prec);\
	for(char *c=sta;c!=ed;++c) pc(*c); return *this;}
	IO& operator <<(float x) FLTO
	IO& operator <<(double x) FLTO
	IO& operator <<(long double x) FLTO
	// __int128_t, __uint128_t
#ifdef __GNUC__
	IO& operator >>(__int128_t& x) SGNI
	IO& operator >>(__uint128_t& x) USGNI
	IO& operator <<(__int128_t x) SGNO
	IO& operator <<(__uint128_t x) USGNO
#endif
};
#undef isd
#undef iss

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

template<typename T>//T is int or LL
class Fenwick{
private:
	int n;
	vector<T>c;
	inline int lowbit(const int& x){
		return x&(-x);
	}
public:
	Fenwick(){}
	Fenwick(int n_){
		init(n_);
	}
	void init(int n_){
		c.assign(n=n_,T(0));
	}
	void add(int i,T x){
		for(;i<n;i+=lowbit(i)) c[i]+=x;
	}
	T query(int i){
		T res=0;
		for(;i;i-=lowbit(i)) res+=c[i];
		return res;
	}
};

IO io;
#define FAIL {io<<"-1";exit(0);}
int main(){
	int n; io>>n;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;++i){
		io>>a[i];
		a[i]-=i;
	}
	map<int,vector<int>>mp;
	for(int i=1;i<=n;++i){
		io>>b[i];
		b[i]-=i;
		mp[b[i]].push_back(i);
	}
	Fenwick<int>fen(n+1);
	LL ans=0;
	for(int i=n;i>0;--i){
		auto it=mp.find(a[i]);
		if(it==mp.end()) FAIL;
		auto& v=it->second;
		if(v.empty()) FAIL;
		a[i]=v.back();
		v.pop_back();
		ans+=fen.query(a[i]);
		fen.add(a[i],1);
	}
	io<<ans;
	return 0;
}
