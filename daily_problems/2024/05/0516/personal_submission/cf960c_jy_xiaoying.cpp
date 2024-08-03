//链接：https://codeforces.com/problemset/problem/960/C

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> g;               //开LL 

ll x,d;

void f(){
	ll cur=1;
	for(int i=50;i>=1;i--){
		ll tmp=(1LL<<i)-1;
		while(x>=tmp){
			x-=tmp;
			for(int j=0;j<i;j++)  g.push_back(cur);
			
			cur+=(d+1);                        //至少+d 
		}
	}
	
	int len=g.size();
	cout<<len<<"\n";
	for(ll i:g){                      //开LL
		cout<<i<<" ";
	}
	cout<<"\n";
}

int main(){
	
	cin>>x>>d;
	g.clear();
	
	f();
	return 0;
} 
