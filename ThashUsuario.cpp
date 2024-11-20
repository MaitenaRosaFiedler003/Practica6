//
// Created by admin on 12/11/2024.
//

#include "ThashUsuario.h"

#include <cmath>
#include <valarray>

unsigned int ThashUsuario::numElementos() const {
    return  this->util;
}

long ThashUsuario::getClave() const {
    return clave;
}

void ThashUsuario::set_clave(long clave) {
    this->clave = clave;
}

vector<Entrada> ThashUsuario::getUsuarios() const {
    return usuarios;
}

void ThashUsuario::set_usuarios(const vector<Entrada> &usuarios) {
    this->usuarios = usuarios;
}



int ThashUsuario::getMaxColisiones() const {
    return max_col;
}

void ThashUsuario::set_max_col(int max_col) {
    this->max_col = max_col;
}

int ThashUsuario::getColisiones() const {
    return this->colisiones;
}

void ThashUsuario::set_colisiones(int colisiones) {
    this->colisiones = colisiones;
}



void ThashUsuario::set_max_colisiones_10(int max_colisiones_10) {
    this->max_colisiones_10 = max_colisiones_10;
}

int ThashUsuario::get_max_colisiones_10() const {
    return max_colisiones_10;
}

int ThashUsuario::getFactorCarga() const {
    return factor_carga;
}

void ThashUsuario::set_factor_carga(int factor_carga) {
    this->factor_carga = factor_carga;
}

int ThashUsuario::getUtil() const {
    return util;
}

void ThashUsuario::set_util(int util) {
    this->util = util;
}

Entrada::Entrada() {
    this->clave =0;
}

long Entrada::getClave() const {
    return clave;
}

void Entrada::set_clave(long clave) {
    this->clave = clave;
}

Usuario * Entrada::getUsuario() const {
    return usuario;
}

void Entrada::set_usuario(Usuario *usuario) {
    this->usuario = usuario;
}

unsigned int ThashUsuario::hashCuadratica(const unsigned &clave, const int &intento) {
    int aux = pow(intento, 2);
    unsigned int hash = (clave + aux ) % this->tam_max;
    return hash;
}

unsigned int ThashUsuario::hashDispersionDoble1(const unsigned &clave, const int &intento) {
    unsigned int primo = calculaPrimo(this->tam_max);
    unsigned int aux=  1 + (intento * primo);
    return aux;
}

unsigned int ThashUsuario::hashDispersionDoble2(const unsigned &clave, const int &intento) {
    unsigned int primo = calculaPrimo(this->tam_max);
    unsigned int aux=  primo * (intento % primo);
    return aux;
}

bool ThashUsuario::insertar(const int &clave,  Usuario *dato) {
    int intentos =0;
    unsigned int posicion = -1;

    for(vector<Entrada>::iterator i = this->usuarios.begin(); this->usuarios[posicion].usuario->getNif() != "-1" ; i++) {
        if(i->getUsuario()->getNif() == dato->getNif()) {
            return false;
        }
        posicion =  this->hashDispersionDoble2(clave, intentos);
        //posicion = this->hashDispersionDoble1(clave, intentos);
        //posicion = this->hashCuadratica(clave, intentos);
        intentos++;
    }
    this->usuarios[posicion].set_usuario(dato);
    if(intentos > this->max_col) {
        this->max_col = intentos;
    }
    if (intentos > 10) {
        this->max_colisiones_10++;
    }
    this->colisiones+= intentos;
    return true;
}


ThashUsuario::ThashUsuario(const int &maxElementos, const float &lambda) {
    this->tam_max = maxElementos/lambda;
    this->factor_carga = lambda;
    this->util =0;
    this->max_col =0;
    this->max_colisiones_10 = 0;
    this->colisiones = 0;
    this->clave =0;

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
    bool encontrado = false;
    unsigned int posicion = -1;
    int intentos =0;

    while(!encontrado){
        posicion = this->hashCuadratica(clave,intentos);
        // posicion = this->hashDispersionDoble1(clave, intentos);
        //posicion = this->hashDispersionDoble2(clave, intentos);
        if(this->usuarios[posicion].getUsuario()->getNif() != "-1") { //las posiciones vacias no nos interesan
            if(this->usuarios[posicion].clave == clave) {
                encontrado = true;

                delete this->usuarios[posicion].usuario;
                this->usuarios[posicion].usuario = nullptr;
            }
        }
        intentos++;
    }
    return encontrado;
}

Usuario* ThashUsuario::buscar(const int &clave) {

    bool encontrado = false;
    Entrada *aux = nullptr;
    unsigned int posicion = -1;
    int intentos =0;
    while(!encontrado){

        posicion = this->hashCuadratica(clave,intentos);
       // posicion = this->hashDispersionDoble1(clave, intentos);
        //posicion = this->hashDispersionDoble2(clave, intentos);

        if(this->usuarios[posicion].getUsuario()->getNif() != "-1") { //las posiciones vacias no nos interesan
            if(this->usuarios[posicion].clave == clave) {
                encontrado = true;
                aux = &this->usuarios[posicion];
            }
        }
        intentos++;
    }
    return aux->usuario;
}

unsigned int ThashUsuario::promedioColisiones() const {
    return (this->colisiones/this->util);
}

unsigned int ThashUsuario::maxColisiones() const {
    return this->max_col;
}

unsigned int ThashUsuario::numMax10() const {
    return this->max_colisiones_10;
}

float ThashUsuario::factorCarga() const {
    return (float)((this->util) / (this->tam_max));
}

unsigned int ThashUsuario::tamTabla() const {
   return this->tam_max;
}

void ThashUsuario::mostrarEstadoTabla() {
    cout << "Tam max: " << this->tam_max << endl;
    cout << "Tam util: " << this->util << endl;
    cout << "Factor carga: " << this->factorCarga() << endl;
    cout << "Num colisiones : " << this->colisiones << endl;
    cout << "Num max10 : " << this->max_colisiones_10 << endl;
    cout << "Promedio colisiones " << this->promedioColisiones() << endl;

}


