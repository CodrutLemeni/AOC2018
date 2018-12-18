#include <bits/stdc++.h>

using namespace std;

const int N = 100000 ;

struct Point{
    int x , y , vitX , vitY ;

};

int noPoints ;
Point allPoints [ N ];

int CalcMaxDistX (){
    int minPos = allPoints [ 0 ].x , maxPos = allPoints [ 0 ].x ;

    for  ( int i = 1 ; i < noPoints ; i++ ){
        minPos = min ( minPos , allPoints [ i ].x );
        maxPos = max ( maxPos , allPoints [ i ].x );
    }

    return maxPos - minPos ;


}

int mat [ 1000 ][ 1000 ];

void makeAStep(){

    for ( int i = 0 ; i < noPoints ; i++ ){

        allPoints [ i ].x += allPoints [ i ].vitX ;
        allPoints [ i ].y += allPoints [ i ].vitY ;

    }

}

void makeAStepBack(){

    for ( int i = 0 ; i < noPoints ; i++ ){

        allPoints [ i ].x -= allPoints [ i ].vitX ;
        allPoints [ i ].y -= allPoints [ i ].vitY ;

    }

}

int main()
{

    freopen("file.in","r",stdin);

    int x , y , vitX , vitY ;

    while ( scanf("position=< %d,  %d> velocity=< %d,  %d>\n",&x,&y,&vitX,&vitY ) != EOF ){
        if ( x == N ){
            break;
        }

        Point crPoint;

        crPoint.x = x ;
        crPoint.y = y ;
        crPoint.vitX = vitX ;
        crPoint.vitY = vitY ;

        allPoints [ noPoints ++ ] = crPoint ;
        x = N ;
    }

    int crDist = CalcMaxDistX() ;
    makeAStep() ;

    while ( crDist > CalcMaxDistX() ){
        crDist = CalcMaxDistX() ;

        makeAStep() ;
    }
    makeAStepBack();

    for ( int i = 0 ; i < noPoints; i++ ){
        printf("%d %d\n",allPoints [ i ].x , allPoints [ i ].y);

        mat [ allPoints [ i ].x + 10 ][ allPoints [ i ].y + 10 ] = 1;

    }

    int minX = N , minY = N ;
    for ( int i = 0 ; i < noPoints; i++ ){
        minX = min ( minX , allPoints [ i ].x);
        minY = min ( minY , allPoints [ i ].y);

    }

    for  (int i = minX ; i < 300 ; i++ ){
        for ( int j = minY ; j < 200 ; j ++ ){
//            cout << mat [ i ][ j ];
            if  ( mat [ i ][ j ] == 0 ){
                cout << ' ';
            }else{
                cout<<'#';
            }

        }
        cout << '\n';
    }



    return 0;
}
