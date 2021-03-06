// Author: proRam
// Name: Shubh Bansal
// Dated: June 6, 2020
// Question: https://www.codechef.com/JUNE20A/problems/TTUPLE

/*
Derivation 
p * x1   +   y1    =    a
q * x2   +   y2    =    b
r * x3   +   y3    =    c
*/

#include <bits/stdc++.h>
using namespace std;
class Timer { 
    private: chrono::time_point <chrono::steady_clock> Begin, End; public: Timer () : Begin(), End (){ Begin = chrono::steady_clock::now(); } ~Timer () { End = chrono::steady_clock::now(); cerr << "\nDuration: " << ((chrono::duration <double>)(End - Begin)).count() << "s\n"; } } T;

using ll = long long ;

ll A,B,C,P,Q,R ;

int ansis1( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // a = b = c = 0
    if ( a==b and b==c and a==c ) {
        return (a==0) ? 1 : 2 ;
    }

    int ans = 3 ;

    // =================================================================

    // p <---x----> a
    // q .......... b
    // r .......... c

    if ( q==b and r==c ) 
        return 1 ;

    // =================================================================

    // p <---x----> a
    // q <---x----> b
    // r .......... c

    // try addition
    if ( a-p == b-q )
        ans = (r==c) ? 1 : 2 ;

    // try multiplication
    if ( p!=0 and q!=0 and a%p==0 and b%q==0 and a/p == b/q )
        ans = (r==c) ? 1 : 2 ;

    // =================================================================

    // p <---x----> a
    // q <---x----> b
    // r <---x----> c    

    // try addition
    if ( c-r == a-p and a-p == b-q )
        return 1 ;

    // try multiplication
    if ( r!=0 and p!=0 and q!=0 and a%p==0 and b%q==0 and c%r == 0 and a/p == b/q and a/p == c/r )
        return 1 ;

    // =================================================================

    return ans ;

}

bool try_system1( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 01 p + y = a            p.......<--y-->a
    // 11 qx + y = b           q<--x--><--y-->b
    // 10 rx = c               r<--x-->.......c

    if ( r==0 or c%r != 0 )
        return false ;

    ll x = c/r ;
    ll y = a-p ;

    ll f1 = q * x ;
    ll f2 = f1 + y ;
    
    return ( f2 == b );

}

bool try_system2( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 01 (p)y = a
    // 11 (q+x)y = b
    // 10 (r+x) = c
                
    if ( p==0 or a%p != 0 )
        return false ;

    ll y = a/p ;
    ll x = c-r ;

    ll f1 = q + x ;
    ll f2 = f1 * y ;

    // cout << f1 << " " << f2 << endl ;

    return ( f2 == b );

}

bool try_system3( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 01 p     + y = a
    // 11 q + x + y = b
    // 10 r + x     = c
                
    ll x = c - r ;
    ll y = a - p ;
    return ( (q+x+y)==b ) ;

}

bool try_system4( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 01 p     * y = a
    // 11 q * x * y = b
    // 10 r * x     = c
                
    if ( r==0 or c%r != 0 or p==0 or a%p!=0 )
        return false ;

    ll y = a/p ;
    ll x = c/r ;

    ll f1 = q * x ;
    ll f2 = f1 * y ;

    // cout << f1 << " " << f2 << endl ;

    return ( f2 == b );

}

bool try_system5( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 01 p + y = a
    // 11 (qx) + y = b
    // 11 (rx) + y = c

    ll y = a - p ;
    // x = b-y / q = c-y/ r

    if ( q==0 or r==0 or (b-y)%q !=0 or (c-y)%r != 0 )
        return false ;

    ll x2 = (b-y)/q ;
    ll x3 = (c-y)/r ;

    // cout << f1 << " " << f2 << endl ;

    return ( x2==x3 ) ;

}

