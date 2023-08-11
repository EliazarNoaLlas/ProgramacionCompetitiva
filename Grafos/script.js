const form = document.getElementById('articulo-form');
const submitBtn = document.getElementById('submit-btn');
const cancelBtn = document.getElementById('cancel-btn');

form.addEventListener('submit', (event) => {
  event.preventDefault();
  const codigo = document.getElementById('codigo').value;
  const descripcion = document.getElementById('descripcion').value;
  const precio = document.getElementById('precio').value;
  const stock = document.getElementById('stock').value;

  // Enviar los datos del artículo al servidor aquí...

  alert('Artículo registrado correctamente!');
  form.reset();
});

cancelBtn.addEventListener('click', () => {
  if (confirm('¿Seguro que quieres salir? Los cambios no se guardarán.')) {
    window.location.href = 'index.html'; // Cambiar esto por la página de destino
  }
});
