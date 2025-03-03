#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/958/F2
//格式化： ctrl+shift+ a

int n,m;
const int MAX=2e5+10;
int a[MAX];
int b[MAX]; 
int cnt;

void f(){
	int ans=n+10;
	int over=0;
	int l=0,r=0;
	for(;l<n;l++){
		while(r<n && cnt!=0){
			int x=a[r]-1;
			b[x]--;
			if(b[x]<0){
				over+=1;
			}
			else{
				cnt--;
			}
			r++;
		}
		if(cnt==0) ans=min(ans,over);
		
		//区间左边界缩小 
		int x=a[l]-1;
		if(++b[x]>0){
			cnt++;
		}
		else{
			over-=1;
		}
	}
	
	if(ans==n+10) ans=-1;
	cout<<ans<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cnt=0;
	for(int i=0;i<m;i++){
		cin>>b[i];
		cnt+=b[i];
	}
	
	f();
	
	return 0;
}
