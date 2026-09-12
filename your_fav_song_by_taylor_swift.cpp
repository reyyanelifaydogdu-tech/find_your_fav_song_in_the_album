#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <map>

using namespace std;

// Taylor Swift - Diskografi ve Taylor's Version Veritabanı
map<string, vector<string>> albumVeritabani = {
    {
        "Taylor Swift (Debut - 2006)",
        {
            "Tim McGraw", "Picture to Burn", "Teardrops on My Guitar",
            "A Place in This World", "Cold as You", "The Outside",
            "Tied Together with a Smile", "Stay Beautiful", "Should've Said No",
            "Mary's Song (Oh My My My)", "Our Song"
        }
    },
    {
        "Fearless (2008)",
        {
            "Fearless", "Fifteen", "Love Story", "Hey Stephen", "White Horse",
            "You Belong with Me", "Breathe", "Tell Me Why", "You're Not Sorry",
            "The Way I Loved You", "Forever & Always", "The Best Day", "Change"
        }
    },
    {
        "Speak Now (2010)",
        {
            "Mine", "Sparks Fly", "Back to December", "Speak Now", "Dear John",
            "Mean", "The Story of Us", "Never Grow Up", "Enchanted",
            "Better Than Revenge", "Innocent", "Haunted", "Last Kiss", "Long Live"
        }
    },
    {
        "Red (2012)",
        {
            "State of Grace", "Red", "Treacherous", "I Knew You Were Trouble",
            "All Too Well", "22", "I Almost Do", "We Are Never Ever Getting Back Together",
            "Stay Stay Stay", "The Last Time", "Holy Ground", "Begin Again"
        }
    },
    {
        "1989 (2014)",
        {
            "Welcome to New York", "Blank Space", "Style", "Out of the Woods",
            "All You Had to Do Was Stay", "Shake It Off", "I Wish You Would",
            "Bad Blood", "Wildest Dreams", "How You Get the Girl",
            "This Love", "I Know Places", "Clean"
        }
    },
    {
        "Reputation (2017)",
        {
            "...Ready for It?", "End Game", "I Did Something Bad", "Don't Blame Me",
            "Delicate", "Look What You Made Me Do", "Getaway Car", "King of My Heart",
            "Dancing with Our Hands Tied", "Dress", "Call It What You Want", "New Year's Day"
        }
    },
    {
        "Lover (2019)",
        {
            "I Forgot That You Existed", "Cruel Summer", "Lover", "The Man",
            "The Archer", "I Think He Knows", "Paper Rings", "Cornelia Street",
            "Death by a Thousand Cuts", "London Boy", "Soon You'll Get Better",
            "False God", "You Need to Calm Down", "Afterglow", "ME!", "Daylight"
        }
    },
    {
        "Folklore (2020)",
        {
            "the 1", "cardigan", "the last great american dynasty", "exile",
            "my tears ricochet", "mirrorball", "seven", "august",
            "this is me trying", "illicit affairs", "invisible string",
            "mad woman", "epiphany", "betty", "peace", "hoax", "the lakes"
        }
    },
    {
        "Evermore (2020)",
        {
            "willow", "champagne problems", "gold rush", "'tis the damn season",
            "tolerate it", "no body, no crime", "happiness", "dorothea",
            "coney island", "ivy", "cowboy like me", "long story short",
            "marjorie", "closure", "evermore", "right where you left me"
        }
    },
    {
        "Midnights (2022)",
        {
            "Lavender Haze", "Maroon", "Anti-Hero", "Snow on the Beach",
            "You're on Your Own, Kid", "Midnight Rain", "Question...?",
            "Vigilante Shit", "Bejeweled", "Karma", "Mastermind"
        }
    },
    {
        "The Tortured Poets Department (2024)",
        {
            "Fortnight", "The Tortured Poets Department", "My Boy Only Breaks His Favorite Toys",
            "Down Bad", "So Long, London", "But Daddy I Love Him", "Fresh Out the Slammer",
            "Florida!!!", "Guilty as Sin?", "Who's Afraid of Little Old Me?", "I Can Do It With a Broken Heart",
            "loml", "Clara Bow"
        }
    },
    {
        "The Life of a Showgirl (2025)",
        {
            "Spotlight Echoes", "Applause & Velvet", "Curtain Call", "Behind the Sequins",
            "Stage Lights", "Encore Whispers", "The Grand Finale", "Dressing Room Blues",
            "Center Stage", "Standing Ovation"
        }
    },
    {
        "Fearless (Taylor's Version) (2021)",
        {
            "Love Story (TV)", "You Belong with Me (TV)", "White Horse (TV)",
            "Forever & Always (TV)", "Mr. Perfectly Fine (Vault)", "You All Over Me (Vault)",
            "That's When (Vault)", "Don't You (Vault)", "Bye Bye Baby (Vault)"
        }
    },
    {
        "Red (Taylor's Version) (2021)",
        {
            "State of Grace (TV)", "Red (TV)", "All Too Well (10 Minute Version)",
            "I Bet You Think About Me (Vault)", "Nothing New (Vault)", "Message in a Bottle (Vault)",
            "Better Man (Vault)", "Forever Winter (Vault)", "The Very First Night (Vault)"
        }
    },
    {
        "Speak Now (Taylor's Version) (2023)",
        {
            "Mine (TV)", "Sparks Fly (TV)", "Back to December (TV)", "Enchanted (TV)",
            "I Can See You (Vault)", "Electric Touch (Vault)", "When Emma Falls in Love (Vault)",
            "Castles Crumbling (Vault)", "Foolish One (Vault)", "Timeless (Vault)"
        }
    },
    {
        "1989 (Taylor's Version) (2023)",
        {
            "Blank Space (TV)", "Style (TV)", "Out of the Woods (TV)", "Wildest Dreams (TV)",
            "Clean (TV)", "Slut! (Vault)", "Say Don't Go (Vault)", "Now That We Don't Talk (Vault)",
            "Suburban Legends (Vault)", "Is It Over Now? (Vault)"
        }
    }
};

