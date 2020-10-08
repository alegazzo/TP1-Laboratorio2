#include <iostream>
#include <cstdlib>

 using namespace std;

#include"rlutil.h"
#include"usuario.h"
#include"submenus.h"
#include"entrenamiento.h"
#include"Configuracion.h"
#include"Reportes.h"



void menuReportes(){


int opc;

  while(true){
        system("color 2F ");
        gotoxy (52, 3);
        cout<<"MENÚ REPORTES"<<endl;
        gotoxy(50, 4);
        cout<<"------------------------"<<endl;
        gotoxy(48, 5);
        cout<<"1) Ejercicio 1"<<endl;
        gotoxy(48, 6);
        cout<<"2) Ejercicio 2"<<endl;
        gotoxy(50, 7);
        cout<<"------------------------"<<endl;
        gotoxy(48,8 );
        cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
        gotoxy (50, 9);
        cout<<"INGRESE UNA OPCIÓN: "<<endl;
        gotoxy (71, 9);
        cin>>opc;
        system("cls");

        switch(opc){
          case 1:
               Punto1();
          break;
          case 2:
               Punto2();
          break;
          case 0:
              system("color 5F");
              return ;
          break;
          default: mensajeError("OPCION NO VALIDA");

          break;

        }


    }


}


//Listar todos los usuarios cuya altura supere la altura promedio de los usuarios de perfil 'B'.//

void Punto1(){
 int cant;
 float promedio;
 Usuario *vec;
 Usuario  reg;
 FILE *P;

 cant = cantidad_usuarios();
 vec= (Usuario*) malloc(sizeof (Usuario)*cant);
 P = fopen("Usuarios.dat", "rb");
 if(P==NULL){
     mensajeError("ERROR: NO SE PUEDE CONTINUAR");
     system("color 0F");
     free(vec);
     return;
    }
 fread(vec,sizeof (Usuario),cant,P);
 fclose(P);


 promedio = calcularPromedio(vec,cant);
 FILE *puntero;
    puntero = fopen("Usuarios.dat"  , "rb" );
    if ( puntero == NULL ){
            cout<<"No se puede leer los datos"<<endl;
            return;
    }
    cout << "Usuarios con altura mayor al promedio de los Usuarios con perfil 'B': " << endl << endl;
    while( fread(&reg, sizeof(Usuario), 1 , puntero )  ){

            if(reg.altura > promedio){
             mostrarRegistro(reg);

            }
    }

    fclose(puntero);
    free(vec);

    system("pause");
    system("cls");
    return;
}



float calcularPromedio(Usuario vec[], int cant){
    int x;
    int contador=0;
    int acu = 0;
    float promedio;
    for(x=0;x<cant;x++){
        if(vec[x].perfilActividad == 'B'){
         acu+= vec[x].altura;
         contador++;

        }

    }
promedio = acu /contador;
return promedio;

}

 //Por cada usuario, listar los Apellidos y nombres y los códigos de las actividades que no realizó.//

void Punto2(){



listarNombres();



system("pause");
system("cls");

return;



}

void listarNombres(){
FILE *P;
Usuario reg;

P= fopen("Usuarios.dat", "rb");
    if(P==NULL){
        mensajeError("No se puede continuar");
        return;

    }
    while(fread(&reg,sizeof (Usuario), 1, P)){
        mostrarNombre(reg);
        mostrar_No_Actividades(reg);

    }
}


void mostrarNombre(Usuario reg){

cout << reg.nombres <<  reg.apellidos << endl;


}
void mostrar_No_Actividades(Usuario reg){
    FILE *P;
    int cant;
    int x;
    bool b1 = true;
    bool b2 = true;
    bool b3 = true;
    bool b4 = true;
    bool b5 = true;
    Entrenamiento *vec;
    cant = cantidad_entrenos();
    vec= (Entrenamiento*) malloc(sizeof (Entrenamiento) * cant);
P= fopen("Entrenamiento.dat","rb");
   fread(vec,sizeof (Entrenamiento),cant,P);
   fclose(P);
   for(x=0;x<cant;x++){

        if(reg.codigo==vec[x].idUsuario){
            if(vec[x].actividad==1){
                b1 = false;
            }
            if(vec[x].actividad==2){
                b2 = false;
            } if(vec[x].actividad==3){
                b3 = false;
            }if(vec[x].actividad==4){
                b4 = false;
            }if(vec[x].actividad==5){
                b5 = false;
            }
        }
   }
   cout << "Actividades no realizadas por el usuario"<< endl;
    if(b1){
        cout <<"1"<< endl;
    }if(b2){
        cout <<"2"<< endl;
    }if(b3){
        cout <<"3"<< endl;
    }if(b4){
        cout <<"4"<< endl;
    }if(b5){
        cout <<"5"<< endl;
    }

    free(vec);
}



















