//链接：https://codeforces.com/problemset/problem/533/E

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
ll dp[MAX][2];
char s[MAX];
char t[MAX];
int n;


void f(){
      int l=n+1,r=0;               //找第一个不同 和 最后一个不同的位置 
      for(int i=1;i<=n;i++){
      	if(s[i]!=t[i]){
      		l=min(l,i);
      		r=max(r,i);
		  }
	  }
	  
	  int a=1,b=1;
	  for(int i=l;i<r;i++){
	  	  if(s[i]!=t[i+1]) a=0;
	  	  if(s[i+1]!=t[i]) b=0;
	  }
	  cout<<a+b<<"\n";
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>t[i];
	
	f();
	return 0;
} 
