#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

// defining a structure to represent a quiz question
struct questions {
    string questionText;
    vector<string> options;
    int correctOption;
};

// displaying a question and its corresponding options
void displayQuestion(const questions& q) {
    cout << q.questionText << endl;
    for (int i = 0; i < q.options.size(); ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
}

// checking if the user's answer is correct
bool isCorrectAnswer(const questions& q, int userAnswer) {
    return userAnswer == q.correctOption;
}

int main() {
    //quiz questions!! and options too
    vector<questions> quiz = {
            {"When was Huston-Tillotson founded?", {"1875", "1715", "1934", "1650"}, 1},
            {"What is the largest planet in our solar system?", {"Mercury", "Venus", "Jupiter", "Mars"}, 3},
            {"Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Mark Twain"}, 1},
            {"Who is the current president/CEO of Huston-Tillotson University?", {"Dr. Melvis X. Williams", "Dr. Melvin K. Wales", "Dr. Melva K. Wallace", "Dr. Zelda K. Wallace"}, 3},
            {"How many seasons does the United States have each year?", {"5", "4", "2", "3"}, 2},
            {"How many stripes are there on the U.S flag?", {"11", "14", "10", "13"}, 4},
            {"How many days does it take for the Earth to orbit the sun?", {"365", "375", "400", "355"}, 1},
            {"Which planet has the most moons?", {"Jupiter", "Saturn", "Earth", "Uranus"}, 2},
            {"What are the four principles of OOP in C++?", {"Encapsulation, Inheritance, Functions, Data Structures", "Loops, Pointers, Functions, Variables", "Abstraction, Polymorphism, Encapsulation, Inheritance", "Classes, Structures, Pointers, Inheritance"}, 3},
            {"In what year did the Titanic sink?", {"1917", "1931", "2000", "1912"}, 4},
            {"What is the chemical symbol for Gold?", {"Au", "Go", "Gd", "Ag"}, 1},
            {"Which animal is known as the 'king of the jungle'?", {"Gorilla", "Lion", "Tiger", "Elephant"}, 2},
            {"What is the largest organ in the human body?", {"Heart", "Brain", "Skin", "Liver"}, 3},
            {"What is the largest ocean on Earth?", {"Pacific", "Indian", "Atlantic", "Artic"}, 1},
            {"What state has the highest population in the U.S?", {"Florida", "Texas", "New York", "California"}, 4},
    };

    // getting user input for the number of questions they want to get quizzed on
    int numQuestions;
    do {
        cout << "Enter the number of questions you want to answer (1-" << quiz.size() << "): ";
        cin >> numQuestions;
    } while (numQuestions < 1 || numQuestions > quiz.size());

    //seeding the random number generator (optional)
    srand(time(0));

    //shuffling the questions in the quiz vector
    random_device rd;
    mt19937 g(rd());
    shuffle(quiz.begin(), quiz.end(), g);

    //displaying each question and getting user's answers
    int score = 0;
    for (int i = 0; i < numQuestions; ++i) {
        displayQuestion(quiz[i]);
        cout << "Enter the answer of your choice(1-" << quiz[i].options.size() << "): ";
        int userAnswer;
        cin >> userAnswer;
        if (isCorrectAnswer(quiz[i], userAnswer)) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer is: " << quiz[i].options[quiz[i].correctOption - 1] << endl;
        }
        cout << endl;
    }

    //displaying final score based on answered questions
    cout << "Quiz completed. Your score: " << score << "/" << numQuestions << endl;

    return 0;
}
