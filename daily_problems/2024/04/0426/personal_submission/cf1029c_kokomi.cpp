#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int l[N],r[N];
//前/后缀最小/大思想！
int a1[N],a2[N],b1[N],b2[N];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
	}
	a1[0]=b1[n]=0;
	a2[0]=b2[n]=1e9;
	for(int i=0;i<n;i++){
		a1[i+1]=max(l[i],a1[i]);
		a2[i+1]=min(r[i],a2[i]);
	}
	for(int i=n-1;i>=0;i--){
		b1[i]=max(l[i],b1[i+1]);
		b2[i]=min(r[i],b2[i+1]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,min(a2[i],b2[i+1])-max(a1[i],b1[i+1]));
	}
	cout<<ans;
	
		
}
int main(){
	int t;
//	cin>>t;
	t=1;
	while(t--){
		solve();
	}

}