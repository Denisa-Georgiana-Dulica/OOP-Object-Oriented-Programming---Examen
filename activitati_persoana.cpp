#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

enum grad
{
	Usoara, Medie, Grea, FoarteGrea
};
class Exception
{
	string mesaj;
public:
	Exception()
	{
		this->mesaj = "Necunoscut";
	}
	Exception(string mesaj)
	{
		this->mesaj = mesaj;
	}
	string getMesaj()
	{
		return this->mesaj;
	}
	~Exception() {}
};

class Abstracta
{
public:
	virtual int returneazaDurata() = 0;
};

class Activitate:public Abstracta
{
	const int idActivitate;
protected:
	char* denumire = nullptr;
	string locatie = "Anonim";
	int durata = 0;//in minute
	int nrObiecte = 0;
	string* denumireObiecte = nullptr;
	float* greutateObiecte = nullptr;
	grad gradDificultate = Usoara;
public:
	static int numarator;
	Activitate() :idActivitate(numarator++)
	{
		this->denumire = new char[strlen("Anonim") + 1];
		strcpy(this->denumire, "Anonim");
	}
	Activitate(const char* denumire, string locatie, int durata, int nrObiecte, string* denumireObiecte, float* greutateObiecte, grad gradDificultate) :idActivitate(numarator++)
	{
		if (denumire != nullptr && strlen(denumire) > 0)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
		{
			this->denumire = new char[strlen("Anonim") + 1];
			strcpy(this->denumire, "Anonim");
		}
		if (locatie.length() > 0)
		{
			this->locatie = locatie;
		}
		if (durata > 0)
		{
			this->durata = durata;
		}
		if (nrObiecte > 0)
		{
			this->nrObiecte = nrObiecte;
		}
		if (denumireObiecte != nullptr && nrObiecte > 0)
		{
			this->denumireObiecte = new string[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->denumireObiecte[i] = denumireObiecte[i];
			}
		}
		if (greutateObiecte != nullptr && nrObiecte > 0)
		{
			this->greutateObiecte = new float[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->greutateObiecte[i] = greutateObiecte[i];
			}
		}
		this->gradDificultate = gradDificultate;
	}
	Activitate(const Activitate& a) :idActivitate(a.idActivitate)
	{
		if (a.denumire != nullptr && strlen(a.denumire) > 0)
		{
			this->denumire = new char[strlen(a.denumire) + 1];
			strcpy(this->denumire, a.denumire);
		}
		else
		{
			this->denumire = new char[strlen("Anonim") + 1];
			strcpy(this->denumire, "Anonim");
		}
		if (a.locatie.length() > 0)
		{
			this->locatie = a.locatie;
		}
		if (a.durata > 0)
		{
			this->durata = a.durata;
		}
		if (a.nrObiecte > 0)
		{
			this->nrObiecte = a.nrObiecte;
		}
		if (a.denumireObiecte != nullptr && a.nrObiecte > 0)
		{
			this->denumireObiecte = new string[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->denumireObiecte[i] = a.denumireObiecte[i];
			}
		}
		if (a.greutateObiecte != nullptr && a.nrObiecte > 0)
		{
			this->greutateObiecte = new float[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->greutateObiecte[i] = a.greutateObiecte[i];
			}
		}
		this->gradDificultate = a.gradDificultate;
	}
	Activitate& operator=(const Activitate& a)
	{
		if (this != &a)
		{
			delete[] this->denumire;
			this->denumire = nullptr;
			delete[] this->denumireObiecte;
			this->denumireObiecte = nullptr;
			delete[] this->greutateObiecte;
			this->greutateObiecte = nullptr;

			if (a.denumire != nullptr && strlen(a.denumire) > 0)
			{
				this->denumire = new char[strlen(a.denumire) + 1];
				strcpy(this->denumire, a.denumire);
			}
			else
			{
				this->denumire = new char[strlen("Anonim") + 1];
				strcpy(this->denumire, "Anonim");
			}
			if (a.locatie.length() > 0)
			{
				this->locatie = a.locatie;
			}
			if (a.durata > 0)
			{
				this->durata = a.durata;
			}
			if (a.nrObiecte > 0)
			{
				this->nrObiecte = a.nrObiecte;
			}
			else
				this->nrObiecte = 0;
			if (a.denumireObiecte != nullptr && a.nrObiecte > 0)
			{
				this->denumireObiecte = new string[this->nrObiecte];
				for (int i = 0; i < this->nrObiecte; i++)
				{
					this->denumireObiecte[i] = a.denumireObiecte[i];
				}
			}
			else
				this->denumireObiecte = nullptr;
			if (a.greutateObiecte != nullptr && a.nrObiecte > 0)
			{
				this->greutateObiecte = new float[this->nrObiecte];
				for (int i = 0; i < this->nrObiecte; i++)
				{
					this->greutateObiecte[i] = a.greutateObiecte[i];
				}
			}
			else
				this->greutateObiecte = nullptr;
			this->gradDificultate = a.gradDificultate;
		}
		return *this;
	}

