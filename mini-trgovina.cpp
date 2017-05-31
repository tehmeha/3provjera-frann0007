#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int brojArtikla = 0;
    int izbor;
    int MAX = 50;
    string artikli[MAX];
    unsigned long long int barkod[MAX];
    float cijena[MAX];
    ofstream datotekaUpisivanje;
    ifstream datotekaUcitavanje;

    while(1)
    {
        cout << "Glavni izbornik" << endl;
        cout << "1. Unos novog artikla" << endl;
        cout << "2. Ispisi sve podatke" << endl;
        cout << "3. Pretraga prema bar kodu artikla" << endl;
        cout << "4. Pretraga prema nazivu artikla" << endl;
        cout << "5. Izmjena podataka prema bar kodu" << endl;
        cout << "6. Ispisi sortirano prema nazivu artikla" << endl;
        cout << "7. Izlaz iz programa" << endl;
        cout << "Upisite broj iz izbornika: ";
        cin >> izbor;
        if( izbor == 1 )
        {
            cout << "Unesite bar kod artikla: ";
            cin >> barkod[brojArtikla] ;
            cout << "Unesite naziv artikla: ";
            cin.ignore();
            getline(cin, artikli[brojArtikla]);
            cout << "Unesite cijene artikla: ";
            cin >> cijena[brojArtikla];

            datotekaUpisivanje.open("artikli.txt", ios::app);
            datotekaUpisivanje << barkod[brojArtikla] << endl;
            datotekaUpisivanje << artikli[brojArtikla] << endl;
            datotekaUpisivanje << cijena[brojArtikla] << endl;

            brojArtikla++;
        }
        else if( izbor == 2 )
        {
            cout << "bar kod" << "\t" << "naziv artikla" << "\t" << "cijena" << endl;
            for( int i = 0; i < brojArtikla; i++ )
            {
                cout << barkod[i] << "\t"<< artikli[i] << "\t"<< cijena[i] << endl;
            }
        }
        else if( izbor == 3 )
        {
            unsigned long long int barkod_pretraga;
            cout << "Upisite barkod po kojem zelite naci artikl: ";
            cin >> barkod_pretraga;
            bool pronadjen = false;
            for (int i = 0; i < brojArtikla; i ++)
            {
                if(barkod_pretraga== barkod[i])
                {
                    pronadjen=true;
                    cout << barkod[i] << "\t"<< artikli[i] << "\t"<< cijena[i] << endl;
                    break;
                }
            }
            if( pronadjen==false )
            {
                cout << "Barkod nije pronaden" << endl;
            }
        }

        else if( izbor == 4 )
        {
            string  artikli_pretraga;
            cout << "Upisite artikl po kojem zelite saznati podatke;  ";
            cin.ignore();
            getline(cin, artikli_pretraga );

            bool pronadjen = false;
            for ( int i = 0; i < brojArtikla; i ++)
            {
                if(artikli_pretraga == artikli[i] )
                {
                    pronadjen=true;
                    cout << barkod[i] << "\t"<< artikli[i] << "\t"<< cijena[i] << endl;
                    break;
                }
            }
            if(pronadjen==false)
            {
                cout << "Artikl nije pronaden " << endl;
            }
        }
        else if( izbor == 5 )
        {

        }
        else if( izbor == 6 )
        {
        }
        else if( izbor == 7 )
        {
            cout << "Kraj rada" << endl;
            break;
        }
        else
        {
            cout << "Unijeli ste krivi broj." << endl;
        }
        cout << endl;
    }
}
