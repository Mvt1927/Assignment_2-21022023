#include "iostream"
#include "fstream"
#include "time.h"
using namespace std;

int charges(int numDay,int dailyRate,int medCharges,int serCharges );
int charges(int medCharges,int serCharges );
string OUTPUT_FILE_NAME = "report.txt";

int main(int argc, char const *argv[])
{
    charges(1000,1000);
    charges(5,500,1000,1000);
    return 0;
}

int charges(int numDay,int dailyRate,int medCharges,int serCharges ){

    ofstream outputFile("in_patient-"+OUTPUT_FILE_NAME);

    int totalCharges=numDay*dailyRate+medCharges+serCharges;

    outputFile<< "Type: in-patient" <<endl;
    outputFile<< "Number of days spent in the hospital: "<< numDay <<endl;
    outputFile<< "The daily rate : "<< dailyRate <<endl;
    outputFile<< "Hospital medication charges : "<< medCharges <<endl;
    outputFile<< "Charges for hospital services (lab tests, etc.) : "<< serCharges <<endl;
    outputFile<< "Total Charges : "<< totalCharges <<endl;

    outputFile.close();
    return totalCharges;
}

int charges(int medCharges,int serCharges ){
    ofstream outputFile("out_patient-"+OUTPUT_FILE_NAME);

    int totalCharges= medCharges+serCharges;

    outputFile<< "Type: out-patient" <<endl;
    outputFile<< "Hospital medication charges : "<< medCharges <<endl;
    outputFile<< "Charges for hospital services (lab tests, etc.) : "<< serCharges <<endl;
    outputFile<< "Total Charges : "<< totalCharges <<endl;

    outputFile.close();
    return totalCharges;
}