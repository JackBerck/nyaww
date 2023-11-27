#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

string generateNomorPesanan() {
    srand(time(0));
    return to_string(rand() % 10000) + to_string(time(0));
}

void kirimKonfirmasi(const string& kontak) {
    cout << "Konfirmasi pemesanan telah dikirim ke " << kontak << endl;
}

void generateNomorVirtualAccount() {
    srand(time(0));
    cout << "Nomor Virtual Account: " << rand() % 1000000 << endl;
}

void tampilkanPesananTerkonfirmasi(const vector<string>& pesananTerkonfirmasi) {
    if (pesananTerkonfirmasi.empty()) {
        cout << "Belum ada pesanan yang terkonfirmasi." << endl;
    } else {
        cout << "=== Pesanan Terkonfirmasi ===" << endl;
        for (const string& pesanan : pesananTerkonfirmasi) {
            cout << pesanan << endl;
        }
    }
}

bool lakukanPembayaranOnline() {
    cout << "Pilih metode pembayaran online:" << endl;
    cout << "1. Kartu Kredit" << endl;
    cout << "2. Transfer Bank" << endl;
    cout << "3. E-Wallet" << endl;
    cout << "Pilihan Anda: ";

    int metodePembayaran;
    cin >> metodePembayaran;

    string nomorPembayaran;

    switch (metodePembayaran) {
        case 1:
            cout << "Masukkan nomor kartu kredit: ";
            cin >> nomorPembayaran;
            // Logika verifikasi kartu kredit (misalnya, validasi panjang nomor kartu, CVV, dll.)
            break;
        case 2:
            cout << "Masukkan nomor rekening bank: ";
            cin >> nomorPembayaran;
            // Logika verifikasi nomor rekening bank (misalnya, validasi panjang nomor rekening, nama pemilik, dll.)
            break;
        case 3:
            cout << "Masukkan nomor e-wallet: ";
            cin >> nomorPembayaran;
            // Logika verifikasi nomor e-wallet (misalnya, validasi panjang nomor e-wallet, PIN, dll.)
            break;
        default:
            cout << "Metode pembayaran tidak valid." << endl;
            return false;
    }

    // Logika untuk memproses pembayaran (misalnya, verifikasi dan konfirmasi pembayaran)
    cout << "Memproses pembayaran..." << endl;

    // Simulasi keberhasilan pembayaran
    return true;
}

int main() {
    vector<string> pesananTerkonfirmasi;

    int pilihan;
    do {
        cout << "============================================" << endl;
        cout << "=== Selamat Datang di Aplikasi Pemesanan Tiket Bus Nana ===" << endl;
        cout << "1. Pesan Tiket" << endl;
        cout << "2. Lihat Daftar Pesanan Terkonfirmasi" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: "; 
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string dari, tujuan, tanggal, kursi, nomorPesanan, kontak;
                int jumlahPenumpang;

                cout << endl << "Dari mana: "; cin >> dari;
                cout << endl << "Mau kemana: "; cin >> tujuan;
                cout << endl << "Tanggal: "; cin >> tanggal;
                cout << endl << "Jumlah Penumpang: "; cin >> jumlahPenumpang;
                cout << endl << "Pilih Kursi: "; cin >> kursi;
                cout << endl << "Nomor Telepon/Email (untuk konfirmasi): "; cin >> kontak;

                nomorPesanan = generateNomorPesanan();

                cout << "Pesanan Anda berhasil dikonfirmasi!" << endl;
                cout << "Nomor Pesanan: " << nomorPesanan << endl;

                kirimKonfirmasi(kontak);
                generateNomorVirtualAccount();

                cout << "Apakah Anda ingin melakukan pembayaran online? (1: Ya, 0: Tidak) ";
                int opsiPembayaran;
                cin >> opsiPembayaran;

                if (opsiPembayaran == 1 && lakukanPembayaranOnline()) {
                    pesananTerkonfirmasi.push_back("Nomor Pesanan: " + nomorPesanan +
                                                  " | Tujuan: " + tujuan +
                                                  " | Tanggal: " + tanggal +
                                                  " | Kursi: " + kursi +
                                                  " | Kontak: " + kontak);
                } else {
                    cout << "Pembayaran gagal atau dibatalkan. Pesanan tidak disimpan." << endl;
                }
                break;
            }
            case 2:
                tampilkanPesananTerkonfirmasi(pesananTerkonfirmasi);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi pemesanan tiket bus." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

    } while (pilihan != 0);

    return 0;
}
