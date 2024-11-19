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
void pruebaRealnelcar();


/**
 * @author Ela Labidi el000020@red.ujaen.es
 * @author Maitena María Rosa Fiedler mmmrf0008@red.ujaen.es
 */

int main() {
pruebaRealnelcar();

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
void ReadandLoadfileUsuarios(list<Usuario> &usuarios,const string filename){
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

                Usuario aux(nif, clave, nombre, dir);
                usuarios.push_back(aux);

            }
        }
        is.close();
        cout << "Tiempo lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl;
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}


void pruebaRealnelcar() {



    /*//Primero cargamos los puntos de recarga,los usuarios y los coches
    vector<PuntoRecarga> Precargas;
    list<Usuario> usuarios;
    map<string,Coche> coches;
    bool asignar= false;

    cout << "Cargando coches" << endl;
    ReadandLoadfileCoches(coches,"../coches.csv");

    cout << "Cargando usuarios " << endl;
    ReadandLoadfileUsuarios(usuarios,"../usuarios1.csv");

    cout << "Cargando Puntos de recarga " << endl;
    ReadandLoadfilePuntoRecarga(Precargas,"../puntos_recarga.csv");


    cout << "Ligando Puntos de recarga con coches " << endl;
    vector<PuntoRecarga>::iterator it_punto_recarga = Precargas.begin();

    for(map<string,Coche>::iterator it_coches = coches.begin(); it_coches != coches.end(); it_coches++) {
        asignar = true;

        while( asignar) {
            if(it_punto_recarga->getNumCoches() < it_punto_recarga->getMax()) {
                 // cout << "El auto " << it_coches->first << " se va a meter en el punto recarga " << it_punto_recarga->getId() << endl;
                it_punto_recarga->addCoche(&it_coches->second);
                it_coches->second.setP(&(*it_punto_recarga));

            }
            it_punto_recarga++;
            if(it_punto_recarga  == Precargas.end()) {
                it_punto_recarga = Precargas.begin();
            }

            asignar = false;
        }
    }

    //***************************************************


    Reanelcar r(&coches,&usuarios,&Precargas);



    //PUNTO 2
    //Buscamos los usuarios cuyos nombres empiezan con un W

    cout << "Punto 2 " << endl;

    list<Usuario>*listaW =r.buscarUsrNomb("W");
    vector<PuntoRecarga>::iterator i_aux;
    int d= 0;
    PuntoRecarga *pr= nullptr;
    vector<PuntoRecarga>::iterator iterador_pr = Precargas.begin();
    Fecha fInicio(29,10,2024);
    Fecha fDestino = Fecha();

    for(list<Usuario>::iterator it_UsW = listaW->begin(); it_UsW != listaW->end(); it_UsW++) {

            d = rand() % 2;
            fDestino.anadirDias(d);
            i_aux = iterador_pr;

            if(iterador_pr->getId() >= 50) { // si no hay mas Pr volvemos a asignar el primero 
                iterador_pr = Precargas.begin(); 
            }
            if(iterador_pr->getId() < 50) {
                pr = &(*i_aux++);
                if(&(*i_aux++) != nullptr) {

                    r.alquilar(*it_UsW, iterador_pr->getId(), pr->getId(),fInicio  , fDestino);
                }
            }

            iterador_pr++;
        }


    for(list<Usuario>::iterator itListW = listaW->begin(); itListW != listaW->end(); itListW++) {
        cout<<"\nUser " <<":  "<<itListW->getNombre()<<"  "<<itListW->getDireccion()<<"  "<<itListW->getNif()<<"  Coche alquilado: "<<
       itListW->getC()->getIdMatricula()<<"  "<<itListW->getC()->getModelo()<<"  "<<itListW->getC()->getMarca()<<"\n";
    }

  //*^**********************************************

    //PUNTO 3
    cout << "PUNTO 3 " << endl;
    Reanelcar rr(&coches,listaW,&Precargas);

    list<Usuario>* listaWA =rr.buscarUsrNomb("Wa");

    cout<<"\n------Aparcando----los----coches----------\n";
    iterador_pr=Precargas.begin();
    list<Usuario>::iterator itWa =listaWA->begin();
    for( itWa =listaWA->begin(); itWa != listaWA->end(); itWa++ ) {
        itWa->aparcarCoche(*itWa->getC(), *iterador_pr);
        iterador_pr++;

        if(iterador_pr==Precargas.end()){
            iterador_pr=Precargas.begin();
        }
    }

    vector<Trayecto> tr;
//Usuarios y sus trayectos
    itWa=listaWA->begin();
    for(int i=0;i<9;i++){
        cout << "User " << i+1 << ":  " << itWa->getNombre() << endl;
        cout << " Trayectos  :  "  << endl;
           tr =  itWa->getTrayectosFechasInicial(fInicio);

            for(vector<Trayecto>::iterator itTr = tr.begin(); itTr != tr.end(); itTr++) {

               itTr->showtrayecto();
            }
        cout<<"\n";
        itWa++;
    }

    /*************************************/

    //Punto 4

    /*cout << "PUNTO 4 "<< endl;

    iterador_pr=Precargas.begin();
    itWa=listaWA->begin();

    for(int i=0;i<10;i++){
        r.alquilar(*itWa,iterador_pr->getId(),iterador_pr++->getId(),fInicio,fDestino);
        itWa++;
    }
    itWa=listaWA->begin();
    int con=0;
    itWa=listaWA->begin();

    while (itWa!=listaWA->end()){
        if(itWa->numTrayectos()>1){
            con++;
        }
        itWa++;
    }
    cout<<"El numero de usuarios que han realizado mas de un trayecto es: "<< con << endl;


    //apartado parejas

    cout << "APARTADO PAREJAS " << endl;

     vector<pair<Usuario,Trayecto>> *trayectos = rr.trayectosEnFecha(Fecha(29,10,2024));

    for(vector<pair<Usuario,Trayecto>>::iterator it_Trayectos = trayectos->begin(); it_Trayectos != trayectos->end(); it_Trayectos++) {
        cout << "Trayecto" << endl;
        it_Trayectos->second.showtrayecto();
        cout << endl;
        cout << "Usuario"  << endl;
        cout << it_Trayectos->first.getNombre() << endl;
        cout << endl;
        cout << "-------------------" << endl;
    }*/
}

