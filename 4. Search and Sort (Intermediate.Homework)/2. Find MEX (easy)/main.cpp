#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)
using namespace std;

////////////////////////////////////////////////
void quickSort(vector <long long>& arr, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}


////////////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long> a(n);

    f(i,0,n-1) cin >> a[i];
    quickSort(a,0,n-1);
    if(n==0) cout<<0;
    else
        if(a[0]!=0) cout<<0;
        else
            f(i,1,n-1)
            {
                if((a[i]-a[i-1])>1)
                {
                    cout<<a[i-1]+1;
                    return 0;
                }
                if(i==(n-1)) cout<<a[i]+1;
            }
    return 0;
}
