#include <iostream>
#include <cstring>
using namespace std;

class StockRecord {
private:
    char id[13];
    char name[51];
    float priceWhenAreBought;
    float PriceNow;
    int nmbofStock; // Neznam dali angliskiov moj e tolku dobar :P
    friend class Client;
    public:
    StockRecord() {
        strcpy(this->id, "");
        strcpy(this->name, "");
        this->priceWhenAreBought = 0;
        this->PriceNow = 0;
        this->nmbofStock = 0;
    }
    StockRecord(char *id, char *name, float priceWhenAreBought,
         int nmbofStock) {
        strcpy(this->id, id);
        strcpy(this->name, name);
        this->priceWhenAreBought = priceWhenAreBought;
        this->nmbofStock = nmbofStock;
    }
    StockRecord(const StockRecord &other) {
        strcpy(this->id, other.id);
        strcpy(this->name, other.name);
        this->priceWhenAreBought = other.priceWhenAreBought;
        this->PriceNow = other.PriceNow;
        this->nmbofStock = other.nmbofStock;
    }
    void setNewPrice(double newPrice) {
        this->PriceNow = newPrice;
    }
    double value() {
        return (double) nmbofStock * PriceNow;
    }
    double profit() {
        return (double) nmbofStock * (this->PriceNow - this->priceWhenAreBought);
    }
    void print() {
        cout << name << " " << nmbofStock
        << " " << priceWhenAreBought << " " << PriceNow
        << " " << profit() << endl;
    }
};

class Client {
private:
    char fullName[61];
    int idOfClient;
    StockRecord stocks[100];
    int nmbofStock;
    public:
    Client() {
        strcpy(this->fullName, "");
        this->idOfClient = 0;
        this->nmbofStock = 0;
    }

    Client(char *fullName, int idOfClient) {
        strcpy(this->fullName, fullName);
        this->idOfClient = idOfClient;
        this->nmbofStock = 0;
    }

    double totalValue() {
        double total = 0;
        for (int i = 0; i < nmbofStock; i++) {
            total += this->stocks[i].value();
        }
        return total;
    }

    void addStock(const StockRecord &stock) {
        if (this->nmbofStock < 100) {
            stocks[nmbofStock++] = stock;
        }
    }

    void print() {
        cout << idOfClient << " " << totalValue() << endl; 
        for (int i = 0; i < nmbofStock; i++) {
            this->stocks[i].print();
        }
    }

};






int main() {

    int test;
    cin >> test;

    if (test == 1) {
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 10);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;

    } else if (test == 2) {
        cout << "=====TEST NA METODITE I PRINT OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int shares;

        cin >> id >> company >> price >> newPrice >> shares;

        StockRecord sr(id, company, price, shares);

        cout << sr.value() << endl; // Value of stocks
        sr.setNewPrice(newPrice);
        sr.print();                 // Print using the `print` method

    } else if (test == 3) {
        cout << "=====TEST NA KLASATA Client=====" << endl;

        char companyID[12], companyName[50], clientName[50];
        int clientID, shares, n;
        double oldPrice, newPrice;

        cin >> clientName >> clientID >> n;

        Client c(clientName, clientID);

        cout << "Konstruktor OK" << endl;

        for (int i = 0; i < n; ++i) {
            cin >> companyID >> companyName >> oldPrice >> newPrice >> shares;

            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);

            c.addStock(sr); // Add stock record to client

            if (i == 0)
                cout << "Operator += OK" << endl; // Print once
        }

        c.print(); // Print client details using the `print` method

        cout << "Operator << OK" << endl;
    }

    return 0;
}
