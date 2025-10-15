#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1185/D
//日期： 2024-3-8 
//格式化： ctrl+shift+ a

const int MAX=2e5+10;
typedef long long ll;
typedef pair<ll,int> pp;
int n;
vector<pp> nums;

void f(){
	if(n==2){
		cout<<"1"<<endl;
		return ;
	}
	vector<pp> g={pp(0,1),pp(0,2),pp(1,2)};
	for(pp its:g){
		int cnt=2;
		ll aa=nums[its.first].first;
		ll bb=nums[its.second].first;
		ll diff=bb-aa;
		int id=its.second-its.first==1?0:1;
		
		ll cur=bb+diff;
		for(int j=its.second+1;j<n;j++){
			if(cur==nums[j].first){
				cnt+=1;
				cur+=diff;
			}
			else{
				id=j;
			}
		}
		if(cnt>=n-1){
			cout<<nums[id].second<<endl;
			return ;
		}
	}
	cout<<"-1"<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>n;
    nums=vector<pp>(n);
    for(int i=0;i<n;i++){
    	cin>>nums[i].first;
    	nums[i].second=i+1;
	}
	sort(nums.begin(),nums.end(),[&](const pp &a,const pp &b){
		return a.first<b.first;
	});
	f();

	return 0;
}
/*

4
1 2 4 7

2
*/

