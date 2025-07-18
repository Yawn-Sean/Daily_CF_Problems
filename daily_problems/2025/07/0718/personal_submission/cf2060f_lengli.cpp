#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
template <const unsigned long long mod,const unsigned long long tmp=(-mod)/mod+1> struct Modint{
	int val;
	Modint(){ val=0; }
	int barrett(long long sum){ return ((sum-=(((unsigned __int128)sum*tmp)>>64)*mod)>=mod?sum-mod:sum); }
	template <typename type> Modint(const type &num){ val=barrett(num); }
	friend bool operator == (const Modint &lhs,const Modint &rhs){ return (lhs.val==rhs.val); }
	friend bool operator != (const Modint &lhs,const Modint &rhs){ return (lhs.val!=rhs.val); }
	Modint& operator += (const Modint &rhs){ if((val+=rhs.val-mod)<0) val+=mod; return (*this); }
	Modint& operator -= (const Modint &rhs){ if((val-=rhs.val)<0) val+=mod; return (*this); }
	Modint& operator *= (const Modint &rhs){ val=barrett((long long)val*rhs.val); return (*this); }
	Modint& operator /= (const Modint &rhs){
		int a=0,b=1,x=rhs.val,y=mod,t; for(;x;t=y/x,swap(x,y-=t*x),swap(a-=t*b,b)); return ((*this)*=a);
	}
	template <typename type> Modint& operator ^= (const type &rhs){
		type a=rhs; Modint res=1,b=(*this); for(;a;a/=2,b*=b) res=(a&1?res*=b:res); return ((*this)=res);
	}
	friend Modint operator + (const Modint &lhs,const Modint &rhs){ return (Modint(lhs)+=rhs); }
	friend Modint operator - (const Modint &lhs,const Modint &rhs){ return (Modint(lhs)-=rhs); }
	friend Modint operator * (const Modint &lhs,const Modint &rhs){ return (Modint(lhs)*=rhs); }
	friend Modint operator / (const Modint &lhs,const Modint &rhs){ return (Modint(lhs)/=rhs); }
	template <typename type> friend Modint operator ^ (const Modint &bas,const type &exp){ return (Modint(bas)^=exp); }
	Modint operator + () const { return Modint(+val); } Modint operator - () const { return Modint(-val); }
	Modint& operator ++ (){ return (*this)+=1; } Modint operator ++ (int){ Modint res(*this); (*this)+=1; return res; }
	Modint& operator -- (){ return (*this)-=1; } Modint operator -- (int){ Modint res(*this); (*this)-=1; return res; }
};
const int L=20,V=100000;
int T,n,k;
Modint<998244353> ans,f[L+5][V+5];
Modint<998244353> comb(int sum1,int sum2){
	Modint<998244353> res=1;
	for(int i=sum1-sum2+1;i<=sum1;i++) res*=i;
	for(int i=1;i<=sum2;i++) res/=i;
	return res;
}
void work(){
	scanf("%d%d",&k,&n);
	for(int v=1;v<=k;v++){
		ans=0;
		for(int l=1;l<=n&&l<=L;l++)
			ans+=f[l][v]*comb(n+1,l+1);
		printf("%d ",(v==1?n:ans));
	}
	printf("\n");
}
int main(){
	f[0][1]=1;
	for(int l=0;l<=L;l++)
		for(int v=1;v<=V;v++)
			if(f[l][v]!=0)
				for(int nv=2;v*nv<=V;nv++)
					f[l+1][v*nv]+=f[l][v];
	for(scanf("%d",&T);T;T--) work();
}
