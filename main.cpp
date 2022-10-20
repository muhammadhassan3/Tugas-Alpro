#include <iostream>

using namespace std;

const string rejectedMessage = "Anda tidak lolos seleksi beasiswa IOM";

int main() {
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
        } else if (jmlPenghasilan > 2000000) {
            cout << "Penghasilan anda lebih dari 2.000.000" << endl;
        }
        cout << "Masukkan jumlah tanggungan : ";
        cin >> jmlTanggungan;
        float average = jmlPenghasilan/jmlTanggungan;
        if(average >= 750000){
            cout << rejectedMessage;
            return 0;
        }else{
            cout << "Apakah anda mengikuti organisasi? (Y/T) : ";
            cin >> response;
            if(tolower(response) == 'y'){
                cout << "Anda mengikuti organisasi"<<endl;
            }else cout << "Anda tidak mengikuti organisasi"<<endl;
            float ipk = 0;
            cout << "Masukkan IPK anda : ";
            cin >> ipk;
            if(ipk < 2.75){
                cout << rejectedMessage << endl;
                return 0;
            }else if(ipk  > 2.75 && ipk < 3.00){
                cout << "IPK anda lebih dari 2,75 dan kurang dari 3,00";
            }else if(ipk > 3.00){
                cout << "IPK anda lebih dari 3,00" << endl;
            }

            cout << "Apakah anda memiliki prestasi? (Y/T) : ";
            cin >> response;
            if(tolower(response) == 'y'){
                cout << "Anda lolos seleksi beasiswa IOM dengan prestasi"<<endl;
                return 0;
            }else{
                cout << "Anda lolos seleksi beasiswa IOM tanpa prestasi"<<endl;
                return 0;
            }
        }
    } else {
        cout << rejectedMessage;
    }
    return 0;
}
