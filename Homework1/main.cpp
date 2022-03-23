#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Student
{

    std::string name;
    std::string surname;
    int album_nr;
    std::vector<int> grades;
public:

    Student(std::string n="unknown",std::string s="unknown" ,int an=0, std::vector<int> g={})
    {
        name = n;
        surname = s;
        album_nr = an;
        grades = g;
    }

    bool add_grade(float grade)
    {
        if (grade >= 2.0 && grade <= 5.0)
        {
            grades.push_back(grade);
            return true;
        }
        return false;
    }

    float calculate_grade()
    {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    void set_name(std::string new_name)
    {
        name = new_name;
    }

    void set_surname(std::string new_surname)
    {
        surname = new_surname;
    }

    bool set_album(int new_album)
    {
        if (new_album<1000000)
        {
            album_nr = new_album;
            return true;
        }
        return false;
    }

    void display(void)
    {
        std::cout << "Name: " << name
                  << "\nSurname:" << surname
                  << "\nAlbum number: " << album_nr
                  << "\nGrades:";
        for(auto g: grades)
        {
            std::cout << g << " ";
        }
    }

    void passed(void)
    {
        int no_2 = 0;
        for(auto g: grades)
        {
            if(g == 0) no_2 ++;
        }
        if(no_2>1) std::cout << "Faild" << std::endl;
        std::cout << "Passed!" << std::endl;
    }

};


class Complex
{
    double real;
    double imaginary;
public:
    Complex(double r=0,double i=0)
    {
        real=r;
        imaginary=i;
    }

    void set_rl(double rl)
    {
        real=rl;
    }

    void set_im(double im)
    {
        imaginary=im;
    }

    void print(void)
    {
        if(imaginary>=0)
            std::cout << real << '+' << imaginary << 'i' << std::endl;
        else
            std::cout << real <<  imaginary << 'i' << std::endl;
    }

    Complex add(Complex x)
    {
        Complex res;
        res.set_rl(real+x.real);
        res.set_im(imaginary+x.imaginary);
        return res;
    }

};

int main()
{

    std::string name, surname;
    int album, grade;

    Student student1;

    std::cout << "1. Student";
    std::cout << "Enter name:"; std::cin >> name;
    std::cout << "Enter surname:"; std::cin >> surname;
    std::cout << "Enter album number:"; std::cin >> album;
    student1.set_name(name);
    student1.set_surname(surname);
    student1.set_album(album);

    std::cout << "Enter 1st grade:"; std::cin >> grade;
    student1.add_grade(grade);
    std::cout << "Enter 2st grade:"; std::cin >> grade;
    student1.add_grade(grade);
    std::cout << "Enter 3st grade:"; std::cin >> grade;
    student1.add_grade(grade);

    std::cout << student1.calculate_grade() << std::endl;
    student1.passed();
    student1.display();


    std::cout << "\n\n\n2. Complex numbers:";

    Complex a(1.0, -2.0);
    Complex b(3.14);

    std::cout << "\na = "; a.print();
    std::cout << "\nb = "; a.print();

    std::cout << "\nim(b) = -5";
    b.set_im(-5);

    std::cout << "\nc = a+b = ";
    Complex c = a.add(b);
    c.print();

    return 0;
}
