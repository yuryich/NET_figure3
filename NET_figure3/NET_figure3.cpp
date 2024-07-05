#include <iostream>
#include <string>
using namespace std;

class Figure {
public:
	Figure(int sides_count, const string& name)
		: sides_count(sides_count), name(name) {}

	int get_sides_count() const {
		return sides_count;
	}

	string get_name() const {
		return name;
	}

	void print_info() const {
		cout << name << ":" << endl;
		cout << "Количество сторон: " << sides_count << endl;
		if (check()) {
			cout << "Правильная" << endl;
		}
		else {
			cout << "Неправильная" << endl;
		}
	}

	bool check() const {
		return sides_count == 0;
	}

protected:
	int sides_count;
	string name;
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: Figure(3, "Треугольник"), side_a(a), side_b(b), side_c(c), degree_A(A), degree_B(B), degree_C(C) {}

	void print_info() const {
		Figure::print_info();
		cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << endl;
		cout << "Углы: A=" << degree_A << " B=" << degree_B << " C=" << degree_C << endl;
		cout << endl;
	}

	bool check() const {
		return (degree_A + degree_B + degree_C == 180);
	}

protected:
	int side_a, side_b, side_c;
	int degree_A, degree_B, degree_C;
};

class RightTriangle : public Triangle {
public:
	RightTriangle(int a, int b, int c, int A, int B)
		: Triangle(a, b, c, A, B, 90) {
		name = "Прямоугольный треугольник";
	}

	bool check() const {
		return Triangle::check() && (degree_C == 90);
	}
};

class IsoscelesTriangle : public Triangle {
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triangle(a, b, a, A, B, A) {
		name = "Равнобедренный треугольник";
	}

	bool check() const {
		return Triangle::check() && (side_a == side_c) && (degree_A == degree_C);
	}
};

class EquilateralTriangle : public Triangle {
public:
	EquilateralTriangle(int a)
		: Triangle(a, a, a, 60, 60, 60) {
		name = "Равносторонний треугольник";
	}

	bool check() const {
		return Triangle::check() && (side_a == side_b) && (side_b == side_c) && (degree_A == 60) && (degree_B == 60) && (degree_C == 60);
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
		: Figure(4, "Четырёхугольник"), side_a(a), side_b(b), side_c(c), side_d(d), degree_A(A), degree_B(B), degree_C(C), degree_D(D) {}

	void print_info() const {
		Figure::print_info();
		cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << " d=" << side_d << endl;
		cout << "Углы: A=" << degree_A << " B=" << degree_B << " C=" << degree_C << " D=" << degree_D << endl;
		cout << endl;
	}

	bool check() const {
		return (degree_A + degree_B + degree_C + degree_D == 360);
	}

protected:
	int side_a, side_b, side_c, side_d;
	int degree_A, degree_B, degree_C, degree_D;
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B)
		: Quadrangle(a, b, a, b, A, B, A, B) {
		name = "Параллелограмм";
	}

	bool check() const {
		return Quadrangle::check() && (side_a == side_c) && (side_b == side_d) && (degree_A == degree_C) && (degree_B == degree_D);
	}
};

class Rectangle : public Parallelogram {
public:
	Rectangle(int a, int b)
		: Parallelogram(a, b, 90, 90) {
		name = "Прямоугольник";
	}

	bool check() const {
		return Parallelogram::check() && (degree_A == 90) && (degree_B == 90);
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int a, int A, int B)
		: Parallelogram(a, a, A, B) {
		name = "Ромб";
	}

	bool check() const {
		return Parallelogram::check() && (side_a == side_b) && (side_b == side_c) && (side_c == side_d);
	}
};

class Square : public Rhombus {
public:
	Square(int a)
		: Rhombus(a, 90, 90) {
		name = "Квадрат";
	}

	bool check() const {
		return Rhombus::check() && (degree_A == 90) && (degree_B == 90);
	}
};

int main() {
	setlocale(LC_ALL, "rus");

	Figure fig(0, "Фигура");
	Triangle triangle(10, 20, 30, 50, 60, 70);
	RightTriangle right_triangle(10, 20, 30, 50, 60);
	IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
	EquilateralTriangle equilateral_triangle(30);
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	Rectangle rectangle(10, 20);
	Square square(20);
	Parallelogram parallelogram(20, 30, 30, 40);
	Rhombus rhombus(30, 30, 40);

	fig.print_info();
	cout << endl;
	triangle.print_info();
	right_triangle.print_info();
	isosceles_triangle.print_info();
	equilateral_triangle.print_info();
	quadrangle.print_info();
	rectangle.print_info();
	square.print_info();
	parallelogram.print_info();
	rhombus.print_info();
}