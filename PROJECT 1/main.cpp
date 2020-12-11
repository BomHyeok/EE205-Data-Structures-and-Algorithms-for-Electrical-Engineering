#include <iostream>
#include <stdexcept>
#include <string>
#include "student.h"



// //****************************************************************
// //                   MAIN FUNCTION
// //****************************************************************

int main()
{
    char command;
    Manager manager;
    int is_grad;
    std::string name;
    int stu_num;
    std::string lab_name;
    int freshmen_class;
    int index;
    bool is_last = true;
	
    while(is_last) {
        std::cout << "\n\n\n*---------------------Welcome to Student Management" 
            << "System---------------------*" << std::endl;

        std::cout << "What do you want to do?\n - Add a student: a\n - Delete a student: d\n"
            << " - Sort the students: s\n - Find a student: f\n"
            << " - Find similar-named students: m\n - Print all student: p\n"
            << " - Quit: q" << std::endl;

        // TODO: Handle any wrong arguments here.
        std::cout << "Enter the command : " << std::endl;
        std::cin >> command;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid argument" << std::endl;
		continue;
	}
	
        switch(command) {
            case 'a': 
                std::cout << "Begin add student.\n\n"
                    << "Type\nUndergraduate: 0 Graduate: 1"<< std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> is_grad;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid argument" << std::endl;
			break;
		}
                
		if (is_grad == 1){
                    std::cout << "\nFormat: [name stu_num lab_name]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> lab_name;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid argument" << std::endl;
				break;
			}
                    manager.add_student(name, stu_num, lab_name);		  
                }

                else if (is_grad == 0){
                    std::cout << "\nFormat: [name stu_num freshmen_class] " << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> freshmen_class;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid argument" << std::endl;
				break;
			}
                    manager.add_student(name, stu_num, freshmen_class);		  
                }
		else
                    std::cout << "Invalid argument." << std::endl;
                break;

            case 'd':
                std::cout << "Begin delete student.\n\n"
                    << "Type\nUndergraduate: 0 Graduate: 1" << std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> is_grad;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid argument" << std::endl;
			break;
		}

                if (is_grad == 1){
                    std::cout << "\nFormat: [name stu_num lab_name]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> lab_name;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid argument" << std::endl;
				break;
			}
                    manager.delete_student(name, stu_num, lab_name);
                }
                else if (is_grad == 0){
                    std::cout << "\nFormat: [name stu_num freshmen_class]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> freshmen_class;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid argument" << std::endl;
				break;
			}
                    manager.delete_student(name, stu_num, freshmen_class);
                }
		else
		    std::cout << "Invalid argument." << std::endl;
                break;

            case 's':
                std::cout << "Begin sort students.\n\n" << std::endl;
                manager.sort_students();
                break;

            case 'f':
                std::cout << "Begin find student.\n\n"
                    << "Type\nUndergraduate: 0 Graduate: 1" << std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> is_grad;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid argument" << std::endl;
			break;
		}

                if (is_grad == 1){
                    std::cout << "\nFormat: [name stu_num lab_name]" << std::endl;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid argument" << std::endl;
				break;
			}

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> lab_name;
		    manager.find_student(name, stu_num, lab_name);
                }
                else if (is_grad == 0){
                    std::cout << "\nFormat: [name stu_num freshmen_class]" << std::endl;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid argument" << std::endl;
				break;
			}

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> freshmen_class;
                    manager.find_student(name, stu_num, freshmen_class);
                }
		else
		    std::cout << "Invalid argument." << std::endl;
                break;

            case 'm':
                std::cout << "Begin find similar-named students.\n\nType\n" << std::endl;
                std::cout << "Format: [name]" << std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> name;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Invalid argument" << std::endl;
			break;
		}
                manager.find_sim_students(name);
                break;

            case 'p':
                std::cout << "Begin print all." << std::endl;
                manager.print_all();
                break;

            case 'q':
                std::cout << "Quit." << std::endl;
                is_last = false;
                break;

            default:
                std::cout << "Invalid argument." << std::endl;
                break;
        }
    }
    return 0;
}

