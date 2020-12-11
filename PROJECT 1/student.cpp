#include <iostream>
#include "student.h"

// //****************************************************************
// //                   REQUIRED FUNCTIONALITIES
// //****************************************************************

// TODO: Implement the methods below.
// TODO: Implement the get_info methods for the relevant classes.

int Manager::add_student(std::string name, int stu_num, std::string lab_name)
{
	// check if name is only alphabet
	for (int i=0 ; i<name.length() ; i++) {
		if (!std::isalpha(name[i])) {
			std::cout << '\n' << "name should be only alphabet" << std::endl;
			return -1;
		}
	}
	// check if stu num is positive
	if (stu_num < 0) {
		std::cout << '\n' << "student number should be positive" << std::endl;
		return -1;
	}
	// check if same stu name is already exist
	for (int i=0 ; i<num_stu ; i++) {
		if (stu_num == stu_list[i]->return_stu_num()) {
			std::cout << '\n' << "student who has same student number is already exist" << std::endl;
			return -1;
		}
	}
	// check if storage is full
	if (num_stu >= Max_num_stu) {
		std::cout << '\n' << "failure (storage is full)" << std::endl;
		return -1;
 	}

	stu_list[num_stu] = new GradStudent(name, stu_num, lab_name);
	num_stu++;

	std::cout << '\n' << "successfully added (graduate student)" << std::endl;
	return num_stu;

    // TODO: Add a GradStudent object using the given arguments.
    // stu_num should be positive and unique across the student array.
    // If successful, return the total number of objects in the student array. Otherwise return -1.
};

int Manager::add_student(std::string name, int stu_num, int freshmen_class)
{
	for (int i=0 ; i<name.length() ; i++) {
		if (!std::isalpha(name[i])) {
			std::cout << '\n' << "name should be only alphabet" << std::endl;
			return -1;
		}
	}
	if (stu_num < 0) {
		std::cout << '\n' << "student number should be positive" << std::endl;
		return -1;
	}
	if (freshmen_class < 0) {
		std::cout << '\n' << "freshmen class should be positive" << std::endl;
		return -1;
	}

	for (int i=0 ; i<num_stu ; i++) {
		if (stu_num == stu_list[i]->return_stu_num()) {
			std::cout << '\n' << "student who has same student number is already exist" << std::endl;
			return -1;
		}
	}

	if (num_stu >= Max_num_stu) {
		std::cout << '\n' << "failure (storage is full)" << std::endl;
		return -1;
	}

	stu_list[num_stu] = new UndergradStudent(name, stu_num, freshmen_class);
	num_stu++;

	std::cout << '\n' << "successfully added (undergraduate student)" << std::endl;
	return num_stu;

    // TODO: Add an UndergradStudent object using the given arguments.
    // The rest of the functionality is similar to when adding a GradStudent object.
};


int Manager::delete_student(std::string name, int stu_num, std::string lab_name)
{
	for (int i=0 ; i<name.length() ; i++) {
		if (!std::isalpha(name[i])) {
			std::cout << '\n' << "name should be only alphabet" << std::endl;
			return -1;
		}
	}
	if (stu_num < 0) {
		std::cout << '\n' << "student number should be positive" << std::endl;
		return -1;
	}

	Student* target = new GradStudent(name, stu_num, lab_name);

	for (int i=0 ; i<num_stu ; i++) {
		if (*stu_list[i] == *target) {
			delete stu_list[i];
			if (i == Max_num_stu-1)
				stu_list[i] = 0;
			else {
				for (int j=i ; j<num_stu-1 ; j++)
					stu_list[j] = stu_list[j+1];
				stu_list[num_stu-1] = 0;
			}
			num_stu--;
			std::cout << '\n' << "successfully deleted (graduate student)" << std::endl;
			return num_stu;
		}
	}

	std::cout << '\n' << "failed to delete (matchced nothing)" << std::endl;
	return -1;

    // TODO: Delete the GradStudent object in the student array that matches the input arguments.
    // If the deletion is successful, return the total number of objects in the student array.
    // If there is no object that matches the arguments, return -1.
};

int Manager::delete_student(std::string name, int stu_num, int freshmen_class)
{
	for (int i=0 ; i<name.length() ; i++) {
		if (!std::isalpha(name[i])) {
			std::cout << '\n' << "name should be only alphabet" << std::endl;
			return -1;
		}
	}
	if (stu_num < 0) {
		std::cout << '\n' << "student number should be positive" << std::endl;
		return -1;
	}
	if (freshmen_class < 0) {
		std::cout << '\n' << "freshmen class should be positive" << std::endl;
		return -1;
	}

	Student* target = new UndergradStudent(name, stu_num, freshmen_class);

	for (int i=0 ; i<num_stu ; i++) {
		if (*stu_list[i] == *target) {
			delete stu_list[i];
			if (i == Max_num_stu-1) {
				stu_list[i] = 0;
			}
			else {
				for (int j=i ; j<num_stu-1 ; j++)
					stu_list[j] = stu_list[j+1];
				stu_list[num_stu-1] = 0;
			}
			num_stu--;
			std::cout << '\n' << "successfully deleted (undergraduate student)" << std::endl;
			return num_stu;
		}
	}

	std::cout << '\n' << "failed to delete (matchced nothing)" << std::endl;
	return -1;

    // TODO: Delete the UndergradStudent object in the student array that matches the input
    // arguments. The rest of the functionality is similar to when deleting a GradStudent object.
};

