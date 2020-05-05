#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
using namespace std;

int arr[100] = {0};
string s;

int BinSearch (int *arr, int left, int right, int val) {
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (arr[mid] > val) right = mid - 1;
        else if (arr[mid] < val) left = mid + 1;
        else return mid + 1;
    }
    return -1;
}

void solve () {
    int n;
    while (1) {
        getline (cin, s);
        cin >> n;
        int j = 0, sum = 0;
        for (int i = 0; i < s.size(); i++)  {
            if(s[i] != ' ') sum = sum * 10 + s[i] - '0';
            else {
				arr[j++] = sum;
				sum = 0;
			}
			if(i == s.size() - 1)	arr[j++] = sum;
        }
        for (int i = 0; i < j; i++) {
            cout << arr[i] << ' ';
        }
        if (BinSearch (arr, 0, j, n) > 0) {
            cout << "Yes" << " " << BinSearch (arr, 0, j, n) << endl;
        } else {
            cout << "No" << endl;
        }
        cin.ignore();
    }
}

int main() {
	
    solve();
    
    return 0;
}


