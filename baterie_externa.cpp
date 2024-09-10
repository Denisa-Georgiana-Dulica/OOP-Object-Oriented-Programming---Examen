#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<fstream>
#include<map>
#include<set>
using namespace std;


class BaterieExterna
{
private:
    char* producator = nullptr;
protected:

	float nivelBaterie = 0;
	float capacitate = 0; //nr amperi
	string* tipuriI_O = nullptr;
	int nrI_O = 0;
	static int nivelMaxBaterie;

public:
	BaterieExterna()
	{
		this->producator = new char[strlen("Anonim") + 1];
		strcpy(this->producator, "Anonim");
	}
	BaterieExterna(const char* producator, float nivelBaterie,float capacitate,string* tipuriI_O, int nrI_O)
	{
		if (strlen(producator) > 0 && producator!=nullptr)
		{
			this->producator = new char[strlen(producator)+1];
			strcpy(this->producator, producator);
		}
		else
		{
			this->producator = new char[strlen("Anonim") + 1];
			strcpy(this->producator, "Anonim");
		}
		if (nivelBaterie >= 0 && nivelBaterie <= 1)
		{
			this->nivelBaterie = nivelBaterie;
		}
		if (capacitate > 0)
		{
			this->capacitate = capacitate;
		}
		if (tipuriI_O != nullptr && nrI_O>0)
		{
			this->nrI_O = nrI_O;
			this->tipuriI_O = new string[this->nrI_O];
			for (int i = 0; i < this->nrI_O; i++)
			{
				this->tipuriI_O[i] = tipuriI_O[i];
			}
		}
	}
	BaterieExterna(const BaterieExterna& b)
	{
		if (strlen(b.producator) > 0 && b.producator != nullptr)
		{
			this->producator = new char[strlen(b.producator) + 1];
			strcpy(this->producator, b.producator);
		}
		
		if (b.nivelBaterie >= 0 && b.nivelBaterie <= 1)
		{
			this->nivelBaterie = b.nivelBaterie;
		}
		if (b.capacitate > 0)
		{
			this->capacitate = b.capacitate;
		}
		if (b.tipuriI_O != nullptr && b.nrI_O > 0)
		{
			this->nrI_O = b.nrI_O;
			this->tipuriI_O = new string[this->nrI_O];
			for (int i = 0; i < this->nrI_O; i++)
			{
				this->tipuriI_O[i] = b.tipuriI_O[i];
			}
		}
	}
	BaterieExterna& operator=(const BaterieExterna& b)
	{
		if (this != &b)
		{
			delete[] this->producator;
			this->producator = nullptr;
			delete[] this->tipuriI_O;
			this->tipuriI_O = nullptr;
			if (strlen(b.producator) > 0 && b.producator != nullptr)
			{
				this->producator = new char[strlen(b.producator) + 1];
				strcpy(this->producator, b.producator);
			}
			else
			{
				this->producator = new char[strlen("Anonim") + 1];
				strcpy(this->producator, "Anonim");
			}
			if (b.nivelBaterie >= 0 && b.nivelBaterie <= 1)
			{
				this->nivelBaterie = b.nivelBaterie;
			}
			if (b.capacitate > 0)
			{
				this->capacitate = b.capacitate;
			}
			if (b.tipuriI_O != nullptr && b.nrI_O > 0)
			{
				this->nrI_O = b.nrI_O;
				this->tipuriI_O = new string[this->nrI_O];
				for (int i = 0; i < this->nrI_O; i++)
				{
					this->tipuriI_O[i] = b.tipuriI_O[i];
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const BaterieExterna& b)
	{
		out << "\n-----------------------------";
		out << "\nDenumire producator: "<< b.producator;
		out << "\nNivel baterie: " << b.nivelBaterie;
		out << "\nCapacitate: " << b.capacitate;
		out << "\nNr I_O: " << b.nrI_O;
		if (b.tipuriI_O != nullptr && b.nrI_O>0)
		{
			out << "\nTipuri I_O: "<<endl;
			for (int i = 0; i < b.nrI_O; i++)
			{
				out << b.tipuriI_O[i] << endl;
			}
		}
		
		return out;
	}
	
	~BaterieExterna()
	{
		delete[] this->producator;
		this->producator = nullptr;
		delete[] this->tipuriI_O;
		this->tipuriI_O = nullptr;
	}
	float getNivelBaterie()
	{
		return this->nivelBaterie;
	}
	void setNivelBaterie(float nivelBaterie)
	{
		if (nivelBaterie >= 0 && nivelBaterie <= 1)
		{
			this->nivelBaterie = nivelBaterie;
		}
		else
			this->nivelBaterie = 0;
	}

   void operator+=(float incarcare)
	{
		if (incarcare >= 0 && incarcare <= 1 && this->nivelBaterie >= 0 && this->nivelBaterie <= 1)
		{
			float max = nivelMaxBaterie - this->nivelBaterie;
			if (incarcare<=max)
			{
				this->nivelBaterie += incarcare;
				cout << "\nNivel baterie nou: "<<this->nivelBaterie;
			}
			else
			{
				this->nivelBaterie += max;
				cout << "\nBaterie incarcata 100%";
			}
			
		}
	}

   void operator-=(float descarcare)
   {
	   if (descarcare >= 0 && descarcare <= 1 && this->nivelBaterie >= 0 && this->nivelBaterie <= 1)
	   {
		   if (descarcare <= this->nivelBaterie)
		   {
			   this->nivelBaterie -= descarcare;
			   cout << "\nNivel baterie nou (descarcare): " << this->nivelBaterie;
		   }
		   else
		   {
			   this->nivelBaterie =0;
			   cout << "\nBaterie descarcata total";
		   }

	   }
   }
   bool operator==(const BaterieExterna& b)
   {
	   if (this != &b)
	   {
		   if (strcmp(this->producator, b.producator)==0 && this->nivelBaterie == b.nivelBaterie && this->capacitate == b.capacitate  && this->nrI_O == b.nrI_O)
		   {
			   for (int i = 0; i < this->nrI_O; i++)
			   {
				   if(this->tipuriI_O[i]==b.tipuriI_O[i])
					   return true;
			   }
			
		   }
		   return false;
	   }
   }
   virtual float Capacitate()
   {
	   return this->capacitate;
   }
   bool operator>(const BaterieExterna& b1)
   {
	   return this->capacitate > b1.capacitate;
   }
 
};
int BaterieExterna::nivelMaxBaterie = 1;


class DispozitivPortabil:public BaterieExterna
{
private:
	float capSuplimentara = 0;
	bool esteWireless = 0; //0 - false 
public:
	DispozitivPortabil():BaterieExterna()
	{

	}
	DispozitivPortabil(const char* producator, float nivelBaterie, float capacitate, string* tipuriI_O, int nrI_O, float capSuplimentara, bool esteWireless) :BaterieExterna(producator, nivelBaterie, capacitate, tipuriI_O, nrI_O)
	{
		if (capSuplimentara > 0)
		{
			this->capSuplimentara = capSuplimentara;
		}
		this->esteWireless = esteWireless;
	}
	DispozitivPortabil(const DispozitivPortabil& d):BaterieExterna(d)
	{
		if (d.capSuplimentara > 0)
		{
			this->capSuplimentara = d.capSuplimentara;
		}
		this->esteWireless = d.esteWireless;
	}
	DispozitivPortabil& operator=(const DispozitivPortabil& d)
	{
		this->BaterieExterna::operator=(d);
		if (this != &d)
		{
			if (d.capSuplimentara > 0)
			{
				this->capSuplimentara = d.capSuplimentara;
			}
			this->esteWireless = d.esteWireless;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const DispozitivPortabil& d)
	{
		out << (BaterieExterna&)d;
		out << "\nCapacitate suplimentara: " << d.capSuplimentara;
		out << "\nEste wireless? " << d.esteWireless;
		return out;
	}
	~DispozitivPortabil() {}
	float Capacitate()
	{
		float cap =BaterieExterna::Capacitate();
		cap += this->capSuplimentara;
		return cap;

	}
};
template <class TIP>
void sorteaza(TIP a, TIP b)
{
	TIP aux;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (a > b)
			{
				aux = a;
				a = b;
				b = aux;
			}
		}
	}
}
int main()
{
	BaterieExterna b1;
	cout << b1;

	string tipuriI_O[] = { "USB C","USB" };
	BaterieExterna b2("Sony",0.5,1000,tipuriI_O,2);
	cout << b2;

	BaterieExterna b3("Samsung", 1, 2000, tipuriI_O, 2);
	cout << b3;

	cout << "\nConstructor copy";
	BaterieExterna b4 = b2;
	cout << b4;

	cout << "\nOp =";
	BaterieExterna b5;
	b5 = b2;
	cout << b5;

	cout << "\nGET / SET";
	cout <<"\nNivel baterie initial: " << b5.getNivelBaterie();
	b5.setNivelBaterie(1);
	cout << "\nNivel baterie dupa: " << b5.getNivelBaterie();

	cout << endl << "\nIncarcare: ";
	b2 += 0.5;
	b3 += 0.3;

	//cout << endl << "\nDescarcare: ";
	//b2 -= 0.4;
	//b3 -= 1;
	
	if (b2 == b5)
	{
		cout << "\nBaterii identice";
	}
	else
		cout << "\nNu sunt identice";

	cout << "\nDISPOZITIV PORTABIL";
	DispozitivPortabil d1;
	cout << d1;

	DispozitivPortabil d2("JVL", 0.6, 1000, tipuriI_O, 2, 1000, 1);
	cout << d2;

	cout << "\nConstructor copy";
	DispozitivPortabil d3 = d2;
	cout << d3;

	cout << "\nOp =";
	DispozitivPortabil d4;
	d4 = d2;
	cout << d4;

	
	BaterieExterna* lista[10];
	lista[0] = &b2;
	lista[1] = &b3;
	lista[2] = &d2;
	cout << "\nCapacitate totala a dispozitivelor:"<<endl;
	float suma = 0;
	for (int i = 0; i < 3; i++)
	{
		suma += lista[i]->Capacitate();
	}
	cout << suma;

	int a = 3;
	int b= 1;
	sorteaza(a, b);
	cout << endl;
	cout << a << " "<<b;

	cout << endl;
	sorteaza<BaterieExterna>(b3, b2);
	cout << b3.Capacitate() << " " << b2.Capacitate();
	
}