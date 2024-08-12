//链接：https://codeforces.com/problemset/problem/1672/D

#include<bits/stdc++.h>
using namespace std;

int t;
int n;
const int MAX=2e5+10;
int a[MAX];
int b[MAX];
bool ans[MAX];

bool f() {
	vector<int> nums(n+10,0);
	int ops=0;
	for(int i=0; i<n; i++) {
		int tmp=a[i];
		if(tmp==b[ops]) {
			ops++;
		} else {
			nums[tmp]++;
		}
		
		while(ops<n && ops>0 && b[ops-1]==b[ops] && nums[b[ops]]) {
			nums[b[ops]]--;
			ops++;
		}
	}

	return ops==n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>t;
	for(int j=0; j<t; j++) {
		cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<n; i++) cin>>b[i];

		ans[j]=f();
	}

	for(int j=0; j<t; j++) {
		if(ans[j]) cout<<"YES"<<endl;
		else  cout<<"NO"<<endl;
	}
	return 0;
}

/*
5
5
1 2 3 3 2
1 3 3 2 2
5
1 2 4 2 1
4 2 2 1 1
5
2 4 5 5 2
2 2 4 5 5
3
1 2 3
1 2 3
3
1 1 2
2 1 1



*/
