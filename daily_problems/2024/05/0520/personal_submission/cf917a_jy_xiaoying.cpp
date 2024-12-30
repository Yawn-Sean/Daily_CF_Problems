//链接：https://codeforces.com/problemset/problem/917/A

#include<bits/stdc++.h>
using namespace std;

string s;
int n;


 
void f(){
	n=s.size();
	int ans=0;
	for(int l=0;l<n;l++){
		int cnt=0;               //遇到？ 先当成 '('  cnt++; 
		int sum=0;               //若是sum < 0 时，再把一个？ 当成')'    (cnt--)   
		
		for(int r=l;r<n;r++){
			if(s[r]=='(')  sum+=1;
			else if(s[r]==')') sum-=1;
			else{
				sum-=1;
				cnt++;
			}
			while(sum<0 && cnt>0){
				cnt--;
				sum+=2;
			}
			if(sum<0) break;                        //已经为负数：说明 当前即 后续不可能合法 
			if(sum==0 ) ans++;
		}
	}
	cout<<ans<<"\n";
}


int main(){
	cin>>s;
	f();
	
	return 0;
} 
