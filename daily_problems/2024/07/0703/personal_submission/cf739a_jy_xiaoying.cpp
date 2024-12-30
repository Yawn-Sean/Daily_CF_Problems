//链接：https://codeforces.com/problemset/problem/739/A  

#include<bits/stdc++.h>
using namespace std;

int n,m;
const int MAX=1e5+10;
int lim;
int ans[MAX];

void f() {
	int base=0;
	cout<<lim<<endl;
	for(int i=0; i<n; i++,base++) {
		cout<<base%lim<<" ";
	}
	cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	lim=INT_MAX;
	int l,r;
	for(int i=0; i<m; i++) {
		cin>>l>>r;
		lim=min(lim,r-l+1);
	}

	f();
	return 0;
}

/*
5 3
1 3
2 5
4 5


*/
