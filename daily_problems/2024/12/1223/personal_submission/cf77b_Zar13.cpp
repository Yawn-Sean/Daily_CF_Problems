#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		double a, b;
		cin>>a>>b;
		if(b==0) cout<<"1\n";
		else if(a==0) cout<<"0.5\n";
		else if(a/4<b){
			cout<<fixed<<setprecision(10)<<0.5+0.5*0.5*(a/4/b)<<"\n";
		}else{
			cout<<fixed<<setprecision(10)<<0.5+0.5*(0.5*1*(b*4)/a+(a-b*4)/a)<<"\n";
		}
	}
	return 0;
}
