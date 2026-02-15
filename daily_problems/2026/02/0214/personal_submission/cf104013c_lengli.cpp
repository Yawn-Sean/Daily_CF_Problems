#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap_elements(int i, int j) {
    cout << i << " " << j << endl; 

    string response;
    if (!(cin >> response)) exit(0);

    if (response[0] == 'W') {
        exit(0);
    }
}

int main() {

    int n;
    cin >> n;

    for (int k = 0; k < n; ++k) {
        
        for (int i = 1; i < n; ++i) {
            swap_elements(i, i + 1);
        }

        for (int i = n; i > 2; --i) {
            swap_elements(i - 1, i);
        }
    }

    return 0;
}
