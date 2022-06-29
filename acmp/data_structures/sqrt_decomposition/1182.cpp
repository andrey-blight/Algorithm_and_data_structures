#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, k, t, len;
vector<int> stat;
vector<int> sh_stat;

bool can_add(int l, int r)
{
    int c_l = l / len, c_r = r / len;
    if (c_l == c_r)
    {
        for (int i = l; i <= r; ++i)
            if (stat[i] >= k)
                return 0;
        return 1;
    }
    for (int i = l; i <= (c_l + 1) * len; ++i)
        if (stat[i] >= k)
            return 0;
    for (int i = c_l + 1; i < c_r; ++i)
        if (sh_stat[i] >= k)
            return 0;
    for (int i = c_r * len; i <= r; ++i)
        if (stat[i] >= k)
            return 0;
    return 1;
}
void add(int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        ++stat[i];
        if (stat[i] > sh_stat[i / len])
            sh_stat[i / len] = stat[i];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> t;
    len = sqrt(n) + 1;
    stat.resize(n);
    sh_stat.resize(len);
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (can_add(l, r - 1))
            add(l, r - 1), cout << "Yes\n";
        else
            cout << "No\n";
    }
}