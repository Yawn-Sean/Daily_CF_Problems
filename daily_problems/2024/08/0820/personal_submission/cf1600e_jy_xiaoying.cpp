//链接：https://codeforces.com/problemset/problem/1600/E
//  2024-8-21   ctrl+shift+A

#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5+10;
int g[MAX];
int n;

void f(){
	int l=0;
	while(l<n-1 && g[l]<g[l+1]) l++;
	int r=n-1;
	while(r>0 && g[r]<g[r-1]) r--;
	
	l+=1;
	r=n-r;
	if(l%2==0 && r%2==0){
		cout<<"Bob"<<endl;
	}
	else{
		cout<<"Alice"<<endl;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	f();
	
	return 0;
} 
