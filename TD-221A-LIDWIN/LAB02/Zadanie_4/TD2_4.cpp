// TD2_4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <math.h>
#include <fstream>
const double pi = acos(-1);
using namespace std;

int main()
{
    float fs = 22050;
    float Ts = 1 / fs;
    float Tc = 1;
    int N = Tc / Ts;
    float f = 1, fi = 0;
    float* s = new float[N]; float* t = new float[N];
    ofstream dane("dane5.txt");
    ofstream dane1("dane6.txt");
    ofstream dane2("dane7.txt");
    float* y = new float[N];
    float* z = new float[N];
    for (int n = 0; n < N; n++) {
        t[n] = n / fs ;
        s[n] = 0;
        for (int h = 1; h <= 1; h++) {
            s[n]=(cos(4*pi*h*t[n])/(4*h*sin(8*pi*h*t[n])+2)
               )+ s[n];
        }
        dane << t[n] << ";" << s[n] << ";" << std::endl;
    }
    for (int n = 0; n < N; n++) {
        y[n] = 0;
        for (int h = 1; h <= 5; h++) {
            y[n] = (cos(4 * pi * h * t[n]) / (4 * h * sin(8 * pi * h * t[n]) + 2)
                ) + y[n];
        }
        dane1 << t[n] << ";" << y[n] << ";" << std::endl;
    }
    for (int n = 0; n < N; n++) {
        z[n] = 0;
        for (int h = 1; h <= 50; h++) {
            z[n] = (cos(4 * pi * h * t[n]) / (4 * h * sin(8 * pi * h * t[n]) + 2)
                ) + z[n];
        }
        dane2 << t[n] << ";" << z[n] << ";" << std::endl;
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
