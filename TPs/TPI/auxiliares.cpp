#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include<cmath>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA esEncuestaValida DEL PUNTO 1:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool esMatriz(vector<vector <int>> t){
    bool res = true;
    if (t.size() == 1){
        return res;
    }
    for (int i = 0; i < t.size() -1 ; ++i){
        if (t[i].size() != t[i+1].size()){
            res = false;
            return res;
        }
    } return res;
}

bool esCantidadCorrectaDeColumnasI(eph_i ti){
    bool res = true;
    for (int i = 0; i < ti.size() ; ++i) {
        if(ti[i].size() != 11){
            res = false;
            return res;
        }
    }
    return res;
}

bool esCantidadCorrectaDeColumnasH(eph_h th){
    bool res = true;
    for (int h = 0; h < th.size() ; ++h) {
        if(th[h].size() != 12){
            res = false;
            return res;
        }
    }
    return res;
}

bool noHayIndividuosSinHogares(eph_h th, eph_i ti){
    bool res = false;
    for(int i=0; i < ti.size(); i++){
        for(int h=0; h < th.size(); h++){
            if(th[h][0] == ti[i][0]){
                res = true;
                break;
            } else {
                if (h == th.size()-1){
                    return res = false;}
            }
        }
    }
    return res;
}

bool noHayHogaresSinIndividuos(eph_h th, eph_i ti){
    bool res = false;
    for(int h=0; h < th.size(); h++){
        for(int i=0; i < ti.size(); i++){
            if(ti[i][0] == th[h][0]){
                res = true;
                break;
            } else {
                if (i == ti.size()-1) {
                    return res = false;
                }
            }
        }
    }
    return res;
}

bool noHayIndividuosRepetidos(eph_i ti){
    bool res = true;
    for(int i=0; i < ti.size() - 1; i++){
        for (int j = i + 1; j <ti.size() ; ++j) {
            if(ti[i][0] == ti[j][0] && ti[i][2] == ti[j][2]){
                return res = false;
            }
        }
    }
    return res;
}

bool noHayHogaresRepetidos(eph_h th){
    bool res = true;
    for(int h=0; h < th.size() ; h++){
        for (int j = h + 1; j <th.size() ; ++j) {
            if(th[h][0] == th[j][0]) {
                return res = false;
            }
        }
    }
    return res;
}

bool esMismoAnioYTrimestre(eph_h th, eph_i ti) {
    bool res = true;
    int anio = ti[0][INDANIO];
    int trimestre = ti[0][INDTRIMESTRE];
    for (int i = 1; i < ti.size(); ++i) {
        if (ti[i][INDTRIMESTRE] != trimestre || ti[i][INDANIO] != anio){
            res = false;
            return res;
        }
    }
    for (int h = 0; h < th.size(); ++h) {
        if (th[h][HOGANIO] != anio || th[h][HOGTRIMESTRE] != trimestre) {
            res = false;
            return res;
        }
    }
    return res;
}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti){
    bool res = true;
    for(int h=0; h < th.size(); h++){
        if(cantidadDeHabitantes(th[h], ti) >20){
            return res = false;}
    }
    return res;
}

bool cantidadValidaDormitorios(eph_h th){
    bool res = true;
    for(int h=0; h < th.size(); h++) {
        if (th[h][IV2] < th[h][II2]) {
            return res = false;
        }
    }
    return res;
}

bool esRegionValida(hogar h){
    bool res = false;
    if(h[REGION] == 1 || (40 <= h[REGION] && h[REGION] <= 44)) {
        res = true;
    }
    return res;
}


bool losValoresEstanEnRangoH(eph_h th){
    bool res = true;
    for(int h=0; h < th.size(); h++){
        if(th[h][HOGCODUSU] <= 0 || th[h][HOGTRIMESTRE] < 1 || th[h][HOGTRIMESTRE] > 4 || th[h][II7] < 1 || th[h][II7] > 3
           || !esRegionValida(th[h]) || th[h][MAS_500] < 0 || th[h][MAS_500] > 1 || th[h][IV1] < 1 || th[h][IV1] > 5 ||
           th[h][IV2] < 1 || th[h][II2] < 1 || th[h][II3] < 1 || th[h][II3] > 2){
            return res = false;
        }
    }
    return res;
}

