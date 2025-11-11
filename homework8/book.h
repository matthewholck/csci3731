#ifndef BOOK_H
#define BOOK_H

#include "exercise.h"

class Book {
private:
    Exercise* firstExercise;
    Exercise* lastExercise;

public:

    // rule of 5:
    Book();
    virtual ~Book();

    // Delete copy operations as suggested by the problem
    Book(const Book& other) = delete;
    Book& operator=(const Book& other) = delete;

    // Delete move operations as suggested by the problem
    Book(Book&& other) = delete;
    Book& operator=(Book&& other) = delete;

    Exercise* addExercise(int chapter, int number);
    Exercise* getExercise(int chapter, int number) const;
    void printAll() const;
};

#endif // BOOK_H
