#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 ;

char str [ N ];
char temp [ N ];

int main()
{
    freopen("file.in","r",stdin);

    scanf("%s",str);


//    for  ( int i = 0 ; i < len - 1  ; i++ ){
//        while ( i >= 0 && str [ i ] == str [ i + 1 ] ){
//            strcpy( str + i  , str + i + 2 );
//            i--;
//        }
//    }

    strcpy( temp , str );

    for ( int crLetter = 'a' ; crLetter <= 'z' ; crLetter++ ){
        strcpy( str , temp );

        int len = strlen( str );

        for  ( int i = 0 ; i < len - 1  ; i++ ){
            while ( tolower( str[ i ] ) == crLetter ){
                strcpy( str + i  , str + i + 1 );
                i--;
            }
        }
        len = strlen( str );
        for  ( int i = 0 ; i < len - 1  ; i++ ){
            while ( i >= 0 && (str [ i ] != str [ i + 1 ] && ( str [ i ] == toupper( str[ i + 1 ]) || str [ i ] == tolower( str [ i + 1 ] ) ) ) ){
                strcpy( str + i  , str + i + 2 );
                i--;
            }
        }
        printf("%d %c\n",strlen( str ) , crLetter);

    }

    return 0;
}
