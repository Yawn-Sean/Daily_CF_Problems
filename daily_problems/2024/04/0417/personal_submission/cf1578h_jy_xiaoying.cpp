//链接：https://codeforces.com/problemset/problem/1578/H

#include<bits/stdc++.h>
using namespace std;

string s;
int n;
int ans;

int f(int &k){
	stack<int> num;
	stack<int> ops;
	while(k>=0){
		if(s[k]==')'){
			k-=1;
			num.push(f(k));
		}
		else if(s[k]=='>'){
			if(!ops.empty()){
				int tmp=num.top()+ops.top();
				num.pop(), ops.pop();
				ans=max({ans,tmp,num.top()});
				num.top()=max(tmp,num.top());
			} 
			ops.push(1);
			k-=2;
		}
		else{  //s[k]=='('
			k--;
			break;
		}
	}
	while(!ops.empty()){
		int x=ops.top()+num.top();
		ops.pop();
		num.pop();
		ans=max({ans,x,num.top()});
		num.top()=max(x,num.top());;
	}
	if(num.empty()) return 0;
	return num.top();
}

int main(){
	cin>>s;
	n=s.size();
	
	int k=n-1;
	ans=INT_MIN;
	int tmp=f(k);
	ans=max(ans,tmp);
	cout<<ans<<"\n";
	return 0;
} 
