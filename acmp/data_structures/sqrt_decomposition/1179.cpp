#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int s = (int)sqrt(n) + 1;
    vector<int> b(s, 10000000);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i / s] = min(b[i / s], a[i]);
    }
    for (int l = 0, r = k - 1; r < n; ++l, ++r)
    {
        int c_l = l / s, c_r = r / s;
        int ans = 100000;
        if (c_l == c_r)
        {
            for (int i = l; i <= r; ++i)
                ans = min(ans, a[i]);
        }
        else
        {
            for (int i = l; i < (c_l + 1) * s; ++i)
                ans = min(ans, a[i]);
            for (int i = r; i >= c_r * s; --i)
                ans = min(ans, a[i]);
            for (int i = c_l + 1; i < c_r; ++i)
                ans = min(ans, b[i]);
        }
        cout << ans << ' ';
    }
}
