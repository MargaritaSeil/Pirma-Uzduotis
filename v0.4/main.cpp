#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include "studentas.h"
#include "lib.hpp"

int main() {
  ifstream ifStudentuFailas("studentų sąrašas.txt");
  ofstream ofStudentuFailas("studentų sąrašas.txt");
  ofstream ofVargsiukaiFailas("vargšiukai.txt");
  ofstream ofKietiakaiFailas("kietiakai.txt");

  vector <studentas> grupeStudentai;  
  vector <studentas> vargsiukai;
  vector <studentas> kietiakai;
  vector <studentas> tempGrupe;

  int nStudentai;
  int nPaz;
  
  auto start = std::chrono::high_resolution_clock::now(); // Paleisti
  auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)
 
  cout << "Įveskite studentų skaičių: " <<endl;
  cin >> nStudentai;
  
  cout<<"Kiek bus namų darbų pažymių? ";
  cin >> nPaz;

  start = std::chrono::high_resolution_clock::now();
  generateList(grupeStudentai, nStudentai, nPaz);
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų pažymių užpildymas užtruko: ";
  cout << diff.count() << "s" << endl;

  tempGrupe = grupeStudentai;
  pazSkaic(tempGrupe);
  start = std::chrono::high_resolution_clock::now();
  for (const auto &kint: tempGrupe) {
    if(kint.galutinis_paz < 5){
      vargsiukai.push_back(kint); 
    }
    else {
      kietiakai.push_back(kint);
    }
  }
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų dalijimas į dvi grupes užtruko: ";
  cout << diff.count() << "s" << endl;

  //sort lists as names
  sort(grupeStudentai.begin(), grupeStudentai.end(), compareStudents);
  sort(vargsiukai.begin(), vargsiukai.end(), compareStudents);
  sort(kietiakai.begin(), kietiakai.end(), compareStudents);

  writeGeneratedListTitle(nPaz, ofStudentuFailas);
  for(const auto &kint : grupeStudentai) { 
    writeGeneratedList(kint, ofStudentuFailas);   
  }
  ofStudentuFailas.close();
  
  start = std::chrono::high_resolution_clock::now();
  writeTitle(ofVargsiukaiFailas);
  for(const auto &kint : vargsiukai) {
    writeResults(kint, ofVargsiukaiFailas);
  }
  ofVargsiukaiFailas.close();
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout <<"vargšiukų įrašymas į failą užtruko: ";
  cout << diff.count() << "s" << endl;
  
  start = std::chrono::high_resolution_clock::now();
  writeTitle(ofKietiakaiFailas);
  for(const auto &kint : kietiakai) {
    writeResults(kint, ofKietiakaiFailas);
  }
  ofKietiakaiFailas.close();
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout <<"kietiakų įrašymas į failą užtruko: ";
  cout << diff.count() << "s" << endl;
  
  
  //ima laikies pries pradedant
  start = std::chrono::high_resolution_clock::now();
  if(ifStudentuFailas.is_open()){
    vector <studentas> tempGrupe;
    studentas temp;
    float tempPaz;
    string line;
    getline(ifStudentuFailas, line);
    while(getline(ifStudentuFailas, line)) {
      istringstream iss(line);
      iss >> temp.vardas >> temp.pavarde;
      
      while(iss >> tempPaz){
        temp.paz.push_back(tempPaz);
        temp.egz = tempPaz;
      }
			temp.paz.pop_back();
      tempGrupe.push_back(temp);
      temp.paz.clear();

    }
    ifStudentuFailas.close();
  }
  else{ cout << "neišeina atidaryti failo"; }
  //ima laiko pabaigus
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout <<"Failo iš " << nStudentai <<" studentų įrašų nuskaitymo laikas: ";
  cout << diff.count() << "s" << endl;


} 