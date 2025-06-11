//链接：https://codeforces.com/problemset/problem/464/A
//  2024-8-15

#include<bits/stdc++.h>
using namespace std;

int n,p;
string s;

bool check(string &s ,char t,int j){  //判断j位置是否合法，且不能==t 
	if(j<0 || s[j]==t) return 0; 
	return 1;
}

void f(){
	int id=-1;
	char tmp;
	for(int i=0;i<n;i++){
		
		for(int j=1;j<26;j++){
			if(s[i]+j>='a'+p) {
				break;
			}
			
			char t=s[i]+j;
			if((i==0) || (i==1 && check(s,t,i-1)) || (check(s,t,i-1) && check(s,t,i-2)) ){
				id=i;
				tmp=t;
				break;
			}
		}
		
	}
	
	if(id<0){
		cout<<"NO"<<endl;
		return ;
	}
	
	string ans="";
	for(int i=0;i<id;i++){
		ans+=s[i];
	}
	ans+=tmp;
	
	for(int i=id+1;i<n;i++){
		for(char t='a';t<='z';t++){
			if((i-2>=0 && check(ans,t,i-1) && check(ans,t,i-2)) || (i-1==0 && check(ans,t,i-1) )){
				ans+=t;
				break;
			}
		}
	}
	
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>p;
	cin>>s;
	
	f();
	return 0;
} 
