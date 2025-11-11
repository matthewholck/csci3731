#include "book.h"
#include <iostream>

Book::Book()
    : firstExercise(nullptr),
      lastExercise(nullptr)
{}

Book::~Book() {
    Exercise* current = firstExercise;
    while (current) {
        Exercise* next = current->getNext();
        delete current;
        current = next;
    }
}

Exercise* Book::addExercise(int chapter, int number) {
    Exercise* newExercise = new Exercise(chapter, number, lastExercise);
    if (!firstExercise)
        firstExercise = newExercise;
    lastExercise = newExercise;
    return newExercise;
}

Exercise* Book::getExercise(int chapter, int number) const {
    Exercise* current = firstExercise;
    while (current) {
        if (current->getChapter() == chapter && current->getNumber() == number)
            return current;
        current = current->getNext();
    }
    return nullptr;
}

void Book::printAll() const {
    Exercise* current = firstExercise;
    while (current) {
        std::cout << *current << " ";
        current = current->getNext();
    }
    std::cout << std::endl;
}
