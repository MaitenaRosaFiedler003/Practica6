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

    long getClave() const;
    void set_clave(long clave);
    Usuario * getUsuarios() const;
    void set_usuario(Usuario *usuario);
};

class ThashUsuario {
private:
    long clave;
    vector<Entrada> usuarios;
    unsigned int tamMax65 =0;
    int max_col = 0; //mide las colisiones que han ocurrido en una inserción
    int max_colisiones_10 =0; //mide la cantidad de veces que se pasa de las 10 colisones
    int factor_carga =0;
    int colisiones =0;
    unsigned int tamMax68 =0;
    int util =0; //cant de elements
    unsigned int tam_max =0;


    static unsigned int hash(const unsigned int &valor, const unsigned int &tam) { return valor%tam;  }
    unsigned int hashH2(const unsigned int &valor, const unsigned int &tam) { int aux = calculaPrimo(tam); return aux - (valor % aux);}

public:
    static unsigned int djb2(const string &clave ){ return stoi(clave);}
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

    /**
     * Inserta el usuario pasado por parametro en la tabla, dentro puede usar cualquiera de los
     * 3 tipos de hash, hay que descomentar el que queramos
     * @param clave
     * @param dato
     * @return
     */
    bool insertar(const int &clave,  Usuario *dato);

   /**
     * Borra el usuario con la clave pasada, dentro puede usar cualquiera de los
     * 3 tipos de hash, hay que descomentar el que queramos
     * @param clave
     * @return true si se pudo borrar, false si no se encontró
     */
    bool borrar(const int &clave);

 /**
     * Busca  el usuario que tenga la clave pasada por parametro, dentro puede usar cualquiera de los
     * 3 tipos de hash, hay que descomentar el que queramos
     * @param clave
     * @return usuario encontrado
     */
    Usuario* buscar(const int &clave);

    /**
     * Constructor
     */
    ThashUsuario();

    /**
     * Constructor parametrizado
     * @param maxElementos
     * @param lambda
     */
    ThashUsuario(const int &maxElementos, const float &lambda=0.7);

    unsigned int calculaPrimo(const int &primo);

    static bool esPrimo(const int &num);

    /**
     *
     * @return Devuelve el número máximo de colisiones que se han producido en la operación de inserción más costosa
     * realizada sobre la tabla
     */
    unsigned  int promedioColisiones() const;

    /**
     *
     * @return el número máximo de colisiones que
     * se han producido en la operación de inserción más costosa realizada sobre la tabla.
     * Si la tabla esta llena el numero de colisiones permitidas serán n-1
     * Si no esta llena se puede resolver con hash doble o cuadratico
     */
    unsigned int maxColisiones() const;

    /**
     *
     * @return l número de veces que se superan 10
     * colisiones al intentar realizar la operación de inserción sobre la tabla de un dato
     */
    unsigned int numMax10() const;

    /**
     *
     * @return devuelve el factor de carga de la tabla de dispersión.
     */
    float factorCarga() const;

    /**
     *
     * @return el tamaño de la tabla de dispersión
     */
    unsigned int tamTabla() const;

    /**
     * muestra por pantalla los diferentes parámetros anteriores de la tabla interna de usuarios.
     */
    void mostrarEstadoTabla();


    /**
     *
     * @return devuelva de forma eficiente el número de elementos que contiene la tabla
     */
    unsigned int numElementos() const;

   //Getter y setters

    long getClave() const;
    void set_clave(long clave);
    vector<Entrada> getUsuarios() const;
    void set_usuarios(const vector<Entrada> &usuarios);
    unsigned int getTam_max65();
    void set_tam_max65(unsigned int tam_max65);
    int max_col1() const;
    void set_max_col(int max_col);
    int getColisiones() const;
    void set_colisiones(int colisiones);
    int max_colisiones_11() const;
    void set_max_colisiones_10(int max_colisiones_10);
    int factor_carga1() const;
    void set_factor_carga(int factor_carga);
    unsigned int getTam_max68();
    void set_tam_max68(unsigned int tam_max68);
    int util1() const;
    void set_util(int util);
};


#endif //P2_THASHUSUARIO_H
