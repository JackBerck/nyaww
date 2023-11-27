#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

string generateOrder()
{
    srand(time(0));
    return to_string(rand() % 10000) + to_string(time(0));
}

void sendConfirmation(const string &contact)
{
    cout << "Konfirmasi pemesanan telah dikirim ke " << contact << endl;
}

void generateVirtualAccountNumber()
{
    srand(time(0));
    cout << "Nomor Virtual Account: " << rand() % 1000000 << endl;
}

void displayConfirmedOrders(const vector<string> &confirmedOrders)
{
    if (confirmedOrders.empty())
    {
        cout << "Belum ada pesanan yang terkonfirmasi." << endl;
    }
    else
    {
        cout << "=== Pesanan Terkonfirmasi ===" << endl;
        for (const string &order : confirmedOrders)
        {
            cout << order << endl;
        }
    }
}

bool makeOnlinePayment()
{
    cout << "Pilih metode pembayaran online:" << endl;
    cout << "1. Kartu Kredit" << endl;
    cout << "2. Transfer Bank" << endl;
    cout << "3. E-Wallet" << endl;
    cout << "Pilihan Anda: ";

    int paymentMethod;
    cin >> paymentMethod;

    string paymentNumber;

    switch (paymentMethod)
    {
    case 1:
        cout << "Masukkan nomor kartu kredit: ";
        cin >> paymentNumber;
        break;
    case 2:
        cout << "Masukkan nomor rekening bank: ";
        cin >> paymentNumber;
        break;
    case 3:
        cout << "Masukkan nomor e-wallet: ";
        cin >> paymentNumber;
        break;
    default:
        cout << "Metode pembayaran tidak valid." << endl;
        return false;
    }

    cout << "Memproses pembayaran..." << endl;

    return true;
}

int main()
{
    vector<string> confirmedOrders;

    int choice;
    do
    {
        cout << "============================================" << endl;
        cout << "=== Selamat Datang di Aplikasi Pemesanan Tiket Bus Nana ===" << endl;
        cout << "1. Pesan Tiket" << endl;
        cout << "2. Lihat Daftar Pesanan Terkonfirmasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            string start, end, date, chair, orderId, contact;
            int numberOfPassengers;

            cout << "Dari mana: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, start);

            cout << "Mau kemana: ";
            getline(cin, end);

            cout << "Tanggal: ";
            getline(cin, date);

            cout << "Jumlah Penumpang: ";
            cin >> numberOfPassengers;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Pilih Kursi: ";
            getline(cin, chair);

            cout << "Nomor Telepon/Email (untuk konfirmasi): ";
            getline(cin, contact);

            system("cls");
            orderId = generateOrder();

            cout << "Pesanan Anda berhasil dikonfirmasi!" << endl;
            cout << "Nomor Pesanan: " << orderId << endl;

            sendConfirmation(contact);
            generateVirtualAccountNumber();

            cout << "Apakah Anda ingin melakukan pembayaran online? (1: Ya, 0: Tidak) ";
            int opsiPembayaran;
            cin >> opsiPembayaran;

            if (opsiPembayaran == 1 && makeOnlinePayment())
            {
                system("cls");
                confirmedOrders.push_back("Nomor Pesanan: " + orderId +
                                          " | Tujuan: " + end +
                                          " | Tanggal: " + date +
                                          " | Kursi: " + chair +
                                          " | contact: " + contact);
            }
            else
            {
                cout << "Pembayaran gagal atau dibatalkan. Pesanan tidak disimpan." << endl;
            }
            break;
        }
        case 2:
            system("cls");
            displayConfirmedOrders(confirmedOrders);
            break;
        case 0:
            system("cls");
            cout << "Terima kasih telah menggunakan aplikasi pemesanan tiket bus." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

    } while (choice != 0);

    return 0;
}
