#include <bits/stdc++.h>
#define int unsigned long long
#define fi first
#define se second
#define ld long double
#define l28 __int128
#define PII pair<int,int>
using namespace std;
const int N=3e6+10,inf=1e18,mod=1e9+7;
void read(l28 &x)
{
	x=0;char ch=getchar();int sign=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') sign=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=sign;
}
void write(l28 x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	write(x/10);
	putchar(x%10+48);
}
int qim(int a,int k,int p){
	int res=1;
	while(k){
		if(k&1)res=res*a%p;
		k>>=1;
		a=a*a%p;
	}
	return res;
}
bool cmp(PII a,PII b){
	return a.fi>b.fi;
}
int s[N];
PII a[N];
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
    	int n;cin>>n;
    	int ans=0;
    	for(int i=1;i<=n;i++){
    		cin>>a[i].fi>>a[i].se;
    		if(a[i].fi>a[i].se)swap(a[i].fi,a[i].se);
			ans=max(ans,a[i].fi*a[i].se); 
		}
		sort(a+1,a+n+1,cmp);
		int ma=0;
		for (int i=1;i<=n;i++) {
	        ans=max(ans,2ll*a[i].fi*min(a[i].se,ma));
	        ma=max(ma, a[i].se);
    	}
    	cout<<ans/2<<'.'<<ans%2*5;
    }
    return 0;
}
