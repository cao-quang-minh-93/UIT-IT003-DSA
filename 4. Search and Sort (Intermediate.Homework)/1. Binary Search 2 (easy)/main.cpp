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



int binarySearch(vector <long long> &a, int l, int r, int x)
{
	while (l <= r)
	{
		int m = (l+r)/2;
		if (x == a[m])
			return 1;
		if (x > a[m])
			l = m+1;
		else r = m-1;
	}
	return 0;
}
////////////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<long long> a(n);

    f(i,0,n-1) cin >> a[i];
    quickSort(a,0,n-1);

    int im;
    f(i,0,q-1)
    {
        cin>>im;
        if(binarySearch(a,0,n-1,im)==1) cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
