#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class Laptop;
class ITStore;

class Laptop {
private:
    char NameOfBrand[101];
    float sizeInches;
    bool touch;
    long int price;
    friend void Cheapest(ITStore stores[], int n);
public:
    Laptop(){
        strcpy(NameOfBrand, "");
        sizeInches = 0;
        price = 0;
        touch = false;
    }

    Laptop(const char* nameOfBrand, float sizeInches, long int price, bool touch){
        strcpy(NameOfBrand, nameOfBrand);
        this->sizeInches = sizeInches;
        this->price = price;
        this->touch = touch;
    }

    [[nodiscard]] const char* getName() const {
        return NameOfBrand;
    }

    [[nodiscard]] float getSizeInches() const {
        return sizeInches;
    }

    [[nodiscard]] long int getPrice() const {
        return price;
    }

    [[nodiscard]] bool isTouch() const {
        return touch;
    }
};

class ITStore {
private:
    char NameOfITStore[101];
    char Location[101];
    Laptop laptops[100];
    int nmbOfLaptops;
    friend void Cheapest(ITStore stores[], int n);
public:
    ITStore() : nmbOfLaptops(0) {
        strcpy(NameOfITStore, "");
        strcpy(Location, "");
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
        cout << laptops[i].getName() << " ";

        if (laptops[i].getSizeInches() == (int)(laptops[i].getSizeInches())) {
            cout << (int)(laptops[i].getSizeInches()) << " ";
        } else {
            cout << fixed << setprecision(1) << laptops[i].getSizeInches() << " ";  // Print with one decimal
        }

        cout << fixed << setprecision(0) << laptops[i].getPrice() << endl;
    }
}
};
void Cheapest(ITStore stores[], int n) {
    ITStore Cheapest = stores[0];
    int minPrice = 0;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < stores[i].nmbOfLaptops; ++j) {
            if (stores[i].laptops[j].isTouch()) {
                if (!found || stores[i].laptops[j].getPrice() < minPrice) {
                    minPrice = stores[i].laptops[j].getPrice();
                    Cheapest = stores[i];
                    found = true;
                }
            }
        }
    }


    if (found) {
        cout << "Najeftina ponuda ima prodavnicata:"<<endl;
        cout << Cheapest.NameOfITStore << " " << Cheapest.Location << endl;

        cout << "Najniskata cena iznesuva: " << minPrice << endl;
    } else {
        cout << "No touch laptop found!" << endl;
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
            long int price;
            bool touchInt;

            cin.getline(NameOfBrand, 101);
            cin >> sizeInches;
            cin >> touchInt;
            cin >> price;
            cin.ignore();



            Laptop newLaptop(NameOfBrand, sizeInches, price, touchInt);
            itStore[i].addLaptop(newLaptop);
        }
    }

    for (int i = 0; i < n; i++) {
        itStore[i].printItStore();
    }
    Cheapest(itStore, n);

    return 0;
}
