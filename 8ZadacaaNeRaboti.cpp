#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Laptop {
private:
    char NameOfBrand[101];
    float sizeInches;
    bool touch;
    int price;
public:
    Laptop() {
        strcpy(NameOfBrand, "");
        sizeInches = 0;
        touch = false;
        price = 0;
    }
    Laptop(const char* nameOfBrand, float sizeInches, int price, bool touch) {
        strcpy(this->NameOfBrand, nameOfBrand);
        this->sizeInches = sizeInches;
        this->price = price;
        this->touch = touch;
    }
    void printLaptop() const {
        cout << NameOfBrand << " " << fixed << setprecision(1) << sizeInches
             << " " << price << endl;
    }
};

class ITStore {
private:
    char NameOfITStore[101];
    char Location[101];
    Laptop laptops[100];
    int nmbOfLaptops;
public:
    ITStore() {
        strcpy(NameOfITStore, "");
        strcpy(Location, "");
        nmbOfLaptops = 0;
    }
    ITStore(const char* nameOfITStore, const char* location) {
        strcpy(this->NameOfITStore, nameOfITStore);
        strcpy(this->Location, location);
        nmbOfLaptops = 0;
    }
    void addLaptop(const Laptop &l) {
        if (nmbOfLaptops < 100) {
            laptops[nmbOfLaptops++] = l;
        }
    }
    void printItStore() const {
        cout << NameOfITStore << " " << Location << endl;
        for (int i = 0; i < nmbOfLaptops; i++) {
            laptops[i].printLaptop();
        }
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    ITStore itStore[100];

    for (int i = 0; i < n; i++) {
        char nameOfITStore[101];
        char location[101];
        cin.getline(nameOfITStore, 101);
        cin.getline(location, 101);


        itStore[i] = ITStore(nameOfITStore, location);

        int nmbOfLaptops;
        cin >> nmbOfLaptops;
        cin.ignore();

        for (int j = 0; j < nmbOfLaptops; j++) {
    char NameOfBrand[101];
    float sizeInches;
    int price;
    int touchInt; 

    cin.ignore();  
    cin.getline(NameOfBrand, 101); 

    cin >> sizeInches >> price >> touchInt;
    bool touch = (touchInt != 0);  
            
    Laptop newLaptop(NameOfBrand, sizeInches, price, touch);
    itStore[i].addLaptop(newLaptop);
}
    }

    for (int i = 0; i < n; i++) {
        itStore[i].printItStore();
    }

    return 0;
}
