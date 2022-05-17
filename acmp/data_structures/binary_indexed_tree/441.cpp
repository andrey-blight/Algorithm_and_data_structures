#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> fen;

void change(int x, int v)
{
    for (int i = x; i < n; i = (i | (i + 1)))
        fen[i] += v;
}
long long pre_sum(int r)
{
    long long res = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
        res += fen[i];
    return res;
}
long long add(int l, int r)
{
    return pre_sum(r) - pre_sum(l - 1);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long seconds = 0;
    cin >> n;
    fen.assign(n, 0);
    vector<pair<int, int>> first(n); // Make pair of vector {val,index} for sorting
    vector<pair<int, int>> second(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        first[i] = {x, i + 1};
    }
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        second[i] = {x, i + 1};
    }
    sort(first.begin(), first.end()); // sort vectors by value and if value is equal by index
    sort(second.begin(), second.end());
    vector<pair<int, int>> indexes(n); // make vector that contains {second index, first index}
    for (int i = 0; i < n; ++i)
        if (first[i].first != second[i].first) // we cannot solve if numbers not equal
        {
            cout << -1;
            return 0;
        }
        else
            indexes[i] = {second[i].second, first[i].second}; // fill indexes
    sort(indexes.begin(), indexes.end());                     // sort by the second index
    for (pair<int, int> el : indexes)
    {
        seconds += el.second - el.first + add(el.second - 1, n - 1); // summing different between indexes and we take into account last moving
        change(el.second - 1, 1);                                    // save that we move element
    }
    cout << seconds;
}