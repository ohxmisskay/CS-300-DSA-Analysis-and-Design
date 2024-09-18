#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

class Course {

public:
    // Default constructor
    Course(const std::string& courseNumber, const std::string& courseTitle, const std::string& prerequisites);

    // Accessor for course number, course title, and prerequisite
    std::string getCourseNumber() const;
    std::string getCourseTitle() const;
    std::string getPrerequisites() const;

private:
    std::string courseNumber;
    std::string courseTitle;
    std::vector<std::string> prerequisites_;
};

// COURSE_H
#endif