//链接：https://codeforces.com/problemset/problem/1009/C

#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

int n,m;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll ans=0;
	cin>>n>>m;
	
	
	ll p1=(ll)(n)*(n-1)/2LL;
	ll p2=0;
	int l=0,r=n-1;
	int mid=n/2;
	while(l<r){
		p2+=abs(l-mid);
		p2+=abs(r-mid);
		l++,r--;
	}
	
	int x,d;
	for(int i=0;i<m;i++){
		cin>>x>>d;
		ans+=n*x;
		ans+=(d>=0?p1*d:p2*d);
	}
	
	cout<<setprecision(20) << (ld)(ans)/n<<endl;
	return 0;
} 
