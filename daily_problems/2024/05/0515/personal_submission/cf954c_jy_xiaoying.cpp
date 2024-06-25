//链接：https://codeforces.com/problemset/problem/954/C

#include<bits/stdc++.h>
using namespace std;

int n;
int big;

const int MAX=2e5+10;
int g[MAX];

void f(){
	int diff=1;
	big=g[0];
	for(int i=1;i<n;i++){
		big=max(big,g[i]);
		int t=abs(g[i]-g[i-1]);
		if(t==1 || t==diff) continue;
		
		if(t==0){                           //==0 直接错 
			cout<<"NO"<<"\n";
			return ;
		}
		diff=t;
	}
	int nn=(big+diff-1)/diff;
	int mm=diff;
	for(int i=1;i<n;i++){
		int x1=(g[i-1]-1)/mm;
		int y1=(g[i-1]-1)%mm;
		
		int x2=(g[i]-1)/mm;
		int y2=(g[i]-1)%mm;
		
		if(abs(x1-x2)+abs(y1-y2)>1){
			cout<<"NO"<<"\n";
			return ;
		}
	}
	
	cout<<"YES"<<"\n";
	cout<< nn<<" "<< mm<<"\n";
}

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	
	if(n==1){
		cout<<"YES"<<"\n";
		cout<<1<<" "<<g[0]<<"\n";
		return 0;
	}
	f();
	return 0;
} 
