#include <algorithm> 
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

/*Forming Quiz Teams,la solucion al problema UVa 10911*/
// Definimos las variables globales
int N, target;
double dist[20][20], memo[1<<16]; //1 << 16 = 2^16, sabiendo que max N=8

double matching(int bitmask){ //estado de DP = mascara de bits
    // inicializamos `memo` con -1 en la funcion main
    if(memo[bitmask] > -0.5)    // este  estado ya se ha calculado
        return memo[bitmask];   //basta buscar en la tabla memo
    if(bitmask == target)       //si todos los estudiantes estan emparejados
        return memo[bitmask] = 0;//entonces el coste es 0

    double ans = 2000000000.0; //Inicializamos en un nuemro muy grande
    int p1, p2;
    for ( p1 = 0; p1 < 2*N; p1++)
    {
        if(!(bitmask & (1 << p1)))
            break; //encontramos el  primer bit apagado
    }
    for ( p2 = p1 + 1; p2 < 2*N; p2++) //despues de intentar emparejar p1con otro bit p2
    {
        if(!(bitmask & (1 << p2))) //elegir el minimo
            ans = min(ans, dist[p1][p2] + matching(bitmask | (1 << p1) | (1 << p2)));
        return memo[bitmask] = ans; //guardar el resultado en una tabla y volver 
    }
    
}
int main(){
    int i, j, caseNo = 1, x[20], y[20];
    while(scanf("%d",&N),N){
        for ( i = 0; i < 2*N; i++)
        {
            scanf("%*s %d %d", &x[i], &y[i]);
        }
        for(i =0;i<2*N; i++)
            for(j =0;j<2*N; j++)
                dist[i][j] = dist[j][i] = hypot(x[i]-x[j], y[i]-y[j]);
        for(i = 0; i<(1 << 16); i++) memo[i]=-1.0;
        target = (1 << (2*N)) -1;
        printf("case %d: % .21f\n", caseNo++,matching(0));
    }
    return 0;
}

