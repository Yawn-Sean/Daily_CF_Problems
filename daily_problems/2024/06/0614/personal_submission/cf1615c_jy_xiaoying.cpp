//链接：https://codeforces.com/problemset/problem/1615/C

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e4+10;
int ans[MAX];

int k;
int n;
string s;
string t;

bool is_0(string &str) {          //是否为全0
	for(char ss:str) {
		if(ss=='1') return 0;
	}
	return 1;
}

int get_1(string &str) {               //统计1的个数
	int cnt=0;
	for(char ss:str) {
		if(ss=='1') cnt++;
	}
	return cnt;
}

int f() {
	if(s==t) return 0;
	if(is_0(s) || is_0(t)) return -1;
	int res=INT_MAX;
	int a=get_1(s);
	int b=get_1(t);
	if(a==b) {
		int cnt=0;
		for(int i=0; i<n; i++) {
			if(s[i]!=t[i]) cnt++;
		}
		res=min(res,cnt);
	}
	if(n-a+1==b) {
		int cnt=0;
		bool flg=0;    //s和t中是否有位置都为 1
		for(int i=0; i<n; i++) {
			if(s[i]==t[i]) cnt++;
			if(s[i]=='1' && t[i]=='1') flg=1;
		}
		if(flg) res=min(res,cnt);
	}

	return res==INT_MAX?-1:res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>k;
	for(int i=0; i<k; i++) {
		cin>>n;
		cin>>s>>t;
		ans[i]=f();
	}

	for(int i=0; i<k; i++) {
		cout<<ans[i]<<"\n";
	}

	return 0;
}
