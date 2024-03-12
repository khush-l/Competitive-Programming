
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 4 < n && s.substr(i, 5) == "mapie") {
                count++;
                i += 4;
            }
            else if (i + 2 < n && s.substr(i, 3) == "pie") {
                count++;
                i += 2;
            }
            else if (i + 2 < n && s.substr(i, 3) == "map") {
                count++;
                i += 2;
            }
        }

        cout << count << "\n";
    }
    return 0;
}