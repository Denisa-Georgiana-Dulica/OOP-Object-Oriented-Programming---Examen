#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<cmath>
using namespace std;

class Element
{
private:
	float valoare = 0;
	int frecventa = 0;
	static int nrValori;
public:
	Element()
	{

	}
	Element(int valoare, float frecventa)
	{
		if (valoare > 0)
		{
			this->valoare = valoare;
		}
		if (frecventa > 0)
		{
			this->frecventa = frecventa;
		}
		nrValori++;
	}
	Element(const Element& e)
	{
		if (e.valoare > 0)
		{
			this->valoare = e.valoare;
		}
		if (e.frecventa > 0)
		{
			this->frecventa = e.frecventa;
		}
	}
	Element& operator=(const Element& e)
	{
		if (this != &e)
		{
			if (e.valoare > 0)
			{
				this->valoare = e.valoare;
			}
			if (e.frecventa > 0)
			{
				this->frecventa = e.frecventa;
			}
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Element& e)
	{
		out << "\n-----------------------";
		out << "\nValoare: " << e.valoare << " - Frecventa: " << e.frecventa;
		return out;
	}

	~Element()
	{

	}

	float getValoare()
	{
		return this->valoare;
	}
	int getFrecventa()
	{
		return this->frecventa;
	}
	
};
int Element::nrValori = 0;
class SerieStatistica
{
private:
	Element* perechi = nullptr;
	int nrPerechi = 0;
public:
	SerieStatistica()
	{

	}
	SerieStatistica(Element* perechi,int nrPerechi)
	{
		if (perechi != nullptr && nrPerechi>0)
		{
			this->nrPerechi = nrPerechi;
			this->perechi = new Element[this->nrPerechi];
			for (int i = 0; i < this->nrPerechi; i++)
			{
				this->perechi[i] = perechi[i];
			}
		}
	}
	SerieStatistica(const SerieStatistica& s)
	{
		if (s.perechi != nullptr && s.nrPerechi > 0)
		{
			this->nrPerechi = s.nrPerechi;
			this->perechi = new Element[this->nrPerechi];
			for (int i = 0; i < this->nrPerechi; i++)
			{
				this->perechi[i] = s.perechi[i];
			}
		}
	}
	SerieStatistica& operator=(const SerieStatistica& s)
	{
		if (this != &s)
		{
			delete[] this->perechi;
			this->perechi = nullptr;
			if (s.perechi != nullptr && s.nrPerechi > 0)
			{
				this->nrPerechi = s.nrPerechi;
				this->perechi = new Element[this->nrPerechi];
				for (int i = 0; i < this->nrPerechi; i++)
				{
					this->perechi[i] = s.perechi[i];
				}
			}
			else
			{
				this->nrPerechi = 0;
				this->perechi = nullptr;
			}
		}
		return *this;
	}
	
	friend ostream& operator<<(ostream& out, const SerieStatistica& s)
	{
		Element aux;
		if (s.perechi != nullptr && s.nrPerechi > 0)
		{
			out << "\nNr perechi: " << s.nrPerechi;
			out << "\nPerechi: ";
			for (int i = 0; i < s.nrPerechi; i++)
			{
				for (int j = i + 1; j < s.nrPerechi; j++)
				{
					if (s.perechi[i].getValoare() > s.perechi[j].getValoare())
					{
						aux = s.perechi[i];
						s.perechi[i] = s.perechi[j];
						s.perechi[j] = aux;
					}
				}
			}
			for (int i = 0; i < s.nrPerechi; i++)
			{
				out << s.perechi[i];
			}
		}
		else
		{
			out << "\nNr perechi: " << s.nrPerechi;
			out << "\nPerechi:- ";
		}
		return out;
	}
	~SerieStatistica()
	{
		delete[] this->perechi;
		this->perechi = nullptr;
	}

