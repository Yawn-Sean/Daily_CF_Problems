#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/923/A
//格式化： ctrl+shift+ a

int x;
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>x;
	vector<int> g(x+10);
	iota(g.begin(),g.end(),0);
	
	auto prime_num=[&]()->void{        //埃氏筛 
	    for(int i=2;i<x+10;i++){
	    	if(g[i]!=i) continue;
	    	for(int j=i;j<x+10;j+=i){
	    		g[j]=i;
			}
		}
	};
	
	prime_num();
	int ans=INT_MAX;
	for(int i=x-g[x]+1;i<=x;i++){
		if(g[i]==i) continue;   //是质数
		ans=min(ans,i-g[i]+1); 
	}
	
	cout<<ans<<endl;
	
	return 0;
}
