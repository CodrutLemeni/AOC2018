#include <bits/stdc++.h>


using namespace std;

const int N = 100 ;
const int INF = 1e5 ;


char mat [ N ][ N ] ;
int dist[ N ][ N ] ;
int type[ N ][ N ] ;
int noLin , noCol ;

struct Unit {
    pair < int , int > crPos ;
    int type , hp ;
    // 0 - elf
    // 1 - goblin


};
struct Position {
    pair < int , int > crPos ;
    int type ;
    // 0 - elf
    // 1 - goblin


};

bool cmp( Unit a , Unit b ){
    return a.crPos < b.crPos ;
}


vector < Unit > allUnits ;

//int dl[] ={ 0 , -1 , 0 , 1 };
//int dc[] ={ -1 , 0 , 1 , 0 };
int dl[] ={ -1 , 0 , 0 , 1 };
int dc[] ={ 0 , -1 , 1 , 0 };

void Lee ( pair < int , int > crPos , int crType ){

    queue < Position > que ;


    int i = crPos.first ;
    int j = crPos.second ;
    dist [ i ] [ j ] = 0 ;
    type [ i ] [ j ] = crType ;



    Position Pos ;
    Pos.crPos =  crPos ;
    Pos.type = crType ;
    que.push( Pos );



    while ( !que.empty() ){
        int crLin = que.front().crPos.first ;
        int crCol = que.front().crPos.second ;
        int crType = que.front().type;

        que.pop();

        for ( int k = 0 ; k < 4 ; k++ ){
            int vecLin = crLin + dl [ k ] ;
            int vecCol = crCol + dc [ k ] ;

            if ( vecCol >= 0 && vecCol <= noCol && vecLin > 0 && vecLin < noLin ){
                if ( mat [ vecLin ][ vecCol ] == '.' && dist[ vecLin ][ vecCol ] > dist [ crLin ][ crCol ] + 1){
                    dist[ vecLin ][ vecCol ] = dist [ crLin ][ crCol ] + 1 ;
                    type[ vecLin ][ vecCol ] = crType ;

                    Position crPos ;

                    crPos.crPos = make_pair( vecLin , vecCol ) ;
                    crPos.type = crType ;

                    que.push( crPos );
                }

            }

        }

    }



}


int makeAttack ( Unit crUnit ){

    int minHp = 200 ;

    for ( Unit vecUnit : allUnits){

        if ( vecUnit.hp <= 0){
            continue;
        }

        if ( vecUnit.type != crUnit.type ){

            for ( int k = 0 ; k < 4 ; k++ ){
                int crLin = crUnit.crPos.first + dl [ k ] ;
                int crCol = crUnit.crPos.second + dc [ k ] ;

                if ( vecUnit.crPos.first == crLin && vecUnit.crPos.second == crCol ){
                    minHp = min  ( minHp , vecUnit.hp );
                }

            }
        }
    }
    for ( int k = 0 ; k < 4 ; k++ ){
        int crLin = crUnit.crPos.first + dl [ k ] ;
        int crCol = crUnit.crPos.second + dc [ k ] ;

        for ( auto it = allUnits.begin() ; it != allUnits.end() ; it++ ){

            if ( it->hp <= 0){
                continue;
            }

            if ( it->type == crUnit.type ){
                continue;
            }

            if ( it->crPos.first == crLin && it->crPos.second == crCol && it->hp == minHp){
                it->hp -= 3;

//                if ( it->hp <= 0 ){
//                    allUnits.erase( it );
//                }

                return 1;
            }
        }

    }
    return 0 ;
}


