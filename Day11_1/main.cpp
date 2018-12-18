//#include <bits/stdc++.h>
//
//using namespace std;
//
//int grid[300][300];
//
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int serial; cin >> serial;
//
//    serial = 1309 ;
//	for(int i = 0; i < 300; i++) {
//		for(int j = 0; j < 300; j++) {
//			int x = i + 1;
//			int y = j + 1;
//			int rackId = x + 10;
//			int p = rackId * y + serial;
//			p *= rackId;
//			p = (p / 100) % 10;
//			p -= 5;
//			grid[i][j] = p;
//		}
//	}
//
//	int maxTot = -100;
//	int maxX, maxY, maxsz;
//	for(int sz = 1; sz <= 300; sz++) {
//		for(int i = 0; i < 300 - sz + 1; i++) {
//			for(int j = 0; j < 300 - sz + 1; j++) {
//				int tot = 0;
//				for(int k = 0; k < sz; k++) {
//					for(int l = 0; l < sz; l++) {
//						tot += grid[i+k][j+l];
//					}
//				}
//				if(tot > maxTot) {
//					maxTot = tot;
//					maxX = i+1;
//					maxY = j+1;
//					maxsz = sz;
//				}
//			}
//		}
//	}
//	cout << maxTot << " " << maxsz << " " << maxX << " " << maxY << endl;
//
//	return 0;
//}




#include <bits/stdc++.h>

using namespace std;

const int N = 300 ;

int serialNumber ;

int mat [ 310 ][ 310 ];


int main()
{
    freopen("file.in","r",stdin);

    scanf("%d",&serialNumber);

    serialNumber = 1309;
    for ( int i = 1 ; i<= N ; i ++ ){
        for ( int j = 1 ; j <= N ; j++ ){
            long long rackId = i + 10 ;
            long long p = rackId * j ;

            p += serialNumber ;

            p *= rackId ;

            p = ( p /100 ) % 10 ;
            mat [ i ][ j ] = p - 5;
           // mat [ i ] [ j ] = mat [ i ] [ j ] + mat [ i - 1 ][ j ] + mat[ i ] [ j - 1 ] - mat [ i -1 ] [ j - 1 ];
        }
    }

    int maxSum = -N , xMax , yMax ;


    for ( int i = 1 ; i <= N - 2 ; i++ ){
        for ( int j = 1 ; j <= N - 2 ; j++ ){

            int crSum = mat [ i ][ j ] + mat [ i + 1 ][ j ] + mat[ i + 2 ][ j ];
            crSum += mat [ i ][ j + 1] + mat [ i + 1 ][ j + 1] + mat[ i + 2 ][ j + 1 ] ;
            crSum += mat [ i ][ j + 2] + mat [ i + 1 ][ j + 2 ] + mat[ i + 2 ][ j + 2 ];

            if ( crSum > maxSum ){
                maxSum = crSum ;
                xMax = i ;
                yMax = j ;
            }


        }
    }


    printf("%d %d %d",xMax , yMax ,maxSum);



    return 0;
}
