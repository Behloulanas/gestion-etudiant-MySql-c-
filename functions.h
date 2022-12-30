#include <iostream>
#include <string>
#include <conio.h>
#include<ctime>
#include <Windows.h>
#include <fstream>
using namespace std;

class etudiant
{
	private:
		static int id;
		string nom;
		string prenom;
		string adresse;
		string filliere;
		string tel;
	public:
		etudiant();
		void saisie();
		void cruds();
		void afficher();
		void abscence();
		string getNom(){	return this->nom;}
};
int etudiant::id = 0;
etudiant::etudiant()
{
	this->id++;
	this->nom = "";
	this->prenom = "";
	this->adresse = "";
	this->filliere = "";
	this->tel = "";
}



void MaximizeOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window 
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}
 HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  
void fontsize(int a, int b){  
  PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();  
  lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);  
  GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
  lpConsoleCurrentFontEx->dwFontSize.X = a;  
  lpConsoleCurrentFontEx->dwFontSize.Y = b;  
  SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);  
 }  
 	
 void textcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}
int GetFontSize(HANDLE windowHandle, COORD *size)
{
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font)) return 0;

    *size = font.dwFontSize;

    return 1;
}
int SetFontSize(HANDLE windowHandle, COORD size)
{
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };

    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font)) return 0;

    font.dwFontSize = size;

    if (!SetCurrentConsoleFontEx(windowHandle, 0, &font)) return 0;

    return 1;
}

