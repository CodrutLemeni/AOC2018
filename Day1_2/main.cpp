#include <bits/stdc++.h>

using namespace std;

const int N = 5 *1e5 ;

unordered_set < long long > mySet ;

int v [ N ];
int noNum ;

int main()
{

    freopen("file.in","r",stdin);

    long long x = 0 ;



    while ( cin >> v [ noNum++ ] ){
       // printf("%d",noNum);
    }

    int i = 0 ;

    while ( i <  noNum ){
        x += v[ i ] ;



        if ( mySet.count( x )  == 1 ){
            printf("%lld", x );
            return 0;
        }
        mySet.insert( x  );

        //printf("%lld %lld\n", x , mySet.count( x ) );


        i = ( i + 1 )%(noNum - 1 );
    }

    cout << "javra" ;

    return 0;
}