bool esIngresoValido(individuo i){
    bool res = false;
    if(i[p47T] >= -1){
        res = true;
    }
    return res;
}

bool losValoresEstanEnRangoI(eph_i ti){
    bool res = true;
    for(int i=0; i < ti.size(); i++){
        if(ti[i][INDCODUSU] <= 0 || ti[i][COMPONENTE] <= 0 || ti[i][INDTRIMESTRE] < 1 || ti[i][INDTRIMESTRE] > 4 ||
           ti[i][CH4] < 1 || ti[i][CH4] > 2 || ti[i][CH6] < 0 || ti[i][NIVEL_ED] < 0 || ti[i][NIVEL_ED] > 1 ||
           ti[i][ESTADO] < -1 || ti[i][ESTADO] > 1 || ti[i][CAT_OCUP] < 0 || ti[i][CAT_OCUP] > 4 || !esIngresoValido(ti[i])
           || ti[i][PP04G] < 0 || ti[i][PP04G] > 10){
            return res = false;
        }
    }
    return res;
}

bool esSuHogar (hogar h, individuo i){
    bool resp = false;
    if (h[HOGCODUSU] == i[INDCODUSU]){
        resp = true;
    }
    return resp;

}

int cantidadDeHabitantes (hogar h, eph_i ti){
    int contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (esSuHogar(h,ti[i])){
            contador++;
        }
    }
    return contador;
}



