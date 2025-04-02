#include <iostream>
#include <cstring>

using namespace std;

class List {
    private:
    int numbers[100];
    int size;
    friend class ListContainer;
    public:
    List() {
        size = 0;
        for (int i = 0; i < 100; i++) {
            numbers[i] = 0;
        }
    }
    List(int* numbers, int size) {
        this->size = size;
        for (int i = 0; i < 100; i++) {
            this->numbers[i] = numbers[i];
        }
    }
    List(const List& l) {
        size = l.size;
        for (int i = 0; i < 100; i++) {
            numbers[i] = l.numbers[i];
        }
    }
    ~List() {

    }
    void pecati() {
        cout << "List info: " << this->size << ": ";
        for (int i = 0; i < this->size; i++) {
            cout << this->numbers[i] << " ";
        }
        cout << "sum: "<<sum() << " average: "<<average();
    }
    float sum() {
        float s = 0;
        for (int i = 0; i < size; i++) {
            s += numbers[i];
        }
        return s;
    }
    float average() {
        float s = sum();
        return s / (float) size;
    }
};

class ListContainer {
    private:
    List list[50];
    int sizeofListContainer;
    int successfulAttempts;
    int failedAttempts;
    public:
    ListContainer() {
        sizeofListContainer = 0;
        successfulAttempts = 0;
        failedAttempts = 0;
    }
    ListContainer(List list[], int size) {
        this->sizeofListContainer = size;
        for (int i = 0; i < 50; i++) {
            this->list[i] = list[i];
        }
    }
    ListContainer(const ListContainer& l) {
        sizeofListContainer = l.sizeofListContainer;
        for (int i = 0; i < 50; i++) {
            this->list[i] = l.list[i];
        }
        successfulAttempts = l.successfulAttempts;
        failedAttempts = l.failedAttempts;
    }
    ~ListContainer() {}
    void pecati() {
        if(sizeofListContainer == 0) {
            cout << "The list is empty " << endl;
        }
        else {
            for (int i = 0; i < sizeofListContainer; i++) {
                cout << "List number: " << i + 1 << " ";
                list[i].pecati();
                cout << endl;
            }
            cout << "Sum: " << sum() << " Average: " << average() << endl;
            cout << "Successful attempts: " << successfulAttempts << " Failed attempts: " << failedAttempts << endl;
        }
    }

    void addNewList(List l) {
        bool add = true;
        int newSum = l.sum();
        for (int i = 0; i < sizeofListContainer; i++) {
            if (list[i].sum() == newSum) {
                add = false;
                break;
            }
        }
        if(add && sizeofListContainer < 50) {
            list[sizeofListContainer++] = l;
            successfulAttempts++;
        }
        else {
            failedAttempts++;
        }
    }

    float sum() {
        float totalSum = 0;
        for (int i = 0; i < sizeofListContainer; i++) {
            totalSum += list[i].sum();
        }
        return totalSum;
    }
    float average() {
        float totalElements = 0;
        for (int i = 0; i < sizeofListContainer; i++) {
            totalElements += list[i].size;
        }

        return sum() / (float) totalElements;
    }
};

int main() {
    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> niza[j];
        }

        List l(niza, n);
        lc.addNewList(l);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.pecati();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.pecati();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();
    } else {
        lc.pecati();
    }

    return 0;
}
