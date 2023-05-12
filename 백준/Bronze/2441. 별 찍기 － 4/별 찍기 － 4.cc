#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cin >> n1;
    n2 = n1 + 1;
    while (n2--) {
        for (int i=0; i<n1-n2; i++) {
            cout << " ";
        }
        for (int i=0; i<n2; i++) {
            cout << "*";
        }
        cout << "\n";
    }
}