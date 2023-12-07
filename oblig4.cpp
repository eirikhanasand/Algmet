/**
 *   Programeksempel nr 29 - Hashing - selvlaget enkel klasse.
 *
 *   Eksemplet viser to ulike former for hashing:
 *      - Linear Probing
 *      - Double Hashing
 *
 *   Litt mer om hashing:  Hashing.pdf
 *
 *   Orden ( O(...)):
 *     LINEAR PROBING bruker gjennomsnittlig mindre enn fem 'probes',
 *     for å få på plass et element, for en tabell som er mindre enn 2/3 full.
 *     DOUBLE HASHING bruker gjennomsnittlig færre 'probes' enn linear probing.
 *     SEPARATE CHAINING reduserer antall sammenligninger ved sekvensielt søk
 *     med en gjennomsnittlig faktor på  M,  når det er M stacker/LIFO-lister.
 *
 *   @file     EKS_29_Hashing.CPP
 *   @author   Frode Haug, NTNU
 */


#include <iostream>          //  cout
#include <iomanip>           //  setw
#include <cctype>            //  toupper
using namespace std;


/**
 *  Enum for hashtabell-type (linear probing eller double hashing).
 */
enum  HashType  {  LinearProbing, DoubleHashing  };


/**
 *  Container-klassen Hasing.
 *
 *  Inneholder en char-array ('tabell'), max. antall elementer i
 *  arrayen ('lengde'), samt hvilken type tabellen er av ('hType').
 */
class  Hashing {
  private:
      char* tabell;                       //  Hash-tabellen
      int   lengde;                       //  Tabellens lengde.
      HashType hType;                     //  Tabellen type ved hashing.

                                          //  Returnerer  k % M:
      int hash1(const int modVerdi, const int kVerdi) {
          return (kVerdi % modVerdi);
      }

                                          //  Returnerer  H - (k % H):
      int hash2(const int hashVerdi, const int kVerdi) {
          return (hashVerdi - (kVerdi % hashVerdi));
      }


      int kVerdi(char bokstav) {          //  Gjør om A-Z til 1-26:
          bokstav = toupper(bokstav);              //  Til stor bokstav.
          if (bokstav >= 'A'  &&  bokstav <= 'Z')  //  ER bokstav:
              return (static_cast <int> (bokstav - 'A') + 1);
          else  return 0;                          //  IKKE bokstav.
      }


  public:
      Hashing(const HashType hT, const int len) {  //  Constructor:
          lengde = len;    hType = hT;             //  Initierer medlemmer.
          tabell = new char[len];                  //  Lager hash-tabell
          for (int i = 0; i < lengde; i++)  tabell[i] = '-'; //  Nullstiller.
      }


      ~Hashing()  {  delete []  tabell;  }         //  Destructor.


      void display() const {                       //  Skriver HELE hash-
          for (int i = 0; i < lengde; i++)         //   tabellens innhold:
              cout << setw(3) << i << ':';            cout << '\n';
          for (int i = 0; i < lengde; i++)
              cout << "  " << tabell[i] << ' ';       cout << "\n\n";
      }

                                      //  Setter inn 'data' i hash-tabellen:
                                      //   (Og der 'hash2' bruker 'hashVerdi')
      void insert(const int hashVerdi, const char data) {
          int dataTilK = kVerdi(data);                //  Får 'k' for 'data'.
          int indeks   = hash1(lengde,    dataTilK);  //  Finner hash1-verdi.
          int tillegg  = hash2(hashVerdi, dataTilK);  //  Finner hash2-verdi.
                                          //  (Brukes KUN ved 'DoubleHashing')

       cout << data << "   k: " << dataTilK << "   h1: " << indeks << "   h2: " << tillegg << '\n';

                                         //  Looper til finner en ledig plass:
          while (tabell[indeks] != '-') {
                                         //  Hopper EN indeks (linear probing)
              indeks = (hType == LinearProbing) ?  //  eller TILLEGG (d.hash):
                                (indeks+1) : (indeks+tillegg);
              indeks %= lengde;          //  OM hopper utforbi, "wrapper" til
          }                              //    starten igjen !!!
          tabell[indeks] = data;         //  Setter inn på ledig funnet plass.
                                                     display();
      }
};



/**
 *  Hovedprogrammet:
 */
int main() {

    char tekst2[] = "ALGORITMERERLIVET";

    Hashing hashTabell2(DoubleHashing, 17);      //   en for double hashing.

// -------------------------     DOUBLE HASHING:     -------------------------

    for (int i = 0; i <= 17; i++)                //  Hasher tekst inn i den
        hashTabell2.insert(4, tekst2[i]);        //    for double hashing.

    return 0;
}