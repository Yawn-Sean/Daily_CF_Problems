#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/576/B

// 详解见：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/03/0311/solution/cf576b.md   
 
//日期： 2024-3-11
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
int  p[MAX];    //  permutation 排列 
int n;
bool vis[MAX];
int color[MAX];

void f(){

	
	bool is_nums_to_2=0;
	int a,b;
	
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		
		int col=0;
		
		vis[i]=1;
		color[i]=col;
		col^=1;
		int j=i;
		int cnt=1;
		while(p[j]!=i){
			cnt++;
			j=p[j];
			vis[j]=1;
			color[j]=col;
			col^=1;
		}
		
		if(cnt%2==1){
			cout<<"NO"<<endl;
			return ;
		}
		
		if(cnt==2){
			a=i,b=p[i];
			is_nums_to_2=1;
		}
	}
	
	if(is_nums_to_2==0){
		cout<<"NO"<<endl;
		return ;
	}
	
	cout<<"YES"<<endl;
	cout<<a<<" "<<b<<endl;
	
	for(int i=1;i<=n;i++){
		if(i==a || i==b || color[i]!=color[a]) continue;
		cout<<a<<" "<<i<<endl;
	}
	for(int i=1;i<=n;i++){
		if(i==a || i==b || color[i]!=color[b]) continue;
		cout<<b<<" "<<i<<endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    int tmp=-1;
    for(int i=1;i<=n;i++){
    	cin>>p[i];
    	vis[i]=0;
    	if(i==p[i]) tmp=i;
	}
	
	if(tmp!=-1){
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){
			if(i==tmp) continue;
			cout<<tmp<<" "<<i<<endl;
		}
		return 0;
	}
	
	f(); 

	return 0;
}
/*

4
4 3 2 1


*/

