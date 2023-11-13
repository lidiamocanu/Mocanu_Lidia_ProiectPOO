#include <iostream>
#include <string>
#include <vector>

class Laptop {
private:
    std::string brand;
    static int totalLaptops;
    const int id;
    int* ramSize;

public:
    Laptop(std::string b, int r, int i) : brand(b), id(i), ramSize(new int(r)) {
        totalLaptops++;
    }

    Laptop(std::string b, int i) : brand(b), id(i), ramSize(new int(8)) {
        totalLaptops++;
    }

    Laptop() : brand("Unknown"), id(0), ramSize(new int(4)) {
        totalLaptops++;
    }

    Laptop(const Laptop& other) : brand(other.brand), id(other.id), ramSize(new int(*other.ramSize)) {
        totalLaptops++;
    }

    ~Laptop() {
        delete ramSize;
    }

    // Supraincarcarea operatorului =
    Laptop& operator=(const Laptop& other) {
        if (this != &other) {
            delete ramSize;
            brand = other.brand;
            ramSize = new int(*other.ramSize);
        }
        return *this;
    }

    // Supraincarcarea operatorului ==
    bool operator==(const Laptop& other) const {
        return brand == other.brand && *ramSize == *other.ramSize;
    }

    // Supraincarcarea operatorului <<
    friend std::ostream& operator<<(std::ostream& os, const Laptop& laptop) {
        os << "Laptop [Brand: " << laptop.brand << ", RAM: " << *laptop.ramSize << "GB]";
        return os;
    }

    // Supraincarcarea operatorului ++
    Laptop& operator++() {
        (*ramSize)++;
        return *this;
    }

    std::string getBrand() const { return brand; }
    void setBrand(std::string b) { brand = b; }
    int getRamSize() const { return *ramSize; }
    void setRamSize(int r) { *ramSize = r; }
    int getId() const { return id; }

    static int getTotalLaptops() { return totalLaptops; }
    static void displayTotalLaptops() {
        std::cout << "Total laptops: " << totalLaptops << std::endl;
    }

    void display() {
        std::cout << "Laptop brand: " << brand << ", RAM size: " << *ramSize << "GB, ID: " << id << std::endl;
    }

    friend void compareLaptops(const Laptop& l1, const Laptop& l2);
};
int Laptop::totalLaptops = 0;

class Smartphone {
private:
    std::string model;
    static int totalSmartphones;
    const int serialNumber;
    int* storageSize;

public:
    Smartphone(std::string m, int s, int sn) : model(m), serialNumber(sn), storageSize(new int(s)) {
        totalSmartphones++;
    }

    Smartphone(std::string m, int sn) : model(m), serialNumber(sn), storageSize(new int(64)) {
        totalSmartphones++;
    }

    Smartphone() : model("Unknown"), serialNumber(0), storageSize(new int(32)) {
        totalSmartphones++;
    }

    Smartphone(const Smartphone& other) : model(other.model), serialNumber(other.serialNumber), storageSize(new int(*other.storageSize)) {
        totalSmartphones++;
    }

    ~Smartphone() {
        delete storageSize;
    }

    // Supraincarcarea operatorului ==
    bool operator==(const Smartphone& other) const {
        return model == other.model && *storageSize == *other.storageSize;
    }

    // Supraincarcarea operatorului <<
    friend std::ostream& operator<<(std::ostream& os, const Smartphone& smartphone) {
        os << "Smartphone [Model: " << smartphone.model << ", Storage: " << *smartphone.storageSize << "GB]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Smartphone& smartphone);


    // Supraincarcarea operatorului +
    Smartphone operator+(int additionalStorage) const {
        return Smartphone(model, *storageSize + additionalStorage, serialNumber);
    }


    Smartphone& operator=(const Smartphone& other);


    std::string getModel() const { return model; }
    void setModel(std::string m) { model = m; }
    int getStorageSize() const { return *storageSize; }
    void setStorageSize(int s) { *storageSize = s; }
    int getSerialNumber() const { return serialNumber; }

    static int getTotalSmartphones() { return totalSmartphones; }
    static void displayTotalSmartphones() {
        std::cout << "Total smartphones: " << totalSmartphones << std::endl;
    }

    void display() {
        std::cout << "Smartphone model: " << model << ", Storage size: " << *storageSize << "GB, Serial Number: " << serialNumber << std::endl;
    }

    friend void compareSmartphones(const Smartphone& s1, const Smartphone& s2);
};
int Smartphone::totalSmartphones = 0;

std::istream& operator>>(std::istream& is, Smartphone& smartphone) {
    std::string model;
    int storage;

    is >> model >> storage;

    smartphone.setModel(model);
    smartphone.setStorageSize(storage);

    return is;
}


// Correct implementation of the copy assignment operator
Smartphone& Smartphone::operator=(const Smartphone& other) {
    if (this != &other) {
        model = other.model;
        delete storageSize;
        storageSize = new int(*other.storageSize);
    }
    return *this;
}


class Smartwatch {
private:
    std::string brand;
    static int totalSmartwatches;
    const int id;
    bool* hasGPS;

public:
    Smartwatch(std::string b, bool gps, int i) : brand(b), id(i), hasGPS(new bool(gps)) {
        totalSmartwatches++;
    }

