// Struggling
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const int N = 200005;
const int Mod = 1e9 + 7;
long long fact[N];
long long Invfact[N];
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % Mod;
            ;
        }
        a = (a * a) % Mod;
        b /= 2;
    }
    return res;
}
void initialize()
{
    fact[0] = 1;
    Invfact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % Mod;
        Invfact[i] = binpow(fact[i], Mod - 2);
    }
}
long long nck(int a, int b)
{
    long long res = (fact[a] * Invfact[b]) % Mod;
    res = (res * Invfact[a - b]) % Mod;
    return res;
}
void solve()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    set<pair<int,char>>st;
    map<char,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[str[i]]++;
    }
    for(auto ele:mp)
    {
        st.insert({ele.second,ele.first});
    }
    while(st.size()>1)
    {
        auto it=*(--st.end());
        char ch=it.second;
        cout<<it.second;
        st.erase(--st.end());
        auto it1=*(--st.end());
        cout<<it1.second;
        st.erase(--st.end());
        if(it.first-1>0)
        {
            st.insert({it.first-1,it.second});
        }
        if(it1.first-1>0)
        {
            st.insert({it1.first-1,it1.second});
        }
    }
    while(st.size()>0)
    {
        auto it=*(--st.end());
        cout<<it.second;
        st.erase(--st.end());
        if(it.first-1>0)
        {
            st.insert({it.first-1,it.second});
        }
    }
    cout<<'\n';

    
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    // initialize();
    t = 1;
    // factorial();
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}