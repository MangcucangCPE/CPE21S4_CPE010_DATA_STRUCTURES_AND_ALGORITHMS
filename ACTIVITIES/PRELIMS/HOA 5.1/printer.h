#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>

class Job {
public:
    int id;
    std::string userName;
    int pages;

    Job(int jobId = 0, std::string name = "", int numPages = 0) {
        id = jobId;
        userName = name;
        pages = numPages;
    }
};

struct Node {
    Job data;
    Node* next;

    Node(Job job) {
        data = job;
        next = nullptr;
    }
};

class Printer {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Printer() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~Printer() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void addJob(int id, std::string userName, int pages) {
        Job newJob(id, userName, pages);
        Node* newNode = new Node(newJob);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        std::cout << "Job #" << id << " submitted by " << userName << " (" << pages << " pages) has been added to the queue.\n";
    }

    void processAllJobs() {
        if (front == nullptr) {
            std::cout << "No jobs to process.\n";
            return;
        }

        std::cout << "Printer is now processing " << count << " job(s)...\n";

        while (front != nullptr) {
            Node* temp = front;
            std::cout << "Printing Job #" << temp->data.id 
                      << " for " << temp->data.userName 
                      << " - " << temp->data.pages << " page(s)... Done.\n";

            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
        }

        count = 0;
        std::cout << "All jobs have been processed. Printer is idle.\n";
    }
};

#endif