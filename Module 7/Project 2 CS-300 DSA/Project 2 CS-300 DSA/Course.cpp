#include "course.h"
#include <sstream>
#include <iostream>

Course::Course(const std::string& courseNumber, const std::string& courseTitle, const std::string& prerequisites) :
    courseNumber(courseNumber),
    courseTitle(courseTitle)
{
    // Parse prerequisite course numbers and stores into a vector
    
    std::istringstream iss(prerequisites);
    std::string prerequisite;
    while (std::getline(iss, prerequisite, ',')) {
        prerequisites_.push_back(prerequisite);
    }
    
}

// Retrieve and return course number
std::string Course::getCourseNumber() const {
    return courseNumber;
}

// Retrieve and return course title
std::string Course::getCourseTitle() const {
    return courseTitle;
}

// Retrieve and return prerequisites
std::string Course::getPrerequisites() const {

    // Combines prerequisites into a comma-separated string
    std::string prerequisitesString;
    for (const auto& prerequisite : prerequisites_) {
        prerequisitesString += prerequisite + ",";
    }
    // Assign prerequisitesString to prerequisite
    if (!prerequisitesString.empty()) {
        // Remove the trailing comma
        prerequisitesString.pop_back();
    }
    // Assign prerequisitesString to say there is no prerequisite
    else {
        prerequisitesString = "None";
    }

    return prerequisitesString;

}
