#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/453/A
//日期： 2024-3-7
//格式化： ctrl+shift+ a

typedef long double lld;

int m,n;

lld double_pow(lld base,int cnt){
	if(base==0) return 0;
	
	lld ans=1;
	while(cnt){
		if(cnt & 1) ans=ans*base;
		base*=base;
		cnt/=2;
	}
	return ans;
}

void f(){
	lld ans=0;
	lld tmp=m;
	for(int i=1;i<=m;i++){
		
		lld probability=double_pow(i/tmp,n)-double_pow((i-1)/tmp,n);
		ans+=i*probability;
	}
	
	cout<<std::fixed<<std::setprecision(12)<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

   cin>>m>>n;
   f();

	return 0;
}


