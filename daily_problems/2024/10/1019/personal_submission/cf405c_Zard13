#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q, t, res=0, op, x;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>t;
			if(i==j){
				a[i]=t;
				res+=t;
			}
		}
	}
	cin>>q;
	while(q--){
		cin>>op;
		if(op==3) cout<<res%2;
		else{
			cin>>x;
			res-=a[x];
			a[x]=(a[x]+1)%2;
			res+=a[x];
		}
	}
	return 0;
}
