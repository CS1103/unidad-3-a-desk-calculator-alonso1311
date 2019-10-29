#include"Calculate.h"

void calculate() {
    for(;;) {
        ts.get();
        if(ts.current().kind == Kind::end)
            break;
        if(ts.current().kind == Kind::print)
            continue;
    }    
}
