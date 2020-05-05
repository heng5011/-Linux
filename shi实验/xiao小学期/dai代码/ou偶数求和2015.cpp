/*************************************************************************
	> File Name: ou偶数求和2015.cpp
	> Author: kwh 
	> Mail: 
	> Created Time: 2019年07月15日 星期一 19时21分10秒
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[105] = {0};

int main() {
    int n, m; 
    while (cin >> n >> m) {
        
        int j = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += 2 * i;
            if (i % m == 0 || i == n) {
                a[j++] = sum;
                sum = 0;
            }
        }
        for (int i = 0; i < j - 1; i++) {
            cout << a[i] / m << " "; 
        }
        if (n % m != 0) {
            cout << a[j - 1] / (n % m) << endl;;
        } else {
            cout << a[j - 1] / m << endl;
        }
    }
    return 0;
}
