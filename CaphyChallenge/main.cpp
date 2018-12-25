#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("file.in","r",stdin);

    char c ;
    int x;
    while ( scanf("%c%d",&c,&x ) != -1 ){
       // printf("%d\n", x -127000);

        x -= 127900 ;


        printf("%c",x + 23 );

    }

    return 0;
}
