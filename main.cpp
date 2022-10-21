#include <iostream>

using namespace std;

const string rejectedMessage = "Anda tidak lolos seleksi beasiswa IOM";

void tugas(), quiz();

int main() {
    tugas(); // use this for run tugas function
    quiz(); //use this for run quiz function
    return 0;
}

void quiz() {
    string npm, name, prodi, predicate = "Unidentified";
    int timeToComplete, totalD;
    float ipk;
    cout << "SISTEM PREDIKAT KELULUSAN MAHASISWA" << endl;
    cout << "NPM : ";
    cin >> npm;
    cout << "Nama : ";
    cin >> name;
    cout << "Prodi : ";
    cin >> prodi;
    cout << "IPK : ";
    cin >> ipk;

    cout << "Waktu tempuh studi : ";
    cin >> timeToComplete;
    cout << "Jumlah nilai D : ";
    cin >> totalD;


    if (timeToComplete == 3) {
        if (ipk >= 3.51 && ipk <= 4.00) {
            predicate = "DENGAN PUJIAN/CUM LAUDE";
        } else if (ipk >= 2.76 && ipk <= 3.50) {
            predicate = "SANGAT MEMUASKAN";
        } else if (ipk >= 2.00 && ipk <= 2.75) {
            predicate = "MEMUASKAN";
        }
    } else if (timeToComplete > 3 && timeToComplete <= 4) {
        if (totalD <= 2) {
            if (ipk >= 2.76 && ipk <= 4.00) {
                predicate = "SANGAT MEMUASKAN";
            } else if (ipk >= 2.00 && ipk <= 2.75) {
                predicate = "MEMUASKAN";
            }
        } else if (totalD <= 4) {
            if (ipk >= 2.00 && ipk <= 4) {
                predicate = "MEMUASKAN";
            }
        }
    }

    cout << "Mahasiswa dengan NPM " << npm << " atas nama " << name << " lulus dengan predikat " << predicate << endl;
}

void tugas() {
    float jmlPenghasilan = 0, jmlTanggungan = 0;
    cout << "Apakah anda sudah membayar IOM? (Y/T) : ";
    char response;
    cin >> response;
    if (tolower(response) == 'y') {
        cout << "Masukkan jumlah penghasilan anda : ";
        cin >> jmlPenghasilan;
        if (jmlPenghasilan < 1000000) {
            cout << "Penghasilan anda kurang dari 1 juta" << endl;
        } else if (jmlPenghasilan >= 1000000 && jmlPenghasilan < 1500000) {
            cout << "Penghasilan anda lebih dari 1 juta dan kurang dari 1.500.000" << endl;
        } else if (jmlPenghasilan >= 2000000) {
            cout << "Penghasilan anda lebih dari 2.000.000" << endl;
        } else if (jmlPenghasilan >= 1500000 && jmlPenghasilan < 2000000) {
            cout << "Penghasilan anda lebih dari 1.500.000 dan kurang dari 2.000.000" << endl;
        }
        cout << "Masukkan jumlah tanggungan : ";
        cin >> jmlTanggungan;
        float average = jmlPenghasilan / jmlTanggungan;
        if (average >= 750000) {
            cout << rejectedMessage;
            return;
        } else {
            cout << "Apakah anda mengikuti organisasi? (Y/T) : ";
            cin >> response;
            if (tolower(response) == 'y') {
                cout << "Anda mengikuti organisasi" << endl;
            } else cout << "Anda tidak mengikuti organisasi" << endl;
            float ipk = 0;
            cout << "Masukkan IPK anda : ";
            cin >> ipk;
            if (ipk < 2.75) {
                cout << rejectedMessage << endl;
                return;
            } else if (ipk > 2.75 && ipk < 3.00) {
                cout << "IPK anda lebih dari 2,75 dan kurang dari 3,00";
            } else if (ipk > 3.00) {
                cout << "IPK anda lebih dari 3,00" << endl;
            }

            cout << "Apakah anda memiliki prestasi? (Y/T) : ";
            cin >> response;
            if (tolower(response) == 'y') {
                cout << "Anda lolos seleksi beasiswa IOM dengan prestasi" << endl;
                return;
            } else {
                cout << "Anda lolos seleksi beasiswa IOM tanpa prestasi" << endl;
                return;
            }
        }
    } else {
        cout << rejectedMessage;
    }
}
