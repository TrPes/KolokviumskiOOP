#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Igrac {
    private:
    char korisnickoIme[16];
    int level;
    int points;
    friend class KompjuterskaIgra;
    public:
    Igrac() {
        level = 0;
        points = 0;
        strcpy(korisnickoIme, "");
    }
    Igrac(const char* korisnickoIme, const int level, const int points) {
        strcpy(this->korisnickoIme, korisnickoIme);
        this->level = level;
        this->points = points;
    }
    Igrac(const Igrac &p) {
        strcpy(this->korisnickoIme, p.korisnickoIme);
        this->level = p.level;
        this->points = p.points;
    }

    void print() const{
        cout << this->korisnickoIme <<" "<<this->level << " " << this->points << endl;
    }
    const char* getKorisnickoIme() const {
        return this->korisnickoIme;
    }
    int getLevel() const {
        return this->level;
    }
    int getPoints() const {
        return this->points;
    }

};
class KompjuterskaIgra {
    private:
    char name[21];
    Igrac players[30];
    int n = 0;
    public:
    KompjuterskaIgra() {
        strcpy(name, "");
    }
    KompjuterskaIgra(const char* name) {
        strcpy(this->name, name);
    }

    void addPlayer(const Igrac &p) {
        if(n < 30) {
            players[n++] = p;
        }

    }
    const char* getName() const {
        return name;
    }
    int getPlayerCount() const {
        return n;
    }
    const Igrac &getPlayer(int index) const {
        return players[index];
    }
};


void najdobarIgrac(KompjuterskaIgra* k, int n) {
  KompjuterskaIgra best = k[0];
    Igrac bestPlayer = k[0].getPlayer(0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k[i].getPlayerCount(); j++) {
            if(k[i].getPlayer(j).getPoints() > bestPlayer.getPoints()) {
                best = k[i];
                bestPlayer = k[i].getPlayer(j);
            }
        }
    }

    cout << "Najdobar igrac e igracot so korisnicko ime "<<bestPlayer.getKorisnickoIme()<<" koj ja igra igrata " << best.getName()<<endl;

}


int main() {
    KompjuterskaIgra kp[50];
    int n; // numberOfGames
    cin >> n;
    cin.ignore();


    int m;
    Igrac players[50];
    char name[21];
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin.ignore();
        kp[i] = KompjuterskaIgra(name);
         cin >> m; // numberOfPlayers
        cin.ignore();

        for (int j = 0; j < m; j++) {
            char korisnickoIme[16];
            int level, points;

            cin >> korisnickoIme >> level >> points;
            players[j] = Igrac(korisnickoIme, level, points);
            kp[i].addPlayer(players[j]);
        }
    }


    // for (int i = 0; i < n; ++i) {
    //     cout << kp[i].getName() << endl;
    //     for (int j = 0; j < kp[i].getPlayerCount(); ++j) {
    //        kp[i].getPlayer(j).print();
    //     }
    // }
    najdobarIgrac(kp, n);

    return 0;
}
