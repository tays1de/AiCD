#include <iostream>

using namespace std;

class day {

private:
	int daybuy;
	int daysell;
	int max;

public:

	day() {
		daybuy = 0;
		daysell = 0;
		max = 0;
	}

	int getbuy() {
		return daybuy;
	}

	int getsell() {
		return daysell;
	}

	int getmax() {
		return max;
	}

	void setbuy(int daybuy) {
		this->daybuy = daybuy;
	}

	void setsell(int daysell) {
		this->daysell = daysell;
	}

	void setmax(int max) {
		this->max = max;
	}

	day find(int* mas, int l, int r) {
		day temp;
		int MaxSum;
		int MaxSum1 = -99999;
		int MaxSum2 = -99999;
		int sum1 = 0;
		int mid = (l + r) / 2;
		int daybuy = 0;
		int daysell = 0;
		for (int i = mid; i >= l; i--) {
			sum1 += mas[i];
			if (sum1 > MaxSum1) {
				MaxSum1 = sum1;
				daybuy = i + 1;
			}
		}
		int sum2 = 0;
		for (int i = mid + 1; i <= r; i++) {
			sum2 += mas[i];
			if (sum2 > MaxSum2) {
				MaxSum2 = sum2;
				daysell = i + 1;
			}
		}
		MaxSum = MaxSum1 + MaxSum2;
		temp.setbuy(daybuy);
		temp.setsell(daysell + 1);
		temp.setmax(MaxSum);
		return temp;
	}
	day rekursiya(int* mas, int l, int r) {
		day mid, leftmid, rightmid;
		if (l == r) {
			day value;
			value.setbuy(l + 1);
			value.setsell(l + 2);
			value.setmax(mas[l]);
			return value;
		}
		else {
			int midl = (l + r) / 2;
			mid = find(mas, l, r);
			leftmid = rekursiya(mas, l, midl);
			rightmid = rekursiya(mas, midl + 1, r);
			if (mid.getmax() >= leftmid.getmax() && mid.getmax() >= rightmid.getmax()) {
				return mid;
			}
			else {
				if (leftmid.getmax() >= mid.getmax() && leftmid.getmax() >= rightmid.getmax()) {
					return leftmid;
				}
				else {
					return rightmid;
				}

			}
		}
	}

};

int main() {
	setlocale(0, "");
	day temp;
	int a;
	cout << "Введите число дней: ";
	cin >> a;
	int* mas = new int[a];
	int* mas1 = new int[a - 1];
	for (int i = 0; i < a; i++) {
		cout << "День " << i + 1 << " введите стоимость акций: ";
		cin >> mas[i];
	}
	for (int i = 0; i < a - 1; i++) {
		mas1[i] = mas[i + 1] - mas[i];
	}
	day max = temp.rekursiya(mas1, 0, a - 1);
	cout << "День покупки: " << max.getbuy()-1 << endl << "День продажи: " << max.getsell() << endl;
	cout << "Максимальная прибыль с акции: " << max.getmax() << endl;//если отрицательная то прибыли нет(надо поставить условие)
	delete[]mas;
	delete[]mas1;
	system("pause");
	return 0;
}