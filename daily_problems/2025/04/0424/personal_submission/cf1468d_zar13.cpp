#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int s[N];
int n, m, a, b;
int t1, t2;
bool check(int x){
	// cout<<"x:"<<x<<endl;
	int add=t2;
	if(x==t1){
		add=0;
	}
	for(int i=1;i<=x;i++){
		int t=t1-x+i-1+add;
		// cout<<"i:"<<i<<" t:"<<t<<" s_i:"<<s[i]<<endl;
		if(t<s[i]) return 0;
	}
	return 1;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>a>>b;
		for(int i=1;i<=m;i++) cin>>s[i];
		sort(s+1, s+m+1);
		t1=abs(a-b), t2;
		if(a<b) t2=a-1;
		else t2=n-a;
		int L=-1, R=min(m, t1)+1;
		// cout<<"t1:"<<t1<<" t2:"<<t2<<endl;
		// cout<<L<<" "<<R<<endl;
		while(L+1<R){
			int mid=(L+R)/2;
			if(check(mid)) L=mid;
			else R=mid;
			// cout<<L<<" "<<R<<endl;
		}
		cout<<L<<endl;
	}
	return 0;
}
