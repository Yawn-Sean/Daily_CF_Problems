#include <bits/stdc++.h>
#define fi first
#define se second
#define lll __int128
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
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
const int N = 5e5 + 10;
int a[N],b[N],c[N],s1[N],s2[N];
signed main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n,sum=0;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			if(i==1)b[i]=a[i],s1[i]=0;
			else {
				if(a[i]<=b[i-1])b[i]=b[i-1]+1,s1[i]=s1[i-1]+(b[i]-a[i]);
				else b[i]=a[i],s1[i]=s1[i-1];
			}
		}
		for(int i=n;i>=1;i--){
			if(i==n)c[i]=a[i],s2[i]=0;
			else {
				if(a[i]<=c[i+1])c[i]=c[i+1]+1,s2[i]=s2[i+1]+(c[i]-a[i]);
				else c[i]=a[i],s2[i]=s2[i+1];
			}
		}
		int ans=1e18;
		for(int i=1;i<=n;i++){
			int z=0;
			if(a[i]<max(b[i-1],c[i+1])+1)z=max(b[i-1],c[i+1])+1-a[i];
			ans=min(ans,s1[i-1]+s2[i+1]+z);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
