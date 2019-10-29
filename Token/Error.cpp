#include"Error.h"

double error(const string&s) {
    no_of_errors++;
    cerr << "error: " << s << '\n';
    return 1;
}
