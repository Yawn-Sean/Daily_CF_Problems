//链接：https://codeforces.com/problemset/problem/231/C

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX=1e5+10;
int n,k;
ll g[MAX];

void f(){
	int cnt=0,ans=0;
	ll sum=0;
	int l=0,r=0;
	for(;r<n;r++){
		sum+=g[r];
		while(l<=r && (ll)(r-l+1)*g[r]-sum>k){
			sum-=g[l++];
		}
		if(r-l+1>cnt){
			cnt=r-l+1;
			ans=g[r];
		}
	}
	
	cout<<cnt<<" "<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	
	sort(g,g+n);
	f();
	return 0;
} 

/*
5 3
6 3 4 0 2

3 4

*/
