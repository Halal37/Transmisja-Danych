﻿// TD_2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <math.h>
#include <fstream>
const double pi = acos(-1);
using namespace std;
int main()
{
    float fs = 8000;
    float Ts = 1 / fs;
    float Tc = 1;
    int N = Tc / Ts;
    float f = 1,fi=0;
    float* s = new float[N]; float*t = new float[N];
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        s[n] = sin(2 * pi * f * t[n] * cos(3*pi*t[n])+t[n]*fi);
        dane << t[n] << ";" << s[n] << ";" << std::endl;
    }
    float* y = new float[N];
    float* z = new float[N];
    float* v = new float[N];
    for (int n = 0; n < N; n++) {
        float temp_sin = pow(t[n], 2);
        float temp_cos = cos(s[n]) + 2;
        y[n] = abs((pow(s[n],2)/temp_cos)*sin(4* temp_sin)-0.12);
        dane1 << t[n] << ";" << y[n] << ";" << std::endl;
    }
    for (int n = 0; n < N; n++) {
        z[n] =s[n]*(sqrt(abs(s[n]+y[n]))-cos(10*s[n]*y[n]));
        dane2 << t[n] << ";" << z[n] << ";" << std::endl;
    }
    for (int n = 0; n < N; n++) {
        v[n] =0.5*z[n]*cos(6*y[n]*pi*t[n])-t[n]*sin(2*pi*t[n]) ;
        dane3 << t[n] << ";" << v[n] << ";" << std::endl;
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
