#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<list>
#include<vector>
using namespace std;

class Produs_carne
{
	static int zi_curenta;
	static int luna_curenta;
	static int an_curent;

	int zi_expirare = 1;
	int luna_expirare = 1;
	int an_expirare = 2024;
	float pret = 0;
	float stoc = 0;
	char* categorie =nullptr;
public:
	Produs_carne()
	{
		this->categorie = new char[strlen("Anonim") + 1];
		strcpy(this->categorie, "Anonim");
	}
	Produs_carne(int zi_expirare, int luna_expirare,int an_expirare,float pret,float stoc,const char* categorie)
	{
		if (zi_expirare > 0 && zi_expirare <= 30)
		{
			this->zi_expirare = zi_expirare;
		}
		if (luna_expirare > 0 && luna_expirare <= 12)
		{
			this->luna_expirare = luna_expirare;
		}
		if (an_expirare >2020 && an_expirare<=2024)
		{
			this->an_expirare = an_expirare;
		}
		if (pret > 0)
		{
			this->pret = pret;
		}
		if (stoc > 0)
		{
			this->stoc = stoc;
		}
		if (strlen(categorie) > 0 && categorie!=nullptr)
		{
			this->categorie = new char[strlen(categorie)+1];
			strcpy(this->categorie, categorie);
		}
		else
		{
			this->categorie = new char[strlen("Anonim") + 1];
			strcpy(this->categorie, "Anonim");
		}
		
	}
	Produs_carne(const Produs_carne& p)
	{
		if (p.zi_expirare > 0 && p.zi_expirare <= 30)
		{
			this->zi_expirare = p.zi_expirare;
		}
		if (p.luna_expirare > 0 && p.luna_expirare <= 12)
		{
			this->luna_expirare = p.luna_expirare;
		}
		if (p.an_expirare > 2020 && p.an_expirare <= 2024)
		{
			this->an_expirare = p.an_expirare;
		}
		if (p.pret > 0)
		{
			this->pret = p.pret;
		}
		if (p.stoc > 0)
		{
			this->stoc = p.stoc;
		}
		if (strlen(p.categorie) > 0 && p.categorie != nullptr)
		{
			this->categorie = new char[strlen(p.categorie) + 1];
			strcpy(this->categorie, p.categorie);
		}
		else
		{
			this->categorie = new char[strlen("Anonim") + 1];
			strcpy(this->categorie, "Anonim");
		}
	}

	Produs_carne& operator=(const Produs_carne& p)
	{
		if (this != &p)
		{
			delete[] this->categorie;
			this->categorie = nullptr;

			if (p.zi_expirare > 0 && p.zi_expirare <= 30)
			{
				this->zi_expirare = p.zi_expirare;
			}
			if (p.luna_expirare > 0 && p.luna_expirare <= 12)
			{
				this->luna_expirare = p.luna_expirare;
			}
			if (p.an_expirare > 2020 && p.an_expirare <= 2024)
			{
				this->an_expirare = p.an_expirare;
			}
			if (p.pret > 0)
			{
				this->pret = p.pret;
			}
			if (p.stoc > 0)
			{
				this->stoc = p.stoc;
			}
			if (strlen(p.categorie) > 0 && p.categorie != nullptr)
			{
				this->categorie = new char[strlen(p.categorie) + 1];
				strcpy(this->categorie, p.categorie);
			}
			else
			{
				this->categorie = new char[strlen("Anonim") + 1];
				strcpy(this->categorie, "Anonim");
			}
		}
		return *this;
	}
	~Produs_carne()
	{
		delete[] this->categorie;
		this->categorie = nullptr;
	}

	friend ostream& operator<<(ostream& out, const Produs_carne& p)
	{
		out << "\n----------------------------";
		out << "\nCategorie: " << p.categorie;
		out << "\nZi-luna-an expirare: " << p.zi_expirare << "-" << p.luna_expirare << "-" << p.an_expirare;
		out << "\nPret: " << p.pret;
		out << "\nStoc: " << p.stoc;
		return out;
	}

	float getStoc()
	{
		return this->stoc;
	}
	void setStoc(float stoc)
	{
		if (stoc > 0)
		{
			this->stoc = stoc;
		}
		else
			this->stoc = 0;
	}
	void operator*=(float reducere)
	{
		if (reducere > 0 && this->pret > 0)
		{
			int diferenta = this->zi_expirare - zi_curenta;
			Produs_carne p = *this;
			if (diferenta == 1)
			{
				p.pret *= reducere;
				this->pret = this->pret - p.pret;
				cout << "\nProdus care expira maine, noul pret dupa reducere: " << this->pret;
			}
			if (diferenta == 0)
			{
				cout << "\nProdusul expira astazi";
			}
			if (diferenta < 0)
			{
				cout << "\nProdus expirat";
			}
			if (diferenta > 1)
			{
				cout << "\nProdusul expira in perioada urmatoare";
			}
		}
	}
	bool operator==(const Produs_carne& p)
	{
		if (this != &p)
		{
			if (this->zi_expirare == p.zi_expirare && this->luna_expirare == p.luna_expirare && this->an_expirare == p.an_expirare && this->pret == p.pret && this->stoc == p.stoc)
			{
				if (strcmp(this->categorie, p.categorie)==0)
				{
					return true;
				}
				
			}
			return false;
		}
	}
	friend bool operator <(const Produs_carne& p1, const Produs_carne& p2)
	{
		return p1.stoc < p2.stoc;
	}
	
};
int Produs_carne::zi_curenta = 19;
int Produs_carne::luna_curenta = 1;
int Produs_carne::an_curent = 2024;

