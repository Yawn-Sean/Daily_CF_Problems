//链接：https://codeforces.com/problemset/problem/949/A
// 2024-8-11

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vv;
string s;

void f(){
	int n=s.size();
	vector<vector<int>> ans;
	vector<int> t0,t1;
	bool flag=1;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){         //遇到‘0 ’
			if(t1.size()==0) {
				t0.push_back(ans.size());
				ans.push_back(vv{i});
			}
			else{
				int id=t1.back();
				ans[id].push_back(i);
				t1.pop_back();
				t0.push_back(id);
			}
		}
		else{      //遇到‘1 ’ 
			if(t0.size()==0){
				flag=0;
				break;
			}
			else{
				int id=t0.back();
				ans[id].push_back(i);
				t0.pop_back();
				t1.push_back(id);
			}
		}
	}
	
	if(flag==0 || t1.size()!=0){
		cout<<"-1"<<endl;
		return ;
	}
	
	int cnt=ans.size();
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		cout<<ans[i].size();
		for(auto j:ans[i]){
			cout<<" "<<j+1;     //下标从1开始 
		}
		cout<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	f();
	return 0;
} 
