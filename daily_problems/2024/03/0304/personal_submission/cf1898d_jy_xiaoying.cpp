#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1898/D
//日期： 2024-3-4
//格式化： ctrl+shift+ a

typedef long long ll;
int tt,n;
const int MAX=2e5+10;

int a[MAX];
int b[MAX];
ll ans[MAX];

ll ff(){
	ll min_right=INT_MAX;   //线段的最小右端点 
	ll max_left=INT_MIN;    //线段的最大左端点
	ll res=0;
	
	for(int i=0;i<n;i++){
		ll mi=min(a[i],b[i]);  //线段左端点
		ll ma=max(a[i],b[i]);  //线段右端点
		res+=(ma-mi);
		min_right=min(min_right,ma);
		max_left=max(max_left,mi);
	}
	res+=max(0LL,2*(max_left-min_right));
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>tt;
	for(int i=0;i<tt;i++){
		cin>>n;
		for(int j=0;j<n;j++) cin>>a[j];
		for(int j=0;j<n;j++) cin>>b[j];
		ans[i]=ff();
	}
	
	for(int i=0;i<tt;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}


