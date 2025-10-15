#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/226/B

//     贪心转化 k 则正叉树 + 前缀
//思路：

//日期：  2024-4-8
//格式化： ctrl+shift+ a


const int MAX=1e5+10;
typedef long long ll;

int n,q;
ll nums[MAX];
ll sum[MAX];
ll ans[MAX];
int k[MAX];
ll special=0;

void ff() {   //特判 x==1 的情况 
	for(int i=n-1,h=1; i>=1; i--,h++) {
		special+=nums[i]*h;
	}
}

ll f(ll x) {
    if(x==1) return special;
    
	ll res=0;
	ll cnt=x;
	int h=1;
	for(ll i=n-1; i>0;) {
		ll r=i;
		ll l=max(1LL,r-cnt+1);
		res+=(sum[r]-sum[l-1])*h;

		i-=cnt;
		cnt*=x;
		h++;     //树深度 +1
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>nums[i];
	}
	cin>>q;
	for(int i=0; i<q; i++) {
		cin>>k[i];
	}

	sort(nums+1,nums+n+1);
	sum[0]=0;
	for(int i=1; i<=n; i++) {
		sum[i]=sum[i-1]+nums[i];
	}
	ff();   
	for(int i=0; i<q; i++) {
		ans[i]=f(k[i]);
	}
    
	for(int i=0; i<q; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}
/*


*/