bool try_system6( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 01  py  = a
    // 11 (q+x)y = b
    // 11 (r+x)y = c
                
    if ( p==0 or a%p!=0 )
        return false ;

    ll y = a/p ;
    // x = b/y - q = c/y - r

    ll x2 = (b/y) - q ;
    ll x3 = (c/y) - r ;

    // cout << f1 << " " << f2 << endl ;

    return ( x2==x3 );

}

bool try_system7( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 10 (px) = a
    // 11 (qx) + y = b
    // 11 (rx) + y = c
                
    if ( p==0 or a%p!=0 )
        return false ;

    ll x = a/p ;
    // y = b-qx

    ll y2 = b - q*x ;
    ll y3 = c - r*x ;

    return ( y2==y3 );

}

bool try_system8( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 10 (p+x)  = a
    // 11 (q+x)y = b
    // 11 (r+x)y = c
                
    if ( r==0 or c%r != 0 or p==0 or a%p!=0 )
        return false ;

    ll x = a-p ;
    // y = b/(q+x)

    if ( (q+x)==0 or (r+x)==0 or b%(q+x)!=0 or c%(r+x)!=0 )
        return false ;

    ll y1 = b/(q+x) ;
    ll y3 = c/(r+x) ;

    return ( y1==y3 );

}


bool try_systemequilibrium1( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 11 (p+x)y = a
    // 11 (q+x)y = b
    // 11 (r+x)y = c
                
    // y = a/(p+x)
    // (a*(q+x))/(p+x) = b
    // x = (bp - aq) / (a-b)

    ll n1 = b*p, n2 = a*q, d = a-b ;
    ll n = n1-n2 ;
    if ( d==0 or n%d!=0 ) {
        return false ;
    }

    ll x = n/d ;
    ll xd = p+x ;
    if ( xd==0 or a%xd!=0 )
        return false ;
    
    ll y = a/xd ;

    // we have x and y

    return ( (r+x)*y == c ) ;

}


bool try_systemequilibrium2( ll &p, ll &q, ll &r, ll &a, ll &b, ll &c ) {

    // 11 (px) + y = a
    // 11 (qx) + y = b
    // 11 (rx) + y = c
            
    if ( p==0 or q==0 or r==0 )
        return false ;
        
    ll x1 = a/p ;
    ll y1 = a%p ;
    ll x2 = b/q ;
    ll y2 = b%q ;
    ll x3 = c/r ;
    ll y3 = c%r ;

    return ( x1==x2 and x2==x3 and y1==y2 and y2==y3 ) ;

}

void postulate_eqsys( ll &p, ll&q, ll&r, ll &a, ll&b, ll&c, int eqorder ) {

    switch ( eqorder ) {
        case 0: {
            p=P, q=Q, r=R ;
            a=A, b=B, c=C ;
            break ;
        }
        case 1: {
            p=P, q=R, r=Q ;
            a=A, b=C, c=B ;
            break ;
        }
        case 2: {
            p=Q, q=P, r=R ;
            a=B, b=A, c=C ;
            break ;
        }
        case 3: {
            p=Q, q=R, r=P ;
            a=B, b=C, c=A ;
            break ;
        }
        case 4: {
            p=R, q=P, r=Q ;
            a=C, b=A, c=B ;
            break ;
        }
        case 5: {
            p=R, q=Q, r=P ;
            a=C, b=B, c=A ;
            break ;
        }
    }

}

