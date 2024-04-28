#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long 
#define endl '\n'
string s;
stack<int>num,op;
void solve()
{
	cin>>s;
	int pos;
	while((pos=s.find("()"))!=string::npos)
	{
		s.replace(pos,2,"0");
	}
	while((pos=s.find("->"))!=string::npos)
	{
		s.replace(pos,2,",");
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') num.push(0);
		else if(s[i]==',') op.push(1);
		else if(s[i]=='(') op.push(0);
		else
		{
			while(op.top())
			{
				int x=num.top();num.pop();
				int y=num.top();num.pop();
				op.pop();
				num.push(max(x,y+1));
			}
			op.pop();
		} 
	}
	while(op.size())
	{
		int x=num.top();num.pop();
		int y=num.top();num.pop();
		op.pop();
		num.push(max(x,y+1));
	}
	cout<<num.top();
}
signed main()
{
	int T=1;
	while(T--) solve();
	return 0;
}
