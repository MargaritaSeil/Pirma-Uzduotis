# Pirma-Uzduotis
# v0.1
* Sukurta strūktūra su studento vardu, pavarde, namų darbų pažymiais bei egzamino pažymiu.
* Parašyta programa leidžia vartotojui įrašyti pažymius ranka arba pasirinkti, kad pažymiai būtų automatiškai sugeneruojami.
* Tuomet pasakaičiuojamas vidurkis, mediana bei galutinis pažymys.
* Galiausiai duomenys išvedami į lentelę.

# v0.2
* Naudojamas v0.1 versijos 'vektorius'.
* Šioje versijoje vartotojas gali pasirinkti ar duomenis įrašyti ranka/sugeneruoti duomenis (iš v0.1), ar kad jie būtų nuskaityti iš failo.
* Kaip ir v0.1 suskaičiuojamas vidurkis, mediana, galutinis pažymys.
* Sudaroma lentelė ir išvedama faile: 'rez.txt'.

# v0.3
* Šiai versijai naudojama v0.2 versija.
* Struktūra bei funckijos perkeltos į antraštinius failus:
1) 'Studentas' struktūra perkelta į 'studentas.h' failą.
2) Skaičiavimo funkcijų deklaravimas perkeltas į 'math.h' bei jų realizavimas į 'math.cpp'.
3) Atitinkamai išvedimo funkcijos perkeltos į 'output.h' bei 'output.cpp'.
* Panaudotas išimčių valdymas (try-catch), klausiant studentų skaičiaus.

# v0.4
* Sugeneruojamas n studentų sąrašas (vardas, pavardė, nd pažymiai bei egzamino pažymys) ir išvedami į failą.
* Šie studentai surūšiuojami i dvi grupes:
1) 'kietiakai', kurių galutinis pažymys yra >=5;
2) 'vargšiukai', kurių galutinis pažymys yra <5.
* surūšiuoti studentai išvedami į atitinkamus failus: 'kietiakai.txt' ir 'vargšiukai.txt'.
* Atlikta programos veikimo spartos analizė:
1) Failų kūrimas (kiek laiko užtruko užpildyti failą duomenimis);
2) Duomenų nuskaitymo iš failų laikas;
3) Studentų rūšiavimo į dvi grupes;
4) Surūšiuotų studentų grupių išvedimo į du naujus failus laikas.
* Testvimas atliktas su 10 pažymių:
![1000 0 4](https://user-images.githubusercontent.com/90559062/142260168-e29624ad-4af7-4536-a4d7-f61f9181aeee.png)
![10000 0 4](https://user-images.githubusercontent.com/90559062/142260197-6bab88ef-15d9-479a-88ec-e2d054730a3c.png)
![100000 0 4](https://user-images.githubusercontent.com/90559062/142260250-28619aad-3e43-461f-9f9d-de0fadf2b3fb.png)
![1000000 0 4](https://user-images.githubusercontent.com/90559062/142260716-a1b739d3-1473-4a46-8711-fa21cfdba9c7.png)
![10000000 0 4](https://user-images.githubusercontent.com/90559062/142260337-0b10891a-ae86-4724-9fe0-a24eb5022d1d.png)

# v0.5
* Konteinerių testavimas;
* Atlikta programos veikimo spartos analizė:
1) Duomenų nuskaitymo iš failų laikas;
2) Studentų rūšiavimo į dvi grupes;
* Šioje versijoje naudota 'list', lyginama su v0.4 'vector'.
* Testavimo sistemos parametrai: CPU: Intel® Core™ i3-6006U CPU @ 2.00GHz × 4, RAM: ~4GB, HDD: 128 GB.
* Testvimas atliktas su 10 pažymių:
(https://user-images.githubusercontent.com/90559062/148956395-c531295a-ece8-4e0c-bd15-dc366d2b89b0.png)
