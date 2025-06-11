#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long a,b;
	cin>>a>>b;
	long long k=round(pow(a*b,1.0/3));
	if(k*k*k==a*b&&a%k==0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}