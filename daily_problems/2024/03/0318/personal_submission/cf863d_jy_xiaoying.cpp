#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/863/D

//  离线处理+倒推数组的初始下标 
//   

//日期： 2024-3-18 
//格式化： ctrl+shift+ a

const int MAX=2e5+10;
int n,q,m;

int nums[MAX];
int ques[MAX][3];

int ans[110];

void f(){
	for(int i=q;i>=1;i--){
		int ops=ques[i][0];
		int l=ques[i][1];
		int r=ques[i][2];
		
		if(ops==1){   //循环右移 
			for(int j=1;j<=m;j++){
				int id=ans[j];
				if(id>l && id<=r){  //*************************
					id-=1;
				}
				else if(id==l){
					id=r;
				}
				ans[j]=id;
			}
		}
		
		else{    // 翻转操作 
			for(int j=1;j<=m;j++){
				int id=ans[j];
				if(id>=l && id<=r){
					ans[j]=r+l-id;
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<nums[ans[i]]<<" ";
	}
	cout<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
   cin>>n>>q>>m;
   for(int i=1;i<=n;i++) cin>>nums[i];
   
   for(int i=1;i<=q;i++) cin>>ques[i][0]>>ques[i][1]>>ques[i][2];
   
   for(int i=1;i<=m;i++) cin>>ans[i];
   
   f();
	
	return 0;
}
/*


*/

