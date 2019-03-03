#include <iostream>
#include "Rectangle.hh"

#include <cassert>
using namespace std;


static bool overlap (const Rectangle& r1, const Rectangle& r2) {
	return not ((r1.get_LL().get_y() > r2.get_LL().get_y() + r2.height() or r2.get_LL().get_y() > r1.get_LL().get_y() + r1.height()) or (r1.get_LL().get_x() > r2.get_LL().get_x() + r2.width() or r2.get_LL().get_x() > r1.get_LL().get_x() + r1.width()));
}

/** Constructor. */
Rectangle::Rectangle (double w, double h, const Point& p)
:   p(p),
    w(w),
    h(h)
{
    assert(w >= 0);
    assert(h >= 0);
}


/** Gets the LL (lower-left) point of this rectangle. */
Point Rectangle::get_LL () const {
    return p;
}


/** Gets the UR (upper-right) point of this rectangle. */
Point Rectangle::get_UR () const {
    return Point(p.get_x() + w, p.get_y() + h);
}


/** Gets the area of this rectangle. */
double Rectangle::area () const {
    return w * h;
}


/** Gets the width of this rectangle. */
double Rectangle::width () const {
    return w;
}


/** Gets the height of this rectangle. */
double Rectangle::height () const {
    return h;
}


// ***********************************************************
// Implement the rest of the Rectangle methods by yourself !!!
// ***********************************************************

/** Scales this rectangle with a factor s >= 0. */
void Rectangle::scale (double s) {
	w = s*w;
	h = s*h;
}

/** Moves the LL of this rectangle to some point p. */
void Rectangle::move_to (const Point& t) {
	p = t;
}

/** Compares this rectangle to rectangle r. */
bool Rectangle::operator== (const Rectangle& r) const {
	return p == r.p and w == r.w and h == r.h;
}

/** Compares this rectangle to rectangle r. */
bool Rectangle::operator!= (const Rectangle& r) const {
	return not operator==(r);
}

/** Intersects this rectangle with another rectangle. */
Rectangle& Rectangle::operator*= (const Rectangle& r) {
	if (overlap(*this, r)) {
		double difw = p.get_x() - r.p.get_x();
		if (difw < 0) difw = 0;
		double difh = p.get_y() - r.p.get_y();
		if (difh < 0) difh = 0;
		p += Point(difh, difw);
		w -= difw;
		h -= difh;
		w = min(get_UR().get_x(), r.get_UR().get_x()) - p.get_x();
		h = min(get_UR().get_y(), r.get_UR().get_y()) - p.get_y();
	} else p = Point(); w = 0; h = 0;
	return *this;
}

/** Returns the intersection of this rectangle with another rectangle. */
Rectangle Rectangle::operator* (const Rectangle& r) const {
	Rectangle s = r;
	s *= *this;
	return s;
}

/** Rotates this rectangle 90 degrees clockwise or counterclockwise around its LL point. */
void Rectangle::rotate (bool clockwise) {
	p += (clockwise ? Point(0, -w) : Point(-h, 0));
	double t = w;
	w = h;
	h = t;
}

/** Horizontally flips this rectangle around its LL point.*/
void Rectangle::flip_hor () {
	p += Point(0, -h);
}

/** Vertically flips this rectangle around its LL point.*/
void Rectangle::flip_ver () {
	p += Point(-w, 0);
}

/** Check whether point p is contained in this rectangle. */
bool Rectangle::contains (const Point& t) const {
	return (p.get_x() <= t.get_x() and t.get_x() <= get_UR().get_x()) and (p.get_y() <= t.get_y() and t.get_y() <= get_UR().get_y());
}

/** Check whether rectangle r is fully contained in this rectangle. */
bool Rectangle::contains (const Rectangle& r) const {
	return contains(r.get_LL()) and contains(r.get_UR());
}

