#include <fstream>
#include "funkcje.h"

using namespace std;


bool stworzTablice(Tablica* t, int dlugosc)
{
    t->dlugosc = dlugosc;
    if (t->dlugosc == 0)
    {
        t->tab = nullptr;
        return true;
    }
    
    t->tab = new short[dlugosc];
    if (t->tab == nullptr)
    {
        t->dlugosc = 0;
        return false;
    }
    return true;
}
void skasujTablice(Tablica* t)
{
    t->dlugosc = 0;
    delete[] t->tab;
    t->tab = nullptr;
}

void zapisz(Tablica* t, const char* nazwaPliku)
{
    ofstream plik(nazwaPliku);
    plik << t->dlugosc << " ";
    for (int i = 0; i < t->dlugosc; i++)
    {
        plik << t->tab[i] << " ";
    }
    plik << endl;
    plik.close();
}

bool wczytaj(Tablica* t, const char* nazwaPliku)
{
    ifstream plik(nazwaPliku);
    if (!plik.good())
    {
        return false;
    }
    
    int dlugosc;
    plik >> dlugosc;
    
    if (t->dlugosc != dlugosc)
    {
        if (t->dlugosc > 0)
        {
            skasujTablice(t);
        }
        if (!stworzTablice(t, dlugosc))
        {
            return false;
        }
    }
    
    for (int i = 0; i < t->dlugosc; i++)
    {
        plik >> t->tab[i];
    }

    plik.close();
    return true;
}