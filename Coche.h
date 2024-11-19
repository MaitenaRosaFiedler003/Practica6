//
// Created by Ela labidi on 25/09/2024.
//

#ifndef PRACTICA2_COCHE_H
#define PRACTICA2_COCHE_H
#include "string"


using namespace std;

class PuntoRecarga;

class Coche {
private:
    string id_matricula="";
    string marca="";
    string modelo="";
    float nivelBateria =0;
    PuntoRecarga *puntoRecarga;

public:
    Coche();
    Coche(string id,string marca,string modelo);
    Coche(const Coche& orig);
    void setid(const string &id);
    void setmarca(const string &m);
    void setmodelo(const string &modelo);
    bool operator<(Coche &otro);
    bool operator>(Coche &otro);

    bool operator==(Coche &otro);
    void printCoche(const Coche &c);
    int busquedaBinMatricula(Coche* vector,const int &tlogico, const string &dato);
    int busquedaBinModelo(Coche* vector, const int &tlogico, const string &dato);
    const string &getIdMatricula() const;
    const string &getMarca() const;
    const string &getModelo() const;
    float getNivelBateria() const;
    void setNivelBateria(float nivelBateria);
    void circular();
    PuntoRecarga *getPuntoRecarga() const;
    void setP(PuntoRecarga *puntoRec);
    bool aparacar(PuntoRecarga pr);

    ~Coche();


};


#endif //PRACTICA2_COCHE_H
