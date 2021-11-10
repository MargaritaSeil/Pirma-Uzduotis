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
![1000 v0 4](https://user-images.githubusercontent.com/90559062/141158673-bc82a59c-fc3f-43c3-94c9-8aa1af9b48ae.png)
![10000 v0 4](https://user-images.githubusercontent.com/90559062/141158697-3363f676-ffec-4dd2-97c5-79d4d5489657.png)
![100000 v0 4](https://user-images.githubusercontent.com/90559062/141158733-d5cc554b-b2ea-4116-a194-c10354ae7e06.png)
![1000000 v0 4](https://user-images.githubusercontent.com/90559062/141158760-c6d65559-97da-4870-b6af-65622ddd8b52.png)


