#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
void solve(){
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	int num=0,tot=0,ans=0;
	for(int i=1;i<=n;i++){
		num=0,tot=0;
		for(int j=i;j<=n;j++){
			if(s[j]=='(')tot++;
			if(s[j]==')')tot--;//代表括号匹配
			if(s[j]=='?'){
				if(tot>0){//前面的左括号比较多
					tot--,num++;//num表示前面问号的个数
				}
				else{
					tot++;//转化为左括号
				}
			}
		
			if(tot<0&&num)tot+=2,num--;
			if(tot<0&&!num)break;
			if(tot==0)ans++;//答案
			//cout<<num<<" "<<tot<<"\n";
		}
 
	}
	cout<<ans<<"\n";
}
 
signed main(){
	solve();
	return 0;
}
