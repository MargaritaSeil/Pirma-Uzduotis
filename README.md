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
* Atlikta programos spartos analizė:
1) Failų kūrimas (kiek laiko užtruko užpildyti failą duomenimis);
2) Duomenų nuskaitymo iš failų laikas;
3) Studentų rūšiavimo į dvi grupes;
4) Surūšiuotų studentų grupių išvedimo į du naujus failus laikas.

