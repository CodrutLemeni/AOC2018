#include <bits/stdc++.h>

using namespace std;

const int SIGMA = 30 ;

char sir[ 500 ];

vector < int > muc [ 30 ];

priority_queue < int > que ;

int grad [ 50 ];
int viz [ 50 ] ;



int main()

{
    freopen("file.in","r",stdin);

    while ( gets( sir ) ){
//        printf("%c %c\n",sir [5 ],sir [ 36]);

        int x = sir [ 5 ]-'A';
        int y = sir [ 36 ]-'A';

        muc [ x ].push_back( y );
        grad [ y ]++;
        viz[ y ] = 1 ;
        viz[ x ] = 1 ;
    }


    for ( int i = 0 ; i < 'Z' - 'A' ; i++ ){
        if ( grad [ i ] == 0 && viz[ i ] ){
            que.push( -i );
        }
    }

    while ( !que.empty() ){
        int crNode = -que.top();
        que.pop();

        printf("%c",crNode+'A');

        for ( int vec : muc [ crNode ]){
            grad [ vec ]--;
            if ( grad [ vec] == 0 ){
                que.push( -vec );
            }

        }

//        sort_que();

    }


    return 0;
}
