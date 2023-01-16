#include <bits/stdc++.h>

using namespace std;

class Oameni {
public:
    Oameni();

    Oameni(string);

    Oameni(const Oameni &);

    void set_nume(string);

    int get_id();

    string get_nume();

    static int generare_id();

    friend istream &operator>>(istream &, Oameni &);

    friend ostream &operator<<(ostream &, Oameni);

    Oameni &operator=(Oameni);

protected:
    string nume;

    int idOm;

    static int ultimulIdGenerat;
};

Oameni::Oameni() {
    idOm = generare_id();
}

Oameni::Oameni(string name) {
    idOm = generare_id();
    this->nume = name;
}

Oameni::Oameni(const Oameni &om) {
    this->idOm = om.idOm;
    this->nume = om.nume;
}

int Oameni::ultimulIdGenerat = 0;

void Oameni::set_nume(string name) {
    this->nume = name;
}

int Oameni::get_id() {
    return this->idOm;
}

string Oameni::get_nume() {
    return this->nume;
}

int Oameni::generare_id() {
    return ultimulIdGenerat++;
}

Oameni &Oameni::operator=(Oameni om) {
    this->idOm = om.idOm;
    this->nume = om.nume;
    return *this;
}

istream &operator>>(istream &citire, Oameni &om) {
    citire >> om.nume;
    return citire;
}

ostream &operator<<(ostream &afisare, Oameni om) {
    afisare << om.idOm << " " << om.nume << "\n";
    return afisare;
}

class TehnicaMilitara {
public:
    TehnicaMilitara();

    TehnicaMilitara(int);

    TehnicaMilitara(const TehnicaMilitara &);

    virtual ~TehnicaMilitara();

    void set_calibru(int);

    int get_calibru();

    int verificare(int);

    friend istream &operator>>(istream &, TehnicaMilitara &);

    friend ostream &operator<<(ostream &, TehnicaMilitara &);

    TehnicaMilitara &operator=(TehnicaMilitara);

protected:
    int calibru;
};

TehnicaMilitara::TehnicaMilitara() {}

TehnicaMilitara::TehnicaMilitara(int valoare) {
    this->calibru = valoare;
}

TehnicaMilitara::TehnicaMilitara(const TehnicaMilitara &stoc) {
    this->calibru = stoc.calibru;
}

TehnicaMilitara::~TehnicaMilitara() {}

void TehnicaMilitara::set_calibru(int valoare) {
    this->calibru = valoare;
}

int TehnicaMilitara::get_calibru() {
    return this->calibru;
}

istream &operator>>(istream &citire, TehnicaMilitara &stoc) {
    citire >> stoc.calibru;
    return citire;
}

ostream &operator<<(ostream &afisare, TehnicaMilitara &stoc) {
    afisare << stoc.calibru;
    return afisare;
}

TehnicaMilitara &TehnicaMilitara::operator=(TehnicaMilitara stocPrimit) {
    this->calibru = stocPrimit.calibru;
    return *this;
}

class Arme : public TehnicaMilitara {
public:
    Arme();

    Arme(int, int, int, int);

    Arme(const Arme &);

    void set_pistoale(int);

    void set_mitraliere(int);

    void set_pusti(int);

    int get_pistoale();

    int get_mitraliere();

    int get_pusti();

    friend istream &operator>>(istream &, Arme &);

    friend ostream &operator<<(ostream &, Arme &);

    Arme &operator=(Arme);

    Arme operator+(Arme);

    Arme operator+=(int);

    Arme operator-(Arme);

    Arme operator-=(int);

private:
    int nrPistoale, nrMitraliere, nrPusti;
};

Arme::Arme() : TehnicaMilitara() {}

Arme::Arme(int calibru, int pistoale, int mitraliere, int pusti) : TehnicaMilitara(calibru) {
    this->nrPistoale = pistoale;
    this->nrMitraliere = mitraliere;
    this->nrPusti = pusti;
}

Arme::Arme(const Arme &arme) : TehnicaMilitara(arme) {
    this->nrPistoale = arme.nrPistoale;
    this->nrMitraliere = arme.nrMitraliere;
    this->nrPusti = arme.nrPusti;
}

void Arme::set_pistoale(int pistoale) {
    this->nrPistoale = pistoale;
}

void Arme::set_pusti(int pusti) {
    this->nrPusti = pusti;
}

void Arme::set_mitraliere(int mitraliere) {
    this->nrMitraliere = mitraliere;
}

int Arme::get_pistoale() {
    return this->nrPistoale;
}

int Arme::get_pusti() {
    return this->nrPusti;
}

int Arme::get_mitraliere() {
    return this->nrMitraliere;
}

istream &operator>>(istream &citire, Arme &arme) {
    citire >> arme.calibru >> arme.nrPistoale >> arme.nrMitraliere >> arme.nrPusti;
    return citire;
}

ostream &operator<<(ostream &afisare, Arme &arme) {
    afisare << arme.calibru << arme.nrPistoale << arme.nrMitraliere << arme.nrPusti;
    return afisare;
}

Arme &Arme::operator=(Arme arme) {
    this->nrPusti = arme.nrPusti;
    this->nrMitraliere = arme.nrMitraliere;
    this->nrPistoale = arme.nrPistoale;
    return *this;
}

Arme Arme::operator+=(int arm2) {
    this->nrPusti = nrPusti + arm2;
    this->nrMitraliere = nrMitraliere + arm2;
    this->nrPistoale = nrPistoale + arm2;
    return *this;
}

Arme Arme::operator+(Arme arm2) {
    this->nrPusti += arm2.nrPusti;
    this->nrPistoale += arm2.nrPistoale;
    this->nrMitraliere += arm2.nrMitraliere;
    return *this;
}

Arme Arme::operator-=(int arm2) {
    this->nrPusti -= arm2;
    this->nrPistoale -= arm2;
    this->nrMitraliere -= arm2;
    return *this;
}

