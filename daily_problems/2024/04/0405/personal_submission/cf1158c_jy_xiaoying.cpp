#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1158/C

//
//     构造 + 贪心 + 单调栈验证 

//日期： 2024-4-5 
//格式化： ctrl+shift+ a

const int MAX=5e5+10;
typedef vector<int> vv;

int tt;
int n;
int p[MAX];
vector<vv> g=vector<vv>(MAX,vv());
int test[MAX];   //与 p 数组进行验证
int ans[MAX]; 

bool f_test(){
	stack<int> sta;
	for(int i=n;i>=1;i--){
		test[i]=n+1;
		while(!sta.empty() && ans[i]>ans[sta.top()]){
			sta.pop();
		}
		if(!sta.empty()) test[i]=sta.top();
		sta.push(i);
	}
	
	for(int i=1;i<=n;i++){
		if(test[i]!=p[i]) return 0;
	}
	return 1;
}

void f(){
	
	for(int i=n;i>=1;i--){
		g[p[i]].push_back(i);
	}
	int id=1;
	for(int i=1;i<=n+1;i++){
		for(int x:g[i]){
			ans[x]=id++;
		}
	}
	
	bool flag=f_test();
	if(flag==0){
		cout<<"-1"<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}

void init(){
	for(int i=0;i<=n+2;i++){
		g[i].clear();
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>tt;
    for(int i=0;i<tt;i++){
    	cin>>n;
    	for(int j=1;j<=n;j++){
    		cin>>p[j];
    		if(p[j]==-1) p[j]=j+1;
		}
		
		init();
		f();
	}

	return 0;
}
/*


*/

