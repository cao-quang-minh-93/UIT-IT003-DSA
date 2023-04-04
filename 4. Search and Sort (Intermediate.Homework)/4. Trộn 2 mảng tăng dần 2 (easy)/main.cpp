
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void merge(int *&a,int n,int *&b,int m, int *&c)
{
    int nc=n+m;
    int ia=0,ib=0;
    for(int i = 0; i < nc; i++)
    {
        if(ia < n && ib < m)
        {
            if(a[ia]<b[ib])
            {
                c[i]=a[ia];
                ia++;
            }
            else
            {
                c[i]=b[ib];
                ib++;
            }
        }
        else
            if(ia >= n && ib < m)
            {
                c[i]=b[ib];
                ib++;
            }
            else
            {
                c[i]=a[ia];
                ia++;
            }
    }
}

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}
