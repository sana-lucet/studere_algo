#include <iostream>
#include <vector>

using namespace std;

vector<int> dArr;
int n;

int recur(int n){
    if (n==1) {
        return 0;
    };
    // 이미 계산이 끝났으면 반환만
    if (dArr[n] > 0) {
        return dArr[n];
    }
    // case (3)
    dArr[n] = recur(n-1) + 1;
    // case (2)
    if (n%2 == 0) {
        int temp = recur(n/2) + 1;
        if (dArr[n] > temp) {
            dArr[n] = temp;
        }
    }
    // case (1)
    if (n%3 == 0) {
        int temp = recur(n/3) + 1;
        if (dArr[n] > temp) {
            dArr[n] =  temp;
        } 
    }
    return dArr[n];
}

int main(){
    cin >> n;
    cout << recur(n);
}