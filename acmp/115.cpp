#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<long long>> arr;
long long rsq(int x1, int y1, int x2, int y2)
{
    if (x1 == 0 && y1 == 0)
        return arr[x2][y2];
    if (x1 == 0)
        return arr[x2][y2] - arr[x2][y1 - 1];
    if (y1 == 0)
        return arr[x2][y2] - arr[x1 - 1][y2];
    return arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    arr.assign(n, vector<long long>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            int el;
            cin >> el;
            if (i == 0 && j == 0)
                arr[i][j] = el;
            else if (i == 0)
                arr[i][j] = el + arr[i][j - 1];
            else if (j == 0)
                arr[i][j] = el + arr[i - 1][j];
            else
                arr[i][j] = el + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    long long max_sum = -150;
    for (int x1 = 0; x1 < n; ++x1)
        for (int y1 = 0; y1 < m; ++y1)
            for (int x2 = 0; x2 < n; ++x2)
            {
                if (x2 < x1)
                    continue;
                for (int y2 = 0; y2 < m; ++y2)
                {
                    if (y2 < y1)
                        continue;
                    long long s = rsq(x1, y1, x2, y2);
                    max_sum = max(max_sum, s);
                }
            }
    cout << max_sum;
}