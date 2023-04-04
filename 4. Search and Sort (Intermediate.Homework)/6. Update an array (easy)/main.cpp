#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)
using namespace std;

////////////////////////////////////////////////

struct Point
{
    long x, y;
};

bool compareXY(const Point &A, const Point &B)
{
    if (A.x != B.x)
        return A.x < B.x;
    return A.y > B.y;
}

void quickSort(vector<Point>& arr, int left, int right)
{
    int i = left, j = right;
    Point tmp;
    Point pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (compareXY(arr[i], pivot)) i++;
        while (compareXY(pivot, arr[j])) j--;
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //freopen("process.inp","r",stdin);
    //freopen("process.out","w",stdout);
    int n;
    scanf("%d", &n);
    vector<Point> a(n);
    f(i,0,n-1) scanf("%ld %ld", &a[i].x, &a[i].y);
    quickSort(a, 0, n-1);
    f(i,0,n-1) printf("%ld %ld\n", a[i].x, a[i].y);
    return 0;
}
