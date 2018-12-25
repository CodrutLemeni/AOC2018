#include <bits/stdc++.h>

using namespace std;

const int X = 10 ;
const int PowerADD = 57 ;

struct Group{
    int id ;

    int noUnits , hitPoints ;
    vector < string > weaks ;
    vector < string > imunity ;
    int dmg , init;
    string power ;
    int isSelected ;
    int attack ;
};

Group infection [ X ] , imune [ X ] ;
int noInf = X , noImn = X ;
vector < int > allGroups ;


bool byEfective( Group a , Group b ){
    if ( a.dmg * a.noUnits == b.dmg * b.noUnits ){
        return a.init > b.init ;
    }
    return a.dmg * a.noUnits > b.dmg * b.noUnits ;
}
bool byInit ( int x , int y ){
    Group a , b ;
    if ( x < X ){
        a = imune [ x ];
    }else{
        a = infection [ x - X ];
    }
    if ( y < X ){
        b = imune [ y ];
    }else{
        b = infection [ y - X ];
    }

    return a.init > b.init ;

}
int calcDamage ( Group a , Group b ){

    int crDmg = a.noUnits * a.dmg ;

    for (  string str : b.weaks ){
        char crArray [ 40 ] ;
        strcpy( crArray , str.c_str() );
//        cout << crArray << '\n';
        if ( strcmp( crArray , a.power.c_str() ) == 0 ){
            return 2 * crDmg ;
        }
    }
    for (  string str : b.imunity ){
        char crArray [ 40 ] ;
        strcpy( crArray , str.c_str() );
//        cout << crArray << '\n';
        if ( strcmp( crArray , a.power.c_str() ) == 0 ){
            return 0 ;
        }
    }

    return crDmg ;
}
void selectTarget ( Group& a , Group v[] ){
    int crInit = 10000 , crPow ;
    int maxDmg = 0 ;
    int selection = 0 ;

    for ( int i = 0 ; i < X ; i++ ){

        if ( v [ i ].noUnits <= 0 || v [ i ].isSelected == 1 ){
            continue ;
        }

        int crDmg = calcDamage( a , v [ i ] );

        if ( maxDmg < crDmg ){
            maxDmg = crDmg ;
            selection = i ;
            crPow = v [ i ].noUnits * v [ i ].dmg ;
            crInit = v [ i ].init ;
        }else if ( maxDmg == crDmg && v [ i ].noUnits * v[ i ].dmg > crPow){
            selection = i ;
            crPow = v [ i ].noUnits * v [ i ].dmg ;
            crInit = v [ i ].init ;
        }else if (maxDmg == crDmg && v [ i ].noUnits * v[ i ].dmg == crPow  && v [ i ].init > crInit ){
            selection = i ;
            crInit = v [ i ].init ;
        }

    }
    if ( maxDmg == 0 ){
        return ;
    }
    a.attack = selection ;
    v[ selection ].isSelected = 1 ;

}


