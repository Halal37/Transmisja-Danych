// TD_3_2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>

using namespace std;
double pi = 3.141592653589793238462643383279502884197169;
int main()
{
    double fs = 1000, Ts = 1 / fs, Tc = 1;
    int N = Tc / Ts;
    double* s = new double[N];
    double* b = new double[N];
    double* c = new double[N];
    double* fk = new double[N/2];
    complex<double>* d = new complex<double>[N];
    double* d_rel = new double[N/2];
    double* d_img = new double[N/2];
    double* M = new double[N/2];
    double* M_prim = new double[N/2];
    double* t = new double[N];
    complex<double> potega;
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    double A = 1, f = 25, fi = 0;
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        s[n] = (A)*sin(((pi * 2 * f) * t[n] + fi));
    }
    double A2 = 0.5, f2 = 66, fi2 = 0;
    for (int n = 0; n < N; n++) {
        b[n] = (A2)*sin(((pi * 2 * f2) * t[n] + fi2));
    }
    for (int n = 0; n < N; n++) {
        c[n] = s[n] + b[n];
    }
    for (int j = 0; j < N; j++) {
        complex<double> sum=0;
        double do_potegi = -pi * 2.0;

        for (int k = 0; k < N; k++) {
            potega = cos((do_potegi * j * k) / N) + complex <double> (0.0, 1.0)* sin((do_potegi * j * k) / N);
            auto test = c[k] * potega;
            sum += test;
        }
        d[j] = sum;
        dane << t[j] << ";" << d[j].real() << ";" << endl;
        dane1 << t[j] << ";" << d[j].imag() << ";" << endl;
    }
 

    for (int j = 0; j < N/2; j++) {
        M[j] = sqrt(pow(d[j].real(),2)+pow(d[j].imag(),2))*2/N;
        dane2 << j << ";" << M[j] << ";" << endl;
    }
    for (int j = 0; j < N/2; j++) {
        M_prim[j] = 10 * log10(M[j]);
    }
    for (int j = 0; j < N/2; j++) {
        fk[j] = int(j*fs/N);
    }

   for (int j = 0; j < N/2; j++) {
        dane3 << fk[j] << ";" << M_prim[j] << ";" << endl;
    }
}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
