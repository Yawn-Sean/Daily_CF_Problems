#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/913/C

//   dp+贪心  price[i]=min(price[i],2*price[i-1])
//   可以得到购买 2^k  件商品的最优解

//日期： 2024-3-21 
//格式化： ctrl+shift+ a

const int MAX=100;
typedef long long ll;
const ll inf=LLONG_MAX/10;

int n;
ll m;
ll price[MAX];
int bit[MAX];

void build(){
	for(int i=0;i<MAX;i++){
		price[i]=inf;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n>>m;
    build();
    
    for(int i=0;i<n;i++){
    	cin>>price[i];
	}
	
	int id=0;
	while(m){
		bit[id++]=(m&1);
		m>>=1;
	}
	
	for(int i=1;i<max(n,id);i++){
		price[i]=min(price[i],2*price[i-1]);
	}
	
	ll ans=0;
	for(int i=0;i<max(n,id);i++){
		if(price[i]<ans) ans=price[i];  //购买的数量可以 >=m 
		if(bit[i]==1) ans+=price[i];
	}
	
	cout<<ans<<endl;
 
	return 0;
}
/*


*/

