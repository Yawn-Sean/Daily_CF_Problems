//链接：https://codeforces.com/problemset/problem/962/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,int> pp;
const int MAX=160000;
ll g[MAX];
int n;



struct comp{
	bool operator()(const pp &a,const pp &b){
		return a.first>b.first || (a.first==b.first && a.second>b.second);
	}
};

void f(){
    
	priority_queue<pp,vector<pp>,comp> q;
	vector<pp> ans(0);
	for(int i=1;i<=n;i++){
		q.push(pp(g[i],i));
	}
	
	while(q.size()>1){
		pp t1=q.top();  q.pop();
		pp t2=q.top();  q.pop();
		
		if(t1.first==t2.first){
			q.push(pp(t1.first*2,t2.second));
		}
		else{
			ans.push_back(pp(t1.first,t1.second));
			q.push(t2);
		}
	}
	
	if(!q.empty()){
		ans.push_back(q.top());
	}
	
	sort(ans.begin(),ans.end(),[&](const pp &a,const pp &b){
		return a.second<b.second;
	});
	
	cout<<ans.size()<<"\n";
	for(auto &t:ans){
		cout<<t.first<<" ";
	}
	cout<<"\n";
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	
	f();
	return 0;
} 

/* 
100
10 10 15 12 15 13 15 12 10 10 15 11 13 14 13 14 
10 13 12 10 14 12 13 11 14 15 12 11 11 15 12 12 11 
14 14 14 15 10 10 15 15 13 13 15 10 12 14 10 12 13 11 
15 11 13 14 12 10 12 11 14 13 15 13 15 13 14 14 11 12 13 
11 14 10 10 15 10 15 12 15 12 13 10 11 13 15 11 10 12 10 
12 14 14 13 12 14 10 12 13 11 13

88 240 15 44 160 192 208 224 20 24 11 26
*/
