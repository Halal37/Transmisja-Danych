// TD_7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include<cmath>
#include <fstream>



using namespace std;
float pi = 3.141592653589793238462643383279502884197169;

int* s2bs(string s) {
    int n = s.length();
    string input = "";
    for (int i = 0; i <= n; i++) {
        int val = int(s[i]);

        string bin = "";
        while (val > 0) {
            (val % 2) ? bin.push_back('1') : bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
         input+= bin;

    }
    int* arr = new int[input.size()];
    for (int i = 0; i < input.size(); i++)
    {
        arr[i] = input[i] - '0';
    }
    return arr;
}
int main()
{
    string napis = "AB";

    int* b = new int[napis.length()*7];
    b=s2bs(napis);
    int B= napis.length() * 7;
    float Tb = 1.0/700.0;
    float Tc = B * Tb;
    float fs = 250000;
    float Ts = 1 / fs;
    float N = ceil(Tc / Ts);
    float* sb = new float[N];
    float* tk = new float[N];
    float* za = new float[N];
    float* zp = new float[N];
    float* zf = new float[N];

    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");

    float TMP_TB = 0;
    int n = 0;
    float A1 = 1.5;
    float A2 = 2.0;
    float W = 100.0;
    float fn1 = (W + 1.0) / Tb;
    cout << fn1<<endl;
    float fn2 = (W + 2.0) / Tb;
    cout << fn2 << endl;
    float fn = W*(1/Tb);
    cout << fn << endl;

    for (int i = 0; i < N; i++) {
        tk[i] = i / fs;
        TMP_TB = TMP_TB + Ts;
        if (TMP_TB >= Tb) {
            n++;
            TMP_TB = 0;
        }
        sb[i] = b[n];
        dane << tk[i] << ";" << sb[i] << ";" << endl;

    }
    //float* tk2 = new float[N];
    for (int t = 0; t < N; t++) {
        tk[t] = t * fs/N;
    }

    for (int t = 0; t < N; t++) {
     if(sb[t]==0){
         za[t] = A1*sin(2.0 * pi * fn * tk[t]);
     }
     else {
         za[t] =A2* sin(2.0 * pi * fn * tk[t]);
     }
     dane1 << tk[t] << ";" << za[t] << ";" << endl;
    }

    for (int t = 0; t < N; t++) {
        if (sb[t] == 0) {
            zp[t] = sin(2.0 * pi * fn * tk[t]);
        }
        else {
            zp[t] = sin(2.0 * pi * fn * tk[t] + pi);
        }
        dane2 << tk[t] << ";" << zp[t] << ";" << endl;
    }

    for (int t = 0; t < N; t++) {
        if (sb[t] == 0) {
            zf[t] = sin(2.0 * pi * fn1 * tk[t]);
        }
        else {
            zf[t] =  sin(2.0 * pi * fn2 * tk[t]);
        }
        dane3 << tk[t] << ";" << zf[t] << ";" << endl;
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
