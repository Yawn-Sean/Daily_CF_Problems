#include <bits/stdc++.h>
#define fi first
#define se second
#define lll __int128
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
typedef long double ld;
void read(ll &x)
{
	x=0;char ch=getchar();int sign=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') sign=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=sign;
}
void write(ll x)
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
const int N = 2e5 + 10;
ld b[N];
signed main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			ld x,y;cin>>x>>y;
			b[i]=atan2l(y,x);
		}
		sort(b+1,b+n+1);
		ld pi=atan2l(0,-1),ans=0;
		for(int i=2;i<=n;i++){
			ans=max(b[i]-b[i-1],ans);
		}
		printf("%.10Lf\n",min(2*pi-ans,b[n]-b[1])/pi*180);
	}
	return 0;
}
