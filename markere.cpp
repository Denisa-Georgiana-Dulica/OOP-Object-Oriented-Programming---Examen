#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<fstream>
using namespace std;

class MarkerElectronic
{
	string proprietar ="Anonim";
	float pret = 0;
	char* culoare = nullptr;
	int timpFunctionareMin = 0;
	
	static float nivelCurentBaza;
public:
	static map<string, set<MarkerElectronic>> mapP;
	MarkerElectronic()
	{
		this->culoare= new char[strlen("Anonim") + 1];
		strcpy(this->culoare, "Anonim");
	}
	MarkerElectronic(string proprietar, float pret, const char* culoare, int timpFunctionareMin)
	{
		if (proprietar.length() > 0)
		{
			this->proprietar = proprietar;
		}
		if (pret > 0)
		{
			this->pret = pret;
		}
		if (culoare != nullptr)
		{
			this->culoare = new char[strlen(culoare) + 1];
			strcpy(this->culoare, culoare);
		}
		else
		{
			this->culoare = new char[strlen("Anonim") + 1];
			strcpy(this->culoare, "Anonim");
		}
		if (timpFunctionareMin > 0)
		{
			this->timpFunctionareMin = timpFunctionareMin;
		}
		//mapP[*this] = this->proprietar;
	}
	MarkerElectronic(const MarkerElectronic& m)
	{
		if (m.proprietar.length() > 0)
		{
			this->proprietar = m.proprietar;
		}
		if (m.pret > 0)
		{
			this->pret = m.pret;
		}
		if (m.culoare != nullptr)
		{
			this->culoare = new char[strlen(m.culoare) + 1];
			strcpy(this->culoare, m.culoare);
		}
		else
		{
			this->culoare = new char[strlen("Anonim") + 1];
			strcpy(this->culoare, "Anonim");
		}
		if (m.timpFunctionareMin > 0)
		{
			this->timpFunctionareMin = m.timpFunctionareMin;
		}
	}
	MarkerElectronic& operator=(const MarkerElectronic& m)
	{
		if (this !=&m)
		{
			delete[] this->culoare;
			this->culoare = nullptr;
			if (m.proprietar.length() > 0)
			{
				this->proprietar = m.proprietar;
			}
			if (m.pret > 0)
			{
				this->pret = m.pret;
			}
			if (m.culoare != nullptr)
			{
				this->culoare = new char[strlen(m.culoare) + 1];
				strcpy(this->culoare, m.culoare);
			}
			else
			{
				this->culoare = new char[strlen("Anonim") + 1];
				strcpy(this->culoare, "Anonim");
			}
			if (m.timpFunctionareMin > 0)
			{
				this->timpFunctionareMin = m.timpFunctionareMin;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const MarkerElectronic& m)
	{
		out << "\n------------------------------";
		out << "\nNume proprietar: " << m.proprietar;
		out << "\nPret: " << m.pret;
		out << "\nCuloare: " << m.culoare;
		out << "\nTimp functionare -minute : " << m.timpFunctionareMin;
		return out;
	}
	friend istream& operator>>(istream& in, MarkerElectronic& m)
	{
		cout << "\nIntroduceti numele proprietarului: ";
		in >> ws;
		string buffer;
		getline(in, buffer);
		m.proprietar = buffer;
		cout << "\nIntroduceti pretul: ";
		in >> m.pret;
		cout << "\nIntroduceti culoarea: ";
		in >> ws;
		string buffer1;
		getline(in, buffer1);
		m.culoare = new char[buffer1.size() + 1];
		strcpy(m.culoare, buffer1.data());
		cout << "\nIntroduceti timpul de functionare: ";
		in >> m.timpFunctionareMin;
		return in;
	}
	~MarkerElectronic()
	{
		delete[] this->culoare;
		this->culoare = nullptr;
	}
	friend bool operator<(const MarkerElectronic& m1, const MarkerElectronic& m2)
	{
		return m1.pret < m2.pret;
	}
	bool operator==(const MarkerElectronic& m)
	{
		if (this->pret > 0 && m.pret > 0 && this->culoare != nullptr && m.culoare != nullptr)
		{
			if (this->pret == m.pret && strcmp(this->culoare, m.culoare) == 0)
			{
				return true;
			}
			return false;
		}
		else
			throw exception("\nUnul din elemente nu exista");
	}
	virtual float CalculPret()
	{
		return this->pret;
	}
	friend bool operator==(const MarkerElectronic& m1, const MarkerElectronic& m2)
	{
		return m1.proprietar== m2.proprietar;
	}
	/*static string GasireProprietar(const MarkerElectronic& m)
	{
		string proprietar;
		map<MarkerElectronic,string>::iterator itMap;
        for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
		{
			if (itMap->first==m)
			{
				proprietar= itMap->second;
			}
		}
		return proprietar;
	}*/
	static void insert(const MarkerElectronic& m)
	{
		mapP[m.proprietar].insert(m);
	}
	static string GasireProprietar(const MarkerElectronic& m)
	{
		set<MarkerElectronic > ::iterator itSet;
		map<string, set<MarkerElectronic>>::iterator itMap;

		for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
		{
			set<MarkerElectronic> markerSet = itMap->second;
				for(itSet = markerSet.begin(); itSet != markerSet.end(); ++itSet)
				{
					if (*itSet == m)
					{
						return itMap->first;  // Returnãm proprietarul gãsit
					}
				}
			
		}
	}
	void readFromCsv(fstream& f)
	{
		string linie;
		if (f.is_open())
		{
			getline(f, linie);
			stringstream s(linie);

			string buffer;
			getline(s, buffer, ';');
			this->proprietar = buffer;
			s >> this->pret;
			s.ignore(1, ';');
			string buffer1;
			getline(s, buffer1, ';');
			this->culoare = new char[buffer1.size() + 1];
			strcpy(this->culoare, buffer1.data());
			s >> this->timpFunctionareMin;
		}
	}
	
};
float MarkerElectronic::nivelCurentBaza = 100;
map<string, set<MarkerElectronic>> MarkerElectronic::mapP;
class MarkerInteligent:public MarkerElectronic
{
	int nrFunctiiExtra = 0;
	string TipLinie = "Anonim";
	int nivelPresiune = 0;
public:
	MarkerInteligent():MarkerElectronic()
	{

	}
	MarkerInteligent(string proprietar, float pret, const char* culoare, int timpFunctionareMin,int nrFunctiiExtra,string TipLinie,int nivelPresiune) :MarkerElectronic(proprietar,pret,culoare,timpFunctionareMin)
	{
		if (nrFunctiiExtra > 0)
		{
			this->nrFunctiiExtra = nrFunctiiExtra;
		}
		if (TipLinie.length() > 0)
		{
			this->TipLinie = TipLinie;
		}
		if (nivelPresiune > 0)
		{
			this->nivelPresiune = nivelPresiune;
		}
	}
	MarkerInteligent(MarkerElectronic m, int nrFunctiiExtra, string TipLinie, int nivelPresiune) :MarkerElectronic(m)
	{
		if (nrFunctiiExtra > 0)
		{
			this->nrFunctiiExtra = nrFunctiiExtra;
		}
		if (TipLinie.length() > 0)
		{
			this->TipLinie = TipLinie;
		}
		if (nivelPresiune > 0)
		{
			this->nivelPresiune = nivelPresiune;
		}
	}
	MarkerInteligent(const MarkerInteligent& m) :MarkerElectronic(m)
	{
		if (m.nrFunctiiExtra > 0)
		{
			this->nrFunctiiExtra = m.nrFunctiiExtra;
		}
		if (m.TipLinie.length() > 0)
		{
			this->TipLinie = m.TipLinie;
		}
		if (m.nivelPresiune > 0)
		{
			this->nivelPresiune = m.nivelPresiune;
		}
	}
	MarkerInteligent& operator=(const MarkerInteligent& m)
	{
		if (this != &m)
		{
			this->MarkerElectronic::operator=(m);
			if (m.nrFunctiiExtra > 0)
			{
				this->nrFunctiiExtra = m.nrFunctiiExtra;
			}
			if (m.TipLinie.length() > 0)
			{
				this->TipLinie = m.TipLinie;
			}
			if (m.nivelPresiune > 0)
			{
				this->nivelPresiune = m.nivelPresiune;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const MarkerInteligent& m)
	{
		out << (MarkerElectronic&)m;
		out << "\nNr functii extra: " << m.nrFunctiiExtra;
		out << "\nTip linie: " << m.TipLinie;
		out << "\nNivel presiune: " << m.nivelPresiune;
		return out;
	}
	~MarkerInteligent()
	{

	}
    float CalculPret()
	{
		float rez = MarkerElectronic::CalculPret();
		rez += this->nrFunctiiExtra * 100;
		return rez;
	}

	//DOWNCASTING
	MarkerInteligent(const MarkerElectronic& m) :MarkerElectronic(m)
	{
		
			this->nrFunctiiExtra =2;
			this->TipLinie = "single-line";
		
	}
};
int main()
{
	cout << "\nCons implicit: ";
	MarkerElectronic m1;
	cout << m1;
	cout << endl;
	cout << "\nCons cu parametrii: ";
	MarkerElectronic m2("Dulica Denisa", 150, "negru", 1440);
	cout << m2;
	MarkerElectronic m6("Dulica Denisa", 130, "verde", 1200);
	cout << m6;
	cout << endl;
	cout << "\nCons cu parametrii: ";
	MarkerElectronic m3("Cristescu Sara", 200, "rosu", 2880);
	cout << m3;
	cout << endl;
	cout << "\nCons copy: ";
	MarkerElectronic m4 = m2;
	cout << m4;
	cout << endl;
	cout << "\nOp = ";
	MarkerElectronic m5;
	m5 = m2;
	cout << m5;
	cout << endl;
	/*cout << "\nOp >> ";
	MarkerElectronic m6;
	cin >> m6;
	cout << m6;*/
	cout << "\nCons implicit clasa derivata: ";
	MarkerInteligent mi1;
	cout << mi1;
	cout << endl;
	cout << "\nCons parametrii clasa derivata: ";
	MarkerInteligent mi2("Dinita Cosmina",400,"albastru",5000,3,"multi-functii",2);
	cout << mi2;
	cout << endl;
	cout << "\nCons parametrii 2 clasa derivata: ";
	MarkerInteligent mi3(m2, 3, "multi-functii", 2);
	cout << mi3;
	try
	{
		if (m2 == m1)
		{
			cout << "\nMarkere identice";
		}
		else
			cout << "\nMarkerele sunt diferite";
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
	MarkerElectronic* lista[10];
	lista[0] = &mi3;
	lista[1] = &m2;
	cout << "\nCostul markerului initial: " << lista[0]->CalculPret();
	cout << "\nCostul markerului nou dezvoltat: " << lista[1]->CalculPret();

	cout << endl;
	//cout<<MarkerElectronic::GasireProprietar(m2);

	//DOWNCASTING  CLASA DERIVATA = CLASA DE BAZA
	//CLASA DERIVATA (CONST CLASA DE BAZA & A) CLASA DE BAZA ( A)
	MarkerInteligent mi4 = m2;
	cout << mi4; //LA CLASA DE BAZA SE ADAUGA ATRIBUTELE IN PLUS

	//UPCASTING  //CLASA SE BAZA = CLASA DERIVATA
	MarkerElectronic m7 = mi4;
	cout << m7; //SE AFISEAZA DOAR ATRIBUTELE DIN CLASA DE BAZA

	MarkerElectronic::insert(m6);
	MarkerElectronic::insert(m2);
	MarkerElectronic::insert(m3);
	cout << "\nMap in set: " << endl;
	cout<<MarkerElectronic::GasireProprietar(m2);

	cout << "\nFisier csv: " << endl;
	MarkerElectronic m[10];

	fstream file("Book1.csv", ios::in);
	for (int i = 0; i < 3; i++)
	{
		m[i].readFromCsv(file);
	}
	file.close();
	for (int i = 0; i < 3; i++)
	{
		cout << m[i];
	}
}
