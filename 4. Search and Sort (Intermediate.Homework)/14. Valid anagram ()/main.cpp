#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)

using namespace std;

////////////////////////////////////////////////

bool isAnagram(string s, string t) 
{
    if (s.size() != t.size()) 
        return false;
    
    int ss[256] = {0};
    int tt[256] = {0};
    for (int i = 0; i < s.size(); i++) 
    {
        ss[s[i]]++;
        tt[t[i]]++;
    }
    
    for (int j = 0; j < 256; j++) 
        if (ss[j] != tt[j]) 
            return false;
    
    return true;
}

////////////////////////////////////////////////


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("process.inp","r",stdin);
    //freopen("process.out","w",stdout);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    if (isAnagram(s1, s2)) {
        cout << "IS ANAGRAM" << endl;
    } else {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) {
            cout << "IS ANAGRAM" << endl;
        } else {
            cout << "NOT ANAGRAM!!!" << endl;
        }
    }
    return 0;
}
