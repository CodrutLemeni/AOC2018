#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    freopen("file.in","r",stdin);

    int n ;
    int x = 0 ;

    while ( cin >> n ){
        x += n ;
    }

    cout << x ;

    return 0;
}
