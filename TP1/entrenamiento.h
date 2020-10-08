#ifndef ENTRENAMIENTO_H_INCLUDED
#define ENTRENAMIENTO_H_INCLUDED


struct Entrenamiento{
    int id;
    int idUsuario;
    Fecha fechaEntreno;
    int actividad;
    float calorias;
    int minutos;

};

void MostrarEntrenamientosPorUsuario(int);
void listarEntrenamientosPorIDusuario();
void listarEntrenamientosPorID();
int  buscarEntrenamiento(int);
bool guardarEntrenamientoModificado(Entrenamiento, int);
Entrenamiento obtenerEntrenamiento(int);
void modificarEntrenamiento ();
void mostrarRegEntreno(Entrenamiento);
void mostrarRegEntreno( Entrenamiento, int);
void listarEntrenamientos();
bool guardarEntrenamiento(Entrenamiento);
int cantidad_entrenos();
Entrenamiento  cargarEntrenamiento ();
///VALIDACIONES

bool validar_idUsuario(Entrenamiento*);
void validar_Actividad(Entrenamiento*);
bool validar_AptoFisico(Entrenamiento*);
void validarCalorias (Entrenamiento*);
void  validarTiempo(Entrenamiento*);

///VALIDACIONES FECHA
void validarFechaEntreno(Entrenamiento*);
bool validarFechaEntreno(Fecha);
#endif // ENTRENAMIENTO_H_INCLUDED
