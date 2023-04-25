#include "SistemaDeMensajes.h"
#include "ConexionJugador.h"

SistemaDeMensajes::SistemaDeMensajes() : _conns(){}

SistemaDeMensajes:: ~SistemaDeMensajes(){ //destructor de la clase
    for (int id= 0; id <4; id++){
        delete _conns[id]; //elimino todos los jugadores registrados (con un un id en el puntero). Libera la memoria asociada al puntero p.
    }
}


void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (registrado(id)){
        delete _conns[id]; //si esta registrado lo desregistro
        _conns[id] = new ConexionJugador(ip); //reserva espacio en el heap para almacenar el nuevo ip(id). Devuelve un puntero de tipo ip* a la direccion de memoria donde comienza ese espacio.
    } else {
        _conns[id] = new ConexionJugador(ip);
    }
}

bool SistemaDeMensajes::registrado(int id) const{ //Doy una copia modificable. (???
    if (_conns[id]== nullptr){
        return false;
    } else {
        return true;
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje); //accedemos al atributo enviarMensaje a través del puntero _conns; Accede al elemento mensaje de enviarMensaje y le asigna el valor de mensaje que ha sido pasado como argumento de la función.(???
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip(); //accedemos al atributo ip a través del puntero _conns(???
}