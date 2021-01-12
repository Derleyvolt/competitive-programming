#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string& s) {
   int i = 0, r = s.length() - 1;
   while(i < r) {
       if(s[i++] != s[r++])
           return false;
   }
   return true;
}

int main() {
    string str = "AAAVVAAA";
    cout << boolalpha << is_palindrome(str) << endl;
    return 0;
}