	~Activitate()
	{
		delete[] this->denumire;
		this->denumire = nullptr;
		delete[] this->denumireObiecte;
		this->denumireObiecte = nullptr;
		delete[] this->greutateObiecte;
		this->greutateObiecte = nullptr;
	}

	//GETTERI SI SETTERI
	const int getId()
	{
		return this->idActivitate;
	}
	const char* getDenumire()
	{
		return this->denumire;
	}
	string getLocatie()
	{
		return this->locatie;
	}
	int getDurata()
	{
		return this->durata;
	}
	int getNrObiecte()
	{
		return this->nrObiecte;
	}
	string* getDenumireOb()
	{
		return this->denumireObiecte;
	}
	float* getGreutateOb()
	{
		return this->greutateObiecte;
	}
	grad getGradDif()
	{
		return this->gradDificultate;
	}
	void setObiecte(string* denumireObiecte, float* greutateObiecte, int nrObiecte)
	{
		if (nrObiecte > 0 && denumireObiecte != nullptr && greutateObiecte != nullptr)
		{
			if (this->denumireObiecte != nullptr && this->greutateObiecte != nullptr)
			{
				delete[] this->denumireObiecte;
				this->denumireObiecte = nullptr;
				delete[] this->greutateObiecte;
				this->greutateObiecte = nullptr;
			}
			this->nrObiecte = nrObiecte;
			this->denumireObiecte = new string[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->denumireObiecte[i] = denumireObiecte[i];
			}
			this->greutateObiecte = new float[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->greutateObiecte[i] = greutateObiecte[i];
			}
		}
	}
	void setDenumire(const char* denumire)
	{
		if (strlen(denumire) > 2)
		{
			if (this->denumire != nullptr)
			{
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
			throw Exception("\nDenumire gresita");
	}

	friend ostream& operator<<(ostream& out, const Activitate& a)
	{
		out << "\n----------------------";
		out << "\nDenumire: " << a.denumire;
		out << "\nLocatie: " << a.locatie;
		out << "\nDurata: " << a.durata;
		out << "\nNr obiecte: " << a.nrObiecte;
		if (a.denumireObiecte != nullptr && a.greutateObiecte != nullptr && a.nrObiecte > 0)
		{
			out << "\nDenumire obiecte: " << endl;
			for (int i = 0; i < a.nrObiecte; i++)
			{
				out << a.denumireObiecte[i] << endl;
			}
			out << "\nGreutate obiecte: " << endl;
			for (int i = 0; i < a.nrObiecte; i++)
			{
				out << a.greutateObiecte[i] << endl;
			}
		}
		out << "\nGrad dificultate: ";
		switch (a.gradDificultate)
		{
		case 0:out << "Usor" << endl;
			break;
		case 1:out << "Medie" << endl;
			break;
		case 2:out << "Grea" << endl;
			break;
		case 3:out << "Foarte grea";
			break;
		default:out << "Usoara" << endl;
			break;
		}
		return out;
	}
	friend ofstream& operator<<(ofstream& out, const Activitate& a)
	{

		out << a.denumire << endl;
		out << a.locatie << endl;
		out << a.durata << endl;
		out << a.nrObiecte << endl;
		if (a.denumireObiecte != nullptr && a.greutateObiecte != nullptr && a.nrObiecte > 0)
		{

			for (int i = 0; i < a.nrObiecte; i++)
			{
				out << a.denumireObiecte[i] << endl;

			}
			for (int i = 0; i < a.nrObiecte; i++)
			{
				out << a.greutateObiecte[i] << endl;
			}
		}
		switch (a.gradDificultate)
		{
		case 0:out << "Usoara" << endl;
			break;
		case 1:out << "Medie" << endl;
			break;
		case 2:out << "Grea" << endl;
			break;
		case 3:out << "Foarte grea";
			break;
		default:out << "Usoara" << endl;
			break;
		}
		return out;
	}
	void serializare(fstream& f)
	{
		//char*
		int lg = strlen(this->denumire) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->denumire, lg);

		//string
		int lg1 = this->locatie.length() + 1;
		f.write((char*)&lg1, sizeof(int));
		f.write(this->locatie.data(), lg1);

		//int
		f.write((char*)&this->durata, sizeof(int));
		f.write((char*)&this->nrObiecte, sizeof(int));

		//string*
		for (int i = 0; i < this->nrObiecte; i++)
		{
			int lg2 = this->denumireObiecte[i].length() + 1;
			f.write((char*)&lg2, sizeof(int));
			f.write(this->denumireObiecte[i].data(), lg2);
		}
		//float*
		for (int i = 0; i < this->nrObiecte; i++)
		{
			f.write((char*)&this->greutateObiecte[i], sizeof(float));
		}
		//enum
		f.write((char*)&this->gradDificultate, sizeof(gradDificultate));
	}
	void deserializare(fstream& f)
	{

		delete[] this->denumire;
		this->denumire = nullptr;
		delete[] this->denumireObiecte;
		this->denumireObiecte = nullptr;
		delete[] this->greutateObiecte;
		this->greutateObiecte = nullptr;
		//char*
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->denumire = new char[strlen(buffer) + 1];
		strcpy(this->denumire, buffer);
		delete[] buffer;
		//string
		int lg1;
		f.read((char*)&lg1, sizeof(int));
		char* buffer1 = new char[lg1];
		f.read(buffer1, lg1);
		this->locatie = buffer1;
		delete[] buffer1;
		//int
		f.read((char*)&this->durata, sizeof(int));
		f.read((char*)&this->nrObiecte, sizeof(int));
		//string*
		this->denumireObiecte = new string[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++)
		{
			int lg2;
			f.read((char*)&lg2, sizeof(int));
			char* buffer2 = new char[lg2 + 1];
			f.read(buffer2, lg2);
			this->denumireObiecte[i] = buffer2;
			delete[] buffer2;
		}
		//float*
		this->greutateObiecte = new float[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++)
		{
			f.read((char*)&this->greutateObiecte[i], sizeof(float));
		}
		//enum
		f.read((char*)&this->gradDificultate, sizeof(gradDificultate));

	}
	friend istream& operator>>(istream& in, Activitate& a)
	{
		delete[] a.denumire;
		a.denumire = nullptr;
		delete[] a.denumireObiecte;
		a.denumireObiecte = nullptr;
		delete[] a.greutateObiecte;
		a.greutateObiecte = nullptr;

		cout << "\nIntroduceti denumirea activitatii: ";
		in >> ws;
		string buffer;
		getline(in, buffer);
		a.denumire = new char[buffer.size() + 1];
		strcpy(a.denumire, buffer.data());

		cout << "\nIntroduceti locatia: ";
		in >> ws;
		string buffer1;
		getline(in, buffer1);
		a.locatie = buffer1;

		cout << "\nIntroduceti durata: ";
		in >> a.durata;

		cout << "\nIntroduceti numarul de obiecte: ";
		in >> a.nrObiecte;

		a.denumireObiecte = new string[a.nrObiecte];
		for (int i = 0; i < a.nrObiecte; i++)
		{
			cout << "\nIntroduceti denumirea obiectului " << i + 1 << " : ";
			in >> ws;
			string buffer3;
			getline(in, buffer3);
			a.denumireObiecte[i] = buffer3;
		}
		a.greutateObiecte = new float[a.nrObiecte];
		for (int i = 0; i < a.nrObiecte; i++)
		{
			cout << "\nIntroduceti greutatea obiectului " << i + 1 << " : ";
			in >> a.greutateObiecte[i];
		}
		cout << "\nIntroduceti gradul de dif Usoara, Medie, Grea,Foarte grea: ";
		in >> ws;
		string buffer2;
		getline(in, buffer2);
		if (buffer2 == "Usoara")
		{
			a.gradDificultate = Usoara;
		}
		else if (buffer2 == "Medie")
		{
			a.gradDificultate = Medie;
		}
		else if (buffer2 == "Grea")
		{
			a.gradDificultate = Grea;
		}
		else if (buffer2 == "Foarte grea")
		{
			a.gradDificultate = FoarteGrea;
		}
		return in;
	}
	friend ifstream& operator>>(ifstream& in, Activitate& a)
	{
		delete[] a.denumire;
		a.denumire = nullptr;
		delete[] a.denumireObiecte;
		a.denumireObiecte = nullptr;
		delete[] a.greutateObiecte;
		a.greutateObiecte = nullptr;

	
		in >> ws;
		string buffer;
		getline(in, buffer);
		a.denumire = new char[buffer.size() + 1];
		strcpy(a.denumire, buffer.data());
		in >> ws;
		string buffer1;
		getline(in, buffer1);
		a.locatie = buffer1;
		in >> a.durata;
		in >> a.nrObiecte;
		a.denumireObiecte = new string[a.nrObiecte];
		for (int i = 0; i < a.nrObiecte; i++)
		{
			in >> ws;
			string buffer3;
			getline(in, buffer3);
			a.denumireObiecte[i] = buffer3;
		}
		a.greutateObiecte = new float[a.nrObiecte];
		for (int i = 0; i < a.nrObiecte; i++)
		{
			
			in >> a.greutateObiecte[i];
		}
		in >> ws;
		string buffer2;
		getline(in, buffer2);
		if (buffer2 == "Usoara")
		{
			a.gradDificultate = Usoara;
		}
		else if (buffer2 == "Medie")
		{
			a.gradDificultate = Medie;
		}
		else if (buffer2 == "Grea")
		{
			a.gradDificultate = Grea;
		}
		else if (buffer2 == "Foarte grea")
		{
			a.gradDificultate = FoarteGrea;
		}
		return in;
	}

	Activitate& adaugaObiect(string obiect,float greutate)
	{
		if (this->denumireObiecte != nullptr && this->greutateObiecte != nullptr && this->nrObiecte > 0)
		{
			Activitate a = *this;
			string* temp = new string[a.nrObiecte + 1];
			float* temp1 = new float[a.nrObiecte + 1];
			for (int i = 0; i < a.nrObiecte; i++)
			{
				if (a.denumireObiecte[i] != obiect)
				{
					temp[i] = a.denumireObiecte[i];
					temp1[i] = a.greutateObiecte[i];
				}
				else
					if (a.denumireObiecte[i] == obiect)
					{
						return *this;
					}
			}
				temp[a.nrObiecte] = obiect;
				temp1[a.nrObiecte] = greutate;
				delete[] this->denumireObiecte;
				this->denumireObiecte = nullptr;
				delete[]this->greutateObiecte;
				this->greutateObiecte = nullptr;
				this->denumireObiecte = temp;
				this->greutateObiecte = temp1;
				this->nrObiecte++;
				return *this;
			
		}
	}
	Activitate& eliminaOb(string obiect)
	{
		if (this->denumireObiecte != nullptr && this->greutateObiecte != nullptr && this->nrObiecte > 0)
		{
			int ok = 0;
			for (int i = 0; i < this->nrObiecte; i++)
			{
				if(this->denumireObiecte[i] == obiect)
				{
					ok = 1;
				}
				if (ok == 1)
				{
					for (int j = i; j < this->nrObiecte-1; j++)
					{
						this->denumireObiecte[j] = this->denumireObiecte[j + 1];
						this->greutateObiecte[j] = this->greutateObiecte[j + 1];
					}
					this->nrObiecte--; //nu uita
					return *this;
				}
				
			}
			if (ok == 0)
				cout << "\nNu s-a gasit obiectul";
			return *this;
		}
	}
	Activitate operator+(const Activitate& a)
	{
		Activitate ac = *this;
		delete[] ac.denumireObiecte;
		ac.denumireObiecte = nullptr;
		delete[] ac.greutateObiecte;
		ac.greutateObiecte = nullptr;
		ac.nrObiecte = this->nrObiecte + a.nrObiecte;
		ac.denumireObiecte = new string[this->nrObiecte + a.nrObiecte];
		ac.greutateObiecte = new float[this->nrObiecte + a.nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++)
		{
			ac.denumireObiecte[i] = this->denumireObiecte[i];
			ac.greutateObiecte[i] = this->greutateObiecte[i];
		}
		for (int i = this->nrObiecte; i < this->nrObiecte+a.nrObiecte; i++)
		{
			if (ac.denumireObiecte[i] != this->denumireObiecte[i - this->nrObiecte])
			{
				ac.denumireObiecte[i] = this->denumireObiecte[i - this->nrObiecte];
				ac.greutateObiecte[i] = this->greutateObiecte[i - this->nrObiecte];
			}
		}
		return ac;
	}
	Activitate operator++(int)
	{
		Activitate a = *this;
		this->durata += 10;
		return a;
	}
	Activitate operator++()
	{
		this->locatie = "Gim Been";
		return *this;
	}

	string operator[](int pozitie)
	{
		if (pozitie >= 0 && pozitie <= this->nrObiecte)
		{
			return this->denumireObiecte[pozitie];
		}
		else
			throw Exception("Pozitia nu exista");
	}
	Activitate operator+(int valoare)
	{
		Activitate a = *this;
		a.durata += valoare;
		return a;
	}
	bool operator>(const Activitate& a)
	{
		return this->durata > a.durata;
	}
	virtual void TipActivitate()
	{
		cout << "\nActivitate normala";
	}
	int returneazaDurata()
	{
		return this->durata;
	}
	void vector_afisare()
	{
		vector<string> vAct;
		if (this->denumireObiecte!=nullptr)
		{
			for (int i = 0; i < this->nrObiecte; i++)
			{
				vAct.push_back(this->denumireObiecte[i]);
			}
		}
		/*for (int i = 0; i < vAct.size(); i++)
		{
			cout << vAct[i] << endl;
		}*/
		vector<string>::reverse_iterator itV;
		for (itV = vAct.rbegin(); itV != vAct.rend(); itV++)
		{
			cout << *itV << endl;
		}
	}
	friend bool operator<(const Activitate& a1, const Activitate& a2)
	{
		return a1.durata < a2.durata;
	}
};
int Activitate::numarator = 0;
Activitate operator+(int valoare, Activitate& a)
{
	return a + valoare;
}
class ActivitateCardio: public Activitate,public Abstracta
{
	int nrCaloriiArse = 0;
	bool scopAtins = 0;
public:
	ActivitateCardio() :Activitate()
	{

	}
	ActivitateCardio(const char* denumire, string locatie, int durata, int nrObiecte, string* denumireObiecte, float* greutateObiecte, grad gradDificultate, int nrCaloriiArse,bool scopAtins) :Activitate(denumire,locatie,durata,nrObiecte, denumireObiecte, greutateObiecte,  gradDificultate)
	{
		if (nrCaloriiArse > 0)
		{
			this->nrCaloriiArse = nrCaloriiArse;
		}
		this->scopAtins = scopAtins;
	}
	ActivitateCardio(Activitate a, int nrCaloriiArse, bool scopAtins) :Activitate(a)
	{
		if (nrCaloriiArse > 0)
		{
			this->nrCaloriiArse = nrCaloriiArse;
		}
		this->scopAtins = scopAtins;
	}
	ActivitateCardio(const ActivitateCardio& a) :Activitate(a)
	{
		if (a.nrCaloriiArse > 0)
		{
			this->nrCaloriiArse = a.nrCaloriiArse;
		}
		this->scopAtins = a.scopAtins;
	}
	//DOWNCASTING
	ActivitateCardio(const Activitate& a) :Activitate(a)
	{
		this->nrCaloriiArse =200;
		this->scopAtins = 1;
	}
	ActivitateCardio& operator=(const ActivitateCardio& a)
	{
		this->Activitate::operator=(a);
		if (this != &a)
		{
			if (a.nrCaloriiArse > 0)
			{
				this->nrCaloriiArse = a.nrCaloriiArse;
			}
			this->scopAtins = a.scopAtins;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const ActivitateCardio& a)
	{
		out << (Activitate&)a;
		out << "\nNr calorii: " << a.nrCaloriiArse;
		out << "\nScop atins :" << a.scopAtins;
		return out;
	}
	friend istream& operator>>(istream& in, ActivitateCardio& a)
	{
		in >> (Activitate&)a;
		cout << "\nIntroduceti nr de calorii: ";
		in >> a.nrCaloriiArse;
		cout << "\nAti atins obiectivul? (Da/Nu): ";
		in >> ws;
		string buffer;
		getline(in, buffer);
		if (buffer == "Da")
		{
			a.scopAtins = 1;
		}
		if (buffer == "Nu")
		{
			a.scopAtins = 0;
		}
		return in;
	}
	friend ofstream& operator<<(ofstream& out, const ActivitateCardio& a)
	{
		out << (Activitate&)a<<endl;
		out<< a.nrCaloriiArse<<endl;
		out  << a.scopAtins;
		return out;
	}
	friend ifstream& operator>>(ifstream& in, ActivitateCardio& a)
	{
		in >> (Activitate&)a;
		in >> a.nrCaloriiArse;
		in >> a.scopAtins;
		return in;
	}
	
	//functie virtuala
    void TipActivitate()
	{
		cout << "\nActivitate cardio";
	}
	//cls abstracta
	int returneazaDurata()
	{
		return this->durata;
	}
	~ActivitateCardio() {}
};
class Persoana:public Abstracta
{
	string nume = "Anonim";
	int nrActivitati = 0;
	Activitate** activitati = nullptr;
public:
	Persoana()
	{

	}
	Persoana(string nume, Activitate** activitati,int nrActivitati)
	{
		if (nume.length() > 0)
		{
			this->nume = nume;
		}
		if (nrActivitati > 0)
		{
			this->nrActivitati = nrActivitati;
		}
		if (activitati != nullptr)
		{
			this->activitati = new Activitate * [this->nrActivitati];
			for (int i = 0; i < this->nrActivitati; i++)
			{
				this->activitati[i] = new Activitate(*activitati[i]);
			}
		}
	}
	Persoana(const Persoana& p)
	{
		if (p.nume.length() > 0)
		{
			this->nume = p.nume;
		}
		if (p.nrActivitati > 0)
		{
			this->nrActivitati = p.nrActivitati;
		}
		if (p.activitati != nullptr)
		{
			this->activitati = new Activitate * [this->nrActivitati];
			for (int i = 0; i < this->nrActivitati; i++)
			{
				this->activitati[i] = new Activitate(*p.activitati[i]);
			}
		}
	}
	Persoana& operator=(const Persoana& p)
	{
		if (this != &p)
		{
			for (int i = 0; i < this->nrActivitati; i++)
			{
				delete this->activitati[i];
				this->activitati[i] = nullptr;
			}
			delete[] this->activitati;
			this->activitati = nullptr;
			if (p.nume.length() > 0)
			{
				this->nume = p.nume;
			}
			if (p.nrActivitati > 0)
			{
				this->nrActivitati = p.nrActivitati;
			}
			else
				this->nrActivitati = 0;
			if (p.activitati != nullptr)
			{
				this->activitati = new Activitate * [this->nrActivitati];
				for (int i = 0; i < this->nrActivitati; i++)
				{
					this->activitati[i] = new Activitate(*p.activitati[i]);
				}
			}
			else
				this->activitati = nullptr;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Persoana& p) {
		out << "\n-------------------------";
		out << "\nNume: " << p.nume;
		out << "\nNr activitati: " << p.nrActivitati;
		if (p.activitati != nullptr && p.nrActivitati > 0)
		{
			out << "\nActivitati: " << endl;
			for (int i = 0; i < p.nrActivitati; i++)
			{
				out << *p.activitati[i] << endl;
			}
		}
		else
			out << "\nActivitati: -";
		return out;
	}
	friend istream& operator>>(istream& in, Persoana& p)
	{
		for (int i = 0; i <p.nrActivitati; i++)
		{
			delete p.activitati[i];
			p.activitati[i] = nullptr;
		}
		delete[] p.activitati;
		p.activitati = nullptr;
		cout << "\nIntroduceti numele: ";
		string buffer;
		in >> ws;
		getline(in, buffer);
		p.nume = buffer;
		cout << "\nIntroduceti nr de activitati: ";
		in >> p.nrActivitati;
		p.activitati = new Activitate * [p.nrActivitati];
		for (int i = 0; i < p.nrActivitati; i++)
		{
			p.activitati[i] = new Activitate();
			cout << "\nActivitate " << i + 1 << " : ";
			in >> *p.activitati[i];
		}
		return in;
	}
	void seralizare(fstream& f)
	{
		int lg = this->nume.length() + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->nume.data(), lg);

		f.write((char*)&this->nrActivitati, sizeof(int));
		for (int i = 0; i < this->nrActivitati; i++)
		{
			this->activitati[i]->serializare(f);
		}
	}
	void deserializare(fstream& f)
	{
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->nume = buffer;
		f.read((char*)&this->nrActivitati, sizeof(int));
		for (int i = 0; i < this->nrActivitati; i++)
		{
			this->activitati[i]->deserializare(f);
		}
		
	}
	~Persoana()
	{
		for (int i = 0; i < this->nrActivitati; i++)
		{
			delete this->activitati[i];
			this->activitati[i] = nullptr;
		}
		delete[] this->activitati;
		this->activitati = nullptr;
	}
	Persoana& operator+=(const Activitate& a)
	{
		Persoana p = *this;
		Activitate** temp = new Activitate * [p.nrActivitati + 1];
		for (int i = 0; i < p.nrActivitati; i++)
		{
			temp[i] = new Activitate( *p.activitati[i]);
		}
		temp[p.nrActivitati] = new Activitate(a);
		for (int i = 0; i < this->nrActivitati; i++)
		{
			delete this->activitati[i];
			this->activitati[i] = nullptr;
		}
		delete[] this->activitati;
		this->activitati = nullptr;
		
		this->activitati = temp;
		this->nrActivitati++;
		return *this;
	}
	Persoana& operator-=( Activitate& a)
	{
		if (this->activitati != nullptr && this->nrActivitati > 0)
		{
			int ok = 0;
			for (int i = 0; i < this->nrActivitati; i++)
			{
				if (this->activitati[i]->getId() == a.getId())
				{
					ok = 1;
				}
				if (ok == 1)
				{
					for (int j = i; j < this->nrActivitati; j++)
					{
						this->activitati[j] = this->activitati[j + 1];
					}
					this->nrActivitati--;
				}
				
			}
			if (ok == 0)
			{
				return *this;
			}
			return *this;
		}
	}
	
