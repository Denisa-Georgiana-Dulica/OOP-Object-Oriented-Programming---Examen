#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<fstream>
using namespace std;
class ServiciuImprimare
{
	
	char* tipMaterial = nullptr;
	float cost = 0;
	int numar_exemplare = 0;
	
public:
	ServiciuImprimare()
	{
		this->tipMaterial = new char[strlen("Anonim") + 1];
		strcpy(this->tipMaterial, "Anonim");
	}
	ServiciuImprimare(const char* tipMaterial,float cost,int numar_exemplare) 
	{
		if (tipMaterial != nullptr)
		{
			this->tipMaterial = new char[strlen(tipMaterial) + 1];
			strcpy(this->tipMaterial, tipMaterial);
		}
		else
		{
			this->tipMaterial = new char[strlen("Anonim") + 1];
			strcpy(this->tipMaterial, "Anonim");
		}
		if (cost > 0)
		{
			this->cost = cost;
		}
		if (numar_exemplare > 0)
		{
			this->numar_exemplare = numar_exemplare;
		}
	}
	ServiciuImprimare(const ServiciuImprimare& s) 
	{
		if (s.tipMaterial != nullptr)
		{
			this->tipMaterial = new char[strlen(s.tipMaterial) + 1];
			strcpy(this->tipMaterial, s.tipMaterial);
		}
		else
		{
			this->tipMaterial = new char[strlen("Anonim") + 1];
			strcpy(this->tipMaterial, "Anonim");
		}
		if (s.cost > 0)
		{
			this->cost = s.cost;
		}
		if (s.numar_exemplare > 0)
		{
			this->numar_exemplare = s.numar_exemplare;
		}
	}
	ServiciuImprimare& operator=(const ServiciuImprimare& s)
	{
		if (this != &s)
		{
			delete[] this->tipMaterial;
			this->tipMaterial = nullptr;
			if (s.tipMaterial != nullptr)
			{
				this->tipMaterial = new char[strlen(s.tipMaterial) + 1];
				strcpy(this->tipMaterial, s.tipMaterial);
			}
			else
			{
				this->tipMaterial = new char[strlen("Anonim") + 1];
				strcpy(this->tipMaterial, "Anonim");
			}
			if (s.cost > 0)
			{
				this->cost = s.cost;
			}
			if (s.numar_exemplare > 0)
			{
				this->numar_exemplare = s.numar_exemplare;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const ServiciuImprimare& s)
	{
		out << "\n--------------------------";
		out << "\nTip material: " << s.tipMaterial;
		out << "\nCost: " << s.cost;
		out << "\nNumar exemplare: " << s.numar_exemplare;
		return out;
	}
	~ServiciuImprimare()
	{
		delete[] this->tipMaterial;
		this->tipMaterial = nullptr;
	}
	bool operator<(const ServiciuImprimare& s)
	{
		return this->cost < s.cost;
	}
	float getPret()
	{
		return this->cost;
	}
	void saveToFile(fstream& f)
	{
		int lg = strlen(this->tipMaterial) + 1;
		f.write((char*)&lg, sizeof(int));
		f.write(this->tipMaterial, lg);
		f.write((char*)&this->cost, sizeof(float));
		f.write((char*)&this->numar_exemplare, sizeof(int));
	}
	void readFromFile(fstream& f)
	{
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->tipMaterial = new char[strlen(buffer)+1];
		strcpy(this->tipMaterial, buffer);
		f.read((char*)&this->cost, sizeof(float));
		f.read((char*)&this->numar_exemplare, sizeof(int));

	}
	friend bool operator<(const ServiciuImprimare& s1, const ServiciuImprimare& s2)
	{
		return s1.cost < s2.cost;
	}
};
class Firma
{
	ServiciuImprimare* servicii = nullptr;
	int nrServicii = 0;
public:
	Firma()
	{

	}
	Firma(ServiciuImprimare* servicii, int nrServicii)
	{
		if (servicii != nullptr && nrServicii > 0)
		{
			this->nrServicii = nrServicii;
			this->servicii = new ServiciuImprimare[this->nrServicii];
			for (int i = 0; i < this->nrServicii; i++)
			{
				this->servicii[i] = servicii[i];
			}
		}
	}
	Firma(const Firma& f)
	{
		if (f.servicii != nullptr && f.nrServicii > 0)
		{
			this->nrServicii = f.nrServicii;
			this->servicii = new ServiciuImprimare[this->nrServicii];
			for (int i = 0; i < this->nrServicii; i++)
			{
				this->servicii[i] = f.servicii[i];
			}
		}
	}
	Firma& operator=(const Firma& f)
	{
		if (this != &f)
		{
			delete[] this->servicii;
			this->servicii = nullptr;
			if (f.servicii != nullptr && f.nrServicii > 0)
			{
				this->nrServicii = f.nrServicii;
				this->servicii = new ServiciuImprimare[this->nrServicii];
				for (int i = 0; i < this->nrServicii; i++)
				{
					this->servicii[i] = f.servicii[i];
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Firma& f)
	{
		out << "\n-----------------------------";
		out << "\nNumar servicii: " << f.nrServicii;
		if (f.nrServicii > 0 && f.servicii != nullptr)
		{
			out << "\nServicii: "<<endl;
			for (int i = 0; i < f.nrServicii; i++)
			{
				out << f.servicii[i]<<endl;
			}
		}
		else
		{
			out << "\nServicii: -";
		}
		return out;
	}
	~Firma()
	{
		delete[] this->servicii;
		this->servicii = nullptr;
	}
	void operator()(int pozitieInitiala, int pozitieFinala)
	{
		if (pozitieInitiala >= 0 && pozitieInitiala < this->nrServicii && pozitieFinala <= this->nrServicii)
		{
			if (this->servicii != nullptr && this->nrServicii > 0)
			{
				for (int i = pozitieInitiala; i <= pozitieFinala; i++)
				{
					for (int j = i + 1; j < pozitieFinala; j++)
					{
						if (this->servicii[j] < this->servicii[i])
						{
							swap(this->servicii[j], this->servicii[i]);
						}
					}
				}
			}
		}
	}
	Firma& operator+=(const ServiciuImprimare& s)
	{
		Firma f = *this;
		ServiciuImprimare* temp = new ServiciuImprimare[this->nrServicii + 1];
		for (int i = 0; i < f.nrServicii; i++)
		{
			temp[i] = f.servicii[i];
		}
		temp[f.nrServicii] = s;
		delete[] this->servicii;
		this->servicii = nullptr;
		this->servicii = temp;
		this->nrServicii++;
		return *this;
	}
	
};

int main()
{
	ServiciuImprimare s1;
	cout << s1;

	ServiciuImprimare s2("lemn",100,3);
	cout << s2;

	ServiciuImprimare s3("plastic", 200, 10);
	cout << s3;

	ServiciuImprimare s4("silicon", 300, 20);
	cout << s4;

	ServiciuImprimare s5("sticla", 500, 35);
	cout << s5;

	if (s2 < s3)
	{
		cout << "\nPretul serviciului 1 este < decat pretul serviciului 2";
	}
	else
		cout << "\nPretul serviciului 1 nu este < decat pretul serviciului 2";

	ServiciuImprimare servicii[] = { s2,s3,s4 };
	Firma f2(servicii,3);
	cout << f2;

	f2(0, 2);
	cout<<"\nPreturi crescatoare: " << f2;

	f2 += s5;
	cout <<"\nDupa adaugare: " << f2;

	/*fstream file("colectie_firma.bin", ios::out, ios::binary);
	s2.saveToFile(file);*/

	fstream file("colectie_firma.bin", ios::in, ios::binary);
	s2.readFromFile(file);
	cout << s2;

	cout << endl << "STL";
	map<ServiciuImprimare, string>mapP;
	mapP[s2] = "lemn";
	mapP[s3] = "plastic";
	mapP[s4] = "silicon";
	mapP[s5] = "sticla";

	map<ServiciuImprimare, string>::iterator itMap;
	for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
	{
		if (itMap->second == "lemn")
		{
			cout <<"\nLemn: " << itMap->first;
		}

	}
	for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
	{
		if (itMap->second == "plastic")
		{
			cout << "\nPlastic: " << itMap->first;
		}
	}
		for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
		{
			if (itMap->second == "silicon")
			{
				cout << "\nSilicon: " << itMap->first;
			}
		}
		for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
		{
			if (itMap->second == "sticla")
			{
				cout << "\nSticla: " << itMap->first;
			}
		}
	
}