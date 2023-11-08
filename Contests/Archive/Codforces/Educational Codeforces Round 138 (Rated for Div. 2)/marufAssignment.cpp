#include <iostream>
#include <string.h>

using namespace std;
	
struct VaccinePerson{
	string nid;
	string name;
	int age;
	string phoneNumber;
	string regNumber;
	string vaccineName;
	string centerName;
	string dateOfFirstDose, dateOfSecondDose, dateOfBoosterDose;

	static void indentifyCenter(VaccinePerson persons[], int size){
		cout<<"List of persons whose center is at DMC: "<<endl;
		for(int i = 0; i<size; i++){
			if(persons[i].centerName == "DMC"){
				cout<<persons[i].name<<endl;
			}
		}
	}

};

int main(){
	VaccinePerson p1;
	p1.nid = "x12121";
	p1.name = "Raju";
	p1.age = 21;
	p1.phoneNumber = "017112222";
	p1.regNumber  = "121222132";
	p1.vaccineName = "Phizer";
	p1.centerName = "DMC";
	p1.dateOfFirstDose = "29/10/22";

	VaccinePerson p2;
	p2.nid = "x13151";
	p2.name = "Montu";
	p2.age = 20;
	p2.phoneNumber = "01711xxxx";
	p2.regNumber  = "126545132";
	p2.vaccineName = "Phizer";
	p2.centerName = "DMC";
	p2.dateOfFirstDose = "29/10/22";

	VaccinePerson arr[2] = {p1, p2};

	VaccinePerson::indentifyCenter(arr, 2);

	return 0;
}