#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1413/D

//   栈+倒序操作
//

//日期： 2024-3-26
//格式化： ctrl+shift+ a

const int MAX=2e5+10;
typedef long long ll;

int nums[MAX];
int n;

void f(){
	vector<int> ans;
	stack<int> sta;
	for(int i=2*n-1;i>=0;i--){
		if(nums[i]==-1){
			if(sta.empty()){
				cout<<"NO"<<endl;
				return ;
			}
			ans.push_back(sta.top());
			sta.pop();
		}
		else{
			if(!sta.empty() && sta.top()<nums[i]){
				cout<<"NO"<<endl;
				return ;
			}
			sta.push(nums[i]);
		}
	}
	
	reverse(ans.begin(),ans.end());
	cout<<"YES"<<endl;
	for(int x:ans){
		cout<<x<<" ";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;

	char ops;
	int id;
	for(int i=0; i<2*n; i++) {
		cin>>ops;
		if(ops=='+') nums[i]=-1;
		else {
			cin>>nums[i];
		}
	}
	
	f();

	return 0;
}
/*


*/

