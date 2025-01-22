#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l28 __int128
#define PII pair<int,int>
using namespace std;
const int N=1e5+10,inf=1e18,mod=1e9+7;
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
int a[N],b[N],c[N],f[N][2];
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
    	int n;cin>>n;
    	for(int i=1;i<=n;i++)cin>>a[i];
    	for(int i=1;i<=n;i++)cin>>b[i];
    	for(int i=1;i<=n;i++)cin>>c[i];
    	//c[1]=0;
    	f[1][0]=-1e18;
    	for(int i=2;i<=n+1;i++){
    		f[i][0]=max(f[i-1][0]+b[i-1],f[i-1][1]+a[i-1]);
    		f[i][1]=max(f[i-1][0]+c[i-1],f[i-1][1]+b[i-1]);
		}
		cout<<f[n+1][0]<<'\n';
    }
    return 0;
}
