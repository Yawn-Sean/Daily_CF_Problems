//链接：https://codeforces.com/problemset/problem/712/C 

#include<bits/stdc++.h>
using namespace std;

int x,y;
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>x>>y;
    
    int a=y,b=y;
    int ans=0;
    while(a<x){
    	b+=a-1;
    	swap(a,b);
    	ans++;
	}
	
	cout<<ans+2<<endl;
	
	return 0;
}
