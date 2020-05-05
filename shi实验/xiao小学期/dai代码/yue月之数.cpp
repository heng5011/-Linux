/*************************************************************************
	> File Name: 2502.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月16日 星期二 09时19分20秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int solve (int n) {
    return (1 << (n - 1)) + (n - 1) * (1 << (n - 2));
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}


