#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>


 using namespace std;

 #include"usuario.h"
#include"submenus.h"
#include"rlutil.h"


 Usuario cargarUsuario(){
    Usuario aux;

    cout<<"Ingrese ID del usuario: ";
    if(validarID(&aux)==false){
        mensajeError("No se pudo abrir el archivo");
        aux.estado = false;
        return aux;
    }
    cout<<"Ingrese nombres: ";
    cin.ignore();
    validarNombre ( &aux );
    cout<<endl;
    cout<<"Ingrese apellido: ";
    validarApellido( & aux);
    cout<<endl;
    cout<<"-fecha de Nacimiento- ";
    validarFecha(&aux);
    cout<<"Ingrese altura: ";
     validarAltura (& aux);
    cout<<endl;
    cout<<"Ingrese peso: ";
    validarPeso (& aux );
    cout<<endl;
    cout<<"Ingrese perfil de actividad: ";
     validacionPerfil ( &aux );
    cout<<endl;
    cout<<"Ingrese apto médico: ";
    validarAptoMedico(& aux );
    aux.estado = true;

      system("cls");
      return aux;
}


 /// GUARDAR EN EL ARCHIVO
bool guardarUsuario (Usuario reg) {

    FILE *puntero;
    puntero = fopen("Usuarios.dat"  , "ab" );
    if ( puntero == NULL ){
            return false;

      }

    fwrite(&reg, sizeof(Usuario), 1 , puntero ) ;
    fclose(puntero);
    mensajeExito();
    return true;
}

void  mostrarUsuarios() {
 Usuario reg;
 int x = 0;
 FILE *puntero;
    puntero = fopen("Usuarios.dat"  , "rb" );
    if ( puntero == NULL ){
            cout<<"No se puede leer los datos"<<endl;

      }
    while(  fread(&reg, sizeof(Usuario), 1 , puntero )  ){
            system("color 70");
         /// Para que los registros se acomoden uno debajo del otro. Modifica el valor de y en gotoxy.
            if(reg.estado) {
                  x+=2;
                  mostrarRegistro (reg , x);
            }
      }

    fclose(puntero);

    system("pause");
    system("cls");
}

void mostrarRegistro( Usuario reg, int x) {

      if(x==2){
            gotoxy(2, 3);
            cout<<"ID" ;
            gotoxy(13,3);
            cout<<"NOMBRE" ;
            gotoxy(34,3);
            cout<<"APELLIDO" ;
            gotoxy(49,3);
            cout<<"FECHA DE NACIMIENTO ";
            gotoxy(74,3);
            cout<<"ALTURA";
            gotoxy(82,3);
            cout<<"PESO";
            gotoxy(89,3);
            cout<<"PERFIL  ACTIVIDAD ";
            gotoxy(109,3);
            cout<<"APTO MEDICO ";

            cout<<endl<<endl;
      }
      if (reg.estado) {
            gotoxy(2, 3+x);
            cout<<reg.codigo ;
            gotoxy(13,3+x);
            cout<<reg.nombres ;
            gotoxy(34,3+x);
            cout<<reg.apellidos;
            gotoxy(49,3+x);
            cout<<reg.nacimiento.dia<<" / "<<reg.nacimiento.mes<<" / "<<reg.nacimiento.anio;
            gotoxy(74,3+x);
            cout<<reg.altura;
            gotoxy(82,3+x);
            cout<<reg.peso;
            gotoxy(92,3+x);
            cout<<reg.perfilActividad;
            gotoxy(109,3+x);
            cout<<reg.aptoMedico;

            cout<<endl<<endl;
            cout<<endl<<endl;
      }

}
void mostrarRegistro (Usuario reg){

      cout<<"  ID : "<<reg.codigo<<endl;
      cout<<"  NOMBRE: "<<reg.nombres<<endl;
      cout<<"  APELLIDO: "<<reg.apellidos<<endl;
      cout<<"  FECHA DE NACIMIENTO: " <<reg.nacimiento.dia<<" / "<<reg.nacimiento.mes<<" / "<<reg.nacimiento.anio<<endl;
      cout<<"  ALTURA: "<< reg.altura<<endl;
      cout<<"  PESO: "<<reg.peso<<endl;
      cout<<"  PERFIL DE ACTIVIDAD: "<<reg.perfilActividad<<endl;
      cout<<"  APTO MEDICO: "<<reg.aptoMedico<<endl;
      cout<<endl<<endl;
}


