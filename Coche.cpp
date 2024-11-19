//
// Created by Ela labidi on 25/09/2024.
//

#include <iostream>
#include <random>
#include "Coche.h"
#include "PuntoRecarga.h"

Coche::Coche() {
    this->id_matricula ="";
    this->marca = "";
    this->modelo = "";
    this->puntoRecarga = nullptr;

}

Coche::Coche(std::string id, std::string marca, std::string modelo):id_matricula(id),marca(marca),modelo(modelo) {
    std::random_device rd;
    std::mt19937 gen(rd()); // Semilla para el generador
    std::uniform_int_distribution<int> dist(20, 100);
    this->nivelBateria=  dist(gen);

}

Coche::Coche(const Coche &orig) {
    this->id_matricula = orig.id_matricula;
    this->marca = orig.marca;
    this->modelo = orig.modelo;
    this->puntoRecarga = orig.puntoRecarga;
    this->nivelBateria = orig.nivelBateria;
}

void Coche::setid(const string &id) {
    this->id_matricula=id;
}

void Coche::setmarca(const string &m) {
    this->marca=marca;
}

void Coche::setmodelo(const string &modelo) {
    this->modelo=modelo;
}


bool Coche::operator<(Coche &otro) {

    if(this->id_matricula < otro.id_matricula){
        return true;
    }
    return false;
}

bool Coche::operator>(Coche &otro){

    if(this->id_matricula > otro.id_matricula){
        return true;
    }
    return false;
}



bool Coche::operator==(Coche &otro){
    if(id_matricula==otro.id_matricula ){
        return true;
    }
    return false;
}



void Coche::printCoche(const Coche &c){
    cout << " Coche: ( Matricula=" << c.getIdMatricula()
         << " Marca=" << c.getMarca() << " Modelo=" << c.getModelo()
         << ")" << endl;
}

int Coche::busquedaBinMatricula(Coche* vector, const int &tlogico, const string &dato) {
    int inf=0;
    int sup=tlogico-1;
    int curIn;
    while(inf<=sup){
        curIn=(inf+sup)/2;
        if(vector[curIn].getIdMatricula()==dato){
            return curIn;
        }
        else if(vector[curIn].getIdMatricula() > dato) {
            inf= curIn+1;
        }
        else {
            sup=curIn-1;
        }
    }
    return -1;

}

int Coche::busquedaBinModelo(Coche* vector, const int &tlogico, const string &dato) {
    int inf=0;
    int sup=tlogico-1;
    int curIn;
    while(inf<=sup){
        curIn=(inf+sup)/2;
        if(vector[curIn].getModelo()==dato){
            return curIn;
        }
        else if(vector[curIn].getModelo() > dato) {
            inf= curIn+1;
        }
        else {
            sup=curIn-1;
        }
    }
    return -1;

}

Coche::~Coche() {
    this->id_matricula = "";
    this->marca = "";
    this->modelo ="";

}

const string &Coche::getIdMatricula() const {
    return id_matricula;
}

const string &Coche::getMarca() const {
    return marca;
}

const string &Coche::getModelo() const {
    return modelo;
}

float Coche::getNivelBateria() const {
    return nivelBateria;
}

void Coche::setNivelBateria(float nivelBateria) {
    Coche::nivelBateria = nivelBateria;
}

void Coche::circular() {
    this->puntoRecarga = nullptr;
}

PuntoRecarga *Coche::getPuntoRecarga() const {
    return puntoRecarga;
}

void Coche::setP(PuntoRecarga *puntoRec) {
    Coche::puntoRecarga = puntoRec;
}

bool Coche::aparacar(PuntoRecarga pr) {
    return(pr.addCoche(this));
}

