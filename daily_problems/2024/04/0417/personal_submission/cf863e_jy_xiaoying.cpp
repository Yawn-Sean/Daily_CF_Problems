#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/863/E

//                                           
//                                            

//       2024-4-17-(排序+区间包含问题)-cf863e 
//思路：

//日期：   2024-4-17 
//格式化： ctrl+shift+ a

typedef pair<int,int> pp;

const int inf=INT_MAX/2;
const int MAX=2e5+5;
pp nums[MAX];
int id[MAX];
int n;

void solve(){
	int ppre=-1,pre=-1;
	
	for(int i=0;i<n;i++){
		int l=nums[id[i]].first,r=nums[id[i]].second;
		
		if(pre>=0 && nums[pre].second>=r){        // 一个区间要么被一个更大的区间 包含着 
			cout<<(id[i]+1)<<endl;
			return ;
		}
		if(ppre>=0 && nums[ppre].second+1>=l){   // +1 !!!        // 要么被两个区间合并后 包含着，只有2种情况 
			cout<<(pre+1)<<endl;
			return ;
		}
		ppre=pre;
		pre=id[i];
	}
	
	cout<<"-1"<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    int a,b;
    for(int i=0;i<n;i++){
    	cin>>a>>b;
    	id[i]=i;
    	nums[i]=pp(a,b);
	}
	sort(id,id+n,[&](const int x,const int y){
		return nums[x].first<nums[y].first || 
		(nums[x].first==nums[y].first && nums[x].second>nums[y].second); 
	});
	
	solve();

	return 0;
}
/*


*/

