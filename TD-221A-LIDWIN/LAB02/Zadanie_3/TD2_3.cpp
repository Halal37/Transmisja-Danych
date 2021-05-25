// TD2_3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
    float f = 1, fi = 0;
    float* s = new float[N]; float* t = new float[N];
    ofstream dane("dane4.txt");

    for (int n = 0; n < N; n++) {
        t[n] = n / (fs/8);
        if (n < 1800) {
            s[n] = -t[n] / 2 * sin(20*pow(t[n],3)-18*pow(t[n],2));
            dane << t[n] << ";" << s[n] << ";" << std::endl;
        }
        else if (n < 3000) {
            s[n] = cos(5 * pi * t[n]) * sin(12 * pi * pow(t[n], 2));
            dane << t[n] << ";" << s[n] << ";" << std::endl;
        }
        else if (n < 4500) {
            s[n] = ((t[n] - 3) / 3) * sin((12-t[n])*pi*pow(t[n],2));
            dane << t[n] << ";" << s[n] << ";" << std::endl;
}
        else {
            break;
        }
      //  t[n] = n / fs;
    //    s[n] = sin(2 * pi * f * t[n] * cos(3 * pi * t[n]) + t[n] * fi);
   //     dane << t[n] << ";" << s[n] << ";" << std::endl;
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
