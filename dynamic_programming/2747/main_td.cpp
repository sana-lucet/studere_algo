#include <iostream>

using namespace std;

int recur(int n){
    int dArr[100];
    dArr[0] = 0;
    dArr[1] = 1;
    
    if (n >= 2) {
        dArr[n] = recur(n-1) + recur(n-2);
    }

    return dArr[n];

}

int main(){
    int n;
    cin >> n;
    cout << recur(n);
}

