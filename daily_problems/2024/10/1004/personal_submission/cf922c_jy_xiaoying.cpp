#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,k;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	for(ll i=1LL;i<=k;i++){
		if(n%i!=i-1){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;

	return 0;
}
