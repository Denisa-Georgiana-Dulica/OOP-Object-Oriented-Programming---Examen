#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class IAmortizabil
{
public:
	virtual float getAmortizare() = 0;
};
class Vehicul
{
	const int id;
protected:
	char* tipVehicul = nullptr;
	int nrLocuri = 0;
	int valoareInventar = 0;
public:
	
	
	Vehicul() :id(0)
	{
		this->tipVehicul = new char[strlen("Anonim") + 1];
		strcpy(this->tipVehicul, "Anonim");
	}
	Vehicul(int id, const char* tipVehicul, int nrLocuri, int valoareInventar) :id(id)
	{
		if (tipVehicul != nullptr && strlen(tipVehicul) > 0)
		{
			this->tipVehicul = new char[strlen(tipVehicul) + 1];
			strcpy(this->tipVehicul, tipVehicul);
		}
		else
		{
			this->tipVehicul = new char[strlen("Anonim") + 1];
			strcpy(this->tipVehicul, "Anonim");
		}
		if (nrLocuri > 0)
		{
			this->nrLocuri = nrLocuri;
		}
		if (valoareInventar > 0)
		{
			this->valoareInventar = valoareInventar;
		}
	}
	Vehicul(const Vehicul& v) :id(v.id)
	{
		if (v.tipVehicul != nullptr && strlen(v.tipVehicul) > 0)
		{
			this->tipVehicul = new char[strlen(v.tipVehicul) + 1];
			strcpy(this->tipVehicul, v.tipVehicul);
		}
		else
		{
			this->tipVehicul = new char[strlen("Anonim") + 1];
			strcpy(this->tipVehicul, "Anonim");
		}
		if (v.nrLocuri > 0)
		{
			this->nrLocuri = v.nrLocuri;
		}
		if (v.valoareInventar > 0)
		{
			this->valoareInventar = v.valoareInventar;
		}
	}
	Vehicul& operator=(const Vehicul& v)
	{
		if (this != &v)
		{
			delete[] this->tipVehicul;
			this->tipVehicul = nullptr;
			if (v.tipVehicul != nullptr && strlen(v.tipVehicul) > 0)
			{
				this->tipVehicul = new char[strlen(v.tipVehicul) + 1];
				strcpy(this->tipVehicul, v.tipVehicul);
			}
			else
			{
				this->tipVehicul = new char[strlen("Anonim") + 1];
				strcpy(this->tipVehicul, "Anonim");
			}
			if (v.nrLocuri > 0)
			{
				this->nrLocuri = v.nrLocuri;
			}
			if (v.valoareInventar > 0)
			{
				this->valoareInventar = v.valoareInventar;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Vehicul& v)
	{
		out << "\nId: " << v.id;
		out << "\nTip vehicul: " << v.tipVehicul;
		out << "\nNr locuri: " << v.nrLocuri;
		out << "\nValoare inventar: " << v.valoareInventar;
		return out;
	}
	~Vehicul()
	{
		delete[] this->tipVehicul;
		this->tipVehicul = nullptr;
	}
	const int getId()
	{
		return this->id;
	}
	virtual void Tip()
	{
		cout << "\nAcesta este un vehicul";
	}
};
class Autobuz:public Vehicul, public IAmortizabil
{
	float capacitateC = 0;
public:
	Autobuz() :Vehicul()
	{

	}
	Autobuz(int id, const char* tipVehicul, int nrLocuri, int valoareInventar,float capacitateC) :Vehicul(id, tipVehicul,nrLocuri, valoareInventar)
	{
		if (capacitateC > 0)
		{
			this->capacitateC = capacitateC;
		}
	}
	Autobuz(Vehicul v, float capacitateC) :Vehicul(v)
	{
		if (capacitateC > 0)
		{
			this->capacitateC = capacitateC;
		}
	}
	Autobuz(const Autobuz& a):Vehicul(a)
	{
		if (a.capacitateC > 0)
		{
			this->capacitateC = a.capacitateC;
		}
	}
	Autobuz(const Vehicul& a) :Vehicul(a)
	{
		
			this->capacitateC = 300;
		
	}
	Autobuz& operator=(const Autobuz& a)
	{
		this->Vehicul::operator=(a);
		if (this != &a)
		{
			if (a.capacitateC > 0)
			{
				this->capacitateC = a.capacitateC;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Autobuz& a)
	{
		out << (Vehicul&)a;
		out << "\nCapacitate cilindrica: " << a.capacitateC;
		return out;
	}
	~Autobuz() {}
	float getAmortizare()
	{
		return 0.1 * this->valoareInventar;
	}
	 void Tip()
	{
		cout << "\nAcesta este un autobuz";
	}
};
class Tramvai :protected Vehicul, public IAmortizabil
{
	int nrVagoane = 0;
public:
	Tramvai() :Vehicul()
	{

	}
	Tramvai(int id, const char* tipVehicul, int nrLocuri, int valoareInventar, int nrVagoane) :Vehicul(id, tipVehicul, nrLocuri, valoareInventar)
	{
		if (nrVagoane > 0)
		{
			this->nrVagoane = nrVagoane;
		}
	}
	Tramvai(Vehicul v, int nrVagoane) :Vehicul(v)
	{
		if (nrVagoane > 0)
		{
			this->nrVagoane = nrVagoane;
		}
	}
	Tramvai(const Tramvai& a) :Vehicul(a)
	{
		if (a.nrVagoane > 0)
		{
			this->nrVagoane = a.nrVagoane;
		}
	}
	Tramvai(const Vehicul& a) :Vehicul(a)
	{
		
			this->nrVagoane =2;
		
	}
	Tramvai& operator=(const Tramvai& a)
	{
		this->Vehicul::operator=(a);
		if (this != &a)
		{
			if (a.nrVagoane > 0)
			{
				this->nrVagoane = a.nrVagoane;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Tramvai& a)
	{
		out << (Vehicul&)a;
		out << "\nNr vagoane: " << a.nrVagoane;
		return out;
	}
	~Tramvai() {}
	float getAmortizare()
	{
		return 0.12 * this->valoareInventar;
	}

};
class Troleibuz :private Vehicul, public IAmortizabil
{
	int putere = 0;
public:
	Troleibuz() :Vehicul()
	{

	}
	Troleibuz(int id, const char* tipVehicul, int nrLocuri, int valoareInventar, int putere) :Vehicul(id, tipVehicul, nrLocuri, valoareInventar)
	{
		if (putere > 0)
		{
			this->putere = putere;
		}
	}
	Troleibuz(Vehicul v, int putere) :Vehicul(v)
	{
		if (putere > 0)
		{
			this->putere = putere;
		}
	}
	Troleibuz(const Troleibuz& a) :Vehicul(a)
	{
		if (a.putere > 0)
		{
			this->putere = a.putere;
		}
	}
	Troleibuz(const Vehicul& a) :Vehicul(a)
	{
		
			this->putere = 2000;
		
	}
	Troleibuz& operator=(const Troleibuz& a)
	{
		this->Vehicul::operator=(a);
		if (this != &a)
		{
			if (a.putere > 0)
			{
				this->putere = a.putere;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Troleibuz& a)
	{
		out << (Vehicul&)a;
		out << "\nPutere kw: " << a.putere;
		return out;
	}
	~Troleibuz() {}
	float getAmortizare()
	{
		return 0.08 * this->valoareInventar;
	}

};

class Parc_auto
{
	Vehicul** vehicule = nullptr;
	int nrVehicule = 0;
public:
	Parc_auto()
	{

	}
	Parc_auto(Vehicul** vehicule, int nrVehicule)
	{
		if (vehicule != nullptr && nrVehicule > 0)
		{
			this->nrVehicule = nrVehicule;
			this->vehicule = new Vehicul * [this->nrVehicule];
			for (int i = 0; i < this->nrVehicule; i++)
			{
				this->vehicule[i] = new Vehicul(*vehicule[i]);
			}
		}
	}
	Parc_auto(const Parc_auto& p)
	{
		if (p.vehicule != nullptr && p.nrVehicule > 0)
		{
			this->nrVehicule = p.nrVehicule;
			this->vehicule = new Vehicul * [this->nrVehicule];
			for (int i = 0; i < this->nrVehicule; i++)
			{
				this->vehicule[i] = new Vehicul(*p.vehicule[i]);
			}
		}
	}
	Parc_auto& operator=(const Parc_auto& p)
	{
		if (this != &p)
		{
			for (int i = 0; i < this->nrVehicule; i++)
			{
				delete this->vehicule[i];
				this->vehicule[i] = nullptr;
			}
			delete[] this->vehicule;
			this->vehicule = nullptr;
			if (p.vehicule != nullptr && p.nrVehicule > 0)
			{
				this->nrVehicule = p.nrVehicule;
				this->vehicule = new Vehicul * [this->nrVehicule];
				for (int i = 0; i < this->nrVehicule; i++)
				{
					this->vehicule[i] = new Vehicul(*p.vehicule[i]);
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Parc_auto& p)
	{
		out << "\nNr vehicule: " << p.nrVehicule;
		if (p.vehicule != nullptr && p.nrVehicule > 0)
		{
			cout << "\nVehicule: " << endl;
			for (int i = 0; i < p.nrVehicule; i++)
			{
				out << *p.vehicule[i];
			}
		}
		else
			cout << "\nVehicule:- " << endl;
		return out;
	}
	~Parc_auto()
	{
		for (int i = 0; i < this->nrVehicule; i++)
		{
			delete this->vehicule[i];
			this->vehicule[i] = nullptr;
		}
		delete[] this->vehicule;
		this->vehicule = nullptr;
	}

	Parc_auto& operator+=(Vehicul& v)
	{
		Parc_auto pa = *this;
		Vehicul** temp = new Vehicul * [pa.nrVehicule + 1];
		int ok = 0;
		for (int i = 0; i < pa.nrVehicule; i++)
		{
			if (pa.vehicule[i]->getId() != v.getId())
			{
				ok = 1;
			}
			if (ok == 1)
			{
				temp[i] = new Vehicul(*pa.vehicule[i]);
			}
			
			
		}
		if (ok == 0)
		{
			return *this;
		}
		temp[pa.nrVehicule] = new Vehicul(v);
		for (int j = 0; j < this->nrVehicule; j++)
		{
			delete this->vehicule[j];
			this->vehicule[j] = nullptr;
		}
		delete[] this->vehicule;
		this->vehicule = nullptr;
		this->vehicule = temp;
		this->nrVehicule++;
		return *this;
	}
	Parc_auto& operator-=(int id)
	{
		if (this->vehicule != nullptr && this->nrVehicule > 0)
		{
			for (int i = 0; i < this->nrVehicule; i++)
			{
				if (this->vehicule[i]->getId() == id)
				{
					for (int j = i; j < this->nrVehicule; j++)
					{
						this->vehicule[j] = this->vehicule[j + 1];
					}
					this->nrVehicule--;
				}
			}
			return *this;
		}
	}
};
int main()
{
	cout << "\nCons imp: ";
	Vehicul v1;
	cout << v1;
	cout <<endl<< "\nCons parametrii: ";
	Vehicul v2(1, "Public", 20, 200);
	cout << v2;
	cout << endl << "\nCons parametrii: ";
	Vehicul v3(2, "Pe sine", 25, 300);
	cout << v3;
	cout << endl << "\nCons parametrii: ";
	Vehicul v4(3, "Public", 40, 400);
	cout << v4;

	cout << endl << "\nCons copy: ";
	Vehicul v5=v4;
	cout << v5;

	cout << endl << "\nop = ";
	Vehicul v6;
	v6= v4;
	cout << v6;

	

	cout << endl << "\nAutobuz" << endl;
	cout << "\nCons imp: ";
	Autobuz a1;
	cout << a1;

	cout << endl << "\nCons parametrii: ";
	Autobuz a2(3, "Public", 20, 150, 200);
	cout << a2;

	cout << endl << "\nCons parametrii: ";
	Autobuz a3(v2, 340);
	cout << a3;

	cout << endl << "\nCons copy: ";
	Autobuz a4 = a2;
	cout << a4;

	cout << endl << "\nop = ";
	Autobuz a5;
	a5= a2;
	cout << a5;

	cout << endl<<"\nDown cast AUTOBUZ: ";
	Autobuz a6 = v2;
	cout << a6;

	cout << endl << "\nTramvai" << endl;
	cout << "\nCons imp: ";
	Tramvai t1;
	cout << t1;

	cout << endl << "\nCons parametrii: ";
	Tramvai t2(4, "Pe sine", 30, 450, 2);
	cout << t2;

	cout << endl << "\nCons parametrii: ";
	Tramvai t3(v4, 2);
	cout << t3;

	cout << endl << "\nCons copy: ";
	Tramvai t4 = t2;
	cout << t4;

	cout << endl << "\nop = ";
	Tramvai t5;
	t5 = t2;
	cout << t5;

	cout << endl << "\nDown cast TRAMVAI: ";
	Tramvai t6 = v3;
	cout << t6;

	cout << endl << "\nTroleibuz" << endl;
	cout << "\nCons imp: ";
	Troleibuz tr1;
	cout << tr1;

	cout << endl << "\nCons parametrii: ";
	Troleibuz tr2(5, "Public", 40, 400, 2000);
	cout << tr2;

	cout << endl << "\nCons parametrii: ";
	Troleibuz tr3(v3, 3000);
	cout << tr3;

	cout << endl << "\nCons copy: ";
	Troleibuz tr4 = tr2;
	cout << tr4;

	cout << endl << "\nop = ";
	Troleibuz tr5;
	tr5 = tr2;
	cout << tr5;

	cout << endl << "\nDown cast TROLEIBUZ: ";
	Troleibuz tr6 = v4;
	cout << tr6;

	cout << endl << "\nPARC AUTO ";
	Vehicul* vehicule[] = { &v2,&v3 };
	Parc_auto pa(vehicule, 2);
	cout << pa;
	cout << endl << "\nop+= ";
	pa += v4;
	cout << pa;
	cout << endl << "\nop-= ";
	pa -= 1;
	cout << pa;

	IAmortizabil* am1 = &a2;
	IAmortizabil* am2 = &t2;
	IAmortizabil* am3= &tr2;
	cout << "\nClasa abstracta: ";
	cout<<"\nAmortizare: "<<am1->getAmortizare()<<endl;
	cout << "\nAmortizare: " << am2->getAmortizare()<<endl;
	cout << "\nAmortizare: " << am3->getAmortizare()<<endl;
	cout << "\nLate binding: ";
	Vehicul* lista[10];
	lista[0] = &a2;
	lista[1] = &v2;

	lista[0]->Tip();
	lista[1]->Tip();

	
	
}

//În cazul clasei Tramvai, moștenirea este specificată ca "protected" 
//(class Tramvai : protected Vehicul).Aceasta înseamnă că membrii publici și protejați ai clasei de 
//bază(Vehicul) sunt deveniți membri protejați în clasa derivată(Tramvai).În consecință, 
//funcția getAmortizare din Vehicul devine membru protejat în Tramvai.
//
//În cazul clasei Troleibuz, moștenirea este specificată ca "private" 
//(class Troleibuz : private Vehicul).Aceasta înseamnă că membrii publici și protejați ai clasei de 
//bază(Vehicul) sunt deveniți membri privați în clasa derivată(Troleibuz).În consecință, 
//funcția getAmortizare din Vehicul devine membru privat în Troleibuz.