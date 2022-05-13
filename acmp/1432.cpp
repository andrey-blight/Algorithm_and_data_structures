#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, r;
    long long ans = 0;
    cin >> n >> q >> r;
    int *pre_sum = new int[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        r = (r * 1103515245ll + 12345) & 2147483647;
        pre_sum[i] = pre_sum[i - 1] + (r >> 16);
    }
    for (int i = 1; i <= q; ++i)
    {
        r = (r * 1103515245ll + 12345) & 2147483647;
        int b1 = ((r >> 16) % n) + 1;
        r = (r * 1103515245ll + 12345) & 2147483647;
        int b2 = ((r >> 16) % n) + 1;
        int left = min(b1, b2), right = max(b1, b2);
        ans += pre_sum[right] - pre_sum[left - 1];
        ans = ans & 2147483647;
    }
    cout << ans;
}