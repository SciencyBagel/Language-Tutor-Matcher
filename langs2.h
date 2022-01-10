//Jahir Montes 1001635994
#ifndef _LANGS_
#define _LANGS_

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>



enum days { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

class Person
{
public:

	std::string name;
	std::string gender;					
	std::string start_date; //start_date of learning for student and start_date of teaching for tutor
	int days[7];					//available days (0 is unavailable, 1 is available)
	
};

class Student : public Person
{
/*TODO:

	Continuously read in files of people looking for language tutors until exit is signaled
	-User continuously adds file names to read from
	-Format:

		Paulie Glott		//Full name	of the language learner
		Gender: Female	    //Desired gender of the	tutor
		Language: Dinka	    //Target anguage
		Start: 08/6/2016	//Date learner started learning the	language
		Max: $4.25			//Max amount willing to	pay	per	hour
		Sunday:	x			//x means	available,	- means	not	available
		Monday:	-
		Tuesday: x
		Wednesday: -
		Thurday: x
		Friday: x
		Saturday: -
*/
public:
	std::string language;			//target language
	double max_rate = 0;					//max amount willing to pay per hour
};


class Tutor : public Person
{
public:
	std::vector<Student> tutor_students;
	std::vector<std::string> languages;				//languages available to tutor
	int max_students = 0;							//max number of learners at any given time
	double rate = 0;								//Amount charged per hour
};

class Language_Company
{
	void read_file(std::string file_name, std::vector<Student>& students);
	void read_file(std::string file_name, std::vector<Tutor>& tutors);
	void register_tutor();
	void match();
	void get_rid();

	/*Containers*/
	std::vector<Student> students;
	std::vector<Tutor> tutors;
	/*---------*/
public:
	Language_Company();
	~Language_Company(); //save all registered tutors on file, clear their student info

	void menu();
};



#endif
