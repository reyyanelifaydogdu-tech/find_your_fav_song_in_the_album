
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
    // -------------------------------
    // 1. ALBUM BILGILERI
    // -------------------------------

    string albumAdi;
    int sarkiSayisi;

    cout << "==============================\n";
    cout << "   ALBUM FAVORI SARKI BULUCU\n";
    cout << "==============================\n\n";

    cout << "Album adini gir: ";
    getline(cin, albumAdi);

    cout << "Albumde kac sarki var? ";
    cin >> sarkiSayisi;

    if (sarkiSayisi < 2)
    {
        cout << "En az 2 sarki olmalidir.\n";
        return 1;
    }

    cin.ignore();

    // -------------------------------
    // 2. SARKILARI AL
    // -------------------------------

    vector<string> sarkilar(sarkiSayisi);

    cout << "\n--- SARKILARI GIR ---\n";

    for (int i = 0; i < sarkiSayisi; i++)
    {
        cout << i + 1 << ". sarki: ";
        getline(cin, sarkilar[i]);
    }

    // -------------------------------
    // 3. SARKILARI KARISTIR
    // -------------------------------

    random_device rd;
    mt19937 g(rd());

    shuffle(sarkilar.begin(), sarkilar.end(), g);

    // -------------------------------
    // 4. TURNUVA
    // -------------------------------

    int tur = 1;
    int karsilasmaSayisi = 0;

    while (sarkilar.size() > 1)
    {
        cout << "\n==============================\n";
        cout << "           TUR " << tur << "\n";
        cout << "==============================\n";

        vector<string> sonrakiTur;

        for (size_t i = 0; i < sarkilar.size(); i += 2)
        {
            // Tek sayida sarki kalirsa
            // son sarki otomatik olarak ilerler.

            if (i + 1 >= sarkilar.size())
            {
                cout << "\n[BAY GECTI]\n";
                cout << sarkilar[i] << " bir sonraki tura gecti.\n";

                sonrakiTur.push_back(sarkilar[i]);

                continue;
            }

            int secim;

            while (true)
            {
                cout << "\n------------------------------\n";
                cout << "Hangisini daha cok seviyorsun?\n\n";

                cout << "1 - " << sarkilar[i] << "\n";
                cout << "2 - " << sarkilar[i + 1] << "\n";

                cout << "\nSecimin (1 veya 2): ";
                cin >> secim;

                if (secim == 1)
                {
                    sonrakiTur.push_back(sarkilar[i]);

                    cout << "Kazanan: "
                         << sarkilar[i] << "\n";

                    break;
                }
                else if (secim == 2)
                {
                    sonrakiTur.push_back(sarkilar[i + 1]);

                    cout << "Kazanan: "
                         << sarkilar[i + 1] << "\n";

                    break;
                }
                else
                {
                    cout << "\nHatali secim!\n";
                    cout << "Lutfen sadece 1 veya 2 gir.\n";
                }
            }

            karsilasmaSayisi++;
        }

        // Bir sonraki tur icin
        // kazananlari yeni listeye aktar.

        sarkilar = sonrakiTur;

        tur++;
    }

    // -------------------------------
    // 5. FINAL
    // -------------------------------

    cout << "\n\n";
    cout << "====================================\n";
    cout << "             SONUC\n";
    cout << "====================================\n";

    cout << "Album: " << albumAdi << "\n";
    cout << "Sarki sayisi: " << sarkiSayisi << "\n";

    cout << "\n";
    cout << "FAVORI SARKIN:\n";
    cout << ">>> " << sarkilar[0] << " <<<\n";

    cout << "\nToplam karsilasma: "
         << karsilasmaSayisi << "\n";

    cout << "====================================\n";

    return 0;
}