int makeMove ( Unit crUnit ){

    if ( makeAttack( crUnit ) ){
        return - 2;
    }

    for ( int i = 0 ; i < noLin ; i++ ){
        for ( int j = 0 ; j < noCol ; j++ ){
            dist[  i ][ j ] = INF ;
        }
    }
    int i = crUnit.crPos.first ;
    int j = crUnit.crPos.second ;

    for ( int k = 0 ; k < 4 ; k ++ ){
        int crLin = i + dl [ k ] ;
        int crCol = j + dc [ k ] ;

        if ( mat [ crLin ][ crCol ] == '.' ){
            Position crPos ;
            crPos.crPos =  make_pair( crLin , crCol ) ;
            crPos.type = k ;
            Lee( crPos.crPos , k );
        }


    }

    int minDist = INF  ;
    int crType;
    int minLin , minCol;

    for ( Unit vecUnit : allUnits){

        if ( vecUnit.hp <= 0 ){
            continue;
        }

        if ( vecUnit.type != crUnit.type ){

            for ( int k = 0 ; k < 4 ; k++ ){
                int crLin = vecUnit.crPos.first + dl [ k ] ;
                int crCol = vecUnit.crPos.second + dc [ k ] ;

                if ( dist [ crLin ][ crCol ] < minDist ){
                    minDist = dist [ crLin][ crCol ];
                    crType = type [ crLin ][ crCol ];
                    minLin = crLin;
                    minCol = crCol;
                }else if ( dist [ crLin ][ crCol ] == minDist ){
                    if ( crLin < minLin ){
                        minLin = crLin;
                        minCol = crCol;
                        crType = type [ crLin ][ crCol ];

                    }else if ( crLin == minLin ){
                        if ( crCol < minCol ){
                            minLin = crLin ;
                            minCol = crCol ;
                            crType = type [ crLin ][ crCol ];

                        }
                    }


                }
            }
        }
    }
    if ( minDist == INF ) {
        return -1;
    }
    return crType ;


}


int isOver(){
    int s = 0 ;

    for ( Unit crUnit : allUnits ){
        if ( crUnit.type == 0 && crUnit.hp > 0 ){
            s += 1;
            break;
        }
    }
    for ( Unit crUnit : allUnits ){
        if ( crUnit.type == 1  && crUnit.hp > 0  ){
            s += 2;
            break;
        }
    }
    if ( s == 3 ){
        return 1 ;
    }

    return 0 ;
}

void UpdateMat(){
    for ( int i = 0 ; i < noLin ; i++ ){
        for ( int j = 0 ; j < noCol ; j++ ){
            if ( mat [ i ][ j ] == 'G' || mat [ i ][ j ] == 'E' ){
                mat [ i ][ j ] = '.';
            }
        }
    }

    for ( auto it = allUnits.begin() ; it != allUnits.end() ; it++ ){
        if ( it->hp <= 0 ){
            continue;
        }

        if( it->type == 0 ){
            mat [ it->crPos.first ] [ it->crPos.second ] = 'E';
        }else {
            mat [ it->crPos.first ] [ it->crPos.second ] = 'G';
        }

    }

}

void printMat (){
    UpdateMat();


    for ( int i = 0 ; i < noLin ; i++ ){
        for ( int j = 0 ; j < noCol ; j++ ){
            printf("%3c",mat[ i ][ j ] );
        }
        printf("\n");
    }


}

int main(){

    freopen("file.in","r",stdin);

    while ( gets( mat [ noLin ++ ] ) );

    noCol = strlen( mat [ 0 ] );


    for ( int i = 0 ; i < noLin ; i++ ){
        for ( int j = 0 ; j < noCol ; j++ ){
            Unit crUnit ;

            crUnit.hp = 200 ;

            crUnit.crPos.first = i ;
            crUnit.crPos.second = j ;

            if ( mat [ i ][ j ] == 'G' ){
                crUnit.type = 1 ;
                allUnits.push_back( crUnit );

            }else if ( mat [ i ][ j ] == 'E' ){
                crUnit.type = 0 ;
                allUnits.push_back( crUnit );            }
        }
    }

    int noRounds = 0 ;
    while ( isOver() ){
//
//        if ( noRounds == 23 ){
//            printf("s");
//        }


        sort ( allUnits.begin() , allUnits.end() ,cmp );

        for ( auto it = allUnits.begin() ; it != allUnits.end() ; it++ ){
            UpdateMat();

            if( isOver() == 0 ){
                noRounds --;

                break;
            }

            if ( it->hp <= 0 ){
//                allUnits.erase( it );
//                it --;
                continue;
            }

            int type = makeMove ( *it );

            if ( type == -1 ){
                continue;
            }
            if ( type == -2 ){
                continue;
            }

            it->crPos.first += dl [ type ];
            it->crPos.second += dc [ type ];

            makeAttack( *it );

        }
        for ( auto it = allUnits.begin() ; it != allUnits.end() ; it++ ){
            if ( it->hp <= 0 ){
                allUnits.erase( it );
                it --;

            }
        }
        UpdateMat();

        noRounds++;

        if ( isOver() ==0 ){
            break;
        }

        //printMat();

    }
    //noRounds -- ;
    //printf("%d",noRounds);

    int sumHp = 0;
    for ( auto it = allUnits.begin() ; it != allUnits.end() ; it++ ){
        sumHp += it->hp;

    }
    printf("%d",sumHp*noRounds);

    return 0;
}
