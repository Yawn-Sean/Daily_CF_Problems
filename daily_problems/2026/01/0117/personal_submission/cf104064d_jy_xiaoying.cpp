#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/104064/problem/D

//    2026-1-17-(计算几何 )- cfgym104064D
//

//日期： 2026-1-17 
//格式化： ctrl+shift+ a


int n;
int x,y;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
    
    //  x+y :s1  x-y :s2  -x+y :s3  -x-y :s4
    int s1=INT_MIN; int s2=s1;
    int s3=INT_MAX;  int s4=s3;
    
    int cnt=n;
    
    while(cnt--){
    	cin>>x>>y;
    	s1=max(s1,x+y);
    	s2=max(s2,x-y);
    	s3=min(s3,x-y);       //等价于 s3=max(s3,-x+y);
    	s4=min(s4,x+y);      //等价于  s4=max(s4,-x-y);
	}
	
	if(n==1){
		cout<<"4"<<endl;
		return 0;
	}
	
	int ans=0;
	if(s1==s4 || s3==s2){       //在同一条斜对角线上 
		ans=5+abs(s1-s4)+abs(s2-s3);
	}
	else{
		ans=4+abs(s1-s4)+abs(s2-s3);
	}
    
	cout<<ans<<endl;
	 
	return 0;
}
/*



*/