bool esValida(eph_h th, eph_i ti){
    bool res = true;
    if(th.size() == 0 || ti.size() == 0 || !esMatriz(th) || !esMatriz(ti) || !esCantidadCorrectaDeColumnasH(th)
       || !esCantidadCorrectaDeColumnasI(ti) || !noHayIndividuosSinHogares(ti, th) || !noHayIndividuosSinHogares(th, ti)
       || !noHayHogaresSinIndividuos(th, ti) || !noHayHogaresRepetidos(th) || !noHayIndividuosRepetidos(ti) ||
       !esMismoAnioYTrimestre(th, ti) || !menosDe21MiembrosPorHogar(th, ti) || !cantidadValidaDormitorios(th) ||
       !losValoresEstanEnRangoI(ti) || !losValoresEstanEnRangoH(th)){

        res = false;
    }
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA histHabitacional DEL PUNTO 2:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cantidadMaximadeHabitacionesEnRegionDada (eph_h th, int region){
    int res = 0;
    for (int i = 0; i < th.size(); i++){
        if (th[i][REGION] == region && th[i][IV1] == 1 && th[i][IV2] > res){

            res = th[i][IV2];

        }
    }
    return res;
}

int cantidadCasasConiHabitacionesEnRegionDada (eph_h th, int region, int k){
    int res = 0;
    for (int i = 0; i < th.size(); i++){
        if (th[i][REGION] == region && th[i][IV1] == 1 && th[i][IV2] == k){
            res++;
        }
    }
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA laCasaEstaQuedandoChica DEL PUNTO 3:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool esHogarConHacinamientoCritico(hogar h, eph_i ti){
    bool res = false;
    if(cantidadDeHabitantes(h, ti) > 3*h[II2] ){
        res = true;
    }
    return res;
}

bool esHogarValido (hogar h, dato region){
    if (h[IV1]==1 && h[REGION]==region && h[MAS_500]==0){
        return true;
    } else {
        return false;
    }
}

float cantidadDeHogaresValidos(eph_h th, dato region){
    float res = 0;
    for (int h = 0; h < th.size(); ++h) {
        if (esHogarValido(th[h], region)){
            res++;
        }
    }
    return res;
}

float cantidadDeHogaresValidosConHC(eph_h th, eph_i ti, int region){
    float res = 0;
    for(int h=0; h < th.size(); h++){
        if(esHogarValido(th[h],region) && esHogarConHacinamientoCritico (th[h], ti)){
            res++;
        }
    }
    return res;
}

float proporcionHogaresConHC(eph_h th, eph_i ti, dato region){
    float res = 0;
    if (cantidadDeHogaresValidos(th,region) > 0){
        res = cantidadDeHogaresValidosConHC(th, ti, region) / cantidadDeHogaresValidos(th, region);
    }
    return res;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA proporcionTeleworking DEL PUNTO 4:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool esCasaODepartamento (hogar h) {
    bool res = false;
    if (h[IV1] == 1 || h[IV1] == 2){
        res = true;
    }
    return res;
}

bool trabaja (individuo i){
    bool res = i[ESTADO] == 1;
    return res;
}

bool suHogarEsCasaODepartamento(individuo i, eph_h th){
    bool res = false;
    for (int h = 0; h < th.size(); ++h) {
        if (esSuHogar(th[h],i) && esCasaODepartamento (th[h])){
            res = true;
            return res;
        }
    }
    return res;
}

bool esDeCiudadGrande (individuo i, eph_h th){
    bool res = false;
    for (int h = 0; h < th.size(); ++h) {
        if (esSuHogar(th[h],i) && th[h][MAS_500] == 1){
            res = true;
            return res;
        }
    }
    return res;
}

bool individuoEnHogarValido (individuo i, eph_h th){
    bool res = false;
    if (esDeCiudadGrande (i,th) && suHogarEsCasaODepartamento(i,th)){
        res = true;
    }
    return res;
}

float cantIndividuosQueTrabajan (eph_h th, eph_i ti) {
    float contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (trabaja(ti[i]) && individuoEnHogarValido(ti[i], th)){
            contador ++;
        }
    }
    return contador;
}

bool tieneEspaciosReservadosParaElTrabajo(hogar h){
    bool resp = false;
    if (h[II3] == 1){
        resp = true;
    }
    return resp;
}

bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo i, eph_h th){
    bool resp = false;
    for (int h = 0; h < th.size() ; ++h) {
        if (esSuHogar(th[h],i) && tieneEspaciosReservadosParaElTrabajo(th[h])){
            resp = true;
            return resp;
        }
    }
    return resp;
}

bool realizaSusTareasEnEsteHogar(individuo i){
    bool resp = false;
    if (i[PP04G] == 6){
        resp = true;
    }
    return resp;
}

bool trabajaEnSuVivienda (individuo i, eph_h th){
    bool resp = false;
    if(realizaSusTareasEnEsteHogar(i) && suHogarTieneEspaciosReservadosParaElTrabajo(i, th)){
        resp = true;
    }
    return resp;
}

float cantIndividuosTrabajandoEnSuVivienda (eph_h th, eph_i ti) {
    float contador = 0;
    for (int i = 0; i < ti.size(); ++i) {
        if (trabaja (ti[i]) && individuoEnHogarValido (ti[i], th) && trabajaEnSuVivienda(ti[i],th)){
            contador++;
        }
    }
    return contador;
}

float proporcionTeleworking (eph_h th, eph_i ti) {
    float resp = 0;
    if (cantIndividuosQueTrabajan (th,ti)>0){
        resp = (cantIndividuosTrabajandoEnSuVivienda (th,ti) )/ (cantIndividuosQueTrabajan (th,ti));
    }
    return resp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA costoSubsidioMejora DEL PUNTO 5:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool tieneCasaPropia (hogar h){
    bool resp = false;
    return resp = h[II7] == 1;
}

bool tieneCasaChica (hogar h, eph_i ti){
    bool resp = false;
    if ((cantidadDeHabitantes(h, ti) -2) > h[II2]){
        resp = true;
    }
    return resp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA ordenarRegionYCODUSU DEL PUNTO 7:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarPorCodusuTh(eph_h &th){
    for (int j = 0; j < th.size(); j++){
        for (int i = 0; i < th.size()-1; i++){
            if (th[i][HOGCODUSU] > th[i+1][HOGCODUSU]){
                hogar temp;
                temp = th[i];
                th[i] = th[i+1];
                th[i+1] = temp;
            }
        }
    }
}

void ordenarPorRegiones(eph_h &th){
    for (int j = 0; j < th.size(); j++){
        for (int i = 0; i < th.size()-1; i++){
            if (th[i][REGION] > th[i+1][REGION]){
                hogar temp;
                temp = th[i];
                th[i] = th[i+1];
                th[i+1] = temp;
            }
        }
    }
}

void ordenarPorComponenteTi (eph_i &ti){
    for (int j = 0; j < ti.size(); j++){
        for (int i = 0; i < ti.size()-1; i++){
            if (ti[i][COMPONENTE] > ti[i+1][COMPONENTE]){
                individuo temp;
                temp = ti[i];
                ti[i] = ti[i+1];
                ti[i+1] = temp;
            }
        }
    }
}

vector < int > listaDeHogcodususOrdenados (eph_h th){
    vector <int> result;
    for (int i = 0; i < th.size(); i++) {
        if (!perteneceAlVector(result,th[i][HOGCODUSU])) {
            result.push_back(th[i][HOGCODUSU]);
        }
    }
    return result;
}

bool perteneceAlVector(vector <int> v, int n){
    bool result = false;
    for (int i = 0; i < v.size(); i++){
        if (v[i] == n){
            result = true;
        }
    }
    return result;
}

bool primerCodusuEstaAntes (dato primer, dato segundo, vector <int> l){
    bool res = false;
    int i = 0;
    int j = 0;
    for (; i < l.size(); i++){
        if (l[i] == primer){
            break;
        }
    }
    for (;j < l.size(); j++){
        if (l[j] == segundo){
            break;
        }
    }
    if ( i < j){
        res = true;
    }
    return res;
}

void ordenarPorCODUSUTi (eph_i &ti, const vector <int> lista){
    for (int j = 0; j < ti.size() ; j++) {
        for (int i = 0; i < ti.size() - 1; i++){
            if (primerCodusuEstaAntes(ti[i+1][HOGCODUSU], ti[i][HOGCODUSU], lista)) {
                individuo temp;
                temp = ti[i];
                ti[i] = ti[i + 1];
                ti[i + 1] = temp;
            }
        }
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA muestraHomogenea DEL PUNTO 8:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ingresosHogar (eph_i ti, int hogcodusu){
    int ingresosHogar = 0;
    for (int i = 0; i < ti.size(); i++){
        if (ti[i][INDCODUSU] == hogcodusu && ti[i][p47T] != -1){
            ingresosHogar = ingresosHogar + ti[i][p47T];
        }
    }
    return ingresosHogar;
}

vector <pair<int,int>> listaHogaresConIngresos (eph_h th, eph_i ti){
    vector <pair<int,int>> v;
    for (int i = 0; i < th.size(); i++){
        pair <int,int> temp;
        temp.first = th[i][HOGCODUSU];
        temp.second = ingresosHogar(ti,th[i][HOGCODUSU]);
        v.push_back(temp);
    }
    return v;
}

void ordenarHogaresPorIngresos (vector <pair<int,int>> &l){
    for (int j = 0; j < l.size(); j++) {
        for (int i = 0; i < l.size() - 1; i++) {
            if (l[i].second > l[i + 1].second) {
                pair<int, int> temp;
                temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
            }
        }
    }
}

vector<int> listaDeHogaresOptimos (vector <pair<int,int>> listaIngresos) {
    vector<int> listaDePosicionesMayor;
    vector<int> listaDePosicionesTemporal;
    for (int k = 0; k < listaIngresos.size() - 1; ++k) {
        for (int m = k + 1; m < listaIngresos.size(); ++m) {
            listaDePosicionesTemporal = {k, m};
            int diferencia = listaIngresos[m].second - listaIngresos[k].second;
            for (int n = m + 1; n < listaIngresos.size(); ++n) {
                                                                // v ultima Posicion Guardada en listaDePosicionesTemporales
                if (listaIngresos[n].second - listaIngresos[listaDePosicionesTemporal[listaDePosicionesTemporal.size() - 1]].second ==
                    diferencia && diferencia != 0) {
                    listaDePosicionesTemporal.push_back(n);
                } 
            }
                if (listaDePosicionesTemporal.size() > listaDePosicionesMayor.size()) {
                    listaDePosicionesMayor = listaDePosicionesTemporal;
                }
        }
    }
        vector<int> listaHogcodusu;
        for (int i = 0; i < listaDePosicionesMayor.size(); ++i) {
            for (int j = 0; j < listaIngresos.size(); ++j) {
                if (listaDePosicionesMayor[i] == j) {
                    listaHogcodusu.push_back(listaIngresos[j].first);
                    break;

                }
            }
        }
        return listaHogcodusu;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA corregirRegion DEL PUNTO 9:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cambiaRegionGBAaPampeana(eph_h &th){
    for(int h=0; h < th.size(); h++){
        if(th[h][REGION] == GBA){
            th[h][REGION] = PAMPEANA;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA histogramaDeAnillosConcentricos DEL PUNTO 10:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cuadrado(int a){
    int b;
    return b = a*a;
}

float distanciaEuclideana(pair < float, float > centro, float latitud, float longitud){
    float res;
    return res = sqrt(cuadrado(centro.first - latitud) + cuadrado(centro.second - longitud));
}

bool estaElHogarEnAnillo(int distDesde, int distHasta, pair < int, int > centro, hogar hog){
    bool res = false;
    if(distDesde < distanciaEuclideana(centro, hog[HOGLATITUD], hog[HOGLONGITUD]) &&
       distanciaEuclideana(centro, hog[HOGLATITUD], hog[HOGLONGITUD]) <= distHasta){
        res = true;
    }
    return res;
}

int cantidadDeHogaresPorAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th){
    int res = 0;
    for(int k=0; k < th.size(); k++){
        if(estaElHogarEnAnillo(distDesde, distHasta, centro, th[k])){
            res = res + 1;
        }
    }
    return res;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES PARA quitarIndividuos DEL PUNTO 11:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool cumpleBusqueda(individuo ind, vector <pair <int,dato> > busqueda){
    bool res = true;
    for(int b=0; b < busqueda.size(); b++){
        if (ind[busqueda[b].first] != busqueda[b].second){
            return res = false;
        }
    }
    return res;
}

vector< vector<int> > tablaIndividuos(eph_i ti, vector <pair <int,dato> > busqueda){

    vector< vector<int> > tablaI;
    for(int i=0; i < ti.size(); i++){
        if (cumpleBusqueda(ti[i], busqueda)){
            tablaI.push_back(ti[i]);
        }
    }
    return tablaI;
}

vector< vector<int> > tablaHogares(eph_h th, eph_i ti, vector <pair <int,dato> > busqueda){
    vector< vector<int> > tablaH;
    vector<vector<int>> tablaI = tablaIndividuos(ti, busqueda);
    for(int h=0; h < th.size(); h++){
        for(int i=0; i < tablaI.size(); i++){
            if(tablaI[i][INDCODUSU] == th[h][HOGCODUSU]){
                tablaH.push_back(th[h]);
                break;
            }
        }
    }
    return tablaH;
}

vector< vector<int> > restoDeTablaIndividuos(eph_i ti,  vector <pair <int,dato> > busqueda){
    vector< vector<int> > tablaIR;

    for(int i=0; i < ti.size(); i++){
        if (!cumpleBusqueda(ti[i], busqueda)){
            tablaIR.push_back(ti[i]);
        }
    }
    return tablaIR;
}

vector< vector<int> > restoDeTablaHogares(eph_h th, eph_i ti,  vector <pair <int,dato> > busqueda){
    vector< vector<int> > tablaHR;
    vector<vector<int>> tablaI = restoDeTablaIndividuos(ti, busqueda);
    for(int h=0; h < th.size(); h++) {
        for (int i = 0; i < tablaI.size(); i++){
            if (tablaI[i][INDCODUSU] == th[h][HOGCODUSU]) {
                tablaHR.push_back(th[h]);
                break;
            }
        }
    }
    return tablaHR;
}
