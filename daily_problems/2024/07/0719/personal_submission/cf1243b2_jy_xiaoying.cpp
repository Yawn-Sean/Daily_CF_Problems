//链接：https://codeforces.com/problemset/problem/1243/B2  

#include<bits/stdc++.h> 
using namespace std;

typedef pair<int,int> pp;
typedef vector<pp> vv;


int k,n;
vv g;
string s,t;

void ops(int i,int j){
	swap(s[i],t[j]);
	g.push_back(pp(i,j));
}

void f(){
	g.clear();
	bool ans=1;
	for(int i=0;i<n;i++){
		if(s[i]==t[i]) continue;
		bool tmp=0;
		for(int j=i+1;j<n;j++){     //先在s串中找 
			if(s[i]==s[j]){
				ops(j,i);          //s[j]  与  t[i]位置交换
				tmp=1;
				break; 
			}
		}
		if(!tmp){
			for(int j=i+1;j<n;j++){   //s串中没有，再去t串中找 
				if(s[i]==t[j]){
					ops(i+1,j);   //s[i+1]  与  t[j]位置交换
					ops(i+1,i);   //s[i+1]  与  t[i]位置交换
					tmp=1;
					break;
				}
			}
		}
		if(!tmp){
			ans=0;
			break;
		}
	}
	if(ans==1){
		cout<<"Yes"<<endl;
		cout<<g.size()<<endl;
		for(auto sp:g){
			cout<<sp.first+1<<" "<<sp.second+1<<endl;
			//字符串的下标从1开始，得+1  &**************************************
		}
	}
	else{
		cout<<"No"<<endl;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>k;
	
	for(int i=0;i<k;i++){
		cin>>n;
		cin>>s>>t;
		f();
	}
	return 0;
}
