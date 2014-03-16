#ifndef GRID_H
#define GRID_H

#include <vector>
#include <algorithm>
#include <fstream>

#include <QtOpenGL>

#ifndef MAX_CELL_SIZE
#define MAX_CELL_SIZE 8
#endif

/*
#ifndef GRID_UNIFORM
#define GRID_UNIFORM 1
#endif

#ifndef GRID_RECTILINEAR
#define GRID_RECTILINEAR 2
#endif

#ifndef GRID_STRUCTURED
#define GRID_STRUCTURED 3
#endif

#ifndef GRID_UNSTRUCTURED
#define GRID_UNSTRUCTURED 4
#endif
*/

/**
 * Basic class of computational grids. It provides the most important methods to handles different grids
 * like uniform or rectilinear. 
 */
class Grid
{
   public:
        Grid();
        virtual                 ~Grid();
        /**
        * 
        * @return number of points in grid
        */
        virtual	int		numPoints() = 0;
        /**
         * 
         * @return number of cells in grid
         */
	virtual	int		numCells() = 0;
        /**
         * Method converts number of point in grid to its coordinates.
         */
	virtual	void		getPoint(int, double*) = 0;
        /**
         * This method converts number of cell to indexes of its vertices.
         * @return dimension number
         */
	virtual	int		getCell(int, int*) = 0;
        /**
         * This method finds cell in which is included point with concrete coordinates.
         * @return number of cell
         */
	virtual	int		findCell(double*) = 0;
        
        /**
         * Gets definition of OpenGL object to be drawn in buffer.
         */
        virtual void            getGlDefinition() = 0;
        
        /**
         * This method makes a copy of current grid.
         * @return Cloned grid
         */
        virtual Grid*           clone() = 0;
        
	void			world2cell(int c, double* world, double* cell);

	void 			getC1Vector(int c, double* p, double* out);
	double 			getC0Scalar(int c, double x, double y);
        QColor*                 getC0Color(int c);
        void                    setC0Color(int c, double r, double g, double b, double a = 1);
        
        void                    setPointVector(int p, double* v);
        
    private:
        double*                 getC1Vector(int i);
        double& 		getC0Scalar(int i);
        
    protected:
	std::vector<double>	c1_vectors_;	
	std::vector<double>	c0_scalars_;
        std::vector<QColor*>    c0_colors_; 
};


/**
 * This is definition of basic grid: Uniform grid. It is the most regular of all grids,
 * what makes it simple.
 */
class UniformGrid : public Grid
{
public: 
                        UniformGrid();
			UniformGrid(int N1, int N2, double m1, double M1, double m2, double M2);
			UniformGrid(std::istream& is, double m1, double M1, double m2, double M2);
                        UniformGrid(const UniformGrid& uniformGrid);
			~UniformGrid();
	int		numPoints();
	int		numCells();
	virtual void    getPoint(int i, double* p);
	int		getCell(int i, int* c);
	virtual int     findCell(double* p);
        void            getGlDefinition();
        virtual Grid*   clone();
        
	int		getDimension1();
	int		getDimension2();
	int		getDimension3();		
        
protected:
    
	int		N1_,N2_,N3_;
	double          m1_,m2_,m3_;

private:

	double          d1_,d2_,d3_;
	
};

/**
 * Definition of rectilinear grid.
 */
class RectilinearGrid : public UniformGrid{
public:
			RectilinearGrid(std::vector<double>* d, double m1, double m2);
                        RectilinearGrid(const RectilinearGrid& rectilinearGrid);
	void            getPoint(int i, double* p);
        int             findCell(double* p);
        void            getGlDefinition();
        Grid*           clone();


private:
	
	std::vector<double> d_[2];
	
};

/**
 * Definition of unstructured grid.
 * @todo To implement structured grid.
 */
class UnstructuredGrid : public Grid{
    
    public:
        UnstructuredGrid(int nPoints, int nCells);
        ~UnstructuredGrid();
        int numCells();
        int numPoints();
        int getCell(int i, int* c);
        void getPoint(int i, double* p);
       	int findCell(double* p);
        
        
        /**
         * 
         * @param i number of cell
         * @param c pointer to intexes of points in cell
         */
        void setCell(int i, int* c);
        
        /**
         * 
         * @param i point number
         * @param p coordinates of point
         */
        void setPoint(int i, double* p);
        void getGlDefinition();
        Grid* clone();

    private:
        std::vector<int> cells_;
        std::vector<double> points_;       
};

#endif