#include <iostream>
#include <vector>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct uczen
{
        string imie, pesel, adres, nazwisko;
        int numer;
};

class klasa
{
                vector <struct uczen> spis;
       
        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
            void wczytajZPliku(const char *);                
};

void klasa::wprowadz()
{
        int iloscUczniow;
        struct uczen wprowadzany;
        cout << "Ilosc Uczniow: ";
        cin  >> iloscUczniow;
        for (int i=0; i<iloscUczniow; i++)
        {
                cout << "Nr Pesel Adres Imie Nazwisko: ";
                cin>> wprowadzany.numer
                		>> wprowadzany.pesel
                        >> wprowadzany.adres
                        >> wprowadzany.imie
                        >> wprowadzany.nazwisko;
                spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
        }
}


void klasa::wypisz()
{
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
        	cout << it->numer << " "
        	             << it->pesel << " "
                         << it->adres << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
              //B³¹d w JSONIE expected primary expression before ':' token 
			  // cout ; {"numer";:["14","12"],"pesel":["2122121"],"adres":"Kepno","imie":"Mikolaj","Nazwisko":"Kaczmarek"}
        }
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik << it->numer<< " "
                         << it->pesel << " "
                         << it->adres << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        }
        plik.close();  
}
void klasa::wczytajZPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik << it->numer<< " "
                         << it->pesel << " "
                         << it->adres << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        }
        plik.close();  
}


int main(int argc, char** argv) {
        klasa TI;
        TI.wprowadz();
        TI.wypisz();
        TI.zapiszDoPliku("c:\\do.JSON");
        TI.wczytajZPliku("c:\\od.JSON");
        return 0;
}
