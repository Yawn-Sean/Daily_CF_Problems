#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/301/A

//      
//思路：

//日期：  2024-4-9 
//格式化： ctrl+shift+ a


const int MAX=210;
typedef long long ll;
typedef long double ld;

int n; 
int nums[MAX];
int sum;
int small;

void solve(){
	int cnt=0;
	for(int i=0;i<2*n-1;i++){
		int cur=nums[i];
		if(cur<=0) cnt++;
	}
	
	if(cnt%2==0 || cnt==0 || (cnt%2==1 && n%2==1)){
		cout<<sum<<endl;
		//cout<<"111"<<endl;
	}
	else{
		cout<<sum-2*small<<endl;
		//cout<<"222"<<endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
     cin>>n;
     small=1000000;
     sum=0;
     for(int i=0;i<2*n-1;i++){
     	cin>>nums[i];
     	sum+=abs(nums[i]);
     	small=min(small,abs(nums[i]));
	 }
	 solve();

	return 0;
}
/*


*/

