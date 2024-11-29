#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l28 __int128
#define PII pair<int,int>
using namespace std;
const int N=2e5+10,inf=1e18,mod=24;
l28 a[N];
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
l28 gcd(l28 a,l28 b){
	return b?gcd(b,a%b):a;
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--){
    	l28 p,q;read(p),read(q);
    	int n;cin>>n;
    	for(int i=1;i<=n;i++)read(a[i]);
    	l28 x=0,y=0;
    	for(int i=n;i>=1;i--){
    		if(i==n)x=1,y=a[n];
    		else {
    			l28 z=x;
    			x=y;
    			y=a[i]*y+z;
	   			z=gcd(x,y);
    			x=x/z;
    			y=y/z;
			}
		}
		l28 z=gcd(p,q);
    	p=p/z;
    	q=q/z;
		if(q==x&&p==y)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
    }
    return 0;
}
