#include <bits/stdc++.h>

#define f(a,b,n) for(unsigned long long a=b;a<=n;a++)
#define fd(a,b,n) for(unsigned long long a=b;a>=n;a--)

using namespace std;

////////////////////////////////////////////////


bool check(unsigned long long mid, vector<unsigned long long> &a, unsigned long long k)
{
    unsigned long long sum = 0;
    unsigned long long cnt = 1;
    for (unsigned long long i = 0; i < a.size(); i++)
    {
        if (a[i] > mid) return false;
        if (sum + a[i] > mid)
        {
            cnt++;
            sum = a[i];
        }
        else
            sum += a[i];
    }
    return cnt <= k;
}

////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("process.inp","r",stdin);
    //freopen("process.out","w",stdout);
    unsigned long long n, k;
    cin >> n >> k;
    vector<unsigned long long> a(n);
    for (unsigned long long i = 0; i < n; i++) cin >> a[i];
    unsigned long long l = *max_element(a.begin(), a.end());
    unsigned long long r = 1e10;
    while (l <= r)
    {
        unsigned long long mid = l + (r - l) / 2;
        if (check(mid, a, k))
            r = mid - 1;
        else
            l = mid + 1;
    }

        cout << l << endl;
    return 0;
}
