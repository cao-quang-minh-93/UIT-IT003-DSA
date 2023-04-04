#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)

using namespace std;

////////////////////////////////////////////////
void process(long long &a)
{
    bool check = false;
    long long x = 4 * a - 1;
    long long y = sqrt(x);

    while (y != 0)
    {
        if (y==1)
            break;
        if (x % y == 0)
        {
            check = true;
            cout << (y - 1) / 2 << " " << ( x/y - 1) / 2 << endl;
            break;
        }
        y--;
    }
    if (check == false )
        cout << -1 << " " << -1 << endl;

}
////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("process.inp","r",stdin);
    //freopen("process.out","w",stdout);
    int n;
    cin >> n;
    vector <long long> a(n);
    f(i,0,n-1)
        cin >> a[i];
    f(i,0,n-1)
    process(a[i]);
    return 0;
}
