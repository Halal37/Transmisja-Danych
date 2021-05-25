// TD_3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>
using namespace std;
const double pi = acos(-1);
complex<float>* dft(complex<float>* tablica, int N);
int main()
{
    float fs = 1000, Ts = 1 / fs, Tc = 1;
    int N = Tc / Ts; 
    float* s = new float[N];
    float* b = new float[N];
    float* c = new float[N];
    complex<float>* d = new complex<float>[N];
    float*t = new float[N];
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    float A = 1, f = 25, fi = 0;
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        s[n] = (A) * sin(((pi * 2 * f) * t[n] + fi));
        dane << t[n] << ";" << s[n] << ";" << std::endl;
    }
    float A2 = 0.5, f2 = 66, fi2 = 0;
    for (int n = 0; n < N; n++) {
        b[n] = (A2) * sin(((pi * 2 * f2) * t[n] + fi2));
        dane2 << t[n] << ";" << b[n] << ";" << std::endl;
    }
    for (int n = 0; n < N; n++) {
        c[n] = s[n]+b[n];
        dane3 << t[n] << ";" << c[n] << ";" << std::endl;
    }

    for (int n = 0; n < N; n++) {
        d[n] = complex<float>(c[n]);
    }
    complex<float>* cDFT = dft(d, N);
    for (int j = 0; j < N; j++) {
        dane1<<t[j] << ";" << cDFT[j].real() << ";" << cDFT[j].imag()<<";" <<endl;
    }
}

complex<float>* dft(complex<float>* tablica, int N)
{
    double do_potegi = -pi * 2.0;
    complex<float>* wynik = new complex<float>[N];
    for (int j = 0; j < N; j++) {
        complex<float> sum(0, 0);
        for (int k = 0; k < N; k++) {
            sum += tablica[k] * exp(complex<float>(0.0, (float)(do_potegi * k * j / N)));
        }
        wynik[j] = sum;
    }
    return wynik;
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
