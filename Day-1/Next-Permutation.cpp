#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define sec second
#define forT(t) for(int i=0;i<t;i++)
#define forN(n) for(int j=0;j<n;j++)
#define MOD 1000000007
#define all(cont) cont.begin(), cont.end()
#define vll vector<ll>
#define pll pair<ll, ll>

typedef pair<int, int> pii;
typedef set<int> seti;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int>> vv;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vv;
typedef vector<vector<string>> vss;


void readVec(vi &vec, int n)
{
    for (int i = 0; i < n; i++)
        cin >> vec[i];
}


void printVec(vi vec, int n)
{
    for (int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << endl;
}

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


void solve(vi vec)
{
    int n = vec.size();
    int k = vec.size() - 1, j;

    if (vec.size() == 1 or vec.size() == 0)return ;

    int i;
    for ( i = vec.size() - 2; i >= 0; i--)
    {
        if (vec[i] < vec[i + 1])break;
    }


    if (i < 0)reverse(vec.begin(), vec.end());
    else
    {

        for ( j = n - 1; j > i; j--)
        {
            if (vec[j] > vec[i])break;

        }

        swap(vec[j], vec[i]);
        reverse(vec.begin() + i + 1, vec.end());
    }


    for (auto it : vec)cout << it << " ";

}




int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n ;
        cout << n ;
        vi vec(n);
        for (int i = 0; i < n; i++)
        {

            cin >> vec[i];

        }



        cout << endl;

        solve(vec);
        // cout << vec.size();
    }
    return 0;
}

// coded with the ❤️ Avnoor

