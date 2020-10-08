#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>


 using namespace std;
#include "rlutil.h"
#include"usuario.h"
#include"submenus.h"
#include"entrenamiento.h"

Entrenamiento cargarEntrenamiento(){
    Entrenamiento aux;
    aux.id=cantidad_entrenos()+1;
    cout<<endl;
    cout<<"Ingrese ID Usuario: ";
     while(validar_idUsuario(&aux)==false){
          mensajeError("USUARIO NO ENCONTRADO");
          system("color B0");
           cout<<"Ingrese ID Usuario: ";
     }
    cout<<endl;
    cout<<"Ingrese fecha de entrenamiento: ";
      validarFechaEntreno(&aux);
    cout<<endl;
    cout<<"Ingrese actividad: ";
    validar_Actividad(&aux);
    cout<<endl;
    cout<<"Ingrese calorias: ";
     validarCalorias (&aux) ;
    cout<<endl;
    cout<<"Ingrese tiempo en minutos: ";
     validarTiempo(&aux);
    cout<<endl;
      return aux;
}


 ///devuelve cantidad registros entrenamiento
 int cantidad_entrenos() {
	int cantidad;
	FILE* pFile;

	pFile = fopen("Entrenamiento.dat", "rb");

	if (pFile == NULL) {
		return 0;
	}

	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(Entrenamiento);
	fclose(pFile);

	return cantidad;
}



///VALIDACIONES

bool validar_idUsuario(Entrenamiento *reg){
    Usuario aux;
    int pos;
    int id;
    cin>>id;
    pos=buscarUsuario(id);
    if(pos==(-1)){
        return false;
    }
    aux=obtenerUsuario(pos);
    if(aux.estado){
            reg->idUsuario=aux.codigo;
            return true;
      }
      else{
            return false;
      }

}



void validar_Actividad(Entrenamiento *aux){
    int act;
    cin>>act;

    while(act<1||act>5){

            mensajeError("ACTIVIDAD NO VÁLIDA");
            system("color B0");
            cout<<"Vuelva a ingresar actividad";
            cin>>act;

      }

    switch(act){
            case 1:
            case 2:
            case 3:aux->actividad=act;
            break;
            case 4:
            case 5:
                  if(validar_AptoFisico(aux)){
                  aux->actividad=act;
            }
            else {
                  mensajeError("Usuario no tiene apto médico aprobado");
                  system("color B0");
                  cout<<"Ingrese otra actividad"<<endl;
                  validar_Actividad(aux);

            }
            break;
    }
}

bool validar_AptoFisico(Entrenamiento *reg){
    Usuario aux;
    int pos;

    pos=buscarUsuario(reg->idUsuario);
    aux=obtenerUsuario(pos);
      if(aux.aptoMedico){
            return true;
      }

    return false;

};


void  validarCalorias (  Entrenamiento *aux ) {
    float calorias;
    cin>> calorias;
      while(calorias <= 0 ) {
            mensajeError("ERROR, DATO ERRONEO");
            system("color B0");
            cout<<"Ingrese calorías: ";
            cin>> calorias;
      }
      aux->calorias = calorias;
 }


void  validarTiempo(Entrenamiento *aux) {
    int tiempo;
    cin>> tiempo;
      while(tiempo<= 0 ) {
            mensajeError("DATO INVÁLIDO");
            system("color B0");
            cout<<" Ingrese Tiempo en minutos: ";
            cin>> tiempo;
      }
      aux->minutos = tiempo;
 }

/// ARCHIVO

void mostrarRegEntreno( Entrenamiento reg) {
      cout<<" ID ENTRENAMIENTO : "<<reg.id<<endl;
      cout<<" ID USUARIO: "<<reg.idUsuario<<endl;
      cout<<" FECHA DE ENTRENAMIENTO: " <<reg.fechaEntreno.dia<<" / "<<reg.fechaEntreno.mes<<" / "<<reg.fechaEntreno.anio<<endl;
      cout<<" ACTIVIDAD: "<< reg.actividad<<endl;
      cout<<" CALORIAS: "<<reg.calorias<<endl;
      cout<<" TIEMPO: "<<reg.minutos<<endl;
      cout<<endl<<endl;
}
void mostrarRegEntreno( Entrenamiento reg, int x) {

      if(x==2){
            gotoxy(2, 6);
            cout<<"ID ENTRENAMIENTO" ;
            gotoxy(21,6);
            cout<<"ID USUARIO" ;
            gotoxy(36,6);
            cout<<"FECHA ENTRENAMIENTO" ;
            gotoxy(57,6);
            cout<<"ACTIVIDAD ";
            gotoxy(72,6);
            cout<<"CALORÍAS";
            gotoxy(84,6);
            cout<<"TIEMPO";
            cout<<endl<<endl;
      }

      gotoxy(2, 6+x);
      cout<<reg.id ;
      gotoxy(21,6+x);
      cout<<reg.idUsuario ;
      gotoxy(36,6+x);
      cout<<reg.fechaEntreno.dia<<" / "<<reg.fechaEntreno.mes<<" / "<<reg.fechaEntreno.anio<<endl;
      gotoxy(57,6+x);
      cout<<reg.actividad;
      gotoxy(72,6+x);
      cout<<reg.calorias;
      gotoxy(84,6+x);
      cout<<reg.minutos;

      cout<<endl<<endl;
      cout<<endl<<endl;

}
bool guardarEntrenamiento(Entrenamiento reg) {

    FILE *puntero;
    puntero = fopen("Entrenamiento.dat"  , "ab" );
    if ( puntero == NULL ){
            return false;

      }

    fwrite(&reg, sizeof(Entrenamiento), 1 , puntero ) ;
    fclose(puntero);
    mensajeExito();
    return true;
}




