#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
enum Pompa
{
	POMPA_STANGA,POMPA_DREAPTA
};
class Exception
{
	string mesaj;
public:
	Exception()
	{
		this->mesaj = "\nNu se cunoaste";
	}
	Exception(string mesaj)
	{
		this->mesaj = mesaj;
	}
	Exception(const Exception& e)
	{
		this->mesaj = e.mesaj;
	}
	string getMesaj()
	{
		return this->mesaj;
	}
	~Exception() {}
};
class Rezervor_combustibil
{
	char* tipCombustibil = nullptr;
	float capacitateRezervor = 0;
	float capacitateMaxima = 0;
	float pret_litru = 0;
	bool rezervor_gol = 0;
	static int nrRezervoare;
	Pompa pompa = POMPA_DREAPTA;
public:
	Rezervor_combustibil()
	{
		this->tipCombustibil = new char[strlen("Anonim") + 1];
		strcpy(this->tipCombustibil, "Anonim");
	}
	Rezervor_combustibil(const char* tipCombustibil, float capacitateRezervor,float capacitateMaxima, float pret_litru, bool rezervor_gol, Pompa pompa)
	{
		if (tipCombustibil != nullptr && strlen(tipCombustibil) > 0)
		{
			this->tipCombustibil = new char[strlen(tipCombustibil) + 1];
			strcpy(this->tipCombustibil, tipCombustibil);
		}
		else
		{
			this->tipCombustibil = new char[strlen("Anonim") + 1];
			strcpy(this->tipCombustibil, "Anonim");
		}
		if (capacitateRezervor > 0)
		{
			this->capacitateRezervor = capacitateRezervor;
		}
		if (capacitateMaxima > 0)
		{
			this->capacitateMaxima = capacitateMaxima;
		}
		if (pret_litru > 0)
		{
			this->pret_litru = pret_litru;
		}
		this->rezervor_gol = rezervor_gol;
		this->pompa = pompa;
		nrRezervoare++;
	}
	Rezervor_combustibil(const Rezervor_combustibil& r)
	{
		if (r.tipCombustibil != nullptr && strlen(r.tipCombustibil) > 0)
		{
			this->tipCombustibil = new char[strlen(r.tipCombustibil) + 1];
			strcpy(this->tipCombustibil, r.tipCombustibil);
		}
		else
		{
			this->tipCombustibil = new char[strlen("Anonim") + 1];
			strcpy(this->tipCombustibil, "Anonim");
		}
		if (r.capacitateRezervor > 0)
		{
			this->capacitateRezervor = r.capacitateRezervor;
		}
		if (r.capacitateMaxima > 0)
		{
			this->capacitateMaxima = r.capacitateMaxima;
		}
		if (r.pret_litru > 0)
		{
			this->pret_litru = r.pret_litru;
		}
		this->pompa = r.pompa;
		this->rezervor_gol = r.rezervor_gol;
	}
	Rezervor_combustibil& operator=(const Rezervor_combustibil& r)
	{
		if (this != &r)
		{
			delete[] this->tipCombustibil;
			this->tipCombustibil = nullptr;
			if (r.tipCombustibil != nullptr && strlen(r.tipCombustibil) > 0)
			{
				this->tipCombustibil = new char[strlen(r.tipCombustibil) + 1];
				strcpy(this->tipCombustibil, r.tipCombustibil);
			}
			else
			{
				this->tipCombustibil = new char[strlen("Anonim") + 1];
				strcpy(this->tipCombustibil, "Anonim");
			}
			if (r.capacitateRezervor > 0)
			{
				this->capacitateRezervor = r.capacitateRezervor;
			}
			if (r.capacitateMaxima > 0)
			{
				this->capacitateMaxima = r.capacitateMaxima;
			}
			if (r.pret_litru > 0)
			{
				this->pret_litru = r.pret_litru;
			}
			this->pompa = r.pompa;
			this->rezervor_gol = r.rezervor_gol;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Rezervor_combustibil& r)
	{
		out << "\n-----------------------";
		out << "\nTip combustibil: " << r.tipCombustibil;
		out << "\nCapacitate rezervor: " << r.capacitateRezervor;
		out << "\nCapacitate maxima: " << r.capacitateMaxima;
		out << "\nPret pe litru combustibil: " << r.pret_litru;
		out << "\nRezervor gol? " << r.rezervor_gol;
		out << "\nTip pompa: ";
		switch (r.pompa)
		{
		case 0:out << "\nPompa pe stanga";
			break;
		case 1:out << "\nPompa pe dreapta";
			break;
		default:out<< "\nPompa pe dreapta";
			break;
		}
		return out;
	}
	friend istream& operator>>(istream& in, Rezervor_combustibil& r)
	{
		delete[] r.tipCombustibil;
		r.tipCombustibil = nullptr;

		cout << "\nIntroduceti tipul de combustibil: ";
		string buffer;
		in >> ws;
		getline(in, buffer);
		r.tipCombustibil = new char[buffer.size() + 1];
		strcpy(r.tipCombustibil, buffer.data());
		cout << "\nIntroduceti capacitatea rezervorului: ";
		in >> r.capacitateRezervor;
		cout << "\nIntroduceti capacitatea maxima: ";
		in >> r.capacitateMaxima;
		cout << "\nIntroduceti pretul pe litru: ";
		in >> r.pret_litru;
		cout << "Rezervor gol? da-1 nu-0";
		in >> r.rezervor_gol;
		cout << "\nTip pompa D/S: ";
		string buffer1;
		in >> ws;
		getline(in, buffer1);
		if (buffer1 == "D")
		{
			r.pompa = POMPA_DREAPTA;
		}
		if (buffer1 == "S")
		{
			r.pompa = POMPA_STANGA;
		}
		return in;
	}
	~Rezervor_combustibil()
	{
		delete[] this->tipCombustibil;
		this->tipCombustibil = nullptr;
	}
	Rezervor_combustibil& operator+=(float valoare)
	{
		if (this->capacitateMaxima > 0 && this->capacitateRezervor >= 0)
		{
			
			if (this->capacitateRezervor + valoare <= this->capacitateMaxima)
			{
				this->capacitateRezervor += valoare;
			}
			else
				throw Exception("\nValoare prea mare");
			return *this;
		}
	}
	bool operator!()
	{
		if (this->rezervor_gol == 0)
			return true;
		return false;
	}
	Rezervor_combustibil& operator-=(float valoare)
	{
		
		if (this->rezervor_gol == 0 && this->capacitateRezervor>0 && this->capacitateMaxima>0)
		{
			if (this->capacitateRezervor > valoare)
			{
				this->capacitateRezervor -= valoare;
				if (this->capacitateRezervor == 0)
				{
					this->rezervor_gol = 1;
				}
				
			}
			else
			{
				throw exception("\nCantitate valoare");
			}
			return *this;
		}
	}
	void raport(float valoare)
	{
		fstream f("raport.txt", ios::out | ios::app);
		f << this->tipCombustibil << " : " << this->pret_litru * valoare << " lei" << endl;
		f.close();
	}
	bool operator>(const Rezervor_combustibil& r)
	{
		return this->capacitateRezervor > r.capacitateRezervor;
	}
};
int Rezervor_combustibil::nrRezervoare = 0;
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
}
int main()
{
	cout << "\nCons implicit: " << endl;
	Rezervor_combustibil r1;
	cout << r1;
	cout << "\nCons cu parametrii: " << endl;
	Rezervor_combustibil r2("Motorina", 500,1000, 6, 0, POMPA_DREAPTA);
	cout << r2;
	Rezervor_combustibil r3("Benzina", 600,900, 7, 0, POMPA_STANGA);
	cout << r3;
	cout << "\nCons copy: ";
	Rezervor_combustibil r4 = r2;
	cout << r4;
	cout << "\nOp = ";
	Rezervor_combustibil r5;
	r5 = r2;
	cout << r5;

	cout << "\nOperator +="<<endl;
	
	int ok = 0;
		try
		{
			r2 += 800;
			cout << r2;
			
			ok = 1;
		}
		catch (Exception ex)
		{
			cout << ex.getMesaj();
			ok = 0;
		}
   
		if (!r2)
		{
			cout << "\nRezervorul nu e gol";
		}
		else
			cout<< "\nRezervorul este gol";

		cout << "\nOperator -=" << endl;
		try
		{
			r2 -= 20;
			r2.raport(20);
			cout << r2;
		}
		catch(Exception ex)
		{ 
			cout << ex.getMesaj();
		}
		sortare<Rezervor_combustibil>(r2, r3);
		cout << r2 << endl << r3;
		
	
}