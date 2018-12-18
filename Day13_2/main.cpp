

#include <bits/stdc++.h>

using namespace std;

const int N = 500 ;

struct Cadou{
    int crLin , crCol ;
    int dir ;
    // 0 - S
    // 1 - V
    // 2 - N
    // 3 - E
    int noGates ;
    int viz ;
};

Cadou allCadou [ N ];
int noCadou ,noViz;

char mat [ N ][ N ];
int noLin , noCol ;

int dl [] = { 1 , 0 , -1 , 0};
int dc [] = { 0 , -1 , 0 , 1 };

int solLin , solCol;

//void verifCiocnire3( ){
//
//
//    for ( int i = 0 ; i < noCadou ; i++ ){
//        if( viz [ i ] ){
//            continue ;
//        }
//        for ( int j = i + 1  ; j < noCadou ; j++ ){
//            if ( viz [ j ] ){
//                continue;
//            }
//            for ( int k = j + 1 ; k < noCadou ; k ++ ){
//                if ( allCadou [ i ].crLin == allCadou [ j ].crLin && allCadou [ i ].crCol == allCadou [ j ].crCol &&
//                     allCadou [ i ].crLin == allCadou [ k ].crLin && allCadou [ i ].crCol == allCadou [ k ].crCol){
//                        printf("sdasfsa");
//                }
//            }
//
//        }
//    }
//
//}
void verifCiocnire2( ){


    for ( int i = 0 ; i < noCadou ; i++ ){
        if( allCadou[ i ].viz ){
            continue ;
        }
        for ( int j = i + 1  ; j < noCadou ; j++ ){
            if ( allCadou [ j ].viz ){
                continue;
            }
            if ( allCadou [ i ].crLin == allCadou [ j ].crLin && allCadou [ i ].crCol == allCadou [ j ].crCol ){
                solLin = allCadou [ i ].crLin ;
                solCol = allCadou [ j ].crCol ;
                printf("P1:%d,%d\n",solCol,solLin);
                allCadou [ i ].crLin = N ;
                allCadou [ j ].crCol = N  ;
                allCadou [ i ].viz = 1 ;
                allCadou [ j ].viz = 1  ;

                noViz -= 2 ;
                break;
            }
        }
    }

}


bool cmp( Cadou a , Cadou b ){
    if( a.crLin == b.crLin ){
        return a.crCol < b.crCol;
    }
    return a.crLin < b.crLin;
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

    noViz = noCadou;
    while( noViz !=  1 ){
        sort( allCadou , allCadou + noCadou , cmp );
        for ( int i = 0 ; i < noCadou ; i++ ){
            if ( allCadou [ i ].viz ){
                continue;
            }
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
            verifCiocnire2();
        }
    }

    for ( int i = 0 ; i < noCadou ; i ++ ){
        if ( allCadou [ i ].viz == 0 ){
            printf("%d,%d",allCadou [ i ].crCol , allCadou [ i ].crLin);
        }
    }


    return 0;
}
//14,42
//88,48
//47,12
//110,76
//12,45
//88,84
//122,42
//146,95
//8,7
