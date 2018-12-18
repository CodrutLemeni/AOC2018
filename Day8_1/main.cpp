#include <bits/stdc++.h>

using namespace std;



long long sum ;

int EvolveNode ( ){
    int noChildren , noMetaData ;



    cin >> noChildren >> noMetaData ;

    while ( noChildren -- ){
        EvolveNode();
    }

    int val ;
    while ( noMetaData--  ){
        scanf("%d",&val);
        sum += val ;

    }


}

int main()
{
    freopen("file.in","r",stdin);

    EvolveNode();

    printf("%I64d",sum);

    return 0;
}
