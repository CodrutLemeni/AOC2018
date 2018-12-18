#include <bits/stdc++.h>

using namespace std;


const int N = 4000;

int mat [ N ][ N ];
int linMax , linMin = N ;

stack < pair < int , int > > allRes ;


void printMat(){

    for ( int i = 0 ; i <= linMax + 1 ;i++ ){
        for ( int j = 450 ; j < 800 ; j++ ){
            printf("%2d",mat [ i ][ j ] );
        }
        printf("\n");
    }
}


void addWater( ){

    int crLin , crCol ;

    crLin = allRes.top().first ;
    crCol = allRes.top().second ;

    allRes.pop();




    mat [ crLin ][ crCol ] = 2 ;

    if ( crLin > linMax ){
        return;
    }
    if ( crLin == linMax ){
        mat [ crLin ][ crCol ] = 1 ;
        return ;
    }
    if ( mat [ crLin + 1 ][ crCol ] == 0 ){
        allRes.push(make_pair( crLin + 1 , crCol ) );
        addWater();
    }

    if ( mat [ crLin + 1 ][ crCol ] == 1 ){
        mat [ crLin ][ crCol ] = 1 ;
        return;
    }

    int spy = 0;

    int t = crCol ;
    while ( mat [ crLin ] [ t - 1 ] == 0 && ( mat [ crLin + 1 ][ t - 1 ] == -1 || mat [ crLin + 1 ][ t - 1 ] == 2 )   ){
        t -- ;
        mat [ crLin ][ t ] = 2 ;
    }

    while ( mat [ crLin + 1 ] [ t - 1 ] == 0 && mat [ crLin  ][ t - 1 ] == 0 ){
        spy = 1;
        allRes.push( make_pair( crLin , t - 1 ));
        addWater();

        if ( mat [ crLin + 1 ] [ t - 1 ] == 1 ){
            mat [ crLin ][ t - 1 ] = 1;
            break;
        }else{
            mat [ crLin ][ t - 1 ] = 2 ;
        }
        t--;
    }

    while ( mat [ crLin ] [ crCol + 1 ] == 0 && ( mat [ crLin + 1 ][ crCol + 1 ] == -1 || mat [ crLin + 1 ][ crCol + 1 ] == 2 )   ){
        crCol++ ;
        mat [ crLin ][ crCol ] = 2 ;
    }

    while ( mat [ crLin + 1 ] [ crCol + 1 ] == 0 && mat [ crLin  ][ crCol + 1 ] == 0 ){
        spy = 1;
        allRes.push( make_pair( crLin , crCol + 1 ));
        addWater();

        if ( mat [ crLin + 1 ] [ crCol + 1 ] == 1 ){
            mat [ crLin ][ crCol + 1 ] = 1;
            break;
        }else{
            mat [ crLin ][ crCol + 1] = 2 ;
        }
        crCol++;
    }

    if ( mat [ crLin ] [ t - 1  ] != 1 && mat [ crLin ] [ crCol + 1  ] != 1  ){
        spy = 0;
    }



    if ( spy == 1 ){
        for ( int i = t   ; i <= crCol  ; i++ ){
            mat[ crLin ][ i ] = 1 ;
        }
    }

}



int main(){

    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);


    int a , bStart , bEnd ;
    char crChar , t ;



    while( scanf("%c=%d, %c=%d..%d\n",&crChar ,&a ,&t, &bStart, &bEnd) != -1 ){

        if ( crChar == 'x' ){
            linMax = max ( linMax , bEnd );
            linMin = min ( linMin , bStart );
            for ( int i = bStart ; i <= bEnd ; i++ ){
                mat [ i ][ a ] = -1;
            }
        }else{
            linMin = min ( linMin, a );
            linMax = max ( linMax , a );
            for ( int i = bStart ; i <= bEnd ; i++ ){
                mat [ a ][ i ] = -1;
            }
        }
    }

    allRes.push( make_pair( 0, 500 ) );
//    printMat();

    addWater();


    int noWater = 0 ;
    //printf("%d %d\n",linMin , linMax);
    for ( int i = linMin ; i <= linMax ; i++ ){
        for ( int j = 0 ; j < N ; j++ ){
            if ( mat [ i ] [ j ] == 2 ){
                noWater++;
            }
        }
    }

    printf("%d",noWater);
    //printMat();



    return 0;
}
