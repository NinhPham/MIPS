#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <time.h> // clock(), time(NULL)
#include <chrono> // for measuring time

#include <cstdio> // printf()
//#include <math.h> // ceil()
#include <cmath> // cos()
#include <algorithm>

#include <vector>
#include <utility>
#include <unordered_map>
#include <string>

using namespace std;

#include <Eigen/Dense>
using namespace Eigen;

//#include <tsl/robin_set.h>
//using namespace tsl;

//#include <sparsehash/dense_hash_set>
//using namespace google;

//#include <sparsepp/spp.h>
//using spp::sparse_hash_set;

#define PI				3.141592653589793238460
#define PRIME           2147483647 // 2^19 - 1 or 2^31 - 1 = 2147483647
#define EPSILON         0.000001

typedef vector<double> DVector;
typedef vector<int> IVector;
typedef vector<uint32_t> I32Vector;
typedef vector<uint64_t> I64Vector;

/*
Structure of pair
- point index
- dot product
*/
struct IDPair
{
    int m_iIndex;
    double	m_dValue;

	IDPair()
	{
        m_iIndex	= 0;
        m_dValue	= 0.0;
	}

	IDPair(int p_iIndex, double p_dValue)
	{
		m_iIndex	= p_iIndex;
		m_dValue	    = p_dValue;
	}

	// Overwrite operation < to get top K largest entries
    bool operator<(const IDPair& p) const
    {
        return m_dValue < p.m_dValue;
    }

    bool operator>(const IDPair& p) const
    {
        return m_dValue > p.m_dValue;
    }
};

/*
Structure of pair
- point index
- counter
*/

struct IIPair
{
    int m_iIndex;
    int	m_iValue;

	IIPair()
	{
	    m_iIndex	= 0;
	    m_iValue	= 0;
	}

	IIPair(int p_iIndex, int p_iCounter)
	{
	    m_iIndex	= p_iIndex;
	    m_iValue	= p_iCounter;
	}

	// Overwrite operation < to get top K largest entries
    bool operator<(const IIPair& p) const
    {
        return m_iValue < p.m_iValue;
    }

    bool operator>(const IIPair& p) const
    {
        return m_iValue > p.m_iValue;
    }
};

/*
- PARAM OF ALGORITHMS
*/

// Input
extern int PARAM_DATA_N; // Number of points (rows) of X
extern int PARAM_QUERY_Q; // Number of rows (queries) of Q
extern int PARAM_DATA_D; // Number of dimensions

// Internal params
extern bool PARAM_INTERNAL_SAVE_OUTPUT; // save the results

// MIPS
extern int PARAM_MIPS_TOP_K; // TopK largest entries from Xq
extern int PARAM_MIPS_TOP_B; // number of points to compute dot products

// Sampling
extern int PARAM_MIPS_SAMPLES; // Budgeted number of points to compute dot products

// LSH table & code
extern int PARAM_LSH_PARTITIONS; // number of partitions in normRange LSH
extern int PARAM_LSH_HASH_FUNCTIONS; // Number of concanation hash functions
extern int PARAM_LSH_HASH_TABLES; // Number of hash tables
extern int PARAM_INTERNAL_LSH_NUM_DECIMAL;

// CEOs
extern int PARAM_CEOs_D_UP;
extern int PARAM_CEOs_S0;
extern int PARAM_CEOs_N_DOWN;
extern bool PARAM_INTERNAL_GAUSS_HD3; // Use Gauss or HD3
extern bool PARAM_INTERNAL_NOT_STORE_MATRIX_X; // data structure does not fit into RAM

// Random Projection
extern int PARAM_RP_D_DOWN;

/*
- DATA STRUCTURE
*/

// Input
//extern Matrix<double, Dynamic, Dynamic, RowMajor> MATRIX_X; // matrix X
extern MatrixXd MATRIX_X;
//extern Matrix<double, Dynamic, Dynamic, ColMajor> MATRIX_Q; // matrix Q
extern MatrixXd MATRIX_Q;

// Sampling
extern DVector POS_COL_NORM_1; // matrix S for positive case
extern vector<IDPair> COL_SORT_DATA_IDPAIR; // Sampling & Greedy

// LSH
extern MatrixXd MATRIX_LSH_SIM_HASH; // matrix of L * D * K normal random variables
extern I32Vector VECTOR_LSH_UNIVERSAL_HASH; // vector of L * K random integers
extern vector<unordered_map<uint64_t, IVector>> VECTOR_LSH_TABLES;
extern I64Vector VECTOR_LSH_CODES;
extern DVector VECTOR_LSH_PARTITION_NORM;

// CEOs
extern IVector MAX_COL_SORT_IDX; // sCEOs, CEOs, 2CEOs
extern MatrixXi MATRIX_CEOs_PRECOMPUTED_MIPS;

extern vector<IDPair> MAX_COL_SORT_DATA_IDPAIR; // co-CEOs
extern vector<IDPair> MIN_COL_SORT_DATA_IDPAIR; // co-CEOs

extern MatrixXd MATRIX_NORMAL_DISTRIBUTION;
extern MatrixXd PROJECTED_X;
extern MatrixXi PROJECT_X_SORTED_IDX;

extern IVector HD1;
extern IVector HD2;
extern IVector HD3;


/**
Struct of comparing matrix elements
**/
struct compare_PROJECTED_X
{
    int dim;
    compare_PROJECTED_X(int d) : dim(d) { }
    bool operator() (int i, int j) { return (PROJECTED_X(i, dim) > PROJECTED_X(j, dim)); }
};

#endif // HEADER_H_INCLUDED
