[33mcommit aae9bbcf97bcc413bcb47c2c66c93715e7515d5b[m[33m ([m[1;36mHEAD -> [m[1;32mmaster[m[33m)[m
Author: Eliazar Noa <infoeliasar@gmail.com>
Date:   Tue Apr 4 11:23:22 2023 -0500

    cambios en la version V1

[1mdiff --git a/.vscode/launch.json b/.vscode/launch.json[m
[1mnew file mode 100644[m
[1mindex 0000000..5da9c63[m
[1m--- /dev/null[m
[1m+++ b/.vscode/launch.json[m
[36m@@ -0,0 +1,16 @@[m
[32m+[m[32m{[m
[32m+[m[32m    // Use IntelliSense para saber los atributos posibles.[m
[32m+[m[32m    // Mantenga el puntero para ver las descripciones de los existentes atributos.[m
[32m+[m[32m    // Para más información, visite: https://go.microsoft.com/fwlink/?linkid=830387[m
[32m+[m[32m    "version": "0.2.0",[m
[32m+[m[32m    "configurations": [[m
[32m+[m[32m        {[m
[32m+[m[32m            "name": "Python: archivo actual",[m
[32m+[m[32m            "type": "python",[m
[32m+[m[32m            "request": "launch",[m
[32m+[m[32m            "program": "${file}",[m
[32m+[m[32m            "console": "integratedTerminal",[m
[32m+[m[32m            "justMyCode": true[m
[32m+[m[32m        }[m
[32m+[m[32m    ][m
[32m+[m[32m}[m
\ No newline at end of file[m
[1mdiff --git a/.vscode/settings.json b/.vscode/settings.json[m
[1mnew file mode 100644[m
[1mindex 0000000..e97753c[m
[1m--- /dev/null[m
[1m+++ b/.vscode/settings.json[m
[36m@@ -0,0 +1,19 @@[m
[32m+[m[32m{[m
[32m+[m[32m    "cmake.configureOnOpen": true,[m
[32m+[m[32m    "files.associations": {[m
[32m+[m[32m        "ostream": "cpp",[m
[32m+[m[32m        "iostream": "cpp",[m
[32m+[m[32m        "*.tcc": "cpp",[m
[32m+[m[32m        "expected": "cpp",[m
[32m+[m[32m        "optional": "cpp",[m
[32m+[m[32m        "ratio": "cpp",[m
[32m+[m[32m        "system_error": "cpp",[m
[32m+[m[32m        "array": "cpp",[m
[32m+[m[32m        "functional": "cpp",[m
[32m+[m[32m        "regex": "cpp",[m
[32m+[m[32m        "tuple": "cpp",[m
[32m+[m[32m        "type_traits": "cpp",[m
[32m+[m[32m        "utility": "cpp",[m
[32m+[m[32m        "variant": "cpp"[m
[32m+[m[32m    }[m
[32m+[m[32m}[m
\ No newline at end of file[m
[1mdiff --git a/.vscode/tasks.json b/.vscode/tasks.json[m
[1mnew file mode 100644[m
[1mindex 0000000..932d6f6[m
[1m--- /dev/null[m
[1m+++ b/.vscode/tasks.json[m
[36m@@ -0,0 +1,28 @@[m
[32m+[m[32m{[m
[32m+[m[32m    "tasks": [[m
[32m+[m[32m        {[m
[32m+[m[32m            "type": "cppbuild",[m
[32m+[m[32m            "label": "C/C++: g++.exe compilar archivo activo",[m
[32m+[m[32m            "command": "C:\\msys64\\mingw64\\bin\\g++.exe",[m
[32m+[m[32m            "args": [[m
[32m+[m[32m                "-fdiagnostics-color=always",[m
[32m+[m[32m                "-g",[m
[32m+[m[32m                "${file}",[m
[32m+[m[32m                "-o",[m
[32m+[m[32m                "${fileDirname}\\${fileBasenameNoExtension}.exe"[m
[32m+[m[32m            ],[m
[32m+[m[32m            "options": {[m
[32m+[m[32m                "cwd": "${fileDirname}"[m
[32m+[m[32m            },[m
[32m+[m[32m            "problemMatcher": [[m
[32m+[m[32m                "$gcc"[m
[32m+[m[32m            ],[m
[32m+[m[32m            "group": {[m
[32m+[m[32m                "kind": "build",[m
[32m+[m[32m                "isDefault": true[m
[32m+[m[32m            },[m
[32m+[m[32m            "detail": "Tarea generada por el depurador."[m
[32m+[m[32m        }[m
[32m+[m[32m    ],[m
[32m+[m[32m    "version": "2.0.0"[m
[32m+[m[32m}[m
\ No newline at end of file[m
[1mdiff --git a/A-welcometoAtCoder.py b/A-welcometoAtCoder.py[m
[1mnew file mode 100644[m
[1mindex 0000000..becdb0c[m
[1m--- /dev/null[m
[1m+++ b/A-welcometoAtCoder.py[m
[36m@@ -0,0 +1,4 @@[m
[32m+[m[32ma = int(input())[m
[32m+[m[32mb,c = map(int, input().split())[m
[32m+[m[32ms = input()[m
[32m+[m[32mprint(str(a+b+c) + " " + s)4[m
[1mdiff --git a/Aluck.cpp b/Aluck.cpp[m
[1mnew file mode 100644[m
[1mindex 0000000..d4526b3[m
[1m--- /dev/null[m
[1m+++ b/Aluck.cpp[m
[36m@@ -0,0 +1,64 @@[m
[32m+[m[32m#include <bits/stdc++.h>[m
[32m+[m[32musing namespace std;[m
[32m+[m
[32m+[m[32m#define ll long long[m
[32m+[m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m[32m    ios::sync_with_stdio(0); // desactivar la sincronización de E / S con C[m
[32m+[m[32m    cin.tie(0); // desactivar la asociación de la entrada estándar con la salida estándar[m
[32m+[m[32m    cout.tie(0); // desactivar la asociación de la salida estándar con la entrada estándar[m
[32m+[m
[32m+[m[32m    int t; // número de casos de prueba[m
[32m+[m[32m    cin >> t;[m
[32m+[m[32m    while(t--){[m
[32m+[m[32m        int l, r; // límites inferior y superior del intervalo de búsqueda[m
[32m+[m[32m        cin >> l >> r;[m
[32m+[m[32m        int max_diff = 0; // la diferencia máxima actual[m
[32m+[m[32m        int best_num = 0; // el número que produce la mayor diferencia actual[m
[32m+[m
[32m+[m[32m        if(r-l >= 100) // si el intervalo es grande[m
[32m+[m[32m        {[m
[32m+[m[32m            int num;[m
[32m+[m[32m            for(int i = 0; i <= 100; i++) // busque los primeros 100 números en el intervalo[m
[32m+[m[32m            {[m
[32m+[m[32m                num = l+i; // número actual a verificar[m
[32m+[m[32m                if(num % 10 == 0) // si el número termina en cero[m
[32m+[m[32m                {[m
[32m+[m[32m                    num /= 10; // eliminar el dígito cero[m
[32m+[m[32m                    if(num % 10 == 9) // si el nuevo dígito de las unidades es 9[m
[32m+[m[32m                    {[m
[32m+[m[32m                        cout << l + i << endl; // mostrar el número actual[m
[32m+[m[32m                        break; // detener la búsqueda[m
[32m+[m[32m                    }[m
[32m+[m[32m                }[m
[32m+[m[32m            }[m
[32m+[m[32m        }[m
[32m+[m[32m        else // si el intervalo es pequeño[m
[32m+[m[32m        {[m
[32m+[m[32m            int num_diff; // la diferencia actual entre los dígitos máximo y mínimo[m
[32m+[m[32m            for(int i = l; i <= r; i++) // busque todos los números en el intervalo[m
[32m+[m[32m            {[m
[32m+[m[32m                int min_digit = 9; // el dígito mínimo inicial[m
[32m+[m[32m                int max_digit = 0; // el dígito máximo inicial[m
[32m+[m[32m                int num = i; // número actual a verificar[m
[32m+[m[32m                while(num) // extraer los dígitos del número[m
[32m+[m[32m                {[m
[32m+[m[32m                    int digit = num % 10;[m
[32m+[m[32m                    min_digit = min(min_digit, digit); // actualizar el dígito mínimo si es necesario[m
[32m+[m[32m                    max_digit = max(max_digit, digit); // actualizar el dígito máximo si es necesario[m
[32m+[m[32m                    num /= 10; // eliminar el último dígito del número[m
[32m+[m[32m                }[m
[32m+[m[32m                num_diff = max_digit - min_digit; // calcular la diferencia entre los dígitos máximo y mínimo[m
[32m+[m[32m                if(num_diff > max_diff){ // si la diferencia actual es mayor que la diferencia máxima registrada[m
[32m+[m[32m                    best_num = i; // actualizar el número que produce la mayor diferencia[m
[32m+[m[32m                    max_diff = num_diff; // actualizar la diferencia máxima registrada[m
[32m+[m[32m                }[m
[32m+[m[32m            }[m
[32m+[m[32m            if(best_num == 0) // si no se encontró ningún número que cumpla con los requisitos[m
[32m+[m[32m                cout << r << endl; // mostrar el límite superior del intervalo[m
[32m+[m[32m            else[m
[32m+[m[32m                cout << best_num << endl; // mostrar el número que produce la mayor diferencia entre sus dígitos[m
[