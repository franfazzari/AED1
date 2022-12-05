#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES esEncuestaValida IMPLEMENTACION 1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool esMatriz(vector<vector <int>> t);

bool esCantidadCorrectaDeColumnasI(vector<vector <int>> t);

bool esCantidadCorrectaDeColumnasH(vector<vector <int>> t);

bool noHayIndividuosSinHogares(eph_h th, eph_i ti);

bool noHayHogaresSinIndividuos(eph_h th, eph_i ti);

bool noHayIndividuosRepetidos(eph_i ti);

bool noHayHogaresRepetidos(eph_h th);

bool esMismoAnioYTrimestre(eph_h th, eph_i ti) ;

bool menosDe21MiembrosPorHogar(eph_i ti, eph_h th);

bool cantidadValidaDormitorios(eph_h th);

bool esRegionValida(hogar h);

bool losValoresEstanEnRangoH(eph_h th);

bool esIngresoValido(individuo);

bool losValoresEstanEnRangoI(eph_i ti);

bool esValida(eph_h th, eph_i ti);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES histHabitacional IMPLEMENTACION 2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cantidadMaximadeHabitacionesEnRegionDada (eph_h th, int region);

int cantidadCasasConiHabitacionesEnRegionDada (eph_h th, int region, int k);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES laCasaEstaQuedandoChica IMPLEMENTACION 3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool esHogarConHacinamientoCritico(hogar h, eph_i ti);

bool esHogarValido (hogar h, dato region);

float cantidadDeHogaresValidos(eph_h th, dato region);

float cantidadDeHogaresValidosConHC(eph_h th, eph_i ti, dato region);

float proporcionHogaresConHC(eph_h th, eph_i ti, dato region);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES proporcionTeleworking IMPLEMENTACION 4
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool esSuHogar (hogar h, individuo i);

bool esCasaODepartamento (hogar h);

bool trabaja (individuo i);

bool suHogarEsCasaODepartamento(individuo i, eph_h th);

bool esDeCiudadGrande (individuo i, eph_h th);

bool individuoEnHogarValido (individuo i, eph_h th);

float cantIndividuosQueTrabajan (eph_h th, eph_i ti);

float cantIndividuosTrabajandoEnSuVivienda (eph_h th, eph_i ti);

bool tieneEspaciosReservadosParaElTrabajo(hogar h);

bool suHogarTieneEspaciosReservadosParaElTrabajo(individuo i, eph_h th);

bool realizaSusTareasEnEsteHogar(individuo i);

bool trabajaEnSuVivienda (individuo i, eph_h th);

float proporcionTeleworking (eph_h th, eph_i ti);

vector< vector<int> > tablaHogares(eph_h th, eph_i ti, vector <pair <int,dato> > busqueda);

vector< vector<int> > restoDeTablaIndividuos(eph_i ti,  vector <pair <int,dato> > busqueda);

vector< vector<int> > restoDeTablaHogares(eph_h th, eph_i ti,  vector <pair <int,dato> > busqueda);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES costoSubsidioMejora IMPLEMENTACION 5
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool tieneCasaPropia (hogar h);

int cantidadDeHabitantes (hogar h, eph_i ti);

bool tieneCasaChica (hogar h, eph_i ti);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES ordenarRegionYCODUSU IMPLEMENTACION 7
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarPorRegiones (eph_h &th);

void ordenarPorCodusuTh (eph_h &th);

void ordenarPorComponenteTi (eph_i &ti);

void ordenarPorCODUSUTi (eph_i &ti, vector <int> lista);

vector < int > listaDeHogcodususOrdenados (eph_h th);

bool primerCodusuEstaAntes (dato primer, dato segundo, vector <int>& l);

bool perteneceAlVector (vector <int> v, int n);

int ingresosHogar (eph_i ti, int hogcodusu);

vector <pair<int,int>> listaHogaresConIngresos (eph_h th, eph_i ti);

void ordenarHogaresPorIngresos (vector <pair<int,int>> &l);

bool perteneceALista (int valor, vector <pair<int,int>> &l);

int laDifferenciaQueMasAparece (vector <pair<int,int>> &l);

vector <int> hogcodususDeDifs(int valor, vector <pair<int,int>> &l);

vector <hogar> listaDeHogaresFinales(eph_h &th, vector <int> &l);

vector<int> listaDeHogaresOptimos (vector <pair<int,int>> listaIngresos);

vector< vector<int> > tablaIndividuos(eph_i ti, vector <pair <int,dato> > busqueda);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES muestraHomogenea IMPLEMENTACION 8
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ingresosHogar (eph_i ti, int hogcodusu);

vector <pair<int,int>> listaHogaresConIngresos (eph_h th, eph_i ti);

void ordenarHogaresPorIngresos (vector <pair<int,int>> &l);

vector<int> listaDeHogaresOptimos (vector <pair<int,int>> listaIngresos);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES corregirRegion IMPLEMENTACION 9
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cambiaRegionGBAaPampeana(eph_h & th);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES quitarIndividuos IMPLEMENTACION 10
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool cumpleBusqueda(individuo ind, vector <pair <int,dato> > busqueda);

void cambiaRegionGBAaPampeana(eph_h &th);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES histogramaDeAnillosConcentricos IMPLEMENTACION 11
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cuadrado(int a);

float distanciaEuclideana(pair < float, float > centro, float latitud, float longitud);

bool estaElHogarEnAnillo(int distDesde, int distHasta, pair < int, int > centro, hogar hog);

int cantidadDeHogaresPorAnillo(int distDesde, int distHasta, pair < int, int > centro, eph_h th);

bool cumpleBusqueda(individuo ind, vector <pair <int,dato> > busqueda);

vector< vector<int> > tablaIndividuos(eph_i ti, vector <pair <int,dato> > busqueda);

vector< vector<int> > tablaHogares(eph_h th, eph_i ti, vector <pair <int,dato> > busqueda);

vector< vector<int> > restoDeTablaIndividuos(eph_i ti,  vector <pair <int,dato> > busqueda);

vector< vector<int> > restoDeTablaHogares(eph_h th, eph_i ti,  vector <pair <int,dato> > busqueda);

#endif //SOLUCION_AUXILIARES_H
