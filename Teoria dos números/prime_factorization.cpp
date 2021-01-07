#include <bits/stdc++.h>

using namespace std;

vector<int> factors(int n) {
	vector<int> ans;
	for(int i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			ans.push_back(i);
			n /= i;
		}
	}

	if(n > 1) ans.push_back(n); // n ou é primo ou é 1..
	                            // todo número composto tem no máximo
								// um primo maior que sua raíz
								// é fácil provar isso
	return ans;
}

int main() {
	auto r = factors(112);
	for(auto a : r)
		cout << a << endl;
	return 0;
}
