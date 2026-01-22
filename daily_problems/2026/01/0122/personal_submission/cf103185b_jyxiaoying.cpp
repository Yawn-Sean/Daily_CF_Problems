#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/gym/103185/problem/B

//    2026-1-22-(思维+不等式)- cfgym103185B 
//

//日期： 2026-1-22 
//格式化： ctrl+shift+ a

typedef long long ll;
const int MAX=1e5+10;

int nums[MAX];
int n;

int inc_arr[MAX];  //从位置 i 开始，最多能往右走多长   cur<=suf
int dec_arr[MAX];  //到位置 i 结束，最多能往左走多长   pre>=cur

void solve(){
	for(int i=0;i<n;i++){
		inc_arr[i]=1;
		dec_arr[i]=1; 
	}
	
	int pos=-1;
	for(int i=n-1;i>=0;i--){    //从位置 i 开始，最多能往右走多长
		if(nums[i]!=-1){
			if(pos!=-1){
				if(nums[i]>nums[pos]) inc_arr[i]=pos-i;
				else inc_arr[i]=inc_arr[i+1]+1;
			}
			pos=i;
		}
		else if(i!=n-1){
			inc_arr[i]=inc_arr[i+1]+1;
		}
	}
	
	pos=-1;
	for(int i=0;i<n;i++){    //到位置 i 结束，最多能往左走多长
		if(nums[i]!=-1){
			if(pos!=-1){
				if(nums[i]>nums[pos]) dec_arr[i]=i-pos;
				else dec_arr[i]=dec_arr[i-1]+1;
			}
			pos=i;
		}
		else if(i!=0){
			dec_arr[i]=dec_arr[i-1]+1;
		}
	}
	
	bool ans=0;
	for(int k=3;k<=n;k++){
		bool tmp=1;
		for(int l=0;l<n;l+=k){
			int r=min(n-1,l+k-1);
			if(r-l+1<3 || inc_arr[l]+dec_arr[r]<r-l+2 || inc_arr[l]<2 || dec_arr[r]<2)
			tmp=0;
		}
		ans|=tmp;
	}
	
	if(ans) cout<<"Y"<<endl;
	else cout<<"N"<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>nums[i];
	}
	
	solve();
   
	return 0;
}
/*



*/

