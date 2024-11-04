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
const int N = 2e5 + 10,mod=1e9+7;
signed main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int x;string s;
		cin>>x>>s;
		vector<int>tmp(x);
		int ans=s.size(),p=min(ans,x);
		for(int i=0;i<p;i++)tmp[i]=s[i]-'0';
		for(int i=0;i<x;i++){
			if(tmp[i]==0)break;
			ans=(ans+(ans-i-1)*(tmp[i]-1)%mod+mod)%mod;
			int j=1,l=i+1,e=p;
			while(j<tmp[i]&&p<x){
				tmp[p]=tmp[l];
				p++,l++;
				if(l==e){
					j++,l=i+1;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
