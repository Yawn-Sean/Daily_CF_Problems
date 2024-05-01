#include<bits/stdc++.h>
using namespace std;
//题意就看了半天：n个不同数， 你可以输入长为k的上升序列，s1~sn
//返回as1~asn中第m小的数和值
//先要求你询问不超过n次，猜出m的值

//对前k+1个元素询问k+1次 每次会少一个数，如果少的是第m大数之后的数，返回的永远是fm
//否则返回的一定是f(m+1)
//这样m大数出现k+1-m次，f(m+1)出现m次
unordered_map<int,int> f;
void solve(){
	int n,k;
	cin>>n>>k;
	int max1=0;
	for(int i=1;i<=k+1;i++){
		cout<<"?"<<" ";
		for(int j=1;j<=k+1;j++){
			if(j==i) continue;
			cout<<j<<" ";
		}
		cout.flush();
		int x,y;
		cin>>x>>y;
		f[y]++;
		max1=max(max1,y);
	}
	cout<<"! "<<f[max1];
}
int main(){
	solve();
}
