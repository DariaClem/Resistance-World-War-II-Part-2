# Proiect2_POO

## Poveste 
În timpul celui de-al Doilea Război Mondial, în Franța ocupată de trupele germane, francezi de toate vârstele s-au unit pentru a slăbi forțele inamicului, atât prin sabotaj, cât și prin operațiuni militare.

Înainte de asedierea Parisului ai studiat criptologia și consideri că ai putea ajuta Rezistența printr-o muncă ascunsă de ochii lumii, dar crucială. Pe un dispozitiv obținut de pe Piața Neagră vrei să centralizezi informațiile despre colegi, atacuri, armament, muniție, coordonatele mesajelor sau a viitoarelor confruntări, dar vrei, de asemenea, să poți verifica autenticitatea unor mesaje primite: sunt mesaje capcane sau sunt trimise de oamenii voștri? 

> Jurnal de război

- [x] *[Prima misiune](https://github.com/DariaClem/Proiect1_POO)* 

- [ ] A doua misiune 

***28 decembrie 1942***
La finalul lunii decembrie, în apropierea Anului Nou, un membru important al Rezistenței este capturat de naziști. Întrucât acesta contribuia din „spatele cortinei”, arestarea sa devine cu atât mai suspicioasă. Cine l-ar fi putut denunța dacă nu chiar cineva din cadrul Rezistenței? 

***4 ianuarie 1943***
La scurt timp după arestarea colegului, observi că de fiecare dată când pleci de acasă ești urmărit de la distanță. De asemenea, în dimineața acestei zile ai găsit pe treptele casei tale o scrisoare care te avertizează cu privire la faptul că ești supravegheat îndeaproape de naziști. Te hotărăști să părăsești pentru o vreme capitala, pentru a scăpa de sub observația inamicului. Înainte de a porni la drum îi explici unui membru al Rezistenței felul în care se folosește dispozitivul. 


> Date tehnice

De la tastatură se vor citi, în cadrul meniului, opțiuni (int), urmate de *enter*. În funcție de alegerea făcută, utilizatorul va putea să prelucreze diferit o serie de obiecte citite anterior. Meniul este construit astfel, denumirile fiind sugestive si venind in sprijinul utilizatorului:

- Resurse Umane - Gestionar Arme 
                - Gestionar Munitie
                - Spion
                - Pagina anterioara
- Mesaje - Criptare Mesaje    - Prelucrare toate mesajele
                              - Prelucrare mesaj unic
                              - Pagina anterioara 
         - Decriptare Mesaje  - Prelucrare toate mesajele
                              - Prelucrare mesaj unic
                              - Pagina anterioara
         - Introducere Mesaj
         - Afisare Mesaje
         - Verificare Mesaje  - Verificare toate mesajele
                              - Verificare mesaj unic
                              - Pagina anterioara
         - Pagina anterioara
- Depozit - Adauga stoc arme
          - Afisare stocuri arme
          - Adauga stoc munitie
          - Afisare stocuri munitie
          - Pagina anterioara
- Inchidere dispozitiv

Meniul este construit în așa manieră încât utilizatorul să nu poată realiza acțiuni care să îi genereze erori. El este îndrumat prin diverse avertizări să urmeze ordinea firească de utilizare a acestui program.

Clasele utilizate în acest program sunt următoarele, sugerându-se de asemenea și relațiile de moștenire:
- Oameni - Gestionar Arme
         - Gestionar Munitie
         - Spion
- Coordonate
- Atacuri
- Decriptare
- Tehnica Militara - Arme
                   - Muniție
