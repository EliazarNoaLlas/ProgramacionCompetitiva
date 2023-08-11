function finLength(N, color, radius) {
    let balls = []; // Lista para representar el arreglo imaginario
    
    for (let i = 0; i < N; i++) {
      // Si la lista de bolas no está vacía y la bola actual tiene el mismo color y tamaño que la última bola en la lista,
      // eliminamos ambas bolas de la lista
      if (balls.length && balls[balls.length - 1][0] === color[i] && balls[balls.length - 1][1] === radius[i]) {
        balls.pop();
        continue;
      }
      
      // Agregamos la bola actual a la lista de bolas
      balls.push([color[i], radius[i]]);
    }
    
    // El tamaño final del arreglo imaginario es la longitud de la lista de bolas
    return balls.length;
  }
  
  // Ejemplo de uso
  const N = 3;
  const color = [2, 2, 5];
  const radius = [3, 3, 4];
  const result = finLength(N, color, radius);
  console.log(result);