#include<bits/stdc++.h> 
using namespace std;

//链接：https://codeforces.com/problemset/problem/1512/G
//日期：  2024-2-29
//格式化： ctrl+shift+ a

typedef long long ll;

int kk;
int x;
const int MAX=1e7+10;
int ans[MAX];
int f[MAX];
int divs[MAX];  // 最小质因子 


void fff(){
	for(int i=0;i<MAX;i++){
		ans[i]=-1;
		divs[i]=i;
	}
	
	ans[1]=1;
	f[1]=1;
	
	for(ll i=2;i<MAX;i++){
		if(divs[i]!=i) continue;
		for(ll j=i*i;j<MAX;j+=i){
			divs[j]=i;
		}
	}
	
	for(ll i=2;i<MAX;i++){
		ll x=0,v=1;
		while(i%v==0){
			x+=v;
			v*=divs[i];
		}
		v/=divs[i];
		f[i]=f[i/v]*x;
	}
	
	for(int i=2;i<MAX;i++){
		int tmp=f[i];
		if(tmp>=MAX) continue;
		if(ans[tmp]==-1) ans[tmp]=i;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>kk;
    
    fff();
    while(kk--){
    	cin>>x;
    	cout<<ans[x]<<endl;
	}

	return 0;
}

