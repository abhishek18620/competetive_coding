#include<bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using namespace std;
int min( int a, int b ) { return( a > b ? b : a ); }
bool from[ 10002 ], to[ 10002 ];

struct edge {
    int v;
    int w;
};

bool operator <( edge a, edge b ) {
    return a.w > b.w;
}

void dijkstra( vector< edge > graph[], int* dist, bool* array, int S ) {
    dist[ S ] =0;
    priority_queue< edge > q;
    q.push( ( edge ) { S, 0 } );
    while ( !q.empty() ) {
        edge p = q.top();
        q.pop();
        for ( int i = 0; i < graph[ p.v ].size(); ++i ) {
            edge k = graph[ p.v ][ i ];
            if ( dist[ p.v ] + k.w < dist[ k.v ] ) {
                dist[ k.v ] = dist[ p.v ] + k.w;
                q.push( k );
            }
        }
    }
}

int scan() {
    int n = 0;
    char c = getchar_unlocked();
    while ( !( '0' <= c && c <= '9' ) ) {
        c = getchar_unlocked();
    }
    while ( '0' <= c && c <= '9' ) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

int main() {
    int t, S, T, k, n, m, i, u, v, w; 
    int fromdis[ 10001 ], todis[ 10001 ];
    vector< edge > fo[ 10001 ], ba[ 10001 ];
    t = scan();
    while ( t-- ) {
        n = scan();
        m = scan();
        k = scan();
        S = scan();
        T = scan();
        for ( i = 0; i <= n; ++i ) {
            fromdis[ i ] = todis[ i ] = INF;
            from[ i ] = to[ i ] = false;
			fo[ i ].clear();
			ba[ i ].clear();
        }
        for ( i = 0; i < m; ++i ) {
            u = scan();
            v = scan();
            w = scan();
            fo[ u ].push_back( ( edge ) { v, w } );
            ba[ v ].push_back( ( edge ) { u, w } );
        }
        dijkstra( fo, fromdis, from, S );
        dijkstra( ba, todis, to, T );
        int ans = min( fromdis[ T ], todis[ S ] );
        while ( k ) {
            u= scan();
            v = scan();
            w = scan();
            ans = min( ans, min( fromdis[ v ] + w + todis[ u ], todis[ v ] + w + fromdis[ u ] ) );
            --k;
     }
        if ( ans == INF ) {
            printf( "-1\n" );
        }
        else {
            printf( "%d\n", ans );
        }
    }
    return 0;
}