#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0); // desactivar la sincronización de E / S con C
    cin.tie(0); // desactivar la asociación de la entrada estándar con la salida estándar
    cout.tie(0); // desactivar la asociación de la salida estándar con la entrada estándar

    int t; // número de casos de prueba
    cin >> t;
    while(t--){
        int l, r; // límites inferior y superior del intervalo de búsqueda
        cin >> l >> r;
        int max_diff = 0; // la diferencia máxima actual
        int best_num = 0; // el número que produce la mayor diferencia actual

        if(r-l >= 100) // si el intervalo es grande
        {
            int num;
            for(int i = 0; i <= 100; i++) // busque los primeros 100 números en el intervalo
            {
                num = l+i; // número actual a verificar
                if(num % 10 == 0) // si el número termina en cero
                {
                    num /= 10; // eliminar el dígito cero
                    if(num % 10 == 9) // si el nuevo dígito de las unidades es 9
                    {
                        cout << l + i << endl; // mostrar el número actual
                        break; // detener la búsqueda
                    }
                }
            }
        }
        else // si el intervalo es pequeño
        {
            int num_diff; // la diferencia actual entre los dígitos máximo y mínimo
            for(int i = l; i <= r; i++) // busque todos los números en el intervalo
            {
                int min_digit = 9; // el dígito mínimo inicial
                int max_digit = 0; // el dígito máximo inicial
                int num = i; // número actual a verificar
                while(num) // extraer los dígitos del número
                {
                    int digit = num % 10;
                    min_digit = min(min_digit, digit); // actualizar el dígito mínimo si es necesario
                    max_digit = max(max_digit, digit); // actualizar el dígito máximo si es necesario
                    num /= 10; // eliminar el último dígito del número
                }
                num_diff = max_digit - min_digit; // calcular la diferencia entre los dígitos máximo y mínimo
                if(num_diff > max_diff){ // si la diferencia actual es mayor que la diferencia máxima registrada
                    best_num = i; // actualizar el número que produce la mayor diferencia
                    max_diff = num_diff; // actualizar la diferencia máxima registrada
                }
            }
            if(best_num == 0) // si no se encontró ningún número que cumpla con los requisitos
                cout << r << endl; // mostrar el límite superior del intervalo
            else
                cout << best_num << endl; // mostrar el número que produce la mayor diferencia entre sus dígitos
        }      
    }
}