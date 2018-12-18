
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

    while ( 3 ){
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

        if ( allRec.size() > 5 ){
            int n = allRec.size() - 1 ;


            int x = allRec[ n - 1 ] +allRec[ n - 2 ] * 10 +allRec[ n - 3 ]* 100 +allRec[ n - 4 ] * 1000 +allRec[ n - 5 ] * 10000+allRec[ n - 6 ] * 100000 ;

            if ( a == x ){
                printf("%d",n-6);
                return 0 ;
            }
            n++ ;
            x = allRec[ n - 1 ] +allRec[ n - 2 ] * 10 +allRec[ n - 3 ]* 100 +allRec[ n - 4 ] * 1000 +allRec[ n - 5 ] * 10000+allRec[ n - 6 ] * 100000 ;

            if ( a == x ){
                printf("%d",n-6);
                return 0 ;
            }
        }

    }





    return 0;
}
