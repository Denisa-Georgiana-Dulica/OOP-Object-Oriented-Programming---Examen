#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string> //pt const ca un string programul nu da eroare daca nu il initializez in linia de initializatori din cauza acestei librarii
using namespace std;

class StreamingFilme
{
private:
	const string codPlatforma;
protected:
	string nume;
	int durata;//luni
	float pretAbonament;
	string* denumireProductii;
	int nrProductii;
	int* vizualizariProductii;
public:
	StreamingFilme():codPlatforma("Anonim")
	{
		this->nume = "Anonim";
		this->durata = 0;
		this->pretAbonament = 0;
		this->denumireProductii = nullptr;
		this->nrProductii = 0;
		this->vizualizariProductii = nullptr;
	}
	StreamingFilme(string codPlatforma,string nume, int durata, float pretAbonament, string* denumireProductii, int nrProductii, int* vizualizariProductii):codPlatforma(codPlatforma)
	{
		if (nume.length() > 0)
		{
			this->nume = nume;
		}
		else
			this->nume = "Anonim";
		if (durata > 0)
		{
			this->durata = durata;
		}
		else
			this->durata = 0;
		if (pretAbonament > 0)
		{
			this->pretAbonament = pretAbonament;
		}
		else
			this->pretAbonament = 0;
		if (nrProductii > 0)
		{
			this->nrProductii = nrProductii;
		}
		else
		{
			this->nrProductii = 0;
		}
			if (denumireProductii != nullptr && nrProductii > 0)
			{
				this->denumireProductii = new string[this->nrProductii];
				for (int i = 0; i < this->nrProductii; i++)
				{
					this->denumireProductii[i] = denumireProductii[i];
					
				}
			}
			else
				this->denumireProductii = nullptr;
			if (vizualizariProductii != nullptr && nrProductii > 0)
			{
				this->vizualizariProductii = new int[this->nrProductii];
				for (int i = 0; i < this->nrProductii; i++)
				{
					this->vizualizariProductii[i] = vizualizariProductii[i];
					
				}
			}
			else
				this->vizualizariProductii = nullptr;
		
		
	}
	StreamingFilme(const StreamingFilme& s):codPlatforma(s.codPlatforma)
	{
		if (s.nume.length() > 0)
		{
			this->nume = s.nume;
		}
		else
			this->nume = "Anonim";
		if (s.durata > 0)
		{
			this->durata = s.durata;
		}
		else
			this->durata = 0;
		if (s.pretAbonament > 0)
		{
			this->pretAbonament = s.pretAbonament;
		}
		else
			this->pretAbonament = 0;
		if (s.nrProductii > 0)
		{
			this->nrProductii = s.nrProductii;
		}
		else
		{
			this->nrProductii = 0;
		}
		if (s.denumireProductii != nullptr && s.nrProductii > 0)
		{
			this->denumireProductii = new string[this->nrProductii];
			for (int i = 0; i < this->nrProductii; i++)
			{
				this->denumireProductii[i] = s.denumireProductii[i];

			}
		}
		else
			this->denumireProductii = nullptr;
		if (s.vizualizariProductii != nullptr && s.nrProductii > 0)
		{
			this->vizualizariProductii = new int[this->nrProductii];
			for (int i = 0; i < this->nrProductii; i++)
			{
				this->vizualizariProductii[i] = s.vizualizariProductii[i];
			}
		}
		else
			this->vizualizariProductii = nullptr;
	}
	StreamingFilme& operator=(const StreamingFilme& s)
	{
		if (this != &s)
		{
			delete[] this->denumireProductii;
			this->denumireProductii = nullptr;
			delete[] this->vizualizariProductii;
			this->vizualizariProductii = nullptr;
			if (s.nume.length() > 0)
			{
				this->nume = s.nume;
			}
			else
				this->nume = "Anonim";
			if (s.durata > 0)
			{
				this->durata = s.durata;
			}
			else
				this->durata = 0;
			if (s.pretAbonament > 0)
			{
				this->pretAbonament = s.pretAbonament;
			}
			else
				this->pretAbonament = 0;
			if (s.nrProductii > 0)
			{
				this->nrProductii = s.nrProductii;
			}
			else
			{
				this->nrProductii = 0;
			}
			if (s.denumireProductii != nullptr && s.nrProductii > 0)
			{
				this->denumireProductii = new string[this->nrProductii];
				for (int i = 0; i < this->nrProductii; i++)
				{
					this->denumireProductii[i] = s.denumireProductii[i];

				}
			}
			else
				this->denumireProductii = nullptr;
			if (s.vizualizariProductii != nullptr && s.nrProductii > 0)
			{
				this->vizualizariProductii = new int[this->nrProductii];
				for (int i = 0; i < this->nrProductii; i++)
				{
					this->vizualizariProductii[i] = s.vizualizariProductii[i];
				}
			}
			else
				this->vizualizariProductii = nullptr;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const StreamingFilme& s)
	{
		out << "\n--------------------------------";
		out << "\nCod platforma: " << s.codPlatforma;
		out << "\nNume platforma: " << s.nume;
		out << "\nDurata abonament: " << s.durata;
		out << "\nPret abonament: " << s.pretAbonament;
		out << "\nNr productii: " << s.nrProductii;
		if (s.denumireProductii != nullptr && s.vizualizariProductii != nullptr && s.nrProductii > 0)
		{
			cout << "\nDenumire - Numar vizualizari:"<<endl;
			for (int i = 0; i < s.nrProductii; i++)
			{
				out << s.denumireProductii[i] << " - " << s.vizualizariProductii[i]<<endl;

			}
		}
		else
		{
			cout << "\nDenumire - Numar vizualizari: - ";
		}
		return out;
	}
	~StreamingFilme()
	{
		delete[] this->denumireProductii;
		this->denumireProductii = nullptr;
		delete[] this->vizualizariProductii;
		this->vizualizariProductii = nullptr;
	}
	//GETTERI SI SETTERI
	float getPretAbonament()
	{
		return this->pretAbonament;
	}
	void setPretAbonament(float pretAbonament)
	{
		if (pretAbonament > 0)
		{
			this->pretAbonament = pretAbonament;
		}
	}

	//GETTERI SETTER PT VECTORI DINAMICI
	int getNrProductii()
	{
		return this->nrProductii;
	}
	string* getDenumireProductii()
	{
		return this->denumireProductii;
	}
	int* getVizualizari()
	{
		return this->vizualizariProductii;
	}
	void setProductii(int nrProductii,string* denumireProductii,int* vizualizariProductii)
	{
		if (nrProductii > 0 && denumireProductii!=nullptr && vizualizariProductii!=nullptr)
		{
			if (this->denumireProductii != nullptr && this->vizualizariProductii != nullptr)
			{
				delete[] this->denumireProductii;
				this->denumireProductii = nullptr;
				delete[] this->vizualizariProductii;
				this->vizualizariProductii = nullptr;
			}
				this->nrProductii = nrProductii;
				this->denumireProductii = new string[this->nrProductii];
				this->vizualizariProductii = new int[this->nrProductii];
				for (int i = 0; i < this->nrProductii; i++)
				{
					this->denumireProductii[i] = denumireProductii[i];
					this->vizualizariProductii[i] = vizualizariProductii[i];
				}
			
		}
	}
	StreamingFilme& operator+=(string productie)
	{
		if (this->denumireProductii != nullptr && this->vizualizariProductii != nullptr && this->nrProductii > 0)
		{
			StreamingFilme s = *this;
			string* temp = new string[s.nrProductii + 1];
			int* temp1 = new int[s.nrProductii + 1];
			for (int i = 0; i < s.nrProductii; i++)
			{
				if (s.denumireProductii[i] != productie)
				{
					temp[i] = s.denumireProductii[i];
					temp1[i] = s.vizualizariProductii[i];
				}
			}
			for (int i = 0; i < s.nrProductii; i++)
			{
				if (s.denumireProductii[i] == productie)
				{
					cout << "\nProductia deja exista";
					return *this;
				}
			}
			temp[s.nrProductii] = productie;
			temp1[s.nrProductii] = 0;
			delete[] this->denumireProductii;
			this->denumireProductii = nullptr;
			delete[] this->vizualizariProductii;
			this->vizualizariProductii = nullptr;
			this->denumireProductii = temp;
			this->vizualizariProductii = temp1;
			this->nrProductii++;
			return *this;
		}
	}
	StreamingFilme& operator-=(string productie)
	{
		if (this->denumireProductii != nullptr && this->vizualizariProductii != nullptr && this->nrProductii > 0)
		{
			int ok = 0;
			for (int i = 0; i < this->nrProductii; i++)
			{
				if (this->denumireProductii[i] == productie)
				{
					ok = 1;
				}
				if(ok==1)
				{
					for (int j = i; j < this->nrProductii-1; j++)
					{
						this->denumireProductii[j] = this->denumireProductii[j + 1];
					}
					this->nrProductii--;
				}
			}
			if (ok == 0)
				cout << "\nNu exista filmul";
			return *this;
		}
	}
	explicit operator double()
	{
		if (this->denumireProductii != nullptr && this->vizualizariProductii != nullptr && this->nrProductii > 0)
		{
			int pozitie = 0;
			float max = this->vizualizariProductii[0];
			for (int i = 1; i < this->nrProductii; i++)
			{
				if (this->vizualizariProductii[i] > max)
				{
					max = this->vizualizariProductii[i];
					pozitie = i;
				}
			}
			return max;
			

		}
	}
	void ceaMaiVizionata()
	{
		double vizionari = double(*this);
		int pozitie = 0;
		for (int i = 1; i < this->nrProductii; i++)
		{
			if (this->vizualizariProductii[i] == vizionari)
			{
				pozitie = i;
			}
		}
		cout << "\nProductia cea mai vizionata: " << this->denumireProductii[pozitie];
	}
	virtual int afiseazaTop2()
	{
		map<int, string> mapS;
		for (int i = 0; i < this->nrProductii; i++)
		{
			mapS[this->vizualizariProductii[i]] = this->denumireProductii[i];
		}
		map<int, string>::reverse_iterator itMap;
		int nr = 0;
		for (itMap = mapS.rbegin(); itMap != mapS.rend(); itMap++)
		{
			cout << itMap->first << " - " << itMap->second << endl;
			nr++;
			if (nr == 2)
			{
				return 0;
			}
		}
	}
	friend bool operator>(const StreamingFilme& s1, const StreamingFilme& s2)
	{
		return s1.pretAbonament > s2.pretAbonament;
	}
};
class StreamingSerialeDocumentare: public StreamingFilme
{
private:
	int nrSeriale=0;
	string* seriale=nullptr;
	int* vizionariSeriale = nullptr;
public:
	StreamingSerialeDocumentare() :StreamingFilme()
	{

	}
	StreamingSerialeDocumentare(string codPlatforma, string nume, int durata, float pretAbonament, string* denumireProductii, int nrProductii, int* vizualizariProductii, int nrSeriale,string* seriale,int* vizionariSeriale) :StreamingFilme(codPlatforma,nume,durata,pretAbonament, denumireProductii,nrProductii, vizualizariProductii)
	{
		if (nrSeriale > 0)
		{
			this->nrSeriale = nrSeriale;
		}
		if (seriale != nullptr && nrSeriale>0)
		{
			
			this->seriale = new string[this->nrSeriale];
			for (int i = 0; i < this->nrSeriale; i++)
			{
				this->seriale[i] = seriale[i];
			}
		}
		if (vizionariSeriale != nullptr && nrSeriale > 0)
		{
			
			this->vizionariSeriale = new int[this->nrSeriale];
			for (int i = 0; i < this->nrSeriale; i++)
			{
				this->vizionariSeriale[i] = vizionariSeriale[i];
			}
		}
	}
	StreamingSerialeDocumentare(const StreamingSerialeDocumentare& s):StreamingFilme(s)
	{
		if (s.nrSeriale > 0)
		{
			this->nrSeriale = s.nrSeriale;
		}
		if (s.seriale != nullptr && s.nrSeriale > 0)
		{
			
			this->seriale = new string[this->nrSeriale];
			for (int i = 0; i < this->nrSeriale; i++)
			{
				this->seriale[i] = s.seriale[i];
			}
		}
		if (s.vizionariSeriale != nullptr && s.nrSeriale > 0)
		{
			
			this->vizionariSeriale = new int[this->nrSeriale];
			for (int i = 0; i < this->nrSeriale; i++)
			{
				this->vizionariSeriale[i] = s.vizionariSeriale[i];
			}
		}
	}
	//DOWNCAST
	StreamingSerialeDocumentare(const StreamingFilme& s) :StreamingFilme(s)
	{
		
			this->nrSeriale =1;
			this->seriale = new string[this->nrSeriale];
			string seriale[] = { "aaaaaa" };
			for (int i = 0; i < this->nrSeriale; i++)
			{
				this->seriale[i] = seriale[i];
			}
		
			this->vizionariSeriale = new int[this->nrSeriale];
			int vizionari[] = { 2000 };
			for (int i = 0; i < this->nrSeriale; i++)
			{
				this->vizionariSeriale[i] = vizionari[i];
			}
		
	}
	StreamingSerialeDocumentare& operator=(const StreamingSerialeDocumentare& s)
	{
		if (this != &s)
		{
			delete[] this->seriale;
			this->seriale = nullptr;
			delete[] this->vizionariSeriale;
			this->vizionariSeriale = nullptr;
			this->StreamingFilme::operator=(s);
			if (s.nrSeriale > 0)
			{
				this->nrSeriale = s.nrSeriale;
			}
			if (s.seriale != nullptr && s.nrSeriale > 0)
			{

				this->seriale = new string[this->nrSeriale];
				for (int i = 0; i < this->nrSeriale; i++)
				{
					this->seriale[i] = s.seriale[i];
				}
			}
			if (s.vizionariSeriale != nullptr && s.nrSeriale > 0)
			{

				this->vizionariSeriale = new int[this->nrSeriale];
				for (int i = 0; i < this->nrSeriale; i++)
				{
					this->vizionariSeriale[i] = s.vizionariSeriale[i];
				}
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const StreamingSerialeDocumentare& s)
	{
		out << (StreamingFilme&)s;
		out << "\nNr seriale: " << s.nrSeriale;
		
		if (s.seriale!= nullptr && s.vizionariSeriale != nullptr && s.nrSeriale > 0)
		{
			cout << "\nDenumire - Numar vizualizari:" << endl;
			for (int i = 0; i < s.nrSeriale; i++)
			{
				out << s.seriale[i] << " - " << s.vizionariSeriale[i] << endl;

			}
		}
		else
		{
			cout << "\nDenumire - Numar vizualizari: - ";
		}
		return out;
	}
	~StreamingSerialeDocumentare()
	{
		delete[] this->seriale;
		this->seriale = nullptr;
		delete[] this->vizionariSeriale;
		this->vizionariSeriale = nullptr;
	}
	int afiseazaTop2()
	{
		map<int, string> mapS;
		for (int i = 0; i < this->nrSeriale; i++)
		{
			mapS[this->vizionariSeriale[i]] = this->seriale[i];
		}
		map<int, string>::reverse_iterator itMap;
		int nr = 0;
		for (itMap = mapS.rbegin(); itMap != mapS.rend(); itMap++)
		{
			cout << itMap->first << " - " << itMap->second << endl;
			nr++;
			if (nr == 2)
			{
				return 0;
			}
		}
	}
	
};
template<class TIP>
void sortare(TIP& a,TIP& b)
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
	/*StreamingFilme sf;
	cout<<sf.getPretAbonament()<<endl;
	sf.setPretAbonament(100);
	cout << sf.getPretAbonament();
	
	string denumire[] = { "GoT","You","Wither" };
	int vizualizari[] = { 55511,42231,44121 };
	sf.setProductii(3, denumire, vizualizari);
	cout << "\nGETTERI SETTER PT VECTORI DINAMICI: ";
	cout << sf.getNrProductii() << endl;
	for (int i = 0; i < sf.getNrProductii(); i++)
	{
		cout << sf.getDenumireProductii()[i]<<" ";
		cout << sf.getVizualizari()[i]<<" " << endl;
	}*/
	cout << endl << "\nCons cu parametrii: " << endl;
	string productii1[] = { "Harry poter","Flash","Batman"};
	int vizionari1[] = { 12000,20000,25000 };
	StreamingFilme sf1("NFL", "Netflix", 3, 80, productii1, 3, vizionari1);
	cout << sf1;

	
	StreamingFilme sf5("DN", "Disney", 3, 90, productii1, 3, vizionari1);
	cout << sf5;

	cout <<endl<< "\nCons implicit: " << endl;
	StreamingFilme sf2;
	cout << sf2;
	cout << endl << "\nCons copy: " << endl;
	StreamingFilme sf3 = sf1;
	cout << sf3;
	cout << endl << "\nOp = " << endl;
	StreamingFilme sf4;
	sf4 = sf1;
	cout << sf4;
	cout << endl << "\nOp += " << endl;
	sf1 += "Transformers";
	cout << sf1;
	cout << endl << "\nOp -= " << endl;
	sf1 -= "Gossip girl";
	cout << sf1;

	double ceaMaiVizionata = double(sf1);
	cout << ceaMaiVizionata;

	sf1.ceaMaiVizionata();

	cout << "\nNoua clasa: "<<endl;
	string productiiseriale2[] = { "Lucifer","Arrow","Flash" ,"Gossip girl"};
	int vizionariseriale2[] = { 2000,3000,4000,5000 };
	StreamingSerialeDocumentare ssd("HBO", "HBO GO", 3, 60, productii1, 3, vizionari1, 4, productiiseriale2, vizionariseriale2);
	cout << ssd;

	//DOWNCASTING
	StreamingSerialeDocumentare ssd1 = sf1;
	cout << ssd1;

	StreamingSerialeDocumentare ssd2 = ssd;
	cout << ssd2;

	StreamingSerialeDocumentare ssd3;
	ssd3 = ssd;
	cout << ssd3;
	cout << endl;
	sf1.afiseazaTop2();
	cout << endl;
	ssd.afiseazaTop2();


	//TEMPLATE
	cout << 33 << endl;
	cout << ssd << endl;
	cout << sf1;
	//TEMPLATE METODA MEA
	sortare(sf5,sf1);
	cout << sf5.getPretAbonament() <<" " << sf1.getPretAbonament();
}