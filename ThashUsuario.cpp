//
// Created by admin on 12/11/2024.
//

#include "ThashUsuario.h"

#include <math.h>
#include <valarray>

unsigned int ThashUsuario::numElementos() const {
    return  this->util;
}

long ThashUsuario::clave1() const {
    return clave;
}

void ThashUsuario::set_clave(long clave) {
    this->clave = clave;
}

vector<Usuario> ThashUsuario::usuarios1() const {
    return usuarios;
}

void ThashUsuario::set_usuarios(const vector<Usuario> &usuarios) {
    this->usuarios = usuarios;
}

unsigned int ThashUsuario::getTam_max65() {
    this->tamMax65 = 10000 / 0.65;
    return tamMax65;
}

void ThashUsuario::set_tam_max65(unsigned int tam_max65) {
    tamMax65 = tam_max65;
}

int ThashUsuario::max_col1() const {
    return max_col;
}

void ThashUsuario::set_max_col(int max_col) {
    this->max_col = max_col;
}

int ThashUsuario::colisiones1() const {
    return colisiones;
}

void ThashUsuario::set_colisiones(int colisiones) {
    this->colisiones = colisiones;
}

int ThashUsuario::max_colisiones_11() const {
    return max_colisiones_10;
}

void ThashUsuario::set_max_colisiones_10(int max_colisiones_10) {
    this->max_colisiones_10 = max_colisiones_10;
}

int ThashUsuario::factor_carga1() const {
    return factor_carga;
}

void ThashUsuario::set_factor_carga(int factor_carga) {
    this->factor_carga = factor_carga;
}

unsigned int ThashUsuario::getTam_max68() {
    this->tamMax68 = 10000/0.68;
    return tamMax68;
}

void ThashUsuario::set_tam_max68(unsigned int tam_max68) {
    tamMax68 = tam_max68 ;
}

int ThashUsuario::util1() const {
    return util;
}

void ThashUsuario::set_util(int util) {
    this->util = util;
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

void ThashUsuario::insertar(const int &clave, const Usuario &dato) {
    int intentos =0;
    unsigned int posicion = -1;

    for(vector<Usuario>::iterator i = this->usuarios.begin(); this->usuarios[posicion].getNif() != "-1" ; i++) {
        posicion =  this->hashDispersionDoble2(clave, intentos);
        //posicion = this->hashDispersionDoble1(clave, intentos);
        //posicion = this->hashCuadratica(clave, intentos);
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
    return this->util/ this->tam_max;
}

unsigned int ThashUsuario::tamTabla() {
   return this->tam_max;
}

void ThashUsuario::mostrarEstadoTabla() {
}


