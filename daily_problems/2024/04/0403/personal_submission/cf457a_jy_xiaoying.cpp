#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/457/A

//     数学 + 等式   q^2 = q+1
//

//日期： 2024-4-3
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long  double ld;
const ld eps=1e-8;
const ld base=1.618033988;


string s,t;
int n,m;
ld nums[MAX];

void f(){
	n=s.size(),m=t.size();
	int len=max(n,m);
	for(int i=0;i<n;i++){
	    nums[i+len-n]+=s[i]-'0';	 //建议做差 防爆 long double 
	}
	for(int i=0;i<m;i++){
		nums[i+len-m]-=t[i]-'0';    //建议做差  防爆 long double
	}
	for(int i=0;i<len-2;i++){
		nums[i+1]+=nums[i];
		nums[i+2]+=nums[i];
		nums[i]=0;
	}
	
	ld ans=nums[len-2]*base+nums[len-1];
	
	if(abs(ans)<=eps){
		cout<<"=";
	}
	else if(ans>0){
		cout<<">";
	}
	else{
		cout<<"<";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>s;
	cin>>t;
	
	if(s.size()==t.size() && s.size()==1){
		if(s==t){
			cout<<"=";
		}
		else{
			if(s=="1") cout<<">";
			else cout<<"<";
		}
		return 0;
	}
	
	f();

	return 0;
}
/*
00111
10100

<

*/

