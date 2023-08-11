import math

# Función para calcular la distancia entre dos puntos en el espacio tridimensional
def distancia(x1, y1, z1, x2, y2, z2):
    return math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)

# Función para calcular el tiempo que tarda el Kamehameha en llegar al planeta Kranus
def tiempo_kamehameha(distancia, velocidad):
    return distancia / velocidad

# Función para calcular el tiempo que tarda Goku en cargar la mitad de su Ki en el planeta Kranus
def tiempo_carga(ki):
    return 0.5 * ki / 10000
# Lectura de datos y procesamiento de cada caso de prueba
while True:
    try:
        x1, y1, z1, x2, y2, z2, velocidad, ki = map(float, input().split())
    except:
        break
    
    dist = distancia(x1, y1, z1, x2, y2, z2)
    print(dist)
    tiempo_k = tiempo_kamehameha(dist, velocidad)
    print(tiempo_k)
    if dist == 0 :
        tiempo_c = 0
    else:
        tiempo_c = tiempo_carga(ki)
    print(tiempo_c)
    if tiempo_k < tiempo_c:
        print("Lanzar kamehameha")
    elif tiempo_k > tiempo_c:
        print("Teleportacion")
    else:
        print("Teleportacion")