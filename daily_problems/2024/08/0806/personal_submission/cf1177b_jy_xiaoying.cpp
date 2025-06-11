//链接：https://codeforces.com/problemset/problem/1177/B  
//  2024-8-6

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll k;

int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

     cin>>k;
     //几位数  n位数开始的第一个数  n位数的数量 
    ll base=1,start=1,cnt=9;
    k--;
    
    while(k>=cnt*base){
    	k-=(cnt*base);
    	base+=1;
    	start*=10;
    	cnt*=10;
	}
	
	int a=k/base,b=k%base;
	string ans=to_string(start+a);
	
	cout<<ans[b]<<endl;
	return 0;
} 
