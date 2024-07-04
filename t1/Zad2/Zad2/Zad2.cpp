#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

short* alokujTablice(int rozmiar, int numer)
{
    short* tab = new short[rozmiar + 1];
    rozmiar = rozmiar << 8;
    tab[0] = rozmiar + numer;
    tab++;
    return tab;
}
void skasujTablice(short* tab)
{
    tab--;
    delete[] tab;
}

void zapisz(const char* nazwaPliku, short* tab)
{
    int metadane = *(tab - 1);
    int rozmiar = metadane >> 8;
    FILE* plik = fopen(nazwaPliku, "w");
    
    fwrite(&metadane, sizeof(short), 1, plik);
    fwrite(tab, sizeof(short), rozmiar, plik);
    fclose(plik);
}

short* odczyt(const char* nazwaPliku)
{
    FILE* plik = fopen(nazwaPliku, "r+b");
    short metadane;
    fread(&metadane, sizeof(short), 1, plik);
    int numer = metadane & 0x00ff;
    int rozmiar = metadane >> 8;
    
    short* tab = alokujTablice(rozmiar, numer);
    fread(tab, sizeof(short), rozmiar, plik);
    fclose(plik);
    return tab;
}

void wypisz(short* tab)
{
    int metadane = *(tab - 1);
    int numer = metadane & 0x00ff;
    int rozmiar = metadane >> 8;
   
    printf("rozmiar: %d, numer: %d\n", rozmiar, numer);
    for (int i = 0; i < rozmiar; i++)
    {
        short x = tab[i];
        printf("%d ", (int)tab[i]);
    }
}

int main(const char* nazwaPliku)
{
    printf("podaj wielkosc tablicy:");
    int wielkosc;
    cin >> wielkosc;
    short* tab = alokujTablice(wielkosc, 1);
    for (int i = 0; i < wielkosc; i++)
    {
        cout << "podaj " << i + 1 << " liczbe:";
        cin >> tab[i];
    }
    wypisz(tab);
    zapisz("test.txt", tab);
    short* tab2 = odczyt("test.txt");
    cout << "zapisano do pliku" << endl;
    cout << "tablica po odczytaniu z pliku:" << endl;

    wypisz(tab2);

    skasujTablice(tab);
    skasujTablice(tab2);


} 

