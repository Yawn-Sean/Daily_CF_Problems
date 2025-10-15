#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/946/E

//   贪心                                                                     
//思路： 固定最大 ans 的前缀（i位）与给定的 s 相同 ，枚举第 i+1 位比 s 小 ，剩下位先填 前面数字为奇数次的，再填 9      
//日期：  2024-4-6
//格式化： ctrl+shift+ a



const int MAX=2e5+10;
char s[MAX];
int n;
string ans[MAX/2];
int tt;
int cnts[MAX][11];

string f(){
	for(int i=0;i<n+5;i++){
		for(int j=0;j<=9;j++){
			cnts[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=9;j++){
			cnts[i][j]=cnts[i-1][j];
		}
		int tmp=s[i]-'0';
		cnts[i][tmp]^=1;
	}
	
	for(int i=n-1;i>=0;i--){
		int suf=s[i+1]-'0';
		for(int k=suf-1;k>=0;k--){
			vector<int> tmp(10);
			for(int j=0;j<=9;j++) tmp[j]=cnts[i][j];
			
			int pre_nums=0;         //前面已经确定了 pre_nums 位数字 
			int kong=n-2;
			if(!(i==0 && k==0)) {   //避免出现前缀 0 
			    tmp[k]^=1;
			    pre_nums=i+1;
			    kong=n-(i+1);
			}   
					
			int odd=0;
			for(int j=0;j<=9;j++){
				if(tmp[j]==1) odd++;
			}
			if(kong<odd) continue;
			
			string res="";
			string suf="";
			for(int j=0;j<=9;j++){
				if(tmp[j]==1) suf+='0'+j;
			}
			for(int j=0;j<kong-odd;j++) suf+='9';
			sort(suf.begin(),suf.end(),[&](char &ii,const char &jj){
				return ii>jj;
			});
			
			if(pre_nums!=0){
				for(int j=1;j<=i;j++) res+=s[j];
			    res+='0'+k;
			}
			
			for(char ii:suf) res+=ii;
			
			return res;
		}
	}
	return "0";
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>tt;
    for(int i=0;i<tt;i++){
    	string tmp;
    	cin>>tmp;
    	int id=1;
    	 n=tmp.size();
    	for(char t:tmp) s[id++]=t;
    	s[0]='0';
    	ans[i]=f();
	}
	
	for(int i=0;i<tt;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}
/*


*/

