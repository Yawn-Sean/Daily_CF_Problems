//链接：https://codeforces.com/problemset/problem/729/D
// 2024-8-8

#include<bits/stdc++.h>
using namespace std;

int n,a,b,k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>a>>b>>k;
	string s;
	cin>>s;
	
	vector<int> ans;   ans.clear();
	int sum=0;
	int id=1;                      //下标从1开始 
	for(char t:s){
		if(t=='1') sum=0;
		else{
			sum++;
			if(sum==b) {
				ans.push_back(id);
				sum=0;
			}
		}
		id++;
	}
	
	int len=ans.size();
	len-=(a-1);
	
	cout<<len<<endl;
	for(int i=0;i<len;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
} 
 
