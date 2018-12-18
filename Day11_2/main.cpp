

#include <bits/stdc++.h>

using namespace std;

const int N = 300 ;

int serialNumber ;

int mat [ 310 ][ 310 ];


int main()
{
    freopen("file.in","r",stdin);

//    scanf("%d",&serialNumber);

    serialNumber = 1309;
    for ( int i = 1 ; i<= N ; i ++ ){
        for ( int j = 1 ; j <= N ; j++ ){
            long long rackId = i + 10 ;
            long long p = rackId * j ;

            p += serialNumber ;

            p *= rackId ;

            p = ( p /100 ) % 10 ;
            mat [ i ][ j ] = p - 5;
            mat [ i ] [ j ] = mat [ i ] [ j ] + mat [ i - 1 ][ j ] + mat[ i ] [ j - 1 ] - mat [ i -1 ] [ j - 1 ];
        }
    }

    int maxSum = -N , xMax , yMax ,szMax   ;


    for ( int sz = 1; sz <= N ; sz ++ ){
        for ( int i = sz ; i <= N - sz ; i++ ){
            for ( int j = sz ; j <= N - sz ; j++ ){

                int crSum = mat [ i ][ j ] - mat[ i - sz ][ j ] - mat [ i ][ j - sz ]  + mat [ i - sz ][ j - sz ];

                if ( crSum > maxSum ){
                    maxSum = crSum ;
                    xMax = i ;
                    yMax = j ;
                    szMax = sz ;
                }


            }
        }
    }

    printf("%d,%d,%d",xMax -szMax + 1  , yMax - szMax  + 1,szMax);



    return 0;
}