	float media()
	{
		float medie = 0;
		float suma = 0;
		if (this->perechi != nullptr && this->nrPerechi > 0)
		{
			for (int i = 0; i < this->nrPerechi; i++)
			{
				suma += this->perechi[i].getValoare();
			}
			medie = suma / this->nrPerechi;
		}
		return medie;
	}
	float Dispersie(float medie)
	{
		float dispersie = 0;
		float suma = 0;
		if (this->perechi != nullptr && this->nrPerechi > 0)
		{
			for (int i = 0; i < this->nrPerechi; i++)
			{
				float patrat= (this->perechi[i].getValoare() - medie)* (this->perechi[i].getValoare() - medie);
				suma += patrat;
			}
			dispersie = suma / this->nrPerechi;
			return dispersie;
		}
	}
	static float CoefCorel(const SerieStatistica& s1, float medie1, float dispersie1, const SerieStatistica& s2, float medie2, float dispersie2)
	{
		float coefCorel = 0;
		float suma = 0;
		float produs2 = 0;
		if (s1.perechi != nullptr && s1.nrPerechi > 0 && s2.perechi != nullptr && s2.nrPerechi > 0)
		{
			for (int i = 0; i < s1.nrPerechi; i++)
			{
				float produs = (s1.perechi[i].getValoare() - medie1) * (s2.perechi[i].getValoare() - medie2);
				suma += produs;
				produs2 = sqrt(dispersie1 *s1.nrPerechi* dispersie2*s2.nrPerechi);
			}
			coefCorel = suma / produs2;
			return coefCorel;
		}
	}
	SerieStatistica& operator+=(const SerieStatistica& s)
	{
		if (this->perechi != nullptr && this->nrPerechi > 0 && s.perechi != nullptr && s.nrPerechi > 0)
		{
			
			Element* temp = new Element[this->nrPerechi + s.nrPerechi];
			for (int i = 0; i < this->nrPerechi; i++)
			{
				temp[i] = this->perechi[i];
			}
			for (int i = 0; i < s.nrPerechi; i++)
			{
				temp[s.nrPerechi+i] = s.perechi[i];
			}
			delete[] this->perechi;
			this->perechi = nullptr;
			this->perechi = temp;
			this->nrPerechi += s.nrPerechi;
			return *this;
		}
	}
	SerieStatistica& operator+=(const Element& e)
	{
		if (this->perechi != nullptr && this->nrPerechi > 0)
		{
			SerieStatistica st = *this;
			Element* temp = new Element[st.nrPerechi +1];
			for (int i = 0; i < st.nrPerechi; i++)
			{
				temp[i] = st.perechi[i];
			}
			temp[st.nrPerechi] = e;
			delete[] this->perechi;
			this->perechi = nullptr;
			this->perechi = temp;
			this->nrPerechi ++;
			return *this;
		}
	}
	SerieStatistica& operator-=(float valoare)
	{
		if (this->perechi != nullptr && this->nrPerechi > 0)
		{
			for (int i = 0; i < this->nrPerechi; i++)
			{
				if (this->perechi[i].getValoare() == valoare)
				{
					for (int j = i; j < this->nrPerechi; j++)
					{
						this->perechi[j] = this->perechi[j + 1];
						this->nrPerechi--;
					}
				}
			}
			return *this;
		}
	}
	
	
};

int main()
{
	Element e1(4, 5);
	Element e2(3, 7);
	Element e3(5, 2);
	
	Element e4(6, 5);
	Element e5(2, 7);
	Element e6(8, 2);

	Element perechi1[] = { e1,e2,e3 };
	Element perechi2[] = { e4,e5,e6 };

	SerieStatistica s1(perechi1, 3);
	cout << s1;
	cout << endl;
	float media1= s1.media();
	cout<<"\nMedia seriei statistice: "<<media1;
	float dispersie1 = s1.Dispersie(media1);
	cout << "\nDispersia seriei statistice: " <<dispersie1;
	cout << endl;
	SerieStatistica s2(perechi2, 3);
	cout << s2;
	float media2 = s2.media();
	cout << "\nMedia seriei statistice: " << media2;
	float dispersie2 = s2.Dispersie(media2);
	cout << "\nDispersia seriei statistice: " << s2.Dispersie(media2);
	cout << endl;
	cout << "\nCoeficientul de corelatie al seriei statistice: " << SerieStatistica:: CoefCorel(s1,media1,dispersie1, s2,media2,dispersie2);

	/*s1 += s2;
	cout << s1;*/

	/*s1+=e4;
	cout << s1;

	cout << endl;
	s1 -= (6);
	cout << s1;*/
	cout << endl;
	float suma = 0;
	int nr = 0;
	map<float, int> perechi;
	perechi[4] = 5;
	perechi[3] = 7;
	perechi[5] = 2;
	map<float, int> ::iterator itMap;
	for (itMap = perechi.begin(); itMap != perechi.end(); itMap++)
	{
		cout << "\nValoare: " << itMap->first << " - Frecventa: " << itMap->second << endl;
		suma += itMap->first;
		nr++;
	}
	float medie = suma / nr;
	cout << "\nMedia seriei statistice: " << medie;
	float suma1 = 0;
	for (itMap = perechi.begin(); itMap != perechi.end(); itMap++)
	{
		suma1 += (itMap->first - medie) * (itMap->first - medie);
	}
	float dispersie = suma1 / nr;
	cout << "\nDispersia seriei statistice: " << dispersie;


}