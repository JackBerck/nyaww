#include <iostream>

using namespace std;

int main() {
    
    float suhu_celsius;
    cout << "Masukkan suhu dalam Celsius: ";
    cin >> suhu_celsius;


    float suhu_fahrenheit = (suhu_celsius * 9/5) + 32;

    
    cout << "Suhu dalam Fahrenheit: " << suhu_fahrenheit;

    return 0;
}


#include <iostream>

using namespace std;

int main() {
    
    int tinggi;
    cout << "Masukkan tinggi segitiga: ";
    cin >> tinggi;

    
    for (int i = 1; i <= tinggi; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


#include <iostream>

using namespace std;

int main() {
    
    int panjang, lebar;
    cout << "Masukkan panjang persegi panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar persegi panjang: ";
    cin >> lebar;

    
    int luas = panjang * lebar;

    
    cout << "Luas persegi panjang: " << luas;

    return 0;
}


#include <iostream>

using namespace std;

int main() {
    
    int bilangan;
    cout << "Masukkan sebuah bilangan : ";
    cin >> bilangan;

    
    if (bilangan % 2 == 0) {
        cout << "Bilangan tersebut adalah bilangan genap.";
    } else {
        cout<< "Bilangan tersebut adalah bilangan ganjil.";
    }

    return 0;
}


#include <iostream>
 
 using namespace std;
int main() {
    
    int bilangan;
    cout << "Masukkan sebuah bilangan : ";
    cin >> bilangan;

    int faktorial = 1;

    for (int i = 1; i <= bilangan; ++i) {
        faktorial *= i;
    }

    
    cout << "Faktorial dari " << bilangan << " adalah: " << faktorial;

    return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    float    jari_jari;
    cout << "Masukkan jari-jari lingkaran: ";
    cin >> jari_jari;

    
    float luas = M_PI * pow(jari_jari, 2);
    float keliling = 2 * M_PI * jari_jari;

    
    cout << "Luas lingkaran: " << luas << endl;
    cout << "Keliling lingkaran: " << keliling << endl;

    return 0;
}
