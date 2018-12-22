#include <bits/stdc++.h>

using namespace std;

const int MOD = 20183 ;
const int N = 1000 ;

int depth , noLin , noCol ;

int level [ N ][ N ] ;
int index [ N ][ N ] ;
int mat [ N ][ N ] ;
int sum ;


void printMat (){

    for ( int i = 0 ; i <= noLin ; i++ ){
        for ( int j = 0 ; j <= noCol ; j++ ){
            if ( level [ i ] [ j ] % 3  == 0 ){
                printf(".");
            }else if ( level [ i ][ j ] % 3  == 1 ){
                printf("=");

            }else{
                printf("|");

            }
        }
        printf("\n");
    }

}

int main()
{
    freopen("file.in","r",stdin);


    scanf("depth: %d\n",&depth);
    scanf("target: %d,%d",&noLin,&noCol);

    for ( int i = 0 ; i <= noLin ; i++ ){
        for ( int j = 0 ; j <= noCol ; j++ ){
            if ( i == 0 ){
                index [ i ] [ j ] = ( ( j % MOD ) * 1LL*48271 ) % MOD ;
            }else if ( j == 0 ){
                index [ i ][ j ] = ( ( i % MOD ) * 1LL * 16807 ) % MOD ;
            }else{
                index [ i ][ j ] = ( level [ i - 1 ][ j ] * level[ i ][ j - 1 ] ) %MOD ;
            }
            if ( i == noLin && j == noCol ){
                index [ i ][ j ] = 0 ;
            }
            level [ i ][ j ] = (  index [ i ][ j ] + depth ) %MOD;
            mat [ i ] [ j ] = level [ i ][ j ] % 3 ;
            sum += level [ i ][ j ] % 3 ;
        }
    }
   // printMat();

    printf("%d",sum);

    return 0;
}
