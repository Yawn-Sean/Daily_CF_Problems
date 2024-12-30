//链接：https://codeforces.com/problemset/problem/1025/C

#include<bits/stdc++.h>
using namespace std;

string s;

void f(){
	int n=s.size();
	int ans=1;
	char t=s[0];
	int cnt=1;
	for(int i=1;i<n;i++){
		if(t!=s[i]){
			cnt++;
		}
		else{
			cnt=1;
		}
		t=s[i];
		ans=min(n/2,max(ans,cnt));   //最长不超过 n/2 
	}
	
	cout<<ans<<"\n";
}

int main(){
	
	string t;
	cin>>t;
	s=t+t;
	
	f();
	return 0;
} 
