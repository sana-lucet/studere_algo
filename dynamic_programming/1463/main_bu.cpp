#include <iostream>

using namespace std;

int main(){
    int dArr[1000001];
    int n;

    dArr[1] = 0;
    cin >> n;

    for (int i = 2; i <= n; i++){
        // case (3)
        dArr[i] = dArr[i-1] + 1;
        // case (2)
        if (n%2 == 0 && dArr[i] > dArr[i/2] + 1) {
            dArr[i] = dArr[i/2] + 1;
        }
        // case (1)
        if (n%3 == 0 && dArr[i] > dArr[i/3] + 1) {
            dArr[i] = dArr[i/3] + 1;
        }
    }

    cout << dArr[n];
}