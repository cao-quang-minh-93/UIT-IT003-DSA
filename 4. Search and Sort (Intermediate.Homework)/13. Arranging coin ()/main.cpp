#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)

using namespace std;

////////////////////////////////////////////////

////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("process.inp","r",stdin);
    //freopen("process.out","w",stdout);
    int n;
    cin>>n;
    cout<<(int)(sqrt(1+8*n)-1)/2;
    return 0;
}
