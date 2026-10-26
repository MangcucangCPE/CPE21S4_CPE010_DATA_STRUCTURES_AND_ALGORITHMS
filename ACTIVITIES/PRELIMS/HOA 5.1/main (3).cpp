#include <iostream>
#include "printer.h"

int main() {
    Printer officePrinter;

    std::cout << "=== Incoming Print Requests ===\n";
    officePrinter.addJob(101, "Marco", 4);
    officePrinter.addJob(102, "Sophia", 15);
    officePrinter.addJob(103, "Liam", 8);
    officePrinter.addJob(104, "Chloe", 5);

    std::cout << "\n=== Executing Print Queue (FIFO) ===\n\n";
    officePrinter.processAllJobs();

    std::cout << "\n=== Second Batch of Print Jobs ===\n";
    officePrinter.addJob(105, "Ethan", 10);
    officePrinter.addJob(106, "Mia", 3);

    std::cout << "\n";
    officePrinter.processAllJobs();

    return 0;
}