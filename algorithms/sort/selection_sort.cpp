#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>& arr) {
  int length = arr.size();
	for (int i = 0; i < length-1; i++) {
		int min_element = i;
		for (int j = i + 1; j < length; j++) {
			if (arr[j] < arr[min_element])
				min_element = j;
		}

    swap(arr[i], arr[min_element]);
	}
}

int main() {
    vector<int> arr = { 10, 9, 5, 2, 6, 7, 11, 22, 55, 12, 13, 100 };
    selection_sort(arr);
    for(auto a:arr) cout << a << endl;
}
