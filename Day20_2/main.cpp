#include <bits/stdc++.h>

using namespace std;

const int N = 100000 ;
const int K = 2000 ;
const int INF = 1e5 ;

char s [ N ] ;

int dist [ K ][ K ] ;
int mat [ K ][ K ];
int doorsMax ;
int noRooms ;

int dl[]= { -1 , 0 , 1 , 0 };
int dc[]= { 0 , 1 , 0 , -1 };

stack < pair < int, int > > stk ;

int val ;

void parse( int& idx ,int crLin , int crCol  ){

    val ++ ;
    stk.push( make_pair( crLin , crCol ) );
    while ( 3 ){

        crLin = stk.top().first ;
        crCol = stk.top().second ;
        stk.pop() ;
        val -- ;

        if ( s [ idx ] == '('  ){
            val += 2 ;
            stk.push( make_pair( crLin , crCol ) );
            stk.push( make_pair( crLin , crCol ) );
        }else if ( s [ idx ] == '|'  ){
            crLin = stk.top().first ;
            crCol = stk.top().second ;
            stk.push( make_pair( crLin , crCol ) );


        }else if ( s[ idx ] == 'N' ){
            mat [ crLin - 1 ] [ crCol ] = 2 ;
            mat [ crLin - 2 ] [ crCol ] = 1 ;
            crLin -= 2 ;
            stk.push( make_pair( crLin , crCol ) );
            val ++ ;
        }else if ( s[ idx ] == 'S' ){

            mat [ crLin + 1 ] [ crCol ] = 2 ;
            mat [ crLin + 2 ] [ crCol ] = 1 ;
            crLin += 2;
            stk.push( make_pair( crLin , crCol ) );
            val ++;
        }else if ( s[ idx ] == 'W' ){

            mat [ crLin  ] [ crCol - 1] = 2 ;
            mat [ crLin  ] [ crCol - 2 ] = 1 ;
            crCol -= 2;
            stk.push( make_pair( crLin , crCol ) );
            val ++;

        }else if ( s[ idx ] == 'E' ){

            mat [ crLin ] [ crCol + 1 ] = 2 ;
            mat [ crLin ] [ crCol + 2 ] = 1 ;
            crCol += 2;
            stk.push( make_pair( crLin , crCol ) );
            val ++ ;
        }else if ( s [ idx ] == ')'  ){
            stk.pop();
            stk.push( make_pair( crLin , crCol ) );
            val ++ ;
        }else if ( s[ idx ] == 0 || s[ idx ] == '$' ){
//            printf("NUU");
            return;
        }



        idx ++ ;
    }
}

void printMat1 (){


    for ( int i = 870 ; i <1150 ; i ++ ){
        for ( int j = 850 ; j < 1200 ; j++ ){
            if ( mat [ i ][ j ] == -1 ){
                printf("#");
            }else if ( mat [ i ][ j ] == 1 ){
                printf(".");
            }else if( mat [ i ] [ j ] == 3 ) {
                printf("X");
            }else {
                printf("|");
            }
            //printf("%d ",mat [ i ][ j ] );
        }
        printf("\n");
    }

}

void printMat (){


    for ( int i = 870 ; i <1150 ; i ++ ){
        for ( int j = 870 ; j < 1200 ; j++ ){
//            if ( mat [ i ][ j ] ==2 ){
//                printf("%4s","||");
//                continue ;
             if ( dist [ i ][ j ] == INF ){
                dist[ i ][ j ] = -1;
            }

            printf("%4d ",dist [ i ][ j ] );
        }
        printf("\n");
    }

}

void Lee (){


    for ( int i = 0 ; i < K ; i++ ){
        for ( int j = 0 ;j < K ; j++ ){
            dist[ i ][ j ] = INF ;
        }
    }

    int crLin = K/2 ;
    int crCol = K/2 ;

    queue< pair < int , int > > que ;

    que.push( make_pair( crLin , crCol ) );

    dist [ crLin ][ crCol ] = 0 ;

    while ( !que.empty() ){

        crLin = que.front().first;
        crCol = que.front().second;
        que.pop();

        if ( dist [ crLin ][ crCol ] >= 1000 ){
            noRooms++;
        }


        for ( int k = 0 ; k < 4 ; k++ ){
            int vecLin = crLin + dl [ k ] ;
            int vecCol = crCol + dc [ k ] ;

            if ( mat [ vecLin ][ vecCol ] == 2  ){
                vecLin += dl[ k ];
                vecCol += dc[ k ];

                if ( dist [ vecLin ][ vecCol ] > dist [ crLin ][ crCol ] + 1 && mat [ vecLin ][ vecCol ] == 1 ){
                    dist [ vecLin ][ vecCol ] = dist [ crLin ][ crCol ] + 1 ;
                    que.push( make_pair( vecLin , vecCol ) );
                    doorsMax = max ( doorsMax ,dist [ vecLin ][ vecCol ] );
                }

            }

        }

    }


}


int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);


    scanf("%s",s );

    int crLin = K/2 ;
    int crCol = K/2 ;

    memset( mat , -1 , sizeof mat) ;

    mat [ crLin ][ crCol ] = 3 ;

    int i = 1 ;

    parse( i , crLin , crCol );



    Lee(  );
    mat [ crLin ][ crCol ] = 3 ;

//    printMat1();
//    printMat();

    printf("%d\n",doorsMax);
    printf("%d",noRooms);
    return 0;
}
