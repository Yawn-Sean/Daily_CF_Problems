#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1277/D

//                                           
//                                            

//       2025-4-21-(思维)-cf1277d
//思路：

//日期：   2025-4-21 
//格式化： ctrl+shift+ a

typedef long long ll;

int t;
int n;
string s;

void solve(){
	cin>>n;
	set<string> mp;
	vector<int> v00,v01,v10,v11;
	vector<string> str;
	
	for(int i=0;i<n;i++){
		cin>>s;
		mp.insert(s);
		str.push_back(s);
		
		if(s[0]=='0'){
			if(s.back()=='0') v00.push_back(i);
			else v01.push_back(i);
		}
		else{
			if(s.back()=='0') v10.push_back(i);
			else v11.push_back(i);
		}
	}
	
	if(v01.size()==0 && v10.size()==0 && v11.size()!=0 && v00.size()!=0){
		cout<<"-1"<<endl;
		return ;
	}
	
	vector<int> ans;
	
	if(v01.size()>v10.size()){           //  翻转01串 
		int cnt=v01.size()-v10.size();

			for(int i=0;i<v01.size() && cnt>1 ;i++){
				int id=v01[i];
				string tmp=str[id];
				reverse(tmp.begin(),tmp.end());
				
				if(mp.find(tmp)==mp.end()){   //确保翻转后的字符串是唯一的 
					cnt-=2;
					ans.push_back(id);
				}
			}
		
	}
	
	if(v01.size()<v10.size()){           //  翻转10串 
		int cnt=v10.size()-v01.size();
		
			for(int i=0;i<v10.size() && cnt>1 ;i++){
				int id=v10[i];
				string tmp=str[id];
				reverse(tmp.begin(),tmp.end());
				
				if(mp.find(tmp)==mp.end()){   //确保翻转后的字符串是唯一的 
					cnt-=2;
					ans.push_back(id);
				}
			}
		
	}
	
	
	cout<<ans.size()<<endl;
	for(int i:ans) cout<<1+i<<" ";     //初始下标从1开始 
	cout<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>t;
    while(t--){
    	solve();
	}
   
	return 0;
}
/*


*/

