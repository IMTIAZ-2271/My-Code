#include <bits/stdc++.h>
using namespace std;

class Figure
{
private:
    int row;
    int col;
    string name;
    int **matrix;

public:
    Figure()
    {
        row = 0;
        col = 0;
        name = "undefined";
        matrix = nullptr;
    }

    Figure(int r, int c, int arr[])
    {
        if (r < 1 || c < 1)
        {
            cout << "Invalid dimensions for Figure" << endl;
            return;
        }
        row = r;
        col = c;
        string temp;
        if (c > 1)
        {
            if (r == 1)
            {
                temp = "point";
            }
            else if (r == 2)
            {
                temp = "line";
            }
            else if (r == 3)
            {
                temp = "triangle";
            }
            else if (r == 4)
            {
                temp = "rectangle";
            }
            else if (r > 4)
            {
                temp = "polygon";
            }
        }
        else if (c == 1)
        {
            temp = "line";
        }
        name = temp + to_string(c) + "D";
        matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = arr[i * col + j];
            }
        }
    }
    Figure(const Figure &f)
    {
        row = f.row;
        col = f.col;
        name = f.name;
        matrix = new int *[row];
        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = f.matrix[i][j];
            }
        }
    }

    ~Figure()
    {
        if (matrix != nullptr)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrix[i][j] = 0;
                }
            }
            row = 0;
            col = 0;
            cout << name << " has been destroyed" << endl;

            for (int i = 0; i < row; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }
    int getsum()
    {
        if (matrix == nullptr)
        {
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }

    int getsum(int m, int n)
    {
        if (matrix == nullptr)
        {
            return 0;
        }
        if (m > row || n > col)
        {
            cout << "Row and Column values exceed matrix dimensions" << endl;
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += matrix[i][j];
            }
        }
        return sum;
    }

    void display()
    {
        cout << "Row: " << row << ", Column: " << col << endl;
        cout << "Figure Name: " << name << endl;
        cout << "Matrix: " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "Demostration for default constructor:" << endl;
    Figure fig0;
    fig0.display();
    cout << "Sum of all elements in fig0: " << fig0.getsum() << endl;
    cout << "Sum of first 2 rows and 2 columns in fig0: " << fig0.getsum(2, 2) << endl;
    cout << endl;

    cout << "Demostration for parameterized constructor:" << endl;
    int row, column;
    cout << "Enter number of rows and columns: ";
    cin >> row >> column;
    int arr[row * column];
    cout << "Enter the elements of the matrix: ";
    for (int i = 0; i < row * column; i++)
    {
        cin >> arr[i];
    }
    Figure fig1(row, column, arr);
    fig1.display();
    cout << "Sum of all elements :" << fig1.getsum() << endl;
    cout << "Sum of first 2 rows and 2 columns: " << fig1.getsum(2, 2) << endl;
    cout << endl;

    cout << "Demostration for copy constructor:" << endl;
    Figure fig3(fig1);
    fig3.display();
    cout << "Sum of all elements in fig3: " << fig3.getsum() << endl;
    cout << "Sum of first 2 rows and 2 columns in fig3: " << fig3.getsum(2, 2) << endl;
    cout << endl;

    return 0;
}