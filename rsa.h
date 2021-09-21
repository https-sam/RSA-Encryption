#ifndef MINIGIT_HPP
#define MINIGIT_HPP

#include <string>


class RSA {
    public:
        void input();
        unsigned _phi();
        unsigned _N();
        void set_e(); // set encryption key
        void set_d(); // set decryption key
        
        

    private:
        unsigned p, q; // prime numbers
        unsigned n; // p*q
        unsigned phi; //(p-1)(q-1)
        unsigned e, d; // (e*d)modT=1

        
};


#endif