int Manager::sort_students(void)
{
	if (num_stu == 0) {
		std::cout << '\n' << "no student in the list" << std::endl;
		return -1;
	}
	// sorting code that I made
	for (int i=0 ; i<num_stu-1 ; i++){
		for (int j=0 ; j<num_stu-1 ; j++) {
			if (stu_list[j]->return_stu_num() > stu_list[j+1]->return_stu_num()) {
				std::swap(stu_list[j], stu_list[j+1]);
			}
		}
	}
	// check if sorting is done succefully
	for (int i=0 ; i<num_stu ; i++) {
		if (stu_list[i]->return_stu_num() > stu_list[i]->return_stu_num()) {
			std::cout << '\n' << "failed to sort" << std::endl;
			return -1;
		}
	}
	
	std::cout << '\n' << "successfully sorted" << std::endl;
	return 0;

    // TODO: Sort the Student class pointer array by stu_num in ascending order.
    // You may use any sorting library or implement your own algorithm.
    // Return 0 if the sorting is successful and -1 otherwise.
};

int Manager::find_student(std::string name, int stu_num, std::string lab_name)
{
	for (int i=0 ; i<name.length() ; i++) {
		if (!std::isalpha(name[i])) {
			std::cout << '\n' << "name should be only alphabet" << std::endl;
			return -1;
		}
	}
	if (stu_num < 0) {
		std::cout << '\n' << "student number should be positive" << std::endl;
		return -1;
	}

	Student *target;
	target = new GradStudent(name, stu_num, lab_name);

	for (int i=0 ; i<num_stu ; i++) {
		if (*stu_list[i] == *target) {
			std::cout << '\n' << "successfully found" << std::endl;
			stu_list[i]->get_info();
			return i;
		}
	}
	
	std::cout << '\n' << "failed to find" << std::endl;
	return -1;

    // TODO: Find the GradStudent object in the student array that matches the input arguments. 
    // Print the information about the matched student, if any.
    // Return the index of the matched student within the student array (an array index starts
    // from 0) or -1 if there is no match.
};

int Manager::find_student(std::string name, int stu_num, int freshmen_class)
{
	for (int i=0 ; i<name.length() ; i++) {
		if (!std::isalpha(name[i])) {
			std::cout << '\n' << "name should be only alphabet" << std::endl;
			return -1;
		}
	}
	if (stu_num < 0) {
		std::cout << '\n' << "student number should be positive" << std::endl;
		return -1;
	}
	if (freshmen_class < 0) {
		std::cout << '\n' << "freshmen class should be positive" << std::endl;
		return -1;
	}

	Student* target;
	target = new UndergradStudent(name, stu_num, freshmen_class);

	for (int i=0 ; i<num_stu ; i++) {
		if (*stu_list[i] == *target) {
			std::cout << '\n' << "successfully found" << std::endl;
			stu_list[i]->get_info();
			return i;
		}
	}

	std::cout << '\n' << "failed to find" << std::endl;
	return -1;

    // TODO: Find the UndergradStudent object in the student array that matches the input
    // arguments. The rest of the functionality is similar to when finding a GradStudent object.
};

