

#include <bits/stdc++.h>

using namespace std;

int score [ 500 ];
list < int > values ;
int noPlayers, noMarble ;

void next( list < int >::iterator& it ){
    it++;

    if ( it == values.end() ){
        it = values.begin();
    }

    //return it ;
}

void prev( list < int >::iterator& it ){


    if ( it == values.begin()  ){
        it = values.end();
    }
    it -- ;

    //return it ;
}



int main()
{
    freopen("file.in","r",stdin);

    char s [ 40 ];

    scanf("%d%s%s%s%s%s%d",&noPlayers ,s,s,s,s,s , &noMarble );
//
//    values [ 0 ] = 0 ;
//    values [ 1 ] = 1 ;

    values.insert( values.begin()  , 0 );


    auto crMarble = values.begin() ;




    for ( int i = 1 ; i < noMarble ; i++  ){
        if ( i % 23 != 0 ){

            int val = *crMarble;

            next( crMarble ) ;
            val = *crMarble;

            next( crMarble ) ;

            crMarble = values.insert( crMarble   , i );

        }else {
            score [ i % noPlayers ] += i ;

            int val = *crMarble;

            prev(crMarble);
            prev(crMarble);
            prev(crMarble);
            prev(crMarble);
            prev(crMarble);
            prev(crMarble);
            prev(crMarble);

            score [ i % noPlayers ] += *crMarble ;

            crMarble = values.erase( crMarble );

        }
    }

    int scMax = 0 ;
    for ( int i = 0 ; i < noPlayers ; i++ ){
        scMax = max ( scMax , score [ i ] );
    }

//    for ( auto it = values.begin() ; it != values.end() ; it ++ ){
//        printf("%d ",*it);
//    }
    printf("%d",scMax);





    return 0;
}
