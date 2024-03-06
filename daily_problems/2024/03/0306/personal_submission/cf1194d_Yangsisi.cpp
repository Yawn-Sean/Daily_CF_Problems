#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int _ ; cin >> _ ;
    while(_--){
        int n , k ; cin >> n >>  k;
        if (k % 3 == 0) {
            n %= k + 1 ;
            if (n == k) {
                cout << "Alice" << endl ;
                continue ;
            }
        }
        if(n%3>0){
            cout << "Alice" << endl ;
        } else {
            cout << "Bob" << endl ;
        }
    }
}
