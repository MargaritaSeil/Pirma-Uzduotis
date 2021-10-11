#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>	
#include "lib.hpp"

struct studentas{
    string vardas, pavarde;
    vector <float> paz;
    double med;
    float egz;
    float galutinis_paz;
};

int random_grade();
void names();
void print(studentas);
double median(vector<float> &vec);
bool compareStudents(studentas a, studentas b){
	return a.vardas.compare(b.vardas) < 0;
}

int main() {
    vector <studentas> grupe;
    studentas temp; ///laikinas kintamasis
    int n; ///studentu sk
    float sum=0, laik, vid, med; //laik - laikinas kintamamsis ivesciai
    string strAuto;			//changed from str_auto
    srand(time(NULL));
    string strLoad;
    string line;
    ifstream readFile("studentai10000.txt");
    ofstream writeFile("rez.txt");
    
    cout << "Ar skaityti iš failo? (t/n) ";
    cin >> strLoad;
    if(strLoad == "t"){
	    if(readFile.is_open()){
		    float nd1, nd2, nd3, nd4, nd5;
		    float nd6, nd7, nd8, nd9, nd10;
		    float nd11, nd12, nd13, nd14, nd15;
		    getline(readFile, line); //ignoruoja pirma eilute
		    while(getline(readFile, line)){
			    istringstream iss(line);
			    iss >> temp.vardas >> temp.pavarde
			    >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 
                >> nd6 >> nd7 >> nd8 >> nd9 >> nd10
                >> nd11 >> nd12 >> nd13 >> nd14 >> nd15
			    >> temp.egz;
			    temp.paz.push_back(nd1);
			    temp.paz.push_back(nd2);
			    temp.paz.push_back(nd3);
			    temp.paz.push_back(nd4);
			    temp.paz.push_back(nd5);
			    temp.paz.push_back(nd6);
			    temp.paz.push_back(nd7);
			    temp.paz.push_back(nd8);
			    temp.paz.push_back(nd9);
			    temp.paz.push_back(nd10);
			    temp.paz.push_back(nd11);
			    temp.paz.push_back(nd12);
			    temp.paz.push_back(nd13);
			    temp.paz.push_back(nd14);
			    temp.paz.push_back(nd15);
			    n++;
            
                vid=accumulate(temp.paz.begin(), temp.paz.end(), 0.0) / temp.paz.size();
                temp.med=median(temp.paz);
                temp.galutinis_paz=0.4*vid+0.6*temp.egz;
                grupe.push_back(temp);
                temp.paz.clear();
		    }
            readFile.close();
	    }
	    else{ cout << "neišeina atidaryti failo"; }
    }
    else {
        cout << "Įveskite studentų skaičių: " <<endl;
        cin >> n;
        grupe.reserve(n);
        for (int i=0; i<n; i++){
            cout<<"Įveskite "<<i+1<<"-o studento vardą: ";
            cin>>temp.vardas;
            cout<<"Įveskite "<<i+1<<"-o studento pavardę: ";
            cin>>temp.pavarde;
            sum=0;
            cout<<"Ar įvesti pažymius automatiškai? (t/n) ";
            cin>>strAuto;
            if(strAuto == "t") {
                int k;
                float random;
                cout<<"Kiek bus pažymių? ";
                cin>>k;
                for(int j=0; j<k; j++) {
                    random = (float) random_grade();
                    temp.paz.push_back(random);
                    sum+= random;
                }
                random = (float) random_grade();
                temp.egz = random;
            }
            else {
                cout<<"Įveskite "<<i+1<<"-o studento pažymius (1-10), baigę, įveskite simbolį, kuris nėra skaičius: ";
                while(cin>>laik) {
                    temp.paz.push_back(laik);
                    sum+= laik; ///kol nesibaigs ciklas, bus sumuojami pazymiai
                }
                cin.clear(); ///ignoruoti bloga ivesti
                cin.ignore(10000, '\n'); ///ingoruoti paskutini ivesta n
                cout<<"Įveskite "<<i+1<<"-o studento egzamino pažymį(1-10): ";
                cin>>temp.egz;
            }
            vid=accumulate(temp.paz.begin(), temp.paz.end(), 0.0) / temp.paz.size(); 
            temp.med=median(temp.paz);
            temp.galutinis_paz=0.4*vid+0.6*temp.egz;
            grupe.push_back(temp);
            temp.paz.clear();
        }
    }
    sort(grupe.begin(), grupe.end(), compareStudents);
    names();
    if(writeFile.is_open()){
        writeFile<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"<<setw(15)<<left<<"Galutinis(vid.)"<<setw(15)<<left<<" / Galutinis(med.)"
        <<"\n---------------------------------------------------------------------\n";
    }
    else {
        cout << "negalima įrašyti. ";
    }
    for (const auto &kint: grupe) {
        print(kint);
        if(writeFile.is_open()) {
 		writeFile<<setw(15)<<kint.vardas<<setw(15)<<kint.pavarde;
        writeFile<<setw(16)<<setprecision(3)<<kint.galutinis_paz<<setw(15)<<kint.med<<endl;
        }
        else {
            cout << "negalima įrašyti." ;
        }
    }
    writeFile.close();		
}
void names () {
  cout<<"\n";
  cout<<setw(15)<<left<<"Vardas"
  <<setw(15)<<left<<"Pavarde"<<setw(15)<<left<<"Galutinis(vid.)"<<setw(15)<<left<<" / Galutinis(med.)"
  <<"\n---------------------------------------------------------------------------------------\n";
}

void print(studentas kint) {
  cout<<setw(15)<<kint.vardas<<setw(15)<<kint.pavarde;
  cout<<setw(16)<<setprecision(3)<<kint.galutinis_paz<<setw(15)<<kint.med<<endl;
}

double median(vector<float> &vec) {
  typedef vector<float>::size_type vecSize;
  vecSize size = vec.size();
  if (size == 0) ///tikrinam ar vektorius nera tuscias
  throw domain_error("negalima skaičiuoti medianos tuščiam vekotoriui");
  sort(vec.begin(), vec.end()); ///surusiuojam elementus didejimo tvarka
  vecSize vid = size/2; ///randamas vidurkis
  return size%2==0 ? (vec[vid] + vec[vid]) / 2 : vec[vid];
}

int random_grade() //sugeneruoja random skaiciu nuo 1 iki 10
{
    return rand() % 10 + 1;
}
