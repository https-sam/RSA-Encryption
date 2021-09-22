#include "rsa.h"
#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>

using namespace std;

void RSA::input() { // prompts to enter p and q 
    cout << "Enter p" << endl;
    cin >> p;
    cout << "Enter q" << endl;
    cin >> q;
}


unsigned RSA::set_phi() { // _phi (p-1)*(q-1)
    phi = (p-1)*(q-1);
    return phi;
}

unsigned RSA::set_N() { // n = p*q
    return p*q;
}

unsigned RSA::set_e() { // calculates an encryption key e
    e = 2;
    while(gcd(e, phi) != 1) {
        ++e;
    }
    if(e >= phi) throw(runtime_error("e is invalid or equal to phi"));

    else return e;
}

unsigned RSA::set_d() { // set decryption key
    unsigned C = 1;
    while(((C*phi)+1)%e != 0) {
        ++C;
    }
    d = ((C*phi)+1)/e;
    return d;
}

int main() {
    try{
        RSA test;
        test.input();
        unsigned phi = test.set_phi();
        unsigned N = test.set_N();
        unsigned e = test.set_e();
        unsigned d = test.set_d();
        cout << "N is " << N << endl;
        cout << "Phi is " << phi << endl;
        cout << "e is " << e << endl;
        cout << "d is " << d << endl;
    }

    catch (runtime_error & error) {
        cout << error.what() << endl;
    }
}