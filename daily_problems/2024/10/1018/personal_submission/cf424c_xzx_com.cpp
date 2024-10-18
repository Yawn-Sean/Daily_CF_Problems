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
const int N =2e6+ 10;
int a[N],s[N];
signed main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n;cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i],ans^=a[i];
		for(int i=0;i<n;i++){
			s[i]=s[i-1]^i;
		}
		for(int i=1;i<=n;i++){
			if(n%i==0){
				if(n/i%2!=0)ans^=s[i-1];
			}else {
				if(n/i%2==0)ans^=s[n%i];
				else ans^=s[n%i]^s[i-1];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
