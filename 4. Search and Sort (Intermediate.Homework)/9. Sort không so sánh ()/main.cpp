
#include <iostream>
using namespace std;



void my_sort(int *&arr, int n)
{
    int maxx = arr[0];
    int i = 1;
    while (i != n)
    {
        maxx = max(maxx, arr[i]);
        i++;
    }

    int sl = 0;
    while (maxx != 0)
    {
        sl++;
        maxx /= 10;
    }

    int exp = 1;
    int *ans = new int[n];
    int j = 0;
    while (j != sl)
    {
        int bk[10] = {0};
        int k = 0;
        while (k != n)
        {
            int kt = (arr[k] / exp) % 10;
            bk[kt]++;
            k++;
        }
        int l = 1;
        while (l != 10)
        {
            bk[l] += bk[l-1];
            l++;
        }

        int m = n-1;
        while (m != -1)
        {
            int kt = (arr[m] / exp) % 10;
            ans[bk[kt]-1] = arr[m];
            bk[kt]--;
            m--;
        }

        int p = 0;
        while (p != n)
        {
            arr[p] = ans[p];
            p++;
        }

        exp *= 10;
        j++;
    }

    delete[] ans;
}


int main(){
    int n;
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    my_sort (A, n);

    for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }
}

