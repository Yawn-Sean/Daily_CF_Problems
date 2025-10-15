#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int stk[N], top;
int main(){
	int n, t, s;
	int cnt=0;//禁止超车标识数
	int ts, ans=0;
	cin>>n;
	while(n--){
		cin>>t;
		if(t==1){
			cin>>s;
			ts=s;
			while(top>0&& stk[top]<ts){
				ans++;
				top--;
//				cout<<"-\n";
			}
		}else if(t==3){
			cin>>s;
			if(s<ts){
				ans++;
				continue;
			}
			stk[++top]=s;
		}else if(t==6){
			cnt++;
		}else if(t==4){
			cnt=0;
		}else if(t==5){
			top=0;
		}else{
			ans+=cnt;
			cnt=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
