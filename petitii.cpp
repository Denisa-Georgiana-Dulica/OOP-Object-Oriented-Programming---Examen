#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<fstream>
#include<map>
#include<set>
using namespace std;

//DACA ZICE SPECIALIZATI CLASA DEFINITA ==>MOSTENIRE
class Petitie
{
private:
	const int idPetitie;
protected:
	
	int nrZileDeLaDep;// (max 30 zile)
	bool esteRezolvata;
	string categorie;
	//nu este rezolvata - deschisa
	char* denumirePetitie;
	bool esteDeschisa;
	
public:
	Petitie() :idPetitie(0)
	{
		this->denumirePetitie = new char[strlen("Anonim") + 1];
		strcpy(this->denumirePetitie, "Anonim");
		this->nrZileDeLaDep = 0;
		this->esteRezolvata = 0;
		this->esteDeschisa = 0;
		this->categorie = "Anonim";
	}
	Petitie(int idPetitie, int nrZileDeLaDep, bool esteRezolvata, const char* denumirePetitie,bool esteDeschisa,string categorie):idPetitie(idPetitie)
	{
		if (denumirePetitie!=nullptr)
		{
			this->denumirePetitie= new char[strlen(denumirePetitie) + 1];
			strcpy(this->denumirePetitie, denumirePetitie);
		}
		else
		{
			this->denumirePetitie = new char[strlen("Anonim") + 1];
			strcpy(this->denumirePetitie, "Anonim");
		}
		if (nrZileDeLaDep > 0)
		{
			this->nrZileDeLaDep = nrZileDeLaDep;
		}
		else
		{
			this->nrZileDeLaDep = 0;
		}
		if (esteRezolvata ==1)
		{
			this->esteRezolvata = esteRezolvata;
		}
		else
			this->esteRezolvata = 0;
		if (esteDeschisa ==1)
		{
			this->esteDeschisa = esteRezolvata;
		}
		else
			this->esteDeschisa = 0;
		if (categorie.length() > 0)
		{
			this->categorie = categorie;
		}
		else
			this->categorie = "Anonim";
	}
	Petitie(const Petitie& p):idPetitie(p.idPetitie)
	{
		if (p.denumirePetitie != nullptr)
		{
			this->denumirePetitie = new char[strlen(p.denumirePetitie) + 1];
			strcpy(this->denumirePetitie, p.denumirePetitie);
		}
		else
		{
			this->denumirePetitie = new char[strlen("Anonim") + 1];
			strcpy(this->denumirePetitie, "Anonim");
		}
		if (p.nrZileDeLaDep > 0)
		{
			this->nrZileDeLaDep = p.nrZileDeLaDep;
		}
		else
		{
			this->nrZileDeLaDep = 0;
		}
		if (p.esteRezolvata == 1)
		{
			this->esteRezolvata = p.esteRezolvata;
		}
		else
			this->esteRezolvata = 0;
		if (p.esteDeschisa == 1)
		{
			this->esteDeschisa = p.esteRezolvata;
		}
		else
			this->esteDeschisa = 0;
		if (p.categorie.length() > 0)
		{
			this->categorie = p.categorie;
		}
		else
			this->categorie = "Anonim";
	}
	friend ostream& operator<<(ostream& out, const Petitie& p)
	{
		out << "\n----------<<---------------";
		out << "\nId petitie: " << p.idPetitie;
		if (p.denumirePetitie != nullptr)
		{
			out << "\nDenumire petitie: " << p.denumirePetitie;
		}
		out << "\nNr zile de la depunere: " << p.nrZileDeLaDep;
		out << "\nEste rezolvata? "<<p.esteRezolvata;
		out << "\nEste deschisa? "<<p.esteDeschisa;
		out << "\nCategorie: " << p.categorie;
		out << "\n----------<<---------------";
		return out;
	}
	friend ofstream& operator<<(ofstream& out, const Petitie& p)
	{
		if (p.denumirePetitie != nullptr)
		{
			out  << p.denumirePetitie<<endl;
		}
		out << p.nrZileDeLaDep<<endl;
		out << p.esteRezolvata<<endl;
		out << p.esteDeschisa<<endl;
		out << p.categorie<<endl;
		return out;
	}
	friend istream& operator>>(istream& in, Petitie& p)
	{
		delete[] p.denumirePetitie;
		p.denumirePetitie = nullptr;
		cout << "\nIntroduceti denumirea: ";
		in >> ws;
		string buffer;
		getline(in, buffer);
		p.denumirePetitie = new char[buffer.size() + 1];
		strcpy(p.denumirePetitie, buffer.data());
		cout << "\nIntroduceti nr de zile de la depunere: ";
		in >> p.nrZileDeLaDep;
		cout << "\nEste rezolvata? 1-da 0-nu: ";
		in >> p.esteRezolvata;
		cout << "\nEste deschisa? 1-da 0-nu: ";
		in >> p.esteDeschisa;
		cout << "\nIntroduceti categoria: ";
		string buffer1;
		in >> ws;
		getline(in, buffer1);
		p.categorie = buffer1;
		return in;
	}
	friend ifstream& operator>>(ifstream& in, Petitie& p)
	{
		delete[] p.denumirePetitie;
		p.denumirePetitie = nullptr;
		in >> ws;
		string buffer;
		getline(in, buffer);
		p.denumirePetitie = new char[buffer.size() + 1];
		strcpy(p.denumirePetitie, buffer.data());
		
		in >> p.nrZileDeLaDep;
		
		in >> p.esteRezolvata;
		
		in >> p.esteDeschisa;
		string buffer1;
		in >> ws;
		getline(in, buffer1);
		p.categorie = buffer1;
		return in;
	}
	int getNrZile()
	{
		return this->nrZileDeLaDep;
	}
	void setNrZile(int nrZileDeLaDep)
	{
		if (nrZileDeLaDep > 0)
		{
			this->nrZileDeLaDep = nrZileDeLaDep;
		}
		else
			this->nrZileDeLaDep = 0;
	}
	Petitie& operator=(const Petitie& p)
	{
		if (this != &p)
		{
			delete[] this->denumirePetitie;
			this->denumirePetitie = nullptr;
			if (p.denumirePetitie != nullptr)
			{
				this->denumirePetitie = new char[strlen(p.denumirePetitie) + 1];
				strcpy(this->denumirePetitie, p.denumirePetitie);
			}
			else
			{
				this->denumirePetitie = new char[strlen("Anonim") + 1];
				strcpy(this->denumirePetitie, "Anonim");
			}
			if (p.nrZileDeLaDep > 0)
			{
				this->nrZileDeLaDep = p.nrZileDeLaDep;
			}
			else
			{
				this->nrZileDeLaDep = 0;
			}
			if (p.esteRezolvata != false)
			{
				this->esteRezolvata = p.esteRezolvata;
			}
			else
				this->esteRezolvata = false;
			if (p.esteDeschisa != false)
			{
				this->esteDeschisa = p.esteRezolvata;
			}
			else
				this->esteDeschisa = false;
			if (p.categorie.length() > 0)
			{
				this->categorie = p.categorie;
			}
			else
				this->categorie = "Anonim";
		}
		return *this;
	}
	~Petitie()
	{
		delete[] this->denumirePetitie;
		this->denumirePetitie = nullptr;
	}