int Manager::find_sim_students(std::string name)
{
	for (int i=0 ; i<name.length() ; i++) {
		if (!std::isalpha(name[i])) {
			std::cout << '\n' << "name should be only alphabet" << std::endl;
			return -1;
		}
	}

	int len_target = name.length();
	int result_num = 0;
	int result[num_stu];
	// if user want to find one character name	
	if (len_target == 1) {
		for (int i=0 ; i<num_stu ; i++) {
			std::string stu_name = stu_list[i]->return_name();
			int len_stu = stu_name.length();
			if (len_stu == 1) {
				if (name[0] == stu_name[0]) {	
					result[i] = 1;
					result_num++;
				}
				else
					result[i] = 0;
			}
			else
				result[i] = 0;
		}
		if (result_num > 0) {
			std::cout << '\n' << "student information of all the similar students" << std::endl;
			for (int i=0 ; i<num_stu ; i++) {
				if (result[i] == 1) {
					stu_list[i]->get_info();
				}
			}
			return result_num;
		}	
		else if (result_num == 0){
			std::cout << '\n' << "there is no similar students" << std::endl;
			return -1;
		}
	}
	// if user want to find more than one character name
	int len_array_target = 0;
	char array_target_1[len_target-1];
	char array_target_2[len_target-1];
	bool endflag_1 = 1;
	
	for (int i=0 ; i<len_target-1 ; i++) {
		for (int j=0 ; j<i ; j++) {
			if (name[i]==name[j] && name[i+1]==name[j+1]) {
				endflag_1 = 0;
			}
		}
		if (endflag_1) {
			array_target_1[len_array_target] = name[i];
			array_target_2[len_array_target] = name[i+1];
			len_array_target++;
		}
		endflag_1 = 1;
	}
	/*
	for (int i=0 ; i<len_array_target ; i++) {
		std::cout << array_target_1[i] << '\t' << array_target_2[i] << std::endl;
	}
	*/
	for (int i=0 ; i<num_stu ; i++) {
		std::string stu_name = stu_list[i]->return_name();
		int len_stu = stu_name.length();
		int len_array_stu = 0;
		char array_stu_1[len_stu-1];
		char array_stu_2[len_stu-1];
		bool endflag_2 = 1;

		for (int j=0 ; j<len_stu-1 ; j++) {
			for (int k=0 ; k<j ; k++) {
				if (stu_name[j]==stu_name[k] && stu_name[j+1]==stu_name[k+1]) {
					endflag_2 = 0;
				}
			}
			if (endflag_2) {
				array_stu_1[len_array_stu] = stu_name[j];
				array_stu_2[len_array_stu] = stu_name[j+1];
				len_array_stu++;
			}
			endflag_2 = 1;
		}
		/*
		for (int m=0 ; m<len_array_stu ; m++) {
			std::cout << array_stu_1[m] << '\t' << array_stu_2[m] << std::endl;
		}
		*/
		if (sim_test(array_target_1, array_target_2, len_array_target, array_stu_1, array_stu_2, len_array_stu) >= 0.3) {
			result[i] = 1;
			result_num++;
		}
		else
			result[i] = 0;
	}
	// print the result
	if (result_num > 0) {
		std::cout << '\n' << "student information of all the similar students" << std::endl;
		for (int i=0 ; i<num_stu ; i++) {
			if (result[i] == 1) {
				stu_list[i]->get_info();
			}
		}
		return result_num;
	}
	else if (result_num == 0){
		std::cout << '\n' << "there is no similar students" << std::endl;
		return -1;
	}



    // TODO: Find the students whose names are similar to the input name by calculating
    // the jaccard similarity of the names and comparing it with the fixed threshold 0.3.
    // Print the student information of all similar students.
    // Return the number of similar students or -1 if there is no such student.
};

int Manager::print_all()
{
	if (num_stu == 0) {
		std::cout << '\n' << "no student in the list" << std::endl;
		return -1;
	}

	for (int i=0 ; i<num_stu ; i++){
		stu_list[i]->get_info();
	}
    // TODO: Print the student information in the student array.
    // Return the total number of objects in the student array.
    return 0;
};

float Manager::sim_test(char* x_1, char* x_2, int x_len, char* y_1, char* y_2, int y_len) {
	int inter_set = 0; // intersection
	int union_set = x_len + y_len; // union

	for (int i=0 ; i<x_len ; i++) {
		for (int j=0 ; j<y_len ; j++) {
			if (x_1[i]==y_1[j] && x_2[i]==y_2[j]) {
				inter_set++;
			}
		}
	}
	union_set -= inter_set;
	//std::cout << union_set << '\t' << inter_set << std::endl;
	
	return (float)inter_set/(float)union_set;
};

// Operator overloading function. 
bool operator==(const Student& x, const Student& y)
{ 
	if (x.grad_or_undergrad != y.grad_or_undergrad) return false;
	if (x.grad_or_undergrad == Grad) {
		GradStudent* Grad_x = (GradStudent*)(&x);
		GradStudent* Grad_y = (GradStudent*)(&y);
		if (Grad_x->return_name() == Grad_y->return_name() &&
		    Grad_x->return_stu_num() == Grad_y->return_stu_num() &&
		    Grad_x->return_lab_name() == Grad_y->return_lab_name())
			return true;
		else
			return false;
	}
	else if (x.grad_or_undergrad == Undergrad) {
		UndergradStudent* Undergrad_x = (UndergradStudent*)(&x);
		UndergradStudent* Undergrad_y = (UndergradStudent*)(&y);
		if(Undergrad_x->return_name() == Undergrad_y->return_name() &&
		   Undergrad_x->return_stu_num() == Undergrad_y->return_stu_num() &&
		   Undergrad_x->return_freshmen_class() == Undergrad_y->return_freshmen_class())
			return true;
		else
			return false;
	}
	else
		return false;
    // TODO: Check whether two students x, y have the same information or not. 
    // Return true if two students are same and false otherwise.
    // This function must at least be used in the find_student() method.
};
