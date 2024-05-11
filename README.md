# Administrator Resurse Umane pentru o Companie
Programul urmator poate administra angajații si departamentele în cadrul unei companii utilizând principiile progrămarii orientate pe obiecte. Acesta citește datele cu care lucrează din fișierul date_companie.txt și poate genera un set de date modificate în fișierul output.txt. Programul oferă acum și posibilitatea adăugării unor contractori, angajați care lucrează doar temporar pentru firmă și care nu au un salariu propriu-zis ci doar un comision. Aceștia lucrează în cadrul unor proiecte, echivalentele departamentelor pentru angajații permanenți.
Programul poate fi rulat din terminalul oricărui IDE de C++ și dispune de diverse funcționalități ce pot fi activate prin scrierea unuia dintre următoarele keyworduri:
1. LIST - permite utilizatorului să vizualizeze mai multe liste din cadrul bazei de date a programului (spre exemplu lista angajaților, a departamentelor, etc.)
2. MOVE - mută un angajat dintr-un departament în altul
3. ADD - adaugă un angajat sau un departament
4. MERGE - mută toți angajații din al doilea departament indicat în primul, ștergându-l apoi pe al doilea
5. PAYRISE - mărește salariul pentru un angajat permanent / un departament
6. PAYCUT - taie salariul pentru un angajat permanent / un departament
7. COMMIT - salvează schimbările făcute in baza de date într-un alt fișier (output.txt)
8. STOP - oprește execuția programului
9. CHANGEID - îi oferă posibilitatea administratorului să schimbe ID-ul oricărui angajat la alegere (dacă ID-ul este deja folosit de un alt angajat acest lucru nu va mai fi posibil iar toate ID-urile vor fi resetate de către program).

Mai multe informații despre funcționalitate sunt transmise user-ului prin terminal după ce acesta tastează keyword-ul și apasă enter. Parametrii funcțiilor vor fi deasemenea ceruți de către program după ce user-ul inserează keyword-ul (atenție! programul este case sensitive deci trebuie scrise cu caps lock ca în lista de exemple). 
