#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<stdio.h>
 using namespace std;

#include"rlutil.h"
#include"usuario.h"
#include"submenus.h"
#include"entrenamiento.h"
#include"Configuracion.h"
#include"Reportes.h"
///MENÚ USUARIOS
void menuUsuarios() {
 int opc;
 Usuario registrado;

      while(true){
            system("color 70");
            gotoxy (52, 3);
            cout<<"MENÚ USUARIOS"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1) NUEVO USUARIO"<<endl;
            gotoxy(50, 6);
            cout<<"2) MODIFICAR USUARIO"<<endl;
            gotoxy(50, 7);
            cout<<"3) LISTAR USUARIO POR ID"<<endl;
            gotoxy(50, 8);
            cout<<"4) LISTAR TODOS LOS USUARIOS"<<endl;
            gotoxy(50, 9);
            cout<<"5) ELIMINAR USUARIO"<<endl;
            gotoxy(47, 10);
            cout<<"------------------------"<<endl;
            gotoxy(48, 11);
            cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
            gotoxy(50, 15);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 15);
            cin>>opc;
            system("cls");

            switch(opc){
                  case 1:
                        registrado = cargarUsuario();
                        if(registrado.estado==false){
                            mensajeError("No se pudo guardar, error en el archivo");
                             return;
                        }
                        if(guardarUsuario(registrado)==false){
                            mensajeError("No se pudo guardar, error en el archivo");
                            return;
                        }

                  break;
                  case 2: modificarUsuario ();
                  break;
                  case 3: listarPorID();
                  break;
                  case 4:  mostrarUsuarios();
                  break;
                  case 5:  bajaLogica();
                  break;
                  case 0: return ;
                  break;
                  default: cout<<"OPCION NO VALIDA."<<endl;
                  break;
            }

      }

 }

///MENÚ DE ENTRENAMIENTO


 void menuEntrenamiento() {
 int opc;
 Entrenamiento registrado;
      while(true){
            system("color B0");
            gotoxy (52, 3);
            cout<<"MENÚ ENTRENAMIENTO"<<endl;
            gotoxy(50, 4);
            cout<<"------------------------"<<endl;
            gotoxy(46, 5);
            cout<<"1) NUEVO ENTRENAMIENTO"<<endl;
            gotoxy(46, 6);
            cout<<"2) MODIFICAR ENTRENAMIENTO"<<endl;
            gotoxy(46, 7);
            cout<<"3) LISTAR ENTRENAMIENTO POR ID"<<endl;
            gotoxy(46, 8);
            cout<<"4) LISTAR TODOS LOS ENTRENAMIENTOS POR ID DE USUARIO"<<endl;
            gotoxy(46,9) ;
            cout<<"5) LISTAR TODOS LOS ENTRENAMIENTOS"<<endl;
            gotoxy(50, 10);
            cout<<"------------------------"<<endl;
            gotoxy(48,11 );
            cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
            gotoxy (50, 15);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy (70, 15);
            cin>>opc;
            system("cls");

            switch(opc){
                  case 1:registrado=cargarEntrenamiento();

                        if(guardarEntrenamiento(registrado)== false){
                            mensajeError("No se pudo guardar, error en el archivo");
                            return;
                        }

                  break;
                  case 2: modificarEntrenamiento ();
                  break;
                  case 3:listarEntrenamientosPorID();
                  break;
                  case 4:listarEntrenamientosPorIDusuario();
                  break;
                  case 5:listarEntrenamientos();
                  break;
                  case 0:return;
                  break;
                  default: cout<<"OPCION NO VALIDA."<<endl;
                  break;
            }

      }

 }
///MENU CONFIGURACION

void menuConfiguracion(){
int opc;

  while(true){
        system("color 9F");
        gotoxy (52, 3);
        cout<<"MENÚ CONFIGURACION"<<endl;
        gotoxy(50, 4);
        cout<<"------------------------"<<endl;
        gotoxy(46, 5);
        cout<<"1) REALIZAR COPIA DE SEGURIDAD"<<endl;
        gotoxy(46, 6);
        cout<<"2) RESTAURAR COPIA DE SEGURIDAD"<<endl;
        gotoxy(46, 7);
        cout<<"3) INTEGRANTES DEL GRUPO"<<endl;
        gotoxy(50, 8);
        cout<<"------------------------"<<endl;
        gotoxy(48,11 );
        cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
        gotoxy (50, 15);
        cout<<"INGRESE UNA OPCIÓN: "<<endl;
        gotoxy (70, 15);
        cin>>opc;
        system("cls");

        switch(opc){
          case 1: realizarCopia();
          break;
          case 2: restaurarCopia();
          break;
          case 3: integrantesDelGrupo();
          break;
          case 0: return ;
          break;
          default: mensajeError("OPCION NO VALIDA");

          break;

        }
    }

}



