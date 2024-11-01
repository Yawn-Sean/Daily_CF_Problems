#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l28 __int128
#define PII pair<int,int>
using namespace std;
const int N=5e5+10,inf=1e18,mod=1e9+7;
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
int a[N],ans;
void check(int l,int r){
	ans=max((r-l-1)/2,ans);
	for(int i=l;i<(l+r)/2;i++){
		a[i]=a[l];
	}
	for(int i=(l+r)/2;i<r;i++){
		a[i]=a[r-1];
	}
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int l=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				check(l,i);
				l=i;
			}
		}
		check(l,n+1);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++){
			cout<<a[i]<<' ';
		}
    }
    return 0;
}