int buscarUsuario (int cod ) {

      Usuario reg;
      FILE *puntero;
      int pos = 0;
      puntero = fopen("Usuarios.dat"  , "rb" );
      if ( puntero == NULL ){
            cout<<"No se puede continuar"<<endl;
            return -2;
      }
      while( fread(&reg, sizeof(Usuario), 1 , puntero ) ) {

            if( cod == reg.codigo ){
                  fclose(puntero);
                  return pos;
            }
            pos ++;
      }
      fclose (puntero);
      return -1;
}

 void listarPorID() {
      int ID, pos;
      Usuario reg;
      cout<<"Ingrese el ID de usuario buscado: "<<endl;
      cin>>ID;
      cout<<endl<<endl;
      pos =  buscarUsuario (ID);
      if(pos>= 0) {
          reg = obtenerUsuario(pos);
            if(reg.estado== false){
                  mensajeError("ID NO ENCONTRADO");
                  return;
            }
          mostrarRegistro(reg);
            system("pause");
            system("cls");

      }
      else  {
           mensajeError("ID NO ENCONTRADO");

      }
 }


 ///MODIFICAR USUARIO
 Usuario obtenerUsuario (int pos) {
    Usuario reg;
      FILE *puntero;
      puntero = fopen("Usuarios.dat"  , "rb" );
      if ( puntero == NULL ){
            reg.estado = false;
            return reg;
      }
      fseek (puntero, sizeof (Usuario) * pos, SEEK_SET) ;
      fread(&reg, sizeof(Usuario), 1 , puntero ) ;
      fclose(puntero);
      return reg;


 }

 void modificarUsuario () {
      Usuario aModificar;
      int ID, pos;
      bool estado;
      cout<<"Ingrese el ID de usuario a modificar: "<<endl;
      cin>>ID;
      pos =  buscarUsuario (ID);
      if(pos>= 0) {
           aModificar = obtenerUsuario(pos);
      }
      else  {
            cout<<"No encontrado"<<endl;
            system("pause");
            system("cls");
            return;
      }
      cout<<"-----USUARIO A MODIFICAR ----"<<endl;
      mostrarRegistro(aModificar);
      cout<<endl;
      cout<<endl;
      cout<<"INGRESE NUEVO PESO: ";
      validarPeso( &aModificar );
      cout<<"INGRESE NUEVO APTO MÉDICO: ";
      validarAptoMedico( &aModificar );
      cout<<"INGRESE NUEVO PERFIL DE ACTIVIDAD  : ";
      validacionPerfil( &aModificar );

     estado =  guardarUsuarioModificado( aModificar, pos);
     if (estado){
            mensajeExito();
     }
 }


 bool guardarUsuarioModificado (Usuario reg, int pos ) {
    FILE *puntero;
    puntero = fopen("Usuarios.dat"  , "rb+" );
    if ( puntero == NULL ){
            cout<<"No se puede continuar"<<endl;
            system("pause");
            system("cls");
            return false;

      }
    fseek (puntero, sizeof (Usuario) * pos, SEEK_SET) ;
    fwrite(&reg, sizeof(Usuario), 1 , puntero ) ;
    fclose(puntero);
    return true;
}

void bajaLogica(){
      Usuario aModificar;
      char opc;
      int ID, pos;
      bool estado;
      cout<<"Ingrese el ID de usuario a dar de baja: ";
      cin>>ID;
      pos =  buscarUsuario (ID);
      if(pos>= 0) {
           aModificar = obtenerUsuario(pos);
      }
      else  {
            mensajeError("USUARIO NO ENCONTRADO");
            system("color 70");
            return;
      }
      cout<<"-----USUARIO A DAR DE BAJA ----"<<endl;
      mostrarRegistro(aModificar);
      cout<<endl;
      cout<<endl;
      cout<<"¿SEGURO DESEA DAR DE BAJA AL USUARIO? (S/N)? ";
      cin>> opc;
      if (opc == 's' || opc == 'S'){
            aModificar.estado = false;
            estado =  guardarUsuarioModificado( aModificar, pos);
           if (estado){
                mensajeExito();
            }

      } else{
            return;
      }

}


