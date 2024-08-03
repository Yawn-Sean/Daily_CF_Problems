#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e5+10;

//先要尽可能调成负的
//然后把绝对值小的调大
int n,k,x;
int a[N];
struct Node{
	int v;
	bool operator <(const Node& b) const{
		return abs(a[v])>abs(a[b.v]);
	}
	Node(int x){
		v=x;	
	}
};

signed main(){
	cin>>n>>k>>x;
	int cnt=0;//记录负的数个数
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0) cnt++;
	}
	priority_queue<Node> q;
	for(int i=1;i<=n;i++) q.push(Node(i));
	while(q.size()&&k){
		Node t=q.top();
		q.pop();
		if(a[t.v]<0){
			if(cnt%2==0){
				a[t.v]+=x;
				if(a[t.v]>=0) cnt--;
			}else a[t.v]-=x;
		}else{
			if(cnt%2==0){
				a[t.v]-=x;
				if(a[t.v]<0) cnt--;
			}else a[t.v]+=x;
		}
		q.push(t);
		k--;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	
	
}