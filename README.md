# Pirma-Uzduotis
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
  
* Antroje startegijoje panaudoti algoritmai paspartinti rūšiavimą:
1) remove_if;
2) copy_if;
3) stable_partition;
4) copy_n.
