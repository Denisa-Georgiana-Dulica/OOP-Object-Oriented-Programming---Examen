#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
using namespace std;

class IConsum
{
public:
	virtual void CostLuna() = 0;
};
enum SurseEnergie
{
	EOLIANA=0,SOLARA=1,HIDROELECTRICA=2
};
class FurnizorEnergie :public IConsum
{
	char* numeClient = nullptr;
	float consumLunar[12];
	const int idContract;
	float pretKwh = 0;
	SurseEnergie sursa = EOLIANA;
	static int nrContracte;
	static map<int, FurnizorEnergie> mapP;
public:
	FurnizorEnergie() :idContract(0)
	{
		for (int i = 0; i < 12; i++)
		{
			this->consumLunar[i] = 0;
		}

		this->numeClient = new char[strlen("Anonim") + 1];
		strcpy(this->numeClient, "Anonim");
	}
	FurnizorEnergie(int idContract,const char* numeClient, float consumLunar[12],float pretKwh, SurseEnergie sursa) :idContract(idContract)
	{
		if (numeClient != nullptr)
		{
			this->numeClient = new char[strlen(numeClient) + 1];
			strcpy(this->numeClient, numeClient);
		}
		for (int i = 0; i < 12; i++)
		{
			if (consumLunar[i] >= 0)
			{
				this->consumLunar[i] = consumLunar[i];
			}
			else
			{
				this->consumLunar[i] = 0;
			}
		}
		if (pretKwh > 0)
		{
			this->pretKwh = pretKwh;
		}
		this->sursa = sursa;
		mapP[idContract] = *this;
	}
	FurnizorEnergie(const FurnizorEnergie& f):idContract(f.idContract)
	{
		if (f.numeClient != nullptr)
		{
			this->numeClient = new char[strlen(f.numeClient) + 1];
			strcpy(this->numeClient, f.numeClient);
		}
		for (int i = 0; i < 12; i++)
		{
			if (f.consumLunar[i] >= 0)
			{
				this->consumLunar[i] = f.consumLunar[i];
			}
			else
			{
				this->consumLunar[i] = 0;
			}
		}
		if (f.pretKwh > 0)
		{
			this->pretKwh = f.pretKwh;
		}
		this->sursa = f.sursa;
	}
	FurnizorEnergie& operator=(const FurnizorEnergie& f)
	{
		if (this != &f)
		{
			delete[] this->numeClient;
			this->numeClient = nullptr;
			if (f.numeClient != nullptr)
			{
				this->numeClient = new char[strlen(f.numeClient) + 1];
				strcpy(this->numeClient, f.numeClient);
			}
			else
			{
				this->numeClient = new char[strlen("Anonim") + 1];
				strcpy(this->numeClient, "Anonim");
			}
			for (int i = 0; i < 12; i++)
			{
				if (f.consumLunar[i] >= 0)
				{
					this->consumLunar[i] = f.consumLunar[i];
				}
				else
				{
					this->consumLunar[i] = 0;
				}
			}
			if (f.pretKwh > 0)
			{
				this->pretKwh = f.pretKwh;
			}
			this->sursa = f.sursa;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const FurnizorEnergie& f)
	{
		out << "\n---------------------------------";
		out << "\nId client: " << f.idContract;
		out << "\nNume client: " << f.numeClient;
		out << "\nPret / kwh: " << f.pretKwh;
		out << "\nConsum lunar: "<<endl;
		for (int i = 0; i < 12; i++)
		{

				out << f.consumLunar[i] << " ";
			
		}
		out << "\nSursa: " << f.sursa;
		return out;
	}
	~FurnizorEnergie()
	{
		delete[] this->numeClient;
		this->numeClient = nullptr;
	}
	FurnizorEnergie& operator()(int index)
	{
		if (index >= 0 && index <= 12)
		{
			for (int i = 0; i < 12; i++)
			{
				this->consumLunar[index] = 142;
			}
		}
		return *this;
	}
	void operator[](int index)
	{
		if (index >= 0 && index <= 12)
		{
			cout << "\nCONSUM INITIAL: " << this->consumLunar[index];
			for (int i = 0; i < 12; i++)
			{
				this->consumLunar[index] = 155;
			}
			cout << "\nCONSUM FINAL: " << this->consumLunar[index];
		}
		
	}
	explicit operator double()
	{
		double suma = 0;
		for (int i = 0; i < 11; i++)
		{
			if ((this->consumLunar[i + 1] - this->consumLunar[i]) > 0)
			{
				suma += (this->consumLunar[i + 1] - this->consumLunar[i]);
			}
		}
		return suma;
	}
	float Valoare_totala()
	{
		float suma = 0;
		for (int i = 0; i < 12; i++)
		{
			
			suma += this->consumLunar[i];
		}
		return suma;
	}
	void Luna_consum_minim()
	{
		int index = 0;
		float min = this->consumLunar[0];
		for (int i = 1; i < 12; i++)
		{
			if (this->consumLunar[i] < min)
			{
				min = this->consumLunar[i];
				index = i;
			}
		}
		cout << "\nLuna cu cel mai mic consum este luna: " << index+1;
	}
	 void CostLuna()
	{
		float costuri[12];
		cout << "\nCosturi pe fiecare luna: ";
		for (int i = 0; i < 12; i++)
		{
			costuri[i] = this->pretKwh * this->consumLunar[i];
			cout << costuri[i] << " ";
		}
	}
	const int getId()
	{
		return this->idContract;
	}
	static FurnizorEnergie& CautaFurnizorDupaContract(int id_contract)
	{
		map<int, FurnizorEnergie>::iterator itMap;
		for (itMap = mapP.begin(); itMap != mapP.end(); itMap++)
		{
			if (itMap->first==id_contract)
			{
				return itMap->second;
			}
			
		}
		if (itMap== mapP.end())
		{
			throw exception("\nNu s-a gasit");
		}
		
		
	}
};
//GETTEREEEEEEEEEEEEEEEEEEEERI SEEEETEEERI
int FurnizorEnergie::nrContracte = 0;
map<int, FurnizorEnergie> FurnizorEnergie::mapP;


int main()
{
	cout << "\nConstructor fara parametrii";
	FurnizorEnergie f1;
	cout << f1;

	cout <<endl<< "\nConstructor cu parametrii";
	float consumLunar1[] = { 100,200,300,150,210,180,250,120,140,290,170,160 };
	FurnizorEnergie f2(1,"Dulica Denisa",consumLunar1,3,HIDROELECTRICA);
	cout << f2;

	cout << endl << "\nConstructor cu parametrii";
	float consumLunar2[] = { 200,190,300,180,155,124,170,280,148,150,110,240 };
	FurnizorEnergie f5(3, "Cristescu Sara", consumLunar2, 4, SOLARA);
	cout << f5;

	cout << endl << "\nConstructor copy";
	FurnizorEnergie f3 = f2;
	cout << f3;

	cout << endl << "\nOp =";
	FurnizorEnergie f4;
	f4 = f2;
	cout << f4;

	cout << endl << "\nOp FUNCTIE () ";
	f2(8);
	cout << f2;

	cout << endl << "\nOp INDEX [] ";
	f2[8];

	cout << endl << "\nConversie la cast: ";
	double suma = (double)f2;
	cout << suma;

	cout << endl << "\nValoare totala: ";
	cout<<f5.Valoare_totala();

	cout << endl;
	f5.Luna_consum_minim();

	cout << endl << "\nVirtualizare: ";
	f5.CostLuna();
	//sau
	IConsum* consum;
	consum = &f5;
	consum->CostLuna();
	try
	{
		cout << FurnizorEnergie::CautaFurnizorDupaContract(1);
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
	
}