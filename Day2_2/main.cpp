#include <bits/stdc++.h>

using namespace std;

const int N = 251 ;

string allStr [ N ];
int noStr = 0 ;

// cypueihajytordkgzxfqplbwn

int calcDiff ( int a , int b  ){
    int diffCounter = 0 ;

    for ( int i = 0 ; allStr [ a ][ i ] ; i++){
        if ( allStr [ a ][ i ] != allStr [ b ] [ i ] ){
            diffCounter ++ ;
        }
    }

    return diffCounter ;
}

int main()
{

    freopen ("file.in","r",stdin);

    while ( cin >> allStr [ noStr ++ ] );

    int i , j ;
    for (  i = 0 ; i < noStr ; i++ ){
        for ( j = i + 1 ; j < noStr ; j++ ){
            int noDiff = calcDiff( i , j );

            if ( noDiff == 1 ){
                printf("%d %d\n",i,j);
                cout << allStr [ i ] << '\n' << allStr [ j ] ;
                //break;
            }

        }
    }



    return 0;
}
