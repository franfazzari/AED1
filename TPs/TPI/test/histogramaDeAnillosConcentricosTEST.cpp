#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;



TEST(histogramaDeAnillosConcentricosTEST, testNormal) {
    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};

    eph_h th = {{22114, 2018,   3,  1, 1, 3,  41, 1,  1,  3,  1,  2},
                {31117, 2018,   3,  5, 6, 3,  40, 1,  1,  6,  6,  1},
                {22866, 2018,   3,  10, 10, 2,  42, 1,  3,  2,  2,  1},
                {22867, 2018,   3,  50, 49, 2,  42, 1,  3,  2,  2,  1},
                {20957, 2018,   3,  0, 0, 1,  43, 0,  1,  3,  1,  1}};

    eph_i ti = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22867, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
                {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};

    vector<int> res = {2, 1, 0, 1};

    vector < int > respuestafunc = histogramaDeAnillosConcentricos(th, ti, centro, distancias);

    EXPECT_EQ(res, respuestafunc);
}


TEST(histogramaDeAnillosConcentricosTEST, todosFueraDeRango) {
    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};

    eph_h th = {{22114, 2018,   3,  12222, 2222, 3,  41, 1,  1,  3,  1,  2},
                {31117, 2018,   3,  5324, 64324, 3,  40, 1,  1,  6,  6,  1},
                {22866, 2018,   3,  1000, 1077, 2,  42, 1,  3,  2,  2,  1},
                {20957, 2018,   3,  5000, 6000, 1,  43, 0,  1,  3,  1,  1}};

    eph_i ti = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
                {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};

    vector<int> res = {0, 0, 0, 0};

    vector < int > respuestafunc = histogramaDeAnillosConcentricos(th, ti, centro, distancias);

    EXPECT_EQ(res, respuestafunc);
}

TEST(histogramaDeAnillosConcentricosTEST, todasEnLimite) {
    vector<int> distancias = {5, 10, 100, 5000};

    pair<int, int> centro = {0, 0};

    eph_h th = {{22114, 2018,   3,  5, 0, 3,  41, 1,  1,  3,  1,  2},
                {31117, 2018,   3,  0, 10, 3,  40, 1,  1,  6,  6,  1},
                {22866, 2018,   3,  100, 0, 2,  42, 1,  3,  2,  2,  1},
                {20957, 2018,   3,  5000, 0, 1,  43, 0,  1,  3,  1,  1}};

    eph_i ti = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
                {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};

    vector<int> res = {1, 1, 1, 1};

    vector < int > respuestafunc = histogramaDeAnillosConcentricos(th, ti, centro, distancias);

    EXPECT_EQ(res, respuestafunc);
}
