#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <vector>
#include <list>
#include <deque>
#include "studentas.h"
#include "lib.hpp"

int main() {
  ifstream ifStudentuFailas("studentų sąrašas.txt");
  ofstream ofStudentuFailas("studentų sąrašas.txt");
  ofstream ofVargsiukaiFailas("vargšiukai.txt");
  ofstream ofKietiakaiFailas("kietiakai.txt");

  list<studentas> grupeStudentaiList;  
  list<studentas> vargsiukaiList;
  list<studentas> kietiakaiList;

  vector<studentas> grupeStudentaiVector;
  vector<studentas> vargsiukaiVector;
  vector<studentas> kietiakaiVector;

  deque<studentas> grupeStudentaiDeque;  
  deque<studentas> vargsiukaiDeque;
  deque<studentas> kietiakaiDeque;

  int nStudentai;
  int nPaz;
  
  auto start = std::chrono::high_resolution_clock::now(); // Paleisti
  auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)
 
  cout << std::fixed;
  cout << "Įveskite studentų skaičių: " <<endl;
  cin >> nStudentai;
  
  cout<<"Kiek bus namų darbų pažymių? ";
  cin >> nPaz;

  generateList(grupeStudentaiList, nStudentai, nPaz);
  writeGeneratedListTitle(nPaz, ofStudentuFailas);
  for(const auto &kint : grupeStudentaiList) { 
    writeGeneratedList(kint, ofStudentuFailas);   
  }
  grupeStudentaiList.clear();
  ofStudentuFailas.close();
  
  readFile(ifStudentuFailas, grupeStudentaiList);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiList);
  start = std::chrono::high_resolution_clock::now();
  for (const auto &kint: grupeStudentaiList) {
    if(kint.galutinis_paz < 5){
      vargsiukaiList.push_back(kint); 
    }
    else {
      kietiakaiList.push_back(kint);
    }
  }
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų dalijimas į dvi grupes užtruko naudojant list: ";
  cout << diff.count() << "s" << endl;
  
  grupeStudentaiList.sort(compareNames);
  vargsiukaiList.sort(compareNames);
  kietiakaiList.sort(compareNames);
  
  writeTitle(ofVargsiukaiFailas);
  for(const auto &kint : vargsiukaiList) {
    writeResults(kint, ofVargsiukaiFailas);
  }
  ofVargsiukaiFailas.close();
  
  writeTitle(ofKietiakaiFailas);
  for(const auto &kint : kietiakaiList) {
    writeResults(kint, ofKietiakaiFailas);
  }
  ofKietiakaiFailas.close();

  grupeStudentaiList.clear();
  vargsiukaiList.clear();
  kietiakaiList.clear();
  
  ifStudentuFailas.open("studentų sąrašas.txt");
  readFile(ifStudentuFailas, grupeStudentaiVector);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiVector);
  start = std::chrono::high_resolution_clock::now();
  for (const auto &kint: grupeStudentaiVector) {
    if(kint.galutinis_paz < 5){
      vargsiukaiVector.push_back(kint); 
    }
    else {
      kietiakaiVector.push_back(kint);
    }
  }
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų dalijimas į dvi grupes užtruko naudojant vector: ";
  cout << diff.count() << "s" << endl;

  grupeStudentaiVector.clear();
  vargsiukaiVector.clear();
  kietiakaiVector.clear();

  grupeStudentaiVector.shrink_to_fit();
  vargsiukaiVector.shrink_to_fit();
  kietiakaiVector.shrink_to_fit();

  ifStudentuFailas.open("studentų sąrašas.txt");
  readFile(ifStudentuFailas, grupeStudentaiDeque);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiDeque);
  start = std::chrono::high_resolution_clock::now();
  for (const auto &kint: grupeStudentaiDeque) {
    if(kint.galutinis_paz < 5){
      vargsiukaiDeque.push_back(kint); 
    }
    else {
      kietiakaiDeque.push_back(kint);
    }
  }
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų dalijimas į dvi grupes užtruko naudojant deque: ";
  cout << diff.count() << "s" << endl;

  grupeStudentaiDeque.clear();
  vargsiukaiDeque.clear();
  kietiakaiDeque.clear();  

  grupeStudentaiDeque.shrink_to_fit();
  vargsiukaiDeque.shrink_to_fit();
  kietiakaiDeque.shrink_to_fit();
} 
