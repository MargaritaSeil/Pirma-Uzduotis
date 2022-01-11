#ifndef STUDENTAS_H     //make sure not already exist
#define STUDENTAS_H     //define

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
    double med;
    float egz;
    float galutinis_paz;
};

// this function generates the student list.

void writeTitle(std::ofstream &file);
void writeResults(studentas, std::ofstream &file);
void writeGeneratedListTitle(int nPaz, std::ofstream &file);
void writeGeneratedList(studentas, std::ofstream &file);

void readFile(std::ifstream &file, std::list<studentas> &grupe);
void readFile(std::ifstream &file, std::vector<studentas> &grupe);
void readFile(std::ifstream &file, std::deque<studentas> &grupe);

void generateList(std::list<studentas> &grupe, int nStudentai, int nPaz);

void pazSkaic(std::list<studentas> &grupe);
void pazSkaic(std::vector<studentas> &grupe);
void pazSkaic(std::deque<studentas> &grupe);

int randomNumber();
double median(std::vector<float> &vec);
bool compareNames(studentas a, studentas b);

#endif     