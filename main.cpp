#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <cstring>

using namespace std;
ifstream fin("date_companie.txt");
ofstream fout("output.txt");
class data {
  int zi;
  int luna;
  int an;
  public:
    data(int day, int month, int year): zi(day), luna(month), an(year) {}
  data(): zi(16), luna(3), an(2024) {}
  friend ostream & operator << (ostream & out,
    const data & d);
  friend int comparare(data data_1, data data_2);

};
class angajat {
  string nume;
  string prenume;
  int ID;
  int ID_departament;
  int salariu;
  data data_nasterii;
  public:
    angajat(string surname, string name, int dep, int sal, int zi_nastere, int luna_nastere, int an_nastere): nume(surname), prenume(name), ID_departament(dep), salariu(sal), data_nasterii(data(zi_nastere, luna_nastere, an_nastere)) {
      ID = genereaza_ID();
    }
  angajat(string surname, string name, int sal, int zi_nastere, int luna_nastere, int an_nastere): nume(surname), prenume(name), ID_departament(0), salariu(sal), data_nasterii(data(zi_nastere, luna_nastere, an_nastere)) {
    ID = genereaza_ID();
  }
  angajat(): nume("place_holder"), prenume("place_holder"), ID(0), data_nasterii(data()) {}
    ~angajat() {
      ID = 0, ID_departament = 0;
    }
  angajat(const angajat & a) {
    nume = a.nume;
    prenume = a.prenume;
    ID = a.ID;
    ID_departament = a.ID_departament;
    salariu = a.salariu;
    data_nasterii = a.data_nasterii;
  }
  void operator = (const angajat & a) {
    nume = a.nume;
    prenume = a.prenume;
    ID = a.ID;
    ID_departament = a.ID_departament;
    salariu = a.salariu;
    data_nasterii = a.data_nasterii;
  }
  int genereaza_ID();
  int getdep() {
    return ID_departament;
  }
  string getname() {
    return nume + " " + prenume;
  }
  int getsalariu() {
    return salariu;
  }
  int get_ID() {
    return ID;
  }
  data get_data() {
    return data_nasterii;
  }
  void set_departmentID(int depID) {
    ID_departament = depID;
  }
  void set_salariu(int sal) {
    salariu = sal;
  }
  void afisare_nume();
  friend ostream & operator << (ostream & out,
    const angajat & a);
  friend istream & operator >> (istream & in, angajat & a);

