#include <iostream>
#include "rational.hpp"

using namespace std;

// Alcuni test per la classe rational

int main() {
    // TEST COSTRUTTORI E SEMPLIFICAZIONE 
    rational<int> r1(4, 8);         
    rational<int> r2(-3, -9);       
    rational<int> r3(5, -10);       
    rational<int> r4(7, 1);         
    rational<int> r5;               

    cout << "--- TEST COSTRUTTORI E SEMPLIFICAZIONE ---" << endl;
    cout << "4/8   -> " << r1 << " (atteso: 1/2)" << endl;
    cout << "-3/-9 -> " << r2 << " (atteso: 1/3)" << endl;
    cout << "5/-10 -> " << r3 << " (atteso: -1/2)" << endl;
    cout << "7/1   -> " << r4 << " (atteso: 7)" << endl;
    cout << "Def   -> " << r5 << " (atteso: 0)" << endl << endl;

    // TEST ARITMETICA STANDARD 
    rational<int> a(1, 2);
    rational<int> b(1, 3);

    cout << "--- TEST ARITMETICA STANDARD ---" << endl;
    cout << a << " + " << b << " = " << (a + b) << " (atteso: 5/6)" << endl;
    cout << a << " - " << b << " = " << (a - b) << " (atteso: 1/6)" << endl;
    cout << a << " * " << b << " = " << (a * b) << " (atteso: 1/6)" << endl;
    cout << a << " / " << b << " = " << (a / b) << " (atteso: 3/2)" << endl << endl;

    // TEST (+=, -=, *=, /=) 
    cout << "--- TEST (+=, -=, *=, /=) ---" << endl;
    rational<int> c(1, 2);
    cout << "Valore iniziale c: " << c << endl;
    c += rational<int>(1, 2); 
    cout << "c += 1/2   -> " << c << " (atteso: 1)" << endl;
    c -= rational<int>(1, 4); 
    cout << "c -= 1/4   -> " << c << " (atteso: 3/4)" << endl;
    c *= rational<int>(2, 3); 
    cout << "c *= 2/3   -> " << c << " (atteso: 1/2)" << endl;
    c /= rational<int>(1, 2); 
    cout << "c /= 1/2   -> " << c << " (atteso: 1)" << endl;
    rational<int> d(1, 3);
    (d += rational<int>(2, 5)) *= rational<int>(5, 2);
    cout << "(1/3 + 2/5) * 5/2 -> " << d << " (atteso: 11/6)" << endl;
    rational<int> e(1, 2);
    e /= rational<int>(0, 1); 
    cout << "1/2 /= 0   -> " << e << " (atteso: Inf)" << endl << endl;

    // TEST (INF, -INF, NaN) 
	
    rational<int> inf(1, 0);
    rational<int> m_inf(-1, 0);
    rational<int> nan(0, 0);
    rational<int> zero(0, 1);

    cout << "--- TEST (INF, -INF, NaN) ---" << endl;
    cout << "Infinito:      " << inf   << endl;
    cout << "Meno Infinito: " << m_inf << endl;
    cout << "NaN (0/0):     " << nan   << endl;
    
    cout << "1/2 + Inf      = " << (a + inf)     << " (atteso: Inf)" << endl;
    cout << "Inf + (-Inf)   = " << (inf + m_inf) << " (atteso: NaN)" << endl;
    cout << "Inf * 0        = " << (inf * zero)  << " (atteso: NaN)" << endl;
    cout << "Inf * Inf      = " << (inf * inf)   << " (atteso: Inf)" << endl;
    cout << "Inf / Inf      = " << (inf / inf)   << " (atteso: NaN)" << endl;
    cout << "1/2 / 0        = " << (a / zero)    << " (atteso: Inf)" << endl << endl;

    return 0;
}