int main()
{

    freopen("file.in","r",stdin);
//    freopen("file.out","w",stdout);

    scanf("Immune System:\n");

    string s ;
    char s2 [ 40 ] ;
    char  t[ 40 ]  ;
    for ( int i = 0 ; i < noImn ; i++ ){
        imune [ i ].id = i ;
        scanf("%d units each with %d hit points %s ", &imune [ i ].noUnits , &imune[ i ].hitPoints , t );

        if ( strcmp( t , "with") == 0 ){
            scanf("%s attack that does%d %s %s at initiative %d\n",t , &imune [ i ].dmg , s2 , t , &imune [ i ].init );
            imune [ i ].power.assign( s2 );

            continue ;
        }else if ( strcmp( t ,"(weak") == 0 ){

            while ( cin >> s ){
                if ( s[ s.length() - 1 ] == ')') {

                    s[ s.length() - 1 ] = 0 ;
                    imune [ i ].weaks.push_back ( s );

                    break;
                }else if ( s[ s.length() - 1 ] == ';') {

                    s[ s.length() - 1 ] = 0 ;
                    imune [ i ].weaks.push_back ( s );

                    cin >> s >> s ;

                    while ( 3 ){
                        cin >> s ;

                        if ( s [ s.length() - 1 ] == ')' ){
                            s[ s.length() - 1 ] = 0 ;
                            imune [ i ].imunity.push_back ( s );
                            break;
                        }
                        s[ s.length() - 1 ] = 0 ;
                        imune [ i ].imunity.push_back ( s );

                    }


                    break;
                }
                s[ s.length() - 1 ] = 0 ;
                imune [ i ].weaks.push_back ( s );

            }

        }else{
            while ( cin >> s ){
                if ( s[ s.length() - 1 ] == ')') {

                    s[ s.length() - 1 ] = 0 ;
                    imune [ i ].imunity.push_back ( s );

                    break;
                }else if ( s[ s.length() - 1 ] == ';') {

                    s[ s.length() - 1 ] = 0 ;
                    imune [ i ].imunity.push_back ( s );

                    cin >> s >> s ;

                    while ( 3 ){
                        cin >> s ;

                        if ( s [ s.length() - 1 ] == ')' ){
                            s[ s.length() - 1 ] = 0 ;
                            imune [ i ].weaks.push_back ( s );
                            break;
                        }
                        s[ s.length() - 1 ] = 0 ;
                        imune [ i ].weaks.push_back ( s );

                    }


                    break;
                }
                s[ s.length() - 1 ] = 0 ;
                imune [ i ].imunity.push_back ( s );

            }
        }

        scanf("%s an attack that does%d %s %s at initiative %d\n",t , &imune [ i ].dmg , s2 , t , &imune [ i ].init );

        imune [ i ].power.assign( s2 );

    }
    scanf("Infection:\n");
    for ( int i = 0 ; i < noImn ; i++ ){
        infection [ i ].id = i + X ;
        scanf("%d units each with %d hit points %s ", &infection [ i ].noUnits , &infection[ i ].hitPoints , t );

        if ( strcmp( t , "with") == 0 ){
            scanf("%s attack that does%d %s %s at initiative %d\n",t , &infection [ i ].dmg , s2 , t , &infection [ i ].init );
            infection [ i ].power.assign( s2 );

            continue ;
        }else if ( strcmp( t ,"(weak") == 0 ){

            while ( cin >> s ){
                if ( s[ s.length() - 1 ] == ')') {

                    s[ s.length() - 1 ] = 0 ;
                    infection [ i ].weaks.push_back ( s );

                    break;
                }else if ( s[ s.length() - 1 ] == ';') {

                    s[ s.length() - 1 ] = 0 ;
                    infection [ i ].weaks.push_back ( s );

                    cin >> s >> s ;

                    while ( 3 ){
                        cin >> s ;

                        if ( s [ s.length() - 1 ] == ')' ){
                            s[ s.length() - 1 ] = 0 ;
                            infection [ i ].imunity.push_back ( s );
                            break;
                        }
                        s[ s.length() - 1 ] = 0 ;
                        infection [ i ].imunity.push_back ( s );

                    }


                    break;
                }
                s[ s.length() - 1 ] = 0 ;
                infection [ i ].weaks.push_back ( s );

            }

        }else{
            while ( cin >> s ){
                if ( s[ s.length() - 1 ] == ')') {

                    s[ s.length() - 1 ] = 0 ;
                    infection [ i ].imunity.push_back ( s );

                    break;
                }else if ( s[ s.length() - 1 ] == ';') {

                    s[ s.length() - 1 ] = 0 ;
                    infection [ i ].imunity.push_back ( s );

                    cin >> s >> s ;

                    while ( 3 ){
                        cin >> s ;

                        if ( s [ s.length() - 1 ] == ')' ){
                            s[ s.length() - 1 ] = 0 ;
                            infection [ i ].weaks.push_back ( s );
                            break;
                        }
                        s[ s.length() - 1 ] = 0 ;
                        infection [ i ].weaks.push_back ( s );

                    }


                    break;
                }
                s[ s.length() - 1 ] = 0 ;
                infection [ i ].imunity.push_back ( s );

            }
        }

        scanf("%s an attack that does%d %s %s at initiative %d\n",t , &infection [ i ].dmg , s2 , t , &infection [ i ].init );

        infection [ i ].power.assign( s2 );

    }

    for ( int i = 0 ; i < noInf ; i++ ){
        imune [ i ].dmg += PowerADD ;
    }

    int noRounds = 0 ;
    int infAlive , imnAlive ;

    while ( noInf > 0  && noImn > 0 ){


        imnAlive = infAlive = 0 ;
        for ( int i = 0; i < noImn ; i++ ){
            imnAlive += imune [ i ].noUnits ;
        }
        for ( int i = 0; i < noInf ; i++ ){
            infAlive += infection [ i ].noUnits ;
        }

        printf("Round %d : %d %d : %d |%d\n", noRounds ++ ,noImn , noInf , imnAlive , infAlive);

//        if ( noImn == 1 && noInf == 8 ){
//            printf("h");
//        }

        sort ( imune , imune + X , byEfective );
        sort ( infection , infection + X , byEfective );
        allGroups.clear();
        for ( int i = 0 ; i < noInf ; i++ ){
            allGroups.push_back( i + X);

            infection [ i ].id = i + X ;
            infection [ i ].isSelected= 0 ;
            infection [ i ].attack = -1 ;
        }
        for ( int i = 0 ; i < noImn ; i++ ){
            allGroups.push_back( i );

            imune [ i ].id = i ;
            imune [ i ].isSelected = 0 ;
            imune [ i ].attack= -1 ;
        }


        for ( int i = 0 ; i < noImn ; i++ ){
            selectTarget ( imune [ i ] , infection );
            //printf("%d %d %d -> %d %d %d\n", imune [ i ].noUnits * imune [ i ].dmg , imune[ i ].noUnits , imune [ i ].dmg ,imune [ i ].attack , infection [ imune [ i ].attack ].noUnits , infection [ imune [ i ].attack ].noUnits  *infection [ imune [ i ].attack ].dmg   );
        }
        for ( int i = 0 ; i < noInf; i++ ){
            selectTarget ( infection [ i ] , imune);
        }

        sort( allGroups.begin() , allGroups.end() , byInit );

        for ( int id : allGroups ){
            if ( id < X ){
                Group a = imune [ id ] ;
                if ( a.attack == -1 ){
                    continue;
                }
                Group& b = infection [ imune [ id ].attack ] ;

                int crDmg = calcDamage( a , b );
                int dead = crDmg / b.hitPoints ;

                b.noUnits -= dead ;
                if ( b.noUnits <= 0 ){
                    b.noUnits = 0 ;
                    noInf -- ;
                }

            }else{
                Group a = infection [ id - X ] ;

                if ( a.attack == -1 ){
                    continue;
                }

                Group& b = imune [ infection [ id - X ].attack ] ;

                int crDmg = calcDamage( a , b );
                int dead = crDmg / b.hitPoints ;

                b.noUnits -= dead ;
                if ( b.noUnits <= 0 ){
                    b.noUnits = 0 ;
                    noImn -- ;
                }
            }

        }

    }

    int sum = 0 ;

    for ( int i = 0 ; i < noImn ; i++ ){
        sum += imune [ i ].noUnits;
        printf("%d  ",imune [ i ].noUnits );
    }
    printf("\n");

    for ( int j = 0 ; j < noInf ; j++ ){
        sum += infection [ j ].noUnits ;
        printf("%d  ",infection [ j ].noUnits );
    }

    cout <<"\n" <<sum ;

    return 0;
}
