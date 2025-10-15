#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/439/D

//       思维 + 排序 
//思路：

//日期： 2024-4-10
//格式化： ctrl+shift+ a


const int MAX=1e5+10;
typedef long long ll;
int n,m;
ll a[MAX];
ll b[MAX];

ll small;  //数组 a 中的最小值
ll big;    //数组 b 中的最大值

void solve() {
	if(small>=big) {
		cout<<"0"<<endl;
		return ;
	}

	sort(a,a+n);
	sort(b,b+m,[&](const int &x1,const int &x2){
		return x1>x2;
	});
	
	ll ans=0;
	for(int i=0;i<min(n,m);i++){
		ans+=max(0LL,b[i]-a[i]);
	}
	cout<<ans<<endl;
}

void init() {
	small=INT_MAX;
	big=INT_MIN;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		small=min(small,a[i]);
	}
	for(int i=0; i<m; i++) {
		cin>>b[i];
		big=max(big,b[i]);
	}

	solve();

	return 0;
}
/*




*/

