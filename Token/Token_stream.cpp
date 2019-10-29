#include"Token_stream.h"

Token_stream::Token_stream(istream& s) : ip{&s}, owns{false} {}

Token_stream::Token_stream(istream* p) : ip{p}, owns{true} {}

Token Token_stream::get() { 
    char ch = 0;

    do {
        if(!ip->get(ch))
            return ct = {Kind::end};
    } while(ch != '\n' && isspace(ch));

    switch(ch) {
        case ';':

        case '\n':
            return ct = {Kind::print};
            
        case '*':

        case '/':

        case '+':

        case '-':

        case '(':

        case ')':

        case '=':
            return ct = {static_cast<Kind>(ch)};

        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '8': case '9':
        case '.':
            ip->putback(ch);
            *ip >> ct.number_value;
            ct.kind = Kind::number;
            return ct;

        default:
            if(isalpha(ch)) {
                ct.string_value = ch;
                while(ip->get(ch) && isalnum(ch))
                    ct.string_value += ch;
                ip->putback(ch);
                return ct = {Kind::end};
            }
            error("bad token");
            return ct = {Kind::print};
        }
}

const Token& Token_stream::current() {
    return ct;
}

void Token_stream::set_input(istream& s) {
    close();
    ip = &s;
    owns = false;
}

void Token_stream::set_input(istream* p) {
    close();
    ip = p;
    owns = true;
}

Token_stream::~Token_stream() {
    close();
}
