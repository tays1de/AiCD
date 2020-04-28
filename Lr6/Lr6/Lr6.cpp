#include <iostream>
#include <windows.h>
#include <list>
using namespace std;



class Steck {
	 list<int> a;
public:
	 void push(int id) {
		 a.push_back(id);
	 }
	 void pop() {
		 a.pop_back();
	 }
	 bool isEmpty() {
		 return a.empty();
	 }
	 int print() {
		 return a.back();
	 }
};

class Queue {
	list<int> b;
public:
	void insert(int id) {
		b.push_back(id);
	}
	void remave() {
		b.pop_front();
	}
	bool isEmpty() {
		return b.empty();
	}
	int print() {
		return b.front();
	}

};


class Dack {
	list<int> c;
public:
	void insertEnd(int id) {
		c.push_back(id);
	}
	void insertBegin(int id) {
		c.push_front(id);
	}
	void remaveEnd() {
		c.pop_back();
	}
	void remaveBegin() {
		c.pop_front();
	}
	bool isEmpty() {
		return c.empty();
	}
	int printLast() {
		return c.back();
	}
	int printBegin() {
		return c.front();
	}
};
void firstQueuePrint() {
	cout << "\n";
	cout << "\t<====================X====================>\n";
	cout << "\t1 - add a student to the retake queue   - 1\n";
	cout << "\t2 - send student to retake              - 2\n";
	cout << "\t3 - print queue                         - 3\n";
	cout << "\t4 - add a top exam ticket               - 4\n";
	cout << "\t5 - add a lower exam ticket             - 5\n";
	cout << "\t6 - add a exem task                     - 6\n";
	cout << "\t9 - program shutdown                    - 9\n";
	cout << "\t<====================X====================>\n";
	cout << "\n";
}

void examTicketsPrint() {
	cout << endl;
	cout << "\t<====================X====================>" << endl;
	cout << "\t1 - choose the top exam ticket          - 1" << endl;
	cout << "\t2 - choose a lower exam ticket          - 2" << endl;
	cout << "\t9 - program shutdown                    - 9" << endl;
	cout << "\t<====================X====================>" << endl;
	cout << endl;

}

void examTaskPrint() {
	cout << endl;
	cout << "\t<====================X====================>" << endl;
	cout << "\t1 - choose the exam task                - 1" << endl;
	cout << "\t9 - program shutdown                    - 9" << endl;
	cout << "\t<====================X====================>" << endl;
	cout << endl;
}

void examPrint() {
	cout << endl;
	cout << "\t<====================X====================>" << endl;
	cout << "\t1 - student passed the exam             - 1" << endl;
	cout << "\t2 - send for retake 			          - 2" << endl;
	cout << "\t9 - program shutdown                    - 9" << endl;
	cout << "\t<====================X====================>" << endl;
	cout << endl;
}
int main()
{
	setlocale(LC_ALL, "");
	Queue students;
	Dack  tickets;
	Steck quiz;
	bool run;
	for (int i = 1; i < 26; i++) {
		tickets.insertBegin(i);
		quiz.push(i);
	}
	for (int i = 1; i < 26; i++) {
		students.insert(i);
	}
	int tempStack, tempDeck, tempQueue;
	int controlButton;

	while (true) {
		firstQueuePrint();
		cout << ":>> ";
		cin >> controlButton;


		switch (controlButton) {
		case  (1):////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "Enter a student number :>>";
			int buf;
			cin >> buf;
			students.insert(buf);

			cout << "\n\t<student add successfully>";
			break;
		case (2):////////////////////////////////////////////////////////////////////////////////////////////////////
			tempQueue = students.print();
			students.remave();
			run = true;
			while (run) {
				examTicketsPrint();
				cout << ":>> ";
				cin >> controlButton;
				switch (controlButton) {
				case  (1):
					tempDeck = tickets.printLast();
					tickets.remaveEnd();
					cout << "\nselected exam ticket: " + tempDeck << endl;
					cout << "\n\t<exam ticket select successfully>" << endl;
					run = false;
					break;
				case (2):
					tempDeck = tickets.printBegin();
					tickets.remaveBegin();
					cout << "\nselected exam ticket: " + tempDeck << endl;
					cout << "\n\t<exam ticket select successfully>" << endl;
					run = false;
					break;
				case (9):////////////////////////////////////////////////////////////////////////////////////////////////////
					cout << "\t<Program shutdown>\n" << endl;
					return 2;
					break;
				default:////////////////////////////////////////////////////////////////////////////////////////////////////
					cout << "\t<ERROR> unknown button <ERROR>" << endl;
					return 3;
					break;
					
				}
			}
			run = true;
			while (run) {
				examTaskPrint();
				cout << ":>> " << endl;
				cin >> controlButton;
				switch (controlButton) {
				case  (1):
					tempStack = quiz.print();
					quiz.pop();
					cout << "\nselected exam task: " + tempStack << endl;
					cout << "\n\t<exam task select successfully>"<< endl;
					run = false;
					break;
				case (9):////////////////////////////////////////////////////////////////////////////////////////////////////
					cout << "\t<Program shutdown>\n" << endl;
					return 5;
					break;
				default:////////////////////////////////////////////////////////////////////////////////////////////////////
					cout << "\t<ERROR> unknown button <ERROR>" << endl;
					break;
				}
			}
			run = true;
			while (run) {
				examPrint();
				cout << ":>> ";
				cin >> controlButton;
				switch (controlButton) {
				case  (1):
					cout << "Good job, student!" << endl;
					run = false;
					break;
				case  (2):
					cout << "U don't no, go start again!" << endl;
					students.insert(tempQueue);
					run = false;
					break;
				case ('9'):////////////////////////////////////////////////////////////////////////////////////////////////////
					cout << "\t<Program shutdown>\n" << endl;
					return 9;
					break;
				default:////////////////////////////////////////////////////////////////////////////////////////////////////
					cout << "\t<ERROR> unknown button <ERROR>" << endl;
					break;
				}
				quiz.push(tempStack);
				tickets.insertBegin(tempDeck);
			}
			break;
		case (3):////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "first: " <<  students.print() << endl;
			break;
		case (4):// select //////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "Enter a exam ticket :>> " << endl;
			int bufik;
			cin >> bufik;
			tickets.insertEnd(buf);

			cout << "top: " <<  tickets.printLast();
			cout << "\nlower: "<< tickets.printBegin();
			cout << "\n\t<exam ticket add successfully>" << endl;
			break;
		case (5):// insert //////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "Enter a exam ticket :>> " << endl;
			int bufer;
			cin >> bufer;
			tickets.insertBegin(bufer);

			cout << "\ntop: " <<  tickets.printLast();
			cout << "\nlower: " << tickets.printBegin();
			cout << "\n\t<exam ticket add successfully>" << endl;
			break;
		case (6):// bubble //////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "Enter a exam task :>> " << endl;
			int k;
			cin >> k;
			quiz.push(k);

			cout << "\n\ttop: " <<  quiz.print();
			cout << "\n\t<exam task add successfully>" << endl;
			break;
		case (9):////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "\t<Program shutdown>\n" << endl;
			return 7;
			break;
		default:////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "\t<ERROR> unknown button <ERROR>" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}
