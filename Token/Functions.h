#ifndef Functions_H
#define Functions_H

#include"Token_stream.h"
#include"Error.h"
#include"Definiciones.h"

extern map<string, double> table;

double term(bool get); //multiplicacion y division

double prim(bool get);

double expr(bool get); //suma y resta

void calculate();

#endif //Functions_H
