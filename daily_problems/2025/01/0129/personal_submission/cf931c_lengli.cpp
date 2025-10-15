#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ms(a,b) memset(a,b,sizeof(a))
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+10;
const int mod=1e9+7;
const int maxm=1e3+10;
using namespace std;
int a[maxn];
int num[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	int minn=inf;
	int maxx=-inf;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		minn=min(a[i],minn);
		maxx=max(maxx,a[i]);
	}
	if(maxx-minn<=1)
	{
		cout<<n<<endl;
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
			a[i]-=minn,num[a[i]]++;
		int res=min(num[0],num[2]);
		int res1=num[1]/2;
		if(res>res1)
		{
			num[1]+=res*2;
			num[0]-=res;
			num[2]-=res;
		}
		else
		{
			res=res1;
			num[1]-=res*2;
			num[0]+=res;
			num[2]+=res;
		}
		cout<<n-res*2<<endl;
		for(int i=0;i<3;i++)
			for(int j=0;j<num[i];j++)
				cout<<minn+i<<" ";
		cout<<endl;
	}
	return 0;
}
