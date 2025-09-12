#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/317/A

//                                           
//                                            

//       2025-4-19-(暴力模拟)-cf317a 
//思路：

//日期：   2025-4-19 
//格式化： ctrl+shift+ a

typedef long long ll;
ll a,b,m;

void solve(){
	if(a>=m || b>=m ){
		cout<<"0"<<endl;
		return ;
	}
	if(a<=0 && b<=0){
		cout<<"-1"<<endl;
		return ;
	}
	
	ll ans=0;
	if(a<=0){
		ans=(-a+b-1)/b;
		a+=ans*b;
	}
	if(b<=0){
		ans=(-b+a-1)/a;
		b+=ans*a;
	}
	while(max(a,b)<m){
		if(a<b) swap(a,b);   // a>=b
		ans++;
		b=a+b;
	}
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>a>>b>>m;
	solve();

	return 0;
}
/*


*/

