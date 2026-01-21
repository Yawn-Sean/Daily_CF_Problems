#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long a, b, n;
        cin >> a >> b >> n;

        if(n > a + 2 * (2 * b - 1)){
            cout << "Bob\n";
        }else if(n <= a + 2 * (b - 1)){
            cout << "Alice\n";
        }else if(n < 3 * a){
            cout << "Bob\n";
        }else{
            cout << "Alice\n";
        }
    }

    return 0;
}
