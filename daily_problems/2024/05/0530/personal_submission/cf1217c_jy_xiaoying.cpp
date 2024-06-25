//链接：https://codeforces.com/problemset/problem/1217/C

#include<bits/stdc++.h>
using namespace std;

int k;
string s;
const int MAX=2e5+10;
int pre[MAX];

void f(){
	int n=s.size();
	pre[0]=0;
	for(int i=1;i<n;i++){
		if(s[i-1]=='1') pre[i]=0;
		else      pre[i]=pre[i-1]+1;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') continue;
		int j=i+1;
		int cur=1;
		ans++;
		while(j<n && cur<=n){
			cur=cur*2 + (s[j]=='1'?1:0);
			j++;
			if(pre[i]>=cur-(j-i)) 
				ans++;
			
		}
	}
	cout<<ans<<"\n";
}

int main(){
	cin>>k;
	while(k--){
		cin>>s;
		f();
	}
	
	return 0;
} 

//别inqueue了