Arme Arme::operator-(Arme arm2) {
    this->nrPusti -= arm2.nrPusti;
    this->nrPistoale -= arm2.nrPistoale;
    this->nrMitraliere -= arm2.nrMitraliere;
    return *this;
}

class Munitie : public TehnicaMilitara {
public:
    Munitie();

    Munitie(int, int, int, int);

    Munitie(const Munitie &);

    void set_gloantepistoale(int);

    void set_gloantepusti(int);

    void set_gloantemitraliere(int);

    int get_gloantepistoale();

    int get_gloantemitraliere();

    int get_gloantepusti();

    friend istream &operator>>(istream &stream, Munitie &);

    friend ostream &operator<<(ostream &stream, Munitie &);

    Munitie operator+=(int mun2);

    Munitie operator-=(int mun2);

    Munitie operator+(Munitie mun2);

    Munitie operator-(Munitie mun2);

private:
    int gloantePistoale, gloanteMitraliere, gloantePusti;
};

Munitie::Munitie() {}

Munitie::Munitie(int glPistoale, int glPusti, int glMitraliere, int val) : TehnicaMilitara(val) {
    this->gloantePistoale = glPistoale;
    this->gloanteMitraliere = glMitraliere;
    this->gloantePusti = glPusti;
}

Munitie::Munitie(const Munitie &munitie) : TehnicaMilitara(munitie) {
    this->gloantePistoale = munitie.gloantePistoale;
    this->gloantePusti = munitie.gloantePusti;
    this->gloanteMitraliere = munitie.gloanteMitraliere;
}

void Munitie::set_gloantepistoale(int cant) {
    gloantePistoale = cant;
}

void Munitie::set_gloantepusti(int cant) {
    gloantePusti = cant;
}

void Munitie::set_gloantemitraliere(int cant) {
    gloanteMitraliere = cant;
}

int Munitie::get_gloantepistoale() {
    return gloantePistoale;
}

int Munitie::get_gloantemitraliere() {
    return gloanteMitraliere;
}

int Munitie::get_gloantepusti() {
    return gloantePusti;
}

Munitie Munitie::operator-=(int mun2) {
    this->gloantePusti -= mun2;
    this->gloanteMitraliere -= mun2;
    this->gloantePistoale -= mun2;
    return *this;
}

Munitie Munitie::operator-(Munitie mun2) {
    this->gloantePusti -= mun2.gloantePusti;
    this->gloanteMitraliere -= mun2.gloanteMitraliere;
    this->gloantePistoale -= mun2.gloantePistoale;
    return *this;
}

Munitie Munitie::operator+(Munitie mun2) {
    this->gloantePusti += mun2.gloantePusti;
    this->gloanteMitraliere += mun2.gloanteMitraliere;
    this->gloantePistoale += mun2.gloantePistoale;
    return *this;
}

Munitie Munitie::operator+=(int mun2) {
    this->gloantePusti += mun2;
    this->gloanteMitraliere += mun2;
    this->gloantePistoale += mun2;
    return *this;
}

istream &operator>>(istream &citire, Munitie &munitie) {
    citire >> munitie.calibru >> munitie.gloantePistoale >> munitie.gloanteMitraliere >> munitie.gloantePusti;
    return citire;
}

ostream &operator<<(ostream &afisare, Munitie &munitie) {
    afisare << munitie.calibru << " " << munitie.gloantePistoale << " " << munitie.gloanteMitraliere << " "
            << munitie.gloantePusti << "\n";
    return afisare;
}

class Coordonate {
public:
    Coordonate();

    Coordonate(int, int, int);

    Coordonate(const Coordonate &);

    void set_grade(int);

    void set_minute(int);

    void set_secunde(int);

    int get_grade();

    int get_minute();

    int get_secunde();

    void coord_atac(int, int, int, int);

    void determinare_coordonate(float);

    friend istream &operator>>(istream &, Coordonate &);

    friend ostream &operator<<(ostream &, Coordonate &);

    friend bool operator!=(Coordonate, Coordonate);

    friend class Decriptare;

    friend class Atacuri;

    Coordonate &operator=(Coordonate);

private:
    int grade, minute, secunde;
};

Coordonate::Coordonate() {}

Coordonate::Coordonate(int gr, int min, int sec) {
    this->grade = gr;
    this->minute = min;
    this->secunde = sec;
}

Coordonate::Coordonate(const Coordonate &coord) {
    this->grade = coord.grade;
    this->minute = coord.minute;
    this->secunde = coord.secunde;
}

void Coordonate::set_grade(int gr) {
    this->grade = gr;
}

void Coordonate::set_minute(int min) {
    this->minute = min;
}

void Coordonate::set_secunde(int sec) {
    this->secunde = sec;
}

int Coordonate::get_grade() {
    return this->grade;
}

int Coordonate::get_minute() {
    return this->minute;
}

int Coordonate::get_secunde() {
    return this->secunde;
}

void Coordonate::determinare_coordonate(float valoare) {
    this->grade = int(valoare);
    this->minute = int((valoare - this->grade) * 60);
    this->secunde = round((valoare - this->grade - this->minute / 60.0) * 3600);
}

void Coordonate::coord_atac(int gr, int min, int sec, int alterare) {
    this->grade = gr * alterare;
    this->minute = min * alterare + (this->grade);
    this->secunde = sec * alterare;
}

bool operator!=(Coordonate coord1, Coordonate coord2) {
    if (coord1.grade == coord2.grade)
        return false;
    if (coord1.minute == coord2.minute)
        return false;
    if (coord1.secunde == coord2.secunde)
        return false;
    return true;
}

Coordonate &Coordonate::operator=(Coordonate coord) {
    this->grade = coord.grade;
    this->minute = coord.minute;
    this->secunde = coord.secunde;
    return *this;
}

