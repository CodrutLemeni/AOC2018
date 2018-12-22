#include <bits/stdc++.h>

using namespace std;


long long v[] = {1,0,0,0,0,0};

int crRegister ;

struct Instr{

    char s [ 10 ] ;
    int a , b , c;

};

Instr allInstr [ 50 ];
int noInstr ;


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

    int ip = 0 ;

    int noRep = 0 ;

    while ( ip < noInstr && ip >=0 ){

        v [ crRegister ] = ip ;

        long long a = allInstr [ ip ].a;
        long long b = allInstr [ ip ].b;
        long long c = allInstr [ ip ].c;


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
        }else if (strcmp( allInstr [ ip ].s , "eqrr") == 0 ){
            if ( v [ a ] == v [ b ] ){
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

        }

        ip = v [ crRegister ];
        ip ++ ;

        noRep ++ ;

        if ( noRep == 5000 ){
            break;
        }

        printf("ip = %d : %I64d , %I64d , %I64d , %I64d , %I64d , %2I64d \n ",ip , v [ 0 ] , v [ 1 ], v[ 2 ] , v[ 3 ], v[ 4 ] , v [ 5 ] );

    }
//
//    int sum = 0 ;
//    for ( int i = 1 ; i <= 10551425 ; i++ ){
//        if ( 10551425 % i == 0 ){
//            sum += i ;
//        }
//    }
//    printf("%d",sum);

    return 0;
}
