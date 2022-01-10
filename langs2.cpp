#include "langs2.h"

/*Read a single file for students*/
void Language_Company::read_file(std::string file_name, std::vector<Student>& students)
{
	/*Create Temporary Student Object*/
	Student s1;

	/*File handle*/
	std::ifstream FILE;
	FILE.open(file_name);

	std::stringstream ss;
	std::string file_buffer;
	std::string intermediate;


	/*Name*/
	getline(FILE, file_buffer);

	s1.name = file_buffer;

	/*Gender*/
	getline(FILE, file_buffer);

	ss << file_buffer;
	getline(ss, intermediate, ' '); //discard gender part
	getline(ss, intermediate, '\n'); //this is gender
	s1.gender = intermediate;

	/*Language*/
	getline(FILE, file_buffer);

	ss.clear();
	ss << file_buffer;
	getline(ss, intermediate, ' '); //discard language
	getline(ss, intermediate, '\n'); //target language
	s1.language = intermediate;

	/*Start Date*/
	getline(FILE, file_buffer);

	ss.clear();
	ss << file_buffer;
	getline(ss, intermediate, ' ');
	getline(ss, intermediate, '\n');
	s1.start_date = intermediate;

	/*Max*/
	getline(FILE, file_buffer);
	ss.clear();
	ss << file_buffer;
	getline(ss, intermediate, '$');//get rid of dollar sign
	getline(ss, intermediate, '\n'); //double ammount

	s1.max_rate = std::stod(intermediate);


	/*Days of the Week*/
	int i;
	for (i = 0; i < 7; i++) //loop will run from sunday to saturday 
	{
		ss.clear();
		getline(FILE, file_buffer);
		ss << file_buffer;
		getline(ss, intermediate, ' ');
		getline(ss, intermediate, ' ');

		if (intermediate == "x")//available
		{
			s1.days[i] = 1;
		}
		else if (intermediate == "-")
		{
			s1.days[i] = 0;
		}
	}
	students.push_back(s1); //register student
	FILE.close();
}

/*Read a single file with all tutors*/
void Language_Company::read_file(std::string file_name, std::vector<Tutor>& tutors)
{

/* Tutor

	The program should allow language tutors to register. When the program exits,
	tutor information should be saved in a file, and when the program starts again,
	tutor information should be populated in the program.
	This allows the tutor information to always be available (meaning that exiting the program does not mean that we no longer
	have a record of all people that signed up to be tutors).
	The information a tutor should give is:

		Rodrigo Juarez
		Gender: Male
		Languages: Spanish,French,Korean
		Date: 09/23/07
		Max: 7
		Rate: $3.40
		Sunday: x
		Monday: x
		Tuesday: -
		Wednesday: -
		Thursday: x
		Friday: x
		Saturday: -

*/
	/*File handle*/
	std::ifstream FILE;
	FILE.open(file_name);

	std::stringstream ss;
	std::string file_buffer;
	std::string intermediate;

	/*Cout how many lines there are in the file*/
	int counter = 0;
	while (getline(FILE, intermediate))
	{
		counter++;
	}

	FILE.clear();
	FILE.seekg(0);


	/*Loop for amount of tutors*/
	int i;
	int total_tutors = counter / 13;
	for (i = 0; i < total_tutors; i++)
	{
		/*Create Temporary Tutor Object*/
		Tutor t1;

		/*Name*/
		getline(FILE, file_buffer);
		t1.name = file_buffer;

		/*Gender*/
		getline(FILE, file_buffer);
		ss << file_buffer;
		getline(ss, intermediate, ' '); //discard gender part
		getline(ss, intermediate, ','); //this is gender
		t1.gender = intermediate;

		/*Languages*/
		getline(FILE, file_buffer);
		ss.clear();
		ss << file_buffer;
		getline(ss, intermediate, ' '); //discard language
	
		while (getline(ss, intermediate, ',')) //loop for how many languages there are
		{
			t1.languages.push_back(intermediate);
		}
	

		/*Start Date*/
		getline(FILE, file_buffer);
		ss.clear();
		ss << file_buffer;
		getline(ss, intermediate, ' ');
		getline(ss, intermediate, ' ');
		t1.start_date = intermediate;

		/*Max Students*/
		int max_students;
		getline(FILE, file_buffer);
		ss.clear();
		ss << file_buffer;
		getline(ss, intermediate, ' ');
		getline(ss, intermediate, ' ');

		t1.max_students = stoi(intermediate);

		/*Rate*/
		getline(FILE, file_buffer);
		ss.clear();
		ss << file_buffer;
		getline(ss, intermediate, '$');//get rid of dollar sign
		getline(ss, intermediate, ' '); //double ammount
		t1.rate = std::stod(intermediate);

		/*Days of the Week*/
		int i;
		for (i = 0; i < 7; i++) //loop will run from sunday to saturday 
		{
			ss.clear();
			getline(FILE, file_buffer);
			ss << file_buffer;
			getline(ss, intermediate, ' ');

			if (intermediate == "x")//available
			{
				t1.days[i] = 1;
			}
			else if (intermediate == "-")
			{
				t1.days[i] = 0;
			}
		}

		tutors.push_back(t1); //register tutor

	}


	FILE.close();
	
}

