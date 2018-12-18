#include <bits/stdc++.h>

using namespace std;

const int N = 200 ;

struct Cadou{
    int crLin , crCol ;
    int dir ;
    // 0 - S
    // 1 - V
    // 2 - N
    // 3 - E
    int noGates ;
};

Cadou allCadou [ N ];
int noCadou ;

char mat [ N ][ N ];
int viz [ 20 ];
int noLin , noCol ;

int dl [] = { 1 , 0 , -1 , 0};
int dc [] = { 0 , -1 , 0 , 1 };

int solLin , solCol;

int verifCiocnire( ){


    for ( int i = 0 ; i < noCadou ; i++ ){
        for ( int j = i + 1  ; j < noCadou ; j++ ){
            if ( allCadou [ i ].crLin == allCadou [ j ].crLin && allCadou [ i ].crCol == allCadou [ j ].crCol ){
                solLin = allCadou [ i ].crLin ;
                solCol = allCadou [ j ].crCol ;
                return 0 ;
            }
        }
    }
    return 1 ;

}



int main()
{
    freopen("file.in","r",stdin);


    while ( gets( mat [ noLin ++ ] ) ){
        int crLen = strlen( mat [ noLin - 1  ] );
        noCol = max ( noCol , crLen );
    }

    for ( int i = 0 ; i < noLin ; i++ ){
        for ( int j = 0  ; j < noCol ; j++ ){
            if ( mat [ i ][ j ] == '>' ){
                allCadou [ noCadou ].crLin = i ;
                allCadou [ noCadou ].crCol = j ;
                allCadou [ noCadou ].noGates = 0 ;
                allCadou [ noCadou ].dir = 3 ;
                noCadou ++ ;
            }else if ( mat [ i ][ j ] == '<' ){
                allCadou [ noCadou ].crLin = i ;
                allCadou [ noCadou ].crCol = j ;
                allCadou [ noCadou ].noGates = 0 ;
                allCadou [ noCadou ].dir = 1 ;
                noCadou ++ ;
            }else if ( mat [ i ][ j ] == 'v' ){
                allCadou [ noCadou ].crLin = i ;
                allCadou [ noCadou ].crCol = j ;
                allCadou [ noCadou ].noGates = 0 ;
                allCadou [ noCadou ].dir = 0 ;
                noCadou ++ ;
            }else if ( mat [ i ][ j ] == '^' ){
                allCadou [ noCadou ].crLin = i ;
                allCadou [ noCadou ].crCol = j ;
                allCadou [ noCadou ].noGates = 0 ;
                allCadou [ noCadou ].dir = 2 ;
                noCadou ++ ;
            }
        }
    }


    while( verifCiocnire() ){
        for ( int i = 0 ; i < noCadou ; i++ ){
            allCadou [ i ].crLin += dl [ allCadou [ i ].dir ];
            allCadou [ i ].crCol += dc [ allCadou [ i ].dir ];

            if ( mat [ allCadou [ i ].crLin ][ allCadou [ i ].crCol ] == '+' ){
                if ( allCadou [ i ].noGates % 3 == 0 ){
                    allCadou [ i ].dir = ( allCadou [ i ].dir -1 + 4 ) % 4 ;
                    allCadou [ i ].noGates ++ ;
                }else if ( allCadou [ i ].noGates % 3 == 1 ){
                    allCadou [ i ].noGates ++ ;
                }else if ( allCadou [ i ].noGates % 3 == 2 ){
                    allCadou [ i ].dir = ( allCadou [ i ].dir + 1 ) % 4 ;
                    allCadou [ i ].noGates ++ ;
                }
            }else if ( mat [ allCadou [ i ].crLin ][ allCadou [ i ].crCol ] == '\\' ){
                if ( allCadou [ i ].dir == 3 ){
                    allCadou [ i ].dir  = 0 ;
                }else if ( allCadou [ i ].dir == 2 ){
                    allCadou [ i ].dir = 1 ;
                }else if ( allCadou [ i ].dir == 0  ){
                    allCadou [ i ].dir = 3 ;
                }else if ( allCadou [ i ].dir == 1  ){
                    allCadou [ i ].dir = 2 ;
                }
    // 0 - S
    // 1 - V
    // 2 - N
    // 3 - E
            }else if ( mat [ allCadou [ i ].crLin ][ allCadou [ i ].crCol ] == '/' ){
                if ( allCadou [ i ].dir == 2 ){
                    allCadou [ i ].dir  = 3 ;
                }else if ( allCadou [ i ].dir == 1 ){
                    allCadou [ i ].dir = 0 ;
                }else if ( allCadou [ i ].dir == 0 ){
                    allCadou [ i ].dir = 1 ;
                }else if ( allCadou [ i ].dir == 3 ){
                    allCadou [ i ].dir = 2 ;
                }

            }
            if ( verifCiocnire() == 0 ){
                break ;
            }
        }
    }


    printf("%d,%d",solCol, solLin);


    return 0;
}
