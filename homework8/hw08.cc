#include <iostream>
#include <cstdlib>
#include "book.h"

int main() {
    Book myBook;

    myBook.addExercise(1, 1);
    myBook.addExercise(1, 2);
    myBook.addExercise(2, 1);
    myBook.addExercise(2, 2);
    myBook.addExercise(3, 1);
    myBook.addExercise(3, 2);

    myBook.getExercise(2, 1)->addRequirement(myBook.getExercise(1, 1));
    myBook.getExercise(3, 1)->addRequirement(myBook.getExercise(2, 1));
    myBook.getExercise(3, 1)->addRequirement(myBook.getExercise(1, 2));

    std::cout << "Initial state of book:\n";
    myBook.printAll();
    std::cout << "Enter positive or negative exercise codes (e.g., 101, -202). Ctrl+D to end.\n";

    int code;
    while (std::cin >> code) {
        int absCode = std::abs(code);
        int chapter = absCode / 100;
        int number = absCode % 100;

        Exercise* ex = myBook.getExercise(chapter, number);
        if (!ex) {
            std::cout << "No such exercise " << chapter << "." << number << "\n";
            continue;
        }

        if (code > 0) {
            ex->assign();
            std::cout << "Assigned " << chapter << "." << number << "\n";
        } else {
            ex->unassign();
            std::cout << "Unassigned " << chapter << "." << number << "\n";
        }

        std::cout << "Current book status:\n";
        myBook.printAll();
    }

    std::cout << "\nEnd of input. Final state:\n";
    myBook.printAll();

    return 0;
}
