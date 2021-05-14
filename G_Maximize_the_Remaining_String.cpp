#include <bits/stdc++.h>
using namespace std;
// #define secondl ("\n")
// #define pi (3.141592653589)
// #define mod 1e9+7
// #define int long long
// #define float double
// #define pb push_back
// #define ff first
// #define ss second
// #define all(c) cc.begin(),c.second()
// #define mini(a,b,c) min(c,min(a,b))
// #define mini(a,b,c,d) min(d,min(c,min(a,b)))
// #define rrep(i,n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)



int main()
{   
    string s1;
    int n;
    cin>>n;
    rep(i,n){
        cin>>s1;
        for (int k = 0; k < s1.length(); k++)
        {
            char a=s1[k];
            for (int j = k+1; j <= s1.length(); j++)
            {
                if (a==s1[j])
                {
                    s1.erase(s1.begin() + k);
                }
                
            }
 
        }
        
           cout<<s1<<secondl;
    }
    return 1;
}