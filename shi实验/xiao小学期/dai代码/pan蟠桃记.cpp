#include <iostream>
using namespace std;

int ans (int n) {
	int ans = 1;
	if (n == 1) {
		return 1;
	} else {
		while (--n) {
			ans = 2 * (ans + 1) ;
 		}
		return ans;;
	}
}

int main() {
	int n;
	while (cin >> n) { 
		cout << ans (n) << endl; 
	} 
	return 0;
} 
