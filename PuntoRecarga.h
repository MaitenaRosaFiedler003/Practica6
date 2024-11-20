//
// Created by Ela labidi on 20/10/2024.
//

#ifndef P2_PUNTORECARGA_H
#define P2_PUNTORECARGA_H
#include <map>
#include<iostream>
#include <queue>
using namespace std;
class Coche;

class UTM {

    float lat;
    float lon;
public:
    UTM(const float &lat, const float &lon);
    float lat1() const;
    float lon1() const;
};

class PuntoRecarga {
    int id;
    UTM posicion;
    int max;
    priority_queue<Coche*> chargepoint; //prioridad a nivel de bateria


public:
    PuntoRecarga();
    PuntoRecarga(const PuntoRecarga &p);
    PuntoRecarga(const int &id,const  UTM &posicion,const  int &max);
    ~PuntoRecarga();
    Coche* getMaxBateria();
    bool addCoche(Coche *c);
    void delCoche(const string &matricula);
    int getNumCoches() const;
    int getId() const;
    void setId(int id);
    const UTM &getPosicion() const;
    void setPosicion(const UTM &posicion);
    int getMax() const;
    void setMax(int max);
    priority_queue<Coche*> &getCoches() ;
    void setCoches(const priority_queue<Coche*> &coches);
    PuntoRecarga &operator=(const PuntoRecarga &f);
};


#endif //P2_PUNTORECARGA_H
