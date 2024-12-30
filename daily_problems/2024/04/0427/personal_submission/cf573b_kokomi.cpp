#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int h[N];
//每一列方块三种消除方式 我一开始对自己消除的所用次数比较犹豫，后来才想明白就是h[i]次
//ans[i-1]+1 ans[i+1]+1 就是三种消除方式的最小值
//可以先用前两种方式得到ans[i]数组，再用第三种方式逆序更新，得到最终的ans[i]数组
int ans[N];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	if(n==1){
		cout<<1<<endl;
		return;
	}
	ans[0]=1;//边缘直接消除
	for(int i=1;i<n;i++){
		ans[i]=min(ans[i-1]+1,h[i]);
	}
	ans[n-1]=1;
	int res=1;
	for(int i=n-2;i;i--){
		ans[i]=min(ans[i],ans[i+1]+1);
		res=max(res,ans[i]);
	}
	cout<<res<<endl;
}

int main(){
	solve();
}