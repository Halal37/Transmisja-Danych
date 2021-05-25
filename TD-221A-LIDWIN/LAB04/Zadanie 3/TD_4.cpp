// TD_4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <cmath>
#include <complex>
#include <fstream>
#include <valarray>

using namespace std;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
double pi = 3.141592653589793238462643383279502884197169;
void liczenie_dft(double* tablica);

void fft(CArray& x);
int main()
{
    double fs = 8000;
    double Ts = 1 / fs;
    double Tc = 1;
    int N = Tc / Ts;
    double f = 450, fi = 0;

    double* t = new double[N];
    double* g = new double[N];
    double* c = new double[N];
    double* fk = new double[N / 2];
    complex<double>* d = new complex<double>[N];
    double* d_rel = new double[N / 2];
    double* d_img = new double[N / 2];
    double* M = new double[N / 2];
    double* M_prim = new double[N / 2];;
    complex<double> potega;
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    ofstream czas("czas.txt");

    for (int n = 0; n < N; n++) {
        t[n] = n / fs;
        c[n] = sin(2 * pi * f * t[n] * cos(3 * pi * t[n]) + t[n] * fi);
    }
    double* y = new double[N];
    double* z = new double[N];
    double* v = new double[N];
    double* pp = new double[N];
    double* u = new double[N];
    for (int n = 0; n < N; n++) {
        float temp_sin = pow(t[n], 2);
        float temp_cos = cos(c[n]) + 2;
        y[n] = abs((pow(c[n], 2) / temp_cos) * sin(4 * temp_sin) - 0.12);
    }
    for (int n = 0; n < N; n++) {
        z[n] = c[n] * (sqrt(abs(c[n] + y[n])) - cos(10 * c[n] * y[n]));
    }
    for (int n = 0; n < N; n++) {
        v[n] = 0.5 * z[n] * cos(6 * y[n] * pi * t[n]) - t[n] * sin(2 * pi * t[n]);
    }

    for (int n = 0; n < N; n++) {
        t[n] = n / (fs / 8);
        if (n < 1800) {
            g[n] = -t[n] / 2 * sin(20 * pow(t[n], 3) - 18 * pow(t[n], 2));
        }
        else if (n < 3000) {
            g[n] = cos(5 * pi * t[n]) * sin(12 * pi * pow(t[n], 2));
        }
        else if (n < 4500) {
            g[n] = ((t[n] - 3) / 3) * sin((12 - t[n]) * pi * pow(t[n], 2));
        }
        else {
            break;
        }
    }
    for (int n = 0; n < N; n++) {
        pp[n] = 0;
        for (int h = 1; h <= 5; h++) {
            pp[n] = (cos(4 * pi * h * t[n]) / (4 * h * sin(8 * pi * h * t[n]) + 2)
                ) + pp[n];
        }
    }
    for (int n = 0; n < N; n++) {
        u[n] = 0;
        for (int h = 1; h <= 50; h++) {
            u[n] = (cos(4 * pi * h * t[n]) / (4 * h * sin(8 * pi * h * t[n]) + 2)
                ) + u[n];
        }
    }
  
    complex<double>* f_com = new complex<double>[N];
    double sum_fft=0;
    double sum_dft = 0;






    for (int j = 0; j < N; j++) {
        f_com[j] = complex<double>(c[j], 0);
    }
    CArray data6(f_com, N);
    clock_t t1 = clock();
    liczenie_dft(c);
    clock_t t2 = clock();
    double dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas DFT c: " << dft_time << endl;
    sum_dft += dft_time;
    t1 = clock();
    fft(data6);
    t2 = clock();
    double fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas FFT c: " << fft_time << endl;
    sum_fft += fft_time;



    for (int j = 0; j < N; j++) {
        f_com[j] = complex<double>(y[j], 0);
    }
    CArray data5(f_com, N);
    t1 = clock();
    liczenie_dft(y);
    t2 = clock();
    dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas DFT y: " << dft_time << endl;
    sum_dft += dft_time;
    t1 = clock();
    fft(data5);
    t2 = clock();
    fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas FFT y: " << fft_time << endl;
    sum_fft += fft_time;



    for (int j = 0; j < N; j++) {
        f_com[j] = complex<double>(z[j], 0);
    }
    CArray data(f_com, N);
    t1 = clock();
    liczenie_dft(z);
    t2 = clock();
    dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas DFT z: " << dft_time << endl;
    sum_dft += dft_time;
    t1 = clock();
    fft(data);
    t2 = clock();
    fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas FFT z: " << fft_time << endl;
    sum_fft += fft_time;



    for (int j = 0; j < N; j++) {
        f_com[j] = complex<double>(v[j], 0);
    }
    CArray data1 (f_com, N);
    t1 = clock();
    liczenie_dft(v);
    t2 = clock();
    dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas DFT v: " << dft_time << endl;
    sum_dft += dft_time;
    t1 = clock();
    fft(data1);
    t2 = clock();
    fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas FFT v: " << fft_time << endl;
    sum_fft += fft_time;



    for (int j = 0; j < N; j++) {
        f_com[j] = complex<double>(g[j], 0);
    }
    CArray data2(f_com, N);
    t1 = clock();
    liczenie_dft(g);
    t2 = clock();
    dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas DFT g: " << dft_time << endl;
    sum_dft += dft_time;
    t1 = clock();
    fft(data2);
    t2 = clock();
    fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas FFT g: " << fft_time << endl;
    sum_fft += fft_time;




    for (int j = 0; j < N; j++) {
        f_com[j] = complex<double>(pp[j], 0);
    }
    CArray data3(f_com, N);
    t1 = clock();
    liczenie_dft(pp);
    t2 = clock();
    dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas DFT pp: " << dft_time << endl;
    sum_dft += dft_time;
    t1 = clock();
    fft(data3);
    t2 = clock();
    fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas FFT pp: " << fft_time << endl;
    sum_fft += fft_time;




    for (int j = 0; j < N; j++) {
        f_com[j] = complex<double>(u[j], 0);
    }
    CArray data4(f_com, N);
    t1 = clock();
    liczenie_dft(u);
    t2 = clock();
    dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas DFT u: " << dft_time << endl;
    sum_dft += dft_time;
    t1 = clock();
    fft(data4);
    t2 = clock();
    fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
    czas << "Czas FFT u: " << fft_time << endl;
    sum_fft += fft_time;



    czas << "Suma DFT: "<<sum_dft << endl;
    czas << "Suma FFT: "<<sum_fft << endl;
    return 0;
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

void liczenie_dft(double* tablica)
{
    double fs = 8000;
    double Ts = 1 / fs;
    double Tc = 1;
    int N = Tc / Ts;
    double f = 450, fi = 0;
    double* t = new double[N];
    double* c = new double[N];
    double* fk = new double[N / 2];
    complex<double>* d = new complex<double>[N];
    double* d_rel = new double[N / 2];
    double* d_img = new double[N / 2];
    double* M = new double[N / 2];
    double* M_prim = new double[N / 2];
    complex<double> potega;
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    for (int j = 0; j < N; j++) {
        complex<double> sum = 0;
        double do_potegi = -pi * 2.0;

        for (int k = 0; k < N; k++) {
            potega = cos((do_potegi * j * k) / N) + complex <double>(0.0, 1.0) * sin((do_potegi * j * k) / N);
            auto test = tablica[k] * potega;
            sum += test;
        }
        d[j] = sum;
        dane << t[j] << ";" << d[j].real() << ";" << endl;
        dane1 << t[j] << ";" << d[j].imag() << ";" << endl;
    }


    for (int j = 0; j < N / 2; j++) {
        M[j] = sqrt(pow(d[j].real(), 2) + pow(d[j].imag(), 2)) * 2 / N;
        dane2 << j << ";" << M[j] << ";" << endl;
    }
    for (int j = 0; j < N / 2; j++) {
        M_prim[j] = 10 * log10(M[j]);
    }
    for (int j = 0; j < N / 2; j++) {
        fk[j] = int(j * fs / N);
    }

    for (int j = 0; j < N / 2; j++) {
        dane3 << fk[j] << ";" << M_prim[j] << ";" << endl;
    }
}

void fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;

    CArray even = x[std::slice(0, N / 2, 2)];
    CArray  odd = x[std::slice(1, N / 2, 2)];

    fft(even);
    fft(odd);

    for (size_t k = 0; k < N / 2; ++k)
    {
        Complex t = polar(1.0, -2 * pi * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }
}