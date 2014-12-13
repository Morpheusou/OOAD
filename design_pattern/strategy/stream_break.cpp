#include <iostream>
using namespace std;
class Coord {
public:
	int x, y;
};

class Compositor {
public:
	virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
			   int componentCount, int lineWidth, int breaks[]) = 0;

protected:
	Compositor(){}
};

class SimpleCompositor : public Compositor {
public:
	SimpleCompositor(){}
	virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
			   int componentCount, int lineWidth, int breaks[]){
		cout << "SimpleCompositor" << endl;
	}
};

class TeXCompositor : public Compositor {
public:
	TeXCompositor(){}
	virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
			   int componentCount, int lineWidth, int breaks[]){
		cout << "TeXCompositor" << endl;
	}
};

class ArrayCompositor : public Compositor {
public:
	ArrayCompositor(int interval){}
	virtual int Compose(Coord natural[], Coord stretch[], Coord shrink[],
			   int componentCount, int lineWidth, int breaks[]){
		cout << "ArrayCompositor" << endl;
	}
};

class Composition {
public:
	Composition(Compositor*);
	void Repair();
private:
	Compositor* _compositor;
	Composition* _components; // the list of components
	int _componentCount;      // number of components
	int _lineWidth;           // the Composition' line width
	int* _lineBreak;          // the position of linebreaks in componenets

	int _lineCount;           // the number of lines
};

Composition::Composition(Compositor* compositor)
{
	_compositor = compositor;
}

void Composition::Repair() {
	Coord* natural;
	Coord* stretchability;
	Coord* shrinkability;
	int componentCount;
	int* breaks;

	// prepare the arrays with the desired component sizes
	// ,,,
	// determine where the breaks are:
	int breakCount;
	breakCount = _compositor->Compose(natural, stretchability, shrinkability, componentCount, _lineWidth, breaks);
	// lay out components according to breaks
	// ...
}

int main()
{
	Composition* quick = new Composition(new SimpleCompositor);
	quick->Repair();
	Composition* slick = new Composition(new TeXCompositor);
	slick->Repair();
	Composition* iconic = new Composition(new ArrayCompositor(100));
	iconic->Repair();
	return 0;
}
