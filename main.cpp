#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

bool zycie = true;
bool strzal = false;

int pozycjay = 7;
int pozycjax = 1;

int pociskx;
int pocisky;
bool reload;

int pociskwrogx;
int pociskwrogy;
bool strzalwrog = true;
bool reloadwrog = true;

int wrogx = 34;
int wrogy = 7;
bool wroghp = true;

int odlegloscx;
int odlegloscy;
int ruchx;
int ruchy;

char plansza[16][36];

int main()
{
    srand( time( NULL ) );

    cout<<"By Adam Czwordon";
    Sleep(500);

    while(zycie&&wroghp)
    {
        system( "cls" );

        for(int i = 0; i <15; i++)
        {
            plansza[i][0] = ' ';

            for(int x = 0; x <35; x++)
            {
                plansza[i][x] = ' ';
            }
        }

        plansza[pozycjay][pozycjax] = '+';


        if(reload == false)
        {
            strzal = true;
        }
        else strzal = false;

        if(strzal)
        {
            if((pociskx == pociskwrogx)&&(pocisky == pociskwrogy))
            {
                plansza[pocisky][pociskx] = ' ';
                plansza[pociskwrogy][pociskwrogx] = ' ';
                pociskwrogx = 36;
                pociskwrogy = 16;
                pociskx = 35;
                pocisky = 16;
                reload = true;
            }

            pociskx++;
            plansza[pocisky][pociskx] = '-';

            if((pociskx >= 35)||(pocisky >= 14))
            {
                strzal = false;
                reload = true;
                plansza[pocisky][pociskx] = ' ';
            }

            if((pociskx == wrogx)&&(pocisky == wrogy))
            {
                wroghp = false;
                reload = true;
            }
        }

        if((pociskx == pociskwrogx)&&(pocisky == pociskwrogy))
        {
            plansza[pocisky][pociskx] = ' ';
            plansza[pociskwrogy][pociskwrogx] = ' ';
            pociskwrogx = 36;
            pociskwrogy = 16;
            pociskx = 35;
            pocisky = 16;
            reload = true;
        }

        if(wroghp)
        {
            odlegloscx = pozycjax - wrogx;
            odlegloscy = pozycjay - wrogy;

            ruchx = rand()% 5 - 4;
            ruchy = rand()% 20 - 10;

            if((odlegloscx < ruchx)&&(wrogx > 0))
                wrogx--;
            else if ((odlegloscx > 5)&&(wrogx < 34))
                wrogx++;

            if((odlegloscy < ruchy)&&(wrogy > 0))
                wrogy--;
            else if ((odlegloscy > ruchy)&&(wrogy < 14))
                wrogy++;

            if(reloadwrog)
            {
                pociskwrogx = wrogx;
                pociskwrogy = wrogy;
                reloadwrog = false;
                strzalwrog = true;
            }

            if(strzalwrog)
            {
                pociskwrogx--;
                plansza[pociskwrogy][pociskwrogx] = 'o';

                if((pociskx == pociskwrogx)&&(pocisky == pociskwrogy))
                {
                    plansza[pocisky][pociskx] = ' ';
                    plansza[pociskwrogy][pociskwrogx] = ' ';
                    pociskwrogx = 36;
                    pociskwrogy = 16;
                    pociskx = 35;
                    pocisky = 16;
                    reload = true;
                    reloadwrog = true;
                }
            }

            if(pociskwrogx == 1)
            {
                strzalwrog = false;
                reloadwrog = true;
                plansza[pocisky][pociskx] = ' ';
            }



            plansza[wrogy][wrogx] = 'H';
        }
        else
            plansza[wrogy][wrogx] = ' ';




        /** WYSWIETLANIE PLANSZY **/

        for(int i = 0; i <15; i++)
        {

            for(int x = 0; x <35; x++)
            {
                cout << plansza[i][x];
            }
            cout<<"\n";
        }


        /** OBSŁUGA KLAWIATURY **/

        char wybor = _getch();

        switch(wybor)
        {
        case 87:
        case 119:

            if(pozycjay>0)
            {
                pozycjay--;
            }

            break;

        case 83:
        case 115:

            if(pozycjay<14)
            {
                pozycjay++;
            }

            break;

        case 65:
        case 97:

            if(pozycjax>0)
            {
                pozycjax--;
            }

            break;

        case 68:
        case 100:

            if(pozycjax<34)
            {
                pozycjax++;
            }

            break;

        case ' ':

            if(reload == true)
            {
                pociskx = pozycjax;
                pocisky = pozycjay;
                reload = false;
                strzal = true;
            }

            break;

        }

        if((pociskwrogx == pozycjax)&&(pociskwrogy == pozycjay))
        {
            zycie = false;
        }

        if((pociskx == wrogx)&&(pocisky == wrogy))
        {
            wroghp = false;
        }

    }

    /** PODSUMOWANIE **/

    system("cls");

    if(zycie==false)
    {
        cout<<"PRZEGRALES!\n";
    }

    if(wroghp==false)
    {
        cout<<"WYGRALES!\n";
    }

    Sleep(500);

    system("pause");

    return 0;
}
