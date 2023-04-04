#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)

using namespace std;

int n, m;
////////////////////////////////////////////////

bool check(int mid, vector<int>& A, vector<int>& B) 
{
    int j = 0;
    f(i,0,n-1) 
    {
        if (A[i] < mid) 
        {
            bool T = false;
            while (j < m) 
            {
                if (B[j] + A[i] >= mid) 
                {
                    T = true;
                    j++;
                    break;
                }
                j++;
            }
            if (T == false)
                return false;
        }
    }
    return true;
}

int find_mid(int min_mid, int max_mid, vector<int>& A, vector<int>& B) 
{
    int l = min_mid;
    int r = max_mid;
    while (l <= r) 
    {
        int mid = (l + r) / 2;
        if (check(mid, A, B)) 
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

void print_result(int h, vector<int>& A, vector<int>& B) 
{
    int j = 0;
    vector<pair<int, int>> KQ;
    f(i,0,n-1) 
    {
        if (A[i] < h) 
        {
            while (j < m) 
            {
                if (B[j] + A[i] >= h) 
                {
                    j++;
                    break;
                }
                j++;
            }
            KQ.push_back(make_pair(i + 1, j));
        }
    }
    cout << h << " " << KQ.size() << "\n";
    for (auto x : KQ)
        cout << x.first << " " << x.second << "\n";
}
////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("process.inp","r",stdin);
    //freopen("process.out","w",stdout);
    cin >> n;
    vector<int> A(n);
    f(i,0,n-1)
        cin >> A[i];

    cin >> m;
    vector<int> B(m);
    f(i,0,m-1)
        cin >> B[i];

    int minA = *min_element(A.begin(), A.end());
    int maxB = *max_element(B.begin(), B.end());
    int max_mid = minA + maxB;
    int min_mid = minA;
    int height = find_mid(min_mid, max_mid, A, B);
    print_result(height, A, B);

    return 0;
}
