#ifndef Functions_H
#define Functions_H

#include"Token_stream.h"
#include"Error.h"

extern map<string, double> table;

double expr(bool get); //suma y resta

double term(bool get); //multiplicacion y division

double prim(bool get);

void calculate();

#endif //Functions_H
