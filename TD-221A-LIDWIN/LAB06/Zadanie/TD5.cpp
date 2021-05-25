// TD5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>

using namespace std;
float pi = 3.141592653589793238462643383279502884197169;
void liczenie_dft(float* tablica);
int main()
{
    
   
    float Tc = 0.02;
    float fm = 100;
    float fn = 3000;
    float fs = 100000;
    float Ts = 1 / fs;
    float ka = 8;
    float kp = 0.3;
    float kf = 0.3;
    int N = Tc / Ts;
    float* t = new float[N];
    float* c = new float[N];
    float* z = new float[N];
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    for (int n = 0; n < N; n++) {
        t[n] = n * Ts; 
        c[n] = sin(2.0 * M_PI * fm * t[n]);
        dane << t[n] << ";" << c[n] << ";" << endl;
    }
    //Test   ka = 0.5; kp = 1; kf = 170;
    //A) ka=0.5; kp=0.5; kf=0.5;
    ka = 0.5; kp = 0.075; kf = 0.025;
    //B) ka=6; kp=0.5*pi; kf=0.2*pi;
  //  ka = 8; kp = pi/2.0; kf = pi/2.0;
    //C) ka = 70; kp = 4 * pi; kf = 18 * pi;
   // ka = 70; kp = 4 * pi; kf = 18 * pi;
    for (int n = 0; n < N; n++) {
        z[n] = (ka*(c[n]+1))*cos(2 * M_PI * fn * t[n]);
        dane1 << t[n] << ";" << z[n] << ";" << endl;
    }
    float* z1 = new float[N];
    float* z2 = new float[N];
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
          z1[n] = cos(2 * pi * fn * t[n]+c[n]*kp);
         dane2 << t[n] << ";" << z1[n] << ";" << endl;
    }
    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        z2[n] = cos(2 * pi * fn * t[n] + kf/fm*c[n] );
         dane3 << t[n] << ";" << z2[n] << ";" << endl;
    }
   liczenie_dft(z);
 // liczenie_dft(z1);
 //  liczenie_dft(z2);
   

 
}

void liczenie_dft(float* tablica)
{
    float Tc = 0.02;
    float fm = 100;
    float fn = 3000;
    float fs = 100000;
    float Ts = 1 / fs;
    float ka = 0.1;
    float kp = 0.3;
    float kf = 0.3;
    int N = Tc / Ts;

    float* t = new float[N];
    float* c = new float[N];
    float* fk = new float[N / 2];
    complex<float>* d = new complex<float>[N];
    float* d_rel = new float[N / 2];
    float* d_img = new float[N / 2];
    float* M = new float[N / 2];
    float* M_prim = new float[N / 2];
    complex<float> potega;
    ofstream dane("dane9.txt");
    ofstream dane1("dane10.txt");
    ofstream dane2("dane11.txt");
    ofstream dane3("dane12.txt");
    for (int j = 0; j < N; j++) {
        complex<float> sum = 0;
        float do_potegi = -pi * 2.0;

        for (int k = 0; k < N; k++) {
            potega = cos((do_potegi * j * k) / N) + complex <float>(0.0, 1.0) * sin((do_potegi *j * k) / N);
            auto test = tablica[k] * potega;
            sum += test;
        }
        d[j] = sum;
        dane << t[j] << ";" << d[j].real() << ";" << endl;
        dane1 << t[j] << ";" << d[j].imag() << ";" << endl;
    }


    for (int j = 0; j < N / 2; j++) {
        M[j] = sqrt(pow(d[j].real(), 2) + pow(d[j].imag(), 2));
        dane2 << j << ";" << M[j] << ";" << endl;
    }
    for (int j = 0; j < N / 2; j++) {
        M_prim[j] = 10 * log10(M[j]);
    }
    for (int j = 0; j < N / 16; j++) {
        fk[j] = j * fs/N;
    }

    for (int j = 0; j < N/16; j++) {
        dane3 << fk[j] << ";" << M_prim[j] << ";" << endl;
    }
    float max = M_prim[0];
    int max_int = 0;
   for (int i = 1; i < N / 16; i++) {
       if (M_prim[i] > max) {
           max = M_prim[i];
           max_int = i;
       }
   }
   cout << "Maks: " << max << " max_int: " << max_int << endl;
   int f_min;
   int f_max;
   int x = 3;
   // int x=6;
   //int x=12;
   for (int i = max_int; i < (N / 16) - max_int; i += 2) {
       if (M_prim[i] < (max - x)) {
           f_max = i - 1;
           break;          
       }
       else {
           f_max = i;
       }
   }


   for (int i = max_int; i > 0; i -= 2) {
       if (M_prim[i] < (max - x)) {
           f_min = i + 1;
           break;
       }
       else {
           f_min = i;
       }
   }

   cout << "FKMAX: " << fk[f_max] << " FKMin: "<< fk[f_min] << endl;
   cout << x << "dB " << fk[f_max] - fk[f_min] << endl;
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
