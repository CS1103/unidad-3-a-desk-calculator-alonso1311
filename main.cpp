#include"Token/Functions.h"
#include"Token/Error.h"

int no_of_errors;
map<string, double> table;

int main(int argc, char* argv[]) {
    table["pi"] = 3.1415926535897932385;
    table["e"] = 2.7182818284590452354;
    cout << "Empieza el programa: \n";
    calculate();

    return no_of_errors;
}
