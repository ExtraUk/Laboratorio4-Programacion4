#include "Interfaces/Interfaces.h/IUsuario.h"
#include <iostream>
#include "Controladores/Controladores.h/ControladorUsuario.h"
#include "Controladores/Controladores.h/ControladorProducto.h"
#include "Controladores/Controladores.h/ControladorComentario.h"
#include "DataTypes/DataType.h/TipoObjeto.cpp"
#include "Objetos/Objetos.h/Fabrica.h"
#include "Objetos/Objetos.h/Compra.h"
using namespace std;

static DTFecha fechaActual = DTFecha(1,1,2000);
static void mostrarListaString(list<string> lista){
    for(string str: lista){
        cout << str << endl;
    }
}

static void mostrarListaString(list<string>* lista){
    for(string str: *lista){
        cout << str << endl;
    }
}

static void CargarDatos(){ //Faltan promociones y compras
    Fabrica * fab = new Fabrica();
    IUsuario * controladorUsuario = fab->getIUsuario();
    IProducto * controladorProducto = fab->getIProducto();
    IComentario * controladorComentario = fab->getIComentario();
    IPromocion * manejadorPromocion = fab->getIPromocion();
    ICompra * controladorCompra = fab->getICompra();

    Cliente * cli1 = controladorUsuario->NuevoCliente("juan87", DTFecha(20,10,1992), "1qaz2wsx", "Av. 18 de Julio 456", "Melo");
    Cliente * cli2 = controladorUsuario->NuevoCliente("laura", DTFecha(22,9,1979), "3edc4rfv", "Rondeau 1617", "Montevideo");
    Cliente * cli3 = controladorUsuario->NuevoCliente("natalia", DTFecha(14,4,1982), "poiuyt", "Paysandú 2021", "Salto");
    Cliente * cli4 = controladorUsuario->NuevoCliente("pablo10", DTFecha(30,11,1995), "lkjhgv", "Av. Rivera 1819", "Mercedes");
    Cliente * cli5 = controladorUsuario->NuevoCliente("roberto", DTFecha(12,8,1995), "mnbvcx", "Av. Brasil 1011", "Montevideo");
    Vendedor * vend1 = controladorUsuario->NuevoVendedor("ana23", DTFecha(15,5,1988),"qwer1234","212345678001");
    Vendedor * vend2 = controladorUsuario->NuevoVendedor("carlos78", DTFecha(18,6,1986), "asdfghj", "356789012345");
    Vendedor * vend3 = controladorUsuario->NuevoVendedor("diegom", DTFecha(28,7,1993), "zxcvbn", "190123456789");
    Vendedor * vend4 = controladorUsuario->NuevoVendedor("maria01", DTFecha(25,3,1985), "5tgb6yhn", "321098765432");
    Vendedor * vend5 = controladorUsuario->NuevoVendedor("sofia25", DTFecha(7,12,1983), "1234asdf", "445678901234");

    Producto * prod1 = controladorProducto->AltaProducto(1, "Camiseta Azul", "Camiseta de poliester, color azul", 50, 1400, TipoObjeto::Ropa, vend2);
    Producto * prod2 = controladorProducto->AltaProducto(2, "Televisor LED", "Televisor LED 55 pulgadas", 30, 40500, TipoObjeto::Electrodomestico, vend1);
    Producto * prod3 = controladorProducto->AltaProducto(3, "Chaqueta de Cuero", "Chaqueta de cuero, color negro", 20, 699.99, TipoObjeto::Ropa, vend2);
    Producto * prod4 = controladorProducto->AltaProducto(4, "Microondas Digital", "Microondas digital, 30L", 15, 1199.99, TipoObjeto::Electrodomestico, vend1);
    Producto * prod5 = controladorProducto->AltaProducto(5, "Luz LED", "Luz Bluetooth LED", 40, 599.99, TipoObjeto::Otro, vend3);
    Producto * prod6 = controladorProducto->AltaProducto(6, "Pantalones Vaqueros", "Pantalones vaqueros, talla 32", 25, 60, TipoObjeto::Ropa, vend2);
    Producto * prod7 = controladorProducto->AltaProducto(7, "Auriculares Bluetooth", "Auriculares bluethooth para celular", 35, 199.99, TipoObjeto::Otro, vend3);
    Producto * prod8 = controladorProducto->AltaProducto(8, "Refrigerador", "Refrigerador de doble puerta", 10, 15499, TipoObjeto::Electrodomestico, vend1);
    Producto * prod9 = controladorProducto->AltaProducto(9, "Cafetera", "Cafetera de goteo programable", 50, 23000, TipoObjeto::Electrodomestico, vend1);
    Producto * prod10 = controladorProducto->AltaProducto(10, "Zapatillas Deportivas", "Zapatillas para correr, talla 42", 20, 5500, TipoObjeto::Ropa, vend2);
    Producto * prod11 = controladorProducto->AltaProducto(11, "Mochila", "Mochila de viaje, 40L", 30, 9000, TipoObjeto::Otro, vend2);
    Producto * prod12 = controladorProducto->AltaProducto(12, "Plancha de Ropa", "Plancha a vapor, 1500W", 25, 2534, TipoObjeto::Electrodomestico, vend3);
    Producto * prod13 = controladorProducto->AltaProducto(13, "Gorra", "Gorra para deportes, color rojo", 50, 200, TipoObjeto::Ropa, vend5);
    Producto * prod14 = controladorProducto->AltaProducto(14, "Tablet", "Tablet Android de 10 pulgadas", 15, 15000, TipoObjeto::Electrodomestico, vend3);
    Producto * prod15 = controladorProducto->AltaProducto(15, "Reloj de Pared", "Reloj de pared vintage", 20, 150.50, TipoObjeto::Otro, vend5);

    Comentario * coment1 = controladorComentario->ComentarioNuevo("¿La camiseta azul esta disponible en talla M?", DTFecha(1,6,2024), prod1, cli1);
    Comentario * coment2 = controladorComentario->ComentarioNuevo("Si, tenemos la camiseta azul en talla M.", DTFecha(1,6,2024), prod1, vend2);
    coment1->agregarRespuesta(coment2);
    Comentario * coment3 = controladorComentario->ComentarioNuevo("¿Es de buen material? Me preocupa la durabilidad.", DTFecha(2,6,2024), prod1, cli2);
    coment2->agregarRespuesta(coment3);
    Comentario * coment4 = controladorComentario->ComentarioNuevo("He comprado antes y la calidad es buena.", DTFecha(2,6,2024), prod1, cli1);
    coment3->agregarRespuesta(coment4);
    Comentario * coment5 = controladorComentario->ComentarioNuevo("Â¿Como es el ajuste? Â¿Es ajustada o holgada?", DTFecha(2,6,2024), prod1, cli3);
    Comentario * coment6 = controladorComentario->ComentarioNuevo("Â¿Cual es la resolucion del Televisor LED?", DTFecha(2,6,2024), prod2, cli2);
    Comentario * coment7 = controladorComentario->ComentarioNuevo("El televisor LED tiene una resolucion de 4K UHD.", DTFecha(2,6,2024), prod2, cli1);
    coment6->agregarRespuesta(coment7);
    Comentario * coment8 = controladorComentario->ComentarioNuevo("Â¿Tiene soporte para HDR10?", DTFecha(3,6,2024), prod2, cli4);
    Comentario * coment9 = controladorComentario->ComentarioNuevo("Si, soporta HDR10.", DTFecha(3,6,2024), prod2, vend1);
    coment8->agregarRespuesta(coment9);
    Comentario * coment10 = controladorComentario->ComentarioNuevo("Â¿La chaqueta de cuero es resistente al agua?", DTFecha(3,6,2024), prod3, cli3);
    Comentario * coment11 = controladorComentario->ComentarioNuevo("No, la chaqueta de cuero no es resistente al agua.", DTFecha(3,6,2024), prod3, vend2);
    coment10->agregarRespuesta(coment11);
    Comentario * coment12 = controladorComentario->ComentarioNuevo("Â¿Viene en otros colores?", DTFecha(4,6,2024), prod3, cli2);
    coment10->agregarRespuesta(coment12);
    Comentario * coment13 = controladorComentario->ComentarioNuevo("Si, tambien esta disponible en marron.", DTFecha(4,6,2024), prod3, vend2);
    coment12->agregarRespuesta(coment13);
    Comentario * coment14 = controladorComentario->ComentarioNuevo("Â¿Es adecuada para climas frios?", DTFecha(4,6,2024), prod3, cli5);
    coment10->agregarRespuesta(coment14);
    Comentario * coment15 = controladorComentario->ComentarioNuevo("Â¿El microondas digital tiene funcion de descongelacion rapida?", DTFecha(4,6,2024), prod4, cli4);
    Comentario * coment16 = controladorComentario->ComentarioNuevo("Si, el microondas digital incluye una funcion de descongelacion rapida.", DTFecha(4,6,2024), prod4, vend1);
    coment15->agregarRespuesta(coment16);
    Comentario * coment17 = controladorComentario->ComentarioNuevo("Â¿Cuantos niveles de potencia tiene?", DTFecha(5,6,2024), prod4, cli3);
    coment15->agregarRespuesta(coment17);
    Comentario * coment18 = controladorComentario->ComentarioNuevo("Tiene 10 niveles de potencia.", DTFecha(5,6,2024), prod4, vend1);
    coment17->agregarRespuesta(coment18);
    Comentario * coment19 = controladorComentario->ComentarioNuevo("Â¿Es facil de limpiar?", DTFecha(5,6,2024), prod4, cli5);
    coment15->agregarRespuesta(coment19);
    Comentario * coment20 = controladorComentario->ComentarioNuevo("Â¿La luz LED se puede controlar con una aplicacion movil?", DTFecha(5,6,2024), prod5, cli5);
    Comentario * coment21 = controladorComentario->ComentarioNuevo("Si, la luz LED se puede controlar a traves de una aplicacion movil.", DTFecha(5,6,2024), prod5, vend3);
    coment20->agregarRespuesta(coment21);
    Comentario * coment22 = controladorComentario->ComentarioNuevo("Â¿Es compatible con Alexa o Google Home?", DTFecha(6,6,2024), prod5, cli4);
    coment20->agregarRespuesta(coment22);
    Comentario * coment23 = controladorComentario->ComentarioNuevo("Si, es compatible con ambos.", DTFecha(6,6,2024), prod5, vend3);
    coment22->agregarRespuesta(coment23);
    Comentario * coment24 = controladorComentario->ComentarioNuevo("Â¿Cuanto dura la bateria?", DTFecha(6,6,2024), prod5, cli3);
    coment20->agregarRespuesta(coment24);
    Comentario * coment25 = controladorComentario->ComentarioNuevo("Â¿La aplicacion movil es facil de usar?", DTFecha(7,6,2024), prod5, cli4);
    coment20->agregarRespuesta(coment25);

    Promocion * promo1 = new Promocion("Casa Nueva", "Para que puedas ahorrar en la casa nueva", 30, DTFecha(25,10,2024));
    Promocion * promo2 = new Promocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", 20, DTFecha(26,10,2024));
    Promocion * promo3 = new Promocion("Domotica", "Para modernizar tu casa", 10, DTFecha(26,10,2024));
    Promocion * promo4 = new Promocion("Liquidacion", "Hasta agotar stock", 10, DTFecha(26,3,2024));
    promo1->agregarProducto(prod1, 1);
    promo1->agregarProducto(prod4, 1);
    promo1->agregarProducto(prod8, 1);
    promo2->agregarProducto(prod3, 2);
    promo2->agregarProducto(prod6, 3);
    promo3->agregarProducto(prod5, 2);
    promo4->agregarProducto(prod14, 1);
    manejadorPromocion->agregarPromo(promo1);
    manejadorPromocion->agregarPromo(promo2);
    manejadorPromocion->agregarPromo(promo3);
    manejadorPromocion->agregarPromo(promo4);

    CompraProducto * compraProd11 = new CompraProducto(2, prod2, true);
    CompraProducto * compraProd12 = new CompraProducto(1, prod4, false);
    CompraProducto * compraProd13 = new CompraProducto(1, prod8, false);
    map<int, CompraProducto*> * compraProds1 = new map<int, CompraProducto*>();
    compraProds1->insert({compraProd11->getProducto()->getId(), compraProd11});
    compraProds1->insert({compraProd12->getProducto()->getId(), compraProd12});
    compraProds1->insert({compraProd13->getProducto()->getId(), compraProd13});
    DTDetalleCompra detalle1 = DTDetalleCompra(fechaActual);
    detalle1.add(prod2->getNombre() + ": " + to_string(compraProd11->getCantidad()) + ", $" + to_string(compraProd11->getCantidad()*compraProd11->getPrecio()*(1-promo1->getDescuento())));
    detalle1.add(prod4->getNombre() + ": " + to_string(compraProd12->getCantidad()) + ", $" + to_string(compraProd12->getCantidad()*compraProd12->getPrecio()*(1-promo1->getDescuento())));
    detalle1.add(prod8->getNombre() + ": " + to_string(compraProd13->getCantidad()) + ", $" + to_string(compraProd13->getCantidad()*compraProd13->getPrecio()*(1-promo1->getDescuento())));
    detalle1.setFecha(DTFecha(1,5,2024));
    detalle1.sumarPrecio((compraProd11->getCantidad()*compraProd11->getPrecio()*(1-promo1->getDescuento())) + compraProd12->getCantidad()*compraProd12->getPrecio()*(1-promo1->getDescuento()) + compraProd13->getCantidad()*compraProd13->getPrecio()*(1-promo1->getDescuento()));
    Compra * compra1 = new Compra(1, compraProds1, detalle1, cli1);

    CompraProducto * compraProd2 = new CompraProducto(1, prod5, true);
    map<int, CompraProducto*> * compraProds2 = new map<int, CompraProducto*>();
    compraProds2->insert({compraProd2->getProducto()->getId(), compraProd2});
    DTDetalleCompra detalle2 = DTDetalleCompra(fechaActual);
    detalle2.add(prod5->getNombre() + ": " + to_string(compraProd2->getCantidad()) + ", $" + to_string(compraProd2->getCantidad()*compraProd2->getPrecio()));
    detalle2.setFecha(DTFecha(1,5,2024));
    detalle2.sumarPrecio(compraProd2->getCantidad()*compraProd2->getPrecio());
    Compra * compra2 = new Compra(2, compraProds2, detalle2, cli1);

    CompraProducto * compraProd3 = new CompraProducto(10, prod14, true);
    map<int, CompraProducto*> * compraProds3 = new map<int, CompraProducto*>();
    compraProds3->insert({compraProd3->getProducto()->getId(), compraProd3});
    DTDetalleCompra detalle3 = DTDetalleCompra(fechaActual);
    detalle3.add(prod14->getNombre() + ": " + to_string(compraProd3->getCantidad()) + ", $" + to_string(compraProd3->getCantidad()*compraProd3->getPrecio()));
    detalle3.setFecha(DTFecha(15,5,2024));
    detalle3.sumarPrecio(compraProd3->getCantidad()*compraProd3->getPrecio());
    Compra * compra3 = new Compra(3, compraProds3, detalle3, cli2);

    CompraProducto * compraProd41 = new CompraProducto(1, prod11, true);
    CompraProducto * compraProd42 = new CompraProducto(1, prod12, true);
    map<int, CompraProducto*> * compraProds4 = new map<int, CompraProducto*>();
    compraProds4->insert({compraProd41->getProducto()->getId(), compraProd41});
    compraProds4->insert({compraProd42->getProducto()->getId(), compraProd42});
    DTDetalleCompra detalle4 = DTDetalleCompra(fechaActual);
    detalle4.add(prod11->getNombre() + ": " + to_string(compraProd41->getCantidad()) + ", $" + to_string(compraProd41->getCantidad()*compraProd41->getPrecio()));
    detalle4.add(prod12->getNombre() + ": " + to_string(compraProd42->getCantidad()) + ", $" + to_string(compraProd42->getCantidad()*compraProd42->getPrecio()));
    detalle4.setFecha(DTFecha(25,4,2024));
    detalle4.sumarPrecio((compraProd41->getCantidad()*compraProd41->getPrecio())+(compraProd42->getCantidad()*compraProd42->getPrecio()));
    Compra * compra4 = new Compra(4, compraProds4, detalle4, cli3);

    CompraProducto * compraProd51 = new CompraProducto(2, prod3, false);
    CompraProducto * compraProd52 = new CompraProducto(3, prod6, true);
    map<int, CompraProducto*> * compraProds5 = new map<int, CompraProducto*>();
    compraProds5->insert({compraProd51->getProducto()->getId(), compraProd51});
    compraProds5->insert({compraProd52->getProducto()->getId(), compraProd52});
    DTDetalleCompra detalle5 = DTDetalleCompra(fechaActual);
    detalle5.add(prod3->getNombre() + ": " + to_string(compraProd51->getCantidad()) + ", $" + to_string(compraProd51->getCantidad()*compraProd51->getPrecio()*(1-promo2->getDescuento())));
    detalle5.add(prod6->getNombre() + ": " + to_string(compraProd52->getCantidad()) + ", $" + to_string(compraProd52->getCantidad()*compraProd52->getPrecio()*(1-promo2->getDescuento())));
    detalle5.setFecha(DTFecha(25,4,2024));
    detalle5.sumarPrecio((compraProd51->getCantidad()*compraProd51->getPrecio()*(1-promo2->getDescuento()))+(compraProd52->getCantidad()*compraProd52->getPrecio()*(1-promo2->getDescuento())));
    Compra * compra5 = new Compra(5, compraProds5, detalle5, cli1);

    CompraProducto * compraProd6 = new CompraProducto(2, prod1, false);
    map<int, CompraProducto*> * compraProds6 = new map<int, CompraProducto*>();
    compraProds6->insert({compraProd6->getProducto()->getId(), compraProd6});
    DTDetalleCompra detalle6 = DTDetalleCompra(fechaActual);
    detalle6.add(prod1->getNombre() + ": " + to_string(compraProd6->getCantidad()) + ", $" + to_string(compraProd6->getCantidad()*compraProd6->getPrecio()));
    detalle6.setFecha(DTFecha(12,5,2024));
    detalle6.sumarPrecio((compraProd6->getCantidad()*compraProd6->getPrecio()));
    Compra * compra6 = new Compra(6, compraProds6, detalle6, cli2);

    CompraProducto * compraProd7 = new CompraProducto(3, prod1, true);
    map<int, CompraProducto*> * compraProds7 = new map<int, CompraProducto*>();
    compraProds7->insert({compraProd7->getProducto()->getId(), compraProd7});
    DTDetalleCompra detalle7 = DTDetalleCompra(fechaActual);
    detalle7.add(prod1->getNombre() + ": " + to_string(compraProd7->getCantidad()) + ", $" + to_string(compraProd7->getCantidad()*compraProd7->getPrecio()));
    detalle7.setFecha(DTFecha(13,5,2024));
    detalle7.sumarPrecio((compraProd7->getCantidad()*compraProd7->getPrecio()));
    Compra * compra7 = new Compra(7, compraProds7, detalle7, cli3);

    CompraProducto * compraProd8 = new CompraProducto(4, prod1, false);
    map<int, CompraProducto*> * compraProds8 = new map<int, CompraProducto*>();
    compraProds8->insert({compraProd8->getProducto()->getId(), compraProd8});
    DTDetalleCompra detalle8 = DTDetalleCompra(fechaActual);
    detalle8.add(prod1->getNombre() + ": " + to_string(compraProd8->getCantidad()) + ", $" + to_string(compraProd8->getCantidad()*compraProd8->getPrecio()));
    detalle8.setFecha(DTFecha(14,5,2024));
    detalle8.sumarPrecio((compraProd8->getCantidad()*compraProd8->getPrecio()));
    Compra * compra8 = new Compra(8, compraProds8, detalle8, cli4);

    CompraProducto * compraProd9 = new CompraProducto(5, prod1, false);
    map<int, CompraProducto*> * compraProds9 = new map<int, CompraProducto*>();
    compraProds9->insert({compraProd9->getProducto()->getId(), compraProd9});
    DTDetalleCompra detalle9 = DTDetalleCompra(fechaActual);
    detalle9.add(prod1->getNombre() + ": " + to_string(compraProd9->getCantidad()) + ", $" + to_string(compraProd9->getCantidad()*compraProd9->getPrecio()));
    detalle9.setFecha(DTFecha(15,5,2024));
    detalle9.sumarPrecio((compraProd9->getCantidad()*compraProd9->getPrecio()));
    Compra * compra9 = new Compra(9, compraProds9, detalle9, cli5);

    controladorCompra->AgregarCompra(compra1);
    controladorCompra->AgregarCompra(compra2);
    controladorCompra->AgregarCompra(compra3);
    controladorCompra->AgregarCompra(compra4);
    controladorCompra->AgregarCompra(compra5);
    controladorCompra->AgregarCompra(compra6);
    controladorCompra->AgregarCompra(compra7);
    controladorCompra->AgregarCompra(compra8);
    controladorCompra->AgregarCompra(compra9);
}