istream &operator>>(istream &stream, Coordonate &coord) {
    stream >> coord.grade >> coord.minute >> coord.secunde;
    return stream;
}

ostream &operator<<(ostream &stream, Coordonate &coord) {
    char grad = 248;
    stream << coord.grade << grad << coord.minute << "'" << coord.secunde << "''\n";
    return stream;
}

class GestionarArme : public Oameni {
public:
    GestionarArme();

    GestionarArme(string, string);

    GestionarArme(const GestionarArme &);

    void set_depozit(string);

    string get_depozit();

    int suplimentare_stoc(string);

    friend istream &operator>>(istream &, GestionarArme &);

    friend ostream &operator<<(ostream &, GestionarArme &);

    GestionarArme &operator=(GestionarArme);

private:
    string numeDepozitArme;
};

GestionarArme::GestionarArme() : Oameni() {
}

GestionarArme::GestionarArme(string name, string depozit) : Oameni(name) {
    this->numeDepozitArme = depozit;
}

GestionarArme::GestionarArme(const GestionarArme &depozit) : Oameni(depozit) {
    this->numeDepozitArme = depozit.numeDepozitArme;
}

void GestionarArme::set_depozit(string depozit) {
    this->numeDepozitArme = depozit;
}

string GestionarArme::get_depozit() {
    return this->numeDepozitArme;
}

int GestionarArme::suplimentare_stoc(string mesaj) {
    int stoc;
    stoc = stoi(mesaj);
    return stoc;
}

istream &operator>>(istream &citire, GestionarArme &gestionar) {
    citire >> gestionar.nume >> gestionar.numeDepozitArme;
    return citire;
}

ostream &operator<<(ostream &afisare, GestionarArme &gestionar) {
    afisare << gestionar.idOm << " " << gestionar.nume << " " << gestionar.numeDepozitArme << "\n";
    return afisare;
}

GestionarArme &GestionarArme::operator=(GestionarArme depozit) {
    this->idOm = depozit.idOm;
    this->nume = depozit.nume;
    this->numeDepozitArme = depozit.numeDepozitArme;
    return *this;
}

class GestionarMunitie : public Oameni {
public:
    GestionarMunitie();

    GestionarMunitie(string, string);

    GestionarMunitie(const GestionarMunitie &);

    void set_depozit(string);

    string get_depozit();

    int suplimentare_stoc(string);

    friend istream &operator>>(istream &, GestionarMunitie &);

    friend ostream &operator<<(ostream &, GestionarMunitie &);

    GestionarMunitie &operator=(GestionarMunitie);

private:
    string numeDepozitMunitie;
};

GestionarMunitie::GestionarMunitie() {}

GestionarMunitie::GestionarMunitie(string nume, string depozit) : Oameni(nume) {
    this->numeDepozitMunitie = depozit;
}

GestionarMunitie::GestionarMunitie(const GestionarMunitie &gestionar) : Oameni(gestionar) {
    this->idOm = gestionar.idOm;
    this->numeDepozitMunitie = gestionar.numeDepozitMunitie;
    this->nume = gestionar.nume;
}

void GestionarMunitie::set_depozit(string depozit) {
    this->numeDepozitMunitie = depozit;
}

string GestionarMunitie::get_depozit() {
    return this->numeDepozitMunitie;
}

int GestionarMunitie::suplimentare_stoc(string mesaj) {
    int stoc;
    stoc = stoi(mesaj);
    return stoc;
}

istream &operator>>(istream &citire, GestionarMunitie &gestionar) {
    citire >> gestionar.nume >> gestionar.numeDepozitMunitie;
    return citire;
}

ostream &operator<<(ostream &afisare, GestionarMunitie &gestionar) {
    afisare << gestionar.idOm << " " << gestionar.nume << " " << gestionar.numeDepozitMunitie << "\n";
    return afisare;
}

GestionarMunitie &GestionarMunitie::operator=(GestionarMunitie gestionar) {
    this->idOm = gestionar.idOm;
    this->nume = gestionar.nume;
    this->numeDepozitMunitie = gestionar.numeDepozitMunitie;
    return *this;
}

class Decriptare {
public:
    Decriptare();

    Decriptare(string, Oameni, int, Coordonate);

    Decriptare(const Decriptare &);

    void set_mesaj(string);

    void set_id(Oameni);

    void set_cheie(int);

    string get_mesaj();

    Oameni get_id();

    int get_cheie();

    Coordonate get_coordonate();

    int verificare_autenticitate();

    void prelucrare_mesaj();

    friend istream &operator>>(istream &, Decriptare &);

    friend ostream &operator<<(ostream &, Decriptare &);

    Decriptare &operator=(Decriptare);

private:
    string mesaj;
    int cheie;
    Oameni idMesager;
    Coordonate coordonateMesaj;
};

Decriptare::Decriptare() {}

Decriptare::Decriptare(string msj, Oameni id, int key, Coordonate coord) {
    this->mesaj = msj;
    this->cheie = key;
    this->idMesager = id;
    this->coordonateMesaj = coord;
}

Decriptare::Decriptare(const Decriptare &decriptare) {
    this->idMesager = decriptare.idMesager;
    this->cheie = decriptare.cheie;
    this->mesaj = decriptare.mesaj;
    this->coordonateMesaj = decriptare.coordonateMesaj;
}

void Decriptare::set_cheie(int key) {
    this->cheie = key;
}

void Decriptare::set_id(Oameni om) {
    this->idMesager = om;
}

void Decriptare::set_mesaj(string msj) {
    this->mesaj = msj;
}

string Decriptare::get_mesaj() {
    return this->mesaj;
}

int Decriptare::get_cheie() {
    return this->cheie;
}

Oameni Decriptare::get_id() {
    return this->idMesager;
}

Coordonate Decriptare::get_coordonate() {
    return this->coordonateMesaj;
}

