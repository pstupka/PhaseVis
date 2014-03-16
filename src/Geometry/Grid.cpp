#include "Grid.h"
#include "Primitives.h"
#include <iostream>

//GRID
Grid::Grid(){

}

Grid::~Grid(){
    for (unsigned int i = 0; i< c0_colors_.size(); i++) if (!c0_colors_[i]) delete c0_colors_[i];
    std::cerr<<"Grid destructed\n";
}


/**
 * Method converts world coordinates of point to parametric cell coordinates ([0,1]).
 * @param i number of cell
 * @param world global coordinates of point
 * @param cell parametric coordinates
 * @todo to implement this method.
 */
void	Grid::world2cell(int i, double* world, double* cell){
    int c[MAX_CELL_SIZE];
    
    switch (1){
        case 0:{
            break;
        }
        case 1:{
            break;
        }
        case 2:{
            break;
        }
        default: break;
    }

}

/**
 * 
 * @param i number of point
 * @return coordinates of vector 
 */
double*	Grid::getC1Vector(int i){
    return &(c1_vectors_[3*i]);
}

/**
 * 
 * @param c number of cell
 * @param p pointer to coordinates of point to be interpolated
 * @param out pointer to vector values
 */
void 	Grid::getC1Vector(int c, double* p, double* out){
    int cell[MAX_CELL_SIZE];
    getCell(c,cell);
    double *vi;
    vi = getC1Vector(cell[0]);
    
    out[0] = vi[0];
    out[1] = vi[1];
    out[2] = vi[2];

}

/**
 * 
 * @param i number of cell
 * @return reference to scalar value in cell
 */
double& Grid::getC0Scalar(int i){
    return c0_scalars_[i];
}

/**
 * 
 * @param c number of cell
 * @param x parametric coordinate
 * @param y parametric coordinate
 * @return 
 */
double 	Grid::getC0Scalar(int c,double x, double y){
    return getC0Scalar(c);
}

/**
 * 
 * @param c number of cell
 * @return pointer to color that is included in cell
 */
QColor* Grid::getC0Color(int c){   
    return c0_colors_[c];
}

/**
 * Method sets color in cell from (R,G,B,A) space.
 * @param c number of cell
 * @param r Red component
 * @param g Green component
 * @param b Blue component
 * @param a Alpha component
 */
void  Grid::setC0Color(int c, double r, double g, double b, double a){
    getC0Color(c) -> setRgbF(r,g,b,a);
}

/**
 * This method sets vector components at point p.
 * @param p point number
 * @param v vector components
 */
void Grid::setPointVector(int p, double* v){
    c1_vectors_[3*p+0] = v[0];
    c1_vectors_[3*p+1] = v[1];
    c1_vectors_[3*p+2] = v[2];
}


//UNIFORM GRID
UniformGrid::UniformGrid(int N1, int N2, double m1, double M1, double m2, double M2) 
        : N1_(N1), N2_(N2), m1_(m1), d1_((M1-m1_)/(N1_-1.)), m2_(m2),  d2_((M2-m2_)/(N2_-1.)){
    c1_vectors_.resize(3*numPoints());
    c0_scalars_.resize(numPoints());
    for(int i = 0; i< numCells();i++)
        c0_colors_.push_back(new QColor());
}

UniformGrid::UniformGrid(std::istream& is, double m1, double M1, double m2, double M2)
	: m1_(m1), m2_(m2){
    double x,y;
    
    is >> N1_ >> N2_;
    d1_ = (M1-m1_)/(N1_-1);
    d2_ = (M2-m2_)/(N2_-1);
    
    for (int i = 0; i < numPoints(); ++i) 
    {
       if (is.eof ()) {
            std::cerr<<"Błąd odczytu z pliku\n"; 
        }
        is >> x >> y;			//dopisać przypadek 3-wym
        c1_vectors_.push_back(x);
        c1_vectors_.push_back(y);
        c1_vectors_.push_back(0);
        c0_scalars_.push_back(sqrt(x*x+y*y));
    }    
    for(int i = 0; i< numCells();i++)
        c0_colors_.push_back(new QColor());
}

UniformGrid::UniformGrid(const UniformGrid& uniformGrid){
    
    d1_ = uniformGrid.d1_;
    d2_ = uniformGrid.d2_;
    
    m1_ = uniformGrid.m1_;
    m2_ = uniformGrid.m2_;
    
    N1_ = uniformGrid.N1_;
    N2_ = uniformGrid.N2_;
    
    c0_scalars_ = uniformGrid.c0_scalars_;
    c1_vectors_ = uniformGrid.c1_vectors_;
    
    for(uint i = 0; i < uniformGrid.c0_colors_.size(); i++){
        c0_colors_.push_back(new QColor(*uniformGrid.c0_colors_[i]));
    }
}

