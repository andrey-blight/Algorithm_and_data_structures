#include <iostream>
#include <vector>
using namespace std;

long long binpow(long long a, long long n)
{
    long long res = 1;
    while (n != 0)
    {
        if (n & 1)
            res = res * a % 2147483647;
        a = a * a % 2147483647;
        n >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, r;
    long long ans = 0;
    cin >> n >> q >> r;
    vector<long long> pre_com(n + 1);
    vector<long long> back_el(n + 1);
    pre_com[0] = 1;
    back_el[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        r = (r * 1103515245ll + 12345) & 2147483647;
        pre_com[i] = (max(1ll, pre_com[i - 1]) * (r >> 16)) % 2147483647;
        back_el[i] = binpow(pre_com[i], 2147483645);
    }
    for (int i = 1; i <= q; ++i)
    {
        r = (r * 1103515245ll + 12345) & 2147483647;
        int b1 = ((r >> 16) % n) + 1;
        r = (r * 1103515245ll + 12345) & 2147483647;
        int b2 = ((r >> 16) % n) + 1;
        int left = min(b1, b2), right = max(b1, b2);
        ans += (pre_com[right] * back_el[left - 1]) % 2147483647;
        ans %= 2147483647;
    }
    cout << ans;
}