    Smartwatch(std::string b, int i) : brand(b), id(i), hasGPS(new bool(false)) {
        totalSmartwatches++;
    }

    Smartwatch() : brand("Unknown"), id(0), hasGPS(new bool(false)) {
        totalSmartwatches++;
    }

    Smartwatch(const Smartwatch& other) : brand(other.brand), id(other.id), hasGPS(new bool(*other.hasGPS)) {
        totalSmartwatches++;
    }

    ~Smartwatch() {
        delete hasGPS;
    }

    // Supraincarcarea operatorului =
    Smartwatch& operator=(const Smartwatch& other) {
        if (this != &other) {
            delete hasGPS;
            brand = other.brand;
            hasGPS = new bool(*other.hasGPS);
        }
        return *this;
    }

    // Supraincarcarea operatorului ==
    bool operator==(const Smartwatch& other) const {
        return brand == other.brand && *hasGPS == *other.hasGPS;
    }

    // Supraincarcarea operatorului <<
    friend std::ostream& operator<<(std::ostream& os, const Smartwatch& smartwatch) {
        os << "Smartwatch [Brand: " << smartwatch.brand << ", GPS: " << (*smartwatch.hasGPS ? "Yes" : "No") << "]";
        return os;
    }

    // Supraincarcarea operatorului !
    Smartwatch operator!() const {
        return Smartwatch(brand, !(*hasGPS), id);
    }

    std::string getBrand() const { return brand; }
    void setBrand(std::string b) { brand = b; }
    bool getHasGPS() const { return *hasGPS; }
    void setHasGPS(bool gps) { *hasGPS = gps; }
    int getId() const { return id; }

    static int getTotalSmartwatches() { return totalSmartwatches; }
    static void displayTotalSmartwatches() {
        std::cout << "Total smartwatches: " << totalSmartwatches << std::endl;
    }

    void display() {
        std::cout << "Smartwatch brand: " << brand << ", Has GPS: " << (*hasGPS ? "Yes" : "No") << ", ID: " << id << std::endl;
    }

