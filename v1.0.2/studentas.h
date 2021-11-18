#ifndef STUDENTAS_H    
#define STUDENTAS_H    

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <list>
#include <deque>


struct studentas{
    std::string vardas, pavarde;
    std::vector <float> paz;
    float egz;
    float galutinis_paz;
};

void writeTitle(std::ofstream &file);
void writeResults(studentas kint, std::ofstream &file);
void writeGeneratedListTitle(int nPaz, std::ofstream &file);
void writeGeneratedList(studentas kint, std::ofstream &file);

void readFile(std::ifstream &file, std::list<studentas> &grupe);
void readFile(std::ifstream &file, std::vector<studentas> &grupe);
void readFile(std::ifstream &file, std::deque<studentas> &grupe);

void generateList(std::vector<studentas> &grupe, int nStudentai, int nPaz);

void pazSkaic(std::list<studentas> &grupe);
void pazSkaic(std::vector<studentas> &grupe);
void pazSkaic(std::deque<studentas> &grupe);

int randomNumber();
bool compareNames(studentas a, studentas b);
bool isLowGrade(studentas kint);

#endif     