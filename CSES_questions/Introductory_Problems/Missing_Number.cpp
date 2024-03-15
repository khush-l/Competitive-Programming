#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ll n; cin >> n;
    ll tot = 0;
    for (int i = 0; i < n-1; ++i) {
         ll val; 
         cin >> val; 
         tot += val;
          }
    cout << ((n*(n+1))/2 - tot);
}