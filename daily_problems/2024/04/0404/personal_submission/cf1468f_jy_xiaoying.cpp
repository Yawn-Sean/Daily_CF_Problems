#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1468/F

//     哈希表 + 向量gcd表示 
//     在角速度方向、大小相同条件下，只有一开始的向量方向相反才能在 某时刻相遇 

//日期： 2024-4-4 
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long long ll;
typedef unsigned long long ull;

const ull base1=1e9+7;
const ull base2=2333;

ll ans[MAX];
int t;
int n;

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

ll f(){
	cin>>n;
	ll res=0;
	unordered_map<ull,ll> mp;
	ll x1,y1,x2,y2;
	for(int i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2;
		
		ll x=x2-x1;
		ll y=y2-y1;
		ll gcd_x_y=gcd(abs(x),abs(y));
		x/=gcd_x_y;
		y/=gcd_x_y;
		
		ull tmp1=base1*(ull)(-x)+base2*(ull)(-y);
		ull tmp2=base1*(ull)(x)+base2*(ull)(y);
		res+=mp[tmp1];
		mp[tmp2]+=1;
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>t;
    for(int i=0;i<t;i++){
    	ans[i]=f();
	}
	
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}
/*


*/

