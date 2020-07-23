#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007
#define clr(a) memset(a, 0, sizeof(a)) 
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a,n) a, a + n
  
using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

vector<vector<vector<int > > > dp ;

int solve( int x, int n, int m ) {

    if ( (x>-1 and m>-1 and n>-1) and dp[x][n][m] != -1 )
        return dp[x][n][m] ;

    if ( x <= 0 )
        return 1 ;
    
    int ans = 0 ;
    if ( n > 0 ) {
        ans = solve( (x/2)+10,n-1,m ) ;
    }
    if ( !ans and m>0 ) {
        ans = solve( x-10, n, m-1 ) ;
    }
    return dp[x][n][m] = ans ;

}

int32_t main(void) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int t ;
    cin >> t ;

    while ( t-- ) {

        int x,n,m ;
        cin >> x >> n >> m ;
// [100001][31][31] ;
        dp.clear() ;
        dp.resize(x+1,vector<vector<int> >(n+1,vector<int>(m+1,-1)) ) ;

        solve( x,n,m ) ;
        int ans = dp[x][n][m] ;
        cout << ((ans==1)?"YES":"NO") << endl ;

    }

    return 0 ;
    
}