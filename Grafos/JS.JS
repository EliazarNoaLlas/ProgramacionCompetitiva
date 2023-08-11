public void leerArchivo() {
    DefaultTableModel modeloTabla = new DefaultTableModel();
    modeloTabla.addColumn("ID");
    modeloTabla.addColumn("Nombre");
    modeloTabla.addColumn("Apellido");
    modeloTabla.addColumn("Edad");

    try {
        File archivo = new File("empleados.txt");
        Scanner scanner = new Scanner(archivo);

        while (scanner.hasNextLine()) {
            String linea = scanner.nextLine();
            String[] campos = linea.split(",");
            Object[] fila = new Object[4];
            fila[0] = campos[0];
            fila[1] = campos[1];
            fila[2] = campos[2];
            fila[3] = campos[3];
            modeloTabla.addRow(fila);
        }

        scanner.close();
        jTableEmpleados.setModel(modeloTabla);
    } catch (FileNotFoundException e) {
        JOptionPane.showMessageDialog(null, "No se encontró el archivo");
    }
}