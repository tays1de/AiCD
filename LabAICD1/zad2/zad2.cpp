#include <iostream>

using namespace std;

class Bottle {
private:
    int Volume;
    int nowVolume;
    char name;

public:
    Bottle(int Volum, char n) {
        Volume = Volum;
        nowVolume = 0;
        name = n;
    }
    void setNowVolume(int Vol) {
        this->nowVolume = Vol;
    }

    int getNowVolume() {
        return nowVolume;
    }

    int getVolume() {
        return Volume;
    }

    void FullVolume() {
        nowVolume = Volume;
        cout << "Объём полностью наполнен в " << this->name << endl;
}
    void Clear() {
        this->nowVolume = 0;
        cout << "Объём очищен в " << this->name  << endl;
    }

};


void perelivanie(Bottle *A, Bottle *B) {
    if (A->getNowVolume() + B->getNowVolume() <= B->getVolume()) {
        B->setNowVolume(B->getNowVolume() + A->getNowVolume());
        A->setNowVolume(0);
    }
    if (A->getNowVolume() + B->getNowVolume() > B->getVolume()) {
        int buff = A->getNowVolume() + B->getNowVolume() - B->getVolume();
        B->setNowVolume(B->getVolume());
        A->setNowVolume(buff);
    }
    cout << "Объём в сосуде А: " << A->getNowVolume() << " \n Объём в сосуде Б: " << B->getNowVolume() << endl;
}


int nod(int a, int b)
{
    int max, min;
    if (a > b)
    {
        max = abs(a);
        min = abs(b);
    }
    else
    {
        max = abs(b);
        min = abs(a);
    }
    int r = max % min;
    if (r == 0)
    {
        return min;
    }
    else
    {
        return nod(b, r);
    }
}


void nedNowVolume(int X, Bottle A, Bottle B) {

    bool first = true;
    if (X > A.getVolume() || X > B.getVolume() && (nod(A.getVolume(), B.getVolume()) != 1)  || (nod(A.getVolume(), B.getVolume()) == 2 && X % 2 != 0)) {
        cout << "Невозможно получить такой объём" << endl;
    }
    else if (nod(A.getVolume(), B.getVolume()) == 1) {
         
        if (A.getVolume() > B.getVolume()) {

            while (first) {
                A.FullVolume();
                perelivanie(&A, &B);

                if (A.getNowVolume() == X || B.getNowVolume() == X) {
                    cout << "Получилось!" << endl;
                    first = false;
                    continue;

                }

                B.Clear();
                perelivanie(&A, &B);
                if (A.getNowVolume() == X || B.getNowVolume() == X) {
                    cout << "Получилось!" << endl;
                    first = false;

                }
                if (B.getNowVolume() == B.getVolume() && A.getNowVolume() != 0) {
                    B.Clear();
                    perelivanie(&A, &B);
                }
            }
        }

    }
    else if (nod(A.getVolume(), B.getVolume()) != 1 && (X % nod(A.getVolume(), B.getVolume()) == 0)) {

        if (A.getVolume() > B.getVolume()) {

            while (first) {
                A.FullVolume();
                perelivanie(&A, &B);

                if (A.getNowVolume() == X || B.getNowVolume() == X) {
                    cout << "Получилось!" << endl;
                    first = false;
                    continue;

                }

                B.Clear();
                perelivanie(&A, &B);
                if (A.getNowVolume() == X || B.getNowVolume() == X) {
                    cout << "Получилось!" << endl;
                    first = false;
                    continue;

                }
                if (B.getNowVolume() == B.getVolume() && A.getNowVolume() != 0) {
                    B.Clear();
                    perelivanie(&A, &B);
                }
            }
        }
    }

    }


int main()
{
    setlocale(LC_ALL, "RUS");
    int Av, AV, Bv, BV;
    cout << "Введите объём сосуда А: ";
    cin >> Av;
  
    cout << "Введите объём сосуда Б: ";
    cin >> Bv;
    
    Bottle A(Av,'A'); 
    Bottle B(Bv,'B');
   
    
    int x;
    cout << "Введите сколько нужно литров" << endl;
    cin >> x;
    if (A.getVolume() > B.getVolume()) {
        nedNowVolume(x, A, B);
    }
    else {
        nedNowVolume(x, B, A);
    }
 
    
    system("pause");
    return 0;
}

