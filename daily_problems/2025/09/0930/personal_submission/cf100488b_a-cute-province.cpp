#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;
int n;
set<int> op(int l, int r){
    r = min(n, r);
    cout << "Q " << l <<' ' << r<< endl;
    set<int> st;
    for(int i = l; i <= r; i ++){
        int x;
        cin >> x;
        st.insert(x);
    }
    return st;
}

void solve() {

    cin >> n;
    int fl = 0;
    vector<int> ans(n+1), vis(n+1);
    if(n == 1 || n == 2){
    	set<int> st;
    	st = op(1, 1);
    	ans[1] = *st.begin();
    	vis[ans[1]] = 1;
	}
	else if(n == 3 || n == 4){
		set<int> st1, st2;
    	st1 = op(1, 2);
    	st2 = op(2, 3);
    	for(auto u :st1){
    		for(auto v : st2){
    			if(u == v){
    				ans[2] = u;
    				vis[u] = 1;
    				break;
				}
			}
		}
    	for(auto u : st1){
    		if(u != ans[2])ans[1] = u, vis[u] = 1;
		}
		for(auto u : st2){
    		if(u != ans[2])ans[3] = u, vis[u] = 1;
		}
	}
	else{
		int cnt = 0;
    set<int> bolck[n+1];
    if(n%2 == 0)n--, fl = 1;
    bolck[++cnt] = op(1, 2);
    for(int i = 2; i < n-2; i += 2){
        bolck[++cnt] = op(i, i+2);
    }
    bolck[++cnt] = op(n-1, n);
    int mid;
   		for(int i = 3; i < cnt; i ++){
   			mid = (i-1)*2;
   			for(auto u : bolck[i-1]){
   				for(auto v : bolck[i]){
   					if(u == v){
   						ans[mid] = u;
   						vis[u] = 1;
   						break;
					   }
				   }
			   }
			   if(i > 3){
				   	for(auto u : bolck[i-1]){
					if(!vis[u]){
						ans[mid-1] = u;
						vis[u] = 1;
						break;
					}
				}
			   }   	
		}
		mid = 2;
		for(auto u : bolck[2]){
   				for(auto v : bolck[1]){
   					if(u == v){
   						ans[mid] = u;
   						vis[u] = 1;
   						break;
					   }
				   }
			   }
			   mid = n-1;
		for(auto u : bolck[cnt]){
   				for(auto v : bolck[cnt-1]){
   					if(u == v){
   						ans[mid] = u;
   						vis[u] = 1;
   						break;
					   }
				   }
			   }
		for(auto u : bolck[1]){
					if(!vis[u]){
						ans[1] = u;
						vis[u] = 1;
						break;
					}
				}
				
		for(auto u : bolck[2]){
					if(!vis[u]){
						ans[3] = u;
						vis[u] = 1;
						break;
					}
				}		
				
		for(auto u : bolck[cnt]){
					if(!vis[u]){
						ans[n] = u;
						vis[u] = 1;
						break;
					}
				}
		for(auto u : bolck[cnt-1]){
					if(!vis[u]){
						ans[n-2] = u;
						vis[u] = 1;
						break;
					}
				}		
		
	}

	if(fl)n++;
    if(ans[n] == 0){
    	for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ans[n] = i;
            break;
        }

    }
	}

    cout << "A ";
    for(int i = 1; i <= n; i++){
    	cout << ans[i] <<' ';

	}
    cout << endl;

}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
