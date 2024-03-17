#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int l = 1;
    int vals[n + 2] = {0}; 
    int a[n + 1] = {0};  
    vals[n + 1] = n + 1;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vals[x] = i;
        a[i] = x;
    }

    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        if (l > vals[i])
            c++;
        l = vals[i];
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int r = a[x], s = a[y];
        swap(a[x], a[y]);
        if (vals[r - 1] <= vals[r] && vals[r - 1] > y)
            c++;
        if (vals[r - 1] > vals[r] && vals[r - 1] <= y)
            c--;
        if (vals[r] <= vals[r + 1] && y > vals[r + 1])
            c++;
        if (vals[r] > vals[r + 1] && y <= vals[r + 1])
            c--;
        vals[r] = y;
        if (vals[s - 1] <= vals[s] && vals[s - 1] > x)
            c++;
        if (vals[s - 1] > vals[s] && vals[s - 1] <= x)
            c--;
        if (vals[s] <= vals[s + 1] && x > vals[s + 1])
            c++;
        if (vals[s] > vals[s + 1] && x <= vals[s + 1])
            c--;
        vals[s] = x;
        cout << c << endl;
    }
}
