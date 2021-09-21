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


unsigned RSA::_phi() { // _phi (p-1)*(q-1)
    phi = (p-1)*(q-1);
    return phi;
}

unsigned RSA::_N() { // n = p*q
    return p*q;
}

void RSA::set_e() { // calculates an encryption key e
    e = 2;
    while(gcd(e, phi) != 1) {
        ++e;
    }
    if(e >= phi) throw(runtime_error("e is invalid or equal to phi"));
}

void RSA::set_d() { // set decryption key
    
}

int main() {
    RSA test;
    test.input();
    int num = test._phi();
    cout << num << endl;
}