#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s,a;cin>>s;
	int n=s.size();
	s=s+' ';
	stack<int>stk1;
	stack<char>stk2;
	for(int i=0;i<n;i++){
		if(s[i]=='('&&s[i+1]==')')
			a+='0',i++;
		else if(s[i]=='-'&&s[i+1]=='>')
			a+='+',i++;
		else
			a+=s[i];
	}
	a='('+a+')';
	cout<<a<<"\n";
	int m=a.size();
	for(int i=0;i<m;i++){
		if(a[i]=='0')
			stk1.push(0);
		else if(a[i]=='+'||a[i]=='(')
			stk2.push(a[i]);
		else if(a[i]==')'){
			while(stk2.size()&&stk2.top()!='('){
				int x=0,y=0;
				if(stk1.size()){
					x=stk1.top();stk1.pop();
				}
				if(stk1.size()){
					y=stk1.top();stk1.pop();
				}
				stk1.push(max(x,y+1));//y为前面的数
				stk2.pop();
			}
			if(stk2.size())
				stk2.pop();
		}
	}
	cout<<stk1.top();
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}
