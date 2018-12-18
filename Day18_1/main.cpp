#include <bits/stdc++.h>

using namespace std;

const int N = 60 ;

char mat [ 2 ] [ N ][ N ] ;
int noLin , noCol ;


int dl [] = { -1 , -1 ,-1 ,0 ,1 ,1 , 1, 0 };
int dc [] = { -1 , 0 , 1 ,1 ,1 ,0 ,-1, -1};

void printMat ( int x ){

    for ( int i = 0 ; i < noLin ; i++ ){
        printf("%s\n",mat[ x ][ i ] );
    }
    printf("\n\n");
}


int main()
{
    freopen("file.in","r",stdin);

    for ( noLin = 0 ; gets( mat [ 0 ][ noLin ] ) ; noLin ++ ){
        int len = strlen( mat [ 0 ][ noLin - 1 ] ) ;
        noCol = max ( noCol , len );
    }

    int cr = 1 ;
    int old = 0 ;

    for  ( int noDays = 0 ; noDays < 1000000000 ; noDays ++  ){

        for ( int i = 0 ; i < noLin ; i++ ){
            for ( int j = 0 ; j < noCol ; j++ ){

                int noGround = 0 , noTrees = 0 , noLumber = 0 ;
                for ( int k = 0 ; k < 8 ; k ++ ){
                    int x = i + dl [ k ];
                    int y = j + dc [ k ];

                    if ( x < 0 || y < 0 ){
                        continue;
                    }

                    if ( mat [ old ][ x ][ y ] == '.' ){
                        noGround ++ ;
                    }else if ( mat [ old ][ x ][ y ] == '|'){
                        noTrees ++ ;
                    }else if ( mat [ old ][ x ][ y ] == '#'){
                        noLumber ++ ;
                    }


                }
                mat [ cr][i][ j ] = mat [ old ][ i ][ j ];


                if ( mat [ old ][ i ][ j ] == '.' && noTrees >= 3  ){
                    mat [ cr ][ i ][ j ] = '|';
                }else if ( mat [ old ][ i ][ j ] == '|' && noLumber >= 3 ){
                    mat [ cr ][ i ][ j ] = '#';
                }else if ( mat [ old ][ i ] [ j ] =='#' && ( noLumber == 0 || noTrees == 0 ) ){
                    mat [ cr ][ i ][ j ] = '.';
                }
            }
        }

        //printMat( cr );

        cr = !cr ;
        old = !old ;
    }


    int noTree = 0 , noLumber = 0  ;
    for ( int i = 0 ; i < noLin ; i++ ){
        for ( int j = 0 ; j < noCol ; j ++ ){
            if ( mat [ old ][ i ][ j ] == '#' ){
                noLumber ++ ;
            }else if ( mat [ old ][ i ][ j ] == '|' ){
                noTree++;
            }
        }
    }

    printf("%d",noTree * noLumber );



    return 0;
}