void FontSize(short _size)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;

    if (GetFontSize(h, &size))
    {
        size.Y = (_size);
        SetFontSize(h, size);
    }
}
int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.Y;
}
void gotoxy(int x, int y)
{
    COORD pos = { x, y };

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Load()
{
	int r,q;
	gotoxy(56,24);
    printf("C H E K I N G ...");
    gotoxy(40,25);	
    for(r=1; r<=49; r++)
    {
        for(q=0; q<=10000000; q++); 
        	printf(".",178);
    }
}
void Fetch()
{
	int r,q;
	gotoxy(89,29);
    printf("F E T C H I N G   D A T A ...");
    gotoxy(85,30);	
    for(r=1; r<=35; r++)
    {
        for(q=0; q<=30000000; q++); 
        	printf(".",178);
    }
    gotoxy(92,31);
    printf("CONNECT TO MYSQL ...");
    gotoxy(85,32);
    for(r=1; r<=35; r++)
    {
        for(q=0; q<=100000000; q++); 
        	printf(".",178);
    }
    gotoxy(87,33);
    cout << "Taper une touche pour finir..." ;
    getch();
}
void rect(int width, int height, int x, int y)
{
    int i,j;

    gotoxy(x,y);
    //Top
    printf("\xDA");
    for(i=0; i<width; i++)
        printf("\xC4");
    printf("\xBF\n");

    gotoxy(x,wherey());
    //Left and Right
    for(i=0; i<height; i++)
    {
        printf("\xB3");
        for(j=0; j<width; j++)
            printf(" ");
        printf("\xB3\n");

        gotoxy(x,wherey());
    }

    //Bottom
    printf("\xC0");
    for(i=0; i<width; i++)
        printf("\xC4");
    printf("\xD9");
}
void BankArt(int x, int y)
{
    gotoxy(x,y);
    puts("         _._._                       _._._");
    gotoxy(x,++y);
    puts("        _|   |_                     _|   |_");
    gotoxy(x,++y);
    puts("        | ... |_._._._._._._._._._._| ... |");
    gotoxy(x,++y);
    puts("        | ||| |  o    E-M-S-I     o  | ||| |");
    gotoxy(x,++y);
    puts("        | \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |");
    gotoxy(x,++y);
    puts("   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())");
    gotoxy(x,++y);
    puts("  (())) |     |---------------------|     | (()))");
    gotoxy(x,++y);
    puts(" (())())| \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |(())())");
    gotoxy(x,++y);
    puts(" (()))()|[-|-]|  :::   .-\"-.   :::  |[-|-]|(()))()");
    gotoxy(x,++y);
    puts(" ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(()");
    gotoxy(x,++y);
    puts("    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||");
}
void BankTitle(int x, int y)
{
    gotoxy(x,y);
    puts(" | |           ____        ____              T T     ||                ||");
    gotoxy(x,++y);	
    puts(" | |        (       )    (                   | |     ||    |           ||");
    gotoxy(x,++y);
    puts(" | |        (       )     (     _____        | |     ||       |        || ");
    gotoxy(x,++y); 
    puts(" | |        (       )      (       )         | |     ||          |     ||");
    gotoxy(x,++y);
    puts(" | |        (       )        (       )       | |     ||            |   ||");
    gotoxy(x,++y);
    puts(" |______       ____            ( ______ )    T T     ||              | ||");

}
void fillieres()
{
	char choice;
	rect(50,20,29,15);
	gotoxy(35,18);
	cout << "A- PREMIERE ANNEE PREPARATOIRE";
	gotoxy(35,20);
	cout << "B- DEUXIEME ANNEE PREPARATOIRE";
	gotoxy(35,22);
	cout << "C- GENIE INDUSTRIEL";
	gotoxy(35,24);
	cout << "D- GENIE CIVIL,  ET TRAVAUX PUBLICS ";
	gotoxy(35,26);
	cout << "E- INGENIERIE AUTOMATISMES ET INDUSTRIELLE";
	gotoxy(35,28);
	cout << "F- INGENIERIE INFORMATIQUE ET RESEAUX";
	gotoxy(35,30);
	cout << "G- INGENIERIE FINANCIERE ET AUDIT";
	gotoxy(35,32);
	cout << "H- SE DECONNECTER";
	gotoxy(35,35);
	cout << "X- QUITTER LE PROGRAMME";
	rect(60,3,10,38);
	gotoxy(20,40);
	cout << " Selectionner une option :  ";
	cin >> choice;
}
void etudiant::saisie()
{
				fstream Myfile;
				Myfile.open("file.txt",ios::app);
				rect(43,28,39,13);
				rect(8,1,56,14);
				gotoxy(59,15);
				cout << "FORM";
				// nom
				rect(6,1,43,17);
				gotoxy(45,18);
				cout << "Nom";
				rect(20,1,53,17);
				// prenom
				rect(7,1,43,20);
				gotoxy(45,21);
				cout << "Prenom";
				rect(20,1,53,20);
				// adresse
				rect(12,1,43,23);
				gotoxy(45,24);
				cout << "Adresse";
				rect(20,1,53,23);
				// filliere
				rect(8,1,43,26);
				gotoxy(44,27);
				cout << "Filliere";
				// tele
				rect(8,1,43,33);
				gotoxy(45,34);
				cout << "Tele";
				rect(20,1,53,33);
				gotoxy(54,34);
				cout << "+212";
				// ID
				rect(8,1,43,36);
				gotoxy(46,37);
				cout << "ID";
				rect(3,1,53,36);
				gotoxy(55,37);
				cout << this->id;
				
				// cin nom
				gotoxy(55,18);	
				cin >> this->nom ;
				getline(cin,this->nom);
				Myfile << this->nom << endl;
				// cin prenom 
				gotoxy(55,21);	
				//cin >> this->prenom;
				getline(cin,this->prenom);
				Myfile << this->prenom << endl;
				// cin adresse
				gotoxy(55,24);	
				getline(cin,this->adresse);
				Myfile << this->adresse << endl;
				//getline(cin,this->adresse);
				// filliere choice
				gotoxy(60,26);
				cout << "a- Informatique";
				gotoxy(60,27);
				cout << "b- Genie-Civil";
				gotoxy(60,28);
				cout << "c- Finance";
				gotoxy(44,30);
				cout << ">> ";
				cin >> this->filliere;
				if(this->filliere == "a")
				{
					Myfile << "Informatique" << endl;
				}
				// cin tele
				gotoxy(58,34);
				cin >> this->tel;
				Myfile << this->tel << endl;
				gotoxy(48,40);
				cout << "Form submitted successfully";
				Fetch();
				Myfile.close();
}
void etudiant::afficher()
{
				string d;
				rect(43,28,39,13);
				rect(8,1,56,14);
				gotoxy(59,15);
				cout << "FORM";
				// nom
				rect(6,1,43,17);
				gotoxy(45,18);
				cout << "Nom";
				rect(20,1,53,17);
				// prenom
				rect(7,1,43,20);
				gotoxy(45,21);
				cout << "Prenom";
				rect(20,1,53,20);
				// adresse
				rect(12,1,43,23);
				gotoxy(45,24);
				cout << "Adresse";
				rect(20,1,53,23);
				// filliere
				rect(8,1,43,26);
				gotoxy(44,27);
				cout << "Filliere";
				// tele
				rect(8,1,43,29);
				gotoxy(45,30);
				cout << "Tele";
				rect(20,1,53,29);
				// ID
				rect(8,1,43,32);
				gotoxy(46,33);
				cout << "ID";
				rect(3,1,53,32);
				gotoxy(55,33);
				cout << this->id;
				// file
				fstream Myfile;
				Myfile.open("file.txt",ios::in);
				int i = 18;
				while(Myfile >> d)
				{
					gotoxy(55,i);
					i+=3;
					cout << d;	
				}
				Myfile.close();
}
void mylist()
{
	char choice;
	etudiant *e = new etudiant;
	rect(16,1,16,13);
	gotoxy(23,14);
	cout << "EMSI";
	rect(27,7,10,16);
	gotoxy(17,17);
	cout << "a- CRUDS" ;
	gotoxy(17,19);
	cout << "b- ABSCENCE" ;
	gotoxy(17,21);
	cout << "c- FILLIERES" ;
	gotoxy(17,23);
	cout << "d- DECONNEXION" ;
	gotoxy(17,25);
	cout << ">> ";
	cin >> choice;
	switch(choice)
	{
		case 'c':
			{
				//fillieres();
			}
		case 'b':
			{
				e->abscence();
			}
		case 'a':
			{
				e->cruds();
			}
	}
	return;
}

void etudiant::cruds()
{
	char choice;
	gotoxy(15,27);
	cout << "--> a-Ajouter";
	gotoxy(15,29);
	cout << "--> b-Modifier";
	gotoxy(15,31);
	cout << "--> c-afficher";
	gotoxy(15,33);
	cout << "--> d-rechercher";
	gotoxy(15,35);
	cout << "--> e-Supprimer";
	gotoxy(15,37);
	cout << ">> ";
	cin >> choice;
	switch(choice)
	{
		case 'a':
			{
				etudiant::saisie();
				system("cls");
				BankArt(40,2); 
		   		rect(114,30,7,12);
				rect(34,2,84,13);
				gotoxy(86,14);
				//cout << "Date : " << asctime(tt); 
				rect(34,2,84,17);
				gotoxy(86,18);
				//cout << "Role : " << this->role;
				mylist();
			}
		case 'c':
			{
				etudiant::afficher();
			}
	}
}
void etudiant::abscence()
{
	system("cls");
	cout << endl << endl ;
	cout << "\t\t____________________________________________________________________________________________________________" << endl;
	cout << "\t\t|  ID   |     Nom      |     Prenom    |    filliere   |        Adresse        |       Telephone            | " << endl;
	cout << "\t\t____________________________________________________________________________________________________________" << endl;
	cout << "\t\t|  1    |    Ahmali    |   Abdessamad  |  Informatique |        daoudiate      |       +212697870947        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  2    |Ait bouserhane|     Maria     |  Informatique |        Massira 3      |       +212697820202        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  3    | Ait Lebhiri  |     Ayman     |  Informatique |        Berrima        |       +212614259999        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  4    |  Al mastour  |     Salwa     |  Informatique |        Al Fadel       |       +212693677777        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  5    |    Ajmaoui   |     Nadia     |  Informatique |        Rue Asfii      |       +212625677454        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  6    |   Aresmouk   |  El mokhrtar  |  Informatique |        Mabrouka       |       +212611396333        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  7    | Bamba Valey  |     Hamed     |  Informatique |        France         |       +212666666666        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  8    |   Behloul    |     Anas      |  Informatique |        Sidi Youssef   |       +212771265689        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  9    |  Boutkhamt   |  Abdelwahab   |  Informatique |        Souq-Sebt      |       +212624327898        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  10   |   Hanguir    |    Oussama    |  Informatique |          Doha         |       +212697877878        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  11   |   Belkiyal   |     Amina     |  Informatique |       Rue Asfii       |       +212697870000        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t|  12   |   Botazit    |    Ihssane    |  Informatique |        Mebrouka       |       +212697877878        | " << endl;
	cout << "\t\t -----------------------------------------------------------------------------------------------------------" << endl;

	getch();
	system("cls");
}