	bool operator!()
	{
		if (this->esteRezolvata == false && this->nrZileDeLaDep > 30)
			return true;
		return false;
	}

	bool operator~()
	{
		if (this->esteDeschisa == false)
			this->esteDeschisa = true;
		
		return this->esteDeschisa;
	}

	virtual string NaturaPetitie()
	{
		return "\nAceasta este o petitie normala pe foaie";
	}

	friend bool operator<(const Petitie& p1, const Petitie& p2)
	{
		return p1.idPetitie < p2.idPetitie;
	}

};
class PetitieOnline:public Petitie
{
private:
	string site;
	int nrSemnaturi;
public:
	PetitieOnline():Petitie()
	{
		this->site = "Anonim";
		this->nrSemnaturi = 0;
	}
	PetitieOnline(int idPetitie, int nrZileDeLaDep, bool esteRezolvata, const char* denumirePetitie, bool esteDeschisa,string categorie, string site, int nrSemnaturi) :Petitie(idPetitie, nrZileDeLaDep, esteRezolvata, denumirePetitie, esteDeschisa,categorie)
	{
		if (site.length() > 0)
		{
			this->site = site;
		}
		if (nrSemnaturi > 0)
		{
			this->nrSemnaturi = nrSemnaturi;
		}
	}
	PetitieOnline(Petitie a, string site, int nrSemnaturi) :Petitie(a)
	{
		if (site.length() > 0)
		{
			this->site = site;
		}
		if (nrSemnaturi > 0)
		{
			this->nrSemnaturi = nrSemnaturi;
		}
	}
	PetitieOnline(const PetitieOnline& p) :Petitie(p)
	{
		if (p.site.length() > 0)
		{
			this->site = p.site;
		}
		if (p.nrSemnaturi > 0)
		{
			this->nrSemnaturi = p.nrSemnaturi;
		}
	}
	PetitieOnline& operator=(const PetitieOnline& p)
	{
		if (this != &p)
		{
			this->Petitie::operator=(p);
			if (p.site.length() > 0)
			{
				this->site = p.site;
			}
			if (p.nrSemnaturi > 0)
			{
				this->nrSemnaturi = p.nrSemnaturi;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const PetitieOnline& p)
	{
		out << "\n------------------------------";
		out << (Petitie&)p;
		out << "\nSite: " << p.site;
		out << "\nNr semnaturi: " << p.nrSemnaturi;
		out << "\n------------------------------";
		return out;
	}
	~PetitieOnline() {}
	 string NaturaPetitie()
	{
		return "\nAceasta este o petitie online";
	}
	
};
int main()
{
	Petitie p1;
	Petitie p2(1, 31, 0, "mediu",0,"Politica");
	cout << p1;
	Petitie p4(4, 18, 1, "Protejarea", 1, "Admin");
	Petitie p5(5, 30, 0, "Organizare", 0, "Politica");
	//GET / SET
	/*cout <<endl<< p2.getNrZile();
	p2.setNrZile(20);
	cout <<endl<< p2.getNrZile();*/

	Petitie p3(2,15,1,"interzicere ceva",1,"Mediu");
	cout << p3;

	if (!p2)
	{
		cout << "\nPetitia nu are raspuns sau a depasit terminul legal de 30 de zile";
	}
	else
	{
		cout << "\nPetitia are raspuns si nu a depasit terminul legal de 30 de zile";
	}
	if (~p2)
	{
		cout << "\ndeschisa,rezolvata";
	}
	else
		cout << "\nnu e deschisa, nu e rezolvata";

	/*Petitie p4;
	cin >> p4; cout << p4;*/

	/*ofstream file1("petitie.txt");
	file1 << p2;*/

	/*Petitie p5;
	ifstream file1("petitie.txt");
	if (file1.is_open())
	{
		file1 >> p5;
		cout << p5;
	}
	else
		cout << "\nFisierul nu se deschide";
	file1.close();*/

	cout << endl << "\nMOSTENIRE";
	
	PetitieOnline o2(4, 18, 1, "Protejarea", 1,"Admin", "Sursa", 100);
	cout << o2;

	PetitieOnline o1(p2,"realtv",200);
	cout << o1;


	//exemplificati conceptul de virtualizare
	Petitie* pp = new Petitie(p2);
	Petitie* pp1 = new PetitieOnline(o2);

	Petitie* lista[10];
	lista[0] = &p2;
	lista[1] = &o2;

	cout << lista[0]->NaturaPetitie() << endl;
	cout << lista[1]->NaturaPetitie() << endl;


	map<Petitie,string> mapP;
	mapP[p2] ="Politica" ;
	mapP[p3] = "Mediu";
	mapP[p4] = "Admin";
	mapP[p5] = "Politica";
	
	map<Petitie, string> ::iterator itMap;
	cout << "\nPetiile pentru categoria politica: ";
	for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
	{
		if (itMap->second == "Politica")
		{
			cout << itMap->first;
		}
	}
	
		cout << "\nPetiile pentru categoria mediu: ";
		for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
		{
			if (itMap->second == "Mediu")
			{
				cout << itMap->first;
			}

		}
		cout << "\nPetiile pentru categoria admin: ";
		for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
		{

			if (itMap->second == "Admin")
			{

				cout << itMap->first;

			}
		}
	
}