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

  vector<studentas> grupeStudentaiVector;
  vector<studentas> vargsiukaiVector;

  deque<studentas> grupeStudentaiDeque;  
  deque<studentas> vargsiukaiDeque;

  int nStudentai;
  int nPaz;
  
  auto start = std::chrono::high_resolution_clock::now(); // Paleisti
  auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)

  auto titList = grupeStudentaiList.begin();
  auto titVector = grupeStudentaiVector.begin();
  auto titDeque = grupeStudentaiDeque.begin();

  cout << std::fixed;
  cout << "Įveskite studentų skaičių: " <<endl;
  cin >> nStudentai;
  
  cout<<"Kiek bus namų darbų pažymių? ";
  cin >> nPaz;
  
  grupeStudentaiVector.reserve(nStudentai);
  generateList(grupeStudentaiVector, nStudentai, nPaz);
  sort(grupeStudentaiVector.begin(), grupeStudentaiVector.end(), compareNames);
  writeGeneratedListTitle(nPaz, ofStudentuFailas);
  for(const auto &kint : grupeStudentaiVector) { 
    writeGeneratedList(kint, ofStudentuFailas);   
  }
  ofStudentuFailas.close();
  grupeStudentaiVector.clear();
  grupeStudentaiVector.shrink_to_fit();

  //-----------------LIST------------------------//
  readFile(ifStudentuFailas, grupeStudentaiList);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiList);

  start = std::chrono::high_resolution_clock::now();
  titList = grupeStudentaiList.begin();
  while (titList != grupeStudentaiList.end()){
    if(isLowGrade(*titList)){
      vargsiukaiList.push_back(*titList);
      titList = grupeStudentaiList.erase(titList);
    }
    else {
      ++titList;
    } 
  }
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų dalijimas į dvi grupes užtruko naudojant list: ";
  cout << diff.count() << "s" << endl;
  
  vargsiukaiList.sort(compareNames);
  grupeStudentaiList.sort(compareNames);
  
  writeTitle(ofVargsiukaiFailas);
  for(const auto &kint : vargsiukaiList) {
    writeResults(kint, ofVargsiukaiFailas);
  }
  ofVargsiukaiFailas.close();
  
  writeTitle(ofKietiakaiFailas);
  for(const auto &kint : grupeStudentaiList) {
    writeResults(kint, ofKietiakaiFailas);
  }
  ofKietiakaiFailas.close();
  
  grupeStudentaiList.clear();
  vargsiukaiList.clear();

  //-------------DEQUE----------------//
  ifStudentuFailas.open("studentų sąrašas.txt");
  readFile(ifStudentuFailas, grupeStudentaiDeque);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiDeque);
  start = std::chrono::high_resolution_clock::now();

  copy_if(
    grupeStudentaiDeque.begin(),
    grupeStudentaiDeque.end(),
    std::back_inserter(vargsiukaiDeque),
    isLowGrade);
    
  titDeque = remove_if(grupeStudentaiDeque.begin(), grupeStudentaiDeque.end(), isLowGrade);
  grupeStudentaiDeque.erase(titDeque, grupeStudentaiDeque.end());

  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų dalijimas į dvi grupes užtruko naudojant deque: ";
  cout << diff.count() << "s" << endl;

  grupeStudentaiDeque.clear();
  vargsiukaiDeque.clear(); 

  grupeStudentaiDeque.shrink_to_fit();
  vargsiukaiDeque.shrink_to_fit();

/*
  //-----------------VECTOR--------------//
  ifStudentuFailas.open("studentų sąrašas.txt");
  readFile(ifStudentuFailas, grupeStudentaiVector);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiVector);
  start = std::chrono::high_resolution_clock::now();
  titVector = grupeStudentaiVector.begin();
  while (titVector != grupeStudentaiVector.end()){
    if(isLowGrade(*titVector)){
      vargsiukaiList.push_back(*titVector);
      titVector = grupeStudentaiVector.erase(titVector);
    }
    else {
      ++titVector;
    } 
  }
  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai <<" studentų dalijimas į dvi grupes užtruko naudojant vector: ";
  cout << diff.count() << "s" << endl;

  grupeStudentaiVector.clear();
  vargsiukaiVector.clear();

  grupeStudentaiVector.shrink_to_fit();
  vargsiukaiVector.shrink_to_fit();
*/

  //---------VECTOR (copy_if, remove_if)----------//
  ifStudentuFailas.open("studentų sąrašas.txt");
  readFile(ifStudentuFailas, grupeStudentaiVector);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiVector);
  
  start = std::chrono::high_resolution_clock::now();

  copy_if(
    grupeStudentaiVector.begin(),
    grupeStudentaiVector.end(),
    std::back_inserter(vargsiukaiVector),
    isLowGrade);
    
  titVector = remove_if(grupeStudentaiVector.begin(), grupeStudentaiVector.end(), isLowGrade);
  grupeStudentaiVector.erase(titVector, grupeStudentaiVector.end());

  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai << " studentų dalijimas į dvi grupes užtruko naudojant vector" <<endl;
  cout << "(remove_if ir copy_if): ";
  cout << diff.count() << "s" << endl;

  grupeStudentaiVector.clear();
  vargsiukaiVector.clear();

  grupeStudentaiVector.shrink_to_fit();
  vargsiukaiVector.shrink_to_fit();

  //--------------VECTOR (stable_partition--------------/
  ifStudentuFailas.open("studentų sąrašas.txt");
  readFile(ifStudentuFailas, grupeStudentaiVector);
  ifStudentuFailas.close();

  pazSkaic(grupeStudentaiVector);

  start = std::chrono::high_resolution_clock::now();

  titVector = stable_partition(grupeStudentaiVector.begin(), grupeStudentaiVector.end(), isLowGrade);

  copy_n(
    grupeStudentaiVector.begin(),
    std::distance(grupeStudentaiVector.begin(), titVector),
    std::back_inserter(vargsiukaiVector));
  
  grupeStudentaiVector.erase(grupeStudentaiVector.begin(), titVector);

  end = std::chrono::high_resolution_clock::now();
  diff = end-start;
  cout << nStudentai << " studentų dalijimas į dvi grupes užtruko naudojant vector" <<endl;
  cout << "(stable_partition): ";
  cout << diff.count() << "s" << endl;
  
  grupeStudentaiVector.clear();
  vargsiukaiVector.clear();

  grupeStudentaiVector.shrink_to_fit();
  vargsiukaiVector.shrink_to_fit();
} 
