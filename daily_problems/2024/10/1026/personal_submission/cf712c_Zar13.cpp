#include<bits/stdc++.h>
using namespace std;
int main(){
	int x, y, res=0;
	cin>>x>>y;
	int a=y, b=y;//a次大 b最大 
	while(b!=x){
		a+=b-1;
		a=min(a, x);
		swap(a, b);
		res++;
	}
	cout<<res+2;
}
