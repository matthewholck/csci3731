#ifndef EXERCISE_H
#define EXERCISE_H

#include <iostream>

class Book; // forward declaration

class Exercise {
private:
    int chapter;
    int number;
    bool assigned;
    Exercise* prev;
    Exercise* next;
    Exercise* requirements[16]; // fixed length suggested by problem descripton
    int reqCount;
    Book* book;

public:
    Exercise(int chapter, int number, Exercise* prevExercise = nullptr);
    virtual ~Exercise();

    Exercise* getNext() const;
    void setNext(Exercise* nextExercise);

    void assign();
    void unassign();

    void addRequirement(Exercise* req);

    int getChapter() const { return chapter; }
    int getNumber() const { return number; }
    bool isAssigned() const { return assigned; }

    friend std::ostream& operator<<(std::ostream& out, const Exercise& ex);
};

#endif // EXERCISE_H
