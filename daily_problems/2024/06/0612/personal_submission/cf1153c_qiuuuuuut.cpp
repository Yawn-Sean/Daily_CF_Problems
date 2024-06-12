#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10,mod=1e9+7;
#define endl '\n'
#define int long long 
typedef pair<int,int> PII;
int n;
string s;
void solve()
{
	cin>>n>>s;
	int cnt=0,l=n/2;
	for(auto &c:s) l-=c=='(';
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') cnt++;
		else if(s[i]==')') cnt--;
		else
		{
			if(l)
			{
				l--;cnt++;s[i]='(';
			}
			else
			{
				cnt--;s[i]=')';
			}
		}
		if(cnt<=0&&i!=n-1) 
		{
			cout<<":(";return;
		 } 
	}
	if(cnt==0) cout<<s;
	else cout<<":(";
	
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
 } 
