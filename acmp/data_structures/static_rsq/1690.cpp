#include <iostream>
#include <vector>
#include <string>
using namespace std;

int h, n, m, t;
vector<vector<vector<int>>> a;

int g(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0 || x >= h || y >= n || z >= m)
        return 0;
    return a[x][y][z];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> h >> n >> m >> t;
    a.assign(h, vector<vector<int>>(n, vector<int>(m)));
    for (int x = 0; x < h; ++x)
        for (int y = 0; y < n; ++y)
        {
            string s;
            cin >> s;
            for (int z = 0; z < m; ++z)
                a[x][y][z] = (s[z] - '0') + g(x, y, z - 1) + g(x, y - 1, z) - g(x, y - 1, z - 1) +
                             g(x - 1, y, z) + g(x - 1, y - 1, z - 1) - g(x - 1, y - 1, z) - g(x - 1, y, z - 1);
        }
    while (t--)
    {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        --x1, --x2, --y1, --y2, --z1, --z2;
        if (x1 > x2)
            swap(x1, x2), swap(y1, y2), swap(z1, z2);
        cout << g(max(x1, x2), max(y2, y1), max(z1, z2)) - g(max(x1, x2), max(y1, y2), min(z2, z1) - 1) -
                    g(max(x1, x2), min(y1, y2) - 1, max(z1, z2)) + g(max(x1, x2), min(y1, y2) - 1, min(z1, z2) - 1) -
                    g(min(x1, x2) - 1, max(y1, y2), max(z1, z2)) + g(min(x1, x2) - 1, max(y1, y2), min(z2, z1) - 1) +
                    g(min(x2, x1) - 1, min(y1, y2) - 1, max(z1, z2)) - g(min(x2, x1) - 1, min(y2, y1) - 1, min(z2, z1) - 1)
             << '\n';
    }
}