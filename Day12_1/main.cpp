#include <bits/stdc++.h>

using namespace std;

const int N = 400 ;
const int M = 200 ;


char crSir [ 2 ][ N ], rule [ 30 ];

struct Trans {
    int lVal , rVal ;
    int crVal , nextVal ;

};
Trans allTrans [ N ];
int noTrans ;

int main()
{
    freopen("file.in","r",stdin);

    scanf("initial state: %s\n\n",crSir[ 0 ] + M );

    for ( int i = 0 ; i < N ; i++ ){
        if ( crSir [ 0 ][ i ] == '#' ){
            crSir [ 0 ][ i ] = 1;
        }else{
            crSir[ 0 ] [ i ] = 0;
        }

    }

    while( gets ( rule ) ){

        int lVal = 0 , rVal = 0 ;

        if ( rule [ 0 ] == '#' ){
            lVal += 2;
        }
        if ( rule [ 1 ] == '#' ){
            lVal += 1;
        }
        if ( rule [ 3 ] == '#' ){
            rVal += 2;
        }
        if ( rule [ 4 ] == '#' ){
            rVal += 1;
        }
        allTrans [ noTrans ].lVal = lVal ;
        allTrans [ noTrans ].rVal = rVal ;
        if ( rule [ 2 ] == '#'){
            allTrans [ noTrans ].crVal = 1 ;
        }

        if ( rule [ 9 ] == '#' ){
            allTrans [ noTrans ].nextVal = 1 ;
        }
        noTrans ++ ;

    }

    int old = 1 , cr = 0 ;

    for ( int noRep = 0 ; noRep < 20 ; noRep ++ ){
        for ( int i = 2; i < N - 2 ; i ++ ){
            int lVal = 0 , rVal = 0 ;

            lVal = crSir [ cr ][ i - 2 ] * 2 + crSir [ cr ][ i - 1 ] ;
            rVal = crSir [ cr ][ i + 1 ] * 2 + crSir [ cr ][ i + 2 ] ;

            for  ( int k = 0 ; k < noTrans ; k++ ){
                if ( allTrans [ k ].lVal == lVal && allTrans [ k ].rVal == rVal && allTrans [ k ].crVal == crSir [ cr ][ i ] ){
                    crSir [ old ][ i ] = allTrans [ k ].nextVal ;
                }

            }


        }
        memset( crSir [ cr ] , 0 , sizeof crSir[ cr ]);
        old = 1 - old ;
        cr = 1 - cr ;
    }

    int crSum = 0 ;

//    for ( int i = 190 ; i < 240 ; i ++ ){
//        printf("%d",crSir [ cr ][ i ] );
//    }
    for ( int i = 0 ; i < N - 2 ; i ++ ){

        if ( crSir [ cr] [ i ] == 1 ){
            crSum += ( i - M ) ;
        }

    }
    printf("%d",crSum);



    return 0;
}
