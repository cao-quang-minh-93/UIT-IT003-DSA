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
    priority_queue <int, vector<int>,less_equal <int>> arr;
    while(1)
    {
        int a;
        cin>>a;
        if(a==-2) break;
        if(a==-1)
        {
            int maxx=arr.top();
            while(maxx==arr.top())
                arr.pop();
        }
        if(arr.size()<100000&&a!=-1) arr.push(a);
    }
    cout<<arr.size()<<endl;
    int n=arr.size();
    f(i,0,n-1)
    {
        cout<<arr.top()<<endl;
        arr.pop();
    }
    return 0;
}
