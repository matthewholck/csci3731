#include "exercise.h"
#include "book.h"

Exercise::Exercise(int chapter, int number, Exercise* prevExercise)
    : chapter(chapter),
      number(number),
      assigned(false),
      prev(prevExercise),
      next(nullptr),
      reqCount(0),
      book(nullptr)
{
    for (int i = 0; i < 16; ++i)
        requirements[i] = nullptr;

    if (prevExercise) {
        prevExercise->setNext(this);
    }
}

Exercise::~Exercise() {
    // Book owns exercise and handles deletion
}

Exercise* Exercise::getNext() const {
    return next;
}

void Exercise::setNext(Exercise* nextExercise) {
    next = nextExercise;
}

void Exercise::assign() {
    if (assigned) return;
    assigned = true;

    // Recursively assign all requirements
    for (int i = 0; i < reqCount; ++i) {
        if (requirements[i])
            requirements[i]->assign();
    }
}

void Exercise::unassign() {
    if (!assigned) return;
    assigned = false;

    // Recursively unassign all requirements
    for (int i = 0; i < reqCount; ++i) {
        if (requirements[i])
            requirements[i]->unassign();
    }
}

void Exercise::addRequirement(Exercise* req) {
    if (req && reqCount < 16) {
        requirements[reqCount++] = req;
    }
}

std::ostream& operator<<(std::ostream& out, const Exercise& ex) {
    if (ex.assigned)
        out << ex.chapter << "." << ex.number;
    else
        out << "*.*";
    return out;
}
