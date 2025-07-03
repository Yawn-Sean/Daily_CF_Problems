#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/491/B

//   数学 
//   曼哈顿距离 

//日期： 2024-3-21 
//格式化： ctrl+shift+ a

const int MAX=100;
typedef long long ll;
const ll inf=LLONG_MIN/10;

ll n,m;
ll c,h;

ll x,y,a,b; // 酒店(x,y)   餐馆(a,b)

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll mx1=inf,mx2=inf,mx3=inf,mx4=inf;
    
    cin>>n>>m;
    cin>>c;
    for(ll i=0;i<c;i++){
    	cin>>x>>y;
    	mx1=max(mx1,y-x);
    	mx2=max(mx2,y+x);
    	mx3=max(mx3,-y-x);
    	mx4=max(mx4,-y+x);
	}
	
	ll mi=-inf; int id;
	cin>>h;
	for(ll i=0;i<h;i++){
		cin>>a>>b;
		ll tmp1=-b+a+mx1;
		ll tmp2=-b-a+mx2;
		ll tmp3=b+a+mx3;
		ll tmp4=b-a+mx4;
		if(max({tmp1,tmp2,tmp3,tmp4})<mi){
			mi=max({tmp1,tmp2,tmp3,tmp4});
			id=i+1;
		}
	}
	
	cout<<mi<<endl<<id;
 
	return 0;
}
/*


*/

