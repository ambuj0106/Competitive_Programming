#include <bits/stdc++.h> 
#include <unordered_set> 
#define pb push_back
#define mp make_pair 
#define fr first
#define sc second
#define MOD 1000000007d
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

        int n, k ;
        string s ;
        cin >> n >> k >> s ;

        int ans = 0 ;

        for ( int i = 0 ; i < k/2 ; ++i ) {

            int freq[26] = {0} ;
            for ( int j = 0 ; j < n/k ; ++j ) {
                // cout << i+j*k << ' ' ;
                ++freq[s[i+j*k]-'a'] ;
            }
            // cout << endl ;
            for ( int j = 1 ; j <= n/k ; ++j ) {
                ++freq[ s[(j*k - (i+1))] - 'a' ] ;
                // cout << (j*k - (i+1)) << ' ' ;
            }
            // cout << endl << endl ;
            int m = 0 ;
            for ( int j = 0 ; j < 26 ; ++j ) {
                m = max(m,freq[j]) ;
            }
            // cout << 2*(n/k) <<  (2*(n/k)-m)
            ans += (2*(n/k)-m) ;

        }

        // centre , odd k
        if ( k&1 ) {
            int freq[26] = {0} ;
            for ( int i = 0 ; i < n/k ; ++i ) {
                ++freq[s[k*i + k/2]-'a'] ;
            }
            int m = 0 ;
            for ( int i = 0 ; i < 26 ; ++i )
                m = max(m,freq[i]) ;
            ans += n/k - m ;
        }

        cout << ans << endl ;

    }

    return 0 ;
    
}