#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
const int mod=1E9+7;
ll MOD(ll x)
{
	return (x%mod+mod)%mod;
}
void solve()
{
	 int x;
	 string s;
	 cin>>x>>s;
	 ll cur=s.size();
	 vector<int>c(x);
	 for(int i=0;i<min<int>(x,s.size());i++)
	 {
	 	c[i]=s[i]-'0';
	 }
	 int pos=min<int>(s.size(),x);
	 
	 for(int i=0;i<x;i++)
	 {
	 	int t=cur;
	 	cur=MOD((i+1)+(cur-(i+1))*c[i]);
	 	int cnt=0;
	 	int npos=i+1;
	 	//复制c[i]-1个长度cur-(i+1)的字符串
	 	while(pos<x&&cnt<c[i]-1)
	 	{
	 		c[pos]=c[npos];
	 		pos++,npos++;
	 		if(npos==t)
	 		{
	 			npos=i+1;
	 			cnt++;
	 		}
	 	}
	 }
	 cout<<cur<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
