#include <iostream>

using namespace std;

class ArrayIndexOutOfBounds {};

class Table {
    int** arr;
    int row;
    int col;

   public:
    Table() {
        row = 0;
        col = 0;
        arr = NULL;
    }

    Table(int row, int col) {
        this->row = row;
        this->col = col;
        arr = new int*[row];
        for (int i = 0; i < row; i++) arr[i] = new int[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) arr[i][j] = 0;
    }

    Table(const Table& that) {
        this->row = that.row;
        this->col = that.col;
        arr = new int*[row];
        for (int i = 0; i < row; i++) arr[i] = new int[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) this->arr[i][j] = that.arr[i][j];
    }

    int* operator[](int i) {
        if (i < 0 || i >= row) throw ArrayIndexOutOfBounds();
        return arr[i];
    }

    friend istream& operator>>(istream& cin, const Table& t) {
        for (int i = 0; i < t.row; i++)
            for (int j = 0; j < t.col; j++) cin >> t.arr[i][j];
        return cin;
    }

    friend ostream& operator<<(ostream& cout, const Table& t) {
        for (int i = 0; i < t.row; i++) {
            for (int j = 0; j < t.col; j++) cout << t.arr[i][j] << " ";
            cout << endl;
        }
        return cout;
    }
};

int main() {
    Table t(4, 5), t1(4, 5);
    cin >> t;
    t[0][0] = 5;
    int x = t[2][3];
    t1 = t;
    cout << t << "\n" << t1;
}
