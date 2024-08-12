//链接：https://codeforces.com/problemset/problem/351/A  

#include<bits/stdc++.h>
using namespace std;

int sum;
int cnt;
int n;

/*
首先答案只于num向上取整有关 

小数为0：最多有min(n,cnt)向上取整 
故小数不为0： 最少有 n-min(n,cnt) 向上取整
小数不为0： 最多有 min(n,2*n-cnt) 向上取整
*/

void f(){
	int l=n-min(n,cnt);
	int r=min(n,2*n-cnt);
	
	int ans=INT_MAX;
	
	for(int i=l;i<=r;i++){
		ans=min(ans,abs(sum-i*1000));
	}
	
	//2234
	//ans=10023;
	int bfw=ans/100%10;
	int sfw=ans/10%10;
	int gw=ans%10;
	cout<<ans/1000<<"."<<bfw<<sfw<<gw<<endl;
	//cout<<ans<<endl;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	sum=0; cnt=0;
	
	string s;
	int len;
	for(int i=0;i<2*n;i++){
		cin>>s;
		len=s.size();
		int t=0;
		for(int j=len-3;j<len;j++){
			t=t*10+s[j]-'0';
		}
		sum+=t;
		if(t==0) cnt++;              //小数为0的个数 
	}
	
	f();
	return 0;
} 

/*
3
4469.000 6526.000 4864.000 9356.383 7490.000 995.896

10
8003.867 4368.000 2243.000 3340.287 5384.000 1036.456 3506.000 
4463.000 1477.000 2420.314 9391.000 1696.000 5857.833 244.000 8220.000 
5879.000 5424.482 2631.197 7111.000 9157.536

*/
