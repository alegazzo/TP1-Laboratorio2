#include <iostream>
#include <cstdlib>
#include<cstdio>
#include<stdio.h>


using namespace std;

#include"rlutil.h"
#include"usuario.h"
#include"submenus.h"
#include"Configuracion.h"
#include"Reportes.h"

int main(){
      setlocale(LC_ALL, "spanish");
      int opc;
      system("color 5F");

      while(true){

            gotoxy (50, 3);
            cout<<"MENÚ PRNICIPAL"<<endl;
            gotoxy(47, 4);
            cout<<"------------------------"<<endl;
            gotoxy(50, 5);
            cout<<"1) USUARIOS"<<endl;
            gotoxy(50, 6);
            cout<<"2) ENTRENAMIENTOS"<<endl;
            gotoxy(50, 7);
            cout<<"3) REPORTES"<<endl;
            gotoxy(50, 8);
            cout<<"4) CONFIGURACIÓN"<<endl;
            gotoxy(47, 9);
            cout<<"------------------------"<<endl;
            gotoxy(48, 10);
            cout<<"0) SALIR DEL PROGRAMA"<<endl;
            gotoxy(50, 14);
            cout<<"INGRESE UNA OPCIÓN: "<<endl;
            gotoxy(70, 14);
            cin>>opc;
            system("cls");

            switch(opc){
                  case 1:
                        menuUsuarios();
                        system("color 5F");
                  break;
                  case 2:
                        menuEntrenamiento();
                        system("color 5F");
                  break;
                  case 3: menuReportes();
                        system("color 5F");
                  break;
                  case 4:menuConfiguracion();
                        system("color 5F");
                  break;
                  case 0: return 0;
                  break;
                  default: cout<<"OPCION NO VALIDA."<<endl;
                  break;
            }

      }

    return 0;
}
