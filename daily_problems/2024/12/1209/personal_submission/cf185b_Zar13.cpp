#include<bits/stdc++.h>
using namespace std;
int main(){
	int s, a, b, c;
	cin>>s>>a>>b>>c;
	if(a|| b|| c){
		int sum=a+b+c;
		cout<<fixed<<setprecision(20)<<1.0*s*a/sum<<" "<<1.0*s*b/sum<<" "<<1.0*s*c/sum;
	}else{
		cout<<1<<" "<<0<<" "<<0;
	}
	return 0;
}