int Decriptare::verificare_autenticitate() {
    if (this->idMesager.get_id() < this->cheie)
        return 0;
    if ((this->idMesager.get_id() - this->cheie) % 2 == 0)
        return 0;
    if ((this->coordonateMesaj.get_grade() + this->coordonateMesaj.get_minute() + this->coordonateMesaj.get_secunde()) %
        2 == 0)
        return 0;
    return 1;
}

void Decriptare::prelucrare_mesaj() {
    int i;
    for (i = 0; this->mesaj[i]; i += 1)
        this->mesaj[i] = this->mesaj[i] xor this->cheie;
}

Decriptare &Decriptare::operator=(Decriptare decript) {
    this->mesaj = decript.mesaj;
    this->cheie = decript.cheie;
    this->idMesager = decript.idMesager;
    this->coordonateMesaj = decript.coordonateMesaj;
    return *this;
}

istream &operator>>(istream &citire, Decriptare &decriptare) {
    citire.get();
    getline(citire, decriptare.mesaj);
    citire >> decriptare.cheie;
    citire >> decriptare.idMesager;
    citire >> decriptare.coordonateMesaj;
    return citire;
}

ostream &operator<<(ostream &afisare, Decriptare &decriptare) {
    afisare << "idMesager: " << decriptare.idMesager;
    afisare << "Mesaj: " << decriptare.mesaj;
    afisare << "\nCheie: " << decriptare.cheie;
    afisare << "\nCoordonate: " << decriptare.coordonateMesaj << "\n";
    return afisare;
}

class Atacuri {
public:
    Atacuri();

    Atacuri(int, int, int, int, int, Coordonate);

    Atacuri(const Atacuri &);

    void set_luna(int);

    void set_zi(int);

    void set_an(int);

    void set_ora(int);

    void set_km(int);

    void set_zona(Coordonate);

    int get_luna();

    int get_zi();

    int get_an();

    int get_ora();

    int get_km();

    Coordonate get_zona();

    friend istream &operator>>(istream &, Atacuri &);

    friend ostream &operator<<(ostream &, Atacuri &);

    bool verificare_siguranta(int, int);

private:
    int luna, zi, an, ora, km_de_capitala;
    Coordonate zona;
};

Atacuri::Atacuri() {}

Atacuri::Atacuri(int h, int d, int m, int y, int km, Coordonate coord) {
    this->ora = h;
    this->zi = d;
    this->luna = m;
    this->an = y;
    this->km_de_capitala = km;
    this->zona = coord;
}

Atacuri::Atacuri(const Atacuri &atacuri) {
    this->zi = atacuri.zi;
    this->luna = atacuri.luna;
    this->an = atacuri.an;
    this->ora = atacuri.ora;
    this->km_de_capitala = atacuri.km_de_capitala;
    this->zona = atacuri.zona;
}

void Atacuri::set_ora(int h) {
    this->ora = h;
}

void Atacuri::set_zi(int d) {
    this->zi = d;
}

void Atacuri::set_luna(int m) {
    this->luna = m;
}

void Atacuri::set_an(int y) {
    this->an = y;
}

void Atacuri::set_km(int km) {
    this->km_de_capitala = km;
}

void Atacuri::set_zona(Coordonate coord) {
    this->zona = coord;
}

int Atacuri::get_ora() {
    return this->ora;
}

int Atacuri::get_zi() {
    return this->zi;
}

int Atacuri::get_luna() {
    return this->luna;
}

int Atacuri::get_an() {
    return this->an;
}

int Atacuri::get_km() {
    return this->km_de_capitala;
}

Coordonate Atacuri::get_zona() {
    return this->zona;
}

bool Atacuri::verificare_siguranta(int h, int km) {
    if (!(h < 8 or h > 20))
        return false;
    if (km > 100)
        return false;
    return true;
}

istream &operator>>(istream &citire, Atacuri &atacuri) {
    citire >> atacuri.ora >> atacuri.zi >> atacuri.luna >> atacuri.an >> atacuri.zona;
    return citire;
}

ostream &operator<<(ostream &afisare, Atacuri &atacuri) {
    afisare << "Atacul va avea loc la \nOra: " << atacuri.ora << ":00\nZiua: " << atacuri.zi << "\nLuna: "
            << atacuri.luna
            << "\nAnul: " << atacuri.an << "\nZona de coordonate: " << atacuri.zona << "Atacul are loc la "
            << atacuri.km_de_capitala
            << "km de Paris.\n";
    return afisare;
}

class Spion : public Oameni {
public:
    Spion();

    Spion(string, string);

    Spion(const Spion &);

    void set_nume(string);

    string get_nume();

    int aprobare_atac(string);

    friend istream &operator>>(istream &, Spion &);

    friend ostream &operator<<(ostream &, Spion &);

    Spion &operator=(Spion);

private:
    string numeDeCod;
};

Spion::Spion() {}

Spion::Spion(string name, string porecla) : Oameni(name) {
    this->numeDeCod = porecla;
}

Spion::Spion(const Spion &spion) : Oameni(spion) {
    this->numeDeCod = spion.numeDeCod;
}

void Spion::set_nume(string porecla) {
    this->numeDeCod = porecla;
}

string Spion::get_nume() {
    return this->numeDeCod;
}

int Spion::aprobare_atac(string mesaj) {
    Atacuri atac;
    Coordonate coord;
    char valori[1001], *p;
    strcpy(valori, (mesaj).c_str());
    p = strtok(valori, "_");
    atac.set_ora(atoi(p));
    p = strtok(NULL, "_");
    atac.set_zi(atoi(p));
    p = strtok(NULL, "_");
    atac.set_luna(atoi(p));
    p = strtok(NULL, "_");
    atac.set_an(atoi(p));
    p = strtok(NULL, "_");
    atac.set_km(atoi(p));
    atac.set_zona(coord);
    if (atac.verificare_siguranta(atac.get_ora(), atac.get_km()))
        return 1;
    else
        return 0;
}

