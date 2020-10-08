#include <iostream>
#include <cstdlib>
#include <ctime>


 using namespace std;

 #include"rlutil.h"
#include"usuario.h"
#include"submenus.h"
#include"entrenamiento.h"
#include"Configuracion.h"


void integrantesDelGrupo(){
gotoxy (52, 3);
cout<<"INTEGRANTES DEL GRUPO";
gotoxy(50, 4);
cout<<"--------------------------"<<endl;
gotoxy(50, 5);
cout<<"ALEJANDRO GAZZO    (23432)"<<endl;
gotoxy(50, 6);
cout<<"SEBASTIAN FLORES   (23413)"<<endl;
gotoxy(50, 7);
cout<<"FEDERICO DI FULVIO (23410)"<<endl;
system("pause");
system("cls");

};

int generarPin( int limite){
  int num;
  int i;
  srand(time(NULL));

    num=(rand()%limite)+1;

  return num;
}


void realizarCopia(){
    int pin;
    int pinU;
    int cantUsuarios;
    int cantEntrenos;

    FILE *puntero;
    Usuario *vec;
    Entrenamiento *vec2;

    pin= generarPin(9999);

    cout<<"PIN DE CONFIRMACION: "<<pin<<endl;
    cout<<"INGRESAR PIN PARA REALIZAR COPIA DE SEGURIDAD: ";
    cin>>pinU;
    while (pinU!=pin){
        mensajeError("PIN ERRONEO");
        system("color 9F");
        cout<<"PIN DE CONFIRMACION: "<<pin<<endl;
        cout<<"REINGRESAR PIN PARA REALIZAR COPIA DE SEGURIDAD: ";
        cin>>pinU;
    }
    ///PARTE USUARIO
    cantUsuarios=cantidad_usuarios();

    if(cantUsuarios==0){
     mensajeError("ERROR: NO SE PUEDE REALIZAR COPIA DE SEGURIDAD");
     system("color 9F");
     return;
    }

    vec= (Usuario*) malloc(sizeof (Usuario) * cantUsuarios);


    puntero= fopen("Usuarios.dat","rb");

    if(puntero==NULL){
     mensajeError("ERROR: NO SE PUEDE REALIZAR COPIA DE SEGURIDAD");
     system("color 9F");
     free(vec);
     return;
    }
    fread(vec,sizeof(Usuario),cantUsuarios,puntero);
    fclose(puntero);

    puntero=fopen("Usuarios.bkp","wb");
    fwrite(vec,sizeof(Usuario),cantUsuarios,puntero);
    fclose(puntero);
    free(vec);

    ///PARTE ENTRENAMIENTO

    cantEntrenos=cantidad_entrenos();

    if(cantEntrenos==0){
     mensajeError("ERROR: NO SE PUEDE REALIZAR COPIA DE SEGURIDAD");
     system("color 9F");
     return;
    }

    vec2= (Entrenamiento*) malloc(sizeof (Entrenamiento) * cantEntrenos);

    puntero= fopen("Entrenamiento.dat","rb");

    if(puntero==NULL){
     mensajeError("ERROR: NO SE PUEDE REALIZAR COPIA DE SEGURIDAD");
     system("color 9F");
     free(vec2);
     return;
    }
    fread(vec2,sizeof(Entrenamiento),cantEntrenos,puntero);
    fclose(puntero);


    puntero=fopen("Entrenamiento.bkp","wb");
    fwrite(vec2,sizeof(Entrenamiento),cantEntrenos,puntero);
    fclose(puntero);
    free(vec2);


    mensajeExito();
};

///RESTAURAR COPIA

void restaurarCopia(){
    int pin;
    int pinU;
    int cantUsuarios;
    int cantEntrenos;

    FILE *puntero;
    Usuario *vec;
    Entrenamiento *vec2;

    pin= generarPin(9999);

    cout<<"PIN DE CONFIRMACION: "<<pin<<endl;
    cout<<"INGRESAR PIN PARA RESTAURAR COPIA DE SEGURIDAD: ";
    cin>>pinU;
    while (pinU!=pin){
        mensajeError("PIN ERRONEO");
        system("color 9F");
        cout<<"PIN DE CONFIRMACION: "<<pin<<endl;
        cout<<"REINGRESAR PIN PARA RESTAURAR COPIA DE SEGURIDAD: ";
        cin>>pinU;
    }
    ///PARTE USUARIO
    cantUsuarios=cantidad_usuarios_bkp();

    if(cantUsuarios==0){
     mensajeError("ERROR: NO SE PUEDE RESTAURAR COPIA DE SEGURIDAD");
     system("color 9F");
     return;
    }

    vec= (Usuario*) malloc(sizeof (Usuario) * cantUsuarios);


    puntero= fopen("Usuarios.bkp","rb");

    if(puntero==NULL){
     mensajeError("ERROR: NO SE PUEDE RESTAURAR COPIA DE SEGURIDAD");
     system("color 9F");
     free(vec);
     return;
    }
    fread(vec,sizeof(Usuario),cantUsuarios,puntero);
    fclose(puntero);

    puntero=fopen("Usuarios.dat","wb");
    fwrite(vec,sizeof(Usuario),cantUsuarios,puntero);
    fclose(puntero);
    free(vec);

    ///PARTE ENTRENAMIENTO

    cantEntrenos=cantidad_entrenos_bkp();

    if(cantEntrenos==0){
     mensajeError("ERROR: NO SE PUEDE REALIZAR COPIA DE SEGURIDAD");
     system("color 9F");
     return;
    }

    vec2= (Entrenamiento*) malloc(sizeof (Entrenamiento) * cantEntrenos);

    puntero= fopen("Entrenamiento.bkp","rb");

    if(puntero==NULL){
     mensajeError("ERROR: NO SE PUEDE REALIZAR COPIA DE SEGURIDAD");
     system("color 9F");
     free(vec2);
     return;
    }
    fread(vec2,sizeof(Entrenamiento),cantEntrenos,puntero);
    fclose(puntero);


    puntero=fopen("Entrenamiento.dat","wb");
    fwrite(vec2,sizeof(Entrenamiento),cantEntrenos,puntero);
    fclose(puntero);
    free(vec2);


    mensajeExito();
};


int cantidad_usuarios_bkp() {
	int cantidad;
	FILE* pFile;

	pFile = fopen("Usuarios.bkp", "rb");

	if (pFile == NULL) {
		return 0;
	}

	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(Usuario);
	fclose(pFile);

	return cantidad;
}

 int cantidad_entrenos_bkp() {
	int cantidad;
	FILE* pFile;

	pFile = fopen("Entrenamiento.bkp", "rb");

	if (pFile == NULL) {
		return 0;
	}

	fseek(pFile, 0, SEEK_END);
	cantidad = ftell(pFile) / sizeof(Entrenamiento);
	fclose(pFile);

	return cantidad;
}
