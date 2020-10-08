#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

struct Fecha{
    int dia, mes, anio;
};

struct Usuario {
    int codigo;
    char nombres [50];
    char apellidos [50];
    Fecha nacimiento;
    float altura;
    float peso;
    char perfilActividad;
    bool aptoMedico;
    bool estado;
};
/// FUNCIONES DE USUARIO
 Usuario cargarUsuario();
 bool guardarUsuario (Usuario);
 void  mostrarUsuarios() ;
 int buscarUsuario (int );
void mostrarRegistro( Usuario );
void mostrarRegistro( Usuario, int );
void listarPorID();
Usuario obtenerUsuario (int );
void modificarUsuario ();
bool guardarUsuarioModificado (Usuario, int ) ;
void bajaLogica();
int cantidad_usuarios();

 ///VAlIDACIONES
bool validarID( Usuario *);
void  validacionPerfil (   Usuario *  ) ;
void  validarAptoMedico (   Usuario *  ) ;
void  validarPeso (  Usuario * );
void  validarAltura(  Usuario * );
void validarNombre(Usuario * );
void validarApellido(Usuario * );
void validarFecha(Usuario * );
bool validarEdad (Fecha );

///FUNCION DE FECHA

Fecha obtenerFechaDelSistema();
Fecha cargarFecha();


void mensajeError(char []);
void mensajeExito();













#endif // USUARIO_H_INCLUDED
