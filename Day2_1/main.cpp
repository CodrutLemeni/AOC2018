#include <bits/stdc++.h>

using namespace std;

const int N = 100 ;
const int SIGMA = 30 ;

int noTwo , noThree ;

char crWord[ N ];
int countAppearance [ SIGMA ];

int main(){

    freopen("file.in","r",stdin);

    int i = 0 ;
    while ( cin >> crWord ){
         i++ ;

        memset( countAppearance , 0 , sizeof countAppearance );

        for ( int i = 0 ; crWord [ i ] ; i++ ){

            countAppearance [ crWord [ i ] - 'a' ]++;

        }

        int crTwo = 0 , crThree = 0 ;
        for ( int i = 'a' ; i <= 'z' ; i++ ){
            if( countAppearance [ i - 'a' ] == 2 ){
                crTwo ++;
            }else if( countAppearance [ i - 'a' ] == 3 ){
                crThree ++;
            }
        }

        noTwo = noTwo + ( crTwo != 0 );
        noThree = noThree + ( crThree != 0 );

    }

    cout << noTwo * noThree ;
//    cout << i;

    return 0;
}