istream &operator>>(istream &citire, Spion &spion) {
    citire >> spion.nume >> spion.numeDeCod;
    return citire;
}

ostream &operator<<(ostream &afisare, Spion &spion) {
    afisare << spion.idOm << " " << spion.nume << " " << spion.numeDeCod << "\n";
    return afisare;
}

Spion &Spion::operator=(Spion spion) {
    this->idOm = spion.idOm;
    this->nume = spion.nume;
    this->numeDeCod = spion.numeDeCod;
    return *this;
}

///         Tehnica Militara
///             /      \
///          Arme     Munitie


int main() {
    vector<Decriptare> mesaje;
    vector<Arme> depozitArme;
    vector<Munitie> depozitMunitie;
    vector<TehnicaMilitara *> tehnica;
    bool meniu0 = true, meniu1 = true, meniu2 = true, meniu3 = true, meniu4 = true;
    int optiune1, optiune2, optiune3, optiune4, index;
    string ceva;
    while (meniu0) {
        cout << "Apasati orice buton pentru a deschide dispozitivul si apasati enter!\n";
        cin >> ceva;
        cout << "Se deschide dispozitivul. Asteptati.\n";
        cout << char(201);
        for (index = 0; index < 21; index += 1) {
            cout << char(205);
        }
        cout << char(187) << "\n" << char(186) << " ";
        for (index = 0; index < 10; index += 1) {
            cout << char(219) << " ";
            for (int j = 0; j < 60000000; j += 1);
        }
        cout << char(186) << " 100%\n" << char(200);
        for (index = 0; index < 21; index += 1) {
            cout << char(205);
        }
        cout << char(188) << "\n";
        while (meniu1) {
            cout
                    << " ___    __    __    _   _       __        ___   ____      ___   ____  __   __    _     _   ___   ____  ___   ____ \n";
            cout
                    << "| |_)  / /\\  / /`_ | | | |\\ |  / /\\      | | \\ | |_      | | \\ | |_  ( (` / /`  | |_| | | | | \\ | |_  | |_) | |_  \n";
            cout
                    << "|_|   /_/--\\ \\_\\_/ |_| |_| \\| /_/--\\     |_|_/ |_|__     |_|_/ |_|__ _)_) \\_\\_, |_| | |_| |_|_/ |_|__ |_| \\ |_|__ \n";
            cout << "1 - Resurse umane\n2 - Mesaje\n3 - Depozit\n4 - Inchidere dispozitiv\n";
            cin >> optiune1;
            if (optiune1 == 1) {
                try {
                    if (mesaje.empty())
                        throw 404;
                    meniu2 = true;
                    while (meniu2) {
                        cout << " ___   ____  __   _     ___   __   ____      _     _       __    _      ____ \n";
                        cout << "| |_) | |_  ( (` | | | | |_) ( (` | |_      | | | | |\\/|  / /\\  | |\\ | | |_  \n";
                        cout
                                << "|_| \\ |_|__ _)_) \\_\\_/ |_| \\ _)_) |_|__     \\_\\_/ |_|  | /_/--\\ |_| \\| |_|__ \n";
                        cout
                                << "Selecteaza ocupatia dumneavoastra: \n1 - Gestionar arme\n2 - Gestionar munitie\n3 - Spion\n4 - Pagina anterioara\n";
                        cin >> optiune2;
                        if (optiune2 == 1) {
                            //gestionar arme
                            cout
                                    << "  __    ___   _      ____\n / /\\  | |_) | |\\/| | |_  \n/_/--\\ |_| \\ |_|  | |_|__ \n";
                            GestionarArme gestionarArme;
                            int id, i, j;
                            cout << "Introduceti id-ul (int) mesagerului al carui mesaj vreti sa il prelucrati.\n";
                            cin >> id;
                            try {
                                for (i = 0; i < mesaje.size() and mesaje[i].get_id().get_id() != id; i += 1);
                                if (i == mesaje.size())
                                    throw 'e';
                                i -= 1;

                                for (j = 0; mesaje[i].get_mesaj()[j]; j += 1) {
                                    if (!(mesaje[i].get_mesaj()[j] >= '0' and mesaje[i].get_mesaj()[j] <= '9')) {
                                        throw 100;
                                    }
                                }

                                int val = gestionarArme.suplimentare_stoc(mesaje[i].get_mesaj());
                                if (depozitArme.empty()) {
                                    Arme stoc(10, val, val, val);
                                    depozitArme.push_back(stoc);
                                } else {
                                    int calibru;
                                    cout << "Introduceti calibrul (int) noului stoc de arme.\n";
                                    cin >> calibru;
                                    Arme stoc(calibru, val, val, val), stocVechi;
                                    stocVechi = depozitArme.back();
                                    depozitArme.pop_back();
                                    stocVechi = stocVechi + stoc;
                                    depozitArme.push_back(stocVechi);
                                }
                            }
                            catch (char error) {
                                cout << "Id-ul tastat nu exista in baza de date.\n";
                            }
                            catch (int error) {
                                cout
                                        << "Id-ul tastat corespunde unui mesaj care nu poate fi prelucrat de un gestionar de arme. Incercati din nou.\n";
                            }
                        } else if (optiune2 == 2) {
                            //gestionar munitie
                            GestionarMunitie gestionarMunitie;
                            cout
                                    << " _      _     _      _  _____  _   ____ \n| |\\/| | | | | |\\ | | |  | |  | | | |_  \n|_|  | \\_\\_/ |_| \\| |_|  |_|  |_| |_|__ \n";
                            int id, i, j;
                            cout << "Introduceti id-ul (int) mesagerului al carui mesaj vreti sa il prelucrati.\n";
                            cin >> id;
                            try {
                                for (i = 0; i < mesaje.size() and mesaje[i].get_id().get_id() != id; i += 1);
                                if (i == mesaje.size())
                                    throw 'e';
                                i -= 1;
                                for (j = 0; mesaje[i].get_mesaj()[j]; j += 1) {
                                    if (!(mesaje[i].get_mesaj()[j] >= '0' and mesaje[i].get_mesaj()[j] <= '9'))
                                        throw 100;
                                }

                                int val = gestionarMunitie.suplimentare_stoc(mesaje[i].get_mesaj());
                                if (depozitMunitie.empty()) {
                                    Munitie stoc(10, val, val, val);
                                    depozitMunitie.push_back(stoc);
                                } else {
                                    int calibru;
                                    cout << "Introduceti calibrul (int) noului stoc de munitie.\n";
                                    cin >> calibru;
                                    Munitie stoc(calibru, val, val, val), stocVechi;
                                    stocVechi = depozitMunitie.back();
                                    depozitArme.pop_back();
                                    stocVechi = stocVechi + stoc;
                                    depozitMunitie.push_back(stocVechi);
                                }
                            }
                            catch (char error) {
                                cout << "Id-ul tastat nu exista in baza de date.\n";
                            }
                            catch (int error) {
                                cout
                                        << "Id-ul tastat corespunde unui mesaj care nu poate fi prelucrat de un Gestionar de munitie. Incercati din nou.\n";
                            }
                        } else if (optiune2 == 3) {
                            //spion
                            Spion spion;
                            cout
                                    << " __   ___   _   ___   _       __      _  \n( (` | |_) | | / / \\ | |\\ |  / /\\    | | \n_)_) |_|   |_| \\_\\_/ |_| \\| /_/--\\ \\_|_| \n";
                            int id, i, j;
                            cout << "Introduceti id-ul (int) mesagerului al carui mesaj vreti sa il prelucrati.\n";
                            cin >> id;
                            try {
                                for (i = 0; i < mesaje.size() and mesaje[i].get_id().get_id() != id; i += 1);
                                if (i == mesaje.size())
                                    throw 'e';
                                i -= 1;
                                for (j = 0; mesaje[i].get_mesaj()[j]; j += 1) {
                                    if (!((mesaje[i].get_mesaj()[j] >= '0' and mesaje[i].get_mesaj()[j] <= '9') or
                                          mesaje[i].get_mesaj()[j] == '_'))
                                        throw 100;
                                }
                                if (spion.aprobare_atac(mesaje[i].get_mesaj())) {
                                    cout << "Atacul poate avea loc.\n";
                                } else {
                                    cout << "Atacul este o capcana.\n";
                                }
                            }
                            catch (char error) {
                                cout << "Id-ul tastat nu exista in baza de date.\n";
                            }
                            catch (int error) {
                                cout
                                        << "Id-ul tastat corespunde unui mesaj care nu poate fi prelucrat de un spion. Incercati din nou. \n";
                            }
                        } else if (optiune2 == 4) {
                            //back
                            meniu2 = false;
                        } else {
                            cout << " __  \n";
                            cout << "|  | \n";
                            cout << "|  | \n";
                            cout << "|__|         Optiune invalida. Introduceti din nou.\n";
                            cout << " __  \n";
                            cout << "|__| \n\n";
                        }
                    }
                }
                catch (int nr) {
                    cout << " __  \n";
                    cout << "|  | \n";
                    cout << "|  | \n";
                    cout
                            << "|__|         Nu exista mesaje de prelucrat. Introduceti mai intai un mesaj in sectiunea mesaje.\n";
                    cout << " __  \n";
                    cout << "|__| \n\n";
                }
            } else if (optiune1 == 2) {
                meniu3 = true;
                while (meniu3) {
                    cout << " _      ____  __    __      _   ____ \n";
                    cout << "| |\\/| | |_  ( (`  / /\\    | | | |_  \n";
                    cout << "|_|  | |_|__ _)_) /_/--\\ \\_|_| |_|__ \n";
                    cout
                            << "1 - Criptare mesaj\n2 - Decriptare mesaj\n3 - Introducere mesaj\n4 - Afisare mesaje\n5 - Verificare mesaje\n6 - Pagina anterioara\n";
                    cin >> optiune3;
                    if (optiune3 == 1) {
                        //criptare
                        cout << " __    ___   _   ___  _____   __    ___   ____ \n";
                        cout << "/ /`  | |_) | | | |_)  | |   / /\\  | |_) | |_  \n";
                        cout << "\\_\\_, |_| \\ |_| |_|    |_|  /_/--\\ |_| \\ |_|__ \n";
                        if (mesaje.empty()) {
                            cout << " __  \n";
                            cout << "|  | \n";
                            cout << "|  | \n";
                            cout << "|__|         Nu exista mesaje de criptat. Introduceti mai intai un mesaj.\n";
                            cout << " __  \n";
                            cout << "|__| \n\n";
                        } else {
                            meniu4 = true;
                            while (meniu4) {
                                int i, gasit;
                                cout
                                        << "1 - Prelucrare toate mesajele\n2 - Prelucrare mesaj unic\n3 - Pagina anterioara\n";
                                cin >> optiune4;
                                if (optiune4 == 1) {
                                    for (i = 0; i < mesaje.size(); i += 1) {
                                        mesaje[i].prelucrare_mesaj();
                                    }
                                } else if (optiune4 == 2) {
                                    int id;
                                    gasit = 0;
                                    cout
                                            << "Introduceti id-ul (int) mesagerului al carui mesaj vreti sa il prelucrati.\n";
                                    cin >> id;
                                    for (i = 0; i < mesaje.size() and gasit == 0; i += 1) {
                                        //Intrucat mesaje[i].get_id() imi returneaza un obiect de tip Oameni, apelez
                                        // pentru acest obiect functia specifica acestuia pentru obtinerea id-ului (int).
                                        if (mesaje[i].get_id().get_id() == id) {
                                            gasit = 1;
                                        }
                                    }
                                    mesaje[i].prelucrare_mesaj();
                                } else if (optiune4 == 3) {
                                    meniu4 = false;
                                } else {
                                    cout << " __  \n";
                                    cout << "|  | \n";
                                    cout << "|  | \n";
                                    cout << "|__|         Optiune invalida. Introduceti din nou.\n";
                                    cout << " __  \n";
                                    cout << "|__| \n\n";
                                }
                            }
                        }
                    } else if (optiune3 == 2) {
                        //decriptare
                        cout << " ___   ____  __    ___   _   ___  _____   __    ___   ____ \n";
                        cout << "| | \\ | |_  / /`  | |_) | | | |_)  | |   / /\\  | |_) | |_  \n";
                        cout << "|_|_/ |_|__ \\_\\_, |_| \\ |_| |_|    |_|  /_/--\\ |_| \\ |_|__ \n";
                        if (mesaje.empty()) {
                            cout << " __  \n";
                            cout << "|  | \n";
                            cout << "|  | \n";
                            cout << "|__|         Nu exista mesaje de decriptat. Introduceti mai intai un mesaj.\n";
                            cout << " __  \n";
                            cout << "|__| \n\n";
                        } else {
                            meniu4 = true;
                            while (meniu4) {
                                int i, gasit;
                                cout
                                        << "1 - Prelucrare toate mesajele\n2 - Prelucrare mesaj unic\n3 - Pagina anterioara\n";
                                cin >> optiune4;
                                if (optiune4 == 1) {
                                    for (i = 0; i < mesaje.size(); i += 1) {
                                        mesaje[i].prelucrare_mesaj();
                                    }
                                } else if (optiune4 == 2) {
                                    int id;
                                    gasit = 0;
                                    cout
                                            << "Introduceti id-ul (int) mesagerului al carui mesaj vreti sa il prelucrati.\n";
                                    cin >> id;
                                    for (i = 0; i < mesaje.size() and gasit == 0; i += 1) {
                                        //Intrucat mesaje[i].get_id() imi returneaza un obiect de tip Oameni, apelez
                                        // pentru acest obiect functia specifica acestuia pentru obtinerea id-ului (int).
                                        if (mesaje[i].get_id().get_id() == id) {
                                            gasit = 1;
                                        }
                                    }
                                    mesaje[i].prelucrare_mesaj();
                                } else if (optiune4 == 3) {
                                    meniu4 = false;
                                } else {
                                    cout << " __  \n";
                                    cout << "|  | \n";
                                    cout << "|  | \n";
                                    cout << "|__|         Optiune invalida. Introduceti din nou.\n";
                                    cout << " __  \n";
                                    cout << "|__| \n\n";
                                }
                            }
                        }
                    } else if (optiune3 == 3) {
                        //citire
                        cout << " __    _  _____  _   ___   ____ \n";
                        cout << "/ /`  | |  | |  | | | |_) | |_  \n";
                        cout << "\\_\\_, |_|  |_|  |_| |_| \\ |_|__ \n";
                        Decriptare mesaj;
                        cout
                                << "Introduceti, in ordine, mesajul (string), cheia (int), numele de familie al mesagerului (string) si coordonatele de unde a fost primit mesajul (grade (int), minute (int), secunde (int)):\n";
                        cin >> mesaj;
                        mesaje.push_back(mesaj);
                    } else if (optiune3 == 4) {
                        //afisare
                        cout << "  __    ____  _   __    __    ___   ____ \n";
                        cout << " / /\\  | |_  | | ( (`  / /\\  | |_) | |_  \n";
                        cout << "/_/--\\ |_|   |_| _)_) /_/--\\ |_| \\ |_|__ \n";
                        if (mesaje.empty()) {
                            cout << " __  \n";
                            cout << "|  | \n";
                            cout << "|  | \n";
                            cout << "|__|         Nu exista mesaje de criptat. Introduceti mai intai un mesaj.\n";
                            cout << " __  \n";
                            cout << "|__| \n\n";
                        } else {
                            int i;
                            for (i = 0; i < mesaje.size(); i += 1) {
                                cout << mesaje[i];
                            }
                        }
                    } else if (optiune3 == 5) {
                        cout << " _      ____  ___   _   ____  _   __     __    ___   ____ \n";
                        cout << "\\ \\  / | |_  | |_) | | | |_  | | / /`   / /\\  | |_) | |_  \n";
                        cout << " \\_\\/  |_|__ |_| \\ |_| |_|   |_| \\_\\_, /_/--\\ |_| \\ |_|__ \n";
                        if (mesaje.empty()) {
                            cout << " __  \n";
                            cout << "|  | \n";
                            cout << "|  | \n";
                            cout
                                    << "|__|         Nu exista mesaje de verificat. Introduceti mai intai un mesaj.\n";
                            cout << " __  \n";
                            cout << "|__| \n\n";
                        } else {
                            meniu4 = true;
                            while (meniu4) {
                                cout
                                        << "1 - Verificare toate mesajele\n2 - Verificare mesaj unic\n3 - Pagina anterioara\n";
                                cin >> optiune4;
                                if (optiune4 == 1) {
                                    int i;
                                    for (i = 0; i < mesaje.size(); i += 1) {
                                        if (mesaje[i].verificare_autenticitate()) {
                                            cout << "Mesaj de incredere.\n";
                                        } else {
                                            cout << "Mesaj corupt\n";
                                        }
                                    }
                                } else if (optiune4 == 2) {
                                    int i, gasit = 0, id;
                                    cout
                                            << "Introduceti id-ul (int) mesagerului al carui mesaj vreti sa il verificati.\n";
                                    cin >> id;
                                    for (i = 0; i < mesaje.size() and gasit == 0; i += 1) {
                                        if (mesaje[i].get_id().get_id() == id) {
                                            gasit = 1;
                                        }
                                    }
                                    if (mesaje[i].verificare_autenticitate()) {
                                        cout << "Mesaj de incredere.\n";
                                    } else {
                                        cout << "Mesaj corupt\n";
                                    }

                                } else if (optiune4 == 3) {
                                    meniu4 = false;
                                } else {
                                    cout << " __  \n";
                                    cout << "|  | \n";
                                    cout << "|  | \n";
                                    cout << "|__|         Optiune invalida. Introduceti din nou.\n";
                                    cout << " __  \n";
                                    cout << "|__| \n\n";
                                }
                            }
                        }
                    } else if (optiune3 == 6) {
                        meniu3 = false;
                    } else {
                        cout << " __  \n";
                        cout << "|  | \n";
                        cout << "|  | \n";
                        cout << "|__|         Optiune invalida. Introduceti din nou.\n";
                        cout << " __  \n";
                        cout << "|__| \n\n";
                    }
                }
            } else if (optiune1 == 3) {
                //depozit arme
                cout << " ___   ____  ___   ___  ____  _  _____       __    ___   _      ____ \n";
                cout << "| | \\ | |_  | |_) / / \\  / / | |  | |       / /\\  | |_) | |\\/| | |_  \n";
                cout << "|_|_/ |_|__ |_|   \\_\\_/ /_/_ |_|  |_|      /_/--\\ |_| \\ |_|  | |_|__ \n";
                meniu3 = true;
                while (meniu3) {
                    cout
                            << "1 - Adauga stoc arme\n2 - Afisare stocuri arme\n3 - Adauga stoc munitie\n4 - Afisare stocuri munitie\n5 - Pagina anterioara\n";
                    cin >> optiune2;
                    if (optiune2 == 1) {
                        //Adauga stoc de arme
                        Arme stocArme;
                        cout
                                << "Introduceti (int), in ordine, calibrul, numarul de pistoale, numarul de mitraliere, numarul de pusti.\n";
                        cin >> stocArme;
                        tehnica.push_back(&stocArme);
                    } else if (optiune2 == 2) {
                        //Afisare stocuri arme
                        int i, calibru, gasit = -1;
                        cout << "Introduceti calibrul (int) pentru care vreti sa vizualizati stocurile de arme.\n";
                        cin >> calibru;
                        try {
                            for (i = 0; i < tehnica.size() and gasit == -1; i += 1) {
                                if (tehnica[i]->get_calibru() == calibru) {
                                    gasit = i;
                                }
                            }
                            if (gasit == -1) {
                                throw 'e';
                            }
                            cout << (dynamic_cast<Arme *>(tehnica[gasit])) << "\n";
                            Arme *arme = dynamic_cast<Arme *>(tehnica[gasit]);
                            if (arme == nullptr) {
                                throw 404;
                            }
                            cout << *(dynamic_cast<Arme *>(tehnica[gasit]));
                        }
                        catch (char eroare) {
                            cout << "Nu exista tehnica militara cu calibrul specificat. Introduceti o valoare noua.\n";
                        }
                        catch (int nr) {
                            cout << "Nu exista stoc de arme cu calibrul specificat. Introduceti o valoare noua.\n";
                        }
                    } else if (optiune2 == 3) {
                        //Adauga stoc de munitie
                        Munitie stocMunitie;
                        cout
                                << "Introduceti (int), in ordine, calibrul, numarul de gloante pistoale, numarul de gloante mitraliere, numarul de gloante pusti.\n";
                        cin >> stocMunitie;
                        tehnica.push_back(&stocMunitie);
                    } else if (optiune2 == 4) {
                        //Afisare stocuri munitie
                        int i, calibru, gasit = -1;
                        cout << "Introduceti calibrul (int) pentru care vreti sa vizualizati stocurile de munitie.\n";
                        cin >> calibru;
                        try {
                            for (i = 0; i < tehnica.size() and gasit == -1; i += 1) {
                                if (tehnica[i]->get_calibru() == calibru) {
                                    gasit = i;
                                }
                            }
                            if (gasit == -1) {
                                throw 'e';
                            }

                            if (dynamic_cast<Munitie *>(tehnica[gasit]) == nullptr) {
                                throw 404;
                            }

                            cout << *(dynamic_cast<Munitie *>(tehnica[gasit]));
                        }
                        catch (char eroare) {
                            cout << "Nu exista tehnica militara cu calibrul specificat. Introduceti o valoare noua.\n";
                        }
                        catch (int nr) {
                            cout << "Nu exista stoc de munitie cu calibrul specificat. Introduceti o valoare noua.\n";
                        }
                    } else if (optiune2 == 5) {
                        meniu3 = false;
                    } else {
                        cout << " __  \n";
                        cout << "|  | \n";
                        cout << "|  | \n";
                        cout << "|__|         Optiune invalida. Introduceti din nou.\n";
                        cout << " __  \n";
                        cout << "|__| \n\n";
                    }
                }
            } else if (optiune1 == 4) {
                meniu0 = meniu1 = meniu2 = false;
                cout << "Se inchide dispozitivul\n";
                cout << char(201);
                for (index = 0; index < 21; index += 1) {
                    cout << char(205);
                }
                cout << char(187) << "\n" << char(186) << " ";
                for (index = 0; index < 10; index += 1) {
                    cout << char(219) << " ";
                    for (int j = 0; j < 70000000; j += 1);
                }
                cout << char(186) << " 100%\n" << char(200);
                for (index = 0; index < 21; index += 1) {
                    cout << char(205);
                }
                cout << char(188) << "\n";
            } else {
                cout << " __  \n";
                cout << "|  | \n";
                cout << "|  | \n";
                cout << "|__|         Optiune invalida. Introduceti din nou.\n";
                cout << " __  \n";
                cout << "|__| \n\n";
            }
        }
    }

    return 0;
}
