#include<iostream>
#include<string>
#include<vector>

// Clasa Laptop
class Laptop {
private:
    std::string brand;
    static int totalLaptops;
    const int id;
    int* ramSize;

public:
    // Constructori, Destructor și Constructor de Copiere
    // ... (Implementați ca în Faza 2)

    // Supraincarcarea operatorului =
    Laptop& operator=(const Laptop &other) {
        if (this != &other) {
            delete ramSize;
            brand = other.brand;
            ramSize = new int(*other.ramSize);
        }
        return *this;
    }

    // Supraincarcarea operatorului ==
    bool operator==(const Laptop &other) const {
        return brand == other.brand && *ramSize == *other.ramSize;
    }

    // Supraincarcarea operatorului <<
    friend std::ostream& operator<<(std::ostream &os, const Laptop &laptop) {
        os << "Laptop [Brand: " << laptop.brand << ", RAM: " << *laptop.ramSize << "GB]";
        return os;
    }

    // Supraincarcarea operatorului ++
    Laptop& operator++() {
        (*ramSize)++;
        return *this;
    }

    // Metode de Acces (Get-eri și Set-eri)
    // ... (Implementați ca în Faza 2)
};

int Laptop::totalLaptops = 0;

// Clasa Smartphone
class Smartphone {
private:
    std::string model;
    static int totalSmartphones;
    const int serialNumber;
    int* storageSize;

public:
    // Constructori, Destructor și Constructor de Copiere
    // ... (Implementați ca în Faza 2)

    // Supraincarcarea operatorului =
    Smartphone& operator=(const Smartphone &other) {
        if (this != &other) {
            delete storageSize;
            model = other.model;
            storageSize = new int(*other.storageSize);
        }
        return *this;
    }

    // Supraincarcarea operatorului ==
    bool operator==(const Smartphone &other) const {
        return model == other.model && *storageSize == *other.storageSize;
    }

    // Supraincarcarea operatorului <<
    friend std::ostream& operator<<(std::ostream &os, const Smartphone &smartphone) {
        os << "Smartphone [Model: " << smartphone.model << ", Storage: " << *smartphone.storageSize << "GB]";
        return os;
    }

    // Supraincarcarea operatorului +
    Smartphone operator+(int additionalStorage) const {
        return Smartphone(model, *storageSize + additionalStorage, serialNumber);
    }

    // Metode de Acces (Get-eri și Set-eri)
    // ... (Implementați ca în Faza 2)
};

int Smartphone::totalSmartphones = 0;

// Clasa Smartwatch
class Smartwatch {
private:
    std::string brand;
    static int totalSmartwatches;
    const int id;
    bool* hasGPS;

public:
    // Constructori, Destructor și Constructor de Copiere
    // ... (Implementați ca în Faza 2)

    // Supraincarcarea operatorului =
    Smartwatch& operator=(const Smartwatch &other) {
        if (this != &other) {
            delete hasGPS;
            brand = other.brand;
            hasGPS = new bool(*other.hasGPS);
        }
        return *this;
    }

    // Supraincarcarea operatorului ==
    bool operator==(const Smartwatch &other) const {
        return brand == other.brand && *hasGPS == *other.hasGPS;
    }

    // Supraincarcarea operatorului <<
    friend std::ostream& operator<<(std::ostream &os, const Smartwatch &smartwatch) {
        os << "Smartwatch [Brand: " << smartwatch.brand << ", GPS: " << (*smartwatch.hasGPS ? "Yes" : "No") << "]";
        return os;
    }

    // Supraincarcarea operatorului !
    Smartwatch operator!() const {
        return Smartwatch(brand, !(*hasGPS), id);
    }

    // Metode de Acces (Get-eri și Set-eri)
    // ... (Implementați ca în Faza 2)
};

int Smartwatch::totalSmartwatches = 0;

// Funcția prietenă
void displayAll(const Laptop &laptop, const Smartphone &smartphone, const Smartwatch &smartwatch) {
   
    std::cout << "Dispozitivele sunt:" << std::endl;
    std::cout << laptop << std::endl;
    std::cout << smartphone << std::endl;
    std::cout << smartwatch << std::endl;
}


// Supraincarcarea operatorului >> pentru Laptop
std::istream& operator>>(std::istream &is, Laptop &laptop) {
    std::cout << "Introduceti brand-ul si dimensiunea RAM pentru Laptop (ex: Dell 8): ";
    is >> laptop.brand >> *laptop.ramSize;
    return is;
}

// Supraincarcarea operatorului >> pentru Smartphone
std::istream& operator>>(std::istream &is, Smartphone &smartphone) {
    std::cout << "Introduceti modelul si dimensiunea stocarii pentru Smartphone (ex: iPhone 128): ";
    is >> smartphone.model >> *smartphone.storageSize;
    return is;
}

// Supraincarcarea operatorului >> pentru Smartwatch
std::istream& operator>>(std::istream &is, Smartwatch &smartwatch) {
    std::cout << "Introduceti brand-ul si starea GPS pentru Smartwatch (1 pentru Da, 0 pentru Nu, ex: Apple 1): ";
    is >> smartwatch.brand;
    int gps;
    is >> gps;
    *smartwatch.hasGPS = gps != 0;
    return is;
}

int main() {
    // Vectori pentru fiecare tip de obiect
    std::vector<Laptop> laptops;
    std::vector<Smartphone> smartphones;
    std::vector<Smartwatch> smartwatches;

    // Citirea și adăugarea obiectelor în vectori
    int n;
    std::cout << "Numar de laptopuri: ";
    std::cin >> n;
    laptops.resize(n);
    for (auto &laptop : laptops) {
        std::cin >> laptop;
    }

    std::cout << "Numar de smartphone-uri: ";
    std::cin >> n;
    smartphones.resize(n);
    for (auto &smartphone : smartphones) {
        std::cin >> smartphone;
    }

    std::cout << "Numar de smartwatch-uri: ";
    std::cin >> n;
    smartwatches.resize(n);
    for (auto &smartwatch : smartwatches) {
        std::cin >> smartwatch;
    }

    // Afișarea obiectelor din vectori
    std::cout << "\nLaptopuri:\n";
    for (const auto &laptop : laptops) {
        std::cout << laptop << std::endl;
    }

    std::cout << "\nSmartphone-uri:\n";
    for (const auto &smartphone : smartphones) {
        std::cout << smartphone << std::endl;
    }

    std::cout << "\nSmartwatch-uri:\n";
    for (const auto &smartwatch : smartwatches) {
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