int32_t main(int argc, char** argv) {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr) ; cout.tie(nullptr) ;

    int t ;
    cin >> t ;

    while ( t-- ) {

        cin >> P >> Q >> R ;
        cin >> A >> B >> C ;

        // CASE WHEN STR==TAR i.e. ans = 0
        if ( P==A and Q==B and R==C ) {
            cout << 0 << '\n' ;
            continue ;
        }

        int ans = 3 ;

        for ( int eqorder = 0 ; eqorder < 6 ; ++eqorder ) {
            
            ll p,q,r,a,b,c ;
            postulate_eqsys(p,q,r,a,b,c,eqorder) ;

            // cout << p << " " << q << " " << r << "\n" ;
            // cout << a << " " << b << " " << c << "\n" ;

            // Try Answer 1
            int temp = min(ans,ansis1(p,q,r,a,b,c)) ;
            // cout << "temp = " << temp << '\n' ;
            if ( temp == 2 ) {
                // cout << "hey" << endl ;
                ans = 2;
            }
            if ( temp == 1) {
                ans = 1 ;
                break ;
            }

            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            // Try Answer 2.0.1 - px + y = a
            // 11 = 
            // 11 = 
            // 11 = 
            if ( ans>2 and try_systemequilibrium1(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }
            // Try Answer 2.0.2 - px + y = a
            // 01
            // 11
            // 10
            if ( ans>2 and try_systemequilibrium2(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }


            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            // Try Answer 2.1.1 - px + y = a
            // 01
            // 11
            // 10
            if ( ans>2 and try_system1(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }
            // Try Answer 2.1.2 - (p+x)y = a
            // 01
            // 11
            // 10
            if ( ans>2 and try_system2(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }
            // Try Answer 2.1.3 - p+x+y = a
            // 01
            // 11
            // 10
            if ( ans>2 and try_system3(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }
            // Try Answer 2.1.4 - p*x*y = a
            // 01
            // 11
            // 10
            if ( ans>2 and try_system4(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }

            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            // Try Answer 2.2.1 - px + y = a
            // 10
            // 11
            // 11
            if ( ans>2 and try_system5(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }
            // Try Answer 2.2.2 - (p+x)y = a
            // 10
            // 11
            // 11
            if ( ans>2 and try_system6(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }
            // Try Answer 2.2.3 - px + y = a
            // 01
            // 11
            // 11
            if ( ans>2 and try_system7(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }
            // Try Answer 2.2.4 - (p+x)y = a
            // 01
            // 11
            // 11
            if ( ans>2 and try_system8(p,q,r,a,b,c) ) {
                ans = min(ans,2) ;
            }

            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            // Try Answer 2
            // 11
            // 11
            // 00
            if ( r==c ) {
                ans = min(ans,2) ;
            }

            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            // Try Answer 2
            // reset and set 
            if ( ans>2 and a==b and b==c and c==a ) {
                ans = min(ans,2);
            }

            // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

            // cout << "\n################################################################\n" ;

        }

        cout << ans << '\n' ;

    }
    cout << endl ;

    return 0 ;   

}


/*
25
1 3 10
10000 30 18979

1 1 0
0 1 1

1 3 10
50 55 20

1 3 10
3 8 12

1 2 3
0 0 0

1 3 6
4 4 10

1 3 10
50 55 12

1 -3 7
5 6 8
2 3 5
7 11 13
5 10 13
53 103 133
1 3 -4
9 9 9
1 2 3
3 8 6
3 5 7
6 5 10
8 6 3
9 7 8
0 0 0
0 0 0
0 0 0
1 2 3
7 11 10
0 0 5
1 2 3
4 5 6
2 3 5
7 11 13
-15 7 1
-5  3 2
1 2 3

642812522 -800362287 63216506
479416287 -131377407 -485384906

-347797377 -31924853 174025552
-600464641 65936784 -404338570

-583978841 -41853773 -107403941
-115244701 -675856231 195451001

316770650 191379060 444940068
206615556 896617444 103019380

441909256 -657638099 -551749241
-407126904 -951344732 462148145

321213728 988318111 -289609678
891954866 908693161 588785979

-228359789 325816295 -786646575
-864898099 394695004 -914582447

-150731004 292399 738517704
-748650385 118117751 -819616428

-880331605 -153000204 590463802
-269398161 -824891562 -458682725

-471173780 -471435275 -678892583
54999150 617738373 -741625813


*/