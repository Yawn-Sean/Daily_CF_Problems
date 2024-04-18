//链接：https://codeforces.com/problemset/problem/1310/A

#include<bits/stdc++.h>
using namespace std;

int n;
typedef vector<int> vv;
typedef long long ll;

const int MAX=2e5+10;
vector<vv> g=vector<vv>(MAX,vv(2));

void f(){
	sort(g.begin(),g.begin()+n,[&](const vv &a,const vv &b){
		return a[0]<b[0];
	});
	
	int i=0;
	ll ans=0;
	ll sum=0;
	int pre=g[0][0];
	priority_queue<int> q;
	for(;i<n;i++){
		int j=i;
		while(j<n && g[j][0]==pre){
			q.push(g[j][1]);
			sum+=g[j][1];
			j++;
		}
		sum-=q.top();
		q.pop();
		ans+=sum;
		if(q.empty()) pre=g[j][0];
		else pre++;
		i=j-1;
	}
	while(!q.empty()){
		sum-=q.top();
		q.pop();
		ans+=sum;
	}
	cout<<ans<<"\n";
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>g[i][0];
	}
	for(int i=0;i<n;i++){
		cin>>g[i][1];
	}
	
	f();
	return 0;
} 
