//
// Created by Ela labidi on 16/09/2024.
//
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Coche.h"
#include "Usuario.h"
#include "Reanelcar.h"

using namespace std;
void pruebaRendimiento();
void prueba2();
void prueba1();
void ReadandLoadfilePuntoRecarga(vector<PuntoRecarga> &pr,const string filename);
void ReadandLoadfileCoches(map<string,Coche> &c,const string &filename);
void ReadandLoadfileUsuarios(ThashUsuario &usuarios,const string filename);
/**
 * @author Ela Labidi el000020@red.ujaen.es
 * @author Maitena María Rosa Fiedler mmmrf0008@red.ujaen.es
 */

int main() {
    //Primero cargamos los puntos de recarga,los usuarios y los coches
    vector<PuntoRecarga> precargas;
    ThashUsuario usuarios;
    map<string,Coche> coches;



    cout << "Cargando coches" << endl;
    ReadandLoadfileCoches(coches,"../coches.csv");

    cout << "Cargando usuarios " << endl;
    ReadandLoadfileUsuarios(usuarios,"../usuarios1.csv");

    cout << "Cargando Puntos de recarga " << endl;
    ReadandLoadfilePuntoRecarga(precargas,"../puntos_recarga.csv");

    Reanelcar rel(&coches, &precargas, &usuarios);

}

void ReadandLoadfilePuntoRecarga(vector<PuntoRecarga> &pr,const string filename){
    ifstream is;
    stringstream  columnas;
    string fila;
    string id;
    string lat;
    string lon;
    string max_cars;

    is.open(filename); //carpeta de proyecto
    if ( is.good() ) {
        clock_t t_ini = clock();
        while ( getline(is, fila ) ) {
            if (!fila.empty()) {
                columnas.str(fila);
                getline(columnas, id, ','); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, lat,',');
                getline(columnas, lon,',');
                getline(columnas, max_cars,',');
                fila="";
                columnas.clear();
                UTM u(stof(lat),stof(lon));
                PuntoRecarga aux(stoi(id), u,stoi(max_cars) );
                pr.push_back(aux);

            }
        }
        is.close();
        cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl;
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}
void ReadandLoadfileCoches(map<string,Coche> &c,const string &filename){

    ifstream is;
    stringstream  columnas;
    string fila;
    string id_matricula;
    string marca;
    string modelo;
    is.open(filename); //carpeta de proyecto

    if ( is.good() ) {
        clock_t t_ini = clock();
        while ( getline(is, fila ) ) {
            if (!fila.empty()) {
                columnas.str(fila);
                getline(columnas, id_matricula, ','); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, marca,',');
                getline(columnas, modelo,',');
                fila="";
                columnas.clear();
                Coche a(id_matricula,marca,modelo);
                c.insert({a.getIdMatricula(),a});
            }
        }
        is.close();
        cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl;
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}
void ReadandLoadfileUsuarios(ThashUsuario &usuarios,const string filename){
    ifstream is;
    stringstream  columnas;
    string fila;
    string nif;
    string clave;
    string nombre;
    string dir;

    is.open(filename); //carpeta de proyecto
    if ( is.good() ) {
        clock_t t_ini = clock();
        while ( getline(is, fila ) ) {
            if (!fila.empty()) {
                columnas.str(fila);
                getline(columnas, nif, ','); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, clave,',');
                getline(columnas, nombre,',');
                getline(columnas, dir,',');
                fila="";
                columnas.clear();

                Usuario *aux = new Usuario(nif, clave, nombre, dir);
                usuarios.insertar(stoi(nif), aux);

            }
        }
        is.close();
        cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl;
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}
void pruebaRendimiento() {

}
void prueba2() {

}
void prueba1() {

}



