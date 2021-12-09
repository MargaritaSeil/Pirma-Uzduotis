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
![1000 0 5](https://user-images.githubusercontent.com/90559062/142508254-af6580fd-877d-4fdc-b5c5-3efa576cf8f9.png)
![10000 0 5](https://user-images.githubusercontent.com/90559062/142508283-78e6d751-7a76-4742-8e63-4a4388694b39.png)
![100000 0 5](https://user-images.githubusercontent.com/90559062/142508308-c4906cfb-ecca-4ba8-ba6d-9ca66fc6e0fd.png)
![1000000 0 5](https://user-images.githubusercontent.com/90559062/142508328-fd2da6ad-a173-4428-8d6f-0de9a7017a26.png)
![10000000 0 5](https://user-images.githubusercontent.com/90559062/142508342-d53261f0-fa28-4fd9-8036-c6cb32c7b03a.png)

# v1.0
* Studentų rūšiavimo į dvi grupes spartos analizė trims kontainerių tipams (vector, list, deque)
* Pirma strategija (v.1.0.1):
  Studentų kontainerio rūšiavimas į du to paties tipo konteinerius (tas pats studentas yra dviejuose konteineriuose)
![1000 1 0](https://user-images.githubusercontent.com/90559062/142512099-738ab65c-0faf-4ec5-bc6d-af14d3945af5.png)
![10000 1 0](https://user-images.githubusercontent.com/90559062/142512108-ec4fb1cb-a991-497a-99a4-36fbda98cc59.png)
![100000 1 0](https://user-images.githubusercontent.com/90559062/142512110-45d417e0-24c9-4c5f-9ec8-cbc21535e948.png)
![1000000 1 0](https://user-images.githubusercontent.com/90559062/142512116-61ac306e-a219-4b80-8e7b-284369a18fd4.png)
![10000000 1 0](https://user-images.githubusercontent.com/90559062/142512124-69e9a528-0807-4cd0-8dab-d77411a506dd.png)

* Antra strategija (v.1.0.2):
  Studentų konteinerio rūšiavimas panaudojant tik vieną naują konteinerį (jei studento galutinis pažymys mažensnis nei 5, jis perkeliamas į naują konteinerį ir       ištrinamas iš bendrojo konteinerio)
![1000 1 0 2](https://user-images.githubusercontent.com/90559062/142513745-8bfa2351-ae83-423d-b812-3874b271bddf.png)
![10000 1 0 2](https://user-images.githubusercontent.com/90559062/142513756-746bdc3b-6790-49ed-afcc-f9bc21e6fe98.png)
![100000 1 0 2](https://user-images.githubusercontent.com/90559062/142513782-f01fcc50-967d-442e-8f9d-8dee17f6f916.png)
![1000000 1 0 1](https://user-images.githubusercontent.com/90559062/142513801-ed839519-1ef3-43fa-8370-9c996a9ca068.png)
![1000000 1 0 2](https://user-images.githubusercontent.com/90559062/145459369-569c10ac-d626-4ef1-834b-d39b1f3ad200.png)
  
* Antroje startegijoje panaudoti algoritmai paspartinti rūšiavimą:
1) remove_if;
2) copy_if;
3) stable_partition;
4) copy_n.

# Naudojimosi instrukcija
1) Parsisiųsti main.cpp, studentas.cpp ir studentas.h failus.
2) Paleisti per VS, Code::Blocks, aš naudojau - VSC, galima atsidarius terminalą paleisti komandą:
```
$ g++ studentas.cpp main.cpp -O3 -o myprogram
$ ./myprogram
```
