#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    int n;
    ll tot = 1;
    cin >> n;
    
    vector<int> a(n);
    vector<int> b(n + 1, 1);

    for (int &x : a){
        cin >> x;
    }
    b[a[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        tot += b[a[i] - 1];
        b[a[i]] = 0;
    }

    cout << tot;
}
