#include <iostream>
#include <string> 

int main(){

    std::string str;
    std::cin >> str;
    
    int n = str.length();
    int arr[n+1];

    int d[5001] = {0};
    for (int i = 1; i <= n; i++) {
        arr[i] = str[i-1] - '0';
    }
    
    if (arr[1] == 0 || arr[1] >= 3 && arr[2] == 0) {
        std::cout << "0" << std::endl;
        return 0;
    } 
    
    d[1] = 1; 
    if (arr[1] * 10 + arr[2] >= 11 && arr[1] * 10 + arr[2] <= 26 && arr[2] > 0) {
        d[2] = 2;
    } else {
        d[2] = 1;
    }
    
    for (int i = 3; i <= n; i++){
        if (arr[i] >= 1 && arr[i] <= 9) {
            d[i] += d[i-1];
            d[i] %= 1000000;
        } 
        if (arr[i-1] * 10 + arr[i] <= 26 && arr[i-1] > 0) {
            d[i] += d[i-2];
            d[i] %= 1000000;     
        } 
    }
    std::cout << d[n] << std::endl;
    return 0;
}