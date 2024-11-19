//
// Created by admin on 12/11/2024.
//

#include "ThashUsuario.h"

#include <math.h>
#include <valarray>

unsigned int ThashUsuario::numElementos() const {
    return  this->util;
}

unsigned int ThashUsuario::hashCuadratica(const unsigned &clave, const int &intento) {

    int aux = pow(intento, 2);
    unsigned int hash = (clave + aux ) % this->tam_max;
    return hash;
}

unsigned int ThashUsuario::hashDispersionDoble1(const unsigned &clave, const int &intento) {
    unsigned int primo = calculaPrimo(this->tamMax65);
    unsigned int aux=  1 + (intento * primo);
    return aux;
}

unsigned int ThashUsuario::hashDispersionDoble2(const unsigned &clave, const int &intento) {
    unsigned int primo = calculaPrimo(this->tamMax68);
    unsigned int aux=  primo (intento % primo);
    return aux;
}

void ThashUsuario::insertarHC(const int &clave, const Usuario &dato) {
    //para que la comprobación de inserción sea mas facil los usuarios que no estan inicializados tienen el nif -1
    int intentos =0;
    unsigned int posicion = -1;

    for(vector<Usuario>::iterator i = this->usuarios.begin(); this->usuarios[posicion].getNif() != "-1" ; i++) {
       posicion =  this->hashCuadratica(clave, intentos);
        intentos++;
    }
    this->usuarios[posicion] = dato;

    if(intentos > this->max_col) {
        this->max_col = intentos;
    }
    if (intentos > 10) {
        this->max_colisiones_10++;
    }
    this->colisiones+= intentos;
}

void ThashUsuario::insertarHD2(const int &clave, const Usuario &dato) {
    int intentos =0;
    unsigned int posicion = -1;

    for(vector<Usuario>::iterator i = this->usuarios.begin(); this->usuarios[posicion].getNif() != "-1" ; i++) {
        posicion =  this->hashDispersionDoble2(clave, intentos);
        intentos++;
    }
    this->usuarios[posicion] = dato;

    //calculo de colisiones
    if(intentos > this->max_col) {
        this->max_col = intentos;
    }
    if (intentos > 10) {
        this->max_colisiones_10++;
    }
    this->colisiones+= intentos;
}

void ThashUsuario::insertarHD1(const int &clave, const Usuario &dato) {
    int intentos =0;
    unsigned int posicion = -1;

    for(vector<Usuario>::iterator i = this->usuarios.begin(); this->usuarios[posicion].getNif() != "-1" ; i++) {
        posicion =  this->hashDispersionDoble2(clave, intentos);
        intentos++;
    }
    this->usuarios[posicion] = dato;
    if(intentos > this->max_col) {
        this->max_col = intentos;
    }
    if (intentos > 10) {
        this->max_colisiones_10++;
    }
    this->colisiones+= intentos;
}


unsigned int ThashUsuario::calculaPrimo(const int &tam) {
    int valor = tam + 1;
    while(!esPrimo(valor)) {
        valor++;
    }
    return valor;
}

bool ThashUsuario::esPrimo(const int &num) {
    if (num <= 1) {
        return false;
    }
    for(int i=2; i < sqrt(num); i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}



bool ThashUsuario::borrar(const int &clave) {

}

bool ThashUsuario::buscar(int clave) {

}

unsigned int ThashUsuario::promedioColisiones() {
    return (this->colisiones/this->util);
}

unsigned int ThashUsuario::maxColisiones() {
    return this->max_col;
}

unsigned int ThashUsuario::numMax10() {
    return this->max_colisiones_10;
}

float ThashUsuario::factorCarga() {
    return this->factor_carga;
}

unsigned int ThashUsuario::tamTabla() {
}

void ThashUsuario::mostrarEstadoTabla() {
}


