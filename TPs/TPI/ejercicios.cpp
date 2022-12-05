#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;

// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
	bool resp = esValida(th, ti);
	return resp;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
	int largo = cantidadMaximadeHabitacionesEnRegionDada(th, region);
	vector < int > resultado;
	for (int i = 1; i <= largo; i++){
		resultado.push_back(cantidadCasasConiHabitacionesEnRegionDada (th, region, i));
	}
	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                    make_pair(40, -1.0),
                                    make_pair(41, -1.0),
                                    make_pair(42,-1.0),
                                    make_pair(43,-1.0),
                                    make_pair(44,-1.0)};

    resp[0].second = proporcionHogaresConHC(th, ti, 1);
    for (int k = 1; k < CANTIDAD_DE_REGIONES; k++) {
        resp[k].second = proporcionHogaresConHC(th, ti, 39 + k);
    }
    return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    bool resp = false;
    if ( proporcionTeleworking (t2h,t2i) > proporcionTeleworking (t1h, t1i)){
        resp = true;
    }
    return resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int resp = 0;
    for (int h = 0; h < th.size(); ++h) {
        if (tieneCasaPropia (th[h]) && tieneCasaChica (th[h], ti)){
            resp = resp + monto;
        }
    }
    return resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
    join_hi resp (ti.size());

    for (int k = 0; k < ti.size(); ++k) { 
        for (int j = k; j < resp.size(); ++j) {
            resp[j].second = ti[k];
            break;
        }

    } 
    for (int j = 0; j < resp.size(); ++j) {
        for (int k = 0; k < th.size(); ++k) { 
            if (resp[j].second[INDCODUSU] == th[k][HOGCODUSU]) {
                resp[j].first = th[k];
                break;
            }
        }
    }
    return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
        // PROBADO FUNCIONA
        ordenarPorCodusuTh(th);
        ordenarPorRegiones(th);
        ordenarPorComponenteTi(ti);
        vector <int> lista = listaDeHogcodususOrdenados(th);
        ordenarPorCODUSUTi(ti,lista);
        return;
}

// Implementacion Problema 8

vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    eph_h resp;
    vector <pair <int,int>> hogaresConIngresos = listaHogaresConIngresos(th,ti);
    ordenarHogaresPorIngresos(hogaresConIngresos);
    vector <pair <int,int>> hogaresConIngresosOrdenados = hogaresConIngresos;
    vector<int> listaDeMejoresHogares = listaDeHogaresOptimos(hogaresConIngresosOrdenados);
    if (listaDeMejoresHogares.size()>=3){
        for (int i = 0; i < listaDeMejoresHogares.size(); ++i) {
            for (int h = 0; h < th.size(); ++h) {
                if (listaDeMejoresHogares[i] == th[h][HOGCODUSU]){
                    resp.push_back(th[h]);
                    break;
                }

            }

        }

    }
    return resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
        cambiaRegionGBAaPampeana(th);
	return;
}

// Implementacion Problema 10
pair < eph_h, eph_i > quitarIndividuos(eph_i &ti, eph_h &th, vector <pair <int,dato> > busqueda){
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);

    eph_h th0 = th;
    eph_i ti0 = ti;

    ti = restoDeTablaIndividuos(ti0, busqueda);
    th = restoDeTablaHogares(th0, ti0, busqueda);

    resp.first = tablaHogares(th0, ti0, busqueda);
    resp.second = tablaIndividuos(ti0, busqueda);

    return resp;
}

// Implementacion Problema 11
vector < int > histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias) {
    vector<int> resp = {};
    resp.push_back(cantidadDeHogaresPorAnillo(0, distancias[0], centro, th));
    for (int k = 1; k < distancias.size(); k++) {
        resp.push_back (cantidadDeHogaresPorAnillo(distancias[k - 1], distancias[k], centro, th));
    }
    return resp;
}