void listarEntrenamientos(){
 Entrenamiento reg;
 int x = 0;
 FILE *puntero;
    puntero = fopen("Entrenamiento.dat"  , "rb" );
    if ( puntero == NULL ){
            cout<<"No se puede leer los datos"<<endl;

      }

    while(  fread(&reg, sizeof(Entrenamiento), 1 , puntero )  ){
            x+= 2;
            mostrarRegEntreno(reg , x );
      }

    fclose(puntero);

    system("pause");
    system("cls");
}

void modificarEntrenamiento () {
      Entrenamiento aModificar;
      int ID, pos;
      bool estado;
      cout<<"Ingrese el ID del entrenamiento a modificar: "<<endl;
      cin>>ID;
      pos =  buscarEntrenamiento(ID) ;
      if(pos>= 0) {
           aModificar = obtenerEntrenamiento(pos);
      }
      else  {
            mensajeError("NO ENCONTRADO");
            return;
      }
      cout<<"-----ENTRENAMIENTO A MODIFICAR ----"<<endl;
      mostrarRegEntreno(aModificar);
      cout<<endl;
      cout<<endl;
      cout<<"INGRESE TIEMPO: ";
       validarTiempo(&aModificar);
      cout<<"INGRESE CALORIAS: ";
      validarCalorias (&aModificar);

     estado =  guardarEntrenamientoModificado( aModificar, pos);
     if (estado){
            system("cls");
            mensajeExito();
     }
 }

 int buscarEntrenamiento(int cod){
     Entrenamiento reg;
      FILE *puntero;
      int pos = 0;
      puntero = fopen("Entrenamiento.dat"  , "rb" );
      if ( puntero == NULL ){
            cout<<"No se puede continuar"<<endl;
            return -2;
      }
      while( fread(&reg, sizeof(Entrenamiento), 1 , puntero ) ) {

            if( cod == reg.id ){
                  fclose(puntero);
                  return pos;
            }
            pos ++;
      }
      fclose (puntero);
      return -1;


 };


Entrenamiento obtenerEntrenamiento(int pos){

    Entrenamiento reg;
      FILE *puntero;
      puntero = fopen("Entrenamiento.dat"  , "rb" );
      if ( puntero == NULL ){
            cout<<"No se puede continuar"<<endl;
      }
      fseek (puntero, sizeof (Entrenamiento) * pos, SEEK_SET) ;
      fread(&reg, sizeof(Entrenamiento), 1 , puntero ) ;
      fclose(puntero);
      return reg;


 }


bool guardarEntrenamientoModificado(Entrenamiento reg, int pos){
FILE *puntero;
    puntero = fopen("Entrenamiento.dat"  , "rb+" );
    if ( puntero == NULL ){
            cout<<"No se puede continuar"<<endl;
            system("pause");
            system("cls");
            return false;

      }
    fseek (puntero, sizeof (Entrenamiento) * pos, SEEK_SET) ;
    fwrite(&reg, sizeof(Entrenamiento), 1 , puntero ) ;
    fclose(puntero);
    return true;



};




 void listarEntrenamientosPorID() {
      int ID, pos;
      Entrenamiento reg;
      cout<<"Ingrese el ID de entrenamiento buscado: "<<endl;
      cin>>ID;
      pos =  buscarEntrenamiento (ID);
      if(pos>= 0) {
            reg = obtenerEntrenamiento(pos);
            mostrarRegEntreno(reg);
      }
      else  {
            mensajeError("NO ENCONTRADO");

      }
      system("pause");
      system("cls");

 }



void listarEntrenamientosPorIDusuario(){
    int cod;
    int pos;
    Usuario reg;

    cout<<"Ingrese el id del usuario que ha realizado el entrenamiento: "<<endl;
    cin>>cod;

    pos=buscarUsuario (cod );

     if(pos>= 0) {

        reg=obtenerUsuario (pos);

         if(reg.estado){
                  system("cls");
                  gotoxy(32, 1);
                  cout<<"-----------------------------------------------------"<<endl;
                  gotoxy(37, 2);
                  cout<<"ENTRENAMIENTOS DE "<<reg.nombres<<" "<<reg.apellidos<<endl;
                  gotoxy(32, 3);
                  cout<<"-----------------------------------------------------"<<endl;
                  cout<<endl;
                  cout<<endl;
            MostrarEntrenamientosPorUsuario(cod);
           }
           else{
                  mensajeError("NO ENCONTRADO");
           }
      }

    else{
          mensajeError("NO ENCONTRADO");
      }

}

void MostrarEntrenamientosPorUsuario(int cod){

 Entrenamiento reg;
 int x = 0;
 FILE *puntero;
    puntero = fopen("Entrenamiento.dat"  , "rb" );
    if ( puntero == NULL ){
            cout<<"No se puede leer los datos"<<endl;

      }

    while(  fread(&reg, sizeof(Entrenamiento), 1 , puntero )  ){
            if(cod==reg.idUsuario){
                  x += 2;
                mostrarRegEntreno(reg , x);
            }
            //else{
                //  x-=2;
         //   }
      }

    fclose(puntero);

    system("pause");
    system("cls");
}


