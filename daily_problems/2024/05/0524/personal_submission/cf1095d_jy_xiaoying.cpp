//链接：https://codeforces.com/problemset/problem/1095/D

#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5+10;
int g[MAX][2];
int ans[MAX];
int n;

bool check(int a,int b){                 // a 是否在 b前面 
	return g[a][0]==b || g[a][1]==b;
}

void f(){
    ans[1]=1;
    int a=g[1][0],b=g[1][1];
    if(check(a,b)){
    	ans[2]=a;   ans[3]=b;
	}
	else{
		ans[2]=b ;  ans[3]=a;
	}
	
	for(int i=2;i<=n-2;i++){
		int u=ans[i];
		int a=g[u][0],b=g[u][1];
		ans[i+2]= ans[i+1]==a? b: a;
	}	
	
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i][0]>>g[i][1];
		if(g[i][0]<g[i][1]) swap(g[i][0],g[i][1]);
	}
	
	f();
	return 0;
} 
