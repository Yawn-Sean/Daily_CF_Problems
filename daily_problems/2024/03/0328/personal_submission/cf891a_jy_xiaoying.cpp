#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/891/A

//   暴力枚举 + 区间gcd
//

//日期： 2024-3-28
//格式化： ctrl+shift+ a

const int MAX=2e3+10;
const int limits=19;
typedef long long ll;

int n;
ll nums[MAX];
int ones=0;

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}
void f() {

	if(ones!=0) {
		cout<<n-ones<<endl;
		return ;
	}

	int ans=2*n;
	for(int i=0; i<n; i++) {
		ll tmp=nums[i];
		for(int j=i+1; j<n; j++) {
			tmp=gcd(tmp,nums[j]);

			if(tmp==1)
				ans=min(ans,j-i);
		}
	}

	if(ans==2*n) cout<<"-1"<<endl;
	else
		cout<<ans+n-1<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>nums[i];
		if(nums[i]==1) ones+=1;
	}

	f();

	return 0;
}
/*


*/

