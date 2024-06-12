//链接：https://codeforces.com/problemset/problem/1153/C
//格式化：ctrl+shift+a

#include<bits/stdc++.h>
using namespace std;

const int MAX=3e5+10;
char s[MAX];

int n;

void f() {
	if(n%2==1) {
		cout<<":("<<endl;
		return ;
	}
	int l=n/2;
	for(int i=0; i<n; i++) {
		if(s[i]=='(') l--;
	}
	if(l<0) {
		cout<<":("<<endl;
		return ;
	}
	int sum=0;
	for(int i=0; i<n; i++) {
		if(s[i]=='?') {
			if(l>0) {
				s[i]='(';
				l--;
			} else
				s[i]=')';
		}
		sum+=(s[i]=='('?1:-1);
		if((i!=n-1 && sum==0) || sum<0) {            //**********************
			cout<<":("<<endl;
			return ;
		}
	}

	for(int i=0; i<n; i++) {
		cout<<s[i];
	}
	cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>s[i];
	}
	f();

	return 0;
}
