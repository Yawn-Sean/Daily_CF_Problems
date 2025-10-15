#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1512/E
//日期：2024-2-27
//格式化： ctrl+shift+ a

int kk;
const int MAX=520;
int ans[MAX];

int n,l,r,s;

void f() {
	int len=r-l+1;
	int mi=len*(len+1)/2;
	int ma=(2*n-len+1)*len/2;


	if(s<mi || s>ma) {
		cout<<"-1"<<endl;
		return ;
	}

	vector<int> tmp(len,0);
	int id=n-r+l;
	int sum=0;
	for(int &x:tmp) {
		x=id++;
		sum+=x;
	}

	int y=sum-s;
	for(int i=0; i<(r-l+1); i++) {
		int z=min(y,tmp[i]-i-1);
		tmp[i]-=z;
		y-=z;
		if(z==0) break;
	}

	vector<int> flag(n+10,1);
	for(int i=l,j=0; i<=r; i++,j++) {
		ans[i]=tmp[j];
		flag[tmp[j]]=0;
	}

	id=1;
	for(int i=1; i<l; i++) {
		while(flag[id]==0) id++;
		ans[i]=id++;
	}

	for(int i=r+1; i<=n; i++) {
		while(flag[id]==0) id++;
		ans[i]=id++;
	}
	
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>kk;
	while(kk--) {
		cin>>n>>l>>r>>s;
		f();
	}

	return 0;
}
