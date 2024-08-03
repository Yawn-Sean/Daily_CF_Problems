#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],b[N];
int n,m;

int check(int x){
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=1;i<=n;i++){
		if(b[i]<b[i-1]){
			if(b[i-1]-b[i]>x)return 0;
			b[i]=b[i-1];
		}
		else if(b[i]>b[i-1]){
			if(b[i-1]+m-b[i]<=x)
				b[i]=b[i-1];
		}
	}
	return 1;
}



void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	int l=-1,r=m+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid;
		//cout<<l<<" "<<r<<"\n";
	}
	cout<<r<<"\n";
}


signed main(){
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
