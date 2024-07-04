#include <iostream>
#include "funkcje.h"

using namespace std;

int main()
{
	Tablica t;
	cout << "podaj ilosc elementow:";
	int dlugosc;
	cin >> dlugosc;
	stworzTablice(&t, dlugosc);
	cout << "podaj elementy:";
	for (int i = 0; i < t.dlugosc; i++)
	{
		cin >> t.tab[i];
	}

	cout << "zapis do pliku" << endl;
	zapisz(&t, "test.txt");

	Tablica t2;
	stworzTablice(&t2, 0);
	wczytaj(&t2, "test.txt");

	cout << "elementy odczytanej tablicy 2: ";
	for (int i = 0; i < t.dlugosc; i++)
	{
		cout << t2.tab[i] << " ";
	}
	cout << endl;


	skasujTablice(&t);
	skasujTablice(&t2);
}
