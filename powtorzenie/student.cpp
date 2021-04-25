#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>


struct Student{
	std::string firstName;
	std::string lastName;
	int index;
	int semester;
	double average;
	
	Student(std::string firstName, std::string lastName, int index, int semester, double average);
	std::string toString();
	
};
Student::Student(std::string fn, std::string ln, int ind, int sem, double avg){
		firstName = fn;
		lastName = ln;
		index = ind;
		semester = sem;
		average = avg;
}

auto main() -> int{
	auto student = Student("Mikolaj", "Noga", 21475, 4, 5.0);
	std::cout << student.toString();
	
	return 0;
}

std::string Student::toString(){
	
    std::string index_str = std::to_string(index);
	std::string semester_str = std::to_string(semester);
	std::string srednia_str = std::to_string(average);
	
	return "Hello " + firstName + " " + lastName + ".\nYour index: " + index_str +
	".\nYou are on " + semester_str + " semester.\n" + "Your average grades: " + srednia_str + ".\n";
}