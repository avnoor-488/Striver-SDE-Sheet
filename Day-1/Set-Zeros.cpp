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


void solve(vv vec, int n, int m)
{
    vector<pair<int, int>>pp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 0)
            {
                pp.pb(make_pair(i, j));
            }

            else continue;
        }
    }


    // for (int i = 0; i < pp.size(); i++)
    // {
    //     cout << pp[i].first << " " << pp[i].second << endl;
    // }
    for (int i = 0; i < pp.size(); i++)
    {
        int tempRow = pp[i].first, tempCol = pp[i].second;

        while (tempCol < m)
        {

            vec[tempRow][tempCol] = 0;
            tempCol++;
        }
        while (tempRow < n)
        {
            vec[tempRow][pp[i].second] = 0; tempRow++;
        }

        tempRow = pp[i].first; tempCol = pp[i].second;
        while (tempCol >= 0)
        {
            // cout << tempCol << " ";
            vec[pp[i].first][tempCol] = 0;
            tempCol--;
            // cout << tempCol << " ";
        }
        while (tempRow >= 0)
        {
            // cout << tempRow;
            vec[tempRow][pp[i].second] = 0; tempRow--;
        }


    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;

    }

}




int main() {

//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;



    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > vec(n, vector<int>(m));
        cout << n << m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> vec[i][j];
            }

        }

        cout << endl;


        solve(vec, n, m);
    }
    return 0;
}

// coded with the ❤️ Avnoor

