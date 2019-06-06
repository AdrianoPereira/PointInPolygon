#include "Geometry.hpp"
#include <vector>
#include <iostream>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

//Construtor classe Point
Point::Point(double x, double y):x_(x), y_(y) {}

// Retorna coordenada x do ponto
const double Point::getX() const { return this->x_; }

// Retorna coordenada y do ponto
const double Point::getY() const { return this->y_; }

// Contrutor da linha
Line::Line(Point p1, Point p2):p1_(p1), p2_(p2) {}

// Retorna o primeiro ponto da linha
Point Line::getP1() { return this->p1_; }

// Retorna o segundo ponto da linha
Point Line::getP2() { return this->p2_; }

// Verifica se o ponto esta em cima da linha
bool Line::onLine(Point p) {
    Point p1 = this->getP1();
    Point p2 = this->getP2();
    
    if(p.getX() <= max(p1.getX(), p2.getX()) && 
        p.getX() <= min(p1.getX(), p2.getX()) &&
        (p.getY() <= max(p1.getY(), p2.getY()) && 
        p.getY() <= min(p1.getY(), p2.getY())))
            return true;
   return false;
}

// Verifica se há intersecções entre linhas 
bool Line::isIntersect(Line l2) {
    // Obter a direção das linhas
    double dir1 = this->direction(this->getP1(), this->getP2(), l2.getP1());
    double dir2 = this->direction(this->getP1(), this->getP2(), l2.getP2());
    double dir3 = this->direction(l2.getP1(), l2.getP2(), this->getP1());
    double dir4 = this->direction(l2.getP1(), l2.getP2(), this->getP2());

    if(dir1 != dir2 && dir3 != dir4)
        return true;
    if(dir1==0 && l2.onLine(this->getP1()))
        return true;
    if(dir2==0 && this->onLine(l2.getP2()))
        return true;
    if(dir3==0 && l2.onLine(this->getP1()))
        return true;
    if(dir4==0 && l2.onLine(this->getP2()))
      return true;
   
   return false;
}

//Construtor do polígono passando um conjunto de pontos já definidos
Polygon::Polygon(std::vector<Point> points):polygon_(points) {}

// Sobrescrita do método construtor do polígono, ainda sem pontos
Polygon::Polygon() {}

// Função Principal para verificar ponto no polígono
bool Polygon::inside(Point p) {
    int n = this->polygon_.size();

    // não é possível formar polígono com menos de 3 pontos
    if(n < 3)
        return false;
    
    Line exline = {p, {9999, p.getY()}}; // Defini um raio infinito
    int count = 0;
    int i = 0;
    do {
        //Linha a partir de dois pontos consecutivos
        Line side = {this->polygon_[i], this->polygon_[(i+1)%n]};
        if(side.isIntersect(exline)) {      
            if(side.direction(side.getP1(), p, side.getP2()) == 0)
                return side.onLine(p);
            count++;
        }
        i = (i+1)%n;
    } while(i != 0);
        //retorna se a quantidade de intersecções com o raio infinito é par
        return count&1;
}

//Função auxiliar para verificar obter a direção do polígono
double Line::direction(Point a, Point b, Point c) {
    double val = (b.getY()-a.getY())*(c.getX()-b.getX())-
    (b.getX()-a.getX())*(c.getY()-b.getY());
    if (val == 0)
        return 0;   // colinear
    else if(val < 0)
        return 2;   // direção anti-horária do polígono
    
    return 1;   // Direção horária do polígono
}