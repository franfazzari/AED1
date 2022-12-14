#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../auxiliares.h"

using namespace std;


TEST(ordenarRegionYCODUSUTEST, regionesDistintas) {

    eph_h th = {                 //
        {2,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
        {4,  2017, 1, 1, 1, 0, 40, 4, 1, 2},
        {3,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
        {5,  2017, 1, 1, 1, 0, 41, 4, 1, 2},
        {1,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
        {9,  2017, 1, 1, 1, 0, 42, 4, 1, 2},
        {10,  2017, 1, 1, 1, 0, 43, 4, 1, 2},
    };

    eph_i ti = {
            {2, 2017,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
            {3, 2017,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
            {3, 2017,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
            {1, 2017,   2,  1,  3,  2,  28, 1,  3,  0,      6},
            {5, 2017,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
            {10, 2017,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
            {5, 2017,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
            {9, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {4, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1}
    };


    eph_h th_esperado = {
            {1,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {2,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {3,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {4,  2017, 1, 1, 1, 0, 40, 4, 1, 2},
            {5,  2017, 1, 1, 1, 0, 41, 4, 1, 2},
            {9,  2017, 1, 1, 1, 0, 42, 4, 1, 2},
            {10,  2017, 1, 1, 1, 0, 43, 4, 1, 2}
    };

    eph_i ti_esperado = {
            {1, 2017,   2,  1,  3,  2,  28, 1,  3,  0,      6},
            {2, 2017,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
            {3, 2017,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
            {3, 2017,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
            {4, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {5, 2017,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
            {5, 2017,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
            {9, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {10, 2017,   5,  0,  3,  2,  15, 0,  0,  5000,   1}

    };


        ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}


TEST(ordenarRegionYCODUSUTEST, regionesDistintasTodoAlreves) {

    eph_h th = {                 //
            {10,  2017, 1, 1, 1, 0, 43, 4, 1, 2},
            {9,  2017, 1, 1, 1, 0, 42, 4, 1, 2},
            {5,  2017, 1, 1, 1, 0, 41, 4, 1, 2},
            {4,  2017, 1, 1, 1, 0, 40, 4, 1, 2},
            {3,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {2,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {1,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
    };

    eph_i ti = {
            {10, 2017,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
            {9, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {5, 2017,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
            {5, 2017,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
            {4, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {3, 2017,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
            {3, 2017,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
            {2, 2017,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
            {1, 2017,   2,  1,  3,  2,  28, 1,  3,  0,      6},
    };


    eph_h th_esperado = {
            {1,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {2,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {3,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {4,  2017, 1, 1, 1, 0, 40, 4, 1, 2},
            {5,  2017, 1, 1, 1, 0, 41, 4, 1, 2},
            {9,  2017, 1, 1, 1, 0, 42, 4, 1, 2},
            {10,  2017, 1, 1, 1, 0, 43, 4, 1, 2}
    };

    eph_i ti_esperado = {
            {1, 2017,   2,  1,  3,  2,  28, 1,  3,  0,      6},
            {2, 2017,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
            {3, 2017,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
            {3, 2017,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
            {4, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {5, 2017,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
            {5, 2017,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
            {9, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {10, 2017,   5,  0,  3,  2,  15, 0,  0,  5000,   1}

    };


    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}



TEST(ordenarRegionYCODUSUTEST, faltaUnaRegion) {

    eph_h th = {                 //
            {2,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {4,  2017, 1, 1, 1, 0, 40, 4, 1, 2},
            {3,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {1,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {9,  2017, 1, 1, 1, 0, 42, 4, 1, 2},
            {10,  2017, 1, 1, 1, 0, 43, 4, 1, 2},
    };

    eph_i ti = {
            {2, 2017,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
            {3, 2017,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
            {3, 2017,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
            {1, 2017,   2,  1,  3,  2,  28, 1,  3,  0,      6},
            {10, 2017,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
            {9, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {4, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1}
    };


    eph_h th_esperado = {
            {1,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {2,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
            {3,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
            {4,  2017, 1, 1, 1, 0, 40, 4, 1, 2},
            {9,  2017, 1, 1, 1, 0, 42, 4, 1, 2},
            {10,  2017, 1, 1, 1, 0, 43, 4, 1, 2}
    };

    eph_i ti_esperado = {
            {1, 2017,   2,  1,  3,  2,  28, 1,  3,  0,      6},
            {2, 2017,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
            {3, 2017,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
            {3, 2017,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
            {4, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {9, 2017,   1,  0,  3,  1,  18, 0,  0,  20000,  1},
            {10, 2017,   5,  0,  3,  2,  15, 0,  0,  5000,   1}

    };


    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}
