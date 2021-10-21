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

struct studentas{
    std::string vardas, pavarde;
    std::vector <float> paz;
    double med;
    float egz;
    float galutinis_paz;
};

void writeTitle(std::ofstream &file);
void writeResults(studentas, std::ofstream &file);
void writeGeneratedListTitle(int nPaz, std::ofstream &file);
void writeGeneratedList(studentas, std::ofstream &file);

void generateList(std::vector<studentas> &grupe, int nStudentai, int nPaz);
void pazSkaic(std::vector<studentas> &grupe);
int randomNumber();
double median(std::vector<float> &vec);
bool compareStudents(studentas a, studentas b);

#endif     
