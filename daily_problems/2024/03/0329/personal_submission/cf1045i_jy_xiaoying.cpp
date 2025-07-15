#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1045/I

//   哈希表 + 枚举 
//

//日期： 2024-3-29 
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long long ll;

int n;
ll nums[MAX];

void f(){
	unordered_map<int,int> mp;
	ll ans=0;
	for(int i=0;i<n;i++){
		int x=nums[i];
		ans+=mp[x];
		if(x==0){
		    for(int j=0;j<26;j++){
		    	int tmp=1<<j;
		    	ans+=mp[tmp];
			}	
		}
		else{
			for(int j=0;j<26;j++){
				if((1<<j) & x==0) continue;
				int tmp=x ^ (1<<j);
				ans+=mp[tmp];
			}
		}
		mp[x]+=1;
	}
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
    	cin>>s;
    	int tmp=0;
    	for(char ss:s){
    		int j=ss-'a';
    		tmp^=(1<<j);
		}
		nums[i]=tmp;
	}
	
	f();

	return 0;
}
/*


*/

