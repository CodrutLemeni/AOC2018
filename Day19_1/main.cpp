#include <bits/stdc++.h>

using namespace std;


int v[] = { 1,0,0,0,0,0};

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

    int noRep ;

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

        if ( noRep == 100 ){
            break;
        }

        printf("ip = %d, %d %d %d %d %d %d \n ",ip , v [ 0 ] , v [ 1 ], v[ 2 ] , v[ 3 ], v[ 4 ] , v [ 5 ] );

    }
    printf("%d",v[ 0 ] );

    return 0;
}
