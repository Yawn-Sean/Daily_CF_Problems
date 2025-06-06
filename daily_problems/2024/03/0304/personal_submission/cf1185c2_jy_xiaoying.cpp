#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1185/C2
//日期： 2024-3-4
//格式化： ctrl+shift+ a

int n,m;
const int MAX=2e5+10;
int nums[MAX];
int cnts[110];
int ans[MAX];

int ff(int x) { // >=x
	int res=0;
	for(int i=100; i>=1; i--) {
		if(cnts[i]==0) continue;
		if(x-cnts[i]*i>=0) {
			res+=cnts[i];
			x-=cnts[i]*i;
		} else {
			res+=(x+i-1)/i;
			return res;
		}
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=0; i<n; i++) cin>>nums[i];

	int sum=0;
	for(int i=0; i<n; i++) {
		if(sum+nums[i]<=m) ans[i]=0;
		else ans[i]=ff(sum-m+nums[i]);

		sum+=nums[i];
		cnts[nums[i]]++;
	}
	for(int i=0; i<n; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}