UniformGrid::~UniformGrid(){
}


int     UniformGrid::numPoints(){
    return N1_*N2_;
}

int     UniformGrid::numCells(){
    return (N1_-1)*(N2_-1);
}

void	UniformGrid::getPoint(int i, double* p){ 
    p[0] = m1_+(int)(i%(N1_))*d1_;
    p[1] = m2_+(int)(i/(N1_))*d2_;  //tu może być błąd - zmienić na N1
    p[2] = 0;
}

int	UniformGrid::getCell(int i, int* c){
    c[0] = i + i/(N1_-1);
    c[1] = c[0] + 1;
    c[3] = c[1] + (N1_-1);
    c[2] = c[3] + 1 ;
    return 4; 
}

int	UniformGrid::findCell(double* p){
    int C[3];

    //compute cell coordinates
    C[0] = ((p[0]-m1_)/d1_);
    C[1] = ((p[1]-m2_)/d2_);

    //test if p is inside the dataset
    if (C[0]<0 || C[0] >= N1_-1 || C[1]<0 || C[1] >= N2_-1) return -1;

    //go from cell coordinates to index
    return C[0] + C[1]*(N1_-1);
}

void UniformGrid::getGlDefinition(){
    int cellPoint[MAX_CELL_SIZE];
    int C;
    double p[3];
    glPushMatrix();
    glBegin(GL_QUADS);
  
    for(int c = 0; c < numCells(); c++){
        C = getCell(c, cellPoint);
        
        glColor4d(getC0Color(c) -> redF(),
                  getC0Color(c) -> greenF(),
                  getC0Color(c) -> blueF(), 
                  getC0Color(c) -> alphaF());
        for (int i = 0; i < C; i++){ 
            getPoint(cellPoint[i],p);
            glVertex3d(p[0],p[1],p[2]);
        }
    }
    
    glEnd();    
    glPopMatrix();
}

Grid* UniformGrid::clone(){
    return new UniformGrid(*this);
}

int	UniformGrid::getDimension1(){
    return N1_;
}

int	UniformGrid::getDimension2(){
    return N2_;
}

int	UniformGrid::getDimension3(){
    return N3_;
}


//RECTILINEAR GRID
RectilinearGrid::RectilinearGrid(std::vector<double>* d, double m1, double m2): UniformGrid(N1_, N2_, m1, m2, 0, 0){
        d_[0] = d[0];
        d_[1] = d[1];
}

void	RectilinearGrid::getPoint(int i, double* p){
    p[0] = m1_ + d_[0][i%N1_];
    p[2] = m2_ + d_[1][i/N1_];
}

int RectilinearGrid::findCell(double* p){
    
}
// To write

void RectilinearGrid::getGlDefinition(){
    
}

Grid* RectilinearGrid::clone(){
    return 0; 
}


//Unstructured grid
UnstructuredGrid::UnstructuredGrid(int nPoints, int nCells) {
    cells_.resize(3*nCells);
    points_.resize(3*nPoints);
}

UnstructuredGrid::~UnstructuredGrid(){
    
}

int UnstructuredGrid::numCells(){
    return cells_.size()/3.;
}

int UnstructuredGrid::numPoints(){
    return points_.size()/3.;
}

int UnstructuredGrid::getCell(int i, int* c){
    c[0] = cells_[3*i+0];       
    c[1] = cells_[3*i+1];  
    c[2] = cells_[3*i+2];  
    return 4;
}

void UnstructuredGrid::getPoint(int i, double* p){
    p[0] = points_[3*i];
    p[1] = points_[3*i+1];
    p[2] = points_[3*i+2];
}

int UnstructuredGrid::findCell(double* p){
    
}

void UnstructuredGrid::setCell(int i, int* c){
    
    cells_[3*i] = c[0];
    cells_[3*i+1] = c[1];
    cells_[3*i+2] = c[2];
}

void UnstructuredGrid::setPoint(int i, double* p){
    points_[3*i] = p[0];
    points_[3*i+1] = p[1];
    points_[3*i+2] = p[2];
}

void UnstructuredGrid::getGlDefinition(){
    
}

Grid* UnstructuredGrid::clone(){
    return 0;
}