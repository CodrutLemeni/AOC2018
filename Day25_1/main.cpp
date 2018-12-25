#include <bits/stdc++.h>

using namespace std;


struct Stea {
    int x , y , z , t ;
};

Stea allStars [ 2000 ];
int noStars ;

vector < int > allMuc [ 2000 ];
int viz [ 2000 ];

int calcDist ( int a , int b ){

    return abs ( allStars [ a ].x - allStars [ b ].x ) +abs ( allStars [ a ].y - allStars [ b ].y ) +abs ( allStars [ a ].z - allStars [ b ].z ) +abs ( allStars [ a ].t - allStars [ b ].t ) ;

}



void dfs ( int crNode ){

    viz [ crNode ] = 1 ;

    for ( int vec : allMuc [ crNode ] ){

        if ( viz [ vec ] == 0 ){
             dfs( vec );
        }

    }

}


int main(){

    freopen("file.in","r",stdin);

    int x , y ,z , t ;
    while ( scanf("%d,%d,%d,%d\n",&x,&y,&z,&t) != -1 ){
        allStars [ noStars ].x = x ;
        allStars [ noStars ].y = y ;
        allStars [ noStars ].z = z ;
        allStars [ noStars++ ].t = t ;
    }

    for ( int i = 0 ; i < noStars ; i ++ ){
        for ( int j = i + 1 ; j < noStars ; j++ ){
            int crDist = calcDist ( i , j ) ;

            if ( crDist <=  3 ){
                allMuc [ i ].push_back ( j );
                allMuc [ j ].push_back ( i );

            }

        }
    }

    int noConst = 0 ;

    for ( int i = 0 ; i < noStars ; i++ ){
        if ( viz [ i ] == 0 ){
            dfs ( i );
            noConst ++ ;
        }
    }

    printf("%d",noConst);


    return 0;
}