void Language_Company::register_tutor()
{
/* Tutor

	The program should allow language tutors to register. When the program exits,
	tutor information should be saved in a file, and when the program starts again,
	tutor information should be populated in the program.
	This allows the tutor information to always be available (meaning that exiting the program does not mean that we no longer
	have a record of all people that signed up to be tutors).
	The information a tutor should give is:

		a. Name
		b. Gender
		c. Languages available to tutor (can be more than 1)
		d. Date he or she started tutoring
		e. Available days to teach
		f. Max number of learners at any given time
		g. Amount charged per hour
*/
	Tutor t1;
	std::string response;

	std::cout << "Welcome Tutor!" << std::endl;

	std::cout << std::endl;

	std::cout << "What is your name? (First and Last)" << std::endl;
	getline(std::cin, response);
	t1.name = response;

	std::cout << std::endl;

	std::cout << "What is your gender? (Male or Female)" << std::endl;
	getline(std::cin, response);
	t1.gender = response;

	std::cout << std::endl;

	std::cout << "What languages do you teach? (first,second,etc..)" << std::endl;
	getline(std::cin, response);
	std::stringstream ss(response);
	std::string intermediate;

	while (getline(ss, intermediate, ','))
	{
		t1.languages.push_back(intermediate);
	}

	std::cout << std::endl;

	std::cout << "Date you started tutoring (dd/mm/yy)" << std::endl;
	getline(std::cin, response);
	t1.start_date = response;

	std::cout << std::endl;

	std::cout << "Max learners you can teach at once?" << std::endl;
	getline(std::cin, response);
	t1.max_students = stoi(response);

	std::cout << std::endl;

	std::cout << "What is your rate? (ex: 4.55)" << std::endl;
	getline(std::cin, response);
	double rate = stod(response);
	t1.rate = rate;

	std::cout << std::endl;

	std::cout << "What days are you available to work? (yes or no)" << std::endl;
	std::cout << std::endl;

	std::cout << "Sunday?" << std::endl;
	getline(std::cin, response);
	if (response == "yes")
	{
		t1.days[Sunday] = 1;
	}
	else //no
	{
		t1.days[Sunday] = 0;
	}
	std::cout << "Monday?" << std::endl;
	getline(std::cin, response);
	if (response == "yes")
	{
		t1.days[Monday] = 1;
	}
	else //no
	{
		t1.days[Monday] = 0;
			}
	std::cout << "Tuesday?" << std::endl;
	getline(std::cin, response);
	if (response == "yes")
	{
		t1.days[Tuesday] = 1;
			}
	else //no
	{
		t1.days[Tuesday] = 0;
	}
	std::cout << "Wednesday?" << std::endl;
	getline(std::cin, response);
	if (response == "yes")
	{
		t1.days[Wednesday] = 1;
	}
	else //no
	{
		t1.days[Wednesday] = 0;
	}
	std::cout << "Thursday?" << std::endl;
	getline(std::cin, response);
	if (response == "yes")
	{
		t1.days[Thursday] = 1;
	}
	else //no
	{
		t1.days[Thursday] = 0;
	}
	std::cout << "Friday?" << std::endl;
	getline(std::cin, response);
	if (response == "yes")
	{
		t1.days[Friday] = 1;
	}
	else //no
	{
		t1.days[Friday] = 0;
	}
	std::cout << "Saturday?" << std::endl;
	getline(std::cin, response);
	if (response == "yes")
	{
		t1.days[Saturday] = 1;
	}
	else //no
	{
		t1.days[Saturday] = 0;
	}

	tutors.push_back(t1);
}

