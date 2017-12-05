#ifndef HEADER_HH
#define HEADER_HH

#include <vector>
#include <list>
#include <memory>
#include <cmath>

using std::fabs;
using std::unique_ptr;
using std::list;
using std::vector;
using std::ifstream;

template<typename P, typename S>
struct tupla
{
    P primero;
    S segundo;

    tupla<P, S>(P prim, S seg) : primero(prim), segundo(seg) {}
    tupla<P, S>() : primero(P()), segundo(S()) {}
    inline bool operator >(const tupla& otro) const { return primero > otro.primero; }
    inline bool operator <(const tupla& otro) const { return primero < otro.primero; }
};

struct CCS
{
    vector<double> values;
    vector<int> rowIndex;
    vector<int> colPtr;
    
    CCS();
    CCS(list<tupla<int, int>>&, int);
    CCS(list<tupla<int, int>>&, vector<int>&, int&, const double&);
};

struct CCSTranspuesta
{
    vector<double> values;
    vector<int> colIndex;
    vector<int> rowPtr;
    
    CCSTranspuesta(CCS&, int);
};

void vecCrossMatrix (vector<double>& vec, vector<double>& res, CCSTranspuesta& mat, int n);

unique_ptr<vector<double>> powerMethod (CCSTranspuesta&, int, double, double, vector<double>&);

void indeg (list<tupla<int, int>>&, vector<tupla<int,int>>&);

void gem (ifstream&, double, vector<vector<double>>&);

#endif //HEADER_HH