	//cls abstracta
	int returneazaDurata()
	{
		float durata = 0;
		if (this->activitati != nullptr)
		{
			for (int i = 0; i < this->nrActivitati; i++)
				durata += this->activitati[i]->getDurata();
		}
		return durata;
	}
};
//FUNCTIE TEMPLATE
template<class TIP>
void comparare(TIP a, TIP b)
{
	TIP aux;
	if (a > b)
	{
		aux = a;
		a = b;
		b = aux;
	}
}
//CLASA TEMPLATE
//template<class tip>
//class Sablon
//{
//	int nrElemente=0;
//	tip* elemente = nullptr;
//public:
//	Sablon()
//	{
//
//	}
//	Sablon(int nrElemente, tip* elemente)
//	{
//		this->nrElemente = nrElemente;
//		this->elemente = new tip[this->nrElemente];
//		if (elemente != nullptr && nrElemente > 0)
//		{
//			for (int i = 0; i < this->nrElemente; i++)
//			{
//				this->elemente[i] = elemente[i];
//			}
//		}
//	}
//	Sablon(const Sablon& s)
//	{
//		this->nrElemente = s.nrElemente;
//		this->elemente = new tip[this->nrElemente];
//		if (s.elemente != nullptr && s.nrElemente > 0)
//		{
//			for (int i = 0; i < this->nrElemente; i++)
//			{
//				this->elemente[i] = s.elemente[i];
//			}
//		}
//	}
//	Sablon& operator=(const Sablon& s)
//	{
//		if (this != &s)
//		{
//			delete[] this->elemente;
//			this->elemente = nullptr;
//			this->nrElemente = s.nrElemente;
//			this->elemente = new tip[this->nrElemente];
//			if (s.elemente != nullptr && s.nrElemente > 0)
//			{
//				for (int i = 0; i < this->nrElemente; i++)
//				{
//					this->elemente[i] = s.elemente[i];
//				}
//			}
//		}
//		return *this;
//	}
//	friend ostream& operator<<(ostream& out, const Sablon& s)
//	{
//		out << "\n----------------------";
//		out << "\nNr elemente: " << s.nrElemente;
//		if (s.elemente != nullptr)
//		{
//			for (int i = 0; i < s.nrElemente; i++)
//			{
//				out << s.elemente[i] << endl;
//			}
//		}
//		return out;
//	}
//	~Sablon()
//	{
//		delete[] this->elemente;
//		this->elemente = nullptr;
//	}
//};
template<class tip>
class Sablon
{
	int nrElemente = 0;
	tip** elemente = nullptr;
public:
	Sablon()
	{

	}
	Sablon(int nrElemente, tip** elemente)
	{
		this->nrElemente = nrElemente;
		this->elemente = new tip*[this->nrElemente];
		if (elemente != nullptr && nrElemente > 0)
		{
			for (int i = 0; i < this->nrElemente; i++)
			{
				this->elemente[i] = new tip(*elemente[i]);
			}
		}
	}
	Sablon(const Sablon& s)
	{
		this->nrElemente = s.nrElemente;
		this->elemente = new tip * [this->nrElemente];
		if (s.elemente != nullptr && s.nrElemente > 0)
		{
			for (int i = 0; i < this->nrElemente; i++)
			{
				this->elemente[i] = new tip(*s.elemente[i]);
			}
		}
	}
	Sablon& operator=(const Sablon& s)
	{
		if (this != &s)
		{
			delete[] this->elemente;
			this->elemente = nullptr;
			this->nrElemente = s.nrElemente;
			this->nrElemente = nrElemente;
			this->elemente = new tip * [this->nrElemente];
			if (s.elemente != nullptr && s.nrElemente > 0)
			{
				for (int i = 0; i < this->nrElemente; i++)
				{
					this->elemente[i] = new tip(*s.elemente[i]);
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Sablon& s)
	{
		out << "\n----------------------";
		out << "\nNr elemente: " << s.nrElemente;
		if (s.elemente != nullptr)
		{
			for (int i = 0; i < s.nrElemente; i++)
			{
				out << *s.elemente[i] << endl;
			}
		}
		return out;
	}
	~Sablon()
	{
		delete[] this->elemente;
		this->elemente = nullptr;
	}
};
int main()
{
	cout << endl << "\nCons fara parametrii: "<<endl;
	Activitate a;
	cout << a;

	cout << endl << "\nCons cu parametrii: " << endl;
	string denumireOb1[]= { "bara","haltere","Ciocan" };
	float greutateOb1[]= { 20,17.5,11.5 };
	Activitate a1("Sala", "Acasa", 30, 3, denumireOb1, greutateOb1, Usoara);
	cout << a1;

	cout << endl << "\nCons cu parametrii: " << endl;
	string denumireOb2[] = { "greutate","haltere mici","topor" };
	float greutateOb2[] = { 10,18.5,11 };
	Activitate a5("Cardio", "Acasa", 60, 3, denumireOb1, greutateOb1, Medie);
	cout << a5;

	cout << endl << "\nCons copy: " << endl;
	Activitate a2 = a1;
	cout << a2;

	cout << endl << "\nOp =: " << endl;
	Activitate a3;
	a3 = a1;
	cout << a3;

	//cout << endl << "Metoda de adaugare obiect: ";
	//a1.adaugaObiect ("Greutate", 5);
	//cout << a1;
	//cout << endl << "Metoda de eliminare obiect: ";
	//a1.eliminaOb("Greutate");
	//cout << a1;
	cout << "\nOp obiect+obiect";
	Activitate a4;
	a4 = a2 + a5;
	cout << a4;

	cout << "\nOp valoare+obiect";
	Activitate a8;
	a8 = 3 + a5;
	cout << a5 << endl << a8;;

	cout << "\nOp ++ postincremenatare";
	Activitate a6 = a2++;
	cout << a6 <<endl<< a2;

	cout << "\nOp ++ preincremenatare";
	Activitate a7 = ++a5;
	cout << a7 << endl << a5;
	

	cout << "\nOp index "<<endl;
	try
	{
		cout << a5[11];
	}
	catch (Exception ex)
	{
		cout << ex.getMesaj();
	}


	cout << "\nFunctie Template" << endl;
	int c = 3; int b = 2;
	comparare<int>(c,b);
	cout << c << " " << b;
	cout << endl;
	comparare<Activitate>(a2, a5);
	cout << a2 << endl << a5;
	cout << "\nCitire / scriere din txt: ";
	/*ofstream f("fisier_activitati.txt");
	f << a1;*/
	
	ifstream g("fisier_activitati.txt");
	g >> a1;
	cout << a1;

	cout << "\nCitire / scriere din binar: "; 
/*	fstream file("fisier_binar_activitate.bin", ios::out | ios::binary);
	a1.serializare(file);
	file.close();*/

	fstream file1("fisier_binar_activitate.bin", ios::in | ios::binary);
	a1.deserializare(file1);
	cout << a1;
	/*cout << endl << "\nOp >> " << endl;
	Activitate a4;
	cin >> a4;
	cout << a4;*/

	string denumireOb3[] = { "coarda","saltea", };
	float greutateOb3[] = { 10,18.5 };
	cout << "\nClasa derivata IS A: ";
	ActivitateCardio ac1("Mancare", "Acasa", 130, 2, denumireOb3, greutateOb3, Usoara, 400, 1);
	cout << ac1;

	cout << "\nUp-cast: ";
	Activitate a9 = ac1;
	cout << a9;
	cout << "\nDown cast: ";
	ActivitateCardio ac2 = a2;
	cout << ac2;

	/*cout << "\n Op >> ";
	ActivitateCardio ac3;
	cin >> ac3;
	cout << ac3;*/

	cout << "\nFunctie virtuala IS-A: ";
	Activitate* lista[10];
	lista[0] = &ac1;
	lista[1] = &a2;
	lista[0]->TipActivitate();
	lista[1]->TipActivitate();
	cout << endl;

	cout << "\nClasa abstracta: ";
	Abstracta* ab = &ac1;
	Abstracta* ab1 = &a2;
	cout << ab->returneazaDurata()<<endl;
	cout << ab1->returneazaDurata();

	cout << "\nClasa Persoana: " << endl;
	Activitate* vector2[] = { &a1 };
	Persoana p("Denisa", vector2, 1);
	cout << p;

	/*Persoana p1;
	cin >> p1;
	cout << p1;*/
	cout << "\nCons copy: " << endl;
	Persoana p2 = p;
	cout << p2;

	cout << "\nOp +=: " << endl;
	p += a5;
	cout << p;

	cout << "\nOp -=: " << endl;
	p -= a5;
	cout << p;
	
	cout << "\nFunctie virtualizare HAS A (CLASA ABSTRACTA): ";
	Abstracta* abs = &a1;
	Abstracta* absP = &p;
	cout<<abs->returneazaDurata();cout << endl;
	cout<<absP->returneazaDurata();

	cout << "\nClasa template: " << endl;
	/*Activitate vector1[] = { a1,a5 };
	Sablon<Activitate> s(2, vector1);
	cout << s;*/
	Activitate* vector1[] = { &a1,&a5 };
	Sablon<Activitate> s(2, vector1);
	cout << s; 

	cout << "\nVector in clasa: " << endl;
	a1.vector_afisare();

	cout << "\nVector : " << endl;
	vector<Activitate> vAct;
	vAct.push_back(a1);
	vAct.push_back(a5);
	/*for (int i = 0; i < vAct.size(); i++)
	{
		cout << vAct[i] << endl;
	}*/
	vector<Activitate>::iterator itV;
	for (itV = vAct.begin(); itV != vAct.end(); itV++)
	{
		cout << *itV << endl;
	}
	cout << "\nLista : " << endl;
	list<Activitate> listAct;
	listAct.push_back(a1);
	listAct.push_front(a5);
	list<Activitate>::iterator itL;
	for (itL = listAct.begin(); itL != listAct.end(); itL++)
	{
		cout << *itL << endl;
	}

	cout << "\nSet : " << endl;
	set<Activitate> setAct;
	setAct.insert(a1);
	setAct.insert(a5);
	setAct.insert(a1);
	set<Activitate>::iterator itSet;
	for (itSet = setAct.begin(); itSet != setAct.end(); itSet++)
	{
		cout << *itSet << endl;
	}

	itSet = setAct.find(a1);

	cout << "\nFisier txt pt clasa derivata: ";
	/*ofstream f("fisier_clasa_derivata.txt");
	f << ac1;*/

	ifstream gd("fisier_clasa_derivata.txt");
	gd >> ac1;
	cout << ac1;

	int pozitie;
	/*do
	{
		cout << "\nIntroduceti pozitia: ";
		cin >> pozitie;
		try
		{
			cout << a1[pozitie];
		}
		catch (Exception ex)
		{
			cout << ex.getMesaj()<<endl;
		}
	} while (pozitie < 0 || pozitie > a1.getNrObiecte());*/

	cout << "\nFisier binar persoana: ";
	/*fstream file2("fisier_binar_has.bin", ios::out | ios::binary);
	p.seralizare(file2);*/

	fstream file2("fisier_binar_has.bin", ios::in | ios::binary);
	p.deserializare(file2);
	cout << p;
	//GETTERI SETTERI
	//cout<<a1.getDenumire();
	//for (int i = 0; i < a1.getNrObiecte(); i++)
	//{
	//	cout << a1.getDenumireOb()[i] << endl;
	//}
	//for (int i = 0; i < a1.getNrObiecte(); i++)
	//{
	//	cout << a1.getGreutateOb()[i] << endl;
	//}
	//cout << a1.getGradDif() << endl;

	//EXCEPTIE
	//try
	//{
	//	a1.setDenumire("io");
	//}
	//catch (Exception ex)
	//{
	//	cout << ex.getMesaj();
	//}

	//string denumiriNoi[] = { "Topor","haltere","Ciocan" };
	//float greutatiNoi[] = { 22,17.5,11.5 };
	//a1.setObiecte(denumiriNoi, greutatiNoi,3);
	//for (int i = 0; i < a1.getNrObiecte(); i++)
	//{
	//	cout << a1.getDenumireOb()[i] << endl;
	//}
	//for (int i = 0; i < a1.getNrObiecte(); i++)
	//{
	//	cout << a1.getGreutateOb()[i] << endl;
	//}
	
}






