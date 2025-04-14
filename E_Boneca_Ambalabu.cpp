#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vec vector<ll>
#define vvec vector<vec>
#define pp pair<ll, ll>
#define ump unordered_map
#define uset unordered_set
#define prq priority_queue
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.rbegin(), v.rend())
#define floop(i, n) for (ll i = 0; i < n; i++)
#define floo(i, n) for (ll i = 1; i <= n; i++)
#define cyes cout << "YES"
#define cno cout << "NO"
#define cln cout << endl
#define double long double
const ll mod = 1e9 + 7;

vvec dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void fast_io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileInput()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int nextPrime(int n) {
    while (true) {
        n++;
        if (isPrime(n)) {
            return n;
        }
    }
}

vector<bool> sieve(ll n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

void printv(vector<ll> v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}   

void printbit(ll n){
    string s = "";
    while(n>0){
        ll rem = n%2;
        s.pb(rem+'0');
        n/=2;
    }
    reverse(s.begin(), s.end());
    cout<<s;
    cln;
}


void solve(){
    ll n, k, y, m; 
    cin>>n;
    vec v(n);
    ll xori = 0;
    ll mini = 32;
    for(int i = 0; i<n; i++){
        cin>>v[i];    
    }
    sortv(v);
    vec left(n, 0), right(n, 0);
    left[0] = v[0], right[n-1] = v[n-1];

    for(int i = 1; i<n; i++){
        left[i] = v[i]^left[i-1];
    }
    for(int j = n-2; j>=0; j--){
        right[j] = v[j]^right[j+1];
    }
    ll ans = 0;

    for(int i = 0; i<n; i++){
        ll l = i>0 ? left[i-1] : 0;
        ll r = i<n-1 ? right[i+1] : 0;
        ans = max(ans, (l^r));
    }
    cout<<ans<<endl;
}

int main()
{
    fast_io();
    ll test_cases = 1;
    // vector<bool> sv = sieve(1000);
    // fileInput();
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }

    return 0;
}