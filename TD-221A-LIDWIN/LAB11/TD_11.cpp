// TD_11.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include<cmath>
#include <fstream>
#include <ctime>

using namespace std;

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
int* kodowanie(int *napis) {
    int* dlug = new int[4];
    for (int i = 0; i < 4; i++) {
        dlug[i]=napis[i];
    }
    int* wynik = new int[7];
    wynik[2] = dlug[0];
    wynik[4] = dlug[1];
    wynik[5] = dlug[2];
    wynik[6] = dlug[3];
    wynik[0] =((((wynik[2]+wynik[4])%2)+wynik[6])%2) ;
    wynik[1] = ((((wynik[2] + wynik[5]) % 2) + wynik[6]) % 2);
    wynik[3] = ((((wynik[4] + wynik[5]) % 2) + wynik[6]) % 2);
    return wynik;
}
int* detekcja_i_korekcja(int* napis) {
    int* pom = new int[3];
    int* dasz = new int[3];
    pom[0] = ((((napis[2] + napis[4]) % 2) + napis[6]) % 2);
    pom[1] = ((((napis[2] + napis[5]) % 2) + napis[6]) % 2);
    pom[2] = ((((napis[4] + napis[5]) % 2) + napis[6]) % 2);
    dasz[0] = (napis[0] + pom[0]) % 2;
    dasz[1] = (napis[1] + pom[1]) % 2;
    dasz[2] = (napis[3] + pom[2]) % 2;

    int S = dasz[0] * pow(2, 0) + dasz[1] * pow(2, 1) + dasz[2] * pow(2, 2);
    cout<<"S to: " << S<<endl;
    if (S == 0) {
        return napis;
    }
    else {
        S = S - 1;
        napis[S] = (napis[S] + 1) % 2;
        return napis;
    }
}
int* spoilbit(int* napis, int zmienna) {
    if (zmienna > 7) {
        int losowa = (rand() % 7) ;
        cout << "Losowa[index] "<<losowa << endl;
        napis[losowa] = (napis[losowa] + 1) % 2;
    }
    else {
        napis[zmienna] = (napis[zmienna] + 1) % 2;
       
    }
    return napis;

}
int main()
{
    srand(time(NULL));
    string napis = "A";

    int* b = new int[napis.length() * 7];
    b = s2bs(napis);
    int B = napis.length() * 7;

    int* test = new int[4];
    test[0] = 1;
    test[1] = 1;
    test[2] = 0;
    test[3] = 1;
    int* test2 = new int[7];
    test2=kodowanie(test);
    int* test3 = new int[7];
    int* blad = new int[7];
    cout <<" Podane bity "<< endl;
    for (int i = 0; i < 4; i++) {
        cout << test[i];
    }
    cout << endl;
    cout<<" Wynik kodowania " << endl;
    for (int i = 0; i < 7; i++) {
        cout << test2[i];
    }
    cout << endl;
    blad=spoilbit(test2, 9);
    cout << " Dane podane " << endl;
    for (int i = 0; i < 7; i++) {
        cout << blad[i];
    }
    cout << endl;
    test3 = detekcja_i_korekcja(blad);
    
    cout<<" Wynik detekcji i korekty " << endl;
    for (int i = 0; i < 7; i++) {
        cout << test3[i];
    }
    cout << endl;
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
