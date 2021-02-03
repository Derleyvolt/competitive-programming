#include <bits/stdc++.h>

using namespace std;

int getNextGap(int gap) { 
    gap = (gap*10)/13; 
  
    if (gap < 1) 
        return 1; 
    return gap; 
} 
  
void combSort(int a[], int n) { 
    int gap = n; 
  
    bool swapped = 1; 
  
    while (gap != 1 || swapped == 1) { 
        gap = getNextGap(gap); 
        
        swapped = 0; 
  
        for (int i=0; i<n-gap; i++) { 
            if (a[i] > a[i+gap]) { 
                swap(a[i], a[i+gap]); 
                swapped = 1; 
            } 
        } 
    } 
} 
  
int main() { 
    int a[] = { 8, 4, 1, 56, 3, -44, 23, -6, 28, 0 };
    int n = sizeof(a)/sizeof(a[0]); 
  
    combSort(a, n); 
  
    cout << "Array ordenado:" << endl;
  
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    return 0; 
} 
