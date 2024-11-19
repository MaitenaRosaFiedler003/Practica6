//
// Created by admin on 12/11/2024.
//

#ifndef P2_THASHUSUARIO_H
#define P2_THASHUSUARIO_H
#include "Usuario.h"
class Usuario;
class Entrada {

public:
    long clave;
    Usuario *usuario;
    Entrada(long aClave, Usuario *user): clave(aClave) , usuario(user) {}
    Entrada();

};

class ThashUsuario {
private:
    long clave;
    vector<Usuario> usuarios;
    unsigned int tamMax65 =0;
    int max_col = 0; //mide las colisiones que han ocurrido en una inserción
    int colisiones =0;
    int max_colisiones_10 =0; //mide la cantidad de veces quese
    int factor_carga =0;
    unsigned int tamMax68 =0;
    int util =0; //cant de elements
    unsigned int tam_max =0;


    static unsigned int hash(const unsigned int &valor, const unsigned int &tam) { return valor%tam;  }
    unsigned int hashH2(const unsigned int &valor, const unsigned int &tam) { int aux = calculaPrimo(tam); return aux - (valor % aux);}
    static unsigned int djb2(const string &clave ){ return stoi(clave);}


public:
    /**
     * calcula la posicion de un valor usando la dispersion cuadratica
     * @param clave clave para el calculo
     * @param intento numero de intentos realizados
     * @return posicion de un valor
     */
    unsigned int hashCuadratica(const unsigned &clave, const int &intento);

    /**
     * calcula la posicion de un valor utilizando la dispersion doble con lambda 0.65
     * @param clave
     * @param intento
     * @return
     */
    unsigned int hashDispersionDoble1(const unsigned &clave, const int &intento);
    unsigned int hashDispersionDoble2(const unsigned &clave, const int &intento);



public:
    /**
     * Inserta utilizando la dispersion cuadratica
     * @param clave
     * @param dato
     */
    void insertarHC(const int &clave, const Usuario &dato);

    /**
     * Inserta utilizando la dispersion doble con factor de carga 0.65
     * @param clave
     * @param dato
     */
    void insertarHD2(const int &clave, const Usuario &dato);

   /**
    * Inserta utilizando la dispersion doble con factor de carga 0.68
    * @param clave
    * @param dato
    */
    void insertarHD1(const int &clave, const Usuario &dato);
    bool borrar(const int &clave);
    bool buscar(int clave);
    ThashUsuario();
    ThashUsuario(const int &maxElementos, const float &lambda=0.7);
    unsigned int calculaPrimo(const int &primo);
    bool esPrimo(const int &num);

    /**
     *
     * @return Devuelve el número máximo de colisiones que se han producido en la operación de inserción más costosa
     * realizada sobre la tabla
     */
    unsigned  int promedioColisiones();

    /**
     *
     * @return el número máximo de colisiones que
     * se han producido en la operación de inserción más costosa realizada sobre la tabla.
     * Si la tabla esta llena el numero de colisiones permitidas serán n-1
     * Si no esta llena se puede resolver con hash doble o cuadratico
     */
    unsigned int maxColisiones();

    /**
     *
     * @return l número de veces que se superan 10
     * colisiones al intentar realizar la operación de inserción sobre la tabla de un dato
     */
    unsigned int numMax10();

    /**
     *
     * @return devuelve el factor de carga de la tabla de dispersión.
     */
    float factorCarga();

    /**
     *
     * @return el tamaño de la tabla de dispersión
     */
    unsigned int tamTabla();

    /**
     * muestra por pantalla los diferentes parámetros anteriores de la tabla interna de usuarios.
     */
    void mostrarEstadoTabla();


    /**
     *
 * @return devuelva de forma eficiente el número de elementos que contiene la tabla
     */
    unsigned int numElementos() const;
};


#endif //P2_THASHUSUARIO_H
