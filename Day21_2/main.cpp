#include <bits/stdc++.h>

using namespace std;


long long v[] = { 16776274,0,0,0,0,0};

int crRegister ;
long long lastVal;


set < int > crSet ;

struct Instr{

    char s [ 10 ] ;
    int a , b , c;

};

Instr allInstr [ 50 ];
int noInstr ;
long long maxVal ;

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);

    scanf("#ip %d\n",&crRegister );

    char sir [ 10 ];
    int a , b, c , type ;

    while ( scanf("%s %d %d %d\n", sir , &a ,&b , &c ) != -1 ){
        Instr crInstr ;

        strcpy( allInstr [ noInstr ].s , sir );

        allInstr[ noInstr ].a = a;
        allInstr[ noInstr ].b = b;
        allInstr[ noInstr++ ].c = c;


    }

    int repMin = 1e9 ;

    for ( int i = 0 ; i < 1 ; i ++ ){
        long long ip = 0 ;

        long long noRep = 0 ;

        v[ 1 ] =v[ 2 ] =v[ 3 ] =v[ 4 ] =v[ 5 ] = 0 ;
        v [ 0 ] = i ;

        while ( ip < noInstr ){

            v [ crRegister ] = ip ;

            int a = allInstr [ ip ].a;
            int b = allInstr [ ip ].b;
            int c = allInstr [ ip ].c;


            if ( strcmp( allInstr [ ip ].s , "seti") == 0 ){
                v[ c ] = a ;
            }else if ( strcmp( allInstr [ ip ].s , "setr") == 0 ){
                v [ c ] = v[ a ];
            }else if ( strcmp( allInstr [ ip ].s , "addi") == 0 ){
                v[ c ] = v [ a ] + b ;
            }else if ( strcmp( allInstr [ ip ].s , "addr") == 0 ){
                v [ c ] = v [ a ] + v[ b ] ;
            }else if (strcmp( allInstr [ ip ].s , "mulr") == 0 ){
                v [ c ] = v [ a ] * v[ b ] ;
            }else if (strcmp( allInstr [ ip ].s , "muli") == 0 ){
                v [ c ] = v [ a ] * b  ;
            }else if (strcmp( allInstr [ ip ].s , "banr") == 0 ){
                v [ c ] = v [ a ] & v[ b ] ;
            }else if (strcmp( allInstr [ ip ].s , "bani") == 0 ){
                v [ c ] = v [ a ] & b  ;
            }else if (strcmp( allInstr [ ip ].s , "borr") == 0 ){
                v [ c ] = v [ a ] | v[ b ] ;
            }else if (strcmp( allInstr [ ip ].s , "bori") == 0 ){
                v [ c ] = v [ a ] | b  ;
            }else if (strcmp( allInstr [ ip ].s , "eqrr") == 0 ){
                if ( v [ a ] == v [ b ] ){
                    v [ c ] = 1 ;
                }else {
                    v [ c ] = 0 ;
                }
            }else if (strcmp( allInstr [ ip ].s , "eqri") == 0 ){
                if ( v [ a ] ==  b  ){
                    v [ c ] = 1 ;
                }else {
                    v [ c ] = 0 ;
                }
            }else if (strcmp( allInstr [ ip ].s , "eqir") == 0 ){
                if ( a  == v [ b ] ){
                    v [ c ] = 1 ;
                }else {
                    v [ c ] = 0 ;
                }
            }else if( strcmp( allInstr [ ip ].s , "gtrr") == 0  ){
                if ( v[ a ] > v[ b ] ){
                    v[ c ] = 1;
                }else{
                    v [ c ] = 0 ;
                }

            }else if( strcmp( allInstr [ ip ].s , "gtir") == 0  ){
                if (  a  > v[ b ] ){
                    v[ c ] = 1;
                }else{
                    v [ c ] = 0 ;
                }

            }else if( strcmp( allInstr [ ip ].s , "gtri") == 0  ){
                if ( v[ a ] >  b  ){
                    v[ c ] = 1;
                }else{
                    v [ c ] = 0 ;
                }

            }

            ip = v [ crRegister ];
            ip ++ ;

            noRep ++ ;


//
//            if ( ip == 29 ){
//                maxVal = max ( maxVal , v[ 1 ] );
//                if ( crSet.count( v [ 1 ] ) ){
//                    printf("%I64d\n",lastVal);
//                    printf("%I64d",crSet.size());
//                    return 0 ;
//                }
//                crSet.insert( v [ 1 ] );
//                lastVal = v[ 1 ] ;
//
//            }
            if ( ip == 29 ){
                maxVal = max ( maxVal , v[ 5 ] );
                if ( crSet.count( v [ 5 ] ) ){
                    printf("%I64d\n",lastVal);
                    printf("%I64d",crSet.size());
                    return 0 ;
                }
                crSet.insert( v [ 5 ] );
                lastVal = v[ 5 ] ;

            }


//            printf("ip = %I64d, %I64d %I64d %I64d %I64d %I64d %I64d \n ",ip , v [ 0 ] , v [ 1 ], v[ 2 ] , v[ 3 ], v[ 4 ] , v [ 5 ] );

        }


    }

    printf("%I64d",maxVal );

    //printf("%d",v[ 0 ] );

    return 0;
}
