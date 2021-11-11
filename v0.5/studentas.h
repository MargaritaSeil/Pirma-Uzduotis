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

//HERE GOES STUFF
struct studentas{
    std::string vardas, pavarde;
    std::vector <float> paz;
    double med;
    float egz;
    float galutinis_paz;
};

// this function generates the student list.

void writeTitle(std::ofstream &file);
void writeResults(studentas, std::ofstream &file);
void writeGeneratedListTitle(int nPaz, std::ofstream &file);
void writeGeneratedList(studentas, std::ofstream &file);
void generateList(std::list<studentas> &grupe, int nStudentai, int nPaz);
void pazSkaic(std::list<studentas> &grupe);
int randomNumber();
double median(std::vector<float> &vec);
bool compareStudents(studentas a, studentas b);

#endif     
