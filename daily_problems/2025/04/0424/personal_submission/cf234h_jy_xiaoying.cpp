
    
#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/234/H

//     2025-4-24-(贪心+构造)-cf234H
//

//
//思路：

//日期： 2025-4-24
//格式化： ctrl+shift+ a


typedef unsigned long long ull;
typedef long long ll;
typedef unordered_set<ull> mp;
const int MAX=2e5+10;
const ull base=1e9+7;

int n,m;
int nums[MAX];
int ans1[MAX];
int ans2[MAX];

ifstream fin("input.txt");     //重定向标准输入输出到文件
ofstream fout("output.txt");

#define cin fin
#define cout fout

void f(int l,int r,int x,int y) {
	int tar=nums[ans1[1]];
	int id=2;
	while(l<=r || x<=y) {
		while(l<=r && nums[l]==tar) {
			ans1[id++]=l++;
		}
		while(x<=y && nums[x]==tar) {
			ans1[id++]=x++;
		}

		tar= tar==1?0:1;
	}
}

void get_res(vector<int> &v) {
	int x=nums[ans1[1]];
	int cnt=1;
	for(int i=2;i<=n+m;i++){

		if(nums[ans1[i]]!=x){
			v.push_back(cnt);
			cnt=1;
			x=nums[ans1[i]];
		}
		else{
			cnt++;
		}
	}
	v.push_back(cnt);
	return ;
}

void solve() {
	ans1[1]=1;
	f(2,n,n+1,n+m);

	vector<int>res2;
	get_res(res2);
	for(int i=1; i<=n+m; i++) {
		ans2[i]=ans1[i];
	}
	
	ans1[1]=n+1;
	f(1,n,n+2,n+m);
	vector<int> res1;
	get_res(res1);
	
	if(res1.size()<=res2.size()){
		for(int i=1;i<=n+m;i++) cout<<ans1[i]<<" ";
		cout<<endl;
		
		int tmp=res1.size();
		if(nums[ans1[n+m]]==0){
			tmp-=1;
		}
		cout<<tmp<<endl;
		int sum=0;
		for(int i=0;i<tmp;i++) {
			sum+=res1[i];
			cout<<sum<<" ";
		}
		cout<<endl;
	}
	else{
		for(int i=1;i<=n+m;i++) cout<<ans2[i]<<" ";
		cout<<endl;
		
		int tmp=res2.size();
		if(nums[ans2[n+m]]==0){
			tmp-=1;
		}
		cout<<tmp<<endl;
		int sum=0;
		for(int i=0;i<tmp;i++){
			sum+=res2[i];
			cout<<sum<<" ";
		} 
		cout<<endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int id=1;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>nums[id++];
	}
	cin>>m;
	for(int i=1; i<=m; i++) {
		cin>>nums[id++];
	}
	solve();

	return 0;
}
/*


*/

    
