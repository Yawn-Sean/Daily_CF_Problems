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
const int N = 1e5 + 10;
bool cmp(int a,int b){
	return a>b;
}
signed main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		vector<int>a[N];
		for(int i=1;i<=n;i++){
			int x,y;cin>>x>>y;
			a[x].push_back(y);
		}
		vector<int>ans(n,0);
		for(int i=1;i<=m;i++){
			sort(a[i].begin(),a[i].end(),cmp);
			int sum=0;
			for(int j=0;j<a[i].size();j++){
				sum+=a[i][j];
				if(sum>0)ans[j]+=sum;
			}
		}
		int ans1=0;
		for(int i=0;i<ans.size();i++)ans1=max(ans1,ans[i]);
		cout<<ans1<<'\n';
	}
	return 0;
}
