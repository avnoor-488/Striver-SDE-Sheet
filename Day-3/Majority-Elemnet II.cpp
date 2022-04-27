#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define forT(t) for(int i=0;i<t;i++)
#define forN(n) for(int j=0;j<n;j++)
#define MOD 1000000007
// #define num 4e6 + 5



typedef pair<int, int> pii;
typedef vector<string> vs;
typedef set<int> seti;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vv;


void fastscan( ll &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;


    if (negative)
        number *= -1;
}

ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

ll dp[100010][110][2];
ll arr[100010];

vi solve(vi vec)
{

    unordered_map<int, int>mp;

    for (int i = 0; i < vec.size(); i++)
        mp[vec[i]]++;

    int num = vec.size() / 3, ans = 0 ;
    vector<int> ansVec;
    for (auto it : mp)
    {
        if (it.second > num)
        {
            ansVec.push_back(it.first);
        }
    }    
    return ansVec;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)

    {
        int n; cin >> n;

        vi vec(n);

        forT(n)
        {
            cin >> vec[i];
        }


        vi ansVec =  solve(vec) ;
        for (auto it : ansVec)cout << it << " "
                                       ;
    }
    return 0;
}

// coded with the ❤️ Avnoor

