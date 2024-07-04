#pragma once

struct Tablica
{
    short* tab;
    int dlugosc;
};


bool stworzTablice(Tablica* t, int dlugosc);

void skasujTablice(Tablica* t);

void zapisz(Tablica* t, const char* nazwaPliku);

bool wczytaj(Tablica* t, const char* nazwaPliku);
