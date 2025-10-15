#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	return b==0? a:gcd(b, a%b);
}
int f(int a, int b){
	if(b==0) return -1;
	int res=0;
	res=a/b+f(b, a%b);
	return res;
}
int main(){
	int n;
	cin>>n;
	int ans=n-1;
	for(int i=1;i<n;i++){
		if(gcd(n,i)==1){
			ans=min(ans, f(n, i));
		}
	}
	cout<<ans;
	return 0;
}
