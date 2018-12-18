#include <bits/stdc++.h>

using namespace std;




int EvolveNode ( ){
    int noChildren , noMetaData ;

    vector < int > v ;


    cin >> noChildren >> noMetaData ;

    for ( int i = 0 ; i < noChildren ; i++ ){
        int t = EvolveNode() ;
        v.push_back( t );
    }

    long long sum = 0 ;
    int val = 0 ;

    if ( noChildren == 0 ){
        while ( noMetaData--  ){
            scanf("%d",&val);
            sum += val ;
        }
        return sum ;
    }

    while ( noMetaData--  ){
        scanf("%d",&val);

        val -- ;
        if ( val < noChildren )
            sum += v [ val ] ;

    }

    return sum ;
}

int main()
{
    freopen("file.in","r",stdin);

    cout << EvolveNode();


    return 0;
}