class Depozit
{
private:
	Produs_carne* produse_carne = nullptr;
	int nrProduse = 0;
public:
	Depozit()
	{

	}
	Depozit(Produs_carne* produse_carne, int nrProduse)
	{
		if (nrProduse > 0)
		{
			this->nrProduse = nrProduse;
		}
		if (produse_carne != nullptr && nrProduse > 0)
		{
			this->produse_carne = new Produs_carne[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->produse_carne[i] = produse_carne[i];
			}
		}
	}
	Depozit(const Depozit& d)
	{
		if (d.nrProduse > 0)
		{
			this->nrProduse = d.nrProduse;
		}
		if (d.produse_carne != nullptr && d.nrProduse > 0)
		{
			this->produse_carne = new Produs_carne[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
			{
				this->produse_carne[i] = d.produse_carne[i];
			}
		}
	}
	Depozit& operator=(const Depozit& d)
	{
		if (this != &d)
		{
			delete[] this->produse_carne;
			this->produse_carne = nullptr;

			if (d.nrProduse > 0)
			{
				this->nrProduse = d.nrProduse;
			}
			if (d.produse_carne != nullptr && d.nrProduse > 0)
			{
				this->produse_carne = new Produs_carne[this->nrProduse];
				for (int i = 0; i < this->nrProduse; i++)
				{
					this->produse_carne[i] = d.produse_carne[i];
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Depozit& d)
	{
		out << "\n----------------------";
		out << "\nNr produse: " << d.nrProduse;
		out << "\nProduse din stoc: ";
		if (d.produse_carne != nullptr && d.nrProduse > 0)
		{
			for (int i = 0; i < d.nrProduse; i++)
			{
				out << d.produse_carne[i] << endl;
			}
		}
		else
			out << "-";
		return out;
	}
	~Depozit()
	{
		delete[] this->produse_carne;
		this->produse_carne = nullptr;
	}

	Depozit& operator+=(Produs_carne& p)
	{
		Depozit d = *this;
		Produs_carne* temp = new Produs_carne[d.nrProduse+1];
		for (int i = 0; i < d.nrProduse; i++)
		{
			temp[i] = d.produse_carne[i];
		}
		if (p.getStoc() > 0)
		{
			temp[d.nrProduse] = p;

			delete[] this->produse_carne;
			this->produse_carne = nullptr;
			this->nrProduse++;
			this->produse_carne = temp;
		}
		else
			cout << "\nProdusul pe care doriti sa il adaugati nu este in stoc";
		return *this;
	}
	Depozit& operator()(int pozitieInitiala, int pozitieFinala)
	{
		pozitieFinala = this->nrProduse;
		if (pozitieInitiala >= 0 && pozitieInitiala < this->nrProduse && pozitieFinala <= this->nrProduse)
		{
			for (int i = pozitieInitiala; i < pozitieFinala; i++)
			{
				if (this->produse_carne[i].getStoc() == 0)
				{
					for (int j = i; j < pozitieFinala; j++)
					{
						this->produse_carne[j] = this->produse_carne[j + 1];
					}
					this->nrProduse--;
				}
				
			}
			
		}
		return *this;

	}
	virtual float StocTotal()
	{
		float suma = 0;
		for (int i = 0; i < this->nrProduse; i++)
		{
			suma += this->produse_carne[i].getStoc();
		}
		return suma;
	}
};
class CentruDepozitare:public Depozit
{
	float* stocuriCompartiment = nullptr;
	int nrCompartimente = 0;
public:
	CentruDepozitare():Depozit()
	{

	}
	CentruDepozitare(Produs_carne* produse_carne, int nrProduse,float* stocuriCompartiment, int nrCompartimente) :Depozit(produse_carne,nrProduse)
	{
		if (nrCompartimente > 0 && stocuriCompartiment != nullptr)
		{
			this->nrCompartimente = nrCompartimente;
			this->stocuriCompartiment = new float[this->nrCompartimente];
			for (int i = 0; i < this->nrCompartimente; i++)
			{
				this->stocuriCompartiment[i] = stocuriCompartiment[i];
			}
		}
	}
	CentruDepozitare(const CentruDepozitare& c):Depozit(c)
	{
		if (c.nrCompartimente > 0 && c.stocuriCompartiment != nullptr)
		{
			this->nrCompartimente = c.nrCompartimente;
			this->stocuriCompartiment = new float[this->nrCompartimente];
			for (int i = 0; i < this->nrCompartimente; i++)
			{
				this->stocuriCompartiment[i] = c.stocuriCompartiment[i];
			}
		}
	}
	CentruDepozitare& operator=(const CentruDepozitare& c)
	{
		if (this != &c)
		{
			this->Depozit::operator=(c);
			delete[] this->stocuriCompartiment;
			this->stocuriCompartiment = nullptr;
			if (c.nrCompartimente > 0 && c.stocuriCompartiment != nullptr)
			{
				this->nrCompartimente = c.nrCompartimente;
				this->stocuriCompartiment = new float[this->nrCompartimente];
				for (int i = 0; i < this->nrCompartimente; i++)
				{
					this->stocuriCompartiment[i] = c.stocuriCompartiment[i];
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const CentruDepozitare& c)
	{
		if (c.stocuriCompartiment != nullptr && c.nrCompartimente>0)
		{
			out << (Depozit&)c;
			out << "\nNr compartimente: " << c.nrCompartimente;
			out << "\nLista stocuri: "<<endl;
			for (int i = 0; i < c.nrCompartimente; i++)
			{
				out << c.stocuriCompartiment[i] << endl;
			}
		}
		else
		{
			out << "\nNr compartimente: " << c.nrCompartimente;
			out << "\nLista stocuri: -";
		}
		return out;
	}
	~CentruDepozitare()
	{
		delete[] this->stocuriCompartiment;
		this->stocuriCompartiment = nullptr;
	}
	float StocTotal()
	{
		float suma = Depozit::StocTotal();
		float stocInitial = 0;
		for (int i = 0; i < this->nrCompartimente; i++)
		{
			stocInitial += this->stocuriCompartiment[i];

		}
		stocInitial += suma;
		return stocInitial;
	}
};
int main()
{
	Produs_carne p1;
	cout << p1;

	Produs_carne p2(20, 01, 2024, 30, 100, "Porc");
	cout << p2;

	Produs_carne p5(30, 02, 2024, 40, 200, "Peste apa dulce");
	cout << p5;

	Produs_carne p6(15, 02, 2024, 50, 300, "Pui");
	cout << p6;

	Produs_carne p7(16, 03, 2024, 60, 0, "Rata");
	cout << p7;

	Produs_carne p8(2, 03, 2024, 60, 10, "Peste apa sarata");
	cout << p8;


	Produs_carne produse_carne[] = { p2,p5,p7,p8 };

	cout << endl;
	Depozit d2(produse_carne, 4);
	cout << d2;


	CentruDepozitare c1;
	cout << c1;
	cout << endl;
	float stocuri[] = { 10,20,30 };
	cout << "\nCompartiment mare";
	CentruDepozitare c2(produse_carne,4, stocuri, 3);
	cout << c2;

	Depozit* listaStocuri[10];
	listaStocuri[0] = &d2;
	listaStocuri[1] = &c2;

	cout << "\nStoc total:";
	float suma = 0;
	for (int i = 0; i < 2; i++)
	{
		suma += listaStocuri[i]->StocTotal();
	}
	cout<< suma;


	/*cout << endl<<"\nCons copy: ";
	Produs_carne p3 = p2;
	cout << p3;

	cout << endl << "\nOp = ";
	Produs_carne p4;
	p4 = p2;
	cout << p4;

	cout << endl;
	cout << "\nOp *=";
	p2 *= 0.2;
	p5 *= 0.2;

	if (p2 == p5)
	{
		cout << "\nProduse identice";
	}
	else
		cout << "\nProdusele nu sunt identice";

	Produs_carne produse_carne[] = { p2,p5,p7,p8};
	
	cout << endl;
	Depozit d2(produse_carne,4);
	cout << d2;

	cout << "\nAdaug produsele care sunt in stoc: ";
	d2 += p6;
	cout << d2;

	cout << "\nElimin produsele care nu mai sunt in stoc: ";
	int nrProduse = 0;
	d2(0, nrProduse);
	cout << d2;

	cout << endl << "STL";
	map<Produs_carne,string>mapP;
	mapP[p5] = "Peste apa dulce";
	mapP[p8] = "Peste apa sarata";

	map<Produs_carne, string>::iterator itMap;
	for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
	{
		if (itMap->second=="Peste apa sarata")
		{
			cout << itMap->first;
		}
		
	}
	for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
	{
		if (itMap->second == "Peste apa dulce")
		{
			cout << itMap->first;
		}
	}*/
}