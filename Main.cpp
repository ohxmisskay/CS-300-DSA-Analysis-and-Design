//============================================================================
// Name        : ABCU Course Planner
// Author      : Winnie Kwong
// Version     : 1.0
// Description : 7-1 Project Two
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

#include "course.h"

using namespace std;

void mainMenu()
{
	std::cout << "Main Menu" << std::endl << std::endl;
	std::cout << "1. Load Data Structure" << std::endl;
	std::cout << "2. Print Course List" << std::endl;
	std::cout << "3. Print Course" << std::endl;
	std::cout << "4. Exit" << std::endl << std::endl;
}

int main()
{
	std::vector < Course > courses;
	std::string filename;
	bool dataLoaded = false;

	while (true)
	{
		mainMenu();

		int choice;
		std::cout << "What would you like to do? ";
		std::cin >> choice;
		std::cout << endl;

		switch (choice)
		{
		case 1: {
			std::cout << "Enter the file of course data: ";
			std::cin >> filename;
			std::ifstream inputFile(filename);
			if (inputFile)
			{
				std::string line;
				while (std::getline(inputFile, line))
				{
					std::istringstream iss(line);
					std::string courseNumber, courseTitle, prerequisites;
					std::getline(iss, courseNumber, ',');
					std::getline(iss, courseTitle, ',');
					std::getline(iss, prerequisites);
					courses.
						push_back(Course
						(courseNumber, courseTitle, prerequisites));
				}

				std::cout << filename << " loaded successfully." << std::endl << std::endl;
				dataLoaded = true;
			}
			else
			{
				std::
					cerr << "ERROR: Could not open file \"" << filename << "\"."
					<< std::endl;
				dataLoaded = false;
			}
			break;
		}
		case 2: {
			if (dataLoaded)
			{
				std::vector < Course > csCourses;
				for (const auto& course : courses)
				{
					if (course.getCourseNumber().substr(0, 2) == "CS"
						|| course.getCourseNumber().substr(0, 2) == "MA")
					{
						csCourses.push_back(course);
					}
				}
				std::sort(csCourses.begin(), csCourses.end(),
					[](const Course& a, const Course& b)
					{
						return a.getCourseNumber() < b.getCourseNumber(); }
				);
				std::cout << "Here is a sample schedule:" << std::endl << std::endl;
				for (const auto& course : csCourses)
				{
					std::cout << course.getCourseNumber() << ", " << course.
						getCourseTitle() << std::endl;
				}
			}
			else
			{
				std::cout << "Please provide course data file" << std::
					endl;
			}
			break;
		}
		case 3:
		{
			if (dataLoaded)
			{
				std::string courseNumber;
				std::cout << "Enter the course number: ";
				std::cin >> courseNumber;
				transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);
				
				auto it =
					std::find_if(courses.begin(), courses.end(),
						[courseNumber](const Course& course) {
							return course.getCourseNumber() == courseNumber; }
				);
				if (it != courses.end())
				{
					std::cout << courseNumber << ", " << it->getCourseTitle() << std::endl;
					std::cout << "Prerequisites: " << it-> getPrerequisites() << std::endl;
				}
				else
				{
					std::
						cout << "ERROR: Course \"" << courseNumber << "\" does not exist." << std::endl;
				}
			}
			else
			{
				std::cout << "Please provide course data file" << std::
					endl;
			}
			break;
		}
		case 4:
		{
			std::cout << "Thank you for using the course planner!" << std::endl;
			return 0;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
		}
	}
	return 0;
}