    friend void compareSmartwatches(const Smartwatch& w1, const Smartwatch& w2);
};
int Smartwatch::totalSmartwatches = 0;

void compareLaptops(const Laptop& l1, const Laptop& l2) {
    std::cout << "Comparing laptops by RAM size: " << std::endl;
    std::cout << "Laptop 1 RAM: " << *l1.ramSize << "GB, Laptop 2 RAM: " << *l2.ramSize << "GB\n";
    if (*l1.ramSize == *l2.ramSize)
        std::cout << "The laptops have the same RAM size.\n";
    else
        std::cout << "The laptops have different RAM sizes.\n";
}

void compareSmartphones(const Smartphone& s1, const Smartphone& s2) {
    std::cout << "Comparing smartphones by storage size: " << std::endl;
    std::cout << "Smartphone 1 Storage: " << *s1.storageSize << "GB, Smartphone 2 Storage: " << *s2.storageSize << "GB\n";
    if (*s1.storageSize == *s2.storageSize)
        std::cout << "The smartphones have the same storage size.\n";
    else
        std::cout << "The smartphones have different storage sizes.\n";
}

void compareSmartwatches(const Smartwatch& w1, const Smartwatch& w2) {
    std::cout << "Comparing smartwatches by GPS feature: " << std::endl;
    std::cout << "Smartwatch 1 GPS: " << (*w1.hasGPS ? "Yes" : "No") << ", Smartwatch 2 GPS: " << (*w2.hasGPS ? "Yes" : "No") << "\n";
    if (*w1.hasGPS == *w2.hasGPS)
        std::cout << "Both smartwatches have the same GPS feature.\n";
    else
        std::cout << "The smartwatches have different GPS features.\n";
}

void displayAll(const Laptop& laptop, const Smartphone& smartphone, const Smartwatch& smartwatch) {

    std::cout << "Dispozitivele sunt:" << std::endl;
    std::cout << laptop << std::endl;
    std::cout << smartphone << std::endl;
    std::cout << smartwatch << std::endl;
}

std::istream& operator>>(std::istream& is, Laptop& laptop) {
    std::string brand;
    int ramSize;

    std::cout << "Introduceti brand-ul si dimensiunea RAM pentru Laptop (ex: Dell 8): ";
    is >> brand >> ramSize;

    laptop.setBrand(brand);
    laptop.setRamSize(ramSize);

    return is;
}


std::istream& operator>>(std::istream& is, Smartwatch& smartwatch) {
    std::string brand;
    int gps;

    std::cout << "Introduceti brand-ul si starea GPS pentru Smartwatch (1 pentru Da, 0 pentru Nu, ex: Apple 1): ";
    is >> brand >> gps;

    smartwatch.setBrand(brand);
    smartwatch.setHasGPS(gps != 0);

    return is;
}


int main() {
    Laptop l1("Dell", 16, 101);
    Laptop l2("HP", 8, 102);
    Laptop l3;
    l1.display();
    l2.display();
    l3.display();
    Laptop::displayTotalLaptops();

    Smartphone s1("iPhone", 128, 501);
    Smartphone s2("Samsung", 64, 502);
    Smartphone s3;
    s1.display();
    s2.display();
    s3.display();
    Smartphone::displayTotalSmartphones();

    Smartwatch w1("Apple", true, 1);
    Smartwatch w2("Samsung", false, 2);
    Smartwatch w3;
    w1.display();
    w2.display();
    w3.display();
    Smartwatch::displayTotalSmartwatches();

    compareLaptops(l1, l2);
    compareSmartphones(s1, s2);
    compareSmartwatches(w1, w2);



    // Demonstrarea supraincarcării operatorilor pentru Laptop
    l3 = l2; // Operatorul =
    std::cout << (l1 == l2) << std::endl; // Operatorul ==
    std::cout << l1 << std::endl; // Operatorul <<
    ++l1; // Operatorul ++

    // Demonstrarea supraincarcării operatorilor pentru Smartphone
    s3 = s2; // Operatorul =

    std::cout << (s1 == s2) << std::endl; // Operatorul ==
    std::cout << s1 << std::endl; // Operatorul <<
    Smartphone s4 = s1 + 32; // Operatorul +

    // Demonstrarea supraincarcării operatorilor pentru Smartwatch
    w3 = w2; // Operatorul =
    std::cout << (w1 == w2) << std::endl; // Operatorul ==
    std::cout << w1 << std::endl; // Operatorul <<
    Smartwatch w4 = !w1; // Operatorul !

    // Apelarea funcției prietene
    displayAll(l1, s1, w1);

    // Vectori pentru fiecare tip de obiect
    std::vector<Laptop> laptops;
    std::vector<Smartphone> smartphones;
    std::vector<Smartwatch> smartwatches;

    // Citirea și adăugarea obiectelor în vectori
    int n;
    std::cout << "Numar de laptopuri: ";
    std::cin >> n;
    laptops.resize(n);
    for (auto& laptop : laptops) {
        std::cin >> laptop;
    }

    std::cout << "Numar de smartphone-uri: ";
    std::cin >> n;
    smartphones.resize(n);
    for (auto& smartphone : smartphones) {
        std::cin >> smartphone;
    }

    std::cout << "Numar de smartwatch-uri: ";
    std::cin >> n;
    smartwatches.resize(n);
    for (auto& smartwatch : smartwatches) {
        std::cin >> smartwatch;
    }

    // Afișarea obiectelor din vectori
    std::cout << "\nLaptopuri:\n";
    for (const auto& laptop : laptops) {
        std::cout << laptop << std::endl;
    }

    std::cout << "\nSmartphone-uri:\n";
    for (const auto& smartphone : smartphones) {
        std::cout << smartphone << std::endl;
    }

    std::cout << "\nSmartwatch-uri:\n";
    for (const auto& smartwatch : smartwatches) {
        std::cout << smartwatch << std::endl;
    }

    // Crearea și afișarea unei matrice de Laptopuri
    std::cout << "\nMatrice de Laptopuri (2x2):\n";
    Laptop laptopMatrix[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> laptopMatrix[i][j];
        }
    }

    // Afișarea matricei de Laptopuri
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << laptopMatrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    return 0;
}