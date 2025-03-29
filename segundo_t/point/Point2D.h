#include <iostream>
#include <cmath>

class Point2D {
    private:
        double x;
        double y;
    public:
      // Constructores
      Point2D(): x(0), y(0) {}                  // Constructor por defecto
      Point2D(double x, double y) : x(x), y(y) {} // Constructor con parámetros
      Point2D(const Point2D & p) : x(p.x), y(p.y) {} // Constructor de copia
    // getters: metodos de acceso
    double getX() const { return x; }
    double getY() const { return y; }
    // setters: metodos de modificación
    void setX(double newX) { x = newX; } // individual
    void setY(double newY) { y = newY; } // individual
    void setCoordinates(double newX, double newY) { x = newX; y = newY; } // conjunto

    // sobrecarga de operadores
    Point2D operator+(const Point2D & p) const {
        return Point2D(x + p.x, y + p.y);
    }   
    Point2D operator-(const Point2D & p) const {
        return Point2D(x - p.x, y - p.y);
    }
    Point2D operator*(double scalar) const {
        return Point2D(x * scalar, y * scalar);
    }
    Point2D operator/(double scalar) const {
        return Point2D(x / scalar, y / scalar);
    }

    // operadores de comparación
    bool operator==(const Point2D & p) const {
        return x == p.x && y == p.y;
    }
    bool operator!=(const Point2D & p) const {
        return x != p.x || y != p.y;
    }

    // operadores de asignación
    Point2D & operator=(const Point2D & p) {
        x = p.x;
        y = p.y;
        return *this;
    }

    // calcular la distancia a otro punto
    double distance(const Point2D & p) const {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
    // calcular la distancia al origen
    double distance() const {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    // punto medio
    Point2D midpoint(const Point2D & p) const {
        return Point2D((x + p.x) / 2, (y + p.y) / 2);
    }

    // vector unitario
    Point2D unitVector() const {
        return *this / distance();
    }
    
};