ejec: main.cpp ControladorComentario.o ControladorUsuario.o ControladorProducto.o TipoObjeto.o Fabrica.o Compra.o
	g++ -o ejec main.cpp ControladorComentario.o ControladorUsuario.o ControladorProducto.o TipoObjeto.o Fabrica.o Compra.o

#main: main.cpp DTFecha.o DTUsuario.o DTCliente.o DTVendedor.o TipoObjeto.o DTProducto.o DTIdYCant.o DTPromo.o DTNotificacion.o DTDetalleCompra.o Usuario.o IObserver.o Producto.o CompraProducto.o Compra.o Cliente.o Vendedor.o Promocion.o Comentario.o DetalleCompra.o IComentario.o ICompra.o IProducto.o IPromocion.o IUsuario.o ControladorComentario.o ControladorProducto.o ControladorCompra.o ManejadorPromocion.o ControladorUsuario.o Fabrica.o
#    g++ -o main main.cpp DTFecha.o DTUsuario.o DTCliente.o DTVendedor.o TipoObjeto.o DTProducto.o DTIdYCant.o DTPromo.o DTNotificacion.o DTDetalleCompra.o Usuario.o IObserver.o Producto.o CompraProducto.o Compra.o Cliente.o Vendedor.o Promocion.o Comentario.o DetalleCompra.o IComentario.o ICompra.o IProducto.o IPromocion.o IUsuario.o ControladorComentario.o ControladorProducto.o ControladorCompra.o ManejadorPromocion.o ControladorUsuario.o Fabrica.o
#g++ -o main main.cpp DTFecha.o DTUsuario.o DTCliente.o DTVendedor.o TipoObjeto.o DTProducto.o DTIdYCant.o DTPromo.o DTNotificacion.o DTDetalleCompra.o Usuario.o IObserver.o Producto.o CompraProducto.o Compra.o Cliente.o Vendedor.o Promocion.o Comentario.o DetalleCompra.o IComentario.o ICompra.o IProducto.o IPromocion.o IUsuario.o ControladorComentario.o ControladorProducto.o ControladorCompra.o ManejadorPromocion.o ControladorUsuario.o Fabrica.o

DTFecha.o: DataTypes/DataType.cpp/DTFecha.cpp DataTypes/DataType.h/DTFecha.h
	g++ -c -o DTFecha.o DataTypes/DataType.cpp/DTFecha.cpp
DTUsuario.o: DataTypes/DataType.cpp/DTUsuario.cpp DataTypes/DataType.h/DTUsuario.h
	g++ -c -o DTUsuario.o DataTypes/DataType.cpp/DTUsuario.cpp
DTCliente.o: DataTypes/DataType.cpp/DTCliente.cpp DataTypes/DataType.h/DTCliente.h DTUsuario.o
	g++ -c -o DTCliente.o DataTypes/DataType.cpp/DTCliente.cpp
DTVendedor.o: DataTypes/DataType.cpp/DTVendedor.cpp DataTypes/DataType.h/DTVendedor.h DTUsuario.o
	g++ -c -o DTVendedor.o DataTypes/DataType.cpp/DTVendedor.cpp	
TipoObjeto.o: DataTypes/DataType.h/TipoObjeto.cpp
	g++ -c -o TipoObjeto.o DataTypes/DataType.h/TipoObjeto.cpp
DTProducto.o: DataTypes/DataType.cpp/DTProducto.cpp DataTypes/DataType.h/DTProducto.h TipoObjeto.o
	g++ -c -o DTProducto.o DataTypes/DataType.cpp/DTProducto.cpp
DTIdYCant.o: DataTypes/DataType.cpp/DTIdYCant.cpp DataTypes/DataType.h/DTIdYCant.h 
	g++ -c -o DTIdYCant.o DataTypes/DataType.cpp/DTIdYCant.cpp	
DTPromo.o: DataTypes/DataType.cpp/DTPromo.cpp DataTypes/DataType.h/DTPromo.h DTFecha.o
	g++ -c -o DTPromo.o DataTypes/DataType.cpp/DTPromo.cpp	
DTNotificacion.o: DataTypes/DataType.cpp/DTNotificacion.cpp DataTypes/DataType.h/DTNotificacion.h DTProducto.o
	g++ -c -o DTNotificacion.o DataTypes/DataType.cpp/DTNotificacion.cpp
DTDetalleCompra.o: DataTypes/DataType.cpp/DTDetalleCompra.cpp DataTypes/DataType.h/DTDetalleCompra.h DTFecha.o
	g++ -c -o DTDetalleCompra.o DataTypes/DataType.cpp/DTDetalleCompra.cpp	


Usuario.o: Objetos/Objetos.cpp/Usuario.cpp Objetos/Objetos.h/Usuario.h DTFecha.o
	g++ -c -o Usuario.o Objetos/Objetos.cpp/Usuario.cpp
IObserver.o: Interfaces/Interfaces.h/IObserver.h 
	g++ -c -o IObserver.o Interfaces\Interfaces.h/IObserver.h
Producto.o: Objetos/Objetos.cpp/Producto.cpp Objetos/Objetos.h/Producto.h TipoObjeto.o
	g++ -c -o Producto.o Objetos/Objetos.cpp/Producto.cpp
