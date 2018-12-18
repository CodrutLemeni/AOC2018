#include <bits/stdc++.h>

using namespace std;

const int N = 4000 ;


int getNumber ( int* index , char commandString[] ){
    int crNum = 0 ;

//    while( commandString[ *index ] == ' ' ){
//        (*index)++;
//    }
    while ( !(commandString[ *index ] >= '0' && commandString[ *index ] <= '9') ){
        (*index)++;
    }
    while( commandString[ *index ] >= '0' && commandString[ *index ] <= '9' ){
        crNum = crNum * 10 + commandString[ *index ] - '0';
        (*index)++;
    }

    return crNum ;

}

int allMinutes [ N ][ 60 ];
int totalMinutes [ N ];
int lastMinute [ N ];

struct Moment{
    int month ,day , minute ;
    int guard, type ;
    // 1 - wake
    // 2 - sleep
    // 3 - begin

};

int noMoments;
Moment allMoments [ N ];

Moment makeMoment ( int month , int day , int minute , int guard , int type ){
    Moment crMoment ;

    crMoment.minute = minute ;
    crMoment.day = day ;
    crMoment.month = month;
    crMoment.guard= guard;
    crMoment.type = type;

    return crMoment ;
}


bool cmp ( Moment a , Moment b ){

    if ( a.month != b.month ){
        return a.month < b.month ;
    }

    if ( a.day != b.day ){
        return a.day < b.day ;
    }

    return a.minute < b.minute ;

}

int main(){

    freopen("file.in","r",stdin);

    char tempChar ;
    int temp ;
    int month ,day , minute ;
    int guard, type ;
    char crStr [ 100 ];


    while( gets( crStr ) ){
        int i  = 0 ;

        month = getNumber( &i , crStr );
        month = getNumber( &i , crStr );
        day = getNumber( &i , crStr);
        minute = getNumber( &i , crStr);
        minute = getNumber( &i , crStr);

        guard = -1 ;
        if ( crStr [ 19 ] == 'w'){
            type = 1 ;
        }else if ( crStr [ 19 ] == 'f'){
            type = 2 ;
        }else if ( crStr [ 19 ] == 'G' ) {
            guard = getNumber( &i , crStr );
            type = 3 ;
        }

        allMoments [ noMoments ++ ] = makeMoment ( month , day , minute , guard , type );

    }

    sort ( allMoments , allMoments + noMoments , cmp );

//    for ( int i = 0 ; i < noMoments ; i++ ){
//
//        printf("%d %d %d \n",allMoments [ i ].month , allMoments [ i ].day , allMoments[ i ].minute );
//    }

    stack < int > myStk ;
    int crDay ;
    int crMonth ;


        int crGuard ;
    for ( int i = 0 ; i < noMoments ; i++ ){
        if ( allMoments [ i ].day != crDay || allMoments [ i ].month != crMonth ){
            while ( !myStk.empty() ){
                int crGuard = myStk.top();
                myStk.pop();
                totalMinutes [ crGuard ] +=  60 - lastMinute[ crGuard ] ;
                for ( int j = lastMinute[ crGuard ] ; j < 60 ; j++ ){
                    allMinutes [ crGuard ][ j ] ++ ;
                }
            }
        }

        crDay =  allMoments [ i ].day ;
        crMonth = allMoments [ i ].month ;


        if ( allMoments [ i ]. type == 3 ){
            crGuard = allMoments [ i ].guard ;
//            myStk.push( allMoments [ i ].guard );
        }else if ( allMoments [ i ]. type == 2 ){
//            crGuard = myStk.top() ;
            lastMinute [ crGuard ] = allMoments [ i ].minute ;
        }else{
//            crGuard = myStk.top() ;
//            myStk.pop();

            totalMinutes [ crGuard ] +=  allMoments [ i ].minute - lastMinute[ crGuard ] ;
            for ( int j = lastMinute[ crGuard ] ; j < allMoments [ i ].minute ; j++ ){
                allMinutes [ crGuard ][ j ] ++ ;
            }

        }

    }


    int maxTimes = 0 , bestGuard , bestMin ;
    for ( int i = 0 ; i < N ; i++ ){
        for  ( int j = 0 ; j < 60 ; j++ ){
            if ( allMinutes [ i ][ j ] > maxTimes ){
                maxTimes =  allMinutes [ i ][ j ];
                bestGuard = i ;
                bestMin = j ;
            }
        }


    }

    printf("%d",bestGuard * bestMin);



    return 0;
}
