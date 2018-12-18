#include <bits/stdc++.h>

using namespace std;

vector < int > allRec ;
int no1 ;
int rec1 , rec2 ;
int a ;

int main(){

    freopen("file.in","r",stdin);

    scanf("%d",&a);

    allRec.push_back( 3 );
    allRec.push_back( 7 );

    rec1 = 0 , rec2 = 1 ;

    while ( allRec.size() <a + 10){
        int crRec = allRec [ rec1 ] + allRec [ rec2 ];


        if ( crRec % 10 == 1 ){
            no1 ++ ;
        }
        if ( crRec / 10 == 1 ){
            no1 ++ ;
        }
        if ( crRec >= 10 ){
            allRec.push_back( crRec / 10 );
        }
        allRec.push_back( crRec % 10 );


        rec1 = ( rec1 + allRec [ rec1 ]  + 1 ) % allRec.size()  ;
        rec2 = ( rec2 + allRec [ rec2 ]  + 1 ) % allRec.size()  ;

    }

    for ( int i = a  ; i <= a + 9  ; i++ ){
        printf("%d",allRec [ i ] );
    }
//    for ( int i = 0 ; i < allRec.size() ; i++ ){
//        printf("%d",allRec [ i ] );
//    }



    return 0;
}
