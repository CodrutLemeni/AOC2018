#include <bits/stdc++.h>

using namespace std;

const int W = 5 ;
const int N = 50 ;

char sir[ 500 ];

vector < int > muc [ N ];

priority_queue < int > que ;

int grad [ N ];
int viz [ N ] ;
int crt [ N ] ;

int workers[ W ];
int task [ W ];

int main()

{
    freopen("file.in","r",stdin);


    memset( viz , -1 , sizeof viz );

    while ( gets( sir ) ){

        int x = sir [ 5 ]-'A';
        int y = sir [ 36 ]-'A';

        muc [ x ].push_back( y );
        grad [ y ]++;

        viz [ x ] = viz [ y ] = 0 ;

    }


    for ( int i = 0 ; i <= 'Z' - 'A' ; i++ ){
        if ( grad [ i ] == 0 && viz[ i ] == 0 ){
            viz [ i ] = 1 ;
        }
    }


    for ( int i = 0 ; i <= 'z'-'a' ; i++ ){
        crt [ i ] = 61 + i ;
    }


    for ( int i = 0 ; i < W ; i++ ){
        task[ i ] = -1;
    }

    int noSol = 0 ;
    int clk = 0 ;
    while ( noSol != 26){

        for ( int crWorker = 0 ; crWorker < W ; crWorker++ ){
            if ( workers [ crWorker ] == 0 ){
                if ( viz [ task [ crWorker ] ] == 2 ){
                    int crTask = task [ crWorker ];
                    noSol++;
                    viz [ crTask ] = 3 ;

                    for ( int vec : muc [ crTask ] ){
                        grad [ vec ]--;

                        if ( grad [ vec ] == 0 ){
                            viz [ vec ] = 1 ;
                        }
                    }
                }
            }
        }

        for ( int crWorker = 0 ; crWorker < W ; crWorker ++ ){
            if ( workers [ crWorker ] == 0 ){
                for ( int crTask = 0 ; crTask <= 'z'-'a' ;crTask ++ ){
                    if ( viz [ crTask ] == 1 ){
                        viz [ crTask ] = 2 ;
                        task [ crWorker ] = crTask ;
                        workers [ crWorker ] = crt [ crTask ];
                        break ;
                    }
                }
            }

            if ( workers [ crWorker ] != 0 ){
                workers [ crWorker ] --;
            }

        }

        if ( noSol == 26 ){
            break;
        }

        clk ++;

    }

    printf("%d",clk);




    return 0;
}
