#include<iostream>
#include<vector>

class Circle;
class Square;

class Visitor{
    public:
    virtual void visit(Circle& circle)=0;
    virtual void visit(Square& square)=0;
};

//Element Interface
class Shape{
    public:
    virtual void accept(Visitor& visitor)=0;
};

// Concrete Elements
class Circle : public Shape {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
private:
  int radius_=1;
};

class Square : public Shape {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }
private:
 int side_=1;
};


// Concrete Visitor that defines actions for each element type
class DrawVisitor : public Visitor {
public:
    void visit(Circle& circle) override {
        std::cout << "Drawing Circle.\n";
    }

    void visit(Square& square) override {
        std::cout << "Drawing Square.\n";
    }
};

class AreaVisitor:public Visitor{
     void visit(Circle& circle) override {
        std::cout << "area of the circle is.\n";
    }

    void visit(Square& square) override {
        std::cout << "area of the square \n";
    }

};

int main() {
    Circle circle;
    Square square;
    
    DrawVisitor drawVisitor; // Visitor that will draw the shapes
    AreaVisitor areaVisitor;

    // Circle and Square accept the visitor, which then performs the appropriate action
    circle.accept(drawVisitor); // Output: Drawing Circle.
    square.accept(drawVisitor); // Output: Drawing Square.
    circle.accept(areaVisitor);
    square.accept(areaVisitor); // Output: Drawing Square.



    return 0;
}