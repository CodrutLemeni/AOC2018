#include <bits/stdc++.h>

using namespace std;

const int N = 2000;
const int NN = 1000 ;
const int INF = 1e9;


int noNum ;

queue < pair < int , int > > que ;

int dl [ ]={ -1, 0 ,1 ,0 };
int dc [ ]={ 0, 1 , 0 ,-1};

int mat [ N ][ N ] ;
int dist [ N ][ N ] ;
int viz [ N ];
int cnt[ N ];

vector < pair < int , int > > allPos;

int calcDist ( int a , int b , int x , int y ){
    int dist ;

    return abs ( a - x ) + abs ( y - b );

}

int main(){

    freopen("file.in","r",stdin);

    for ( int i = 0 ; i < N ; i++ ){
        for ( int j = 0 ; j < N ; j++ ){
            dist [ i ][ j ] = INF ;
            mat [ i ][ j ] = -1 ;
        }
    }

    int x , y ;
    char v ;
    while ( cin >> y >> v >> x ){
        //dist [ x ][ y ] = 0 ;

        x+= N/2;
        y+= N/2;

        mat [ x ][ y ] = noNum ;

        allPos.push_back ( make_pair( x , y ) );

        que.push( make_pair( x, y ));
        noNum ++ ;

    }


    for ( int i = 0 ; i < N ; i++ ){
        for ( int j = 0 ; j < N ; j++ ){

            for ( int crPos = 0 ; crPos < noNum ;crPos++ ){
                int crDist = calcDist( i , j  , allPos [ crPos].first , allPos[crPos].second  );

                if ( crDist < dist[ i ][ j ] ){
                    mat[ i ][ j ] = crPos;
                }else if ( crDist == dist[ i ][ j ] ){
                    mat [ i ][ j ] = -1 ;
                }
                dist[ i ][ j ] = min ( dist[ i ][ j ] , crDist );
            }
        }
    }



    for ( int i = 0 ; i < N ; i++ ){
        if ( mat [ 0 ][ i ] != -1 ){
            viz [ mat [ 0 ][ i ] ] = 1 ;
        }
        if ( mat [ N - 1 ][ i ] != -1 ){
            viz [ mat [ N - 1 ][ i ] ] = 1 ;
        }
        if ( mat [ i ][ 0 ] != -1 ){
            viz [ mat [ i ][ 0 ] ] = 1 ;
        }
        if ( mat [ i ][ N - 1 ] != -1 ){
            viz [ mat [ i ][ N - 1 ] ] = 1 ;
        }
    }

    for ( int i = 0 ; i < N ; i++ ){
        for ( int j = 0 ; j < N ; j++ ){
            if ( mat [ i ][ j ] != -1 )
                cnt [ mat [ i ][ j ] ]++;
        }
    }




    int valMax = 0 ;

    for  (int i = 0 ; i < N ; i++ ){

        if ( viz [ i ] ){
            continue;
        }

        valMax = max ( valMax , cnt [ i ] );

    }

    cout << valMax  ;

    return 0;
}