void Language_Company::match()
{
	/*
	a. Match desired Gender 
	b. Match target Language 
	c. Check that time spent learning matches up with experience of the tutor. For example, if the learner started learning on 08/06/2016, they want a tutor with 2 years of experience (since we are now in 2018-it is up to you how to determine the current date) 
	d. Match available days 
	e. Check that the price per hour is acceptable for both parties 
	f. Check that that the tutor is willing to take more learners. For example, if the tutor indicated they only wanted a max number of two learners, this should be considered
	*/

	std::string response;
	std::string name;
	std::string preferred_gender;
	std::vector<Tutor*> matched_tutors;
	Student s1;

	/*Get input*/
	std::cout << "Hello Learner" << std::endl;
	std::cout << std::endl;

	std::cout << "What is your name? (first last)" << std::endl;
	getline(std::cin, response);
	std::cout << std::endl;
	name = response;

	std::cout << "What gender do you desire your instructor to be?" << std::endl;
	getline(std::cin, response);
	preferred_gender = response;
	std::cout << std::endl;

	/*Get student*/
	int i;
	int check = 0;
	for (i = 0; i < students.size(); i++)
	{
		if (students.at(i).name == name); //student found
		s1 = students.at(i);
		check = 1;
	}
	if (check==0)
	{
		std::cout << "Sorry, your name was not found in our records" << std::endl;
		return;
	}
	//std::cout << "Tutors.size: " << tutors.size() << std::endl;
	//std::cout << "tutors.at(0).gender " << tutors.at(0).gender << std::endl;



	/*Match Logic*/
	for (i = 0; i < tutors.size(); i++)
	{

		if (tutors.at(i).gender == preferred_gender)//their gender matches, now for target language
		{

			int j;
			for (j = 0; j < tutors.at(i).languages.size(); j++)
			{

				if (tutors.at(i).languages.at(j) == s1.language)//langauge matches, now check available days
				{

					int k;
					for (k = 0; k < 7; k++)
					{

						if (tutors.at(i).days[k] == s1.days[k]) //both available on the same day, now check times
						{
							/*TIME LOGIC*/

							std::string time_s = s1.start_date;
							std::string time_t = tutors.at(i).start_date;

							std::string intermediate;
							int total_time_s;
							int total_time_t;

							/*Get starting year for student first*/
							std::stringstream stream_time_s(time_s);
							getline(stream_time_s, intermediate, '/');
							getline(stream_time_s, intermediate, '/');
							int student_start_year = stoi(intermediate);
							total_time_s = 20 - student_start_year;

							/*Get starting year for tutor*/
							std::stringstream stream_time_t(time_t);
							getline(stream_time_s, intermediate, '/');
							getline(stream_time_s, intermediate, '/');
							int tutor_start_year = stoi(intermediate);
							total_time_t = 20 - tutor_start_year;


							if (total_time_t >= total_time_s) //if the tutor started for a longer or equal time to the learner, check rates
							{
								if (s1.max_rate <= tutors.at(i).rate) //tutor rate is less than or equal max rate of student
								{
									//now we check if the tutor is willing to take more learners
									if (tutors.at(i).tutor_students.size() == tutors.at(i).max_students)
									{
										std::cout << "Sorry, matched tutor is at max capacity" << std::endl;
									}
									else //match found
									{
										/*check if this tutor has been added before*/
										int c;
										bool check = false;
										for (c = 0; c < matched_tutors.size(); c++)
										{
											if (tutors.at(i).name == matched_tutors.at(c)->name)//repeat found
											{
												check = true;
											}
										}
										if (!check)
										{
											std::cout << tutors.at(i).name << " is available!" << std::endl;
											matched_tutors.push_back(&tutors.at(i));
										}
									}
								}
							}
						}
					}
				}
			}

		}
	}

	if (matched_tutors.empty())
	{
		std::cout << "Sorry, no available tutors to be matched with" << std::endl;
	}
	else
	{
		std::cout << "Which tutor would you like to enroll with? (first last). If none wanted, enter 'leave'" << std::endl;
		getline(std::cin, response);

		if (response == "leave")//exit function
		{
			return;
		}
		
		for (i = 0; i < matched_tutors.size(); i++)
		{
			if (matched_tutors.at(i)->name == response)
			{
				matched_tutors.at(i)->tutor_students.push_back(s1);
				std::cout << "Enrolled!" << std::endl;
				return;;
			}
		}
	}
	
}

