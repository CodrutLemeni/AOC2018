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


int noPct;

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


            int crDist = 0 ;
            for ( int crPos = 0 ; crPos < noNum ;crPos++ ){
                crDist += calcDist( i , j  , allPos [ crPos].first , allPos[crPos].second  );
            }
            if ( crDist < 10000 ){
                noPct ++;
            }
        }
    }

    printf("%d",noPct);


    return 0;
}