CompraProducto.o: Objetos/Objetos.cpp/CompraProducto.cpp Objetos/Objetos.h/CompraProducto.h Producto.o
	g++ -c -o CompraProducto.o Objetos/Objetos.cpp/CompraProducto.cpp
Compra.o: Objetos/Objetos.cpp/Compra.cpp Objetos/Objetos.h/Compra.h Cliente.o CompraProducto.o DTFecha.o DTDetalleCompra.o
	g++ -c -o Compra.o Objetos/Objetos.cpp/Compra.cpp
Cliente.o: Objetos/Objetos.cpp/Cliente.cpp Objetos/Objetos.h/Cliente.h Usuario.o DTNotificacion.o IObserver.o Compra.o DTFecha.o
	g++ -c -o Cliente.o Objetos/Objetos.cpp/Cliente.cpp
Vendedor.o: Objetos/Objetos.cpp/Vendedor.cpp Objetos/Objetos.h/Vendedor.h Usuario.o Producto.o Cliente.o DTFecha.o IObserver.o
	g++ -c -o Vendedor.o Objetos/Objetos.cpp/Vendedor.cpp	
Promocion.o: Objetos/Objetos.cpp/Promocion.cpp Objetos/Objetos.h/Promocion.h Producto.o DTFecha.o 
	g++ -c -o Promocion.o Objetos/Objetos.cpp/Promocion.cpp
Comentario.o: Objetos/Objetos.cpp/Comentario.cpp Objetos/Objetos.h/Comentario.h Producto.o Usuario.o DTFecha.o 
	g++ -c -o Comentario.o Objetos/Objetos.cpp/Comentario.cpp	
DetalleCompra.o: Objetos/Objetos.cpp/DetalleCompra.cpp Objetos/Objetos.h/DetalleCompra.h DTFecha.o CompraProducto.o
	g++ -c -o DetalleCompra.o Objetos/Objetos.cpp/DetalleCompra.cpp


IComentario.o: Interfaces/Interfaces.h/IComentario.h Comentario.o 
	g++ -c -o IComentario.o Interfaces/Interfaces.h/IComentario.h
ICompra.o: Interfaces/Interfaces.h/ICompra.h Compra.o 
	g++ -c -o ICompra.o Interfaces/Interfaces.h/ICompra.h
IProducto.o: Interfaces/Interfaces.h/IProducto.h DetalleCompra.o Vendedor.o 
	g++ -c -o IProducto.o Interfaces/Interfaces.h/IProducto.h
IPromocion.o: Interfaces/Interfaces.h/IPromocion.h Promocion.o  
	g++ -c -o IPromocion.o Interfaces/Interfaces.h/IPromocion.h
IUsuario.o: Interfaces/Interfaces.h/IUsuario.h DTProducto.o DTVendedor.o DTCliente.o DTNotificacion.o  
	g++ -c -o IUsuario.o Interfaces/Interfaces.h/IUsuario.h


ControladorComentario.o: Controladores/Controladores.cpp/ControladorComentario.cpp Controladores/Controladores.h/ControladorComentario.h Comentario.o Usuario.o Cliente.o Vendedor.o IComentario.o Fabrica.o 
	g++ -c -o ControladorComentario.o Controladores/Controladores.cpp/ControladorComentario.cpp
ControladorProducto.o: Controladores/Controladores.cpp/ControladorProducto.cpp Controladores/Controladores.h/ControladorProducto.h Comentario.o DTNotificacion.o Usuario.o Cliente.o Vendedor.o DTPromo.o DTIdYCant.o Promocion.o DetalleCompra.o DTProducto.o Producto.o   
	g++ -c -o ControladorProducto.o Controladores/Controladores.cpp/ControladorProducto.cpp
ControladorCompra.o: Controladores/Controladores.cpp/ControladorCompra.cpp Controladores/Controladores.h/ControladorCompra.h Fabrica.o ControladorProducto.o DTDetalleCompra.o Compra.o ICompra.o DTFecha.o 
	g++ -c -o ControladorCompra.o Controladores/Controladores.cpp/ControladorCompra.cpp
ManejadorPromocion.o: Controladores/Controladores.cpp/ManejadorPromocion.cpp Controladores/Controladores.h/ManejadorPromocion.h Promocion.o ControladorProducto.o IPromocion.o  
	g++ -c -o ManejadorPromocion.o Controladores/Controladores.cpp/ManejadorPromocion.cpp
ControladorUsuario.o: Controladores/Controladores.cpp/ControladorUsuario.cpp Controladores/Controladores.h/ControladorUsuario.h Fabrica.o Vendedor.o ManejadorPromocion.o Comentario.o DTNotificacion.o DTProducto.o Usuario.o Cliente.o IUsuario.o  
	g++ -c -o ControladorUsuario.o Controladores/Controladores.cpp/ControladorUsuario.cpp
Fabrica.o: Objetos/Objetos.cpp/Fabrica.cpp Objetos/Objetos.h/Fabrica.h ControladorComentario.o ControladorCompra.o ManejadorPromocion.o ControladorProducto.o ControladorUsuario.o IUsuario.o  
	g++ -c -o Fabrica.o Objetos/Objetos.cpp/Fabrica.cpp