void Language_Company::get_rid()
{
	std::string response;
	bool check = false;
	std::cout << "What is your name tutor? (First Last)" << std::endl;
	getline(std::cin, response);

	int i;
	int tutor_index;
	for (i = 0; i < tutors.size(); i++)
	{
		if (tutors.at(i).name == response) //name of tutor found
		{
			tutor_index = i;
			check = true;
		}
	}
	if (!check)
	{
		std::cout << "Sorry, tutor name not found" << std::endl;
	}
	else if (check)
	{
		//first, check if tutor has students under them
		if (tutors.at(tutor_index).tutor_students.size() == 0)
		{
			std::cout << "You don't have any students under you" << std::endl;
		}
		else //remove last student
		{
			tutors.at(tutor_index).tutor_students.pop_back();
			std::cout << "Most recent student has been removed" << std::endl;
		}
	}
}

Language_Company::Language_Company()
{
	std::string response;

	/*Get Student Information from files*/

	std::cout << "Continuously type in file names of students. Once finished, type 'quit'." << std::endl;
	std::getline(std::cin, response);

	while (response != "quit")
	{
		read_file(response, students);
		std::getline(std::cin, response);
	}

	/*Enter file name where tutor information is stored*/
	std::cout << "Enter file name where tutor information is stored" << std::endl;
	std::getline(std::cin, response);
	read_file(response, tutors);
}

Language_Company::~Language_Company()
{
	//saving tutor information in file
	int i;
	std::ofstream outf;
	outf.open("Tutors.txt");

	/*Loop for every tutor in program*/
	for (i = 0; i < tutors.size(); i++)
	{
		outf << tutors.at(i).name << std::endl;
		outf <<"Gender: "<<tutors.at(i).gender << std::endl;

		/*Print out languages to file*/
		outf << "Languages: ";
		int j;
		for (j = 0; j < tutors.at(i).languages.size(); j++)
		{
			outf << tutors.at(i).languages.at(j) << ",";
		}
		outf << std::endl;

		outf << "Date: " << tutors.at(i).start_date << std::endl;

		outf << "Max: " << tutors.at(i).max_students << std::endl;

		outf << "Rate: $" << tutors.at(i).rate << std::endl;

		/*Day availabiity*/
		outf << "Sunday: ";
		if (tutors.at(i).days[Sunday] == 0)
		{
			outf << "-" << std::endl;
		}
		else
		{
			outf << "x" << std::endl;
		}
		outf << "Monday: ";
		if (tutors.at(i).days[Monday] == 0)
		{
			outf << "-" << std::endl;
		}
		else
		{
			outf << "x" << std::endl;
		}
		outf << "Tuesday: ";
		if (tutors.at(i).days[Tuesday] == 0)
		{
			outf << "-" << std::endl;
		}
		else
		{
			outf << "x" << std::endl;
		}
		outf << "Wednesday: ";
		if (tutors.at(i).days[Wednesday] == 0)
		{
			outf << "-" << std::endl;
		}
		else
		{
			outf << "x" << std::endl;
		}
		outf << "Thursday: ";
		if (tutors.at(i).days[Thursday] == 0)
		{
			outf << "-" << std::endl;
		}
		else
		{
			outf << "x" << std::endl;
		}
		outf << "Friday: ";
		if (tutors.at(i).days[Friday] == 0)
		{
			outf << "-" << std::endl;
		}
		else
		{
			outf << "x" << std::endl;
		}
		outf << "Saturday: ";
		if (tutors.at(i).days[Saturday] == 0)
		{
			outf << "-" << std::endl;
		}
		else
		{
			outf << "x" << std::endl;
		}

	}

	outf.close();
}

void Language_Company::menu()
{
	int response;
	bool Exit = false;

	while (!Exit)
	{
		std::cout << std::endl;

		std::cout << "Main Menu: Type your number choice." << std::endl;

		std::cout << std::endl;

		std::cout << "1. Register a Language Tutor" << std::endl;
		std::cout << "2. Match a Learner with a Tutor" << std::endl;
		std::cout << "3. Get Rid of a Learner" << std::endl;
		std::cout << "4. Exit" << std::endl;

		std::cout << std::endl;

		std::cin >> response;
		getchar();

		if (response == 4)
		{
			std::cout << "Good Bye!" << std::endl;
			Exit = true;
			continue;
		}
		else if (response == 1) //register tutor
		{
			register_tutor();
		}
		else if (response == 2) //match a learner with a tutor
		{
			match();
		}
		else if (response == 3) //get rid of a learner
		{
			get_rid();
		}
	}
}

