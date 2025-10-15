#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/490//D

//
//

//       2025-4-22-(质因数分解+数学)-cf490d
//思路：

//日期：   2025-4-22
//格式化： ctrl+shift+ a

typedef long long ll;
ll x,y;
ll a,b;

int f2(ll nums) {
	int ans=0;
	while(nums%2==0) {
		nums/=2;
		ans++;
	}
	return ans;
}

int f3(ll nums) {
	int ans=0;
	while(nums%3==0) {
		nums/=3;
		ans++;
	}
	return ans;
}

void solve() {
	int ans=0;
	int cnt=f3(x)+f3(y)-f3(a)-f3(b);
	ans+=abs(cnt);
	
	while(cnt>0) {                        //第一个矩形 3的质因子多
		if(x%3==0)
			x=x/3*2;
		else
			y=y/3*2;
		cnt--;
	}
	while(cnt<0) {                         //第二个矩形 3的质因子多
		if(a%3==0)
			a=a/3*2;
		else
			b=b/3*2;
		cnt++;
	}
	
	 cnt=f2(x)+f2(y)-f2(a)-f2(b);
	 ans+=abs(cnt);
	 
	while(cnt>0) {                        //第一个矩形 2的质因子多
		if(x%2==0)
			x/=2;
		else
			y/=2;
		cnt--;
	}
	while(cnt<0) {                         //第二个矩形 2的质因子多
		if(a%2==0)
			a/=2;
		else
			b/=2;
		cnt++;
	}
	
	if(a*b==x*y){
		cout<<ans<<endl;
		cout<<x<<" "<<y<<endl;
		cout<<a<<" "<<b<<endl;
		return ;
	}
	cout<<"-1"<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>x>>y;
	cin>>a>>b;

	solve();

	return 0;
}
/*


*/

