#include <iostream>
#include <cstring>

using namespace std;

enum tip {
	Pop, Rap, Rok
};

class Pesna {
private:
	char name[20];
	int min;
	tip t;

public:
	Pesna() {
		t = Pop;
		min = 0;
		strcpy(name, "");
	}
	Pesna(char* name, int min, tip t) {
		this->t = t;
		this->min = min;
		strcpy(this->name, name);
	}
	Pesna(const Pesna &p) {
		strcpy(this->name, p.name);
		this->min = p.min;
		this->t = p.t;
	}

	int getMin() {
		return min;
	}
	tip getTip() const {
		return this->t;
	}
	void pecati() {
		cout<<"\""<<name<<"\"-"<< min << "min" << endl;
	}
};

class CD {
private:
	Pesna pesni[10];
	int brojPesni;
	int max_minuti;
	int momentalniMin;

public:
	CD(int max_minuti = 100) {
		this->max_minuti = max_minuti;
		this->brojPesni = 0;
		this->momentalniMin = 0;
	}

	int getBroj() {
		return brojPesni;
	}

	Pesna getPesna(int index) {
		if (index < brojPesni)
			return pesni[index];
		return Pesna();
	}

	void dodadiPesna(Pesna p) {
		if (brojPesni < 10 && (momentalniMin + p.getMin()) <= max_minuti) {
			pesni[brojPesni++] = p;
			momentalniMin += p.getMin();
		}
	}

	void pecatiPesniPoTip(tip t) {
		for (int i = 0; i < brojPesni; i++) {
			if (pesni[i].getTip() == t) {
				pesni[i].pecati();
			}
		}
	}
};
int main() {
	// se testira zadacata modularno
    int testCase;
    cin >> testCase;
	
	int n, minuti, kojtip;
	char ime[50];
	
	if(testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime,minuti,(tip)kojtip);
		p.pecati();
    } else if(testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<n; i++)
				(omileno.getPesna(i)).pecati();
	}
    else if(testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        	for (int i=0; i<omileno.getBroj(); i++)
				(omileno.getPesna(i)).pecati();
    }
    else if(testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    else if(testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
		CD omileno(20);
		cin>>n;
			for (int i=0;i<n;i++){
				cin >> ime;
				cin >> minuti;
				cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
				Pesna p(ime,minuti,(tip)kojtip);
				omileno.dodadiPesna(p);
			}
        cin>>kojtip;
        omileno.pecatiPesniPoTip((tip)kojtip);
        	
    }
    
return 0;
}