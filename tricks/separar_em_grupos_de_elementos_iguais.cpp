#include <bits/stdc++.h>

using namespace std;

vector<string> separate(string& s) {
    vector<string> ans(1);
    char c = s.front();
    for(auto a:s) {
        if(a == c)
            ans.back().push_back(a);
        else
            c = a, ans.push_back({a});
    }
    
    for(auto a:ans) cout << a << endl;    
    return ans;
}

int main() {
    string s = "AAABBBCCCCDDDDEEFFGHIJJJJJKKKKLLLEEERRRGGGHHHAAABBCCC";
    separate(s);
    return 0;
}
