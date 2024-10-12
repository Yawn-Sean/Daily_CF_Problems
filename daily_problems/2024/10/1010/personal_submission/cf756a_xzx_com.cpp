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
const int N = 2e5 + 10;
int p[N],b[N];
int find(int x){
	if(x!=p[x]){
		p[x]=find(p[x]);
	} 
	return p[x];
}
bool st[N];
signed main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)p[i]=i;
		for(int i=1;i<=n;i++){
			int x;cin>>x;
			int a=find(i),b=find(x);
			if(a!=b){p[a]=b;}
		}
		int z=0,k=0;
		for(int i=1;i<=n;i++){
			cin>>b[i];
			if(b[i]==1)z++;
		}
		if(z%2==0)k++;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!st[find(i)])ans++,st[find(i)]=1;
		}
		if(ans==1)ans=0;
		cout<<ans+k<<'\n';
	}
	return 0;
}