  friend void ordonare_alfabetica(vector < angajat > angajati);

};
class departament {
  string nume;
  int ID;
  vector < angajat > angajati;
  public:
    departament(string name): nume(name) {
      ID = genereaza_ID();
    }
  departament(): nume("place_holder"), ID(0) {}
  friend istream & operator >> (istream & in, departament & d);
  friend ostream & operator << (ostream & out,
    const departament & d);
  friend void afisare_departamente_salarii(vector < angajat > angajati, vector < departament > departamente);
  friend void afisare_angajati_departamente(vector < angajat > angajati, vector < departament > departamente);
  friend void muta_angajat(angajat & ang, departament & dep);
  friend void sterge_angajat(angajat & ang, vector < departament > & dep);
  friend void unire(vector < angajat > & angajati, vector < departament > & departamente);
  friend void crestere_departament(vector < angajat > & angajati, vector < departament > & dep);
  friend void scadere_departament(vector < angajat > & angajati, vector < departament > & dep);
  friend void update(angajat & a, departament & d);
  string get_nume() {
    return nume;
  }
  int get_ID() {
    return ID;
  }
  int genereaza_ID();
  void adauga_angajat(angajat & a) {
    angajati.push_back(a);
  }
  void afiseaza_angajatii();
};
ostream & operator << (ostream & out,
  const data & d) {
  out << d.zi << " " << d.luna << " " << d.an;
  return out;
}
ostream & operator << (ostream & out,
  const angajat & a) {
  out << a.nume << " " << a.prenume << " " << a.ID_departament << " " << a.data_nasterii << " " << a.salariu << endl;
  return out;
}
ostream & operator << (ostream & out,
  const departament & d) {
  fout << d.nume << endl;
}
istream & operator >> (istream & in, angajat & a) {
  string nume, prenume;
  int zi, luna, an, id_departament, salariu;
  in >> nume;
  in >> prenume;
  in >> id_departament;
  in >> zi >> luna >> an;
  in >> salariu;
  a = angajat(nume, prenume, id_departament, salariu, zi, luna, an);
  return in;
}
istream & operator >> (istream & in, departament & d) {
  string nume;
  in >> nume;
  d = departament(nume);
}
int comparare(data data_1, data data_2) {
  if (data_1.an < data_2.an) {
    return 1;
  } else {
    if (data_1.an == data_2.an) {
      if (data_1.luna < data_2.luna) {
        return 1;
      } else {
        if (data_1.luna == data_2.luna) {
          if (data_1.zi < data_2.zi) {
            return 1;
          }
        }
      }
    }
  }
  return -1;

}
void update(angajat & a, departament & d) {
  for (int i = 0; i < d.angajati.size(); i++) {
    if (d.angajati[i].get_ID() == a.get_ID()) {
      d.angajati[i] = a;
      break;
    }
  }
}
int angajat::genereaza_ID() {
  static int contor;
  contor++;
  return contor;

}
int departament::genereaza_ID() {
  static int contor;
  contor++;
  return contor;
}
void angajat::afisare_nume() {
  cout << nume << " " << prenume;

}
void departament::afiseaza_angajatii() {
  cout << nume << ":\n";
  for (int i = 0; i < angajati.size(); i++) {
    angajati[i].afisare_nume();
    cout << endl;
  }
  cout << "-------------------------------------------------------" << endl;
}
void ordonare_alfabetica(vector < angajat > angajati) {
  vector < string > nume;
  for (int i = 0; i < angajati.size(); i++) {
    nume.push_back(angajati[i].getname());
  }
  for (int i = 0; i < nume.size() - 1; i++) {
    for (int j = i + 1; j < nume.size(); j++) {
      if (nume[i] > nume[j]) {
        swap(nume[i], nume[j]);
      }
    }
  }
  for (int i = 0; i < nume.size(); i++) {
    cout << nume[i] << endl;
  }
}
void afisare_departamente(vector < departament > departamente) {
  for (int i = 0; i < departamente.size(); i++) {
    cout << departamente[i].get_nume() << endl;
  }

}
void afisare_angajati_departamente(vector < angajat > angajati, vector < departament > departamente) {
  for (int i = 0; i < angajati.size(); i++) {
    cout << angajati[i].getname() << " ";
    for (int j = 0; j < departamente.size(); j++) {
      if (departamente[j].get_ID() == angajati[i].getdep()) {
        cout << departamente[j].get_nume() << endl;
        break;
      }
    }
  }
}
void afisare_departamente_angajati(vector < departament > departamente) {
  for (int i = 0; i < departamente.size(); i++) {
    departamente[i].afiseaza_angajatii();
  }
}
void afisare_salarii(vector < angajat > angajati) {
  for (int i = 0; i < angajati.size(); i++) {
    cout << angajati[i].getname() << " " << angajati[i].getsalariu() << endl;
  }
}
void afisare_departamente_salarii(vector < angajat > angajati, vector < departament > departamente) {
  for (int i = 0; i < departamente.size(); i++) {
    for (int j = 0; j < departamente[i].angajati.size(); j++) {
      cout << departamente[i].angajati[j].getname() << " " << departamente[i].get_nume() << " " << departamente[i].angajati[j].getsalariu() << endl;
    }
    cout << endl;
  }
}
void afisare_angajati_data(vector < angajat > angajati) {
  for (int i = 0; i < angajati.size() - 1; i++) {
    for (int j = i + 1; j < angajati.size(); j++) {
      if (comparare(angajati[i].get_data(), angajati[j].get_data()) == -1) {
        swap(angajati[i], angajati[j]);
      }
    }
  }
  for (int i = 0; i < angajati.size(); i++) {
    cout << angajati[i].getname() << " " << angajati[i].get_data() << endl;
  }
}
void adauga_angajat(int & numar, vector < angajat > & angajati) {
  cout << "Introduceti numele si prenumele angajatului separate printr-un singur spatiu\n";
  string nume, prenume;
  int zi, luna, an, salariu;
  cin >> nume >> prenume;
  cout << "Introduceti data de nastere a angajatului(in format DD MM YYYY)\n";
  cin >> zi >> luna >> an;
  cout << "Introduceti valoarea salariului angajatului\n";
  cin >> salariu;
  numar++;
  angajati.resize(numar);
  angajati[numar - 1] = angajat(nume, prenume, salariu, zi, luna, an);

}
void adauga_departament(int & numar, vector < departament > & departamente) {
  cout << "Introduceti numele departamentului\n";
  string nume;
  cin >> nume;
  departamente.resize(++numar);
  departamente[numar - 1] = departament(nume);
}
void muta_angajat(angajat & ang, departament & dep) {
  ang.set_departmentID(dep.get_ID());
  dep.angajati.push_back(ang);
}
void sterge_angajat(angajat & ang, vector < departament > & dep) {
  for (int i = 0; i < dep.size(); i++) {
    if (dep[i].get_ID() == ang.getdep()) {
      for (int j = 0; j < dep[i].angajati.size(); j++) {
        if (dep[i].angajati[j].get_ID() == ang.get_ID()) {
          for (int k = j; k < dep[i].angajati.size() - 1; k++) {
            dep[i].angajati[k] = dep[i].angajati[k + 1];
          }
          dep[i].angajati.resize(dep[i].angajati.size() - 1);
          break;
        }
      }
      break;
    }
  }
}
void unire(vector < angajat > & angajati, vector < departament > & departamente) {
  cout << "Alegeti doua dintre urmatoarele departamente pentru a fi unite:\n";
  afisare_departamente(departamente);
  cout << "Scrieti numele celor doua departamente separate printr-un singur spatiu\n";
  string dep1, dep2;
  cin >> dep1 >> dep2;
  for (int i = 0; i < departamente.size(); i++) {
    if (departamente[i].get_nume() == dep1 || departamente[i].get_nume() == dep2) {
      for (int j = i + 1; j < departamente.size(); j++) {
        if (departamente[j].get_nume() == dep1 || departamente[j].get_nume() == dep2) {
          int size_1 = departamente[i].angajati.size();
          int size_2 = departamente[j].angajati.size();
          departamente[i].angajati.resize(size_1 + size_2);
          for (int k = size_1; k < size_1 + size_2; k++) {
            departamente[i].angajati[k] = departamente[j].angajati[k - size_1];
          }
          for (int k = 0; k < angajati.size(); k++) {
            if (angajati[k].getdep() == departamente[j].get_ID()) {
              angajati[k].set_departmentID(departamente[i].get_ID());
            }
          }
          for (int k = j; k < departamente.size() - 1; k++) {
            departamente[k] = departamente[k + 1];
          }
          departamente.resize(departamente.size() - 1);
          break;
        }
      }
      break;
    }
  }

}
void crestere_angajat(vector < angajat > & angajati, vector < departament > & dep) {
  cout << "Introduceti numele angajatului\n";
  string nume, prenume;
  cin >> nume >> prenume;
  nume = nume + " " + prenume;
  cout << "Introduceti cu cat vreti sa mariti salariul(adaugati % daca doriti ca schimbarea sa fie procentuala sau * daca vreti sa fie o suma fixa)\n";
  int numar;
  char modificator;
  cin >> numar >> modificator;
  if (modificator == '%') {
    float procent = float(numar) / 100 + 1;
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getname() == nume) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() * procent << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() * procent);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
        break;
      }
    }
  } else {
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getname() == nume) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() + numar << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() + numar);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
        break;
      }
    }
  }
}
void crestere_departament(vector < angajat > & angajati, vector < departament > & dep) {
  cout << "Introduceti numele departamentului\n";
  string nume;
  cin >> nume;
  int ID;
  for (int i = 0; i < dep.size(); i++) {
    if (nume == dep[i].get_nume()) {
      ID = dep[i].ID;
    }
  }
  cout << "Introduceti cu cat vreti sa mariti salariul(adaugati % daca doriti ca schimbarea sa fie procentuala sau * daca vreti sa fie o suma fixa)\n";
  int numar;
  char modificator;
  cin >> numar >> modificator;
  if (modificator == '%') {
    float procent = float(numar) / 100 + 1;
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getdep() == ID) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() * procent << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() * procent);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
      }
    }
  } else {
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getdep() == ID) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() + numar << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() + numar);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
      }
    }
  }
}
void scadere_angajat(vector < angajat > & angajati, vector < departament > & dep) {
  cout << "Introduceti numele angajatului\n";
  string nume, prenume;
  cin >> nume >> prenume;
  nume = nume + " " + prenume;
  cout << "Introduceti cu cat vreti sa micsorati salariul(adaugati % daca doriti ca schimbarea sa fie procentuala sau * daca vreti sa fie o suma fixa)\n";
  int numar;
  char modificator;
  cin >> numar >> modificator;
  if (modificator == '%') {
    float procent = 1 - float(numar) / 100;
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getname() == nume) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() * procent << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() * procent);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
        break;
      }
    }
  } else {
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getname() == nume) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() - numar << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() - numar);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
        break;
      }
    }
  }
}
void scadere_departament(vector < angajat > & angajati, vector < departament > & dep) {
  cout << "Introduceti numele departamentului\n";
  string nume;
  cin >> nume;
  int ID;
  for (int i = 0; i < dep.size(); i++) {
    if (nume == dep[i].get_nume()) {
      ID = dep[i].ID;
    }
  }
  cout << "Introduceti cu cat vreti sa micsorati salariul(adaugati % daca doriti ca schimbarea sa fie procentuala sau * daca vreti sa fie o suma fixa)\n";
  int numar;
  char modificator;
  cin >> numar >> modificator;
  if (modificator == '%') {
    float procent = 1 - float(numar) / 100;
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getdep() == ID) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() * procent << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() * procent);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
      }
    }
  } else {
    for (int i = 0; i < angajati.size(); i++) {
      if (angajati[i].getdep() == ID) {
        cout << "salariu vechi: " << angajati[i].getsalariu() << " salariu nou: " << angajati[i].getsalariu() - numar << endl;
        angajati[i].set_salariu(angajati[i].getsalariu() - numar);
        for (int j = 0; j < dep.size(); j++) {
          if (dep[j].get_ID() == angajati[i].getdep()) {
            update(angajati[i], dep[j]);
          }
        }
      }
    }
  }
}
void rescrie_fisier(int nra, vector < angajat > ang, int nrd, vector < departament > dep) {
  fout << nrd << endl;
  for (int i = 0; i < nrd; i++) {
    fout << dep[i];
  }
  fout << endl << nra << endl;
  for (int i = 0; i < nra; i++) {
    fout << ang[i];
  }
}
int main() {
  vector < angajat > lista_angajati;
  vector < departament > departamente;
  int nr_angajati, nr_departamente;
  fin >> nr_departamente;
  departamente.resize(nr_departamente);
  for (int i = 0; i < nr_departamente; i++) {
    fin >> departamente[i];
  }
  fin >> nr_angajati;
  lista_angajati.resize(nr_angajati);
  for (int i = 0; i < nr_angajati; i++) {
    fin >> lista_angajati[i];
  }
  for (int i = 0; i < nr_angajati; i++) {
    departamente[lista_angajati[i].getdep() - 1].adauga_angajat(lista_angajati[i]);
  }
  cout << "Scrieti aici keywordul pentru comenzile pe care vreti sa le efectuati. Scrieti STOP daca vreti ca programul sa se opreasca sau COMMIT daca vreti ca schimbarile efectuate sa se aplice in fisier\n";
  while (true) {
    string keyword;
    cin >> keyword;
    if (keyword == "STOP")
      break;
    else {
      if (keyword == "LIST") {
        optiuni_list: cout << "Scrie numarul corespunzator uneia dintre urmatoarele optiuni:\nDEPARTAMENTE 1 / ANGAJATI 2 / ANGAJATI + DEPARTAMENT 3 / DEPARTAMENT + ANGAJATI 4 / ANGAJATI + SALARIU 5 / ANGAJATI + DEPARTAMENT + SALARIU 6 / ANGAJATI + DATA NASTERII 7\n";
        int cod;
        cin >> cod;
        if (cod == 1)
          afisare_departamente(departamente);
        else {
          if (cod == 2)
            ordonare_alfabetica(lista_angajati);
          else {
            if (cod == 3)
              afisare_angajati_departamente(lista_angajati, departamente);
            else {
              if (cod == 4)
                afisare_departamente_angajati(departamente);
              else {
                if (cod == 5)
                  afisare_salarii(lista_angajati);
                else {
                  if (cod == 6)
                    afisare_departamente_salarii(lista_angajati, departamente);
                  else {
                    if (cod == 7) {
                      afisare_angajati_data(lista_angajati);
                    } else {
                      cout << "Optiune invalida introdusa, incercati din nou";
                      goto optiuni_list;

                    }
                  }
                }
              }
            }
          }
        }

      }
      else {
        if (keyword == "ADD") {
          cout << "Optiuni: ANGAJAT 1 / DEPARTAMENT 2\n";
          int cod;
          cin >> cod;
          if (cod == 1) {
            string departament;
            adauga_angajat(nr_angajati, lista_angajati);
            cout << "Introduceti departamentul angajatului din optiunile:\n";
            afisare_departamente(departamente);
            cin >> departament;
            for (int i = 0; i < nr_departamente; i++) {
              if (departamente[i].get_nume() == departament) {
                muta_angajat(lista_angajati[nr_angajati - 1], departamente[i]);
              }
            }
            cout << "Angajatul a fost adaugat.\n";
          } else {
            adauga_departament(nr_departamente, departamente);
            cout << "Departamentul a fost adaugat\n";

          }
        } else {
          if (keyword == "MOVE") {
            cout << "Introduceti numele angajatului\n";
            string nume_a, prenume_a, nume_d;
            cin >> nume_a >> prenume_a;
            nume_a = nume_a + " " + prenume_a;
            cout << "Introduceti numele departamentului\n";
            cin >> nume_d;
            for (int i = 0; i < nr_angajati; i++) {
              if (lista_angajati[i].getname() == nume_a) {
                sterge_angajat(lista_angajati[i], departamente);
                for (int j = 0; j < nr_departamente; j++) {
                  if (departamente[j].get_nume() == nume_d) {
                    muta_angajat(lista_angajati[i], departamente[j]);
                    break;
                  }
                }
              }
            }
            cout << "Angajatul " << nume_a << " a fost mutat la departametnul " << nume_d << "\n";
          } else {
            if (keyword == "MERGE") {
              unire(lista_angajati, departamente);
              cout << "Departamentele au fost unite.\n";
            } else {
              if (keyword == "PAYRISE") {
                cout << "Doriti sa modificati salariul pentru un angajat (tastati 1) sau pentru un intreg departament (tastati 2)?\n";
                int cod;
                cin >> cod;
                if (cod == 1) {
                  crestere_angajat(lista_angajati, departamente);
                } else {
                  crestere_departament(lista_angajati, departamente);
                }
              } else {
                if (keyword == "PAYCUT") {
                  cout << "Doriti sa modificati salariul pentru un angajat (tastati 1) sau pentru un intreg departament (tastati 2)?\n";
                  int cod;
                  cin >> cod;
                  if (cod == 1) {
                    scadere_angajat(lista_angajati, departamente);
                  } else {
                    scadere_departament(lista_angajati, departamente);
                  }
                } else {
                  if (keyword == "COMMIT") {
                    rescrie_fisier(nr_angajati, lista_angajati, nr_departamente, departamente);
                  } else {
                    cout << "Keyword invalid introdus\n";
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  return 0;
}
