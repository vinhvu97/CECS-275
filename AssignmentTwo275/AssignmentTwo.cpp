#include <iostream>
using namespace std;

#include "point.h"
#include "circle.h"
#include "target.h"

static void doPoint(Point &p1, Point &p2)
{
	cout << "Point p1 is " << p1 << endl;
	cout << "Point p2 is " << p2 << endl;

	cout << "p1 == p1? " << ((p1 == p1) ? " Yes " : " No ") << endl;
	cout << "p1 == p2? " << ((p1 == p2) ? " Yes " : " No ") << endl;

	cout << "p1 != p1? " << ((p1 != p1) ? " Yes " : " No ") << endl;
	cout << "p1 != p2? " << ((p1 != p2) ? " Yes " : " No ") << endl;

	cout << "X of p1 is " << p1.getX() << ", Y of p1 is " << p1.getY() << endl;
	cout << "X of p2 is " << p2.getX() << ", Y of p2 is " << p2.getY() << endl;

	cout << "Distance between p1 & p2 is " << p1.getDistance(p2) << endl;
	
	double rho, theta;
	
	p1.getPolarCoordinate(rho, theta);
	cout << "Polar coordinate of p1 is (" << rho << "," << theta << ")" << endl;
	
	p2.getPolarCoordinate(rho, theta);
	cout << "Polar coordinate of p2 is (" << rho << "," << theta << ")" << endl;

}

static void doPoints(Point &p1, Point &p2)
{
	doPoint(p1,p2);
	    
	cout << endl << "Move p2 by (0,5)" << endl << endl;
	p2.move(0, 5);
	doPoint(p1,p2);

	cout << endl << "Multiple Assignments after moving (5,10)" << endl << endl;
	p2.move(5, 10);
	p1 = p1 = p2;
	doPoint(p1, p2);
	    
}
	
static void doCircle(Circle &c1, Circle &c2, Circle &c3)
{
	cout << "Circle c1 is " << c1 << endl;
	cout << "Circle c2 is " << c2 << endl;
	cout << "Circle c3 is " << c3 << endl;

	cout << "c1 == c1? " << ((c1 == c1) ? " Yes " : " No ") << endl;
	cout << "c1 == c2? " << ((c1 == c2) ? " Yes " : " No ") << endl;
	cout << "c1 == c3? " << ((c1 == c3) ? " Yes " : " No ") << endl;
	cout << "c2 == c3? " << ((c2 == c3) ? " Yes " : " No ") << endl;
	cout << "c1 != c1? " << ((c1 != c1) ? " Yes " : " No ") << endl;
	cout << "c1 != c2? " << ((c1 != c2) ? " Yes " : " No ") << endl;
	cout << "c1 != c3? " << ((c1 != c3) ? " Yes " : " No ") << endl;
	cout << "c2 != c3? " << ((c2 != c3) ? " Yes " : " No ") << endl;

	cout << "c1 center is " << c1.getCenter() << endl;
	cout << "c1 radius is " << c1.getRadius() << endl;
	cout << "c2 center is " << c2.getCenter() << endl;
	cout << "c2 radius is " << c2.getRadius() << endl;
	cout << "c3 center is " << c3.getCenter() << endl;
	cout << "c3 radius is " << c3.getRadius() << endl;

	cout << "Distance from c1 to c1 is " << c1.getDistance(c1) << endl;
	cout << "Distance from c2 to c2 is " << c2.getDistance(c2) << endl;
	cout << "Distance from c3 to c3 is " << c3.getDistance(c3) << endl;

	cout << "Distance from c1 to c2 is " << c1.getDistance(c2) << endl;
	cout << "Distance from c1 to c3 is " << c1.getDistance(c3) << endl;
	cout << "Distance from c2 to c3 is " << c2.getDistance(c3) << endl;

}

static void doCircles(Circle &c1, Circle &c2, Circle &c3)
{
    doCircle(c1,c2,c3);
   
    cout << endl << "Move c2 by (3,6)" << endl;
    c2.move(3,6);
	doCircle(c1,c2,c3);

	cout << endl << "Multiple Assignments" << endl << endl;
	c1 = c2 = c3;
	doCircle(c1, c2, c3);
}

static void doTarget(Target &t1, Target &t2, Target &t3)
{
	cout << "Target t1 is " << t1 << endl;
	cout << "Target t2 is " << t2 << endl;
	cout << "Target t3 is " << t3 << endl;

	cout << "t1 == t1? " << ((t1 == t1) ? " Yes " : " No ") << endl;
	cout << "t1 == t2? " << ((t1 == t2) ? " Yes " : " No ") << endl;
	cout << "t1 == t3? " << ((t1 == t3) ? " Yes " : " No ") << endl;
	cout << "t2 == t3? " << ((t2 == t3) ? " Yes " : " No ") << endl;

	cout << "t1 BullsEye is " << t1.getBullsEye() << endl;
	cout << "t2 BullsEye is " << t2.getBullsEye() << endl;
	cout << "t3 BullsEye is " << t3.getBullsEye() << endl;
	
	cout << "Distance from t1 to t1 is " << t1.getDistance(t1) << endl;
	cout << "Distance from t2 to t2 is " << t2.getDistance(t2) << endl;
	cout << "Distance from t3 to t3 is " << t3.getDistance(t3) << endl;

	cout << "Distance from t1 to t2 is " << t1.getDistance(t2) << endl;
	cout << "Distance from t1 to t3 is " << t1.getDistance(t3) << endl;
	cout << "Distance from t2 to t3 is " << t2.getDistance(t3) << endl;

	cout << endl << "Change Target 1's second and last ring" << endl;
	t1.setRingRadius(1, t1.getRingRadius(1) + 1);
	t1.setRingRadius(t1.getCount() - 1, 300);
	cout << t1 << endl;

}

static void doTargets(Target &target1, Target &target2, Target &target3)
{
	doTarget(target1, target2, target3);
		
	cout << "Move target1 by (-2, -3)" << endl;
	target1.move(-2, -3);
	doTarget(target1, target2, target3);

	cout << endl << "Multiple Assignments" << endl << endl;
	target1 = target2 = target3;
	doTarget(target1, target2, target3);
}


int main() 
{
	Point p1(0,0);
	Point p2(p1);

	cout << "\nPoints\n" << endl;
	doPoints(p1, p2);

	Circle c1(5, 5, 1);
	Circle c2(p1, 5);
	Circle c3(c2);
	cout << "\nCircles\n" << endl;
	doCircles(c1,c2,c3);

	Target t1(0, 0, 1, 3);
	Circle c4(5, 7, 2);
	Target t2(c4, 5);
	Target t3(t2);
	cout << "\nTargets\n" << endl;
	doTargets(t1, t2, t3);

	cout << "Done. Press 'a' to dismiss window";
	char a;
	cin >> a;

}

	