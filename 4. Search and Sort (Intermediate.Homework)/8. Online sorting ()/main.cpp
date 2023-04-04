#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("process.inp", "r", stdin);
    //freopen("process.out", "w", stdout);

    vector<int> arr;
    int a, b;

    while (cin >> a >> b && a != 0)
    {
        if (a == 1)
        {
            int pos = lower_bound(arr.begin(), arr.end(), b) - arr.begin();
            if (pos == arr.size() || arr[pos] != b)
                arr.insert(arr.begin() + pos, b);
        }
        else if (a == 2)
        {
            int pos = lower_bound(arr.begin(), arr.end(), b) - arr.begin();
            if (pos == arr.size() || arr[pos] != b)
                cout << 0 << endl;
            else
                cout << pos + 1 << endl;
        }
    }

    return 0;
}
