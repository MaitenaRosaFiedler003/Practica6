//
// Created by Maitena on 3/10/2024.
//

#ifndef P2_USUARIO_H
#define P2_USUARIO_H
#include "iostream"
#include "Coche.h"
#include "Reanelcar.h"
#include "Trayecto.h"
#include "map"
#include "vector"
using namespace std;
class Reanelcar;



class Usuario {
private:
    string nif;
    string clave;
    string nombre;
    string direccion;
    Coche *coche;
    Reanelcar *Linkreanel;
    std::multimap<Fecha,Trayecto> route; //Clave es la fecha de inicio


public:
    Coche *getC() const;
    void setC(const Coche &c);
    const string &getNif() const;
    void setNif(const string &nif);
    const string &getClave() const;
    void setClave(const string &clave);
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getDireccion() const;
    bool operator==(Usuario &otro);
    void setDireccion(const string &direccion);
    Coche& cogecoche();
    Trayecto* crearTrayecto(PuntoRecarga &ori,PuntoRecarga& des,Fecha &fInicio,Fecha &fFin);
    Coche& iniciaTrayecto(int idPuntoinicio,int idPuntoFinal,Fecha fIni,Fecha fFin);
    void aparcarCoche(Coche& c,PuntoRecarga& pr);
    vector<Trayecto>& getTrayectosFechasInicial(const Fecha &f);
    vector<Trayecto>& getTrayectosFechasFinal(const Fecha &f);
    int numTrayectos();
    void setTrayecto(const Trayecto &t, const Fecha &f);
    std::multimap<Fecha, Trayecto> route1() ;
    Trayecto *getTrayecto(int id);

    void aparcarCoche(const Coche &c, PuntoRecarga& pr, const int &retraso );

    void decrementarPuntos(const int &retraso);

    void eliminarTrayectos();

    Usuario();
    Usuario(const string &nif, const string &clave, const string &nombre, const string &direccion);
    ~Usuario();
};


#endif //P2_USUARIO_H
