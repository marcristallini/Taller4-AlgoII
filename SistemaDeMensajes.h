#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>
#include "Proxy.h"

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    class Proxy; //definida en Proxy.h

    SistemaDeMensajes();

    ~SistemaDeMensajes(); //destructor de la clase
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);
    void desregistrarJugador(int id);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    Proxy *obtenerProxy(int id);

    class Proxy {
    public:
        Proxy(ConexionJugador **conn);
        void enviarMensaje(string msg);

    private:
        ConexionJugador **_conn;

        // No puedo copiarlo
        Proxy(const Proxy&);
    };


private:
    ConexionJugador* _conns[4];
};



#endif
