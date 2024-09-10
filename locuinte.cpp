#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Locuinta
{
	const int nr;
	char* tipLocuinta = nullptr;
	int numarLocatari = 0;
	int numarCamere = 0;
	int etaje = 0;
public:
	Locuinta() :nr(0)
	{
		this->tipLocuinta = new char[strlen("Anonim") + 1];
		strcpy(this->tipLocuinta, "Anonim");
	}
	Locuinta(int nr, const char* tipLocuinta, int numarLocatari, int numarCamere, int etaje) :nr(nr)
	{
		if (tipLocuinta != nullptr)
		{
			this->tipLocuinta = new char[strlen(tipLocuinta) + 1];
			strcpy(this->tipLocuinta, tipLocuinta);
		}
		else
		{
			this->tipLocuinta = new char[strlen("Anonim") + 1];
			strcpy(this->tipLocuinta, "Anonim");
		}
		if (numarLocatari > 0)
		{
			this->numarLocatari = numarLocatari;
		}
		if (numarCamere > 0)
		{
			this->numarCamere = numarCamere;
		}
		if (etaje > 0)
		{
			this->etaje =etaje;
		}
	}
	Locuinta(const Locuinta& l):nr(l.nr)
	{
		if (l.tipLocuinta != nullptr)
		{
			this->tipLocuinta = new char[strlen(l.tipLocuinta) + 1];
			strcpy(this->tipLocuinta, l.tipLocuinta);
		}
		else
		{
			this->tipLocuinta = new char[strlen("Anonim") + 1];
			strcpy(this->tipLocuinta, "Anonim");
		}
		if (l.numarLocatari > 0)
		{
			this->numarLocatari = l.numarLocatari;
		}
		if (l.numarCamere > 0)
		{
			this->numarCamere = l.numarCamere;
		}
		if (l.etaje > 0)
		{
			this->etaje = l.etaje;
		}
	}
	Locuinta& operator=(const Locuinta& l)
	{
		if (this != &l)
		{
			delete[] this->tipLocuinta;
			this->tipLocuinta = nullptr;
			if (l.tipLocuinta != nullptr)
			{
				this->tipLocuinta = new char[strlen(l.tipLocuinta) + 1];
				strcpy(this->tipLocuinta, l.tipLocuinta);
			}
			else
			{
				this->tipLocuinta = new char[strlen("Anonim") + 1];
				strcpy(this->tipLocuinta, "Anonim");
			}
			if (l.numarLocatari > 0)
			{
				this->numarLocatari = l.numarLocatari;
			}
			if (l.numarCamere > 0)
			{
				this->numarCamere = l.numarCamere;
			}
			if (l.etaje > 0)
			{
				this->etaje = l.etaje;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Locuinta& l)
	{
		out << "\n----------------------------";
		out << "\nTip locuinta: " << l.tipLocuinta;
		out << "\nNumar locatari: " << l.numarLocatari;
		out << "\nNumar camere: " << l.numarCamere;
		out << "\nNumar etaje: " << l.etaje;
		return out;
	}
	~Locuinta()
	{
		delete[] this->tipLocuinta;
		this->tipLocuinta = nullptr;
		
	}
	bool operator()(int numarLocatari)
	{
		if (this->numarLocatari > 0)
		{
			numarLocatari = this->numarLocatari;
			if (this->numarLocatari <= this->numarCamere)
			{
				return true;
			}
			return false;
		}
	}
	bool operator==(const Locuinta& l)
	{
		if (this->nr == l.nr && this->numarLocatari == l.numarLocatari && this->numarCamere == l.numarCamere && this->etaje == l.etaje)
		{
			if (strcmp(this->tipLocuinta, l.tipLocuinta) == 0)
			{
				return true;
			}
		}
		return false;
	}
	virtual void TipLocuinta()
	{
		cout<<"\nAceasta este o locuinta";
	}
	friend bool operator>(const Locuinta& l1, const Locuinta& l2)
	{
		return l1.etaje > l2.etaje;
	}
};

class Bloc:public Locuinta
{
private:
	bool areAdministrator = 0;
	string* tipuriApartamente = nullptr;
	int* nrTipApartament = nullptr;
	int nrTipuri = 0;
public:
	Bloc() :Locuinta()
	{

	}
	Bloc(int nr, const char* tipLocuinta, int numarLocatari, int numarCamere, int etaje,bool areAdministrator,string* tipuriApartamente,int* nrTipApartament,int nrTipuri) :Locuinta(nr,tipLocuinta,numarLocatari,numarCamere,etaje)
	{
		this->areAdministrator = areAdministrator;
		if (nrTipuri > 0)
		{
			this->nrTipuri = nrTipuri;
		}
		if (tipuriApartamente != nullptr && nrTipuri>0)
		{
			this->tipuriApartamente = new string[this->nrTipuri];
			for (int i = 0; i < this->nrTipuri; i++)
			{
				this->tipuriApartamente[i] = tipuriApartamente[i];
			}
		}
		if (nrTipApartament != nullptr && nrTipuri > 0)
		{
			this->nrTipApartament = new int[this->nrTipuri];
			for (int i = 0; i < this->nrTipuri; i++)
			{
				this->nrTipApartament[i] = nrTipApartament[i];
			}
		}

	}
	Bloc(const Bloc& b):Locuinta(b)
	{
		this->areAdministrator = b.areAdministrator;
		if (b.nrTipuri > 0)
		{
			this->nrTipuri = b.nrTipuri;
		}
		if (b.tipuriApartamente != nullptr && b.nrTipuri > 0)
		{
			this->tipuriApartamente = new string[this->nrTipuri];
			for (int i = 0; i < this->nrTipuri; i++)
			{
				this->tipuriApartamente[i] = b.tipuriApartamente[i];
			}
		}
		if (b.nrTipApartament != nullptr && b.nrTipuri > 0)
		{
			this->nrTipApartament = new int[this->nrTipuri];
			for (int i = 0; i < this->nrTipuri; i++)
			{
				this->nrTipApartament[i] = b.nrTipApartament[i];
			}
		}
	}
	Bloc& operator=(const Bloc& b)
	{
		if (this != &b)
		{
			delete[] this->tipuriApartamente;
			this->tipuriApartamente = nullptr;
			delete[] this->nrTipApartament;
			this->nrTipApartament = nullptr;

			this->Locuinta::operator=(b);
			this->areAdministrator = b.areAdministrator;
			if (b.nrTipuri > 0)
			{
				this->nrTipuri = b.nrTipuri;
			}
			if (b.tipuriApartamente != nullptr && b.nrTipuri > 0)
			{
				this->tipuriApartamente = new string[this->nrTipuri];
				for (int i = 0; i < this->nrTipuri; i++)
				{
					this->tipuriApartamente[i] = b.tipuriApartamente[i];
				}
			}
			if (b.nrTipApartament != nullptr && b.nrTipuri > 0)
			{
				this->nrTipApartament = new int[this->nrTipuri];
				for (int i = 0; i < this->nrTipuri; i++)
				{
					this->nrTipApartament[i] = b.nrTipApartament[i];
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Bloc& b)
	{
		out << (Locuinta&)b;
		out << "\nAre administrator: ";
		if (b.areAdministrator == 0)
			out << "Nu";
		else
			out << "Da";
		out << "\nNumar tipuri apartamente: " << b.nrTipuri;
		if (b.tipuriApartamente != nullptr && b.nrTipApartament != nullptr && b.nrTipuri > 0)
		{
			out << "\nTip apartament " << " - " << "Nr de camere de acest tip"<<endl;
			for (int i = 0; i < b.nrTipuri; i++)
			{
				out << b.tipuriApartamente[i] << " - " << b.nrTipApartament[i]<<endl;
			}
		}
		else
			out << "\nTip apartament =0" << " - " << "Nr de camere de acest tip=0";
		return out;
	}
	~Bloc()
	{
		delete[] this->tipuriApartamente;
		this->tipuriApartamente = nullptr;
		delete[] this->nrTipApartament;
		this->nrTipApartament = nullptr;
	}
	 void TipLocuinta()
	{
		cout << "\nAceasta este un bloc";
	}
};

//getteri si setteri
template<class TIP>
void sortare(TIP a, TIP b)
{
	TIP aux;
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
	cout << a << " " << b;
}
int main()
{
	cout << endl << "\nCons implicit: " << endl;
	Locuinta l1;
	cout << l1;

	cout << endl << "\nCons cu parametrii: " << endl;
	Locuinta l2(123,"casa",4,2,1);
	cout << l2;

	cout << endl << "\nCons cu parametrii: " << endl;
	Locuinta l3(124, "vila", 4, 6, 2);
	cout << l3;

	cout << endl << "\nCons copy: " << endl;
	Locuinta l4 = l2;
	cout << l4;

	cout << endl << "\nop = " << endl;
	Locuinta l5;
	l5 = l2;
	cout << l5;

	int numarLocatari=0;
	if (l2(numarLocatari) == true)
	{
		cout << "\nFiecare persoana poate sa aiba propria camera.";
	}
	else
		cout << "\nNu sunt camere suficiente.";

	if (l2 == l4)
	{
		cout << "\nLocuinte identice";
	}
	else
		cout << "\nLocuintele nu sunt identice";

	cout << endl << "\nCons implicit clasa derivata: " << endl;
	Bloc b1;
	cout << b1;

	cout << endl << "\nCons cu parametrii clasa derivata: " << endl;
	string tipuriAp[] = { "apartament cu 3 camere","apartament 2 camere","garsoniera" };
	int nrTipAp[] = { 10,20,10 };
	Bloc b2(130,"Bloc 4 etaje",120,80,4,1,tipuriAp,nrTipAp,3);
	cout << b2;

	Locuinta* lista[2];
	lista[0] = &b1;
	lista[1] = &l2;
	lista[0]->TipLocuinta();
	cout << endl;
	lista[1]->TipLocuinta();

	cout << "\nSortare: "<<endl;
	sortare<Locuinta>(l2, l3);
	cout << endl;
	sortare<int>(6,3);
}