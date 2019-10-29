#ifndef Token_stream_H
#define Token_stream_H

#include"Token.h"
#include"Error.h"

class Token_stream {
public:
    Token_stream(istream& s);
    Token_stream(istream* p);

    Token get(); //read and return next token
       
    const Token& current(); //most recently read token

    void set_input(istream& s);

    void set_input(istream* p);

    virtual ~Token_stream();

private:
   void close() {
       if(owns)
           delete ip;
   }

   istream* ip;
   bool owns;
   Token ct {Kind::end};
};


#endif //Token_stream_H
