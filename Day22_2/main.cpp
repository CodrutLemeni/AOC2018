#include <bits/stdc++.h>

using namespace std;

const int MOD = 20183 ;
const int N = 3000 ;
const int INF = 1e6 ;


int depth , noLin , noCol ;

long long level [ N ][ N ] ;
int index [ N ][ N ] ;
int mat [ N ][ N ] ;
int dist [ 3 ][ N ][ N ];
// 0 - nimic
// 1 - torta
// 2 - aparat
int sum ;

struct Pozitie{
    int crLin , crCol ;
    int type ;
};

Pozitie makePoz ( int type , int crLin , int crCol ){
    Pozitie crPos ;

    crPos.type = type ;
    crPos.crLin = crLin ;
    crPos.crCol = crCol ;
    return crPos;
}

queue < Pozitie > que ;


int dl [] = { -1 , 0 , 1 , 0 };
int dc [] = { 0 , 1 , 0 , -1 };

void LEE(){


    for ( int k = 0 ; k < 3 ; k ++ ){
        for  ( int i = 0 ; i <= 3 * noLin ; i++ ){
            for ( int j = 0 ; j <= 3 * noCol ; j++ ){
                dist [ k ] [ i ] [ j ] = INF ;
            }
        }
    }

    dist [ 1 ] [ 0 ][ 0 ] = 0 ;

    que.push( makePoz( 1 , 0 , 0 ) );

    while ( !que.empty() ){
        Pozitie crPoz = que.front() ;
        que.pop() ;

        int type = crPoz.type ;
        int crLin = crPoz.crLin ;
        int crCol = crPoz.crCol ;

        for ( int k = 0 ; k < 3 ; k ++ ){
            if ( type != k ){

                if ( dist [ k ] [ crLin ] [ crCol ] > dist [ type ][ crLin ][ crCol ] + 7 ){
                    dist [ k ][ crLin ][ crCol ] = dist [ type ][ crLin ][ crCol ] + 7 ;
                    que.push( makePoz( k , crLin , crCol ) );
                }

            }
        }

        for ( int k = 0 ; k < 4 ; k++ ){
            int vecLin = crLin + dl [ k ] ;
            int vecCol = crCol + dc [ k ] ;

            if ( vecLin < 0 || vecCol < 0 ){
                continue ;
            }

            if ( mat [ vecLin ][ vecCol ] == 0 ){
                if ( type == 1 || type == 2 ){
                    if ( dist [ type ] [ vecLin ] [ vecCol ] > dist [ type ][ crLin ][ crCol ] + 1 ){
                        dist [ type ][ vecLin ][ vecCol ] = dist [ type ][ crLin ][ crCol ] + 1 ;
                        que.push( makePoz( type , vecLin , vecCol ) );
                    }
                }
            }else if ( mat [ vecLin ][ vecCol ] == 1 ){
                if ( type == 0 || type == 2 ){
                    if ( dist [ type ] [ vecLin ] [ vecCol ] > dist [ type ][ crLin ][ crCol ] + 1 ){
                        dist [ type ][ vecLin ][ vecCol ] = dist [ type ][ crLin ][ crCol ] + 1 ;
                        que.push( makePoz( type , vecLin , vecCol ) );
                    }
                }
            }else if ( mat [ vecLin ][ vecCol ] == 2 ){
                if ( type == 1 || type == 0 ){
                    if ( dist [ type ] [ vecLin ] [ vecCol ] > dist [ type ][ crLin ][ crCol ] + 1 ){
                        dist [ type ][ vecLin ][ vecCol ] = dist [ type ][ crLin ][ crCol ] + 1 ;
                        que.push( makePoz( type , vecLin , vecCol ) );
                    }
                }
            }



        }

    }


}



void printMat (){

    for ( int i = 0 ; i <= 3 * noLin ; i++ ){
        for ( int j = 0 ; j <= 3 * noCol ; j++ ){
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

void printMat1 (){

    for ( int i = 0 ; i <= 2 * noLin ; i++ ){
        for ( int j = 0 ; j <= 2 * noCol ; j++ ){
            printf("%2d ",dist[ 0 ][ i ][ j ]);
        }
        printf("\n");
    }

    printf("\n\n");

    for ( int i = 0 ; i <=  2 * noLin ; i++ ){
        for ( int j = 0 ; j <= 2 * noCol ; j++ ){
            printf("%2d ",dist[ 1 ][ i ][ j ]);
        }
        printf("\n");
    }

    printf("\n\n");


    for ( int i = 0 ; i <= 2 * noLin ; i++ ){
        for ( int j = 0 ; j <= 2 * noCol ; j++ ){
            printf("%2d ",dist[ 2 ][ i ][ j ]);
        }
        printf("\n");
    }

}

int main()
{
    freopen("file.in","r",stdin);


    scanf("depth: %d\n",&depth);
    scanf("target: %d,%d",&noCol,&noLin );

    for ( long long i = 0 ; i <= noLin * 3 ; i++ ){
        for ( long long j = 0 ; j <= noCol  * 3; j++ ){
            if ( i == 0 ){
                index [ i ] [ j ] = ( ( j % MOD ) * 1LL * 16807   ) % MOD ;
            }else if ( j == 0 ){
                index [ i ][ j ] = ( 1LL* ( i % MOD ) * 1LL * 48271  ) % MOD ;
            }else{
                index [ i ][ j ] = ( 1LL * level [ i - 1 ][ j ] * level[ i ][ j - 1 ] ) %MOD ;
            }
            if ( i == noLin && j == noCol ){
                index [ i ][ j ] = 0 ;
            }
            level [ i ][ j ] = (  index [ i ][ j ] + depth ) %MOD;
            mat [ i ] [ j ] = level [ i ][ j ] % 3 ;
        }
    }

    int sum = 0 ;

    for ( int i = 0 ; i <= noLin ; i++ ){
        for ( int j = 0 ; j <= noCol ; j++ ){
            sum += mat [ i ][ j ] ;
        }
    }

//    printMat();
//
//
//    cout << sum ;
//    return 0 ;

    LEE ();
    //printMat1();

    printf("%d" , dist [ 1 ] [ noLin ][ noCol ]);


    return 0;
}