static void mostrarSetString(set<string> set){
    for(string str: set){
        cout << str << endl;
    }
}
static void CambiarFecha(){
    int dia = 0;
    while(dia > 31 || dia < 1){
        cout << "Dia: ";
        cin >> dia;
    }
    int mes = 0;
    while(mes > 12 || mes < 1){
        cout << "Mes: ";
        cin >> mes;
    }
    int ano = 0;
    cout << "Anio: ";
    cin >> ano;
    fechaActual = DTFecha(dia,mes,ano);
}


void RealizarCaso(){
    Fabrica * fab = new Fabrica();
    int seleccionado = 0;
    while (seleccionado != 15){
        cout <<"seleccione una opcion ingresando su numero correspondiente" << "\n";
        cout <<"1: Alta de usuario" << "\n";
        cout <<"2: Listado de usuarios" << "\n";
        cout <<"3: Alta de producto" << "\n";
        cout <<"4: Consultar producto" << "\n";
        cout <<"5: Crear promocion" << "\n";
        cout <<"6: Consultar promocion" << "\n";
        cout <<"7: Realizar Compra" << "\n";
        cout <<"8: Dejar comentario" << "\n";
        cout <<"9: Eliminar comentario" << "\n";
        cout <<"10: Enviar producto" << "\n";
        cout <<"11: Expediente de Usuario" << "\n";
        cout <<"12: Suscribirse a notificaciones" << "\n";
        cout <<"13: Consulta de notificaciones" << "\n";
        cout <<"14: Eliminar suscripciones" << "\n";
        cout <<"15: Volver al menu" << "\n";
        cin >> seleccionado;
        switch(seleccionado){
            case 1: //Alta Usuario TERMINADO
                try{
                    IUsuario* controladorUsuario = fab->getIUsuario();
                    cout << "Ingrese el nombre del nuevo usuario \n";
                    string nombre;
                    cin.get();
                    getline(cin, nombre, '\n');
                    if(nombre.length() == 0 || nombre == "0"){
                        throw(0);
                    }
                    Usuario* chequeo = controladorUsuario->getUsuario(nombre);
                    if(chequeo != nullptr){
                        throw(1);
                    }
                    cout << "Ingrese su fecha de nacimiento, primero ingrese el dia, luego el mes y luego el anio" << endl;
                    int dia;
                    int mes;
                    int anio;
                    cin >> dia;
                    cin >> mes;
                    cin >> anio;
                    if(dia > 31 || dia < 1 || mes > 12 || mes < 1 || anio < 1){
                        throw(4);
                    }
                    DTFecha fecha = DTFecha(dia, mes, anio);
                    cout << "Inserte la contrasenia" << endl;
                    string contrasena;
                    cin.get();
                    getline(cin, contrasena, '\n');
                    if(contrasena.length() < 6){
                        throw(2);
                    }
                    int TUser;
                    cout << "Seleccione el tipo de usuario de la lista proporcionada" << endl;
                    cout << "1: Cliente" << endl;
                    cout << "2: Vendedor" << endl;
                    cin >> TUser;
                    while(TUser != 1 && TUser != 2){
                        cout << "Ingrese un numero valido" << endl;
                        cin >> TUser;
                    }
                    switch(TUser){
                        case 1:{
                        cout << "Ingrese la Ciudad" << endl;
                        string ciudad;
                        cin.get();
                        getline(cin, ciudad, '\n');
                        if(ciudad.length() == 0){
                        throw(0);
                        }
                        cout << "Ingrese la direccion" << endl;
                        string dir;
                        getline(cin, dir, '\n');
                        if(dir.length() == 0){
                        throw(0);
                        }
                        controladorUsuario->NuevoCliente(nombre, fecha, contrasena, dir, ciudad);
                        break;
                        }
                        case 2: {
                        cout << "Ingrese el numero de RUT" << endl;
                        string RUT;
                        cin >> RUT;
                        if(RUT.length() != 12){
                            throw(3);
                        }
                        for(auto c: RUT){
                            if(!isdigit(c)) throw(3);
                        }
                        controladorUsuario->NuevoVendedor(nombre, fecha, contrasena, RUT);
                        break;
                        }
                    }
                }
                catch(int numError){
                    switch(numError){
                        case 0:
                            cout << "ERROR: el valor ingresado es vacío" << endl;
                            break;
                        case 1:
                            cout << "ERROR: El usuario ingresado ya existe" << endl;
                            break;
                        case 2:
                            cout << "ERROR: La contraseña no cumple el minimo de 6 caracteres" << endl;
                            break;
                        case 3:
                            cout << "ERROR: El RUT ingresado no es un número de 12 digitos" << endl;
                            break;
                        case 4:
                            cout << "ERROR: La fecha ingresada es incorrecta" << endl;
                            break;
                        default:
                            cout << "ERROR: Error Indefinido" << endl;
                            break;
                    }
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 2: //Listado de Usuarios TERMINADO
                for (string aImprimir: fab->getIUsuario()->ListarUsuarios()){
                    cout << aImprimir + "\n";
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 3: //Alta de Producto TERMINADO
                try{
                    IProducto* controladorProducto = fab->getIProducto();
                    IUsuario* controladorUsuario = fab->getIUsuario();
                    if(controladorUsuario->CantidadVendedores() == 0){
                        throw(1);
                    }
                    for(string &i:controladorUsuario->ListarVendedores()){
                        cout << i << endl;
                    }
                    cout <<"seleccione un vendedor" << "\n";
                    string vendedorName;
                    cin >> vendedorName;
                    Vendedor* vNuevoProd = controladorUsuario->getVendedor(vendedorName);
                    if(vNuevoProd == nullptr){
                        throw(2);
                    }
                    cout << "Inserte el nombre del producto" << endl;
                    string NomProd;
                    cin.get();
                    getline(cin, NomProd, '\n');
                    if(NomProd == "0") throw(5);
                    cout << "Inserte el precio" << endl;
                    int precio;
                    cin >> precio;
                    if(precio <= 0) throw(3);
                    cout << "Inserte la cantidad del producto" << endl;
                    int cant;
                    cin >> cant;
                    if(precio <= 0) throw(4);
                    cout << "Inserte la descripcion del producto" << endl;
                    string descr;
                    cin.get();
                    getline(cin, descr, '\n');
                    cout << "Seleccione el tipo de producto de la lista proporcionada" << endl;
                    cout << "1: Ropa" << endl;
                    cout << "2: Electrodomestico" << endl;
                    cout << "3: otro" << endl;
                    int Tprod;
                    cin >> Tprod;
                    while(Tprod != 1 && Tprod != 2 && Tprod != 3){
                        cout << "Ingrese un numero valido" << endl;
                        cin >> Tprod;
                    }
                    TipoObjeto Tob;
                    switch(Tprod){
                        case 1: Tob = TipoObjeto::Ropa;
                        case 2: Tob = TipoObjeto::Electrodomestico;
                        case 3: Tob = TipoObjeto::Otro;
                    }
                    Producto* nuevoProd = controladorProducto->NuevoProducto(NomProd,precio,cant,descr,Tob);
                    controladorUsuario->AgregarProducto(vNuevoProd,nuevoProd);
                    cout <<"seleccione otro caso" << "\n";
                    break;
                }
                catch(int numerror){
                    if(numerror = 1){
                        cout << "ERROR: No hay vendedores en el sistema" << endl;
                    }
                    else if(numerror = 2){
                        cout << "ERROR: El vendedor seleccionado no existe" << endl;
                    }
                    else if(numerror = 3){
                        cout << "ERROR: El precio es negativo" << endl;
                    }
                    else if(numerror = 4){
                        cout << "ERROR: La cantidad es negativa" << endl;
                    }
                    else{
                        cout << "ERROR";
                    }
                }
            case 4: //Consulta Producto TERMINADO
                try{
                    IProducto* controladorProducto = fab->getIProducto();
                    map<int, Producto*> productos = controladorProducto->getProductos();
                    //list<string> productos = controladorProducto->ListarProductos(); //
                    /*if (productos.size() == 0){*/ if (productos.size() == 0){ 
                        throw(0);
                    } else {
                        cout << "Seleccione un producto por su id:" << endl;
                        /*mostrarListaString(productos);*/ for(auto [key, val] : productos) cout << val->getCodigo() << ": " + val->getNombre() << "\n";
                        int producto; 
                        cin >> producto;
                        Producto* prod = controladorProducto->SeleccionarProducto(producto);
                        if(prod == nullptr) throw(1);
                        cout << prod->toString() << endl;
                    }
                }
                catch(int numError){
                    if(numError == 0){
                        cout << "No existen productos" << endl;
                    }
                    else if(numError == 1){
                        cout << "Error: Id incorrecta" << endl;
                    }
                }
                cout <<"seleccione otro caso" << "\n" << endl;
                break;
            case 5: //Crear Promocion TERMINADO
                try{
                    IPromocion* manejadorPromocion = fab->getIPromocion();
                    IUsuario* controladorUsuario = fab->getIUsuario();
                    IProducto* controladorProducto = fab->getIProducto();
                    cout << "Ingrese el nombre de la promocion" << endl;
                    string nombre;
                    cin.get();
                    getline(cin, nombre, '\n');
                    for (Promocion * n : manejadorPromocion->getPromociones()){
                        if (nombre == n->getNombre()){
                            throw(3);
                            break;
                        }
                    }
                    cout << "Ingrese la descripcion de la promocion" << endl;
                    string descripcion;
                    cin.get();
                    getline(cin, descripcion, '\n');
                    cout << "Ingrese el descuento de la promocion" << endl;
                    int descuento;
                    cin >> descuento;
                    if(descuento < 1 || descuento > 100) throw(5);
                    cout << "Ingrese la fecha de caducidad de la promocion" << endl;
                    int dia;
                    int mes;
                    int ano;
                    cout << "Dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    cout << "Anio: ";
                    cin >> ano;
                    if(dia > 31 || dia < 1 || mes > 12 || mes < 1 || ano < 1){
                        throw(0);
                    }
                    DTFecha fecha = DTFecha(dia, mes, ano);
                    for (string v : controladorUsuario->ListarVendedores()){
                        cout << v << endl;
                    }
                    cout << "Seleccione un vendedor" << endl;
                    string vendedor;
                    cin >> vendedor;
                    Vendedor* ven = controladorUsuario->getVendedor(vendedor);
                    if(ven == nullptr){
                        throw(1);
                    }
                    if(controladorUsuario->ObtenerProductosVendedor(vendedor).empty()){
                        throw(2);
                    }
                    for (DTProducto p : controladorUsuario->ObtenerProductosVendedor(vendedor)){
                        cout << p.toString() << endl;
                    }
                    bool seguir = true;
                    map<int, int> minimas;
                    list<Producto*> productos;
                    while(seguir){
                        cout << "Seleccione un producto por su id" << endl;
                        int id;
                        cin >> id;
                        bool valido = false;
                        for (DTProducto p : controladorUsuario->ObtenerProductosVendedor(vendedor)){
                            if(p.getCodigo() == id) valido = true;
                        }
                        if(!valido) throw(4); //Producto no en varias promociones a la vez
                        if(manejadorPromocion->estaEnPromocion(id)){
                            throw(6);
                        }
                        cout << "Seleccione la cantidad minima" << endl;
                        int cantmin;
                        cin >> cantmin;
                        if(cantmin <= 0) throw(6);
                        minimas.insert({id, cantmin});
                        Producto* prod = controladorProducto->SeleccionarProducto(id);
                        productos.push_back(prod);
                        cout << "Desea seleccionar otro producto? Seleccione 0 o 1" << endl;
                        cout << "0: Si" << endl;
                        cout << "1: No" << endl;
                        int s;
                        cin >> s;
                        while(s != 1 && s != 0){
                            cout << "Ingrese un valor valido" << endl;
                            cin >> s;
                        }
                        if (s == 0) {
                            seguir = true;
                        } else if (s == 1) {
                            seguir = false;
                        }
                    }
                    manejadorPromocion->IngresarDatosPromo(nombre, fecha, descuento, descripcion, minimas, productos);
                    manejadorPromocion->ConfirmarPromocion();
                    cout << "promocion creada" << endl;
                }
                catch(int numError){
                    if (numError == 0){
                        cout << "La fecha ingresada es incorrecta" << endl;
                    } else if (numError == 1){
                        cout << "El vendedor seleccionado no existe" << endl;
                    } else if (numError == 2){
                        cout << "El vendedor no tiene productos" << endl;
                    } else if (numError == 3){
                        cout << "El nombre de la promocion ya esta en uso" << endl;
                    } else if(numError == 4){
                        cout << "El producto no pertenece al vendedor seleccionado" << endl;
                    }
                    else if(numError == 5){
                        cout << "Error: Descuento Invalido" << endl;
                    }
                    else if(numError == 5){
                        cout << "Error: Cantidad Invalida" << endl;
                    } else if (numError == 6){
                        cout << "El producto ya pertenece a una promocion" << endl;
                    }
                    else{
                        cout << "Error Desconocido" << endl;
                    }
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 6: //Consultar Promocion TERMINADO
                try{
                    cout<<"Lista de Promociones: \n";
                    mostrarListaString(fab->getIPromocion()->ListarPromosDisponibles(fechaActual));
                    string sele;
                    cout<<"Si desea visualizar la informacion de la promocion ingrese el nombre de la promocion, de manera contraria ingrese 0. \n";
                    cin.get();
                    getline(cin, sele, '\n');
                    if(sele != "0"){
                        if(fab->getIPromocion()->PromosDisponibles(sele)){
                            fab->getIPromocion()->SeleccionarPromoDisponible(sele); 
                            cout<<"Productos de la promocion: ";
                            mostrarListaString(fab->getIPromocion()->ListarProductosPromo());
                            fab->getIUsuario()->SeleccionarVendedorPromo();
                            cout<< "Informacion del Vendedor: " + fab->getIUsuario()->getVendedor()->toString() << "\n";
                        }else{
                            throw(0);
                        }
                    }  
                }
                catch(int numError){
                    if(numError == 0){
                        cout << "Error: El nombre de la Promocion es invalido" << endl;
                    }
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 7:  //Realizar compra 
                try{
                    if ((fab->getIUsuario()->CantidadClientes() == 0) || (fab->getIProducto()->CantidadProductos() == 0)){
                        throw("Datos insuficientes");
                    }
                    string seleccionado1;
                    int select2;
                    int cantidad;
                    set<int> agregados;
                    DTDetalleCompra Detalles = DTDetalleCompra(fechaActual);
                    for (string aImprimir :fab->getIUsuario()->ListaClientes()){
                        cout << aImprimir + "\n";
                    }
                    fab->getIUsuario()->SeleccionarCliente("");
                    while(fab->getIUsuario()->getCliente() == nullptr){
                        cout << "seleccione un cliente con su nombre" << endl;
                        cin.get();
                        getline(cin, seleccionado1, '\n');
                        fab->getIUsuario()->SeleccionarCliente(seleccionado1);
                        if (fab->getIUsuario()->getCliente() == nullptr) {
                            cout << "seleccion invalida, elija de nuevo";
                        }
                    }
                    for (string aImprimir :fab->getIProducto()->ListarProductos()){
                        cout << aImprimir + "\n";
                    }
                    cout << "ingrese '0' como codigo para finalizar la seleccion de productos" << endl;
                    select2 = 1;
                    while (select2 != 0)
                    {
                        cout << "seleccione el codigo del producto" << endl;
                        cin >> select2;
                        if ((select2 == 0) || (fab->getIProducto()->SeleccionarProducto(select2) == nullptr)){
                            if (select2 != 0) cout << "seleccion invalida, elija de nuevo" << endl;
                        } 
                        else if (agregados.find(select2) != agregados.end()){
                            cout << "No se puede agregar el mismo producto dos veces, elija otro producto" << endl;
                        }
                        else{
                            cout << "Seleccione la cantidad que desea comprar" << "\n";
                            cin >> cantidad;
                            if (cantidad > fab->getIProducto()->SeleccionarProducto(select2)->getStock()){
                                cout << "No hay suficientes en stock para realizar la compra, no se agrego el producto" << endl;
                            } 
                            else{
                                agregados.insert(select2);
                                fab->getICompra()->insertarCompraProducto(cantidad, select2);
                            }
                        }
                    }
                    if (agregados.size() > 0){
                        Detalles = fab->getICompra()->getDetalles(fechaActual);
                        for (string aListar :Detalles.ImprimirDetalles()){
                            cout << aListar << "\n";
                        }
                        do{
                            cout << "Desea realizar compra? (si = 1, no = 2)";
                            cin >> select2;
                            switch(select2)
                            {
                                case 1:
                                    fab->getICompra()->ConfirmarCompra(Detalles, fab->getIUsuario()->getCliente());
                                    break;
                                case 2:
                                    fab->getICompra()->DescartarCompra();
                                default:
                                    cout << "seleccion invalida, seleccione nuevamente";
                                    break;
                            }
                        }
                        while ((select2 != 1) && (select2 != 2));
                    }
                    cout <<"seleccione otro caso" << "\n";
                    break;
                }
                catch(string a){
                    if (a == "Datos insuficientes"){
                        cout << "No existen los datos necesarios para realizar este caso de uso (al menos un cliente y un producto)";
                    }
                    else{
                        cout << "ocurrio un error desconocido";
                    }
                }
                break;
            case 8: //Dejar comentario NO TERMINADO
                try
                {
                    string seleccionado1;
                    string seleccionado2;
                    int selec3;
                    int selec4;
                    if (fab->getIUsuario()->CantidadUsuarios() == 0){
                        throw ("No Usuarios");
                    }
                    if(fab->getIProducto()->CantidadProductos() == 0){
                        throw ("No Productos");
                    }
                    for(string &aImprimir:fab->getIUsuario()->ListarUsuarios()) 
                    {
                        cout << aImprimir << "\n";
                    }
                    Usuario* SelecUser = nullptr;
                    while(SelecUser == nullptr){
                        cout << "ingrese el usuario que desea seleccionar " << endl;
                        cin.get(); 
                        getline(cin, seleccionado1, '\n');
                        SelecUser = fab->getIUsuario()->getUsuario(seleccionado1);
                        if (SelecUser == nullptr)
                        {
                            cout << "seleccion invalida, elija de nuevo \n";
                        }
                    }
                    cout << "Desea dejar un comentario en un producto (1) o responder a un comentario(2)" << endl;
                    cin >> selec4;
                    cout << to_string(selec4) << endl;
                    switch (selec4)
                    {
                    case 1:{
                        for(auto [key,val] :fab->getIProducto()->getProductos())
                        {
                            cout << to_string(val->getId()) + ": " + val->getNombre() << endl;
                        }
                        Producto* SelecProd = nullptr;
                        while(SelecProd == nullptr){
                            cout << "ingrese el id del producto que desea seleccionar" << endl;
                            cin >> selec3;
                            SelecProd = fab->getIProducto()->SeleccionarProducto(selec3);
                            if (SelecProd == nullptr)
                            {
                                cout << "seleccion invalida, elija de nuevo";
                            }
                        }
                        cout << "ingrese su comentario" << endl;
                        cin.ignore(80, '\n');
                        getline(cin, seleccionado2, '\n');
                        fab->getIComentario()->ComentarioNuevo(seleccionado2,fechaActual,SelecProd,SelecUser);
                        break;
                    }
                    case 2:{
                        if (fab->getIComentario()->ListarComentarios().size() == 0){
                            throw("No comentarios");
                        }
                        for(string aListar: fab->getIComentario()->ListarComentarios()){
                            cout << aListar << "\n";
                        }
                        Comentario* SelecCom = nullptr;
                        while (SelecCom == nullptr){
                            cout << "Seleccione el id del comentario al que desea responder" << endl;
                            cin >> selec4;
                            if (selec4<26 || selec4>fab->getIComentario()->getcantidad())
                            {
                                cout << "seleccion invalida, elija de nuevo";
                            }else{
                                SelecCom = fab->getIComentario()->seleccionarComentario(selec4);
                            }
                        }
                        cout << "ingrese su respuesta" << endl;
                        cin.get();
                        getline(cin, seleccionado2, '\n');
                        fab->getIComentario()->Responder(seleccionado2, SelecCom->getProducto(), SelecCom, fechaActual, SelecUser);
                        break;
                    }
                    default:
                        throw("opcion");
                        break;
                    }
                } 
                catch(string a)
                {
                    if (a == "No Usuarios"){
                    cout << "ERROR: No existen Usuarios en el sistema" << endl;
                    }
                    else if(a == "No Productos"){
                        cout << "ERROR: No existen Productos en el sistema" << endl;
                    }
                    else if(a == "No Comentarios"){
                        cout << "ERROR: No hay comentarios en el producto seleccionado" << endl;
                    }
                    else if(a == "opcion"){
                        cout << "ERROR: Se selecciono una opción fuera de limites" << endl;
                    }
                }
                catch(...){
                    cout << "ERROR" << endl;
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 9:{ //Eliminar Comentario TERMINADO
                try{
                    IUsuario* controladorUsuario = fab->getIUsuario();
                    IComentario* controladorComentario = fab->getIComentario();
                    for(string i : controladorUsuario->ObtenerUsuarios()){
                        cout << i << endl;
                    }
                    cout << "Seleccione un usuario" << endl;
                    string usuario;
                    cin >> usuario;
                    Usuario* usu = controladorUsuario->getUsuario(usuario);
                    if(controladorComentario->ListarComentariosUsuario(usu).empty()){
                        throw(0);
                    }
                    for(string c : controladorComentario->ListarComentariosUsuario(usu)){
                        cout << c << endl;
                    }
                    cout << "Seleccione un comentario escribiendo su id" << endl;
                    int idcomentario;
                    cin >> idcomentario;

                    controladorComentario->seleccionarComentario(idcomentario);
                    controladorComentario->EliminarHilo();
                    cout << "Comentario e hilo eliminados" << endl;
                }
                catch(int numError){
                    if(numError == 0){
                        cout << "El usuario no tiene comentarios" << endl;
                    }
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            }
            case 10: //Enviar Producto TERMINADO
                try{
                    IProducto* controladorProducto = fab->getIProducto();
                    IUsuario* controladorUsuario = fab->getIUsuario();
                    ICompra* controladorCompra = fab->getICompra();
                    if(controladorUsuario->CantidadVendedores() == 0){
                        throw(1);
                    }
                    if(controladorProducto->CantidadProductos() == 0){
                        throw(3);
                    }
                    cout << "Elija un vendedor de la lista provista" << endl;
                    for(string &i:controladorUsuario->ListarVendedores()){
                        cout << i << endl;
                    }
                    string nombreVend;
                    cin >> nombreVend;
                    Vendedor* SelecVend = controladorUsuario->getVendedor(nombreVend);
                    if(SelecVend == nullptr){
                        throw(2);
                    }
                    cout << "Elija la id de un producto de la lista provista" << endl;
                    /*for(string i: controladorProducto->ListarProductos()){
                        cout << i << endl;
                    }*/
                    for(auto prod: SelecVend->getProductos()){
                        cout << to_string(prod->getCodigo()) + " " + prod->getNombre() << endl;
                    }
                    int idActual;
                    cin >> idActual;
                    if(controladorProducto->SeleccionarProducto(idActual) == nullptr){
                        throw(4);
                    }
                    cout << "Seleccione una compra segun su id" << endl;
                    for(Compra* compra: controladorCompra->getCompras()){
                        if(compra->perteneceCompra(idActual) && !compra->getProductos()[idActual]->getEnviado()){
                            cout << to_string(compra->getId()) << ": " << compra->getFecha().toString() << endl;
                        }
                    }
                    int idCompra;
                    cin >> idCompra;
                    if(controladorCompra->getCompra(idCompra) == nullptr){
                        throw(5);
                    }
                    controladorCompra->marcarEnviado(idActual,idCompra);
                }
                catch(int numError){
                    switch (numError){
                        case 1:
                            cout << "ERROR: No hay vendedores en el sistema" << endl;
                            break;
                        case 2:
                            cout << "ERROR: El vendedor seleccionado no existe" << endl;
                            break;
                        case 3:
                            cout << "ERROR: No hay productos en el sistema" << endl;
                            break;
                        case 4:
                            cout << "ERROR: El producto seleccionado no existe" << endl;
                            break;
                        case 5:
                            cout << "ERROR: La compra seleccionada no existe" << endl;
                            break;
                        default:
                            cout << "ERROR: Error desconocido" << endl;
                            break;
                    }
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 11: //Expediente Usuario TERMINADO
                try{
                    string sele1;
                    cout << "Lista de Usuarios: \n";
                    mostrarListaString(fab->getIUsuario()->ListarUsuariosNombre());
                    cout << "\n Seleccione el nombre del Usuario: ";
                    cin.get();
                    getline(cin, sele1, '\n');
                    Usuario* chequeo = fab->getIUsuario()->getUsuario(sele1);
                    if(chequeo == nullptr){
                        throw(0);
                    }
                    fab->getIUsuario()->SeleccionarUsuario(sele1);//nombre no valido 
                    if(fab->getIUsuario()->getVendedor() != nullptr){
                        cout << fab->getIUsuario()->InfoVendedor(fechaActual);
                    }else{
                        cout << fab->getIUsuario()->InfoCliente();
                    }
                }
                catch(int numError){
                    switch(numError){
                        case 0:
                            cout << "Error: El nombre del Usuario es invalido" << endl;
                            break;
    
                    }
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 12: //Suscribirse a Notificaciones TERMINADO
                try{
                    IUsuario* controladorUsu = fab->getIUsuario();
                    for(string i : controladorUsu->ListaClientes()){
                        cout << i << endl;
                    }
                    cout << "Ingrese el Nickname del cliente que desea suscribir" << endl;
                    string nick;
                    cin.get();
                    getline(cin, nick, '\n');
                    list<string>* listaVendedores = fab->getIUsuario()->ListarVendedoresNoSuscrito(nick);
                    if(listaVendedores == nullptr) throw("Error: Nickname de Cliente Invalido");
                    cout << "Vendedores No Suscritos por el Cliente" << endl;
                    mostrarListaString(listaVendedores);

                    nick = "1";
                    cout << "Ingrese el Nickname del vendedor a suscribir y luego 0 para salir" << endl;
                    while(nick != "0"){
                        getline(cin, nick, '\n');
                        if(nick != "0"){
                            if(!fab->getIUsuario()->SeleccionarVendedorNotificacion(nick)) throw("Error: Nickname de Vendedor Invalido");
                        }
                    }
                    
                    fab->getIUsuario()->ConfirmarSuscripcion();
                }
                catch(string ex){
                    cout << ex;
                }
                catch(...){
                    cout << "Ocurrio un error" << endl;
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 13: //Consulta Notificaciones TERMINADO
                try{
                    string sele2;
                    cout<<"Lista de Clientes: \n";
                    mostrarSetString(fab->getIUsuario()->ListaClientes());
                    cout<<"Ingrese el Nickname del Cliente: ";
                    cin.ignore(80, '\n');
                    getline(cin, sele2, '\n');
                    if(fab->getIUsuario()->getClientes().find(sele2) != fab->getIUsuario()->getClientes().end()){
                        if(fab->getIUsuario()->ConsultaNotificaciones(sele2).size() != 0){
                             for(auto x: fab->getIUsuario()->ConsultaNotificaciones(sele2)){
                                    cout << x.toString();}  
                            fab->getIUsuario()->getCliente()->LimpiarNotificaciones(); 
                        }else{
                            cout<<"El cliente no cuenta con Notificaciones. \n";
                        }
                            
                        
                    }else{
                        throw(0);
                    }
                }
                catch(int Error){
                    if(Error == 0){
                        cout << "Error: El nickname del cliente es invalido" << endl;        
                    }
                    
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 14: //Eliminar Suscripcion TERMINADO
                try{
                    IUsuario* controladorUsu = fab->getIUsuario();
                    for(string i : controladorUsu->ListaClientes()){
                        cout << i << endl;
                    }
                    cout << "Ingrese el Nickname del cliente que desea desuscribir" << endl;
                    string nick;
                    cin.get();
                    getline(cin, nick, '\n');
                    list<string>* listaVend = fab->getIUsuario()->ListarVendedoresSuscritosCliente(nick);
                    if(listaVend == nullptr) throw(0);
                    cout << "Vendedores Suscritos por el Cliente" << endl;
                    mostrarListaString(listaVend);

                    nick = "1";
                    cout << "Ingrese el Nickname del vendedor a desuscribir o 0 para salir" << endl;
                    while(nick != "0"){
                        getline(cin, nick, '\n');
                        if(nick != "0"){
                            if(!fab->getIUsuario()->SeleccionarVendedorNotificacion(nick)) throw(1);
                        }
                    }
                    
                    fab->getIUsuario()->EliminarSuscripcion();
                }
                catch(string ex){
                    cout << "Ocurrio un Error";
                }
                cout <<"seleccione otro caso" << "\n";
                break;
            case 15: //Salir
                break;
            default:
                cout <<"seleccion invalida, intente de nuevo";
                break;
        }
    }
}

int main(){
    bool cargarDatos = true;
    cout << "Elija una fecha para comenzar" << endl;
    CambiarFecha();
    while(true){
        cout <<"seleccione una opcion ingresando su numero correspondiente" << "\n";
        cout <<"1: realizar caso de uso" << "\n";
        cout <<"2: cargar datos" << "\n";
        cout <<"3: cambiar fecha" << "\n";
        cout <<"4: detener programa" << "\n";
        int seleccionado;
        cin >> seleccionado;
        switch (seleccionado) {
            case 1:
                RealizarCaso();
                break;
            case 2:
                if(cargarDatos){
                    CargarDatos();
                    cargarDatos = false;
                }
                break;
            case 3:
                CambiarFecha();
                break;
            case 4:
                return 0;
            default:
                cout <<"seleccion invalida, intente de nuevo";
                break;
        }
    }
}



