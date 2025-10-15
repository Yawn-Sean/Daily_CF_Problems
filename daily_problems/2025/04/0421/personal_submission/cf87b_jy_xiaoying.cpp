#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/87/B

//                                           
//                                            

//       2025-4-21-(大模拟)-cf87b 
//思路：

//日期：   2025-4-21 
//格式化： ctrl+shift+ a

typedef long long ll;
const string ops1="typedef"; 
const string ops2="typeof"; 

const int NA=INT_MIN/10;

int n;
string s;
string a,b;

void solve(){
	cin>>n;
	
	unordered_map<string,int> mp;
	mp["void"]=0;
	mp["errtype"]=NA;
	
	while(n--){
		cin>>s;
		if(s==ops1){
			cin>>a>>b;
			int l=0,r=a.size()-1;
			
			int cnt=0;              //  几级指针 
			while(a[l]=='&'){
				cnt--;
				l++;
			}
			while(a[r]=='*'){
				cnt++;
				r--;
			}
			
			string tmp="";
			for(int i=l;i<=r;i++){
				tmp+=a[i];
			}
			
			int cur=0;
			if(mp.find(tmp)==mp.end() || mp[tmp]+cnt<0) cur=NA;
			else cur=mp[tmp]+cnt;
			
			mp[b]=cur;
		}
		
		else{
			cin>>a;
			int l=0,r=a.size()-1;
			
			int cnt=0;              //  几级指针 
			while(a[l]=='&'){
				cnt--;
				l++;
			}
			while(a[r]=='*'){
				cnt++;
				r--;
			}
			
			string tmp="";
			for(int i=l;i<=r;i++){
				tmp+=a[i];
			} 
			
			if(mp.find(tmp)==mp.end() || mp[tmp]+cnt<0){
				cout<<"errtype"<<endl;
			}
			else{
				cout<<"void";
				
				int cur=mp[tmp]+cnt;
				while((cur--) >0) cout<<"*";
				cout<<endl;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    solve(); 
   
	return 0;
}
/*


*/

