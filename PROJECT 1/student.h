// //***************************************************************
// //                         CLASSES
// //****************************************************************

#define Grad 1
#define Undergrad 2
#define Max_num_stu 300

// I changed the order from skeleton code
class Student {
    // TODO: Define the member variables.
    private:
    protected:
	    std::string name;
	    int stu_num;
	    int grad_or_undergrad;
    public:
	    Student(std::string name_temp, int stu_num_temp) {
		    name = name_temp;
		    stu_num = stu_num_temp;
		    grad_or_undergrad = 0;
	    }
	    int return_stu_num() {
		    return stu_num;
	    }
	    std::string return_name() {
		    return name;
	    }
	    friend bool operator==(const Student&, const Student &);
	    virtual void get_info() = 0;
        // TODO: Declare get_info() as a pure virtual function.
};

class GradStudent: public Student {
    // TODO: Define the member variables.
    private:
	    std::string lab_name;
    protected:
    public:	
	    GradStudent(std::string name, int stu_num, std::string lab_name_temp)
	    : Student(name, stu_num) {
		    lab_name = lab_name_temp;
		    grad_or_undergrad = Grad;
	    }
	    std::string return_lab_name() {
		    return lab_name;
	    }
	    virtual void get_info() {
		    std::cout<<name<<'\t'<<stu_num<<'\t'<<lab_name<<std::endl;
	    }
        // TODO: Declare get_info().
};

class UndergradStudent: public Student {
    // TODO: Define the member variables.
    private:
	    int freshmen_class;
    protected:
    public:
	    UndergradStudent(std::string name, int stu_num, int freshmen_class_temp)
	    : Student(name, stu_num) {
		   freshmen_class = freshmen_class_temp;
		   grad_or_undergrad = Undergrad;
	    }
	    int return_freshmen_class() {
		    return freshmen_class;
	    }
	    virtual void get_info() {
		    std::cout<<name<<'\t'<<stu_num<<'\t'<<freshmen_class<<std::endl;
	    }
        // TODO: Declare get_info().
};

class Manager {
    // TODO: Define the member variables.
    private:
	    Student* stu_list[Max_num_stu];
	    int num_stu;
    protected:
    public:
	// reset number of student to zero
	Manager() : num_stu(0)
	{}
        // Adds a student object in the student array.
        int add_student(std::string name, int stu_num, std::string lab_name);
        int add_student(std::string name, int stu_num, int freshmen_class);

        // Deletes a student object from the student array.
        int delete_student(std::string name, int stu_num, std::string lab_name);
        int delete_student(std::string name, int stu_num, int freshmen_class);

        // Sorts the students by stu_num.
        int sort_students(void);

        // Finds a student in the student array.
        int find_student(std::string name, int stu_num, std::string lab_name);
        int find_student(std::string name, int stu_num, int freshmen_class);

        // Finds students with similar names.
        int find_sim_students(std::string name);

	// Jaccard similarity test that I made
	float sim_test(char* x_1, char* x_2, int x_len, char* y_1, char* y_2, int y_len);

        // Prints the information of students.
        int print_all();
};
