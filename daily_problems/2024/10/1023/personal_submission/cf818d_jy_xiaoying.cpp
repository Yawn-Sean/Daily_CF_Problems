//链接：https://codeforces.com/problemset/problem/818/D

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e6+5;
typedef vector<int> vv;

int n,a;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>a;
	vector<vv> arr(MAX,vv());
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr[x].push_back(i);
	}
	
	int ans=-1;
	for(int i=1;i<MAX;i++){
		if(i==a || arr[a].size()>arr[i].size()) continue;
		bool flg=1;
		int len=arr[a].size();
		for(int j=0;j<len;j++){
			if(arr[a][j]<arr[i][j]){
				flg=0;
				break;
			}
		}
		
		if(flg){
			ans=i;
			break;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
} 
