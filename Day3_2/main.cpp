#include <bits/stdc++.h>

using namespace std;

const int N = 2000 ;

int dp [ N ][ N ];
int noFab;
char sir[ N ][ N ];



char getFirstLetter( int* index , char commandString[] ){

    while( commandString[ *index ] == ' ' ){
        (*index)++;
    }
    char temp = commandString[ (*index)++ ] ;

    return temp ;
}

int getNumber ( int* index , char commandString[] ){
    int crNum = 0 ;

    while( commandString[ *index ] == ' ' ){
        (*index)++;
    }
    if ( !(commandString[ *index ] >= '0' && commandString[ *index ] <= '9') ){
        return -1 ;
    }
    while( commandString[ *index ] >= '0' && commandString[ *index ] <= '9' ){
        crNum = crNum * 10 + commandString[ *index ] - '0';
        (*index)++;
    }

    return crNum ;

}

int main(){

    freopen("file.in","r",stdin);

    int leftCol, upLine ;
    int rightCol, downLine ;
    int id;
    char crch;

    int noSir = 0 ;
    while ( gets( sir[ noSir ++ ] ) ){

        int crIdx = 0;

        getFirstLetter( &crIdx , sir[ noSir - 1 ] );
        id = getNumber( &crIdx , sir[ noSir - 1 ] );
        getFirstLetter( &crIdx , sir[ noSir - 1 ] );

        leftCol = getNumber( &crIdx , sir[ noSir - 1 ]);
        getFirstLetter( &crIdx , sir[ noSir - 1 ]);
        upLine = getNumber( &crIdx , sir[ noSir - 1 ]);
        getFirstLetter( &crIdx , sir[ noSir - 1 ]);

        rightCol= getNumber( &crIdx , sir[ noSir - 1 ]);
        getFirstLetter( &crIdx , sir[ noSir - 1 ]);
        downLine = getNumber( &crIdx , sir[ noSir - 1 ]);


        rightCol += leftCol ;
        downLine += upLine ;

        leftCol++;
        upLine++;

        for ( int i = upLine ; i <= downLine ; i++ ){
            for ( int j = leftCol ; j<= rightCol ; j++ ){
                dp [ i ][ j ] ++ ;
                if ( dp [ i ][ j ] == 2 ){
                    noFab++;
                }
            }
        }

    }


    for ( int i = 0 ; i < noSir ; i++ ){
        int crIdx = 0;

        getFirstLetter( &crIdx , sir[ i ] );
        id = getNumber( &crIdx , sir[ i ] );
        getFirstLetter( &crIdx , sir[ i ] );

        leftCol = getNumber( &crIdx , sir[ i ]);
        getFirstLetter( &crIdx , sir[ i ]);
        upLine = getNumber( &crIdx , sir[ i ]);
        getFirstLetter( &crIdx , sir[ i  ]);

        rightCol= getNumber( &crIdx , sir[ i  ]);
        getFirstLetter( &crIdx , sir[ i  ]);
        downLine = getNumber( &crIdx , sir[ i ]);


        rightCol += leftCol ;
        downLine += upLine ;

        leftCol++;
        upLine++;

        int spy = 0 ;
        for ( int i = upLine ; i <= downLine ; i++ ){
            for ( int j = leftCol ; j<= rightCol ; j++ ){
                if ( dp [ i ][ j ] != 1 ){
                    spy = 1;
                }
            }
        }
        if ( spy == 0 ){
            printf("%d",id);
        }


    }

    return 0;
}
