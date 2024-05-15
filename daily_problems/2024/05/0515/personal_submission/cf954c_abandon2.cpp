#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int m=-1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==0){
			cout<<"NO\n";return;
		}
		if(abs(a[i]-a[i-1])>1){
			m=abs(a[i]-a[i-1]);
		}
	}
	if(m==-1)
		m=1e9;
	for(int i=2;i<=n;i++){
		int y1=(a[i-1]-1)%m+1,x1=(a[i-1]-1)/m+1;
		int y2=(a[i]-1)%m+1,x2=(a[i]-1)/m+1;
		//cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
		if(abs(x1-x2)+abs(y1-y2)>1){
			cout<<"NO\n";return;
		}
	}
	cout<<"YES\n";
	cout<<(int)1e9<<" "<<m<<"\n";

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
