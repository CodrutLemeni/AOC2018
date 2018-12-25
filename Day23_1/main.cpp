#include <bits/stdc++.h>

using namespace std;

const int N = 1100 ;


struct Robot{
    long long x , y , z , r ;
};


Robot allRobots [ N ];
int noRobots;

int rMax , bestPos ;
char s [ 100 ];

int pt ;
int getNum (){

    while ( s [ pt ] < '0' || s [ pt ] > '9' ){
        pt++;
    }

    int nr = 0 ;
    int neg = 0 ;

    while ( s [ pt ] >= '0' && s [ pt ] <= '9' ){
        if ( s [ pt - 1 ] == '-' ){
            neg = 1 ;
        }
        nr = nr * 10 + s [ pt ] - '0' ;
        pt++;
    }

    if ( neg ){
        nr = -nr ;
    }

    return nr ;

}


int verif ( int i ){

    return abs ( allRobots[ i ].x - allRobots [ bestPos ].x ) + abs ( allRobots[ i ].y - allRobots [ bestPos ].y ) + abs ( allRobots[ i ].z - allRobots [ bestPos ].z ) <= allRobots [ bestPos ].r ;

}

int main()
{
    freopen("file.in","r",stdin);

    int x , y , z , r ;

    while ( gets( s ) ){


        pt = 0 ;
        x = getNum ();
        y = getNum ();
        z = getNum ();
        r = getNum ();


        allRobots [ noRobots ].x = x ;
        allRobots [ noRobots ].y = y ;
        allRobots [ noRobots ].z = z ;
        allRobots [ noRobots++ ].r = r ;

        if ( r > rMax ){
            rMax = r ;
            bestPos = noRobots - 1 ;
        }


    }
    int sum = 0 ;
    for ( int i = 0 ; i < noRobots ; i++ ){
        sum += verif( i ) ;
    }

    printf("%d",sum);



    return 0;
}
