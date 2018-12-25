#include <bits/stdc++.h>

using namespace std;

const int N = 1100 ;
const int X = 10 ;


struct Robot{
    long long x , y , z , r ;
};


Robot allRobots [ N ];
int noRobots;

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

int POW = 1e7 ;


int isInside ( Robot crRobot , int i ){
    return abs ( allRobots[ i ].x/POW - crRobot.x ) + abs ( allRobots[ i ].y/POW - crRobot.y ) + abs ( allRobots[ i ].z/POW - crRobot.z ) <= allRobots [ i ].r/POW ;
}


int howMany( Robot crRobot ){
    int sol = 0 ;

    for  ( int i = 0 ; i < noRobots ; i ++ ){
        sol += isInside( crRobot , i );
    }
    return sol ;
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

    }

    Robot crRobot ;
    crRobot.x = 0 ;
    crRobot.y = 0 ;
    crRobot.z = 0 ;

    int bestVal = 0 ;
    Robot bestRobot ;

    while ( POW  ){
        bestVal = 0 ;
        for (  long long i = crRobot.x - X ; i < crRobot.x + X ; i++ ){
            for ( long long j = crRobot.y - X ; j < crRobot.y + X ; j++ ){
                for  ( long long z = crRobot.z - X ; z < crRobot.z + X ; z++ ){
                    Robot rb ;
                    rb.x = i ;
                    rb.y = j ;
                    rb.z = z ;

                    int crVal = howMany( rb );

                    if ( crVal > bestVal ){
                        bestVal = crVal ;
                        bestRobot = rb ;
                    }else if ( crVal == bestVal ){
                        if ( i + j + z < bestRobot.x + bestRobot.y + bestRobot.z ){
                            bestRobot = rb ;
                        }
                    }
                }
            }
        }
        POW /= 10 ;

        if ( POW == 0 ){
            break ;
        }
        crRobot = bestRobot ;
        crRobot.x *= 10 ;
        crRobot.y *= 10 ;
        crRobot.z *= 10 ;

        printf("%I64d %I64d %I64d\n",crRobot.x , crRobot.y , crRobot.z );

    }

    printf("%I64d\n", bestRobot.x + bestRobot.y + bestRobot.z );
    printf("%d", bestVal );



    return 0;
}
