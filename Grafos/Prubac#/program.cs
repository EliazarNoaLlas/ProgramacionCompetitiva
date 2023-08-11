using System;

public class Ventas {

    // EMPLEADO
    public string codempleado;
    public string nombreempleado;
    public string apellidopaternoempleado;
    public string apellidomaternoempleado;
    public double sueldobaseempleado;
    public string estadocivilempleado;
    public int numerodehijosempleado;
    
    // VENTAS
    public string numerodeboleta;
    public string fecha;
    public double subtotal;
    public double igv;
    public double total;
    
    // DETALLE DE VENTAS
    public int cantidadarticulo;
    
    // SEGURO
    public string codigoseguro;
    public string descripcionseguro;
    public double porcentajededescuentodeseguro;
    
    // ARTICULO
    public string codigoarticulo;
    public string descripciondearticulo;
    public double preciodearticulo;
    public int stock;
    
    // Constructor sin parámetros
    public Ventas() {}
    
    // Constructor con parámetros
    public Ventas(string codempleado, string nombreempleado, string apellidopaternoempleado, 
                  string apellidomaternoempleado, double sueldobaseempleado, string estadocivilempleado, 
                  int numerodehijosempleado, string numerodeboleta, string fecha, double subtotal, 
                  double igv, double total, int cantidadarticulo, string codigoseguro, 
                  string descripcionseguro, double porcentajededescuentodeseguro, string codigoarticulo, 
                  string descripciondearticulo, double preciodearticulo, int stock) {
        this.codempleado = codempleado;
        this.nombreempleado = nombreempleado;
        this.apellidopaternoempleado = apellidopaternoempleado;
        this.apellidomaternoempleado = apellidomaternoempleado;
        this.sueldobaseempleado = sueldobaseempleado;
        this.estadocivilempleado = estadocivilempleado;
        this.numerodehijosempleado = numerodehijosempleado;
        this.numerodeboleta = numerodeboleta;
        this.fecha = fecha;
        this.subtotal = subtotal;
        this.igv = igv;
        this.total = total;
        this.cantidadarticulo = cantidadarticulo;
        this.codigoseguro = codigoseguro;
        this.descripcionseguro = descripcionseguro;
        this.porcentajededescuentodeseguro = porcentajededescuentodeseguro;
        this.codigoarticulo = codigoarticulo;
        this.descripciondearticulo = descripciondearticulo;
        this.preciodearticulo = preciodearticulo;
        this.stock = stock;
    }
}

public String getCodempleado() {
return codempleado;
}

public void setCodempleado(String codempleado) {
this.codempleado = codempleado;
}

public String getNombreempleado() {
return nombreempleado;
}

public void setNombreempleado(String nombreempleado) {
this.nombreempleado = nombreempleado;
}

public String getApellidopaternoempleado() {
return apellidopaternoempleado;
}

public void setApellidopaternoempleado(String apellidopaternoempleado) {
this.apellidopaternoempleado = apellidopaternoempleado;
}

public String getApellidomatemoempleado() {
return apellidomatemoempleado;
}

public void setApellidomatemoempleado(String apellidomatemoempleado) {
this.apellidomatemoempleado = apellidomatemoempleado;
}

public double getSueldobaseempleado() {
return sueldobaseempleado;
}

public void setSueldobaseempleado(double sueldobaseempleado) {
this.sueldobaseempleado = sueldobaseempleado;
}

public String getEstadocivilempleado() {
return estadocivilempleado;
}

public void setEstadocivilempleado(String estadocivilempleado) {
this.estadocivilempleado = estadocivilempleado;
}

public String toString() {
// Implementación del método toString
return "";
}
public String getDescripcionseguro(){
return descripcionseguro;
}

public void setDescripcionseguro(String descripcionseguro) {
this.descripcionseguro = descripcionseguro;
}

public double getPorcentajededescuentoseguro() {
return porcentajededescuentoseguro;
}

public void setPorcentajededescuentoseguro(double porcentajededescuentoseguro) {
this.porcentajededescuentoseguro = porcentajededescuentoseguro;
}

public String getCodigoarticulo() {
return codigoarticulo;
}

public void setCodigoarticulo(String codigoarticulo) {
this.codigoarticulo = codigoarticulo;
}

public String getDescripciondearticulo() {
return descripciondearticulo;
}

public void setDescripciondearticulo(String descripciondearticulo) {
this.descripciondearticulo = descripciondearticulo;
}

public double getPreciodearticulo() {
return preciodearticulo;
}

public void setPreciodearticulo(double preciodearticulo) {
this.preciodearticulo = preciodearticulo;
}

public int getStock() {
return stock;
}

public void setStock(int stock) {
this.stock = stock;
}
public void setStock(int stock) {
this.stock = stock;
}

public double calcularSueldoNeto() {
return calcularTA() - calcularDescuentoSeguro();
}

public double calcularComisionVentas() {
return 0.05 * getTotal();
}

public double calcularTA() {
return getSueldobaseempleado() + calcularComisionVentas();
}

public double calcularDescuentoImpuesto() {
if (calcularTA() > 0 && calcularTA() < 1500) {
return 0;
}
else if (calcularTA() >= 1500 && calcularTA() <= 2300) {
return 0.03 * calcularTA();
}
else if (calcularTA() >= 2301 && calcularTA() <= 3000) {
return 0.04 * calcularTA();
}
else if (calcularTA() >= 3001) {
return 0.06 * calcularTA();
}
return 0;
}

public double calcularDescuentoSeguro() {
    switch (getEstadocivilempleado()) {
        case "soltero":
        return 100;
        case "casado sin hijos":
        return 120;
        case "casado con hijos":
        return 50 + 70 * getNumerodehijosempleado();
        default:
        return 0;
    }
}