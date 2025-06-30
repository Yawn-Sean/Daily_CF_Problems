#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/773/A

//  数学 - 倍数  
//   

//日期： 2024-3-19 
//格式化： ctrl+shift+ a

const int MAX=1e3+10;
typedef long long ll;
int n;
ll x,y,p,q; 
ll ans[MAX];

ll f(){
	if(p==0){
		return x==0?0:-1;
	}
	if(q==p){
		return x==y?0:-1;
	}
	
	ll t1=(x+p-1)/p;
	ll t2=(y-x+q-p-1)/(q-p);
	return max(t1,t2)*q-y;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x>>y>>p>>q;
    	ans[i]=f();
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}
 
	return 0;
}
/*


*/

