//
// Created by Maitena on 3/10/2024.
//

#ifndef P2_REANELCAR_H
#define P2_REANELCAR_H


#include "Coche.h"
#include "Usuario.h"
#include "PuntoRecarga.h"
#include "vector"
#include "map"
#include "list"
#include "Trayecto.h"
#include "Fecha.h"
#include "ThashUsuario.h"
#include "ThashUsuario.h"
class Usuario;
class ThashUsuario;

class Reanelcar {
private:
    map<string,Coche> *cars;
    list<Usuario> *users;
    vector<PuntoRecarga>* sites;
    PuntoRecarga* buscarpunto(int id);
    ThashUsuario *usersNif;

public:
    /**
     * Busca el usuario que tenga el nif pasado por parametro
     * @param nif nif a buscar
     * @return devuelev el usuario encontrado, si no se encontró ninguno se devuelve nulo
     */
    Usuario* buscarUsrNif(const string &nif);

    /**
     *   Devuelve una lista enlazada con todos los usuarios que empiecen por la subcadena dada como parametro
     * @param nom subcadena a buscar
     * @return devuelve lista enlazada de los usuarios que cumplan la condicion
     */
    list<Usuario> *buscarUsrNomb(const string &nom);

    /**
     * Busca un coche por una matricula dada
     * @param mat matricula a buscar
     * @return devuelve el coche que cumpla la condicion, de no ser asi devuelve nulo
     */
    Coche* buscarCochMat(const string &mat);

    /**
     * Busca coches por un modelo dada
     * @param mod modelo a buscar
     * @return devuelve el vector con coches que cumplen la condicion
     */
    vector<Coche>* buscarCochModelo(const string &mod);//como se buscan los modelos cuando en una mapa no se pueden repetir datos?

    /**
     * Permite a un usuario alquilar un coche
     * @param usr usuario que desea alquilar
     * @param c coche a alquilar
     * @return si el usuario ya alquilo un coche no puede alquilar otro. Por ende si el usuario tiene un coche
     * alquilado devolverá false, ya que no se puede, en caso de que no haya alquilado un coche devuelve true, se
     * permite el alquiler
     */
    Coche& alquilar(Usuario &usr,int idPRorigin,int idPRDestino,Fecha &fIni,Fecha &fFin);



    /**
     * Constructor parametrizado
     * @param coches vector dinamico de coches
     * @param usuarios lista doblemente enlazada de usuarios
     */
    Reanelcar( map<string,Coche> *coches,  list<Usuario> *usuarios,vector<PuntoRecarga>* PR);

    /**
     *
     * @param c coche a colocar en el vector de puntos de recarga
     * @param pr punto de recarga donde se colocará el coche
     * @return true si fue posible la inserción
     * false si no lo fue
     */
    bool colocarcochePR(Coche *c,PuntoRecarga &pr);

    /**
     *
     * @param p establece el vector de puntos de recarga para la clase
     */
    void setpuntorecarga(vector<PuntoRecarga> *p);

    /**
     *
     * @return obtiene el punto de recarga con menos coches
     */
    PuntoRecarga& obtenerPRmenoscoche();

    /**
     *
     * @param p agrega un punto de recarga al vector de puntos de la clase
     */
    void setpuntorecarga(PuntoRecarga *p);

    /**
     * busca los trayectos en la fecha pasada por parametro
     * @param f fecha a buscar
     * @return aquellos trayectos que se encuentren
     */
    vector<pair<Usuario,Trayecto>>*trayectosEnFecha(const Fecha &f);

    /**
     *
     * @param nif nif del usuario a buscar
     * @return el usuario encontrado en la tabla hash
     */
    Usuario* buscarUsrNifTHash(const string &nif);


    /**
     *
     * @param nif  nif del usuario a borrar
     * @return si se borró con éxito
     */
    bool borrarUsuarioHash(const string &nif);
};


#endif //P2_REANELCAR_H
