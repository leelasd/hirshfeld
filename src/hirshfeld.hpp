#ifndef HIRSHFELD_H
#define HIRSHFELD_H
#include <vector>
#include "molecule.hpp"

namespace chemistry {
  class Atomdata;
}

class Hirshfeld{
public:
	Hirshfeld(char * fname);
	void run();
	~Hirshfeld();
private:
	chemistry::Molecule mol;
	std::vector<chemistry::Atomdata *> atoms;
	int activeatom;
	double gauss_chebyshev_integrate(int n);
//	double atomdensity(int n, double r) const;
	double lebedev_x[110];
	double lebedev_y[110]; 
	double lebedev_z[110];
	double lebedev_w[110];
	double density(double r) const;
	double sphereint(double r) const;
	void initatoms();
	double atomdensity(int atomicnumber, double r) const;
	double radiusmedium(int atmidx) const;
};

#endif