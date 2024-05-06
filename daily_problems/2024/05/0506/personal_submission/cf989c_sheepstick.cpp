#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	vector<pair<int,char>> state(4);
	for (int i = 0; i < 4; i++){
		int x; cin >> x;
		state[i] = {x, i + 'A'};
	}
	sort(state.rbegin(), state.rend());

	if (state[0].first == 1){
		cout << 1 <<" "<< 4 << "\n";
		cout << "ABCD" << "\n";
		return;
	}



	state[0].first--;
	state[1].first--;

    vector<string> res(50, string(50, state[0].second));

    int rowNeed = (state[0].first + 24) / 25;
    for (int i = 0; i < rowNeed * 2; i++){
    	res[i] = string(50, state[1].second);
    } 

    int i = 0, j = 0;
    while(state[0].first > 0){
    	res[i][j] = state[0].second;
    	state[0].first--;
    	j += 2;
    	if (j >= 50) {
    		i += 2;
    		j = 0;
    	}
    }
    
    i = 2 * rowNeed;
    auto gao = [&](int cnt, char X) -> void {
    	i += 2;
    	int j = 0;
    	while(cnt){
    		res[i][j] = X;
    		j += 2;
    		if (j >= 50){
    			i += 2;
    			j = 0;
    		}
    		cnt--;
    	}
    };

    for (int i = 1; i < 4; i++){
    	gao(state[i].first, state[i].second);
    }

    cout << 50 <<" "<< 50 << "\n";
    for (int i = 0; i < 50; i++){
    	cout << res[i] << "\n";
    }



}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}