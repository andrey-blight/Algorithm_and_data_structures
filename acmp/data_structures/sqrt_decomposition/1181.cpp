#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int s = (int)sqrt(n) + 1;
    vector<int> b(s);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i / s] += (!a[i]) ? 1 : 0;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int c_l = l / s, c_r = r / s;
        int ans = 0;
        if (c_l == c_r)
        {
            for (int i = l; i <= r; ++i)
                if (!a[i])
                    ++ans;
        }
        else
        {
            for (int i = l; i < (c_l + 1) * s; ++i)
                if (!a[i])
                    ++ans;
            for (int i = r; i >= c_r * s; --i)
                if (!a[i])
                    ++ans;
            for (int i = c_l + 1; i < c_r; ++i)
                ans += b[i];
        }
        cout << ans << ' ';
    }
}