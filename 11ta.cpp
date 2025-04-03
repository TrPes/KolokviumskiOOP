#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
enum Gender {
    Male, Female
};
class Ucesnik {
private:
    char name[101];
    Gender gender;
    int age;
    friend class Maraton;
    public:
    Ucesnik() {
        strcpy(name, " ");
        age = 0;
        gender = Male;
    }
    Ucesnik(char *name,Gender gender, int age) {
        strcpy(this->name, name);
        this->age = age;
        this->gender = gender;
    }
    Ucesnik(const Ucesnik &u) {
        strcpy(this->name, u.name);
        this->age = u.age;
    }
    void set(char *name, Gender g, int age) {
        strcpy(this->name, name);
        this->age = age;
        this->gender = g;
    }
    void setAge(int age) {
        this->age = age;
    }
   const char *getName() const{
        return this->name;
    }
    int getAge() const {
        return this->age;
    }
    Gender getGender() const {
        return this->gender;
    }
    void print() const {
        cout << this->name << endl;
        if (gender == Male)
        {  cout << "mashki" << endl;}
        else
        { cout << "zhenski" << endl;}
        cout << this->age << endl;
    }
};

class Maraton {
private:
    char location[100];
    Ucesnik ucesnici[100];
    int n; // brojNaUcesnici
    public:
    Maraton() {
        strcpy(this->location, " ");
        n = 0;
    }
    Maraton(char *location, Ucesnik ucesnici[], int n) {
        strcpy(this->location, location);
        this->n = n;
        for (int i = 0; i < 100; ++i) {
            this->ucesnici[i] = ucesnici[i];
        }
    }
    void setLocation(char *location) {
        strcpy(this->location, location);
    }

    void addUcesnik(const Ucesnik &u) {
        if(n < 100) {
            this->ucesnici[n++] = u;
        }
    }
    double prosecnoVozrast() {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += this->ucesnici[i].getAge();
        }
        return (float) sum / n;
    }

    void pecatiPomladi(const Ucesnik &u) const {
        for (int i = 0; i < n; ++i) {
            if(ucesnici[i].getAge() < u.getAge()) {
                ucesnici[i].print();
            }
        }
    }
};

int main() {
    int n;
    cin >> n;

    char location[100];
    cin >> location;

    Maraton m;
    m.setLocation(location);

    Ucesnik lista[100];

    for (int i = 0; i < n; i++) {
        char ime[100];
        int genderInput; // 0 = MALE, 1 = FEMALE, 2 = OTHER
        int vozrast;

        cin >> ime >> genderInput >> vozrast;

        Gender g;
        if (genderInput == 1) g = Male;
        else g = Female;

        lista[i].set(ime, g, vozrast);
        m.addUcesnik(lista[i]);
    }

    m.pecatiPomladi(lista[n - 1]);
    cout << m.prosecnoVozrast() << endl;

    return 0;
}