

#include <bits/stdc++.h>

using namespace std;

long long score [ 500 ];
list < long long > values ;
int noPlayers, noMarble ;

void next( list < long long >::iterator& it ){
    it++;

    if ( it == values.end() ){
        it = values.begin();
    }

    //return it ;
}

void prev( list < long long >::iterator& it ){


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
    noMarble *= 100;

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

    long long scMax = 0 ;
    for ( int i = 0 ; i < noPlayers ; i++ ){
        scMax = max ( scMax , score [ i ] );
    }

//    for ( auto it = values.begin() ; it != values.end() ; it ++ ){
//        printf("%d ",*it);
//    }
    printf("%I64d",scMax);





    return 0;
}