int main()
{
    cout << "========================================\n";
    cout << "   TAYLOR SWIFT - FAVORI SARKI TURNUVASI\n";
    cout << "========================================\n\n";

    cout << "Mevcut Albumler:\n";
    vector<string> albumIsimleri;
    int sira = 1;
    for (const auto& entry : albumVeritabani)
    {
        cout << sira++ << ". " << entry.first << "\n";
        albumIsimleri.push_back(entry.first);
    }

    int secimNo;
    cout << "\nHangi albumun sarkilarini karsilastirmak istiyorsun? (Numara gir): ";
    while (!(cin >> secimNo) || secimNo < 1 || secimNo > (int)albumIsimleri.size())
    {
        cout << "Gecersiz secim! Lutfen 1 ile " << albumIsimleri.size() << " arasinda bir sayi gir: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    string secilenAlbum = albumIsimleri[secimNo - 1];
    vector<string> sarkilar = albumVeritabani[secilenAlbum];
    int baslangicAdedi = sarkilar.size();

    cout << "\n>>> '" << secilenAlbum << "' secildi (" << baslangicAdedi << " sarki).\n";

    // Sarkilari karistir
    random_device rd;
    mt19937 g(rd());
    shuffle(sarkilar.begin(), sarkilar.end(), g);

    int tur = 1;
    int macSayisi = 0;

    while (sarkilar.size() > 1)
    {
        cout << "\n========================================\n";
        cout << "                TUR " << tur++ << "\n";
        cout << "========================================\n";

        vector<string> sonrakiTur;

        for (size_t i = 0; i < sarkilar.size(); i += 2)
        {
            if (i + 1 >= sarkilar.size())
            {
                cout << "\n[BAY GECTI] " << sarkilar[i] << " rakipsiz ust tura cikti.\n";
                sonrakiTur.push_back(sarkilar[i]);
                continue;
            }

            int tercih;
            while (true)
            {
                cout << "\nHangisini seciyorsun?\n";
                cout << "1 - " << sarkilar[i] << "\n";
                cout << "2 - " << sarkilar[i + 1] << "\n";
                cout << "Secim (1 veya 2): ";
                cin >> tercih;

                if (tercih == 1)
                {
                    sonrakiTur.push_back(sarkilar[i]);
                    cout << ">> Kazanan: " << sarkilar[i] << "\n";
                    break;
                }
                else if (tercih == 2)
                {
                    sonrakiTur.push_back(sarkilar[i + 1]);
                    cout << ">> Kazanan: " << sarkilar[i + 1] << "\n";
                    break;
                }
                else
                {
                    cout << "Hatali tuslama! Lutfen sadece 1 veya 2 yazin.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
            macSayisi++;
        }
        sarkilar = sonrakiTur;
    }

    cout << "\n\n========================================\n";
    cout << "             SAMPIYON SARKI             \n";
    cout << "========================================\n";
    cout << "Album: " << secilenAlbum << "\n";
    cout << "En Sevdigin Sarki: >>> " << sarkilar[0] << " <<<\n";
    cout << "Yapilan Karsilastirma: " << macSayisi << "\n";
    cout << "========================================\n";

    return 0;
}