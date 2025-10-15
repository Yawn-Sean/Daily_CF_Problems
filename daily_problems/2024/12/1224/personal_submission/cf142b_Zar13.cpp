#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
    cin>>n>>m;
	if(m>n) swap(n, m);
	if(m==1) cout<<n;
	else if(m==2) cout<<2*(n/4*2+min(n%4, 2));
	else cout<<(n*m+1)/2;
	return 0;
} 
