#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin >> a;
    unordered_map<int,int> m;
    int sum = 0;
    int ans = 0;
    m[0] = -1;
    for(int i = 0; i < a; i++) {
        char b;
        cin >> b;
        if(b == 'P') sum++;
        else sum--;
        if(m.find(sum) != m.end()) ans = max(ans, i - m[sum]);
        else m[sum] = i;
    }
    cout << ans <<endl;
    return 0;
}
