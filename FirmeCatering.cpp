#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<list>
using namespace std;
class IServicii
{
public:
	virtual void ListaEvenimente() = 0;
};
class Eveniment : public IServicii
{
private:
	string numeClient = "Anonim";
	string eveniment = "Anonim";
	string* produseComandate = nullptr;
	int* cantitatiComandate = nullptr;
	int numarProduseComandate = 0;
    list<string> listP;
public:
	static int nrClienti;
public:
	Eveniment()
	{
		
	}
	Eveniment(string numeClient, string eveniment,string* produseComandate,int* cantitatiComandate,int numarProduseComandate)
	{
		if (numeClient.length() > 0)
		{
			this->numeClient = numeClient;
		}
		if (eveniment.length() > 0)
		{
			this->eveniment = eveniment;
		}
		if (produseComandate != nullptr && cantitatiComandate!=nullptr &&  numarProduseComandate>0)
		{
			this->numarProduseComandate = numarProduseComandate;
			this->produseComandate = new string[this->numarProduseComandate];
			this->cantitatiComandate = new int[this->numarProduseComandate];
			
			for (int i = 0; i < this->numarProduseComandate; i++)
			{
				this->produseComandate[i] = produseComandate[i];
				this->cantitatiComandate[i] = cantitatiComandate[i];
				listP.push_back(this->produseComandate[i]);
			}
		}
		
		nrClienti++;
	}
	Eveniment(const Eveniment& f)
	{
		if (f.numeClient.length() > 0)
		{
			this->numeClient = f.numeClient;
		}
		if (f.eveniment.length() > 0)
		{
			this->eveniment = f.eveniment;
		}
		if (f.produseComandate != nullptr && f.cantitatiComandate != nullptr && f.numarProduseComandate > 0)
		{
			this->numarProduseComandate = f.numarProduseComandate;
			this->produseComandate = new string[this->numarProduseComandate];
			this->cantitatiComandate = new int[this->numarProduseComandate];
			
			for (int i = 0; i < this->numarProduseComandate; i++)
			{
				this->produseComandate[i] = f.produseComandate[i];
				this->cantitatiComandate[i] = f.cantitatiComandate[i];
				
			}
		}
	}
	Eveniment& operator=(const Eveniment& f)
	{
		if (this != &f)
		{
			delete[] this->produseComandate;
			this->produseComandate = nullptr;
			delete[] this->cantitatiComandate;
			this->cantitatiComandate = nullptr;
		

			if (f.numeClient.length() > 0)
			{
				this->numeClient = f.numeClient;
			}
			if (f.eveniment.length() > 0)
			{
				this->eveniment = f.eveniment;
			}
			if (f.produseComandate != nullptr && f.cantitatiComandate != nullptr  && f.numarProduseComandate > 0)
			{
				this->numarProduseComandate = f.numarProduseComandate;
				this->produseComandate = new string[this->numarProduseComandate];
				this->cantitatiComandate = new int[this->numarProduseComandate];
				
				for (int i = 0; i < this->numarProduseComandate; i++)
				{
					this->produseComandate[i] = f.produseComandate[i];
					this->cantitatiComandate[i] = f.cantitatiComandate[i];
					
				}
			}
			else
			{
				this->numarProduseComandate =0;
				this->produseComandate = nullptr;
				this->cantitatiComandate =nullptr;
			
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Eveniment& f)
	{
		out << "\n------------------------------";
		out << "\nClient: " << f.numeClient;
		out << "\nEveniment: " << f.eveniment;
		out << "\nNumar produse comandate: " << f.numarProduseComandate;
		out << "\nProduse: " << endl;
		if (f.produseComandate != nullptr && f.numarProduseComandate > 0)
		{
			for (int i = 0; i < f.numarProduseComandate; i++)
			{
				out << f.produseComandate[i]<<endl;
			}
		}
		else
			cout << "-";
		out << "\nCantitati: " << endl;
		if (f.cantitatiComandate != nullptr && f.numarProduseComandate > 0)
		{
			for (int i = 0; i < f.numarProduseComandate; i++)
			{
				out << f.cantitatiComandate[i]<<endl;
			}
		}
		else
			cout << "-";
		
		return out;
	}
	friend ofstream& operator<<(ofstream& out, const Eveniment& f)
	{
		
		out << f.numeClient<<endl;
		out << f.eveniment << endl;
		out  << f.numarProduseComandate << endl;
		if (f.produseComandate != nullptr && f.numarProduseComandate > 0)
		{
			for (int i = 0; i < f.numarProduseComandate; i++)
			{
				out << f.produseComandate[i] << endl;
			}
		}
		if (f.cantitatiComandate != nullptr && f.numarProduseComandate > 0)
		{
			for (int i = 0; i < f.numarProduseComandate; i++)
			{
				out << f.cantitatiComandate[i] << endl;
			}
		}
		
		return out;
	}
	
	~Eveniment()
	{
		delete[] this->produseComandate;
		this->produseComandate = nullptr;
		delete[] this->cantitatiComandate;
		this->cantitatiComandate = nullptr;
		
	}
	string operator[](int index)
	{
		if (this->produseComandate != nullptr && this->numarProduseComandate > 0)
		{
			for (int i = 0; i < this->numarProduseComandate; i++)
			{
				return this->produseComandate[index];
			}
		}
	}
	Eveniment& operator+=(string produs)
	{
		if (this->cantitatiComandate != nullptr && this->produseComandate != nullptr && this->numarProduseComandate > 0)
		{
			Eveniment f = *this;
			string* temp = new string[f.numarProduseComandate + 1];
			int* temp1 = new int[f.numarProduseComandate + 1];
			for (int i = 0; i < this->numarProduseComandate; i++)
			{
				if (f.produseComandate[i]!=produs)
				{
					temp[i] = f.produseComandate[i];
					temp1[i] = f.cantitatiComandate[i];
				}
			}
			for (int i = 0; i < this->numarProduseComandate; i++)
			{
				if (f.produseComandate[i] == produs)
				{
					this->cantitatiComandate[i] += 100;
					return *this;
				}
			}
			listP.push_back(produs);
			temp[f.numarProduseComandate] = produs;
			temp1[f.numarProduseComandate] = 100;
			delete[] this->produseComandate;
			this->produseComandate = nullptr;
			delete[] this->cantitatiComandate;
			this->cantitatiComandate = nullptr;
			this->produseComandate = temp;
			this->cantitatiComandate = temp1;
			this->numarProduseComandate++;
			return *this;
		}
	}
	string getEveniment()
	{
		return this->eveniment;
	}
	friend bool operator<(const Eveniment& e1, const Eveniment& e2)
	{
		return e1.numarProduseComandate < e2.numarProduseComandate;
	}
	void afisare()
	{
		list<string>::iterator itList;
		for (itList=listP.begin();itList!=listP.end();itList++)
		{
			cout << *itList << " ";
		}
	}
	void stergere(string produs)
	{
		list<string>::iterator itList;
		for (itList = listP.begin(); itList != listP.end(); itList++)
		{
			if (*itList == produs)
			{
				itList=listP.erase(itList);
				break;
			}
			
		}
		for (itList = listP.begin(); itList != listP.end(); itList++)
		{
			cout << *itList << " ";
		}
	}
	void ListaEvenimente()
	{
		cout<< this->eveniment;
	}
};
int Eveniment::nrClienti = 0;

class FirmaCatering: public IServicii
{
	Eveniment** evenimente = nullptr;
	int nrEvenimente = 0;
public:
	FirmaCatering()
	{

	}
	FirmaCatering(Eveniment** evenimente, int nrEvenimente)
	{
		if (evenimente != nullptr && nrEvenimente > 0)
		{
			this->nrEvenimente = nrEvenimente;
			this->evenimente = new Eveniment*[this->nrEvenimente];
			for (int i = 0; i < this->nrEvenimente; i++)
			{
				this->evenimente[i] = new Eveniment(*evenimente[i]);
			}
		}
	}
	FirmaCatering(const FirmaCatering& f)
	{
		if (f.evenimente != nullptr && f.nrEvenimente > 0)
		{
			this->nrEvenimente = f.nrEvenimente;
			this->evenimente = new Eveniment * [this->nrEvenimente];
			for (int i = 0; i < this->nrEvenimente; i++)
			{
				this->evenimente[i] = new Eveniment(*f.evenimente[i]);
			}
		}
	}
	FirmaCatering& operator=(const FirmaCatering& f)
	{
		if (this != &f)
		{
			for (int i = 0; i < this->nrEvenimente; i++)
			{
				delete this->evenimente[i];
				this->evenimente[i] = nullptr;
			}
			delete[] this->evenimente;
			this->evenimente = nullptr;
			if (f.evenimente != nullptr && f.nrEvenimente > 0)
			{
				this->nrEvenimente = f.nrEvenimente;
				this->evenimente = new Eveniment * [this->nrEvenimente];
				for (int i = 0; i < this->nrEvenimente; i++)
				{
					this->evenimente[i] = new Eveniment(*f.evenimente[i]);
				}
			}
			else
			{
				this->nrEvenimente = 0;
				this->evenimente = nullptr;
			}

		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const FirmaCatering& f)
	{
		out << "\n---------------------------------";
		out << "\nNumar evenimente: " << f.nrEvenimente;
		out << "\nEvenimente: ";
		if (f.evenimente != nullptr && f.nrEvenimente > 0)
		{
			for (int i = 0; i < f.nrEvenimente; i++)
			{
				out << *f.evenimente[i];
			}
		}
		return out;
	}
	friend ofstream& operator<<(ofstream& out, const FirmaCatering& f)
	{
		
		out << f.nrEvenimente;
		if (f.evenimente != nullptr && f.nrEvenimente > 0)
		{
			for (int i = 0; i < f.nrEvenimente; i++)
			{
				out << *f.evenimente[i];
			}
		}
		return out;
	}
	void ScrieInFisierText(string eveniment)
	{
		if (this->evenimente != nullptr && this->nrEvenimente > 0)
		{
			ofstream g("fisier_evenimente.txt");
			for (int i = 0; i < this->nrEvenimente; i++)
			{
				if (this->evenimente[i]->getEveniment() == eveniment)
				{
					g << *this->evenimente[i];
				}
			}
			g.close();
		}
	}
	~FirmaCatering()
	{
		for (int i = 0; i < this->nrEvenimente; i++)
		{
			delete this->evenimente[i];
			this->evenimente[i] = nullptr;
		}
		delete[] this->evenimente;
		this->evenimente = nullptr;
	}
	 void ListaEvenimente()
	{
		string* evenimente = new string[this->nrEvenimente];
		if (this->evenimente != nullptr && this->nrEvenimente > 0)
		{
			for (int i = 0; i < this->nrEvenimente; i++)
			{
				evenimente[i] = this->evenimente[i]->getEveniment();
				
			}
			for (int i = 0; i < this->nrEvenimente; i++)
			{
				cout << evenimente[i] << " ";
			}
		}
		
	}
};
int main()
{
	cout << "\nConstructori fara parametrii: ";
	Eveniment f1;
	cout << f1;

	cout << "\nConstructori cu parametrii: ";
	string produseComandate1[] = {"Meniuri de nunta","Servicii bauturi","Servicii suplimentare chelneri","Bufet desert"};
	int cantitatiComandate1[] = { 100,80,1,2 };

	Eveniment f2("Dulica Denisa","nunta",produseComandate1,cantitatiComandate1,4);
	cout << f2;

	cout <<endl<< "\nConstructori cu parametrii: ";
	string produseComandate2[] = { "Meniuri de botez","Servicii bauturi","Bufet desert" };
	int cantitatiComandate2[] = { 80,40,1 };
	
	Eveniment f3("Cristescu Sara", "botez", produseComandate2, cantitatiComandate2, 3);
	cout << f3;

	cout <<endl<< "\nConstructori copy: ";
	Eveniment f4 = f2;
	cout << f4;

	cout << endl << "\nOp = ";
	Eveniment f5;
		f5= f2;
	cout << f5;

	cout << endl << "\nAtribut static: ";
	cout << Eveniment::nrClienti;

	cout<<"\nProdusul comandat: " << f2[1];
	string produs="Aperitiv";
	f2 += produs;
	cout << f2;

	Eveniment* evenimente[] = { &f2,&f3 };
	FirmaCatering firma1(evenimente, 2);
	cout << firma1;

	firma1.ScrieInFisierText("nunta");
	cout << "\nVirtualizare cls derivata firma: ";
	IServicii* servicii = &firma1;
	servicii->ListaEvenimente();
	cout << "\nVirtualizare cls derivata even: ";
	IServicii* servicii1 = &f2;
	servicii1->ListaEvenimente();
	
	
	cout << endl;
	f2.afisare();
	cout << endl;
	f2.stergere("Aperitiv");
}