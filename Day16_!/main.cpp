#include <bits/stdc++.h>

using namespace std;



char crSir [ 20 ];
int v[ 5 ];
int t [ 5 ];
int after [ 5 ];
int noReg;

void cpy(){
    memcpy(  t , v , sizeof t );

}

int isEqual (){

    for ( int i = 0 ; i < 4 ; i ++ ){
        if ( t [ i ] != after[ i ]){
            return 0 ;
        }
    }

    return 1 ;
}

int main()
{

    freopen("file.in","r",stdin);

    while ( 3 ){
        int code , a , b, c;

        if ( scanf("%s",crSir) ==EOF ){
            break;
        }

        if ( crSir [ 0 ] != 'B' ){
            break;
        }
        scanf(" [%d, %d, %d, %d]\n",&v[ 0 ] ,&v[ 1 ],&v[ 2 ],&v [ 3 ]);


        scanf("%d %d %d %d\n",&code , &a,&b,&c);
        scanf("After: [%d, %d, %d, %d]\n\n",&after [ 0 ] , &after [ 1 ] , &after [ 2 ] , &after [ 3 ] );

        int noSame = 0;

        cpy();
        t [ c ] = t [ a ] + t [ b ];
        if ( isEqual() ){
            noSame ++ ;
        }

        cpy();
        t [ c ] = t [ a ] + b ;
        if ( isEqual() ){
            noSame ++ ;
        }

        cpy();
        t [ c ] = t[ a ] *t [ b ];
        if ( isEqual() ){
            noSame ++ ;
        }
        cpy();
        t [ c ] = t[ a ] * b ;
        if ( isEqual() ){
            noSame ++ ;
        }
        cpy();
        t [ c ] = t[ a ] & t [ b ];
        if ( isEqual() ){
            noSame ++ ;
        }
        cpy();
        t [ c ] = t[ a ] &  b ;
        if ( isEqual() ){
            noSame ++ ;
        }
        cpy();
        t [ c ] = t[ a ] | t[ b ] ;
        if ( isEqual() ){
            noSame ++ ;
        }
        cpy();
        t [ c ] = t[ a ]   ;
        if ( isEqual() ){
            noSame ++ ;
        }
        cpy();
        t [ c ] =  a   ;
        if ( isEqual() ){
            noSame ++ ;
        }

        cpy();
        if ( a  > t [ b ] ){
            t[ c ] = 1 ;
        }else{
            t [ c ] = 0 ;
        }
        if ( isEqual() ){
            noSame ++ ;
        }

        cpy();
        if ( t [ a ] >  b  ){
            t[ c ] = 1 ;
        }else{
            t [ c ] = 0 ;
        }
        if ( isEqual() ){
            noSame ++ ;
        }

        cpy();
        if ( t [ a ]  > t [ b ] ){
            t[ c ] = 1 ;
        }else{
            t [ c ] = 0 ;
        }
        if ( isEqual() ){
            noSame ++ ;
        }
        cpy();
        if ( a  == t [ b ] ){
            t[ c ] = 1 ;
        }else{
            t [ c ] = 0 ;
        }
        if ( isEqual() ){
            noSame ++ ;
        }

        cpy();
        if ( t [ a ] ==  b  ){
            t[ c ] = 1 ;
        }else{
            t [ c ] = 0 ;
        }
        if ( isEqual() ){
            noSame ++ ;
        }

        cpy();
        if ( t [ a ]  == t [ b ] ){
            t[ c ] = 1 ;
        }else{
            t [ c ] = 0 ;
        }
        if ( isEqual() ){
            noSame ++ ;
        }

        if ( noSame >= 3 ){
            noReg ++;
        }



    }

    printf("%d",noReg);
    return 0;
}
