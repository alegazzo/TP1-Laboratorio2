#include <iostream>
#include <cstdlib>
#include<cstdio>
#include <ctime>

 using namespace std;
  #include"usuario.h"
  #include"entrenamiento.h"


Fecha cargarFecha(){
    Fecha fecha;
    cout<<endl;
    cout<<"Ingrese dia: ";
    cin>>fecha.dia;
    cout<<endl;
    cout<<"Ingrese mes: ";
    cin>>fecha.mes;
    cout<<endl;
    cout<<"Ingrese año: ";
    cin>>fecha.anio;
    cout<<endl<<endl;

    return fecha;
}
/** VALIDACION DE FECHA PARA USUARIO
*/
void validarFecha (Usuario *aux){

    Fecha fechaValidar;
    bool fecha_correcta = false;
    bool bandera = false;
    int dia_maximo;
    while(fecha_correcta==false || bandera== false){
            fechaValidar = cargarFecha();
            if ( fechaValidar.mes >= 1 && fechaValidar.mes <= 12 ){
                  switch ( fechaValidar.mes ){
                      case  1 :
                      case  3 :
                      case  5 :
                      case  7 :
                      case  8 :
                      case 10 :
                      case 12 :
                          dia_maximo = 31;
                      break;

                      case  4 :
                      case  6 :
                      case  9 :
                      case 11 :
                          dia_maximo = 30;
                      break;

                      case  2 :
                          if ( fechaValidar.anio % 4 == 0 && (fechaValidar.anio % 100 != 0 || fechaValidar.anio % 400 == 0) ){
                            dia_maximo = 29;
                          }
                          else{
                                dia_maximo = 28;
                          }

                      break;

                  }

                  if ( fechaValidar.dia >= 1 && fechaValidar.dia <= dia_maximo ){
                      fecha_correcta = true;
                      bandera = validarEdad(fechaValidar);
                  }
            }

           if (bandera == 0){
                  mensajeError("FECHA ERRONEA O EDAD INSUFICIENTE");
                  system("color 70");
               cout << "REINGRESE LA FECHA DE NACIMIENTO:" << endl;

           }

    }
   aux->nacimiento.dia  =  fechaValidar.dia;
   aux->nacimiento.mes  =  fechaValidar.mes;
   aux->nacimiento.anio =  fechaValidar.anio;

return;
}



bool validarEdad ( Fecha fechaValidar){
Fecha hoy;
int aux, edad;

hoy = obtenerFechaDelSistema();
if (fechaValidar.anio < 1900)return false;     ///* no se puede ingresar un año de nacimiento menor a 1900 *///
aux = hoy.anio - fechaValidar.anio;   ///* 5/11/1996   04/11/2020    2020 - 1996= 24     si el mes actual es mas chico al nacimiento se le resta 1     si el dia actual es menor, tambien se resta 1 *///
edad = aux;
if(hoy.mes < fechaValidar.mes){
    edad = aux - 1;
}
    else{
        if(hoy.mes == fechaValidar.mes){
            if(hoy.dia < fechaValidar.dia){
                edad = aux -1;
            }
        }

    }

if (edad < 14){                 ///* si da menor a 14 significa que o es menor o el año es mayor al actual, por lo tanto la edad seria negativa *///
    return false;
}
return true;

}

/**VALIDACION DE FECHA PARA ENTRENAMIENTO
*/
 void validarFechaEntreno(Entrenamiento *aux){

    Fecha fechaValidar;
    bool fecha_correcta = false;
    bool bandera = false;
    int dia_maximo;
      while(fecha_correcta==false || bandera== false){
            fechaValidar = cargarFecha();
         if ( fechaValidar.mes >= 1 && fechaValidar.mes <= 12 ){
            switch ( fechaValidar.mes ){
                case  1 :
                case  3 :
                case  5 :
                case  7 :
                case  8 :
                case 10 :
                case 12 :
                    dia_maximo = 31;
                break;

                case  4 :
                case  6 :
                case  9 :
                case 11 :
                    dia_maximo = 30;
                break;

                case  2 :
                    if ( fechaValidar.anio % 4 == 0 && (fechaValidar.anio % 100 != 0 || fechaValidar.anio % 400 == 0) ){
                      dia_maximo = 29;
                    }
                    else{
                          dia_maximo = 28;
                    }

                break;

            }

            if ( fechaValidar.dia >= 1 && fechaValidar.dia <= dia_maximo ){
                fecha_correcta = true;
                bandera = validarFechaEntreno(fechaValidar);
            }
        }

            if (bandera == 0){
                  mensajeError("ERROR, FECHA INCORRECTA");
                  system("color B0");
            }

    }
   aux->fechaEntreno.dia=  fechaValidar.dia;
   aux->fechaEntreno.mes=  fechaValidar.mes;
   aux->fechaEntreno.anio= fechaValidar.anio;

return;
}



bool validarFechaEntreno(Fecha aux){
Fecha hoy;

hoy=obtenerFechaDelSistema();

if(hoy.anio>aux.anio){
    return true;
}
if(hoy.anio==aux.anio){
    if(hoy.mes>aux.mes){
       return true;
    }

    else{
       if(hoy.mes==aux.mes){

            if(hoy.dia>=aux.dia){
                return true;
            }

        }
    }
}
return false;

};

/** FECHA DEL SISTEMA */
Fecha obtenerFechaDelSistema(){
    time_t t;
    Fecha aux;
    struct tm *f;
    t = time(NULL);
    f = localtime(&t);
    aux.anio = f->tm_year+1900;
    aux.mes  = f->tm_mon+1;
    aux.dia  = f->tm_mday;
    return aux;
}