/** -------VALIDACIONES-----------*/

bool validarID( Usuario *aux){

      int id , pos;
      bool bandera = false;
      cin>> id;
      while ( bandera == false ) {
            pos = buscarUsuario ( id );
            if ( (pos == -1) && id > 0 ){
                  bandera = true;
            }
            else {
                  if(pos == -2){
                        return false;
                  }
                  else{
                        mensajeError( "CÓDIGO REPETIDO / INVÁLIDO");
                        system("color 70");
                        cout <<"Ingrese un nuevo código: ";
                        cin>>id;
                  }
            }
      }
      aux->codigo = id;
      return true;
}





void  validacionPerfil (   Usuario *aux  ) {
     char perfil;
    cin>> perfil;
      while(perfil != 'A' && perfil != 'a' &&perfil != 'B' && perfil != 'b' &&perfil != 'C'&& perfil != 'c' ) {
            mensajeError("PERFIL INVÁLIDO");
            system("color 70");
            cout<<"Ingrese perfil de actividad: ";
            cin>> perfil;
      }
      aux->perfilActividad = perfil;
 }

 void  validarAptoMedico (  Usuario *aux ) {
    int apto;
    cin>> apto;
      while(apto != 1 && apto != 0 ) {
             mensajeError("APTO MÉDICO INVÁLIDO");
            system("color 70");
            cout<<"Ingrese apto medico: ";
            cin>> apto;
      }
      aux->aptoMedico = apto;
 }

 void  validarPeso (  Usuario *aux ) {
    float peso;
    cin>> peso;
      while(peso <= 0 ) {
            mensajeError("VALOR FUERA DE RANGO");
            system("color 70");
            cout<<"Ingrese peso: ";
            cin>> peso;
      }
      aux->peso = peso;
 }

 void  validarAltura (  Usuario *aux ) {
    float altura;
    cin>> altura;
      while(altura <= 0 ) {
            mensajeError("VALOR FUERA DE RANGO");
            system("color 70");
            cout<<" Ingrese altura: ";
            cin>> altura;
      }
      aux->altura = altura;
 }

void validarNombre(Usuario *aux ) {
      char nombre[50];
      int contador;
      bool bandera;
      int cant, x;
      cin.getline(nombre, 50);
      cant = strlen( nombre );

      do{
            contador = 0;
            bandera = true;
            for (x= 0; x<cant; x++){
                  if (nombre[x]== ' ' ) {
                        contador++;
                  }
            }
            if (contador == cant) {
                  mensajeError("DATO INVÁLIDO");
                  system("color 70");
                  cout<<" Ingrese nombre: ";
                  cin.getline(nombre, 50);
                  cant = strlen( nombre );
                  bandera = false;
            }
      } while( bandera == false);

      strcpy( aux->nombres, nombre );
 }

 void validarApellido (Usuario *aux ) {
      char apellido [50];
      int contador;
      bool bandera;
      int cant, x;
      cin.getline(apellido, 50);
      cant = strlen( apellido );

      do{
            contador = 0;
            bandera = true;
            for (x= 0; x<cant; x++){
                  if (apellido [x]== ' ' ) {
                        contador++;
                  }
            }
            if (contador == cant) {
                  mensajeError( "DATO INVÁLIDO");
                 system("color 70");
                  cout<<" Ingrese apellido: ";
                  cin.getline(apellido, 50);
                  cant = strlen( apellido );
                  bandera = false;
            }
      } while( bandera == false);

      strcpy( aux->apellidos, apellido );
 }

/// MENSAJES
void mensajeError( char mensaje[70]){
      system("cls");
      system("color 4F");
      cout<<mensaje<<endl;
      system("pause");
      system("cls");

 }

void mensajeExito(){
      system("cls");
      system("color 2F");
      cout<<"ACCIÓN REALIZADA CON ÉXITO"<<endl;
      system("pause");
      system("cls");


 }

int cantidad_usuarios() {
	int cantidad;
	FILE* pFile;

	pFile = fopen("Usuarios.dat", "rb");

	if (pFile == NULL) {
		return 0;
	}

	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(Usuario);
	fclose(pFile);

	return cantidad;
}











