#include <bits/stdc++.h>

using namespace std;



char crSir [ 20 ];
int v[ 5 ];
int t [ 5 ];
int after [ 5 ];
int noReg;

int type [ 20 ];
int viz [ 20 ];

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

//    type [ 10 ] = 0;
//    viz[ 0 ] = 1 ;

    int noTest = 0 ;
    for ( int i = 0 ; i < 777 ; i++ ){
        int code , a , b, c;
        noTest ++ ;

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
        int crType ;


        if ( viz [ 0 ] == 0  ){
            cpy();
            t [ c ] = t [ a ] + t [ b ];
            if ( isEqual() ){
                crType=0;
                noSame ++ ;
            }
        }

        if ( viz [ 1 ] == 0  ){

            cpy();
            t [ c ] = t [ a ] + b ;
            if ( isEqual() ){
                crType=1;
                noSame ++ ;
            }
        }


        if ( viz [ 2 ] == 0  ){

            cpy();
            t [ c ] = t[ a ] *t [ b ];
            if ( isEqual() ){
                crType=2;
                noSame ++ ;
            }
        }

        if ( viz [ 3 ] == 0  ){

            cpy();
            t [ c ] = t[ a ] * b ;
            if ( isEqual() ){
                crType=3;
                noSame ++ ;
            }
        }
        if ( viz [ 4 ] == 0  ){

            cpy();
            t [ c ] = t[ a ] & t [ b ];
            if ( isEqual() ){
                crType=4;
                noSame ++ ;
            }
        }
        if ( viz [ 5 ] == 0  ){
            cpy();
            t [ c ] = t[ a ] &  b ;
            if ( isEqual() ){
                noSame ++ ;
                crType=5;

            }
        }
        if ( viz [ 6 ] == 0  ){
            cpy();
            t [ c ] = t[ a ] | t[ b ] ;
            if ( isEqual() ){
                noSame ++ ;
                crType = 6 ;
            }
        }
        if ( viz [ 7 ] == 0  ){
            cpy();
            t [ c ] = t[ a ] |  b  ;
            if ( isEqual() ){
                noSame ++ ;
                crType = 7 ;
            }

        }
        if ( viz [ 8 ] == 0  ){
            cpy();
            t [ c ] = t[ a ]   ;
            if ( isEqual() ){
                noSame ++ ;
                crType = 8 ;
            }
        }
        if ( viz [ 9 ] == 0  ){
            cpy();
            t [ c ] =  a   ;
            if ( isEqual() ){
                noSame ++ ;
                crType = 9 ;
            }
        }

        if ( viz [ 10 ] == 0  ){
            cpy();
            if ( a  > t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }
            if ( isEqual() ){
                noSame ++ ;
                crType = 10;
            }
        }

        if ( viz [ 11 ] == 0  ){
            cpy();
            if ( t [ a ] >  b  ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }
            if ( isEqual() ){
                noSame ++ ;
                crType = 11;
            }
        }

        if ( viz [ 12 ] == 0  ){
            cpy();
            if ( t [ a ]  > t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }
            if ( isEqual() ){
                noSame ++ ;
                crType = 12;
            }
        }
        if ( viz [ 13 ] == 0  ){
            cpy();
            if ( a  == t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }
            if ( isEqual() ){
                noSame ++ ;
                crType = 13;
            }
        }
        if ( viz [ 14 ] == 0  ){
            cpy();
            if ( t [ a ] ==  b  ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }
            if ( isEqual() ){
                noSame ++ ;
                crType = 14;
            }
        }
        if ( viz [ 15 ] == 0  ){
            cpy();
            if ( t [ a ]  == t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }
            if ( isEqual() ){
                noSame ++ ;
                crType = 15;
            }
        }
        if ( noSame == 1 ){
            type [ code ] = crType ;
            viz [ crType ] = 1 ;
        }

    }


    t[ 0 ] = t [ 1 ] = t [ 2 ] = t[ 3 ] = 0;

    int code , a , b, c;
    while ( cin >> code >> a >> b >> c ){

        if ( type [ code ] == 0  ){
            t [ c ] = t [ a ] + t [ b ];

        }

        if ( type [ code ] == 1  ){

            t [ c ] = t [ a ] + b ;

        }


        if ( type [ code ] == 2  ){

            t [ c ] = t[ a ] *t [ b ];

        }

        if ( type [ code ] == 3  ){

            t [ c ] = t[ a ] * b ;

        }
        if ( type [ code ] == 4  ){

            t [ c ] = t[ a ] & t [ b ];

        }
        if ( type [ code ] == 5  ){
            t [ c ] = t[ a ] &  b ;

        }
        if ( type [ code ] == 6  ){
            t [ c ] = t[ a ] | t[ b ] ;

        }
        if ( type [ code ] == 7  ){
            t [ c ] = t[ a ] |  b  ;


        }
        if ( type [ code ] == 8  ){
            t [ c ] = t[ a ]   ;

        }
        if ( type [ code ] == 9  ){
            t [ c ] =  a   ;

        }

        if ( type [ code ] == 10  ){
            if ( a  > t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }

        }

        if ( type [ code ] == 11  ){
            if ( t [ a ] >  b  ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }

        }

        if ( type [ code ] == 12  ){
            if ( t [ a ]  > t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }

        }
        if ( type [ code ] == 13 ){
            if ( a  == t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }

        }
        if ( type [ code ] == 14  ){
            if ( t [ a ] ==  b  ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }

        }
        if ( type [ code ] == 15  ){
            if ( t [ a ]  == t [ b ] ){
                t[ c ] = 1 ;
            }else{
                t [ c ] = 0 ;
            }

        }
    }

    printf("%d",t[ 0 ] );


    return 0;
}
