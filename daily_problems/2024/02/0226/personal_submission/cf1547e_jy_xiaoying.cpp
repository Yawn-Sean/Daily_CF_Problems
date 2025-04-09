#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1547/E
//日期：2024-2-26 
//格式化： ctrl+shift+ a

const int inf=INT_MAX/2;
const int MAX=3e5+10;
int kk;

int pos[MAX];
int val[MAX];
int len,n;

int pre[MAX];
int suf[MAX];

void f(){
	for(int i=0;i<=len+1;i++) pre[i]=suf[i]=inf;
	
	for(int i=1;i<=n;i++){
		int id=pos[i];
		int temp=val[i];
		pre[id]=temp-id;
		suf[id]=temp+id;
	}
	for(int i=1;i<=len;i++) pre[i]=min(pre[i-1],pre[i]);
	for(int i=len;i>=1;i--) suf[i]=min(suf[i],suf[i+1]);
	
	for(int i=1;i<=len;i++){
		cout<<min(pre[i]+i,suf[i]-i)<<" ";
	}
	cout<<endl;
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>kk;
	
	for(int k=0;k<kk;k++){
		cin.ignore();
		cin>>len>>n;
		for(int i=1;i<=n;i++){
			cin>>pos[i];
		}
		for(int i=1;i<=n;i++){
			cin>>val[i];
		}
		
		f();
	} 
	
	return 0;
} 
