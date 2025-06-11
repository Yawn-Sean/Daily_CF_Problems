#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int len=s.size();
	if(s[0]=='0'){
		if(len==1) cout<<1;
		else cout<<0;
	}
	else if((s[0]>='1'&& s[0]<='9')||s[0]=='_'){
		int st=0;
		if(s[0]=='_') st=1;
		if(len==1) cout<<st;
		else{
			if(s[len-2]=='0'|| s[len-2]=='2'|| s[len-2]=='5'|| s[len-2]=='7'){
				bool fg=0;
				if(s[len-1]>='0'&& s[len-1]<='9'){
					if(((s[len-2]-'0')*10+s[len-1]-'0')%25==0) fg=1;
				}
				if(fg|| s[len-1]=='_'){
					int res=1, fg=1;
					if(st) res=9;
					//s[len-1]=='_'  -> res*=1
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
						if(s[i]=='X'&& fg){
							res*=10;
							fg=0;
						}
					}
					cout<<res;
				}else if(s[len-1]=='X'){
					int res=1;
					if(st) res=9;
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else{
					cout<<0;
				}
			}
			else if(s[len-2]=='_'){
				if(s[len-1]=='0'|| s[len-1]=='5'){
					int res=2, fg=1;
					if(len>2){
						if(st) res*=9;
						for(int i=st;i<=len-3;i++){
							if(s[i]=='_') res*=10;
							if(s[i]=='X'&& fg){
								res*=10;
								fg=0;
							}
						}
					}
					cout<<res;
				}else if(s[len-1]=='_'){
					int res=3, fg=1; //00 × 
					if(len>2){
						res++;// 
						if(st) res*=9;
						for(int i=st;i<=len-3;i++){
							if(s[i]=='_') res*=10;
							if(s[i]=='X'&& fg){
								res*=10;
								fg=0;
							}
						}
					}
					cout<<res;
				}else if(s[len-1]=='X'){
					int res=3, fg=1; //00 × 
					if(len>2){
						res++;// 
						if(st) res*=9;
						for(int i=st;i<=len-3;i++){
							if(s[i]=='_') res*=10;
						}
					}
					cout<<res;
				}else{
					cout<<0;
				}
			}
			else if(s[len-2]=='X'){
				if(s[len-1]=='0'|| s[len-1]=='5'){
					int res=2, fg=1;
					if(st) res*=9;
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else if(s[len-1]=='X'){
					int res=1;
					if(st) res=9;
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else if(s[len-1]=='_'){
					int res=4, fg=1;
					if(st) res*=9;
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}
	}	
	else if(s[0]=='X'){
		int st=1;
		if(len==1) cout<<1;
		else{
			if(s[len-2]=='0'|| s[len-2]=='2'|| s[len-2]=='5'|| s[len-2]=='7'){
				bool fg=0;
				if(s[len-1]>='0'&& s[len-1]<='9'){
					if(((s[len-2]-'0')*10+s[len-1]-'0')%25==0) fg=1;
				}
				if(fg|| s[len-1]=='_'){
					int res=9, fg=1;
					//s[len-1]=='_'  -> res*=1
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else if(s[len-1]=='X'){
					int res=1;
					if(s[len-2]=='0'|| s[len-2]=='5') res=0;
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else{
					cout<<0;
				}
			}
			else if(s[len-2]=='_'){
				if(s[len-1]=='0'|| s[len-1]=='5'){
					int res=2, fg=1;
					if(len>2){
						if(st) res*=9;
						for(int i=st;i<=len-3;i++){
							if(s[i]=='_') res*=10;
						}
					}
					cout<<res;
				}else if(s[len-1]=='_'){
					int res=3, fg=1; //00 × 
					if(len>2){
						res++;// 
						if(st) res*=9;
						for(int i=st;i<=len-3;i++){
							if(s[i]=='_') res*=10;
						}
					}
					cout<<res;
				}else if(s[len-1]=='X'){
					int res=2, fg=1; //_0 × 25 75 
					if(len>2){
						for(int i=st;i<=len-3;i++){
							if(s[i]=='_') res*=10;
						}
					}
					cout<<res;
				}else{
					cout<<0;
				}
			}
			else if(s[len-2]=='X'){
				if(s[len-1]=='0'){
					int res=1, fg=1;
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else if(s[len-1]=='5'){
					int res=2, fg=1;
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else if(s[len-1]=='X'){
					cout<<0; // 0...00
				}else if(s[len-1]=='_'){
					int res=3, fg=1; //0_ × 25 50 75 
					for(int i=st;i<=len-3;i++){
						if(s[i]=='_') res*=10;
					}
					cout<<res;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}
