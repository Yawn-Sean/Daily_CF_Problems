 #include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1260/C
//日期：2024-2-28
//格式化： ctrl+shift+ a


typedef long long ll;
ll r,b,k;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

void f(){
	if(r==b){
		cout<<"OBEY"<<endl;
		return ;
	}
	
	if(r>b) swap(r,b);
	
	ll tmp=gcd(r,b);
	r/=tmp;
	b/=tmp;
	
	if(r*(k-1)+1>=b){
		cout<<"OBEY"<<endl;
	}
	else{
		cout<<"REBEL"<<endl;
	}
	
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int kk;
	cin>>kk;
	while(kk--) {
		cin>>r>>b>>k;
		f(); 
	}

	return 0;
}
