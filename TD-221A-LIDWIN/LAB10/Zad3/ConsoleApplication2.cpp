// ConsoleApplication2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
        input += bin;

    }
    int* arr = new int[input.size()];
    for (int i = 0; i < input.size(); i++)
    {
        arr[i] = input[i] - '0';
    }
    return arr;
}

void funkcja_na_bit(float*c,float prog) {
    string napis = "AB";

    int* b = new int[napis.length() * 7];
    b = s2bs(napis);
    int B = napis.length() * 7;
    float fs = 100000;
    float Ts = 1 / fs;
    float Tb = 1.0 / 7.0;
    float Tc = B * Tb;
    float N = ceil(Tc / Ts);
    float* tk = new float[N];
    float* sb = new float[N];
    int n = 0;
    float TMP_TB = 0;
    float suma = 0;
    int *wynik=new int[napis.length() * 7];
    for (int i = 0; i < N; i++) {
        TMP_TB = TMP_TB + Ts;
        suma = suma + c[i];
        if (TMP_TB >= Tb) {           
            
            if (suma / 14 >= prog) {
                wynik[n] = 1;
            }
            else {
                wynik[n] = 0;
            }
            n++;
            TMP_TB = 0;
            
            suma = 0;
        }
        sb[i] = b[n];
    }
    if (suma / 14 >= prog) {
        wynik[n] = 1;
    }
    else {
        wynik[n] = 0;
    }
    n++;
    for (int i = 0; i < (napis.length() * 7); i++) {
        cout << wynik[i];
    }
}
int main()
{
    string napis = "AB";

    int* b = new int[napis.length() * 7];
    b = s2bs(napis);
    int B = napis.length() * 7;
    float Tb = 1.0 / 7.0;
    float Tc = B * Tb;
    float fs = 100000;
    float Ts = 1 / fs;
    float N = ceil(Tc / Ts);
    float* sb = new float[N];
    float* tk = new float[N];
    float* za = new float[N];
    float* zp = new float[N];
    float* zf = new float[N];
    cout << "Oryginal" << endl;
    for (int i = 0; i < (napis.length() * 7); i++) {
        cout << b[i];
    }
    ofstream dane("dane.txt");
    ofstream dane1("dane1.txt");
    ofstream dane2("dane2.txt");
    ofstream dane3("dane3.txt");
    ofstream dane4("dane4.txt");
    ofstream dane5("dane5.txt");
    ofstream dane6("dane6.txt");
    ofstream dane7("dane7.txt");
    ofstream d_pa("d_pa.txt");
    ofstream d_ca("d_ca.txt");
    ofstream d_pp("d_pp.txt");
    ofstream d_cp("d_cp.txt");
    ofstream d_pf("d_pf.txt");
    ofstream d_pf1("d_pf1.txt");
    ofstream d_pf2("d_pf2.txt");
    ofstream d_cf("d_cf.txt");

    float TMP_TB = 0;
    int n = 0;
    float A1 = 1.5;
    float A2 = 2.0;
    float W = 2.0;
    float fn1 = (W + 1.0) / Tb;
    float fn2 = (W + 2.0) / Tb;
    float fn = 14.0;// W * (1 / Tb);

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

    for (int t = 0; t < N; t++) {
        if (sb[t] == 0) {
            za[t] = A1 * sin(2.0 * pi * fn * tk[t]);
        }
        else {
            za[t] = A2 * sin(2.0 * pi * fn * tk[t]);
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
            zf[t] = sin(2.0 * pi * fn2 * tk[t]);
        }
        dane3 << tk[t] << ";" << zf[t] << ";" << endl;
    }


    float* xa = new float[N];
    float A_x = 2.0;
    for (int t = 0; t < N; t++) {
        xa[t] = za[t] * A_x * sin(2.0 * pi * fn * tk[t]);

        dane4 << tk[t] << ";" << xa[t] << ";" << endl;
    }
    float* pa = new float[N];
    float* ca = new float[N];
    float pom = 0.0;
    float pa_pom = 0.0;
    int h = 23000;
    for (int t = 0; t < N; t++) {
        pom = pom + Ts;
        pa_pom = pa_pom + xa[t];
        if (pom >= Tb) {
            pom = 0.0;
            pa_pom = 0.0;
        }
        pa[t] = pa_pom;
        d_pa<< tk[t] << ";" << pa[t] << ";" << endl;
    }
    for (int t = 0; t < N; t++) {
        if (pa[t] > h) {
            ca[t] = 1;
        }
        else {
            ca[t] = 0;
        }
        d_ca << tk[t] << ";" << ca[t] << ";" << endl;
    }

    float* xp = new float[N];
    float P_x = 2.0;
    for (int t = 0; t < N; t++) {
        xp[t] = zp[t] * P_x * sin(2.0 * pi * fn * tk[t]);

        dane5 << tk[t] << ";" << xp[t] << ";" << endl;
    }
    float* pp = new float[N];
    float* cp = new float[N];
    float pom_p = 0.0;
    float pp_pom = 0.0;
    for (int t = 0; t < N; t++) {
        pom_p = pom_p + Ts;
        pp_pom = pp_pom + xp[t];
        if (pom_p >= Tb) {
            pom_p = 0.0;
            pp_pom = 0.0;
        }
        pp[t] = pp_pom;
        d_pp << tk[t] << ";" << pp[t] << ";" << endl;
    }

    for (int t = 0; t < N; t++) {
        if (pp[t] < 0) {
            cp[t] = 1;
        }
        else {
            cp[t] = 0;
        }
        d_cp << tk[t] << ";" << cp[t] << ";" << endl;
    }



    float* xf1 = new float[N];
    float F1_x = 2.0;
    for (int t = 0; t < N; t++) {
        xf1[t] = zf[t] * F1_x * sin(2.0 * pi * fn1 * tk[t]);

        dane6 << tk[t] << ";" << xp[t] << ";" << endl;
    }
    float* pf = new float[N];
    float* pf1 = new float[N];
    float* cf = new float[N];
    float pom_f = 0.0;
    float pf_pom = 0.0;
    for (int t = 0; t < N; t++) {
        pom_f = pom_f + Ts;
        pf_pom = pf_pom + xf1[t];
        if (pom_f >= Tb) {
            pom_f = 0.0;
            pf_pom = 0.0;
        }
        pf1[t] = pf_pom;
        d_pf1 << tk[t] << ";" << pf1[t] << ";" << endl;
    }




    float* xf2 = new float[N];
    float F2_x = 2.0;
    for (int t = 0; t < N; t++) {
        xf2[t] = zf[t] * F2_x * sin(2.0 * pi * fn2 * tk[t]);

        dane7 << tk[t] << ";" << xf2[t] << ";" << endl;
    }
    float* pf2 = new float[N];
    float pom_f2 = 0.0;
    float pf2_pom = 0.0;
    for (int t = 0; t < N; t++) {
        pom_f2 = pom_f2 + Ts;
        pf2_pom = pf2_pom + xf2[t];
        if (pom_f2 >= Tb) {
            pom_f2 = 0.0;
            pf2_pom = 0.0;
        }
        pf2[t] = pf2_pom;
        d_pf2 << tk[t] << ";" << pf2[t] << ";" << endl;
    }

    for (int t = 0; t < N; t++) {
        pf[t] = -1*pf1[t]+pf2[t];
        d_pf << tk[t] << ";" << pf[t] << ";" << endl;
    }


    for (int t = 0; t < N; t++) {
        if (pf[t] > 0) {
            cf[t] = 1;
        }
        else {
            cf[t] = 0;
        }
        d_cf << tk[t] << ";" << cf[t] << ";" << endl;
    }
    cout << endl;
    cout << "c(t)_a_bit" << endl;
    funkcja_na_bit(ca, 165.0);
    cout << endl;
    cout << "c(t)_p_bit" << endl;
    funkcja_na_bit(cp, 165.0);
    cout << endl;
    cout << "c(t)_f_bit" << endl;
    funkcja_na_bit(cf, 165.0);
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
