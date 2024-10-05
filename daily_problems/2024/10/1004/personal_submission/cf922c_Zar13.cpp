#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n, k;
	cin>>n>>k;
	for(LL i=1;i<=k;i++){
		if(n%i!=i-1){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
