// TD5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double pi = 3.141592653589793238462643383279502884197169;
int main()
{
    
   
    double Tc = 0.02;
    double fm = 100;
    double fn = 300;
    double fs = 100000;
    double Ts = 1 / fs;
    double ka = 1;
    double kp = 1;
    double kf = fm/2;
    int N = Tc / Ts;
    double* t = new double[N];
    double* c = new double[N];
    double* z = new double[N];
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        c[n] = sin(2 * pi * fm * t[n]);
        dane << t[n] << ";" << c[n] << ";" << endl;
    }
    //Test   ka = 0.5; kp = 1; kf = 170;
    //A) ka=0.5; kp=0.5; kf=0.5;
   // ka = 0.5; kp = 0.075; kf = 0.025;
    //B) ka=6; kp=0.5*pi; kf=0.2*pi;
   // ka = 6; kp = 0.5 * pi; kf = 0.2 * pi;
    //C) ka = 70; kp = 4 * pi; kf = 18 * pi;
    ka = 70; kp = 4 * pi; kf = 18 * pi;
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        z[n] = (ka*(c[n]+1))*cos(2 * pi * fn * t[n]);
        dane1 << t[n] << ";" << z[n] << ";" << endl;
    }
    double* z1 = new double[N];
    double* z2 = new double[N];
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
          z1[n] = cos(2 * pi * fn * t[n]+c[n]*kp);
         dane2 << t[n] << ";" << z1[n] << ";" << endl;
    }
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        z2[n] = cos(2 * pi * fn * t[n] + c[n] * kf/fm);
         dane3 << t[n] << ";" << z2[n] << ";" << endl;
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
