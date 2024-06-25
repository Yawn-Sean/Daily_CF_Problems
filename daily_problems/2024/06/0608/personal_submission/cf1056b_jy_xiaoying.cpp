//链接：https://codeforces.com/problemset/problem/1056/B

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;

int main(){
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if((i*i+j*j)%m==0)
			    ans+=(ll)((n-i+m)/m)*((n-j+m)/m);
		}
	}
	cout<<ans<<"\n";
	return 0;
} 

/*
6 5

13

*/
