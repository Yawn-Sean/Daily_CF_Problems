// Problem: D. Robot Vacuum Cleaner
// Contest: Codeforces - Codeforces Round 461 (Div. 2)
// URL: https://codeforces.com/problemset/problem/922/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define int long long
struct node{
	int x,y,z;
	friend bool operator<(node a,node b){
		return b.x*a.y<a.x*b.y;
	}
}a[N];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		string c;cin>>c;
		int x=0,y=0,sum=0;
		for(int j=0;j<(int)c.size();j++){
			if(c[j]=='s')
				x++;
			else{
				y++;
				sum+=x;
			}
			a[i]={x,y,sum};
		}
	}
	sort(a+1,a+1+n);
	// for(int i=1;i<=n;i++){
		// cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
	// }
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].z;
	}
	int s=a[n].y;
	for(int i=n-1;i>=1;i--){
		sum+=a[i].x*s;
		s+=a[i].y;
	}
	cout<<sum<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}

